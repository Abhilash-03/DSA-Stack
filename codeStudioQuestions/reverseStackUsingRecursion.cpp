/*
Problem Statement
Suggest Edit
Reverse a given stack of integers using recursion.

Note:
You are not allowed to use any extra space other than the internal stack space used due to recursion.
You are not allowed to use the loop constructs of any sort available as handy. For example: for, for-each, while, etc. 
The only inbuilt stack methods allowed are:
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.

*/
#include<bits/stdc++.h>
using namespace std;

void reverse(stack<int>& stack, int n){
    if(stack.empty()){
        stack.push(n);
        return ;
    }

    int store = stack.top();
    stack.pop();

    reverse(stack, n);

    stack.push(store);
}

void reverseStack(stack<int> &stack){
   if(stack.empty()){
    return;
   }

   int num = stack.top();
   stack.pop();

   reverseStack(stack);

   reverse(stack, num);
}