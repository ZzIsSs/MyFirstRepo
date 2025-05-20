#include <iostream>
#include<fstream>
#include<vector>
#include<stack>

using namespace std;

struct NODE
{
    int key;
    NODE *p_left;
    NODE *p_right;
};

NODE* createNode(int data){
    NODE* p = new NODE;
    if(p == nullptr){
        cout<<"tran bo nho \n";
        return p;
    }
    p->key = data;
    p->p_left = nullptr;
    p->p_right = nullptr;
    return p;
}


vector<int> LNR(NODE* pRoot){
    NODE* p = pRoot;

    stack<NODE*> s;
    vector<int> ans;
        if(p == nullptr){
        return ans;
    }
    do{
        while(p != nullptr){
            s.push(p);
            p=p->p_left;
        }
        p = s.top();
        s.pop();
        ans.push_back(p->key);
        p=p->p_right;
    }while(p || s.size());
    return ans;
}

vector<int> NLR(NODE* pRoot){
    NODE* p = pRoot;
    stack<NODE*> s;
    vector<int> ans;
    if(p == nullptr){
        return ans;
    }
    do{
        while(p != nullptr){
            s.push(p);
            ans.push_back(p->key);
            p=p->p_left;
        }
        p=s.top();
        p=p->p_right;
        s.pop();
    }while(p!= nullptr || s.size());
    return ans;
}

void postOrdered(NODE* pRoot, vector<int> &a){
    if(pRoot == nullptr){
        return ;
    }
    postOrdered(pRoot->p_left, a);
    postOrdered(pRoot->p_right, a);
    a.push_back(pRoot->key);
}

vector<int> LRN(NODE* pRoot){
    vector<int> ans;
    postOrdered(pRoot, ans);
    return ans;
}

void addLevel(NODE* pRoot,vector<vector<int>> &a, int height){
    if(pRoot == nullptr){
        return ;
    }
    if(height == a.size()){
        a.push_back({pRoot->key});
    }else{
        a[height].push_back(pRoot->key);
    }
    addLevel(pRoot->p_left,a,height+1);
    addLevel(pRoot->p_right,a,height+1);
}

vector<vector<int>> LevelOreder(NODE* pRoot){
    vector<vector<int>> ans;
    addLevel(pRoot,ans,0);
    return ans;
}

int countNode(NODE* pRoot){
    if(pRoot == nullptr){
        return 0;
    }
    return 1 + countNode(pRoot->p_left) + countNode(pRoot->p_right);
}

int sumNode(NODE* pRoot){
    if(pRoot == nullptr){
        return 0;
    }
    return pRoot->key + sumNode(pRoot->p_left) + sumNode(pRoot->p_right);
}

int heightNode(NODE* pRoot,int value){
    if(pRoot == nullptr){
        return -1;
    }
    if(pRoot->key == value){
        return 0;
    }
    int h = heightNode(pRoot->p_left,value);
    if(h == -1){
        h = heightNode(pRoot->p_right,value);
    }
    if(h == -1) return -1;
    return 1 + h;
}

int Level(NODE* pRoot,NODE* p){
    if(p == nullptr){
        return -1;
    }
    return heightNode(pRoot,p->key);
}

int countLeaf(NODE* pRoot){
    if(pRoot == nullptr){
        return 0;
    }
    if(pRoot->p_left == nullptr && pRoot->p_right == nullptr){
        return 1;
    }
    return countLeaf(pRoot->p_left) + countLeaf(pRoot->p_right);
}
