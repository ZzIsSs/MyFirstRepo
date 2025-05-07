#include<iostream>
#include<string.h>
#include<fstream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

void reverse(string& s) {
	int n = s.size();
	char tmp;
	for (int i = 0;i < n / 2;i++) {
		tmp = s[i];
		s[i] = s[n - 1 - i];
		s[n - 1 - i] = tmp;
	}
}

//Ham xoa cac chu so 0 bi du o dau va cac dau tru bi lap
void ChuanHoa(string& a) {
	if (a.size()<2) return;
	bool sign = 0;
	reverse(a);
	while (a.size() > 1) {
		if (a[a.size() - 1] >= '1' && a[a.size() - 1] <= '9') {
			if (sign) {
				a += '-';
			}
			reverse(a);
			return;
		}
		if (a[a.size() - 1] == '-') {
			sign = !sign;
		}
		a.pop_back();
	}
	if (sign && a != "0") {
		a += '-';
	}reverse(a);
}


// Ham tra ve duong neu a lon hon bang b, tra ve am khi a be hon b
int Compare(string a, string b) {
	if (a.size() < b.size()) return -1;
	if (a.size() > b.size()) return 1;
	if (a > b) return 1;
	if (a < b) return -1;
	return 1;
}

// Ham tra ve so nguyen khong am khi cong 2 so nguyen khong am a va b
string CorePlus(string a, string b) {
	if (a.size() == 0 || a == "0") return b;
	if (b.size() == 0 || b == "0") return a;
	int temp = 0;
	int sum = 0;
	int n1 = a.size();
	int n2 = b.size();
	string ans;
	int i = 0;
	for (;i < n1 && i < n2;i++) {
		sum = a[n1 - 1 - i] + b[n2 - 1 - i] - 2 * '0' + temp;
		temp = sum / 10;
		sum %= 10;
		ans += sum + '0';
	}
	for (;i < n1;i++) {
		sum = a[n1 - 1 - i] - '0' + temp;
		temp = sum / 10;
		sum %= 10;
		ans += sum + '0';
	}
	for (;i < n2;i++) {
		sum = b[n2 - 1 - i] - '0' + temp;
		temp = sum / 10;
		sum %= 10;
		ans += sum + '0';
	}
	if (temp) {
		ans += temp + '0';
	}
	reverse(ans);
	return ans;
}


//Ham tra ve gia tri khi lay a tru cho b (tham so truyen vao a luon >=b && a, b lon hon 0)
string CoreMinus(string a, string b) {
	if (!a.size() || a == "0") {
		string ans = "-"+b;
		return ans;
	}
	if (!b.size() || b == "0") {
		return a;
	}
	if (a == b) {
		string ans;
		for (int i = 0;i < a.size();i++) {
			ans += '0';
		}return ans;
	}
	string ans;
	int temp = 0;
	int n1 = a.size();
	int n2 = b.size();
	int val;
	int i = 0;
	for (;i < n2;i++) {
		val = a[n1 - 1 - i] - b[n2 - 1 - i] - temp;
		if (val < 0) {
			temp = 1;
			val += 10;
		}
		else {
			temp = 0;
		}
		ans += val + '0';
	}
	for (;i < n1;i++) {
		val = a[n1 - 1 - i] - temp - '0';
		if (val < 0) {
			temp = 1;
			val += 10;
		}
		else {
			temp = 0;
		}
		ans += val + '0';
	}
	reverse(ans);
	return ans;
}

