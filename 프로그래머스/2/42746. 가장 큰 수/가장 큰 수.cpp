#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string& s1, string& s2){
    return s1+s2 > s2+s1;
}

string solution(vector<int> numbers) {
    vector<string> strNums;
    for(int i = 0; i < numbers.size(); ++i){
        strNums.push_back(to_string(numbers[i]));
    }
    sort(strNums.begin(), strNums.end(), comp);
    
    if(strNums.at(0) == "0")
        return "0";
    
    string rt = "";
    vector<string>::iterator it;
    for(it = strNums.begin(); it != strNums.end(); ++it){
        rt += *it;
    }
    return rt;
}