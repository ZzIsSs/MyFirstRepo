#include<iostream>
#include<time.h>
#include<stdlib.h> 
 
 
using namespace std;

void Merge(int* a,int left,int mid,int right){
	int* temp=new int[right-left+1];
	int l=left,r=mid+1;
	int count=0;
	while(l<=mid&&r<=right){
		if(a[l]<a[r]){
			temp[count++]=a[l++];
		}else{
			temp[count++]=a[r++];
		}
	}while(l<=mid){
		temp[count++]=a[l++];
	}while(r<=right){
		temp[count++]=a[r++];
	}for(int i=0;i<count;i++){
		a[i+left]=temp[i];
	}delete[] temp;
}

void MergeSort(int* a,int left,int right){
	if(left!=right){
		int mid=left+(right-left)/2;
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merge(a,left,mid,right);
	}
	
}

int* CreateArray(int n){
	int* ans=new int[n];
	for(int i=0;i<n;i++){
		ans[i]=rand()%20-10;
	}return ans;
}


void PrintArray(int* a,int n){
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}

void PrintMatrix(int** a,int n,int m){
	for(int i=0;i<n;i++){
		PrintArray(a[i],m);
	}
}

int** solve(int* nums,int numsSize,int &returnSize){
	MergeSort(nums,0,numsSize-1);
	int index=0,left,right;
	int temp[10000][3];
	int count=0;
	int sum;
	int cur;
	while(index<numsSize-2){
		left=index+1;
		right=numsSize-1;
		while(left<right){
			sum=nums[left]+nums[right];
			if(sum==-nums[index]){
				temp[count][0]=nums[index];
				temp[count][1]=nums[left];
				temp[count][2]=nums[right];
				while(left<right&&nums[left]==nums[left+1]) left++;
				count++;
			}if(sum>-nums[index]){
				right--;
			}else{
				left++;
			}
		}cur=index;
		while(index<numsSize-2&&nums[cur]==nums[index]){
			index++;
		}
	}int**ans= new int*[count];
	for(int i=0;i<count;i++){
		ans[i]=new int[3];
		for(int j=0;j<3;j++){
			ans[i][j]=temp[i][j];
		}
	}returnSize=count;
	return ans;	
}


int main(){
	srand((unsigned)time(0));
	int n=rand()%11+15;
	int* a=CreateArray(n);
	PrintArray(a,n);
	int** res=solve(a,n,n);
	if(res) PrintMatrix(res,n,3);
	
	
}
