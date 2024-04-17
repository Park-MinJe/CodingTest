#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> rowSizes, colSizes;

int solution(vector<vector<int>> sizes) {
    // 긴 길이를 index 0, 짧은 길이를 index 1로 이동
    for(int i = 0; i < sizes.size(); ++i){
        if(sizes[i][0] < sizes[i][1]){
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        rowSizes.push(sizes[i][0]);
        colSizes.push(sizes[i][1]);
    }
    
    return rowSizes.top()*colSizes.top();
}