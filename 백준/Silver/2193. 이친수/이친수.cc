#include <iostream>

#define MAX_N 91

using namespace std;

int N;
long long nCr[MAX_N][MAX_N],
    result = 0;
    
void init(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        nCr[i][0] = 1;
        nCr[i][1] = i;
        nCr[i][i] = 1;
        nCr[i][i-1] = i;
    }
}

long long combi(int n, int r){
    if(nCr[n][r] != 0){
        return nCr[n][r];
    }
    
    nCr[n-1][r] = combi(n-1, r);
    nCr[n-1][r-1] = combi(n-1, r-1);
    return nCr[n-1][r] + nCr[n-1][r-1];
}

void solv(){
    if(N == 1){
        result = 1;
        return;
    }
    
    int maxOnes = (N+1)/2;
    for(int i = 1; i <= maxOnes; ++i){
        int zeros = N-i,
            r = i-1;
        result += combi(zeros, r);
    }
}

int main(){
    init();
    solv();
    printf("%lld", result);
    return 0;
}