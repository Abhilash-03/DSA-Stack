/*
You're given string ‘STR’ consisting solely of “{“, “}”, “(“, “)”, “[“ and “]” . Determine whether the parentheses are balanced.

Sample Input 1 :
2
[()]{}{[()()]()}
[(])
Sample Output 1 :
Balanced
Not Balanced
Explanation Of The Sample Input 1 :
In TestCase 1 there is always an opening brace before a closing brace i.e ‘{‘ before ‘}’, ‘(‘ before ‘)’, ‘[‘ before ‘]’.

In TestCase 2 there is closing brace for ‘[‘ i.e. ‘]’ before closing brace for ‘(‘ i.e. ‘)’. The balanced sequence should be ‘[()]’.
Sample Input 2 :
2
[[}[
[]{}()
Sample Output 2 :
Not Balanced
Balanced
Explanation Of The Sample Input 2 :
In TestCase 1 there is no opening brace before a closing brace i.e no ‘{‘ for ‘}’.

In TestCase 2 there is exactly one closing for each opening braces and each closing brace is after their corresponding opening brace.
*/
#include<bits/stdc++.h>
using namespace std;


bool isValidParenthesis(string expression)
{
    stack<char> s;

    for(int i = 0; i<expression.size(); i++){
        char ch = expression[i];

        if(ch == '(' || ch == '{' || ch== '['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                   char top = s.top();

                   if((ch == ')' && top == '(') || (ch == ']' && top=='[') || (ch == '}' && top=='{')){
                       s.pop();
                   }
                   else{
                      return false;
                   }
            }
            else{
                  return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}