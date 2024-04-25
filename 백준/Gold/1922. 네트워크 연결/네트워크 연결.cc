#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000
#define MAX_M 100000

using namespace std;

class Edge{
public:
    int n1, n2, w;
    Edge(){}
    Edge(int iN1, int iN2, int iW): n1(iN1), n2(iN2), w(iW){}
};

int N, M,
    Parents[MAX_N+1],
    answer = 0;
vector<Edge*> lstEdges;

bool compareW(Edge* e1, Edge* e2){
    if(e1->w < e2->w){
        return true;
    }
    else if(e1->w == e2->w){
        return e1->n1 == e2->n2;
    }
    return false;
}

void init(){
    cin>>N;
    cin>>M;
    for(int i = 1; i <= N; ++i){
        Parents[i] = i;
    }
    for(int i = 0; i < M; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        
        lstEdges.push_back(new Edge(min(a, b), max(a, b), c));
    }
    sort(lstEdges.begin(), lstEdges.end(), compareW);
}

int find(int n){
    if(Parents[n] == n) return n;
    else return Parents[n] = find(Parents[n]);
}

void Union(int n1, int n2){
    int n1Parent = find(n1),
        n2Parent = find(n2);
    if(n1Parent != n2Parent) Parents[n2Parent] = n1Parent;
}

bool isSameParent(int n1, int n2){
    int n1Parent = find(n1),
        n2Parent = find(n2);
    return n1Parent == n2Parent;
}

void solve(){
    for(int i = 0; i < M; ++i){
        Edge* cur = lstEdges[i];
        if(isSameParent(cur->n1, cur->n2))
            continue;
        answer += cur->w;
        Union(cur->n1, cur->n2);
    }
}

int main(){
    init();
    solve();
    cout<<answer;
    return 0;
}