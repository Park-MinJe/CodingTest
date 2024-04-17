#include <string>
#include <vector>
#include <queue>

#define MAX_PLAYERS 100

using namespace std;

vector<int> toChild[MAX_PLAYERS+1];
vector<int> toParent[MAX_PLAYERS+1];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 0; i < results.size(); ++i){
        toChild[results[i][0]].push_back(results[i][1]);
        toParent[results[i][1]].push_back(results[i][0]);
    }
    
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        vector<bool> isVisted(n+1, false);
        int cntVisted = 0;
        
        // 부모 노드를 통해 접근할 수 있는 노드 수 구하기
        q.push(i);
        isVisted[i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int j = 0; j < toParent[cur].size(); ++j){
                if(!isVisted[toParent[cur][j]]){
                    q.push(toParent[cur][j]);
                    isVisted[toParent[cur][j]] = true;
                    ++cntVisted;
                }
            }
        }
        
        // 방문 여부 초기화
        for(int j = 1; j <= n; ++j){
            isVisted[j] = false;
        }

        // 자식 노드를 통해 접근할 수 있는 노드 수 구하기
        q.push(i);
        isVisted[i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int j = 0; j < toChild[cur].size(); ++j){
                if(!isVisted[toChild[cur][j]]){
                    q.push(toChild[cur][j]);
                    isVisted[toChild[cur][j]] = true;
                    ++cntVisted;
                }
            }
        }
        
        if(cntVisted == (n-1))
            ++answer;
    }
    
    return answer;
}