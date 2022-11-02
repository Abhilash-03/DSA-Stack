/*
You will be given ‘Q’ queries. You need to implement a circular queue according to those queries. Each query will belong to one of these two types:
1 ‘X’: Enqueue element ‘X’ into the end of the nth queue. Returns true if the element is enqueued, otherwise false.

2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.
Note:
Enqueue means adding an element to the end of the queue, while Dequeue means removing the element from the front of the queue.

Sample Input 1:
3 7
1 2 
1 3 
2 
1 4 
1 6 
1 7 
2
Sample Output 1:
True 
True
2
True
True
False
3
Explanation Of Sample Output 1:
For this input, we have the size of the queue, 'N' = 3, and the number of queries, 'Q' = 7.

Operations performed on the queue are as follows:

push(2): Push element ‘2’ into the queue. This returns true.
push(3): Push element ‘3’ into the queue. This returns true.
pop(): Pop the top element from the queue. This returns 2.
push(4): Push element ‘4’ into the queue. This returns true.
push(6): Push element ‘6’ into the queue. This returns true.
push(7): Push element ‘7’ into the queue. This returns false because the queue is full.
pop(): Pop the top element from the queue. This returns 3.
Sample Input 2:
4 7
1 11 
1 51 
1 26 
2 
1 6
2
2 
Sample Output 2:
True
True
True
11
True
51
26
Explanation For Sample Output 2:
For this input, we have the size of the queue, 'N' = 3, and the number of queries, 'Q' = 7.

Operations performed on the queue are as follows:

push(11): Push element ‘11’ into the queue. This returns true.
push(51): Push element ‘51’ into the queue. This returns true.
push(26): Push element ‘26’ into the queue. This returns true.
pop(): Pop the top element from the queue. This returns 11.
push(6): Push element ‘6’ into the queue. This returns true.
pop(): Pop the top element from the queue. This returns 51.
pop(): Pop the top element from the queue. This returns 26.
*/

#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
     int* arr;
     int size;
     int frnt;
     int rear;
public:
      CircularQueue(int n){
        size = n;
        arr = new int[size];
        frnt = rear = -1;
      }
      // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((frnt == 0 && rear == size-1) || (rear = (frnt-1)%(size-1))){
            return true;
        }
        else if(frnt = -1){//first element has to be pushed
            frnt = rear = 0;
        }
        else if(rear = size-1 && frnt != 0){
            rear = 0; //to maintain cyclic nature.
        }
        else{
            rear++; // normal flow
        }

        arr[rear] = value;
        return true;
    }

    
    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(frnt == -1){
            return -1;
        }
        int ans = arr[frnt];
        arr[frnt] = -1;

//only one element is present
        if(frnt == rear){
            frnt = rear = -1;
        }
        //front reached at last so maintain the cyclic nature
        else if(frnt = size-1){
            frnt = 0; 
        }
        else{
            frnt++;
        }

        return ans;

    }
};
