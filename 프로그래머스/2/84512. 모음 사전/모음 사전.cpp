#include <string>
#include <vector>

using namespace std;

int idx;
string trgt;
vector<char> lstWord = {
    'A', 'E', 'I', 'O', 'U'
};

bool backtracking(string curCase){
    if(curCase.compare(trgt) == 0){
        return true;
    }
    else{
        if(curCase.length() == 5)
            return false;
    }
    
    for(int i = 0; i < 5; ++i){
        ++idx;
        bool result = backtracking(curCase+lstWord[i]);
        if(result)
            return true;
    }
    return false;
}

int solution(string word) {
    trgt = word;
    backtracking("");
    return idx;
}