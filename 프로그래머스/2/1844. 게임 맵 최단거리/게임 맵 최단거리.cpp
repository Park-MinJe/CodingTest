#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int n, m,
    dr[4] = {-1, 0, 1, 0},
    dc[4] = {0, 1, 0, -1},
    minDist = INT_MAX;

bool inRange(int r, int c){
    return 0<=r&&r<n && 0<=c&&c<m;
}
bool isAccesible(vector<vector<int> >& maps, int r, int c){
    return inRange(r, c) && maps[r][c] == 1;
}
bool isTarget(int r, int c){
    return r == n-1 && c == m-1;
}

int bfs(vector<vector<int> >& maps){
    vector<vector<bool>> isVisitable;
    for(int i = 1; i <= n; ++i){
        vector<bool> tmpVec(m, false);
        isVisitable.push_back(tmpVec);
    }
    bool isSuccessed = false;
    
    queue<pair<pair<int, int>, int>> q;     // <<r, c>, moved distance>
    q.push(make_pair(make_pair(0, 0), 1));
    isVisitable[0][0] = true;
    
    while(!q.empty()){
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        
        if(isTarget(cur.first.first, cur.first.second) && minDist > cur.second){
            minDist = cur.second;
            isSuccessed = true;
        }
        
        for(int i = 0; i < 4; ++i){
            int nr = cur.first.first + dr[i],
                nc = cur.first.second + dc[i];
            
            if(isAccesible(maps, nr, nc) && !isVisitable[nr][nc]){
                q.push(make_pair(make_pair(nr, nc), cur.second + 1));
                isVisitable[nr][nc] = true;
            }
        }
    }
    
    if(isSuccessed){
        return minDist;
    }
    else{
        return -1;
    }
}

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    return bfs(maps);
}