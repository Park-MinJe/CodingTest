#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

bool sortByRequestedTimie(vector<int>& v1, vector<int>& v2){
    return v1.at(0) < v2.at(0);
}

struct compare{
    bool operator()(const vector<int> v1, const vector<int> v2){
        return v1.at(1) > v2.at(1);
    }
};

priority_queue<vector<int>, vector<vector<int>>, compare> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0,
        j = 0,
        time = 0;
    
    sort(jobs.begin(), jobs.end(), sortByRequestedTimie);
    while(j < jobs.size() || !pq.empty()){
        if(j < jobs.size() && time >= jobs[j][0]){
            pq.push(jobs[j]);
            ++j;
            continue;
        }
        if(!pq.empty()){
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else{
            time = jobs[j][0];
        }
    }
    
    return answer / jobs.size();
}