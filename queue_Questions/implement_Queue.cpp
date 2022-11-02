/*
Implement a Queue Data Structure specifically to store integer data using a Singly Linked List or an array.
You need to implement the following public functions :
1. Constructor: It initializes the data members as required.

2. enqueue(data): This function should take one argument of type integer. It enqueues the element into the queue.

3. dequeue(): It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.

4. front(): It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.

5. isEmpty(): It returns a boolean value indicating whether the queue is empty or not.

Operations Performed On The Queue :
Query-1(Denoted by an integer 1): Enqueues integer data to the queue.

Query-2(Denoted by an integer 2): Dequeues the data kept at the front of the queue and returns it to the caller, return -1 if no element is present in the queue.

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the front of the queue but doesn't remove it, unlike the dequeue function, return -1 if no element is present in the queue.

Query-4(Denoted by an integer 4): Returns a boolean value denoting whether the queue is empty or not.

Sample Input 1 :
1
7
1 17
1 23
1 11
2
2
2
2
Sample Output 1 :
17
23
11
-1
Explanation For Sample Output 1 :
The first three queries are of enQueue, so we will push 17, 23, and 11 into the queue.

The next four queries are of deQueue, so we will starting removing elements from the queue, so the first element will be 17, then 23, and then 11. And after the third dequeue query, the queue is now empty so for the fourth query, we will return -1.
Sample Input 2 :
1
3
2
1 10
3
Sample Output 2 :
-1 
10

*/

#include <bits/stdc++.h>
using namespace std;

class Queue {
     int *arr;
     int size;
     int frnt;
     int rear;

     public:
    Queue() {
         size = 100001;
        arr = new int[size];
        frnt = rear = 0;
     }

     bool isEmpty(){
        if(frnt == rear){
            return true;
        }
        else{
            return false;
        }
     }

     void enqueue(int data){
        //queue is full or not
        if(rear == size){
            cout<<"Queue if full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }

        
    int dequeue(){
        //queue is empty or not
        if(frnt == rear){
            return -1;
        }
        else{
            int ans = arr[frnt];
            arr[frnt] = -1;
            frnt++;
            if(frnt == rear){
                frnt = rear = 0;
            }
            return ans;
        }
    }

     int front() {
        if(frnt == rear){
            return -1;
        }
        else{
            return arr[frnt];
        }
     }
     }
};