#include <iostream>

#define MAX_N 100001
#define MAX_M 100001

using namespace std;

int arr[MAX_N];

int main(){
    int n, m;
    int s, e;
    
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; ++i){
        scanf(" %d", &arr[i]);
        arr[i] += arr[i-1];
    }
    
    for(int i = 0; i < m; ++i){
        scanf(" %d %d", &s, &e);
        printf("%d\n", arr[e]-arr[s-1]);
    }
    
    return 0;
}