#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int test_linked_list();

int main() {
    if (test_linked_list())
        printf("Test OK.\n");
    else
        printf("Test failed.\n");
    return 0;
}

int test_linked_list() {
    struct list *l = NULL;
    l = create_list();
    if (l == NULL) return 0;

    if (!insert_start(l, 10)) {
        printf("Couldn't insert at start!\n");
        return 0;
    }
    if (!insert_end(l, 20)) {
        printf("Couldn't insert at end!\n");
        return 0;
    }
    if (!check_val(l, 20)) {
        printf("Couldn't check val!\n");
        return 0;
    }
    if (!insert_end(l, 40)) {
        printf("Couldn't insert at end!\n");
        return 0;
    }
    if (!check_val(l, 40)) {
        printf("Couldn't check val!\n");
        return 0;
    }

    printAll(l);
    delete_list(l);
    return 1;
}
