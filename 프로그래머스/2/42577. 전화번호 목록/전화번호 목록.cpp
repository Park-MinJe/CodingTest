#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    int pbSize = phone_book.size();
    for(int i = 0; i < pbSize-1; ++i){
        int tmpNumeSize = phone_book[i].size();
        if(phone_book[i].compare(phone_book[i+1].substr(0, tmpNumeSize)) == 0)
                return false;
    }
    
    return true;
}