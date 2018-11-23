#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

    for (now=head, i=0; i < sum-n  ; prev=now, now=now->next, i++)
    {

        if(n==sum) /* delete node on head */
        {
            free(now);
            head = now->next;
        }

        /* delete node in tail */
        if (i==n)
        {
            prev->next = NULL;
            free(now);
            now = NULL;
        }
        else if(i==sum-n)/* other case */
        {
            prev->next = now->next;
            free(now);
            now = NULL;
        }
    }
    return head;
}

/* reverse linkedlist */
struct ListNode* reverseList(struct ListNode* head) {

}

/* Merge Two Sorted Lists */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

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
