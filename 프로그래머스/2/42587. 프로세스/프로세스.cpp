#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

queue<pair<int, int>> q;    // <우선순위, 초기 위치>
priority_queue<int> pqPriorities;

int solution(vector<int> priorities, int location) {
    int inputSize = priorities.size();
    for(int i = 0; i < inputSize; ++i){
        q.push(make_pair(
            priorities[i], i
        ));
        pqPriorities.push(priorities[i]);
    }
    
    int cnt = 0;
    while(!q.empty()){
        pair<int, int> curProcess = q.front();
        q.pop();
        
        if(curProcess.first < pqPriorities.top()){
            q.push(curProcess);
            continue;
        }
        
        pqPriorities.pop();
        ++cnt;
        if(curProcess.second == location){
            return cnt;
        }
    }
}