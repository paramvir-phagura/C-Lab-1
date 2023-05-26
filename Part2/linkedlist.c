#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

/* Create an empty list.
   Return a pointer to the empty list, or NULL on failure. */

struct list *create_list() {
    struct list *p_list;
    if ((p_list = (struct list *) malloc(sizeof(struct list))) == 0)
        return NULL;
    p_list->first = NULL;
    p_list->last = NULL;
    return p_list;
}

/* Free up memory used by list and nodes in it */
void delete_list(struct list *l) {
    struct node *iter = l->first;
    struct node *tmp;
    while (iter != NULL) {
        tmp = iter;
        iter = iter->next;
        free(tmp);
    }
    free(l);
    return;
}

/* Insert value in the beginning of a list.
   Return 0 on failure and 1 on success. */
int insert_start(struct list *l, int val) {
    struct node *n;
    if ((n = (struct node *) malloc(sizeof(struct node))) == 0)
        return 0;
    n->val = val;
    n->prev = NULL;

    if (l->first != NULL) {
        n->next = l->first;
        l->first->prev = n;
    } else {
        n->next = NULL;
        l->last = n;
    }
    l->first = n;

    return 1;
}

/* Insert value in the end of a list.
   Return 0 on failure and 1 on success. */
int insert_end(struct list *l, int val) {
    struct node *n = NULL;
    if ((n = (struct node *) malloc(sizeof(struct node))) == 0)
        return 0;
    n->val = val;

    if (l->first != NULL) {
        n->prev = l->last;
        n->next = NULL;
        l->last = n;
        // Part 1 solution
        l->first->next = n;
    } else {
        n->next = n->prev = NULL;
        l->first = l->last = n;
    }

    return 1;
}

/* Create a node with value val and put it in the list after node n.
   Return 0 on failure and 1 on success. */
int insert_after(struct list *l, struct node *n, int val) {
    struct node *m = NULL;
    if ((m = (struct node *) malloc(sizeof(struct node))) == 0)
        return 0;
    m->val = val;
    m->next = n->next;
    m->prev = n; // Part 2 solution
    if (l->last == n)
        l->last = m;
    else
        n->next->prev = m;
    n->next = m;

    return 1;
}

/* Create a node with value val and put it in the list before node n.
   Return 0 on failure and 1 on success. */
int insert_before(struct list *l, struct node *n, int val) {
    struct node *m;
    if ((m = (struct node *) malloc(sizeof(struct node))) == 0)
        return 0;
    m->val = val;

    /* link m and n */
    m->prev = n->prev;
    m->next = n;
    if (l->first == n) {
        l->first = m;
    } else {
        if (n->prev) {
            n->prev->next = m;
        }
    }
    n->prev = m;
    return 1;
}

/* Delete node n from the list.
   The other nodes should remain in their old relative order. */
void delete_node(struct list *l, struct node *n) {
    //if(!check_node(l,n)) { printf("CHECK NODE FAILED\n\n"); return; }
    //else                 { printf("CHECK NODE OK\n\n"); }

    /* link n->prev and n->next */
    if (n->prev != NULL)
        n->prev->next = n->next;
    if (n->next != NULL)
        n->next->prev = n->prev;

    if (l->first == n)
        l->first = n->next;
    if (l->last == n)
        l->last = n->prev;

    free(n);
}

/* Check if there is a node with value val.
   Return 1 if val is in the list, 0 otherwise. */
int check_val(struct list *l, int val) {
    struct node *iter = l->first;
    while (iter != NULL) {
        if (iter->val == val) {
            return 1;
        } else {
            iter = iter->next;
        }
    }
    /* end of list reached */
    return 0;
}

void printAll(struct list *l) {
    struct node *iter = l->first;
    int index = 0;
    while (iter != NULL) {
        int value = iter->val;
        printf("index: %d val: %d\n", index, value);
        iter = iter->next;
        index++;
    }
}
