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

    int opt = 0;
    do {
        menu();
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("-----------------------------------------------\n");
                print_list(list);
                printf("\n");
                break;
            case 2: {
                int number;

                printf("-----------------------------------------------\n");
                printf("Enter the number you want to append: ");

                scanf("%d", &number);

                int append_status = append(list, number);

                if (append_status == 1) {
                    printf("\n%d appended successfully\n", number);
                } else {
                    printf("\nFailed to append\n");
                }

                break;
            }
            case 3: {
                int number;
                int index;

                printf("-----------------------------------------------\n");
                printf("Enter the number you want to insert: ");

                scanf("%d", &number);

                printf("Enter the index you want to insert: ");

                scanf("%d", &index);

                int insert_status = insert(list, index, number);

                if (insert_status == 1) {
                    printf("\n%d inserted successfully\n", number);
                } else {
                    printf("\nFailed to insert\n");
                }

                break;
            }
            case 4:
                sort(list);

                printf("-----------------------------------------------\n");
                printf("List sorted succesfully\n");

                break;
            default:
                break;
        }
    } while (opt != 20);

    destroy_list(list);

    return 0;
}
