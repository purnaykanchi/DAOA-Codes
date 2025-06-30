#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
        char* result = (char*)malloc(maxLen + 2); 
    result[maxLen + 1] = '\0';
    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = maxLen;
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }
    char* finalResult = result + k + 1;
    if (finalResult[0] == '0' && finalResult[1] != '\0') {
        finalResult++;
    }
    return finalResult;
}
char* subtractStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1; 
    char* result = (char*)malloc(maxLen + 1);
    result[maxLen] = '\0';
    int borrow = 0;
    int i = len1 - 1, j = len2 - 1, k = maxLen - 1;
    while (i >= 0) {
        int digit1 = num1[i--] - '0' - borrow;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[k--] = (digit1 - digit2) + '0';
    }
    while (result[0] == '0' && result[1] != '\0') {
        result++;
    }
    return result;
}
char* karatsuba(char* x, char* y) {
    int lenX = strlen(x);
    int lenY = strlen(y);
    if (lenX == 1 && lenY == 1) {
        int product = (x[0] - '0') * (y[0] - '0');
        char* result = (char*)malloc(3);
        if (product < 10) {
            result[0] = product + '0';
            result[1] = '\0';
        } else {
            result[0] = (product / 10) + '0';
            result[1] = (product % 10) + '0';
            result[2] = '\0';
        }
        return result;
    }
    int maxLen = (lenX > lenY) ? lenX : lenY;
    if (maxLen % 2 != 0) {
        maxLen++;
    }
    char* xPadded = (char*)malloc(maxLen + 1);
    char* yPadded = (char*)malloc(maxLen + 1);
    memset(xPadded, '0', maxLen - lenX);
    strcpy(xPadded + (maxLen - lenX), x);
    memset(yPadded, '0', maxLen - lenY);
    strcpy(yPadded + (maxLen - lenY), y);
    int half = maxLen / 2;
    char* a = (char*)malloc(half + 1);
    strncpy(a, xPadded, half);
    a[half] = '\0';
    char* b = (char*)malloc(half + 1);
    strcpy(b, xPadded + half);
    char* c = (char*)malloc(half + 1);
    strncpy(c, yPadded, half);
    c[half] = '\0';
    char* d = (char*)malloc(half + 1);
    strcpy(d, yPadded + half);
    char* ac = karatsuba(a, c);
    char* bd = karatsuba(b, d);
    char* a_plus_b = addStrings(a, b);
    char* c_plus_d = addStrings(c, d);
    char* ad_plus_bc = subtractStrings(karatsuba(a_plus_b, c_plus_d), addStrings(ac, bd));
    char* term1 = (char*)malloc(strlen(ac) + maxLen + 1);
    strcpy(term1, ac);
    for (int i = 0; i < maxLen; i++) {
        strcat(term1, "0");
    }
    char* term2 = (char*)malloc(strlen(ad_plus_bc) + half + 1);
    strcpy(term2, ad_plus_bc);
    for (int i = 0; i < half; i++) {
        strcat(term2, "0");
    }
    char* temp = addStrings(term1, term2);
    char* result = addStrings(temp, bd);
    free(xPadded);
    free(yPadded);
    free(a);
    free(b);
    free(c);
    free(d);
    free(ac);
    free(bd);
    free(a_plus_b);
    free(c_plus_d);
    free(ad_plus_bc);
    free(term1);
    free(term2);
    free(temp);
    return result;
}
int main() {
    char num1[] = "123456789";
    char num2[] = "987654321";
    char* product = karatsuba(num1, num2);
    printf("Product of %s and %s is: %s\n", num1, num2, product);
    free(product);
    return 0;
}