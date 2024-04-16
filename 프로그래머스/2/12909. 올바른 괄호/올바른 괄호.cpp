#include<string>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    if(s[0] == ')')
        return false;

    stack<char> st;
    for(int i = 0; i < s.length(); ++i){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        if(s[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }
            else{
                return false;
            }
        }
        else{
            st.push(s[i]);
        }
    }
    
    if(!st.empty()){
        return false;
    }

    return true;
}