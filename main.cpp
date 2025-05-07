#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

const int m = pow(10, 9) + 9;
const int p = 31;
const int last = 20;

struct Company {
	string name;
	string profit_tax;
	string address;
};

struct HashTable {
	Company cty;
	HashTable* next;
};

vector<Company> readCompanyList(string file_name) {
	fstream doc(file_name);
	string line;
	Company temp;
	vector<Company> ans;
	while (getline(doc, line)) {
		stringstream ss(line);
		getline(ss, temp.name, '|');
		getline(ss, temp.profit_tax, '|');
		getline(ss, temp.address, '|');
		ans.push_back(temp);
	}
	doc.close();
	return ans;
}

int min(int a, int b) {
	return a > b ? b : a;
}

long long key(string company_name) {
	long long ans = 0;
	int n = company_name.size();
	int times = min(n, last);
	for (int i = 0; i < times; i++) {
		ans += ( company_name[n - i - 1] * (int)pow(p, i) % m);
		ans %= m;
	}
	return ans;
}

bool add(HashTable** hash, Company cty) {
	int Key = key(cty.name)%m;
	HashTable* p = new HashTable();
	if (p == nullptr) {
		return 0;
	}
	p->cty = cty;
	p->next = hash[Key];
	hash[Key] = p;
	return 1;
}

HashTable* createHashTable(vector<Company> list_company) {
	HashTable** hash = new HashTable * [m];
	for (int i = 0; i < m; i++) {
		hash[i] = nullptr;
	}

}

void Print(ostream& os,Company company) {
	os << company.name << endl << company.profit_tax << endl << company.address << endl << endl;
}

void Print(vector<Company> list) {
	for (int i = 0; i < list.size(); i++) {
		Print(cout,list[i]);
	}
}

int main() {
	string file = "Text.txt";
	vector<Company> ans = readCompanyList(file);
	Print(ans);
}