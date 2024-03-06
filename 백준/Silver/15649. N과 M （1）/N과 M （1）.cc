#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int iN, iM;
vector<string> vResults;

class Node{
private:
    int v;
    vector<Node*> children;
public:
    Node(int pV){
        this->v = pV;
    }
    
    void node_push_back(Node* pNode){
        this->children.push_back(pNode);
    }
    
    int getSubtreeSize(){
        return this->children.size();
    }
    
    int getValue(){
        return this->v;
    }
    
    vector<Node*> &getSubtree(){
        return this->children;
    }
};

void buildTree(string result, int vSubTreeH, Node* vParent, vector<int> pUsed, vector<int> pUnused){
    if(vSubTreeH == 0) {
        printf("%s\n", result.c_str());
        return;
    }
    
    vSubTreeH--;
    vector<int>::iterator itUnused;
    for(itUnused = pUnused.begin(); itUnused != pUnused.end(); itUnused++){
        vector<int> newUsed;
        newUsed.insert(newUsed.end(), pUsed.begin(), pUsed.end());
        vector<int> newUnused;
        newUnused.insert(newUnused.end(), pUnused.begin(), pUnused.end());
        
        newUsed.push_back(*itUnused);
        newUnused.erase(remove(newUnused.begin(), newUnused.end(), *itUnused), newUnused.end());
        
        Node* newNode = new Node(*itUnused);
        (*vParent).node_push_back(newNode);
        
        buildTree(result + to_string(*itUnused) + " ", vSubTreeH, newNode, newUsed, newUnused);
    }
}

/*void printTree(Node* pHead, string pStr){
    if((*pHead).getSubtreeSize() == 0){
        //vResults.push_back(pStr + " " + to_string(pHead.getValue()));
        //cout<<pStr<<endl;
        return;
    }
    
    vector<Node*> subtree = (*pHead).getSubtree();
    vector<Node*>::iterator itSubtree;
    for(itSubtree = subtree.begin(); itSubtree != subtree.end(); itSubtree++){
        printTree(*itSubtree, pStr + to_string((**itSubtree).getValue()) + " ");
    }
}*/

int main(){
    scanf("%d %d", &iN, &iM);
    // head node
    Node* head = new Node(-1);
    vector<int> initUsed;
    vector<int> initUnused;
    for(int i = 1; i <= iN; ++i){
        initUnused.push_back(i);
    }
    buildTree("", iM, head, initUsed, initUnused);
    // printTree(head, "");
}