string Cong(string a, string b) {
	ChuanHoa(a);
	ChuanHoa(b);
	if (!a.size()) return b;
	if (!b.size()) return a;
	bool signA = a[0] == '-';
	if (signA) {
		a.erase(0, 1);
	}
	bool signB = b[0] == '-';
	if (signB) {
		b.erase(0, 1);
	}
	string ans;
	if (signA && signB) {
		ans = "-" + CorePlus(a, b);
	}
	if (!signA && !signB) {
		ans = CorePlus(a, b);
	}
	if (ans.size()) {
		ChuanHoa(ans);
		return ans;
	}

	if (signA) {
		if (Compare(a,b) == 1) {
			
			ans = "-" + CoreMinus(a, b);
		}
		else {
			ans = CoreMinus(b, a);
		}
		ChuanHoa(ans);
		return ans;
	}


	if (Compare(a,b) == 1) {
		ans = CoreMinus(a, b);
	}
	else {
		ans = "-" + CoreMinus(b, a);
	}
	ChuanHoa(ans);
	return ans;
}

string Tru(string a, string b) {
	if (a.size() == 0) return "-" + b;
	if (b.size() == 0) return a;
	b = "-" + b;
	return Cong(a, b);
}


//Ham tra ve boi so cua mot so trong khoang tu 0 den 9
string CoreMul(string a, char b) {
	if (b == '0') return "0";
	if (b == '1') {
		string ans;
		int n = a.size();
		for (int i = 0;i < n;i++) {
			ans += a[n - 1 - i];
		}
		return ans;
		
	}
	int times = b - '0';
	int temp = 0;
	int val;
	string ans;
	int n = a.size();
	for (int i = 0;i < n;i++) {
		val = (a[n - 1 - i] - '0') * times + temp;
		temp = val / 10;
		val %= 10;
		ans += val + '0';
	}
	if (temp) {
		ans += temp + '0';
	}
	return ans;
}

string AddReverse(string a, string b) {
	if (!a.size()) return b;
	if (!b.size()) return a;
	int n1 = a.size();
	int n2 = b.size();
	string ans;
	int i;
	int temp = 0;
	int val;
	for (i = 0;i < n1 && i < n2;i++) {
		val = a[i] + b[i] - 2 * '0' + temp;
		temp = val / 10;
		val %= 10;
		ans += val + '0';
	}
	for (;i < n1;i++) {
		val = a[i] - '0' + temp;
		temp = val / 10;
		val %= 10;
		ans += val + '0';
	}
	for (;i < n2;i++) {
		val = b[i] - '0' + temp;
		temp = val / 10;
		val %= 10;
		ans += val + '0';
	}
	if (temp) {
		ans += '1';
	}
	return ans;
}

string Nhan(string a, string b) {
	if (!b.size()) return a;
	if (!a.size()) return b;
	bool sign = 0;
	if (a[0] == '-') {
		sign = !sign;
		a.erase(0, 1);
	}
	if (b[0] == '-') {
		sign = !sign;
		b.erase(0, 1);
	}
	if (a == "0" || b == "0") return "0";
	vector<string> store(10, "0");
	for (int i = 1;i < 10;i++) {
		store[i] = CoreMul(a, i + '0');
	}
	int n = b.size();
	string ans;
	for (int i = 0;i < n;i++) {
		string temp;
		for (int j = 0;j < n - 1 - i;j++) {
			temp += '0';
		}temp += store[b[i] - '0'];
		ans = AddReverse(ans, temp);
	}
	if (sign) ans += '-';
	reverse(ans);
	return ans;
}



