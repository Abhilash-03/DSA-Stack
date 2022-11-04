/*
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.
Example 1:

Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.

Example 2:

Input:
4 4
4 3 2 1

Output: 
1 2 3 4

Explanation: 
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.
Your Task:
Complete the provided function modifyQueue that takes queue and k as parameters and returns a modified queue. The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxiliary Space : O(K)

Constraints:
1 <= N <= 1000
1 <= K <= N
*/

#include<bits/stdc++.h>
using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k){
           
           stack<int> s;
//take k element from queue and put into stack.
           for(int i = 0; i<k; i++){
            int val = q.front();
            q.pop();
            s.push(val);
           }

          //from stack put into queue, k element has been reversed.
        while(!s.empty()){
            int val = s.top();
            s.pop();
            q.push(val);
        }

        int t = q.size() - k;   //remaining element(s) , which has to be pushed after reversed k elements 

        while(t--){
            int val = q.front();
            q.pop();
            q.push(val);
        }

        return q;
}