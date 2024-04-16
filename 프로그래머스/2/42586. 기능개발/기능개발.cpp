#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> leftDays;
    int jobs = progresses.size();
    for(int i = 0; i < jobs; ++i){
        leftDays.push(
            ceil((100-progresses[i]) / ((double)speeds[i]))
        );
    }
    
    while(!leftDays.empty()){
        int curWork = leftDays.front(),
            curCnt = 1;
        leftDays.pop();
        
        while(!leftDays.empty()){
            int nextWork = leftDays.front();
            if(nextWork > curWork){
                break;
            }
            
            ++curCnt;
            leftDays.pop();
        }
        
        answer.push_back(curCnt);
    }
    
    return answer;
}