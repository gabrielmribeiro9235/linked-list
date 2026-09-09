#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

void menu() {
    printf("-----------------------------------------------\n");
    printf("Select a function:\n");
    printf(" 1 - print_list\n");
    printf(" 2 - append\n");
    printf(" 3 - insert\n");
    printf(" 4 - sort\n");
    printf(" 5 - remove_item\n");
    printf(" 6 - remove_at\n");
    printf(" 7 - find\n");
    printf(" 8 - get_node_by_item\n");
    printf(" 9 - get_node_by_index\n");
    printf("10 - size\n");
    printf("11 - is_empty\n");
    printf("12 - clear\n");
    printf("13 - peek_front\n");
    printf("14 - peek_back\n");
    printf("15 - pop_front\n");
    printf("16 - pop_back\n");
    printf("17 - reverse\n");
    printf("18 - merge\n");
    printf("19 - clone\n");
    printf("20 - exit\n");
    printf("-----------------------------------------------\n");
    printf("Your choice: ");
}

int main() {
    t_list *list = create_list();

    append(list, 1);
    append(list, 4);
    append(list, 9);
    append(list, 20);

    print_list(list);

    destroy_list(list);

    return 0;
}
