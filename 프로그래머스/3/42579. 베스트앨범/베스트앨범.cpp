#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, pair<int, vector<pair<int, int>>>> mapSongs;
    // <장르, pair<장르별 재생 횟수, vector<pair<곡별 재생 횟수, 곡별 고유 번호>>>>

bool sortPerGenre(pair<string, pair<int, vector<pair<int, int>>>>& p1,
             pair<string, pair<int, vector<pair<int, int>>>>& p2){
    return p1.second.first > p2.second.first;
}
bool sortPerSong(pair<int, int>& p1, pair<int, int>& p2){
    if(p1.first > p2.first){
        return true;
    }
    else if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    else{
        return false;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int cntSongs = genres.size();
    for(int i = 0; i < cntSongs; ++i){
        mapSongs[genres[i]].first += plays[i];
        mapSongs[genres[i]].second.push_back(
            make_pair(
                plays[i], i
            )
        );
    }
    vector<pair<string, pair<int, vector<pair<int, int>>>>> vecToSort(
        mapSongs.begin(), mapSongs.end()
    );
    sort(vecToSort.begin(), vecToSort.end(), sortPerGenre);
    
    vector<pair<string, pair<int, vector<pair<int, int>>>>>::iterator itToSort;
    for(itToSort = vecToSort.begin(); itToSort != vecToSort.end(); ++itToSort){
        sort((itToSort->second).second.begin(), (itToSort->second).second.end(), sortPerSong);
        
        for(int i = 0; i < (itToSort->second).second.size(); ++i){
            answer.push_back((itToSort->second).second[i].second);
            if(i == 1) break;
        }
    }
    
    return answer;
}