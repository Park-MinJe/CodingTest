#include <iostream>
#include <string>
#include <vector>

using namespace std;

int aLen, ans = 0;
vector<int> leftMin,
            rightMin;

void init(vector<int>& a){
    aLen = a.size();
    leftMin.resize(aLen);
    rightMin.resize(aLen);
    
    int tmpMin = a[0];
    for(int i = 0; i < aLen; ++i){
        tmpMin = min(tmpMin, a[i]);
        leftMin[i] = tmpMin;
    }
    
    tmpMin = a[aLen-1];
    for(int i = aLen-1; i >= 0; --i){
        tmpMin = min(tmpMin, a[i]);
        rightMin[i] = tmpMin;
    }
}

int count(vector<int>& a){
    for(int i = 0; i < aLen; ++i){
        if(!(a[i] > leftMin[i] && a[i] > rightMin[i])){
            ++ans;
        }
    }
}

int solution(vector<int> a) {
    
    aLen = a.size();
    leftMin.resize(aLen);
    rightMin.resize(aLen);
    
    int tmpMin = a[0];
    for(int i = 0; i < aLen; ++i){
        tmpMin = min(tmpMin, a[i]);
        leftMin[i] = tmpMin;
    }
    
    tmpMin = a[aLen-1];
    for(int i = aLen-1; i >= 0; --i){
        tmpMin = min(tmpMin, a[i]);
        rightMin[i] = tmpMin;
    }
    
    for(int i = 0; i < aLen; ++i){
        if(!(a[i] > leftMin[i] && a[i] > rightMin[i])){
            ++ans;
        }
    }
    
    return ans;
}