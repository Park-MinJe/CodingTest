#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int len = citations.size();
    sort(citations.begin(), citations.end());
    int prev = 0,
        cur = citations[0],
        tmpH = len;
    for(int i = 0; i < len; ++i){
        if(i != 0){
            prev = citations[i-1],
            cur = citations[i],
            tmpH = len-i;
        }
        
        if(prev<=tmpH && tmpH<=cur){
            return tmpH;
        }
    }
    return 0;
}