#include<iostream>
using namespace std;

int MinLen(int* nums, int n, int key) {
	int left=0,right=0;
	int sum=0;
	int ans=INT_MAX;
	bool flag=true;
	while(right<n){
		if(flag) sum+=nums[right];
		else sum-=nums[left-1];
		if(sum<key){
			right++;
			flag=true;
		}else{
			flag=false;
			if(sum==key&&ans>right-left) ans=right-left;
			left++;
		}
	}if(sum==key){
		if(ans>right-left) ans=right-left;
	}
	if(ans==INT_MAX) return -1;
	return ans+1;
}

int main(){
	int a[]={7,10,3,4,5,9,11,23,2};
	int n=sizeof(a)/sizeof(a[0]);
	int key;cout<<"nhap tong muon tim ";cin>>key;
	
	cout<<"chuoi so co do dai be nhat la "<<MinLen(a,n,key);
	return 0;
}
