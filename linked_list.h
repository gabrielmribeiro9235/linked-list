#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _node {
    int item;
    struct _node* next;
} t_node;
typedef struct {
    t_node* head;
    t_node* tail;
    int size;
} t_list;
t_list* create_list();
void destroy_list(t_list*);
int size(t_list*);
int is_empty(t_list*);
int append(t_list*, int);
int insert(t_list*, int, int);
int remove_item(t_list*, int);
t_node* get_node_by_item(t_list*, int);
t_node* get_node_by_index(t_list*, int);
void print_list(t_list*);
void clear(t_list*);
int find(t_list*, int);
int remove_at(t_list*, int);
t_node* peek_front(t_list*);
t_node* peek_back(t_list*);
t_node* pop_front(t_list*);
t_node* pop_back(t_list*);
void reverse(t_list*);
void sort(t_list*);
void merge(t_list*, t_list*);
void clone(t_list*, t_list*);

#endif