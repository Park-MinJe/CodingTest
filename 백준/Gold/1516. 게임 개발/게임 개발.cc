#include <iostream>
#include <vector>
#include <queue>
#define MAX 501

using namespace std;

int n, inDegree[MAX], _time[MAX], result[MAX];
vector<int> arch[MAX];

void calcMinSumOf_time(){
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(inDegree[i] == 0){
            result[i] = _time[i];
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int j = 0; j < arch[x].size(); ++j){
            int y = arch[x][j];
            result[y] = max(result[y], result[x] + _time[y]);
            if(--inDegree[y] == 0){
                q.push(y);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        printf("%d\n", result[i]);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        inDegree[i] = 0;
        _time[i] = 0;
        result[i] = 0;
    }
    
    int tmp;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &tmp);
        if(tmp != -1) _time[i] = tmp;
        else continue;
        
        scanf("%d", &tmp);
        while(tmp != -1) {
            arch[tmp].push_back(i);
            inDegree[i]++;
            scanf("%d", &tmp);
        }
    }
    
    calcMinSumOf_time();
}