#include<iostream>
#include<fstream>
#include<string>



using namespace std;



struct Node {
	int val;
	Node* next;
};

struct Stack {
	Node* head;
	int size;
};

Stack* InitStack() {
	Stack* ans = new Stack;
	if (ans != nullptr)
	{
		ans->size = 0;
		ans->head = nullptr;
	}
	else
	{
		cout << "Out of memory " << endl;
	}
	return ans;
}

void push(Stack* s, int val) {
	Node* p = new Node;
	if (p == nullptr) {
		cout << "out of memory" << endl;
		return;
	}
	p->next = s->head;
	p->val = val;
	s->head = p;
	s->size++;
}

int top(Stack* s) {
	if (s == nullptr || s->size == 0) {
		return -1;
	}
	return s->head->val;
}

void pop(Stack* s) {
	if (s == nullptr || s->size == 0) {
		return;
	}
	Node* p = s->head;
	s->head = p->next;
	delete p;
	s->size--;
}

int size(Stack* s) {
	if (s == nullptr) return 0;
	return s->size;
}

bool isEmpty(Stack* s) {
	if (s == nullptr) return true;
	return s->size == 0;
}

void print(Stack* s) {
	if (s == nullptr) return;
	Node* p = s->head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}cout << endl;
}

void clear(Stack* s) {
	if (s == nullptr) return;
	while (s->size) {
		pop(s);
	}s = nullptr;
}

int main() {
	//ifstream doc("intput.txt");
	//ofstream ghi("output.txt");
	//if (!doc.is_open() || !ghi.is_open()) return -1;
	Stack* s = InitStack();
	push(s, 10);
	push(s, 120);
	push(s, 103);
	push(s, 110);
	push(s, 103);
	push(s, 140);
	push(s, 150);
	push(s, 107);
	print(s);
	clear(s);
	if(isEmpty(s)) cout<<"stack is empty bro !!"<<endl;
	return 0;
}