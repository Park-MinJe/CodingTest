#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> mapParticipantCnt;

bool compareNameCnt(pair<string, int>& p1, pair<string, int>& p2){
    return p1.second > p2.second;
}

string solution(vector<string> participant, vector<string> completion) {
    vector<string>::iterator it;
    for(it = participant.begin(); it != participant.end(); ++it){
        ++mapParticipantCnt[*it];
    }
    
    for(it = completion.begin(); it != completion.end(); ++it){
        --mapParticipantCnt[*it];
    }
    
    vector<pair<string, int>> vec(mapParticipantCnt.begin(), mapParticipantCnt.end());
    sort(vec.begin(), vec.end(), compareNameCnt);
    
    return vec[0].first;
}