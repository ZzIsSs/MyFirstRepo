#include<iostream>

using namespace std;

bool solve(int* nums,int numsSize,int key){
	int left=0,right=numsSize-1;
	int sum;
	while(left<right){
		sum=nums[left]+nums[right];
		if(sum==key) return true;
		if(sum<key) left++;
		else right--;
	}return false;
}

int main(){
	int a[]={1,3,5,7,10,14,16,18,21,24,25,29,30,35};
	int n=sizeof(a)/sizeof(a[0]);
	int key; cin>>key;
	if(solve(a,n,key)) cout<<"Found ";
	else cout<<"Not Found ";
	return 0;
}
