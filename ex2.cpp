#include<iostream>

using namespace std;
int LinearSearchWithSentinel(int* nums, int numsSize, int key) {
	if (nums[numsSize - 1] == key) return numsSize - 1;
	nums[numsSize - 1] = key;
	int i = 0;
	while (nums[i] != key) i++;
	if (i < numsSize - 1) return i;
	return -1;
}

int* CreateArray(int& n) {
	cout << "Nhap so luong phan tu ";
	cin >> n;
	cout << endl;
	int* ans = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Hay nhap phan tu thu " << i << endl;
		cin >> ans[i];
	}return ans;
}


int main() {
	int n;
	int* a = CreateArray(n);
	int key; cout << "Hay nhap so can tim " << endl; cin >> key;
	cout << "phan tu dung o vi tri " << LinearSearchWithSentinel(a, n, key);
	return 0;
}
