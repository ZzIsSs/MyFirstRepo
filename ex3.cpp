#include<iostream>
#include<string>
using namespace std;

void BinaryString( int n, string s){
	if(s.size()==n){
		cout<<s<<endl;
		return ;
	}for(int i=0;i<2;i++){
		s+=i+'0';
		BinaryString(n,s);
		s.erase(s.end()-1);
	}
}

int main(){
	string ans;
	BinaryString(3,ans);
}
