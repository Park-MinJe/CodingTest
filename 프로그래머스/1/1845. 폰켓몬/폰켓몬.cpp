#include <vector>
#include <set>
using namespace std;

set<int> types;

int solution(vector<int> nums)
{
    int N_2 = nums.size()/2;
    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); ++it){
        types.insert(*it);
    }
    int typeCnt = types.size();
    
    if(N_2 > typeCnt){
        return typeCnt;
    }
    else{
        return N_2;
    }
}