#include <iostream>

#define MAX_N 1001
#define MOD 10007

using namespace std;

int N, result = 0,
    nCr[MAX_N][MAX_N];

void init(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        nCr[i][0] = 1;
        nCr[i][i] = 1;
        
        nCr[i][1] = i;
        nCr[i][i-1] = i;
    }
    
}

int _min(int a, int b){
    return a < b ? a:b;
}

int combi(int n, int r){
    if(nCr[n][r] != 0){
        return nCr[n][r];
    }
    
    int cmb1 = combi(n-1, r),
        cmb2 = combi(n-1, r-1);
    nCr[n][r] = (nCr[n-1][r] + nCr[n-1][r-1])%MOD;
    
    return nCr[n][r];
}

void solve(){
    int cntTwo = N/2;
    for(int i = 0; i <= cntTwo; ++i){
        int cntOne = N-i*2,
            n = cntOne+i,
            r = _min(i, n-i);
        
        int tmp = combi(n, r);
        //printf("%dC%d = %d\n", n, i, tmp);
        result += tmp;
    }
}

int main(){
    init();
    solve();
    printf("%d", result%MOD);
    return 0;
}