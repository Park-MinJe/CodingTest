#include <iostream>
#include <queue>
#include <string>

using namespace std;

int T;                    // 문자열의 개수 (1<=T<=30)
vector<string> lstStrs;
queue<int> lstAnswers;    // 회문-0 / 유사 회문-1 / 이외-2

int getStrType(int left, int right, bool hasDeleted, string& str){
    while(left < right){
        if(str[left] != str[right]){    // 양쪽 문자가 다른 경우 발견
            if(hasDeleted) return 2;    // 회문, 유사 회문 모두 아닌 경우
            
            if(getStrType(left+1, right, true, str) == 0
              || getStrType(left, right-1, true, str) == 0){
                return 1;
            }
            else return 2;                // 회문, 유사 회문 모두 아닌 경우
        }
        else{
            ++left;
            --right;
        }
    }
    
    return 0;                            // 회문인 경우
}

void initAndSolve(){
    cin>>T;
    for(int i = 0; i < T; ++i){
        string tmpStr;
        cin>>tmpStr;
        
        lstAnswers.push(getStrType(0, tmpStr.length()-1, false, tmpStr));
    }
}

void printResults(){
    while(!lstAnswers.empty()){
        cout<<lstAnswers.front()<<"\n";
        lstAnswers.pop();
    }
}

int main(){
    initAndSolve();
    printResults();
    return 0;
}