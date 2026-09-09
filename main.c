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
            case 5: {
                int item;

                printf("-----------------------------------------------\n");
                printf("Enter the item you want to remove: ");

                scanf("%d", &item);

                int remove_status = remove_item(list, item);

                if (remove_status == 1) {
                    printf("\n%d removed successfully\n", item);
                } else {
                    printf("\nFailed to remove\n");
                }

                break;
            }
            case 6: {
                int index;

                printf("-----------------------------------------------\n");
                printf("Enter the index you want to remove: ");

                scanf("%d", &index);

                int remove_status = remove_at(list, index);

                if (remove_status == 1) {
                    printf("\nIndex %d removed successfully\n", index);
                } else {
                    printf("\nFailed to remove\n");
                }

                break;
            }
            case 7: {
                int item;

                printf("-----------------------------------------------\n");
                printf("Enter the item you want to search for: ");

                scanf("%d", &item);

                int exist = find(list, item);

                if (exist == 1) {
                    printf("\n%d IS on the list\n", item);
                } else {
                    printf("\n%d IS NOT on the list\n", item);
                }

                break;
            }
            case 8: {
                int item;

                printf("-----------------------------------------------\n");
                printf("Enter the item for which you want to search\nthe node: ");

                scanf("%d", &item);

                t_node *node = get_node_by_item(list, item);

                if (node != NULL) {
                    printf("\nNode:\n");
                    printf("%d -> ", node->item);
                    if (node->next == NULL) {
                        printf("NULL\n");
                    } else {
                        printf("%d\n", node->next->item);
                    }
                } else {
                    printf("\n%d IS NOT on the list\n", item);
                }

                break;
            }
            case 9: {
                int index;

                printf("-----------------------------------------------\n");
                printf("Enter the index where you want to search\nthe node: ");

                scanf("%d", &index);

                t_node *node = get_node_by_index(list, index);

                if (node != NULL) {
                    printf("\nNode:\n");
                    printf("%d -> ", node->item);
                    if (node->next == NULL) {
                        printf("NULL\n");
                    } else {
                        printf("%d\n", node->next->item);
                    }
                } else {
                    printf("\nThere is NO node in the index %d\n", index);
                }

                break;
            }
            case 10:
                printf("-----------------------------------------------\n");
                printf("List size: %d\n", size(list));

                break;
            case 11:
                printf("-----------------------------------------------\n");
                if (is_empty(list)) {
                    printf("The list is empty\n");
                } else {
                    printf("The list is not empty\n");
                }

                break;
            case 12:
                clear(list);

                printf("-----------------------------------------------\n");

                printf("The list has been cleared\n");

                break;
            case 13: {
                t_node *node = peek_front(list);

                if (node != NULL) {
                    printf("\nFirst node:\n");
                    printf("%d -> ", node->item);
                    if (node->next == NULL) {
                        printf("NULL\n");
                    } else {
                        printf("%d\n", node->next->item);
                    }
                } else {
                    printf("\nThe list is empty\n");
                }

                break;
            }
            case 14: {
                t_node *node = peek_back(list);

                if (node != NULL) {
                    printf("\nLast node:\n");
                    printf("%d -> NULL\n", node->item);
                } else {
                    printf("\nThe list is empty\n");
                }

                break;
            }
            case 15: {
                t_node *node = pop_front(list);

                if (node != NULL) {
                    printf("\nItem of the removed node: %d\n", node->item);
                } else {
                    printf("\nThe list is empty\n");
                }

                free(node);

                break;
            }
            case 16: {
                t_node *node = pop_back(list);

                if (node != NULL) {
                    printf("\nItem of the removed node: %d\n", node->item);
                } else {
                    printf("\nThe list is empty\n");
                }

                free(node);

                break;
            }
            default:
                break;
        }
    } while (opt != 20);

    destroy_list(list);

    return 0;
}
