#include <iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<limits.h>

using namespace std;

struct NODE
{
    int key;
    NODE *p_left;
    NODE *p_right;
};

int min(int a,int b){
    return a<b ? a: b;
}

int max(int a,int b){
    return a>b ? a:b;
}

NODE* createNODE(int val){
    NODE* p = new NODE;
    if(p == nullptr){
        cout<<"tran bo nho "<<endl;
        return p;
    }
    p->key = val;
    p->p_left = nullptr;
    p->p_right = nullptr;
    return p;
}

NODE *Search(NODE *pRoot, int x)
{
    NODE *p = pRoot;
    while (p)
    {
        if (p->key == x)
            return p;
        if (p->key > x)
        {
            p = p->p_left;
        }
        else
        {
            p = p->p_right;
        }
    }
    return p;
}

void Insert(NODE *&pRoot, int x)
{
    NODE *p = createNODE(x);
    NODE *cur = pRoot;
    if (cur == nullptr)
    {
        pRoot = p;
        return;
    }
    NODE *dad;
    while (cur && cur->key != x)
    {
        dad = cur;

        if (cur->key < x)
        {
            cur = cur->p_right;
        }
        else
        {
            cur = cur->p_left;
        }
    }
    if(cur){
        delete p;
        return ;
    }
    if (dad->key < x)
    {
        dad->p_right = p;
        return;
    }
    dad->p_left = p;
}

void Remove(NODE *&pRoot, int x)
{
    NODE *p = pRoot;
    NODE *dad = nullptr;
    bool flag;
    /*
    flag = 0 ->chuyen qua left
    flag = 1 ->chuyen qua right
    */
    while (p && p->key != x)
    {
        dad = p;
        if (p->key > x)
        {
            p = p->p_left;
            flag = 0;
        }
        else
        {
            p = p->p_right;
            flag = 1;
        }
    }
    if (p == nullptr){
        return ;
    }
    if(dad == nullptr){
        NODE* q = pRoot;
        if(pRoot->p_left == nullptr || pRoot->p_right){
            if(pRoot->p_left){
                pRoot = q->p_right;
            }else{
                pRoot = q->p_left;
            }
            delete q;
            return;
        }

    }

    if(p->p_left == nullptr){
        if(flag){
            dad->p_right = p->p_right;
        }else{
            dad->p_left = p->p_right;
        }
        delete p;
        return ;
    }
    if(p->p_right == nullptr){
        if(flag){
            dad->p_right = p->p_left;
        }else{
            dad->p_left = p->p_left ;
        }
        delete p;
        return ;
    }
    NODE* grand = p;
    dad = p;
    p=p->p_left;
    flag = 0;
    while(p->p_right){
        dad = p;
        p=p->p_right;
        flag = 1;
    }
    grand->key = p->key;
    if(flag){
        dad->p_right = p->p_left;
    }else{
        dad->p_left = p->p_left;
    }
    delete p;
    return ;
}

NODE* createTree(int a[], int n){
    NODE* ans = nullptr;
    for(int i = 0;i < n; i++){
        Insert(ans,a[i]);
    }
    return ans;
}

NODE* createTreeSP(int a[],int n,int left,int right){
    int mid = (left + right)/2;
    if(mid >= n){
        return nullptr;
    }

    NODE* p = createNODE(a[mid]);
    if(left != mid) p->p_left = createTreeSP(a,n,left,mid);
    if(mid+1 < right) p->p_right = createTreeSP(a,n,mid+1,right);
    return p;
}

NODE* createTree2(int a[],int n){
    return createTreeSP(a,n,0,n);
}

int treeSize(NODE* root){
    if(root == nullptr) return 0;
    return 1+treeSize(root->p_left)+treeSize(root->p_right);
}

int height(NODE* pRoot){
    if(pRoot == nullptr){
        return 0;
    }
    return 1 + max(height(pRoot->p_left),height(pRoot->p_right));
}

int Height(NODE* pRoot){
    return height(pRoot) - 1;
}

bool isBST(NODE* pRoot){
    stack<NODE*> s;
    NODE* p = pRoot;
    int val = INT_MIN ;
    do{
        while(p != nullptr){
            s.push(p);
            p=p->p_left;
        }
        p=s.top();
        s.pop();
        if(p->key < val) return 0;
        val = p->key;
        p=p->p_right;
    }while(s.size() && p);
    return 1;
}

bool isFullBST(NODE* pRoot){
    if(pRoot == nullptr){
        return true;
    }

    if(pRoot->p_left == nullptr && pRoot->p_right == nullptr){
        return 1;
    }
    if(pRoot->p_left  == nullptr || pRoot->p_right == nullptr){
        return 0;
    }
    if(pRoot->key > pRoot->p_left->key && pRoot->key < pRoot->p_right->key){
        return isFullBST(pRoot->p_left) && isFullBST(pRoot->p_right);
    }
    return 0;
}

int countGreater(NODE* pRoot,int x){
    NODE* p = Search(pRoot,x);
    if(p == nullptr) return 0;
    return treeSize(p->p_right);
}

int countLess(NODE* pRoot, int x){
    NODE* p = Search(pRoot,x);
    if(p == nullptr) return 0;
    return treeSize(p->p_left);
}

void removeTree(NODE* &pRoot){
    if(pRoot == nullptr){
        return ;
    }
    removeTree(pRoot->p_left);
    removeTree(pRoot->p_right);
    delete pRoot;
    pRoot = nullptr;
}


