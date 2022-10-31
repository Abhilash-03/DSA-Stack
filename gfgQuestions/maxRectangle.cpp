/*
Max rectangle

Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1

*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
    private:
    int largestRectangleArea(int * heights, int n) {
          int maxArea = 0;
          stack<int>s;

          for(int i = 0; i<=n; i++){
            int currHeight = i == n? 0 : heights[i];

            while(!s.empty() && currHeight < heights[s.top()]){
                int top = s.top();
                s.pop();

                int width = s.empty()? i : i - s.top() - 1;

                int area = heights[top] * width;
                maxArea = max(area, maxArea);
            }

            s.push(i);
          }
          return maxArea;
    }

    public:
    int maxArea(int M[MAX][MAX], int n, int m){
      //compute area for 1st row
        int area = largestRectangleArea(M[0], m);

        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){

               //row udpate: by adding previous row's value
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else{
                    M[i][j] = 0;    
                }
            }

            area = max(area, largestRectangleArea(M[i], m));
        }
          
          return area;
    }
};