#include<iostream>

using namespace std;

int searchProMax(int* nums, int numsSize) {
	int left=0,right=numsSize-1,mid=left+(right-left)/2;
	while(mid!=left&&mid!=right){
		if(nums[mid]>nums[right]) left=mid+1;
		else right=mid;
		mid=left+(right-left)/2;
	}return nums[right]>nums[mid]? nums[mid]: nums[right];
}

void Rotate(int* ans,int n) {
	int times; cout << "ban muon xoay bao nhieu "; cin >> times;
	times %= n;
	int* temp = new int[times];
	for (int i = 0; i < times; i++) {
		temp[i] = ans[i];
	}for (int i = 0; i < n - times; i++) {
		ans[i] = ans[i + times];
	}int count = 0;
	for (int i = n - times; i < n; i++) {
		ans[i] = temp[count++];
	}delete[] temp;
}

int* CreateArray(int& n) {
	cout << "Nhap so luong phan tu ";
	cin >> n;
	cout << endl;
	int* ans = new int[n];
	for (int i = 0; i < n; i++) {
		ans[i] = i;
	}Rotate(ans, n);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}cout << endl;
	return ans;
}


int main() {
	int n;
	int* a = CreateArray(n);
	int min = searchProMax(a, n);
	cout<<"min la "<<min<<endl;
	return 0;
}
