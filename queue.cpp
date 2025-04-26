#include<iostream>
#include<fstream>
#include<cstring>


using namespace std;

struct Node{
	Node* next ;
	int val;
};

struct queue{
	Node* head;
	Node* tail;
};

queue* initializeQueue(){
	queue* ans = new queue;
	if(ans == nullptr){
		cout << " out of memory " << endl;
		return ans;
	}
	ans->head = nullptr;
	ans->tail = nullptr;
	return ans;
}

void enqueue(queue *&q, int key){
	Node* p = new Node;
	if(p == nullptr ){
		cout << " out of memory " << endl;
		return ;
	}
	p->val = key;
	p->next = nullptr;
	if(q == nullptr){
		q = initializeQueue();
		if(q == nullptr){
			delete p;
			return ;
		} 
	}
	if(q->head == nullptr){
		p->next = q->head;
		q->head = p;
		q->tail = p;
		return ;
	}
	q->tail->next = p;
	q->tail = p;
}

int dequeue(queue* q){
	if(q == nullptr || q->head == nullptr) return -1;
	Node* p = q->head;
	q->head = p->next;
	if(q->head == nullptr){
		q->tail = nullptr;
	}
	int val = p->val;
	delete p;
	return val;
}

int size(queue* q){
	if(q == nullptr) return 0;
	Node* p= q->head ;
	int cnt =0;
	while(p!=nullptr){
		cnt++;
		p = p->next;
	}return cnt;
}

bool isEmpty(queue* q){
	if(q == nullptr) return 1;
	return q->head == nullptr;
}

void print(ostream& os, queue* q){
	if(q == nullptr || q->head == nullptr){
		os << "EMPTY" <<endl ;
		return;
	}
	Node* p= q->head;
	while(p != nullptr){
		os << p->val << " ";
		p = p->next;
	}
	os << endl;
}

void clearQueue(queue* &q){
	if(q == nullptr) return ;
	while(q->head != nullptr){
		dequeue(q);
	}
	delete q;
}

int main(){
	int val;
	queue* q = initializeQueue();
	ifstream doc("input.txt");
	ofstream ghi("output.txt");
	char* temp;
	char str[100];
	if(!doc.is_open() || !ghi.is_open()) return 2;
	while(!doc.eof()){
		doc.getline(str,99);
		strtok(str," ");
		strcpy(str,strlwr(str));
		if(strcmp(str,"size") == 0){
			ghi << size(q) <<endl;
		}else if(strcmp(str,"dequeue") == 0){
			dequeue(q);
			print(ghi ,q);
			
		}else if(strcmp(str, "isempty") == 0){
			if(isEmpty(q)){
				ghi << "YES" <<endl;
			}else{
				ghi << "NO " <<endl;
			}
		}else if(strcmp(str,"init") == 0){
			q = initializeQueue();
			ghi << "EMPTY" <<endl;
		}else{
			val = atoi(strtok(NULL," "));
			enqueue(q,val);
			print(ghi,q);
		}
	}doc.close();
	ghi.close();
	clearQueue(q);
	return 100;
	
}