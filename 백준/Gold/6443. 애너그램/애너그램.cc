#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

int N;
queue<string> qInput;

void backtracking(string curStr, string& inputStr, int alphabetCnt[26]);

void initAndSovlve(){
    cin>>N;
    for(int i = 0; i < N; ++i){
        string tmpStr;
        cin>>tmpStr;
        
        int alphabetCnt[26] = {0};
        for(int j = 0; j < tmpStr.length(); ++j){
            alphabetCnt[tmpStr[j] - 'a']++;
        }
        backtracking("", tmpStr, alphabetCnt);
    }
}

void backtracking(string curStr, string& inputStr, int alphabetCnt[26]){
    if(curStr.length() == inputStr.length()){
        cout<<curStr<<"\n";
        return;
    }
    
    for(int i = 0; i < 26; ++i){
        if(alphabetCnt[i] > 0){
            alphabetCnt[i]--;
            backtracking(curStr + (char)('a' + i), inputStr, alphabetCnt);
            alphabetCnt[i]++;
        }
    }
}

int main(){
    initAndSovlve();
    return 0;
}