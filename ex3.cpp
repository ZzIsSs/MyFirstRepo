#include<iostream>

using namespace std;

int searchProMax(int* nums, int numsSize) {
	int left=0,right=numsSize-1,mid=left+(right-left)/2;
	while(left<right){
		if(nums[mid]>nums[right]) left=mid+1;
		else right=mid;
		mid=left+(right-left)/2;
	}return nums[right];
}

int* CreateArray(int& n) {
	cout << "Nhap so luong phan tu ";
	cin >> n;
	cout << endl;
	int* ans = new int[n];
	for (int i = 0; i < n; i++) {
		cout<<"Hay nhap gia tri thu "<<i<<" ";
		cin>>ans[i];
	}
	return ans;
}


int main() {
	int n;
	int* a = CreateArray(n);
	int min = searchProMax(a, n);
	cout<<"min la "<<min<<endl;
	return 0;
}
