/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (45.14%)
 * Total Accepted:    483.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* l1_ptr   =  l1;
            ListNode* l2_ptr   =  l2;
            ListNode* l2_head  =  l2;
            ListNode* prev_l2  =  l2;
            ListNode* merge_head = NULL;

            while(l1_ptr->next!=NULL || l2_ptr->next!=NULL)
            {
                if(l1_ptr->val > l2_ptr->val )
                {
                    ListNode* tmp = new ListNode;
                    tmp->val = l1_ptr->val;
                    tmp = l2_ptr->next;
                    l2_ptr->next = tmp;
                    l2_ptr = l2_ptr->next->next;
                }
                else
                {
                    ListNode* tmp = new ListNode;

                    if(prev_l2 == l2_head )
                        l2_head = tmp;

                    tmp->val = l1_ptr->val;
                    tmp->next = prev_l2;
                    prev_l2 = prev_l2->next;
                }
            }

            if(l1_ptr==NULL)
            {
                return l2_head;
            }

            if(l2_ptr==NULL)
            {
                while(l1_ptr!=NULL)
                {
                    ListNode* tmp = new ListNode;
                    tmp->val = l1_ptr->val;
                    l2_ptr->next = tmp;
                    l2_ptr = l2_ptr->next;
                }
            }

        }
};
