#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string addStrings(string num1, string num2) {
    if (num1.length() < num2.length()) {
        swap(num1, num2);
    }
    string result;
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    size_t startPos = result.find_first_not_of('0');
    if (startPos != string::npos) {
        return result.substr(startPos);
    }
    return "0";
}
string subtractStrings(string num1, string num2) {
    string result;
    int borrow = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0) {
        int digit1 = num1[i--] - '0' - borrow;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(digit1 - digit2 + '0');
    }
    reverse(result.begin(), result.end());
    size_t startPos = result.find_first_not_of('0');
    if (startPos != string::npos) {
        return result.substr(startPos);
    }
    return "0";
}
string karatsuba(string x, string y) {
    int lenX = x.length();
    int lenY = y.length();
    if (lenX == 1 && lenY == 1) {
        int product = (x[0] - '0') * (y[0] - '0');
        return to_string(product);
    }
    int maxLen = max(lenX, lenY);
    if (maxLen % 2 != 0) {
        maxLen++;
    }
    x = string(maxLen - lenX, '0') + x;
    y = string(maxLen - lenY, '0') + y;
    int half = maxLen / 2;
    string a = x.substr(0, half);
    string b = x.substr(half);
    string c = y.substr(0, half);
    string d = y.substr(half);
    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    string a_plus_b = addStrings(a, b);
    string c_plus_d = addStrings(c, d);
    string ad_plus_bc = subtractStrings(karatsuba(a_plus_b, c_plus_d), addStrings(ac, bd));
    string term1 = ac + string(maxLen, '0');
    string term2 = ad_plus_bc + string(half, '0');
    string temp = addStrings(term1, term2);
    string result = addStrings(temp, bd);
    size_t startPos = result.find_first_not_of('0');
    if (startPos != string::npos) {
        return result.substr(startPos);
    }
    return "0";
}int main() {
    string num1 = "123456789";
    string num2 = "987654321";
    string product = karatsuba(num1, num2);
    cout << "Product of " << num1 << " and " << num2 << " is: " << product << endl;
    return 0;
}