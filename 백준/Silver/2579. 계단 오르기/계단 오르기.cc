/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
    for(int i = 0; i < n; ++i){
        scanf(" %d", &stair[i]);
    }
    
    dp[0] = stair[0];
    dp[1] = _max(stair[0]+stair[1], stair[1]);
    dp[2] = _max(stair[0]+stair[2], stair[1]+stair[2]);
}

void simulate(){
    for(int i = 3; i < n; ++i){
        dp[i] = _max(dp[i-2]+stair[i], stair[i-1]+stair[i]+dp[i-3]);
    }
}

int main()
{
    init();
    simulate();
    printf("%d", dp[n-1]);
    return 0;
}