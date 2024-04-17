#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<vector<int>> vec = {
    {1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5},
};
vector<int> vecSizes;
vector<pair<int, int>> scores;

bool comp(pair<int, int>& p1, pair<int, int>& p2){
    if(p1.second > p2.second){
        return true;
    }
    else if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    
    return false;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    for(int i = 0; i < vec.size(); ++i){
        vecSizes.push_back(vec[i].size());
        scores.push_back(make_pair(
            i+1, 0
        ));
    }
    
    for(int i = 0; i < answers.size(); ++i){
        for(int j = 0; j < 3; ++j){
            if(answers[i] == vec[j][i%vecSizes[j]]){
                ++(scores[j].second);
            }
        }
    }
    
    sort(scores.begin(), scores.end(), comp);
    answer.push_back(scores[0].first);
    int maxScore = scores[0].second;
    for(int i = 1; i < scores.size(); ++i){
        if(scores[i].second == maxScore)
            answer.push_back(scores[i].first);
        else
            break;
    }
    
    return answer;
}