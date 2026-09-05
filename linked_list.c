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

    if (is_empty(list)) {
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
    return is_empty(list);
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

    if (is_empty(list)) {
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

int insert(t_list *list, int index, int elem) {
    if (list == NULL || index > list->size || index < 0) {
        return 0;
    }

    if (index == list->size) {
        return append(list, elem);
    }

    t_node *previous_node = get_node_by_index(list, index - 1);

    t_node *node = malloc(sizeof(t_node));

    if (node == NULL) {
        return 0;
    }

    node->item = elem;

    if (previous_node == NULL) {
        node->next = list->head;
        list->head = node;
    } else {
        node->next = previous_node->next;
        previous_node->next = node;
    }

    list->size++;

    return 1;
}

int remove_item(t_list *list, int item) {
    if (list == NULL || is_empty(list)) {
        return 0;
    }

    if (list->head->item == item) {
        t_node *next = list->head->next;

        free(list->head);
        list->head = next;

        list->size--;

        if (is_empty(list)) {
            list->tail = NULL;
        }

        return 1;
    }

    t_node *previous = list->head;

    while (previous->next != NULL && previous->next->item != item) {
        previous = previous->next;
    }

    if (previous->next == NULL) {
        return 0;
    }

    t_node *next = previous->next->next;

    free(previous->next);
    previous->next = next;

    if (next == NULL) {
        list->tail = previous;
    }

    list->size--;

    return 1;
}

t_node* get_node_by_item(t_list *list, int item) {
    if (list == NULL) {
        return NULL;
    }

    t_node *current_node = list->head;

    while (current_node != NULL && current_node->item != item) {
        current_node = current_node->next;
    }

    return current_node;
}

void print_list(t_list *list) {
    t_node *current = list->head;

    while (current != NULL) {
        printf("%d -> ", current->item);
        current = current->next;
    }

    printf("NULL");
}

void clear(t_list *list) {
    if (list == NULL || is_empty(list)) {
        return;
    }

    while (list->head != list->tail) {
        t_node *next = list->head->next;
        free(list->head);
        list->head = next;
    }

    free(list->tail);

    list->head = NULL;
    list->tail = NULL;

    list->size = 0;
}

int find(t_list *list, int item) {
    return get_node_by_item(list, item) != NULL;
}

int remove_at(t_list* list, int index) {
    if (list == NULL || index < 0 || index >= list->size) {
        return 0;
    }

    if (index == 0) {
        t_node *next = list->head->next;

        free(list->head);
        list->head = next;

        list->size--;

        if (is_empty(list)) {
            list->tail = NULL;
        }

        return 1;
    }

    t_node *previous = list->head;

    for (int i = 0; i < index - 1; i++) {
        previous = previous->next;
    }

    t_node *next = previous->next->next;

    free(previous->next);
    previous->next = next;

    if (next == NULL) {
        list->tail = previous;
    }

    list->size--;

    return 1;
}

t_node* peek_front(t_list *list) {
    return list != NULL ? list->head : NULL;
}

t_node* peek_back(t_list *list) {
    return list != NULL ? list->tail : NULL;
}

t_node* pop_front(t_list *list) {
    if (list == NULL || is_empty(list)) {
        return NULL;
    }

    t_node *head = malloc(sizeof(t_node));

    if (head == NULL) {
        return NULL;
    }
    
    head->item = list->head->item;
    head->next = NULL;

    remove_at(list, 0);

    return head;
}

t_node* pop_back(t_list *list) {
    if (list == NULL || is_empty(list)) {
        return NULL;
    }

    t_node *tail = malloc(sizeof(t_node));

    if (tail == NULL) {
        return NULL;
    }

    *tail = *list->tail;

    remove_at(list, list->size - 1);

    return tail;
}

void reverse(t_list *list) {
    if (list == NULL || is_empty(list)) {
        return;
    }

    t_node *previous = NULL;
    t_node *current = list->head;

    while (current != NULL) {
        t_node *next = current->next;

        current->next = previous;
        previous = current;
        current = next;
    }

    list->tail = list->head;
    list->head = previous;
}
