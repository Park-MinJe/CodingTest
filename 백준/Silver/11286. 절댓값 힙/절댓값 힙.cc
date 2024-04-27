#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int N;
priority_queue<int> pq;
unordered_map<int, priority_queue<int>> map;
queue<int> answer;

void init(){
    cin>>N;
}

void solve(){
    for(int i = 0; i < N; ++i){
        int x;
        cin>>x;
        
        if(x != 0){
            pq.push(abs(x) * (-1));
            map[abs(x)].push(x*(-1));
        }
        else{
            if(!pq.empty()){
                int curMinAbs = pq.top() * (-1);
                pq.pop();
                
                answer.push(map[curMinAbs].top() * (-1));
                map[curMinAbs].pop();
            }
            else{
                answer.push(0);
            }
        }
    }
}

void printAnswer(){
    while(!answer.empty()){
        cout<<answer.front()<<"\n";
        answer.pop();
    }
}

int main(){
    init();
    solve();
    printAnswer();
    return 0;
}