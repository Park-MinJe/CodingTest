#include <iostream>
#include <queue>

#define MAX_N 100000

using namespace std;

class cmp{
public:
    bool operator() (int n1, int n2){
        return n1 > n2;
    }
};

int N, answer;
priority_queue<int, vector<int>, cmp> pq;

void init(){
    cin>>N;
    for(int i = 0; i < N; ++i){
        int tmp;
        cin>>tmp;
        pq.push(tmp);
    }
}

void solve(){
    answer = 0;
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        answer += a + b;
        pq.push(a+b);
    }
}

int main(){
    init();
    solve();
    cout<<answer;
    return 0;
}