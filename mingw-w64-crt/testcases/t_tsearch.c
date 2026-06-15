#include <search.h>
#include <stdio.h>
#include <string.h>

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
