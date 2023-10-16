#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node {
    void *key;
    struct node *next;
} node_t;

typedef node_t * linkedlist_t;

linkedlist_t linkedlist_create();
bool linkedlist_push_front(linkedlist_t *list, void *data);
bool linkedlist_push_back(linkedlist_t *list, void *data);
bool linkedlist_add_at(linkedlist_t *list, void *data);
void linkedlist_print(linkedlist_t *list);
size_t linkedlist_size(linkedlist_t *list);
void ** linkedlist_to_array(linkedlist_t *list);

#endif
