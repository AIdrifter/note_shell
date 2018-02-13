#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}Node;


typedef struct list
{
    Node *head;
    Node *tail;
}List;

void append_list_node_end(List *list, Node *target)
{
    if(target == NULL)
    {
        printf("[error] target is NULL \n");
    }

    // head is empty
    if(list->head == NULL)
    {
        list->head = target ;
    }
    else
    {
        Node *ptr = NULL;

        for(ptr = list->head; ptr->next!=NULL ;ptr=ptr->next)
        {
            printf("ptr %p \n",ptr);
        }

        ptr->next = target;
        target->next = NULL;
    }
}

void append_list_node_front(List *list, Node *target)
{
    if(target == NULL)
    {
        printf("[error] target is NULL \n");
    }

    // head is empty
    if(list->head == NULL)
    {
        list->head = target ;
    }
    else
    {
        target->next = list->head;
    }

}
// 3 exceptional cases, we need to take care of:
//    1.list is empty
//    2.delete the head node
//    3.node is not in the list
void remove_list_node(List *list, Node *target)
{
    Node *prev = NULL;
    Node *current = list->head;
    // Walk the list
    while (current != target) {
        prev = current;
        current = current->next;
    }
    // Remove the target by updating the head or the previous node.
    if (!prev)
        list->head = target->next;
    else
        prev->next = target->next;

    target->next = NULL;
}

void Add_list_node(List *list, Node *target)
{
    Node *prev = NULL;
    Node *current = list->head;
    // Walk the list
    while (current != target) {
        prev = current;
        current = current->next;
    }
    // Remove the target by updating the head or the previous node.
    if (!prev)
        list->head = target->next;
    else
        prev->next = target->next;
}

void remove_list_node_good_tatse(List *list, Node *target)
{
    // The "indirect" pointer points to the *address*
    // of the thing we'll update.
    Node **indirect = &list->head;
    // Walk the list, looking for the thing that
    // points to the node we want to remove.
    while (*indirect != target)
        indirect = &(*indirect)->next;
    *indirect = target->next;
}


int main()
{
    List list = {NULL,NULL};
    Node a1 = {1,NULL};
    Node a2 = {2,NULL};
    Node a3 = {3,NULL};
    Node a4 = {4,NULL};
    Node a5 = {5,NULL};
    Node a6 = {6,NULL};
    append_list_node_end(&list,&a1);
    append_list_node_end(&list,&a2);
    append_list_node_end(&list,&a3);
    append_list_node_end(&list,&a4);
    append_list_node_end(&list,&a5);
    remove_list_node(&list,&a2);
    remove_list_node_good_tatse(&list,&a3);
    return 0;
}
