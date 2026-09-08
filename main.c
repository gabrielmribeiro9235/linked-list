#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

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
