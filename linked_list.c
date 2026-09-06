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

void sort(t_list *list) {
    if (list == NULL || is_empty(list)) {
        return;
    }

    t_node *current = list->head;

    for (int i = 0; i < list->size - 1; i++) {
        t_node *min_node = current;
        t_node *cursor = current->next;

        for (int j = i + 1; j < list->size; j++) {
            if (cursor->item < min_node->item) {
                min_node = cursor;
            }

            cursor = cursor->next;
        }

        if (min_node != current) {
            int swap = min_node->item;
            min_node->item = current->item;
            current->item = swap;
        }

        current = current->next;
    }
}

t_list* merge(t_list *list1, t_list *list2) {
    if (list1 == NULL || is_empty(list1)) {
        free(list1);
        return list2;
    }

    if (list2 == NULL || is_empty(list2)) {
        free(list2);
        return list1;
    }

    t_list *new_list = malloc(sizeof(t_list));

    if (new_list == NULL) {
        return NULL;
    }

    t_node *head = NULL;

    t_node *current1 = list1->head;
    t_node *current2 = list2->head;

    if (current1->item < current2->item) {
        head = current1;
        current1 = current1->next;
    } else {
        head = current2;
        current2 = current2->next;
    }

    t_node *tail = head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->item <= current2->item) {
            tail->next = current1;
            current1 = current1->next;
        } else {
            tail->next = current2;
            current2 = current2->next;
        }

        tail = tail->next;
    }

    tail->next = current1 != NULL ? current1 : current2;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    new_list->head = head;
    new_list->tail = tail;
    new_list->size = list1->size + list2->size;

    free(list1);
    free(list2);

    return new_list;
}

void clone(t_list *src, t_list *dest) {
    dest->head = NULL;
    dest->tail = NULL;
    dest->size = 0;

    if (src == NULL || is_empty(src)) {
        return;
    }

    t_node *source = src->head;
    t_node *tail = NULL;

    while (source != NULL) {
        t_node *current = malloc(sizeof(t_node));

        if (current == NULL) {
            return;
        }

        current->item = source->item;
        current->next = NULL;

        if (tail == NULL) {
            dest->head = current;
        } else {
            tail->next = current;
        }

        tail = current;
        source = source->next;
    }

    dest->tail = tail;
    dest->size = src->size;
}
