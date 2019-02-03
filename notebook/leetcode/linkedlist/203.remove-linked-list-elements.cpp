/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (35.08%)
 * Total Accepted:    201.2K
 * Total Submissions: 573.5K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 *
 *
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
        ListNode* removeElements(ListNode* head, int val) {

            // dummy pointer can solve head problem easily
            ListNode *dummy = new ListNode(-1);
            ListNode *prev = dummy;
            dummy->next = head;

#if 0
            while (prev->next)
            {
                if (prev->next->val == val)
                {
                    ListNode *t = prev->next;
                    prev->next = t->next;
                    t->next = NULL;
                    free(t);
                }
                else
                    prev = prev->next;
            }
#else
            ListNode *ptr = prev->next;
            while (ptr!=NULL)
            {
                if (ptr->val == val)
                {
                    prev->next = ptr->next;
                    delete ptr;
                    ptr->next = NULL;
                    ptr = prev->next;
                }
                else
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
            }
#endif

            return dummy->next;
        }

};
