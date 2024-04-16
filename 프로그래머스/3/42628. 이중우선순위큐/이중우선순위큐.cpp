#include <string>
#include <vector>
#include <deque>
#include <algorithm>

// debug
#include <iostream>

using namespace std;

deque<int> dq;

int str2Int(string str){
    int rt = 0;
    if(str[0] == '-'){
        for(int i = 1; i < str.length(); ++i){
            rt *= 10;
            rt += str[i]-'0';
        }
        rt *= -1;
    }
    else{
        for(int i = 0; i < str.length(); ++i){
            rt *= 10;
            rt += str[i]-'0';
        }
    }
    return rt;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int opLen = operations.size();
    for(int i = 0; i < opLen; ++i){
        char cmd = operations[i][0];
        string op = operations[i].substr(2);
        int op2Int = str2Int(op);
        
        if(cmd == 'I'){
            dq.push_back(op2Int);
        }
        else if(cmd == 'D'){
            if(!dq.empty()){
                if(op.compare("1") == 0){
                    dq.pop_back();
                }
                else if(op.compare("-1") == 0){
                    dq.pop_front();
                }
            }
        }
        sort(dq.begin(), dq.end());
    }
    
    if(dq.empty()){
        for(int i = 0; i < 2; ++i)
            answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}