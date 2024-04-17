#include <string>
#include <vector>
#include <queue>
#include <climits>

// debug
#include <iostream>

#define MAX_N 100

using namespace std;

vector<int> map[MAX_N+1];
int minDiff = INT_MAX;

void init(int& n, vector<vector<int>>& wires){
    for(int i = 0; i < wires.size(); ++i){
        map[wires[i][0]].push_back(wires[i][1]);
        map[wires[i][1]].push_back(wires[i][0]);
    }
}

void search(int& n, vector<vector<int>>& wires){
    // i: 제외할 연결의 인덱스
    for(int i = 0; i < wires.size(); ++i){
        vector<bool> isVisited(n+1, false);
        queue<int> q;
        
        vector<int> removedConnect = wires[i];
        
        int group = 0, dif = 0;
        // 탐색 시작점 인덱스
        for(int j = 1; j <= n; ++j){
            if(!isVisited[j]){
                q.push(j);
                isVisited[j] = true;
                
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    
                    if(group == 0)
                        ++dif;
                    else if(group == 1)
                        --dif;
                    
                    vector<int>::iterator it;
                    for(it = map[cur].begin(); it != map[cur].end(); ++it){
                        
                        if(!isVisited[*it]
                            && !((cur == removedConnect[0] && (*it) == removedConnect[1])
                                || (cur == removedConnect[1] && (*it) == removedConnect[0]))){
                            // 제거된 연결이 아닌경우
                            q.push(*it);
                            isVisited[*it] = true;
                        }
                    }
                }
                ++group;
            }
        }
        
        minDiff = min(minDiff, abs(dif));
    }
}

int solution(int n, vector<vector<int>> wires) {
    init(n, wires);
    search(n, wires);
    return minDiff;
}