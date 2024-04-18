#include <string>
#include <vector>

using namespace std;

int trgt, numSize,
    cases = 0;

void searchCases(vector<int>& numbers, int curIdx, int curVal){
    if(curIdx == numSize){
        if(curVal == trgt)
            ++cases;
        return;
    }
    
    searchCases(numbers, curIdx+1, curVal+numbers[curIdx]);
    searchCases(numbers, curIdx+1, curVal-numbers[curIdx]);
}

int solution(vector<int> numbers, int target) {
    trgt = target;
    numSize = numbers.size();
    searchCases(numbers, 0, 0);
    return cases;
}