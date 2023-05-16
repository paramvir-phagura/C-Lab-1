#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int test_linked_list2();

int main() {
    if (test_linked_list2())
        printf("Test OK.\n");
    else
        printf("Test failed.\n");
    return 0;
}

int test_linked_list2() {
    struct list *l = NULL;
    l = create_list();
    if (l == NULL) {
        return 0;
    }
    if (!insert_end(l, 10)) {
        printf("Couldn't insert at end!\n");
        return 0;
    }
    if (!insert_after(l, l->last, 50)) {
        printf("Couldn't insert after!\n");
        return 0;
    }
    if (!insert_before(l, l->last, 40)) {
        printf("Couldn't insert before!\n");
        return 0;
    }
    printAll(l);
    if (!check_val(l, 40)) {
        printf("Couldn't check val!\n");
        return 0;
    }

    delete_list(l);
    return 1;
}
