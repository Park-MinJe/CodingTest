#include <iostream>

#define MAX_N 1001
#define RGB 3
#define INF 999999999

using namespace std;

int n, minCost;
int** cost; // 0-빨강, 1-초록, 2-파랑
int** dp;   // 0-빨강, 1-초록, 2-파랑

void init(){
    scanf("%d", &n);
    cost = new int*[n+1];
    dp = new int*[n+1];
    for(int i = 1; i <= n; ++i){
        cost[i] = new int[RGB];
        dp[i] = new int[RGB];
        for(int j = 0; j < RGB; ++j){
            scanf(" %d", &cost[i][j]);
            dp[i][j] = INF;
        }
    }
}

int _min(int a, int b){
    return a < b ? a:b;
}

void simulate(){
    for(int i = 0; i < RGB; ++i){
        dp[1][i] = cost[1][i];
    }
    for(int i = 2; i <= n; ++i){
        int preIdx = i-1;
        dp[i][0] = _min(dp[preIdx][1], dp[preIdx][2]) + cost[i][0];
        dp[i][1] = _min(dp[preIdx][0], dp[preIdx][2]) + cost[i][1];
        dp[i][2] = _min(dp[preIdx][1], dp[preIdx][0]) + cost[i][2];
    }
    
    minCost = _min(dp[n][0], dp[n][1]);
    minCost = _min(minCost, dp[n][2]);
}

int main(){
    init();
    simulate();
    printf("%d", minCost);
    //debug
    // printf("\n");
    // for(int i = 1; i <= n; ++i){
    //     printf("%d ", color[i]);
    // }
    return 0;
}