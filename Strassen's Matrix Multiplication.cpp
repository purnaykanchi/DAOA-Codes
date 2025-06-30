#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> split(vector<vector<int>> a, int x, int y) {
    int n = a.size();
    vector<vector<int>> b(a.size()/2, vector<int>(a.size()/2, 0));
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            b[i][j] = a[i+x][j+y];
        }
    }
    return b;
}
vector<vector<int>> add(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
vector<vector<int>> strassen(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n, 0));
    if (n == 1) {
        c[0][0] = a[0][0] * b[0][0];
        return c;
    }
    vector<vector<int>> a11 = split(a, 0, 0), a12 = split(a, 0, n/2), a21 = split(a, n/2, 0),
                        a22 = split(a, n/2, n/2);
    vector<vector<int>> b11 = split(b, 0, 0), b12 = split(b, 0, n/2), b21 = split(b, n/2, 0),
                        b22 = split(b, n/2, n/2);
    vector<vector<int>> x = strassen(a11, b11), y = strassen(a12, b21);
    vector<vector<int>> c11 = add(x, y);
    x = strassen(a11, b12);
    y = strassen(a12, b22);
    vector<vector<int>> c12 = add(x, y);
    x = strassen(a21, b11);
    y = strassen(a22, b12);
    vector<vector<int>> c21 = add(x, y);
    x = strassen(a21, b12);
    y = strassen(a22, b22);
    vector<vector<int>> c22 = add(x, y);
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            c[i][j] = c11[i][j];
            c[i][j+n/2] = c12[i][j];
            c[i+n/2][j] = c21[i][j];
            c[i+n/2][j+n/2] = c22[i][j];
        }
    }
    return c;
}
int main() {
    vector<vector<int>> a = {{0, 0, 3, 4}, {5, 6, 0, 0}, {0, 0, 6, 5}, {4, 3, 0, 0}};
    vector<vector<int>> b = {{0, 0, 6, 5}, {4, 3, 0, 0}, {0, 0, 3, 4}, {5, 6, 0, 0}};
    vector<vector<int>> c = strassen(a, b);
    print(c);
    return 0;
}