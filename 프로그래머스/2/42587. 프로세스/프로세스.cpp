#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

queue<pair<int, int>> q;    // <우선순위, 초기 위치>

int solution(vector<int> priorities, int location) {
    int inputSize = priorities.size();
    for(int i = 0; i < inputSize; ++i){
        q.push(make_pair(
            priorities[i], i
        ));
    }
    
    int cnt = 0;
    while(!q.empty()){
        pair<int, int> curProcess = q.front();
        q.pop();
        
        bool isExecutable = true;
        queue<pair<int, int>> tmp;
        while(!q.empty()){
            pair<int, int> tmpP = q.front();
            tmp.push(tmpP);
            q.pop();
            
            if(tmpP.first > curProcess.first){
                isExecutable = false;
            }
        }
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        
        if(isExecutable){
            if(curProcess.second == location){
                ++cnt;
                return cnt;
            }
            else{
                ++cnt;
            }
        }
        else{
            q.push(curProcess);
        }
    }
}