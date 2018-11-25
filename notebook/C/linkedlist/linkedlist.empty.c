#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode_t;

struct ListNode *makeListFromChars(const char *array, int size) {
    struct ListNode anchor  = { .next = NULL }, *curr = &anchor;

    for(int i = 0; i < size; i++) {
        curr = curr->next = malloc(sizeof(struct ListNode));//Creating lists and adding data is a separate function.
        curr->val = array[i];
        curr->next = NULL;
    }
    return anchor.next;
}

struct ListNode *makeListFromInts(const int *array, int size) {
    struct ListNode anchor  = { .next = NULL }, *curr = &anchor;

    for(int i = 0; i < size; i++) {
        curr = curr->next = malloc(sizeof(struct ListNode));//Creating lists and adding data is a separate function.
        curr->val = array[i];
        curr->next = NULL;
    }
    return anchor.next;
}



/* Definition for singly-linked list. */
void deleteNode(struct ListNode* node) {
    ListNode_t *next_ptr = node->next;
    node->val = next_ptr->val;
    node->next  = next_ptr->next;
    free(next_ptr);
}

/* Remove Nth Node From End of List */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int i, sum = 0;
    struct ListNode *now = NULL;
    struct ListNode *prev = NULL;

    /* travrsal for compute linked list size */
    for (now=head; now!=NULL; now=now->next)
        sum++;

    for (now=head, i=0; i < sum  ; prev=now, now=now->next, i++)
    {

        if(n==sum) /* delete node on head */
        {
            free(now);
            head = now->next;
            return head;
        }

        /* delete node in tail */
        if (i==sum-1)
        {
            prev->next = NULL;
            free(now);
            now = NULL;
            return head;
        }
        else if(i==sum-n)/* other case */
        {
            prev->next = now->next;
            free(now);
            now = NULL;
            return head;
        }
    }
    return head;
}


/* reverse linkedlist */
struct ListNode* reverseList(struct ListNode* head) {
    if (head==NULL)
        return head;

     struct ListNode *a0 = NULL, *a1 = NULL, *a2 = NULL;
     a0 = a1; a1 = head;a2 = head->next;

     while(a1!=NULL)
     {
         a1->next = a0;
         a0 = a1;
         a1 = a2;
         if(a2!=NULL)a2 = a2->next;
     }
     return a0;
}


uint32_t linkedlist_size(struct ListNode *ptr)
{

    uint32_t size = 0;
    for(;ptr!=NULL;ptr=ptr->next)
        size++;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    uint32_t l1_size = 0;
    uint32_t l2_size = 0;
    uint32_t idx1=0 , idx2= 0;
    l1_size = linkedlist_size(l1);
    l2_size = linkedlist_size(l2);
    int *ptr= malloc(sizeof(int)*(l1_size+l2_size));

    while(idx1 != l1_size && idx2 != l2_size)
    {
        int i = 0 ;
        if (l1[idx1].val > l2[idx2].val)
        {
            ptr[i] = l2[idx2++].val;
        }
        else
        {
            ptr[i] = l1[idx1++].val;
        }
        i++;
    }

    struct ListNode *input = makeListFromInts(ptr, (l1_size + l2_size));
    return input;
}


/* Palindrome Linked List */
bool isPalindrome(struct ListNode* head) {

}

/* Linked List Cycle */
bool hasCycle(struct ListNode *head) {

}

void printList(struct ListNode *p) {
    for(; p; p = p->next)
        printf("%d ", p->val);
    printf("\n");
}

int main()
{
    char lista1[] = {1,2};
    struct ListNode *l1 = makeListFromChars(lista1, sizeof(lista1)/sizeof(char));
    printList(l1);
    removeNthFromEnd(l1,1);
    printList(l1);

}
