#include <string>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <climits>

// debug
#include <iostream>

#define MAX_N 20000

using namespace std;

vector<int> vec[MAX_N+1];
map<int, int> mapLen;
int maxLen = INT_MIN,
    cntMaxLen = 0;

void init(vector<vector<int>>& edge){
    for(int i = 0; i < edge.size(); ++i){
        vec[edge[i][0]].push_back(edge[i][1]);
        vec[edge[i][1]].push_back(edge[i][0]);
    }
}

void search(int& n){
    vector<int> isVisited(n+1, false);
    queue<pair<int, int>> q;    // <노드 번호, 탐색에 걸린 길이>
    q.push(make_pair(
        1, 0
    ));
    isVisited[1] = true;
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        int leftWay = 0;
        for(int i = 0; i < vec[cur.first].size(); ++i){
            if(!isVisited[vec[cur.first][i]]){
                isVisited[vec[cur.first][i]] = true;
                ++leftWay;
                q.push(make_pair(
                    vec[cur.first][i], cur.second+1
                ));
            }
        }
        
        if(leftWay == 0){
            if(maxLen < cur.second){
                maxLen = cur.second;
                cntMaxLen = 1;
            }
            else if(maxLen == cur.second){
                ++cntMaxLen;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    init(edge);
    search(n);
    return cntMaxLen;
}