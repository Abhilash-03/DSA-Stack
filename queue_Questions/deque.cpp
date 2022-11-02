/*
Design a data structure to implement deque of size ‘N’. It should support the following operations:
pushFront(X): Inserts an element X in the front of the deque. Returns true if the element is inserted, otherwise false.

pushRear(X): Inserts an element X in the back of the deque. Returns true if the element is inserted, otherwise false.

popFront(): Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.

popRear(): Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.

getFront(): Returns the first element of the deque. If the deque is empty, it returns -1.

getRear(): Returns the last element of the deque. If the deque is empty, it returns -1.

isEmpty(): Returns true if the deque is empty, otherwise false.

isFull(): Returns true if the deque is full, otherwise false.

Sample Input 1:
5 7
7
1 10
1 20
2 30
5
4
4
Sample Output 1:
True 
True 
True
True
20
30
10
Explanation 1:
For the given input, we have the number of queries, Q = 7.
Operations performed on the deque are as follows:

isEmpty(): Deque is initially empty. So, this returns true.
pushFront(10): Insert the element ‘10’ in the front of the deque. This returns true.
pushFront(20): Insert the element ‘20’ in the front of the deque. This returns true.
pushRear(30): Insert the element ‘30’ in the back of the deque. This returns true.
getFront(): Returns the front element of the deque i.e. 20
popRear(): Pop an element from the back of the deque. This returns 30.
popRear(): Pop an element from the back of the deque. This returns 10.

The following image shows the snapshots of the deque after each operation:
*/

#include <bits/stdc++.h>
using namespace std;

class Deque{
    int* arr;
    int size;
    int frnt ;
   int rear;

   public:
    // Initialize your data structure.
    Deque(int n){
        size = n;
        arr = new int[size];
        frnt = rear = -1;

    }

       // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x){
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            frnt =rear = 0;
        }
        else if(frnt == 0 && rear != size-1){
             frnt = size-1;
        }
        else{
            frnt--;
        }
        arr[frnt] = x;
        return true;
    }

    
    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x){
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            frnt = rear = 0;
        }
        else if(rear == size-1 && frnt != 0){
            rear = 0;
        }
        else{
            rear++;
        }

        arr[rear] = x;
        return true;
    }

     // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront(){
        if(isEmpty()){
            return -1;
        }

        int ans = arr[frnt];
        arr[frnt] = -1;
        if(frnt == rear){
            frnt = rear = -1;
        }
        else if(frnt = size-1){
            frnt = 0;
        }
        else{
            frnt++;
        }

        return ans;
    }

    
    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear(){
        if(isEmpty()){
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if(frnt == rear){
            frnt = rear = -1;
        }
        else if(rear = 0){
            rear = size-1;

        }
        else{
            rear--;
        }
        return ans;
    }

      // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[frnt];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty(){
        if(frnt == -1){
            return true;
        }
        else{
            return false;
        }
    }

     // Returns true if the deque is full. Otherwise returns false.
    bool isFull(){
         if((frnt == 0 && rear == size-1) || (frnt != 0 && rear == (frnt-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }
};