#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int C,
    totalScore;
queue<int> answers;

void dfs(int cnt, int curScore, vector<vector<int>>& players, bool isSelected[11]){
    if(cnt == 11){
        totalScore = max(totalScore, curScore);
        return;
    }
    
    for(int i = 0; i < 11; ++i){    // 선수 별
        if(!isSelected[i] && players[i][cnt] != 0){
            isSelected[i] = true;
            dfs(cnt+1, curScore+players[i][cnt], players, isSelected);
            isSelected[i] = false;
        }
    }
}

void initAndSolve(){
    cin>>C;
    for(int i = 0; i < C; ++i){
        totalScore = INT_MIN;
        
        vector<vector<int>> players(11);
        for(int j = 0; j < 11; ++j){
            vector<int> player(11);
            for(int k = 0; k < 11; ++k){
                cin>>player[k];
            }
            players[j] = player;
        }
        
        bool isSelected[11] = {false};
        dfs(0, 0, players, isSelected);
        answers.push(totalScore);
    }
}

void printResults(){
    while(!answers.empty()){
        cout<<answers.front()<<"\n";
        answers.pop();
    }
}

int main(){
    initAndSolve();
    printResults();
    return 0;
}