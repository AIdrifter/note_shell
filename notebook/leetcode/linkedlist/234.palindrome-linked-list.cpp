/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.02%)
 * Total Accepted:    221.1K
 * Total Submissions: 631.3K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 *
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;

        ListNode *ptr = NULL;
        int numbers = 0;
        int i = 0;
        int right = 0 ,left = 0;
        for (ptr=head; ptr!=NULL ;ptr=ptr->next)
        {
            numbers++;
        }

        int *array = new int[numbers];
        for (ptr=head , i=0; ptr!=NULL ;ptr=ptr->next,i++)
        {
            array[i] = ptr->val;
        }

        right = numbers/2;
        if (numbers%2 == 0)
            left = right-1;
        else
            left = right;

//        printf("left(%u) right(%u) nums(%u) \n", left, right, numbers);

        while (left >= 0)
        {
            if( array[right++]==array[left--] )
                continue;
            else
                return false;
        }

        return true;



    }
};
