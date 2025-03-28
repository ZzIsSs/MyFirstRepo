#include<iostream>

using namespace std;

bool check(int* nums,int n,int capacity,int limit){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=nums[i];
		if(sum>capacity){
			sum=nums[i];
			limit--;
		}
	}
	return limit>0;
}

int solve(int* weights,int n,int limit){
	long long left=-1,right,mid;
	for(int i=0;i<n;i++){
		if(left<weights[i]) left=weights[i];
		right+=weights[i];
	}bool tempCheck1,tempCheck2;
	while(left<=right){
		mid=left+(right-left)/2;
		tempCheck1=check(weights,n,mid,limit);
		tempCheck2=check(weights,n,mid+1,limit);
		if(!tempCheck1&&tempCheck2) return mid+1;
		if(tempCheck1){
			right=mid;
		}else left=mid;
	}return left;
}


int main(){
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<solve(a,n,5);
}
