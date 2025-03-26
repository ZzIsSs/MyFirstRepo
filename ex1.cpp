#include<iostream>

using namespace std;

int linearSearch(int* nums, int numsSize, int key) {
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == key) return i;
	}return -1;
}

//int* CreateArray(int& n) {
//	cout << "Nhap so luong phan tu ";
//	cin >> n;
//	cout << endl;
//	int* ans = new int[n];
//	for (int i = 0; i < n; i++) {
//		cout << "Hay nhap phan tu thu " << i << endl;
//		cin >> ans[i];
//	}return ans;
//}


//int main() {
//	int n;
//	int* a = CreateArray(n);
//	int key; cout << "Hay nhap so can tim " << endl; cin >> key;
//	cout << "phan tu co gia tri 7 dung o vi tri " << linearSearch(a, n, 7);
//	return 0;
//}