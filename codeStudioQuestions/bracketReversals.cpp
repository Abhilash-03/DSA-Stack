/*
Minimum Cost To Make String Valid

Problem Statement
Suggest Edit
Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the brackets are balanced. Formally for each opening bracket, there must be a closing bracket right to it.
For Example:
“{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such operation is 1.
Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.
For Example:
Minimum operations to make ‘STR’ =  “{{“ valid is 1.
In one operation, we can convert ‘{’ at index ‘1’ (0-based indexing) to ‘}’. The ‘STR’ now becomes "{}" which is a valid string.
Note:
Return -1 if it is impossible to make ‘STR’ valid.

Sample Input 1:
2
{{{}
{{}{}}
Sample Output 1:
1
0
Explanation For Sample Input 1:
For the first test case:
The two valid strings that can be obtained from  ‘STR’ using minimum operations “{{}}”   and “{}{}”. Ninja can transform ‘STR’ to “{{}}” by performing the following operations:
Convert ‘{’ at index 2 to ‘}’.

Ninja can transform ‘STR’ to “{}{}” by performing the following operations:
Convert ‘{‘ at index 1 to ‘}’.
The minimum number of operations in transforming ‘STR’ to either of the two valid strings is 1.So, the total cost is 1.

For the second test case:
Given ‘STR’ is already valid so the minimum number of 
operations required is 0.
So, the total cost is 0.
Sample Input 2:
3
{}}{}}
{{{{
{{{}}
Sample Output 2:
1
2
-1
*/

#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string str){
    //when odd condition.
    if(str.size()%2 != 0){
        return -1;
    }

    stack<char> s;

    for(int i=0; i<str.size(); i++){
        char ch = str[i];

        if(ch == '{'){
            s.push(ch);
        }
        else{
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }

    int a = 0, b = 0;
    while(!s.empty()){
        if(s.top() == '{'){
            a++;
        }
        else{
            b++;
        }

        s.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}