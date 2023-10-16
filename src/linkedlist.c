#include "linkedlist.h"

static node_t *node_create(void *data) {
    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    if (!node)
        return NULL;
    node->key = data;
    node->next = NULL;
    return node;
}

linkedlist_t linkedlist_create() {
    return NULL;
}

bool linkedlist_add_first(linkedlist_t *list, void *data) {
    node_t *node = node_create(data);
    if (!node)
        return false;

    node->next = *list;
    *list = node;
    return true;
}

bool linkedlist_add_last(linkedlist_t *list, void *data) {
    node_t *node = node_create(data);
    if (!node)
        return false;

    linkedlist_t temp = *list;

    while (temp->next) {
        temp = (temp)->next;
    }

    temp->next = node;

    return true;
}

size_t linkedlist_size(linkedlist_t *list) {
    size_t len = 0;
    linkedlist_t temp = *list;
    while (temp) {
        temp = (temp)->next;
        len++;
    }
    return len;
}

void **linkedlist_to_array(linkedlist_t *list) {
    size_t len = linkedlist_size(list);
    if (len <= 0)
        return 0;

    void **a = (void **)calloc(len + 1, sizeof(void *));
    if (!a)
        return a;

    linkedlist_t temp = *list;
    len = 0;
    while (temp) {
        a[len++] = (temp)->key;
        temp = (temp)->next;
    }
    a[len] = NULL;
    return a;
}

void linkedlist_print(linkedlist_t *list) {
    linkedlist_t temp = *list;
    while (temp != NULL) {
        printf("%s\r\n", (temp)->key);
        temp = (temp)->next;
    }
}