#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <cmath>

// debug
#include <iostream>

using namespace std;

int answer = 0,
    len = 0;
unordered_set<string> cases;

int str2Int(string& num){
    int rt = 0;
    for(int i = 0; i < num.length(); ++i){
        rt *= 10;
        rt += (num[i]-'0');
    }
    return rt;
}

bool isPrime(string& num){
    int n = str2Int(num);
    
    if(n == 0 || n == 1)
        return false;
    
    for(int i = 2; i <= sqrt(n); ++i){
        if(n%i == 0) return false;
    }
    return true;
}

void search(string& nums){
    queue<pair<string, vector<bool>>> q;    // <숫자 조합, 사용 여부>
    for(int i = 0; i < len; ++i){
        if(nums[i] != '0'){
            vector<bool> tmpIsVisted(len, false);
            tmpIsVisted[i] = true;
            
            string tmpStr = "";
            tmpStr += nums[i];
            
            if(cases.find(tmpStr) == cases.end()){
                cases.insert(tmpStr);
                q.push(make_pair(
                    tmpStr, tmpIsVisted
                ));
            }
        }
    }
    while(!q.empty()){
        pair<string, vector<bool>> cur = q.front();
        q.pop();
        
        // debug
        // cout<<cur.first<<"\n";
        
        if(isPrime(cur.first)){
            ++answer;
        }
        
        for(int i = 0; i < len; ++i){
            if(!cur.second[i]){
                string tmpStr = cur.first;
                vector<bool> tmpIsVisted = cur.second;
                
                tmpStr += nums[i];
                tmpIsVisted[i] = true;
                
                if(cases.find(tmpStr) == cases.end()){
                    cases.insert(tmpStr);
                    q.push(make_pair(
                        tmpStr, tmpIsVisted
                    ));
                }
            }
        }
    }
}

int solution(string numbers) {
    len = numbers.length();
    search(numbers);
    return answer;
}