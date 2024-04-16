#include <string>
#include <vector>
#include <queue>
#include <tuple>

// debug
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int len = prices.size();
    for(int i = 0; i < len; ++i){
        if(i == len-1){
            answer.push_back(0);
        }
        else{
            answer.push_back(1);
        }
    }
    
    queue<pair<int, int>> qToCompare;  // <idx, price>
    for(int i = 0; i < len-1; ++i){
        queue<pair<int, int>> tmpQ;
        while(!qToCompare.empty()){
            pair<int, int> toCompare = qToCompare.front();
            qToCompare.pop();
            
            if(prices[i] >= toCompare.second){
                // debug
                // cout<<"Compare ["<<toCompare.first<<"] - ["<<i<<"]\n";
                
                ++answer[toCompare.first];
                tmpQ.push(toCompare);
            }
        }
        qToCompare = tmpQ;
        
        qToCompare.push(make_pair(
            i, prices[i]
        ));
    }
    
    return answer;
}