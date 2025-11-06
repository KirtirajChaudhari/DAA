//-------------------------------------------------------------
//N-Queens Problem using Backtracking
//-------------------------------------------------------------

#include <iostream>
using namespace std;

int n, col[20], d1[40], d2[40], board[20][20];
int fixedCol; // first queen column

bool solve(int r) {
    if(r == n) return true;

    if(r == 0) { // first queen already placed
        col[fixedCol] = d1[r+fixedCol] = d2[r-fixedCol+n] = 1;
        board[r][fixedCol] = 1;
        return solve(r+1);
    }

    for(int c = 0; c < n; c++) {
        if(!col[c] && !d1[r+c] && !d2[r-c+n]) {
            col[c] = d1[r+c] = d2[r-c+n] = 1;
            board[r][c] = 1;

            if(solve(r+1)) return true;

            col[c] = d1[r+c] = d2[r-c+n] = 0;
            board[r][c] = 0;
        }
    }
    return false;
}

int main() {
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter the column (0 to n-1) for first queen: ";
    cin >> fixedCol;

    if(solve(0)) {
        cout << "\nN-Queens solution:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution possible!\n";
    }
}
