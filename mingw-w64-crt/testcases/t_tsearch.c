/*

Code exposing two POSIX-incompatibilities in search.h from mingw.org:

- compilation causes a NULL-warning, although key=NULL is allowed:
  "warning: null argument where non-null required (argument 1) [-Wnonnull]"

- the second deletion method using tdelete() only causes the following
  assertion at runtime:

     Assertion failed! File:
../../../build/mingw/mingw-w64-crt/misc/tdelete.c, Line 33
     Expression: vkey != NULL. abnormal program termination

These issues are fixed in the mingw-w64 svn as of rev. 4413

 */

#include <stdio.h>
#include <string.h>
#include <search.h>

static int node_cmp (const void *a, const void *b)
{
 return strcmp((const char *) a, (const char *) b);
}

/* match any node... */
static int node_any (const void *a, const void *b)
{
 return 0;
}

static void
noop_free (void *arg)
{
}

void print_node (const void *ptr, VISIT order, int level)
{
 const char *s = *(const char **) ptr;
 if (order == postorder || order == leaf)
   printf("%s\n", s);
}

int main (int argc, char **argv)
{
 void *root = NULL;
 void *nodep;

 tsearch("aaa", &root, node_cmp);
 tsearch("bbb", &root, node_cmp);
 tsearch("ccc", &root, node_cmp);
 printf("---------- tree after insertion of 3 nodes:\n");
 twalk(root, print_node);

 printf("----------\n");

 while ((nodep = tfind(NULL, &root, node_any)))
 {
   const char *key = * (const char **) nodep;
   tdelete(key, &root, node_cmp);
 }
 printf("---------- tree after deletion of all nodes using tfind()+tdelete():\n");
 twalk(root, print_node);
 printf("----------\n");

 tsearch("ddd", &root, node_cmp);
 tsearch("eee", &root, node_cmp);
 tsearch("fff", &root, node_cmp);
 printf("---------- tree after insertion of 3 new nodes:\n");
 twalk(root, print_node);
 printf("----------\n");
 while (tdelete(NULL, &root, node_any) != NULL)
   ;
 printf("---------- tree after deletion of all nodes using tdelete() only:\n");
 twalk(root, print_node);
 printf("----------\n");

 tsearch("ggg", &root, node_cmp);
 tsearch("hhh", &root, node_cmp);
 tsearch("iii", &root, node_cmp);
 printf("---------- tree after insertion of 3 new nodes:\n");
 twalk(root, print_node);
 printf("----------\n");
 tdestroy(root, noop_free);
 printf("---------- tree after deletion of all nodes using tdeosty() only:\n");
 twalk(root, print_node);
 printf("----------\n");
 printf("Passed\n");
 return 0;
}

/*
------------ requested output:
$ valgrind ./search_test
==9853== Memcheck, a memory error detector
==9853== Copyright (C) 2002-2010, and GNU GPL'd, by Julian Seward et al.
==9853== Using Valgrind-3.7.0.SVN and LibVEX; rerun with -h for copyright info
==9853== Command: ./search_test
==9853==
---------- tree after insertion of 3 nodes:
aaa
bbb
ccc
----------
---------- tree after deletion of all nodes using tfind()+tdelete():
----------
---------- tree after insertion of 3 new nodes:
ddd
eee
fff
----------
---------- tree after deletion of all nodes using tdelete() only:
----------
==9853==
==9853== HEAP SUMMARY:
==9853==     in use at exit: 0 bytes in 0 blocks
==9853==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==9853==
==9853== All heap blocks were freed -- no leaks are possible
==9853==
==9853== For counts of detected and suppressed errors, rerun with: -v
==9853== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/
