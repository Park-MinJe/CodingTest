#include <string>
#include <vector>
#include <queue>
#include <tuple>

// debug
#include <iostream>

using namespace std;

int canTravel = 0;

void search(int& k, vector<vector<int>>& dungeons){
    int cntDungeons = dungeons.size();
    for(int i = 0; i < cntDungeons; ++i){
        if(k < dungeons[i][0]){
            continue;
        }
        
        queue<tuple<int, vector<int>, vector<bool>>> q;
        // 현재 남은 체력, 방문한 던전의 인덱스, 방문여부 배열 저장
        
        vector<int> tmpCase;
        tmpCase.push_back(i);
        
        vector<bool> tmpIsVisted(cntDungeons, false);
        tmpIsVisted[i] = true;
        
        q.push(make_tuple(
            k - dungeons[i][1], tmpCase, tmpIsVisted
        ));
        
        while(!q.empty()){
            tuple<int, vector<int>, vector<bool>> cur = q.front();
            q.pop();
            
            int curSize = get<1>(cur).size();
            // debug
            // for(int j = 0; j < curSize; ++j){
            //     cout<<get<1>(cur)[j]<<" ";
            // }
            // cout<<"\n";
            
            if(curSize > canTravel){
                // debug
                // cout<<canTravel<<"->"<<curSize<<"\n";
                
                canTravel = curSize;
                if(canTravel == cntDungeons)
                    return;
            }
            
            for(int j = 0; j < cntDungeons; ++j){
                if(!get<2>(cur)[j] && get<0>(cur) >= dungeons[j][0]){
                    int tmpK = get<0>(cur) - dungeons[j][1];
                    
                    vector<int> tmpC = get<1>(cur);
                    tmpC.push_back(j);
                    
                    vector<bool> tmpIV = get<2>(cur);
                    tmpIV[j] = true;
                    
                    q.push(make_tuple(
                        tmpK, tmpC, tmpIV
                    ));
                }
            }
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    search(k, dungeons);
    return canTravel;
}