string Chia(string a, string b) {
	ChuanHoa(a);
	ChuanHoa(b);
	if (!a.size() || a == "0") return "0";
	if (!b.size() || b == "0") return "0";

	//luu dau cua ket qua
	bool sign = false;
	if (a[0] == '-') {
		sign = !sign;
		a.erase(0, 1);
	}
	if (b[0] == '-') {
		sign = !sign;
		b.erase(0, 1);
	}

	// luu bang gia tri nhan cua b vao mang mul
	vector<string> mul(10, "0");
	for (int i = 0;i < 10;i++) {
		mul[i] = CoreMul(b, i + '0');
		reverse(mul[i]);
	}
	string ans, tru, temp,des;
	int times;
	int Bsize = b.size();
	int Tsize = 0;
	int cnt;
	cnt = a.size();
	for (int i = 0;i < cnt;i++) {
		des += '0';
	}
	int Asize = a.size();
	cnt = 0;
	while (cnt != Asize) {
		temp += a[cnt];
		cnt++;
		Tsize++;
		times = 9;
		
		if (temp[0] == '0' && temp.size() > 1) {
			temp.erase(0, 1);
		}

		while (Compare(temp, mul[times]) == -1) {
			times--;
		}
		ans += times + '0';
		

		temp = CoreMinus(temp, mul[times]);
		for (int i = 0;i < Tsize;i++) {
			a[cnt-Tsize+i] = temp[i];
		}

		ChuanHoa(temp);
		Tsize = temp.size();

	}
	for (int i = cnt;i < a.size();i++) {
		ans += '0';
	}

	if (sign) {
		ans = "-" + ans;
	}
	ChuanHoa(ans);
	return ans;
}


bool isNum(char a) {
	return a >= '0' && a <= '9';
}

bool isNum(string a) {
	if (a.size() > 1) return true;
	return isNum(a[0]);
}

int prece(char a) {
	if (a == '*' || a == '/') return 2;
	return 1;
}

stack<string> reverse(stack<string> &s) {
	stack<string>ans;
	while (s.size()) {
		ans.push(s.top());
		s.pop();
	}
	return ans;
}

string solve(string s) {
	stack<string> postfix;
	string temp;
	stack<char> ope;
	string ans;


	for (char it : s) {
		if (it == ' ') continue;
		if (isNum(it)) {
			temp += it;
			continue;
		}

		if(temp.size()) postfix.push(temp);
		temp.clear();
		if (it == '(') {
			ope.push(it);
			continue;
		}
		if (it == ')') {
			while (ope.size() && ope.top() != '(') {
				temp.clear();
				temp += ope.top();
				postfix.push(temp);
				ope.pop();
			}
			if (ope.size()) {
				temp.clear();
				ope.pop();
			}
			else {
				return "Error !!";
			}continue;
		}
		if (it == '-') {
			if (ope.size() && ope.top() == '(') {
				temp += it;
				continue;
			}
		}
		while (ope.size() && ope.top() != '(' && prece(ope.top()) >= prece(it)) {
			
			temp += ope.top();
			postfix.push(temp);
			ope.pop();
			temp.clear();

		}
		ope.push(it);
	}
	
	if (temp.size()) {
		postfix.push(temp);
	}

	while (ope.size()) {
		temp.clear();
		temp += ope.top();
		postfix.push(temp);
		ope.pop();
	}
	
	postfix = reverse(postfix);

	stack<string>val;
	string a, b;
	char op;
	
	while (postfix.size()) {
		if (isNum(postfix.top())) {
			val.push(postfix.top());
		}
		else {
			op = postfix.top()[0];
			if (val.size() < 2) return "Errol !!";
			b = val.top();
			val.pop();
			a = val.top();
			val.pop();

			if (op == '+') {
				a = Cong(a, b);
			}
			if (op == '-') {
				a = Tru(a, b);
			}
			if (op == '*') {
				a = Nhan(a, b);
			}
			if (op == '/') {
				a = Chia(a, b);
			}
			if (a == "Error") {
				return a;
			}
			val.push(a);
		}
		postfix.pop();
	}
	return val.top();
}

int main() {
	cout << endl;
	string a = "-0";
	ChuanHoa(a);
	cout << a << endl;


	//ifstream doc("input.txt");
	//ofstream ghi("output.txt");
	//string ex;
	//
	//if (!doc.is_open()) {
	//	cout << "Loi khong mo duoc file input" << endl;
	//	return 1;
	//}
	//if (!ghi.is_open()) {
	//	cout << "Loi khong mo duoc file output" << endl;
	//	return 1;
	//}
	//
	//while (getline(doc, ex)) {	
	//	ghi << solve(ex) << endl;
	//}
	return 0;
}