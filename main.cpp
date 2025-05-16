#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

const int m = 10037;
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
	ifstream doc(file_name);
	vector<Company> ans;
	if(!doc.is_open()){
		cout<<"Khong the mo file "<<file_name<<endl;
		return ans;
	}
	string line;
	Company temp;
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


// do m <INT_MAX ta thay kieu tra ve la int thay vi long long
int key(string company_name) {
	int ans = 0;
	int n = company_name.size();
	int times = min(n, last);
	for (int i = 0; i < times; i++) {
		ans += (company_name[n - i - 1] * abs((int)pow(p, i) % m));
		ans %= m;
	}
	return ans;
}

bool add(HashTable** hash, Company cty) {
	int Key = key(cty.name);
	
	HashTable* p = new HashTable();
	if (p == nullptr) {
		return 0;
	}
	p->cty = cty;
	p->next = hash[Key];
	hash[Key] = p;
	return 1;
}

HashTable** createHashTable(vector<Company> list) {
	HashTable** hash = new HashTable * [m];
	for (int i = 0; i < m; i++) {
		hash[i] = nullptr;
	}
	int n = list.size();
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = add(hash, list[i]);
		i++;
		
	}
	return hash;
}

void print(ostream& os, Company company) {

	os << company.name << " | " << company.profit_tax << " | " << company.address << endl;
}

void print(ostream &os, vector<Company> list) {
	for (int i = 0; i < list.size(); i++) {
		print(os, list[i]);
	}
}

HashTable* find(HashTable** hash, string name) {
	int Key = key(name);
	HashTable* p = hash[Key];
	while (p && p->cty.name != name) {
		p = p->next;
	}
	return p;
}

void solve(string output, string file,HashTable** hash) {
	ifstream doc(file);
	ofstream os(output);
	if(!os.is_open()){
		cout<<"can not read file "<<output<<endl;
		return ;
	}
	if (!doc.is_open()) {
		cout << "Can not read file " << file<<endl;
		return;
	}
	string name;
	HashTable* p;

	while (getline(doc, name)) {
		p = find(hash, name);
		if (p != nullptr) {
			print(os, p->cty);
		}
		else {
			os << "NULL" << endl;
		}
	}
	doc.close();
	os.close();
}
/*
g++ main.cpp -o main
main MST.txt input.txt output.txt

*/


int main(int argc, char* argv[]) {
	if(argc != 4){
		cout<<"Loi tham so truyen vao ham main "<<endl;
		return -1;
	}
	string data = argv[1];
	string input =  argv[2] ; 
	string output = argv[3] ;
	vector<Company> list = readCompanyList(data);
	HashTable** hash = createHashTable(list);

	solve(output, input, hash);
	return 1;
}