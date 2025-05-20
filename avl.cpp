#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<limits.h>

using namespace std;

struct NODE{
    int key;
    NODE* p_left;
    NODE* p_right;
    int height;
};

int max(int a,int b){
    return a>b ? a : b;
}

int min(int a,int b){
    return a<b ? a : b;
}

int height(NODE* p){
    if(p == nullptr){
        return -1;
    }
    return p->height;
}

void updateHeight(NODE* p){
    if(p == nullptr){
        return ;
    }
    p->height = 1 + max(height(p->p_left), height(p->p_right));
}

NODE* createNode(int data){
    NODE* p = new NODE;
    if(p == nullptr){
        cout<<"tran bo nho "<<endl;
        return p;
    }
    p->key = data;
    p->height = 0;
    p->p_left = nullptr;
    p->p_right = nullptr;
    return p;
}

NODE* rotateLeft(NODE* p){
    NODE* pivot = p->p_left;
    p->p_left = pivot->p_right;
    pivot->p_right = p;

    updateHeight(p);
    updateHeight(pivot);


    return pivot;
}

NODE* rotateRight(NODE* p){
    NODE* pivot = p->p_right;
    p->p_right = pivot->p_left;
    pivot->p_left = p;

    updateHeight(p);
    updateHeight(pivot);

    return pivot;
}

NODE* rotateRightLeft(NODE* p){
    NODE* pivot = p->p_right->p_left;
    NODE* pre = p->p_right;
    p->p_right = pivot->p_left;
    pre->p_left = pivot->p_right;
    pivot->p_left = p;
    pivot->p_right = pre;

    updateHeight(p);
    updateHeight(pre);
    updateHeight(pivot);

    return pivot;
}

NODE* rotateLeftRight(NODE* p){
    NODE* pivot = p->p_left->p_right;
    NODE* pre = p->p_left;
    p->p_left = pivot->p_right;
    pre->p_right = pivot->p_left;
    pivot->p_left = pre;
    pivot->p_right = p;

    updateHeight(p);
    updateHeight(pre);
    updateHeight(pivot);

    return pivot;
}

void Insert(NODE* &pRoot,int x){
    NODE* p = createNode(x);
    if(p == nullptr){
        return ;
    }
    if(pRoot == nullptr){
        pRoot = p;
        return ;
    }
    NODE* cur = pRoot;
    NODE* dad = nullptr;
    vector<NODE*> s;
    bool mode;
    do{
        s.push_back(cur);
        dad = cur;
        if(cur->key > x){
            cur = cur->p_left;
            mode = 0;
        }else{
            cur = cur->p_right;
            mode = 1;
        }
    }while(cur && cur->key!=x);


    if(cur != nullptr){
        // x da ton tai trong cay
        delete p ;
        return ;
    }
    if(mode){
        dad->p_right = p;
    }else{
        dad->p_left = p;
    }

    updateHeight(dad);

    int i = s.size();
    if(i == 1){
        return ;
    }
    int right;
    int left; 
    do{
        i--;
        cur = s[i];
        updateHeight(cur);
        right = height(cur->p_right);
        left = height(cur->p_left);
    }while(i && abs(left - right) < 2);
    if(abs(left - right) < 2){
        return ;
    }
    dad = cur;
    
    if(left > right){
        cur = cur->p_left;
        if(height(cur->p_left) > height(cur->p_right)){
            dad = rotateLeft(dad);
        }else{
            dad = rotateLeftRight(dad);
        }

    }else{
        cur = cur->p_right;
        if(height(cur->p_left) > height(cur->p_right)){
            dad = rotateRightLeft(dad);
        }else{
            dad = rotateRight(dad);
        }
    }
    if(i == 0){
        pRoot = dad;
        updateHeight(pRoot);
    }else{
        if(s[i-1]->key < dad->key){
            s[i-1]->p_right = dad;
        }else{
            s[i-1]->p_left = dad;
        }
        updateHeight(s[i-1]);
    }    
}

void Remove(NODE* pRoot,int x){
    NODE* cur = pRoot;
    vector<NODE*> s;
    bool mode;
    while(cur != nullptr && cur->key != x){
        s.push_back(cur);
        if(cur->key > x){
            cur = cur->p_left;
            mode = 0;
        }else{
            cur = cur->p_right;
            mode = 1;
        }
    }
    if(cur == nullptr){
        return ;
    }
    if(cur == pRoot){
        pRoot = nullptr;
        delete cur;
        return ;
    }

    int i = s.size();
    bool del = 1;
    if(cur->p_right == nullptr){
        if(mode){
            s[i-1]->p_right = cur->p_left;
        }else{
            s[i-1]->p_left = cur->p_left;
        }
        del = 0;
        delete cur;
    }
    if(del && cur->p_left == nullptr){
        if(mode){
            s[i-1]->p_right = cur->p_right;
        }else{
            s[i-1]->p_left = cur->p_right;
        }
        del = 0;
        delete cur;
    }
    if(!del){
        updateHeight(s[i-1]);
    }
    if(del){
        s.push_back(cur);
        NODE* pivot = cur->p_left;
        while(pivot->p_right != nullptr){
            s.push_back(pivot);
            pivot = pivot->p_right;
        }
        cur->key = pivot->key;

        i = s.size();
        s[i-1]->p_right = pivot->p_left;
        delete pivot;
        updateHeight(s[i-1]);      
    }
    int preH  = 0;
    int afterH = 0;

    int left, right;

    do{
        i--;
        preH = height(s[i]);
        left = height(s[i]->p_left);
        right = height(s[i]->p_right);
        if(abs(left - right) > 1){
            if(left > right){
                cur = s[i]->p_left;
                if(height(cur->p_left) > height(cur->p_right)){
                    s[i] = rotateLeft(s[i]);
                }else{
                    s[i] = rotateLeftRight(s[i]);
                }
            }else{
                cur = s[i]->p_right;
                if(height(cur->p_right) > height(cur->p_left)){
                    s[i] = rotateRight(s[i]);
                }else{
                    s[i] = rotateRightLeft(s[i]);
                }
            }
            if(i == 0){
                pRoot = s[i];
            }else{
                if(s[i-1]->key > s[i]->key){
                    s[i-1]->p_right = s[i];
                }else{
                    s[i-1]->p_left = s[i];
                }
            }
        }
        updateHeight(s[i]);
        afterH = s[i]->height;
    }while(i && preH!=afterH);
}

bool isAVL(NODE* pRoot){
    if(pRoot == nullptr){
        return 1;
    }
    int right = -1, left = -1;
    if(pRoot->p_left){
        left = pRoot->p_left->height;
        if(pRoot->key <= pRoot->p_left->key){
            return 0;
        }
        
    }
    if(pRoot->p_right){
        right = pRoot->p_right->height;
        if(pRoot->key >= pRoot->p_right->key){
            return 0;
        }
    }
    if(abs(left - right) > 1) return 0;
    return isAVL(pRoot->p_left) && isAVL(pRoot->p_right);
}
