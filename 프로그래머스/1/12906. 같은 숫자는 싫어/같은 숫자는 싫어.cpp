#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    deque<int> dq;
    vector<int>::iterator it;
    for(it = arr.begin(); it != arr.end(); ++it){
        if(dq.empty()){
            dq.push_back(*it);
            continue;
        }
        
        if(dq.back() != (*it)){
            dq.push_back(*it);
        }
    }
    
    vector<int> answer;
    while(!dq.empty()){
        answer.push_back(dq.front());
        dq.pop_front();
    }

    return answer;
}