#include<iostream>

using namespace std;

int Fib(int n){
	if(n<2) return n;
	return Fib(n-1)+Fib(n-2);
}

int main(){
	int n; cin>> n;
	cout<<"So Fib thu "<<n<<" = "<<Fib(n);
	return 0;
}
