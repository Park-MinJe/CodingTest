#include <iostream>
#include <queue>
//#include <unordered_map>

using namespace std;

class cmp{
public:
    bool operator() (int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

int N;
priority_queue<int, vector<int>, cmp> pq;
//priority_queue<int> pq;
//unordered_map<int, priority_queue<int>> map;
queue<int> answer;

void init(){
    cin>>N;
}

void solve(){
    for(int i = 0; i < N; ++i){
        int x;
        cin>>x;
        
        if(x != 0){
            /*pq.push(abs(x) * (-1));
            map[abs(x)].push(x*(-1));*/
            
            pq.push(x);
        }
        else{
            if(!pq.empty()){
                /*int curMinAbs = pq.top() * (-1);
                pq.pop();
                
                answer.push(map[curMinAbs].top() * (-1));
                map[curMinAbs].pop();*/
                
                answer.push(pq.top());
                pq.pop();
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