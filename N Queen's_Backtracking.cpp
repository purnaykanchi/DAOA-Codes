#include <iostream>
#include <vector>
using namespace std;
#define N 6
struct State {
    vector<int> queens;
    bool isValid() const {
        for(int i=0; i<size(); i++) {
            for(int j=i+1; j<size(); j++) {
                if(queens[i] == queens[j] || abs(queens[i] - queens[j]) == j - i) {
                    return false;
                }
            }
        }
        return true;
    }
};
    vector<State> generateChildren(const State& parent) {
        vector<State> children;
        for(int col=0; col<N; col++) {
            State child = parent;
            child.queens.push_back(col);
            if(child.isValid()) {
                children.push_back(child);
            }
        }
        return children;
    }
void solveNQueens(const State& current) {
    if(current.queens.size() == N) {
        for(int col : current.queens) {
            cout << col << " ";
        }
        cout << endl;
        return;
    }
    vector<State> children = generateChildren(current);
    for(const State& child : children) {
        solveNQueens(child);
    }
}
int main() {
    State initial;
    solveNQueens(initial);
    return 0;
}