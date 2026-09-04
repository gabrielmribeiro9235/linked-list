#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

t_list* create_list() {
    t_list* list = malloc(sizeof(t_list));

    if (list == NULL) {
        exit(1);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void destroy_list(t_list *list) {
    if (list == NULL) {
        return;
    }

    if (list->size == 0) {
        free(list);
        return;
    }

    while (list->head != list->tail) {
        t_node *next = list->head->next;
        free(list->head);
        list->head = next;
    }

    free(list->tail);
    free(list);
}

int size(t_list *list) {
    return list->size;
}

int is_empty(t_list *list) {
    return list->size == 0;
}

int append(t_list *list, int elem) {
    if (list == NULL) {
        return 0;
    }

    t_node *node = malloc(sizeof(t_node));

    if (node == NULL) {
        return 0;
    }

    node->item = elem;
    node->next = NULL;

    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;

    return 1;
}

t_node* get_node_by_index(t_list *list, int index) {
    if (list == NULL || index >= list->size || index < 0) {
        return NULL;
    }

    int i = 0;
    t_node *current_node = list->head;

    while (i < index) {
        current_node = current_node->next;
        i++;
    }

    return current_node;
}
