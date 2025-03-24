#include<iostream>

using namespace std;

void HanoiTower(int n,char from_rod,char to_rod,char aux_rod){
	if(n==1){
		cout<<"chuyen vong thu 1 tu "<<from_rod<<" den "<<to_rod<<endl;
		return ;
	}HanoiTower(n-1,from_rod,aux_rod,to_rod);
	cout<<"chuyen vong thu "<<n<<" tu "<<from_rod<<" den "<<to_rod<<endl;;
	HanoiTower(n-1,aux_rod,to_rod,from_rod);
}


int main(){
	HanoiTower(3,'A','B','C');
	return 0;
}
