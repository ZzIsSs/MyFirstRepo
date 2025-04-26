#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Node{
	int val;
	Node* next;
};

struct stack{
	Node* head;
};

stack* initializeStack(){
	stack* s = new stack;
	if (s == nullptr) return s;
	s->head = nullptr;
	return s;
}

void push(stack* &s, int key){
	if(s == nullptr ){
		s = initializeStack();
	}
	if(s == nullptr) return ;
	Node* p = new Node;
	if(p == nullptr){
		cout<<"Out of memory "<<endl;
		return ;
	}
	p->val = key;
	p->next = s->head ;
	s->head = p;
}

int pop(stack* &s){
	if(s == nullptr || s->head == nullptr){
		return -1;
	}
	int val = s->head->val;
	Node* p= s->head;
	s->head = s->head->next;
	delete p;
	return val;
}

int top(stack* s){
	if(s == nullptr || s->head == 0){
		return -1;
	}
	return s->head->val;
}

void DeInitStack(stack* &s){
	while(s->head){
		pop(s);
	}
}

int size(stack* s){
	if(s == nullptr) return 0;
	int cnt = 0;
	Node* p = s->head ;
	while(p != nullptr){
		p = p->next;
		cnt ++ ;
	}return cnt;
}

void print(ostream& os,stack* s){
	if(s == nullptr) return ;
	Node* p= s->head;
	while(p != nullptr){
		os << p->val << " ";
		p = p->next;
	}
	os << endl;
}

bool isEmpty(stack* s){
	if(s == nullptr )return true;
	return s->head == nullptr;	
}

void printReverse(ostream& os,Node* p){
	if(p == nullptr) return ;
	printReverse(os,p->next);
	os << p->val <<" ";
	
}

int main(){
	int val;
	stack* s;
	s=initializeStack();
	char* temp;
	char str[100];
	ifstream doc("input.txt");
	ofstream ghi("output.txt");
	if(!doc || !ghi) return -1;
	while(!doc.eof()){
		doc.getline(str,99);
		temp = strtok(str, " ");
		strcpy(str,strlwr(str));
		if(strcmp(temp,"pop") == 0){
			if(s == nullptr || s->head == nullptr){
				ghi << "EMPTY" <<endl;
			}else{
				pop(s);
				if(s->head == nullptr){
					ghi << "EMPTY" << endl;
				}else{
					printReverse(ghi,s->head);
					ghi << endl;
				}
			}	
		}else if(strcmp(temp,"isempty") == 0){
			if(isEmpty(s)){
				ghi << "YES";
			}else{
				ghi << "NO";
			}ghi << endl;
		}else if(strcmp(temp, "init") == 0){
			s = initializeStack();
			ghi << "EMPTY" <<endl;
		}else if(strcmp(temp, "size") == 0){
			ghi << size(s) <<endl;
		}else{
			val = atoi(strtok(NULL," "));
			push(s,val);
			printReverse(ghi,s->head);
			ghi << endl;
		}
		
	}
	doc.close();
	ghi.close();
	return 0;
	
}
