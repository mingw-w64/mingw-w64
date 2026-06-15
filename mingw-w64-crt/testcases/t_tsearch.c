#define _GNU_SOURCE
#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * FIXME: calling `twalk` after `tdestroy` walks the tree as if tree was not
 *  destroyed. That is, it dereferences freed nodes.
 */

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
  return;
}

/* Number of nodes printed by `print_node` in a call to `twalk` */
static int nodes_printed;

void print_node (const void *ptr, VISIT order, int level)
{
 const char *s = *(const char **) ptr;
 if (order == postorder || order == leaf) {
   nodes_printed += 1;
   printf("%s\n", s);
 }
}

int main (int argc, char **argv)
{
 int exit_code = EXIT_SUCCESS;

 void *root = NULL;
 void *nodep;

 tsearch("aaa", &root, node_cmp);
 tsearch("bbb", &root, node_cmp);
 tsearch("ccc", &root, node_cmp);
 printf("---------- tree after insertion of 3 nodes:\n");
 nodes_printed = 0;
 twalk(root, print_node);
 if (nodes_printed != 3) {
  printf ("ERROR: printed %d nodes when expected %d\n", nodes_printed, 3);
  exit_code = EXIT_FAILURE;
 }

 printf("----------\n");

 while ((nodep = tfind(NULL, &root, node_any)))
 {
   const char *key = * (const char **) nodep;
   tdelete(key, &root, node_cmp);
 }
 printf("---------- tree after deletion of all nodes using tfind()+tdelete():\n");
 nodes_printed = 0;
 twalk(root, print_node);
 if (nodes_printed != 0) {
  printf ("ERROR: printed %d nodes when expected %d\n", nodes_printed, 0);
  exit_code = EXIT_FAILURE;
 }

 printf("----------\n");

 tsearch("ddd", &root, node_cmp);
 tsearch("eee", &root, node_cmp);
 tsearch("fff", &root, node_cmp);
 printf("---------- tree after insertion of 3 new nodes:\n");
 nodes_printed = 0;
 twalk(root, print_node);
 if (nodes_printed != 3) {
  printf ("ERROR: printed %d nodes when expected %d\n", nodes_printed, 3);
  exit_code = EXIT_FAILURE;
 }

 printf("----------\n");

 while (tdelete(NULL, &root, node_any) != NULL)
   ;
 printf("---------- tree after deletion of all nodes using tdelete() only:\n");
 nodes_printed = 0;
 twalk(root, print_node);
 if (nodes_printed != 0) {
  printf ("ERROR: printed %d nodes when expected %d\n", nodes_printed, 0);
  exit_code = EXIT_FAILURE;
 }

 printf("----------\n");

 tsearch("ggg", &root, node_cmp);
 tsearch("hhh", &root, node_cmp);
 tsearch("iii", &root, node_cmp);
 printf("---------- tree after insertion of 3 new nodes:\n");
 nodes_printed = 0;
 twalk(root, print_node);
 if (nodes_printed != 3) {
  printf ("ERROR: printed %d nodes when expected %d\n", nodes_printed, 3);
  exit_code = EXIT_FAILURE;
 }

 printf("----------\n");

 tdestroy(root, noop_free);
 printf("---------- tree after deletion of all nodes using tdestroy() only:\n");
 nodes_printed = 0;
 twalk(root, print_node);
 if (nodes_printed != 0) {
  printf ("ERROR: printed %d nodes when expected %d\n", nodes_printed, 0);
  exit_code = EXIT_FAILURE;
 }

 printf("----------\n");

 printf("Done\n");

 return exit_code;
}
