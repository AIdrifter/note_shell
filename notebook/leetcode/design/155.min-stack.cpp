/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (35.18%)
 * Total Accepted:    259.7K
 * Total Submissions: 738.3K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 *
 *
 * pop() -- Removes the element on top of the stack.
 *
 *
 * top() -- Get the top element.
 *
 *
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstring>
#include <map>
using namespace std;



#define STACK_STL 1
class MinStack {
public:
    /** initialize your data structure here. */
    int stack_capacity = 2;
    int stack_top = 1;
    int *ptr = NULL;
    int array[10000]; // Coredump is array size problem

    void resize(int stack_size_now)
    {
        if(stack_size_now+10>stack_capacity)
        {
            stack_capacity+=300;
            int *new_ptr = new int [stack_capacity];
            memcpy(new_ptr,ptr,stack_size_now*sizeof(int));
            ptr = new_ptr;
        }
    }

    MinStack() {
#if STACK_STL
       ptr = new int [stack_capacity];
       //ptr = array;
#endif
    }

    void push(int x) {
#if STACK_STL
        stack_top++;
        resize(stack_top);
        ptr[stack_top-1] = x;
#else
        S.push(x);
#endif
        //if(min_stack.empty() || x<min_stack.top()) // [FIXME]This version will coredump
        if(min_stack.empty() || x<=min_stack.top())
            min_stack.push(x);
    }

    void pop() {
#if STACK_STL
        if(min_stack.top()==ptr[stack_top-1])
            min_stack.pop();

        if(stack_top>=1)
            stack_top--;

#else
        if(min_stack.top()==S.top())
             min_stack.pop();
        S.pop();
#endif
    }


    int top() {
#if STACK_STL
       return  ptr[stack_top-1];
#else
       return S.top();
#endif
   }

    int getMin() {
        return min_stack.top();
    }
private:
    stack<int> min_stack,S;
};

#if 0
int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();  // --> Returns -3.
    minStack.pop();
    minStack.top();     // --> Returns 0.
    minStack.getMin();  // --> Returns -2.

    return 0;
}
#endif


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
