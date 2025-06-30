#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(string a, string b) {
    if (a.length() < b.length()) swap(a, b);
    int carry = 0;
    string result;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (size_t i = 0; i < a.size(); i++) {
        int sum = a[i] - '0' + carry + (i < b.size() ? b[i] - '0' : 0);
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    if (carry) result.push_back(carry + '0');
    reverse(result.begin(), result.end());
    return result;
}
string subtract(string a, string b) {
    int borrow = 0;
    string result;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (size_t i = 0; i < a.size(); i++) {
        int diff = a[i] - '0' - borrow - (i < b.size() ? b[i] - '0' : 0);
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else borrow = 0;
        result.push_back(diff + '0');
    }
    while (result.size() > 1 && result.back() == '0') result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}
string karatsuba(string x, string y) {
    int n = max(x.size(), y.size());
    if (n == 1)
        return to_string((x[0] - '0') * (y[0] - '0'));
    while (x.size() < n) x = '0' + x;
    while (y.size() < n) y = '0' + y;
    if (n % 2) {
        n++;
        x = '0' + x;
        y = '0' + y;
    }
    string a = x.substr(0, n / 2), b = x.substr(n / 2);
    string c = y.substr(0, n / 2), d = y.substr(n / 2);
    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    string ab_cd = karatsuba(add(a, b), add(c, d));
    string mid = subtract(subtract(ab_cd, ac), bd);
    for (int i = 0; i < n; ++i) ac += '0';
    for (int i = 0; i < n / 2; ++i) mid += '0';

    return add(add(ac, mid), bd);
}
int main() {
    string num1 = "3141592653589793238462643383279502884197169399375105820974944592";
    string num2 = "2718281828459045235360287471352662497757247093699959574966967627";
    string product = karatsuba(num1, num2);
    cout << "Product = " << product << endl;
    return 0;
}