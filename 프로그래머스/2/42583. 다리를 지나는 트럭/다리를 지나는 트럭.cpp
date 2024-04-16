#include <string>
#include <vector>
#include <queue>
#include <tuple>

// debug
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int cnt = 0,
        onBridgeWeight = 0;
    
    queue<int> waiting;
    queue<pair<int, int>> onBridge;   // <무게, 다리에 올라온 시점>
    for(int i = 0; i < truck_weights.size(); ++i){
        waiting.push(truck_weights[i]);
    }
    
    while(!waiting.empty() || !onBridge.empty()){
        ++cnt;
        
        // debug
        // cout<<"\n경과 시간 "<<cnt;
        
        // 다리를 지난 트럭 처리
        if(!onBridge.empty()                    // 다리에 트럭이 남아 있고
           && onBridge.front().second == (cnt - bridge_length)
                                                // 다리를 다 건넌 경우
        ){
            // debug
            // cout<<"::다리를 지난 트럭::("<<onBridge.front().first<<", "<<onBridge.front().second<<")";
            
            onBridgeWeight -= onBridge.front().first;
            onBridge.pop();
        }
        
        // 다리에 진입하는 트럭 처리
        if(!waiting.empty()                     // 대기 중인 트럭이 있고
          && (onBridge.size() < bridge_length   // 다리 위의 트럭 수가 다리 길이 보다 작고
            && onBridgeWeight+waiting.front() <= weight)
                // 그 무게와 진입하고자 하는 트럭의 무게의 합이 허용 가능하면 다리에 진입할 수 있다
        ){
            onBridge.push(make_pair(
                waiting.front(), cnt
            ));
            onBridgeWeight += waiting.front();
            
            waiting.pop();
        }
    }
    
    return cnt;
}