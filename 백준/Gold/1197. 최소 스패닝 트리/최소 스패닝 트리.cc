#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_V 10000

using namespace std;

class Vect{
public:
    int n1, n2, w;
    Vect(){}
    Vect(int iN1, int iN2, int iW): n1(iN1), n2(iN2), w(iW){}
};

int V, E,
    rotateTab[MAX_V+1];
long long answer = 0;
vector<Vect*> lstVect;

bool compareW(Vect* v1, Vect* v2){
    if(v1->w < v2->w){
        return true;
    }
    else if(v1->w == v2->w){
        return v1->n1 < v2->n1;
    }
    else{
        return false;
    }
}

void init(){
    cin>>V>>E;
    for(int i = 1; i <= V; ++i){
        rotateTab[i] = i;
    }
    for(int i = 0; i < E; ++i){
        int A, B, C;
        cin>>A>>B>>C;
        
        Vect* newVect = new Vect();
        newVect->n1 = min(A, B);
        newVect->n2 = max(A, B);
        newVect->w = C;
        lstVect.push_back(newVect);
    }
    sort(lstVect.begin(), lstVect.end(), compareW);
}

int Find(int n){
    if(rotateTab[n] == n) return n;
    else return rotateTab[n] = Find(rotateTab[n]);
}

void Union(int n1, int n2){
    n1 = Find(n1);
    n2 = Find(n2);
    
    if(n1 != n2) rotateTab[n2] = n1;
}

bool SameParent(int n1, int n2){
    n1 = Find(n1);
    n2 = Find(n2);
    return n1 == n2;
}

void solve(){
    for(int i = 0; i < lstVect.size(); ++i){
        Vect* cur = lstVect[i];
        if(SameParent(cur->n2, cur->n1))
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