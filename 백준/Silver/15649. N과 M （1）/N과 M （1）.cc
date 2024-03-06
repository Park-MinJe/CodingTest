#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int iN, iM;
bool* isUsed;

void buildTree(string result, int vSubTreeH){
    if(vSubTreeH == 0) {
        printf("%s\n", result.c_str());
        return;
    }
    
    vSubTreeH--;
    for(int i = 1; i <= iN; ++i){
        if(!isUsed[i]){
            isUsed[i] = true;
            buildTree(result + to_string(i) + " ", vSubTreeH);
            isUsed[i] = false;
        }
    }
}

int main(){
    scanf("%d %d", &iN, &iM);
    isUsed = new bool[iN+1];
    for(int i = 1; i <= iN; ++i){
        isUsed[i] = false;
    }
    buildTree("", iM);
}