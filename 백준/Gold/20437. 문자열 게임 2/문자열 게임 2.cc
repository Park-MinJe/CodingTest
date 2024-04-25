// 문제 링크: https://www.acmicpc.net/problem/20437
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <climits>
#include <queue>

#define MAX_T 100

using namespace std;

int T, K,
    answer3[MAX_T],		// t번째 문장에 대해 3번 조건을 만족하는 가장 짧은 문장의 길이
    answer4[MAX_T];		// t번째 문장에 대해 4번 조건을 만족하는 가장 긴 문장의 길이
string W;				// 문장 입력 받을 변수

// 입력과 3, 4번 조건 충족 여부 판단
void initAndSolve(){
    cin>>T;
    for(int i = 0; i < T; ++i){
        unordered_map<char, pair<int, queue<int>>> mapAlphabat;	// 문자별 개수, 위치한 인덱스 배열
        
        cin>>W;
        cin>>K;
        
        answer3[i] = INT_MAX;
        answer4[i] = INT_MIN;
        
        int tmpLen = W.length();
        bool isFound = false;					// K개 이상인 문자 존재 여부
        for(int j = 0; j < tmpLen; ++j){
            ++(mapAlphabat[W[j]].first);
            mapAlphabat[W[j]].second.push(j);
            
            if(mapAlphabat[W[j]].first >= K){	// 문자 W[j]가 K개 이상인 경우
                isFound = true;
                
                queue<int>& curQ = mapAlphabat[W[j]].second;
                int curLen = j - curQ.front() + 1;	            // K개의 문자W[j]를 포함한 문자열 길이
                curQ.pop();
                
                answer3[i] = min(answer3[i], curLen);			// 최소 길이 갱신
                answer4[i] = max(answer4[i], curLen);			// 최대 길이 갱신
            }
            
        }
        
        if(!isFound){							// K개 이상인 문자가 존재하지 않으면 -1
            answer3[i] = -1;
        }
    }
}

void printResult(){
    for(int i = 0; i < T; ++i){
        if(answer3[i] == -1){					// K개 이상인 문자가 존재하지 않으면 -1
            cout<<-1<<"\n";
        }
        else{									// K개 이상인 문자가 존재하면
            cout<<answer3[i]<<" "<<answer4[i]<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    initAndSolve();
    printResult();
    return 0;
}