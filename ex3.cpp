#include<iostream>

using namespace std;

int searchProMax(int* nums, int numsSize, int key) {
	int left = 0, right = numsSize - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == key) return mid;
		if (nums[mid] <= nums[right]) {
			if (nums[mid] < key && nums[right] >= key) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		else {
			if (nums[mid] > key && nums[left] <= key) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}if (left == mid) - 1;
	}return -1;
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
	int key; cout << "Hay nhap so can tim " << endl; cin >> key;
	int index = searchProMax(a, n, key);
	if (index >= 0) {
		cout << "so can tim o vi tri " << index << endl;
	}
	else {
		cout << "khong tim thay so " << endl;
	}return 0;
}