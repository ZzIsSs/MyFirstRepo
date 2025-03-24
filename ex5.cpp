#include<iostream>

using namespace std;

bool IsSorted(int* nums,int n){
	if(n<2) return true;
	if(nums[n-1]<nums[n-2]) return false;
	return IsSorted(nums,n-1);
}


int main(){
	int a[]={0,1,2,3,4,5};
	cout<<IsSorted(a,6);
	return 0;
}
