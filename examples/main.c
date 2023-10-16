#include <stdint.h>
#include <stdio.h>

#include "../src/linkedlist.h"

linkedlist_t my_list;

int main() {
    printf("Hello\r\n");
    my_list = linkedlist_create();

    linkedlist_add_first(&my_list, "Hi");
    linkedlist_add_first(&my_list, "Ajay");
    linkedlist_add_first(&my_list, "Haresh");
    linkedlist_add_last(&my_list, "How Are you?");

    // linkedlist_print(&my_list);

    void **ptr = linkedlist_to_array(&my_list);
    while (*ptr) {
        printf("Elements: %s\r\n", *ptr);
        *ptr++;
    }
    free(ptr);

    return 0;
}