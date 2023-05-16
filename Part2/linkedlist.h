#ifndef LL_H
#define LL_H

struct node {
  int val;
  struct node *next;
  struct node *prev;
};

struct list {
  struct node *first;
  struct node *last;
};

/* Create an empty list.
   Return a pointer to the empty list, or NULL on failure. */
struct list *create_list();

/* Free up memory used by list and nodes in it */
void delete_list(struct list *l);

/* Insert value in the beginning of a list.
   Return 0 on failure and 1 on success. */ 
int insert_start(struct list *l, int val);

/* Insert value in the end of a list.
   Return 0 on failure and 1 on success. */ 
int insert_end(struct list *l, int val);

/* Create a node with value val and put it in the list after node n.
   Return 0 on failure and 1 on success. */
int insert_after(struct list *l, struct node *n, int val);

/* Create a node with value val and put it in the list before node n.
   Return 0 on failure and 1 on success. */
int insert_before(struct list *l, struct node *n, int val);

/* Delete node n from the list. 
   The other nodes should remain in their old relative order. */
void delete_node(struct list *l, struct node *n);

/* Check if there is a node with value val.
   Return 1 if val is in the list, 0 otherwise. */
int check_val(struct list *l, int val);

void printAll(struct list *l);

#endif
