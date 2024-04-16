#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

unordered_map<string, int> mapClothes;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    vector<vector<string>>::iterator itClothes;
    for(itClothes = clothes.begin(); itClothes != clothes.end(); ++itClothes){
        ++mapClothes[(*itClothes)[1]];
    }
    
    unordered_map<string, int>::iterator itMap;
    for(itMap = mapClothes.begin(); itMap != mapClothes.end(); ++itMap){
        answer *= (itMap->second + 1);
    }
    
    return answer - 1;
}