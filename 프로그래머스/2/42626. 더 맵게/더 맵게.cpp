#include <string>
#include <vector>
#include <queue>
#include <climits>

// debug
#include <iostream>

using namespace std;

priority_queue<int> pqScoville;

int solution(vector<int> scoville, int K) {
    int answer = 0, minVal = INT_MAX;
    
    vector<int>::iterator it;
    for(it = scoville.begin(); it != scoville.end(); ++it){
        pqScoville.push((*it) * (-1));
        if(minVal > *it)
            minVal = *it;
    }
    // debug
    // cout<<pqScoville.size()<<"\n";
    
    while(minVal < K){
        if(pqScoville.size() < 2){
            answer = -1;
            break;
        }
        ++answer;
        
        int v1, v2, newV;
        v1 = pqScoville.top() * (-1);
        pqScoville.pop();
        v2 = pqScoville.top() * (-1);
        pqScoville.pop();
        
        newV = v1 + v2*2;
        pqScoville.push(newV * (-1));
        minVal = pqScoville.top()*(-1);
        
        // debug
        // cout<<answer<<"::"<<newV<<" "<<minVal<<"\n";
    }
    
    return answer;
}