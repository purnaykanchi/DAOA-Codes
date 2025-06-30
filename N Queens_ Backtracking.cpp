#include<iostream>
#include<string>
#include<vector>
using namespace std;
int boardcnt = 0;
bool IsBoardOk(vector<string>& chessboard, int row, int col) {
    for(int c=0; c<col; c++){
        if(chessboard[row][c] == 'Q') {
            return false;
        }
    }
    for(int r=row-1, c=col-1; r>=0 && c>=0; r--, c--){
        if(chessboard[r][c] == 'Q') {
            return false;
        }
    }
    for(int r=row+1, c=col-1; c>=0 && r<chessboard.size(); r++, c--){
        if(chessboard[r][c] == 'Q') {
            return false;
        }
    }
    return true;
}
void DisplayBoard(vector<string>& chessboard) {
    for(auto& row : chessboard) {
        for(auto& ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void PlaceNQueens(vector<string>& chessboard, int col) {
    if(col >= chessboard.size()) {
        cout << endl << "Board " << ++boardcnt << endl;
        cout << "--------" << endl;
        DisplayBoard(chessboard);
        cout << endl;
    } else {
        for(int row=0; row<chessboard.size(); row++) {
            if(IsBoardOk(chessboard, row, col) == true) {
                chessboard[row][col] = 'Q';
                PlaceNQueens(chessboard, col+1);
                chessboard[row][col] = '.';
            }
        }
    }
}
int main() {
    vector<string> chessboard;
    int N;
    cout << "Enter chessboard size: ";
    cin >> N;
    for(int i=0; i<N; i++) {
        string row(N, '.');
        chessboard.push_back(row);
    }
    PlaceNQueens(chessboard, 0);
    return 0;
}