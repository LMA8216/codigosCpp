#include <iostream>
#include <bits/stdc++.h>

/*D1 - Given an expression string exp, write a program to examine whether the pairs and 
the orders of parenthesis "(" and ")" are correct in exp.
For example, the program should print true for exp = ()(()) and false for exp = ())(

exp = "()(())"  answer: true
exp = "())("    answer: false
*/

using namespace std;

bool correctOrWrong(string);

int main(){

    bool b;
    string exp = "()(())";
    
    b = correctOrWrong(exp);
    
    if (b)
        cout << "exp = \"" << exp << "\" " << "answer: true" << endl; 
    
    else
        cout << "exp = \"" << exp << "\" " << "answer: false" << endl;
    
    
    return 0;
}

bool correctOrWrong(string s){

    stack<char> stk;
    int lenght = s.length();

    if(s.empty())
        return false;
    else
    {   //check the whole string, 
        for (size_t i = 0; i < lenght; i++)
        {
            if (s[i] == '(')
            {   //if the element open parantheses then push to stack 
                stk.push(s[i]);
                continue;
            }
                //stk empty means that there is no one open parenthesis waiting to be close
            if (stk.empty())
                return false;
                // close a open parenthesis and pop tha stack
            if (s[i] == ')')
                stk.pop();
        }
    }

    // if the stack is empty means that all the open parenthesis were closed, otherwise the string is wrong 
    return stk.empty();
}