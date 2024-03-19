#include <iostream>

#define MAX_STAIR 301

using namespace std;

int n,
    stair[MAX_STAIR],
    dp[MAX_STAIR];
    
int _max(int a, int b){
    return a > b ? a : b;
}
    
void init(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf(" %d", &stair[i]);
    }
    
    dp[1] = stair[1];
    dp[2] = _max(stair[1]+stair[2], stair[2]);
    dp[3] = _max(stair[1]+stair[3], stair[2]+stair[3]);
}

void simulate(){
    for(int i = 4; i <= n; ++i){
        dp[i] = _max(dp[i-2]+stair[i], stair[i-1]+stair[i]+dp[i-3]);
    }
}

int main()
{
    init();
    simulate();
    printf("%d", dp[n]);
    return 0;
}