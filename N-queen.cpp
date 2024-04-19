#include <bits/stdc++.h>
using namespace std;
int N;

void printSol(vector<vector<int>> board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(board[i][j]==1)  cout<<"Q"<<" ";
            else                cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isSafe(int row, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
{
    if (rows[row] == true || left_digonals[row + col] == true || Right_digonals[col - row + N - 1] == true)
    {
        return false;
    }

    return true;
}

bool solve(vector<vector<int>> &board, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
{
    if (col >= N)   return true;
    
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col, rows, left_digonals, Right_digonals) == true)
        {
            rows[i] = true;
            left_digonals[i + col] = true;
            Right_digonals[col - i + N - 1] = true;
            board[i][col] = 1; 

            if (solve(board, col + 1, rows, left_digonals, Right_digonals) == true)      return true;
            
            rows[i] = false;
            left_digonals[i + col] = false;
            Right_digonals[col - i + N - 1] = false;
            board[i][col] = 0; 
        }
    }
    return false;
}

int main()
{
    cout << "Enter the no of rows for the square Board : ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<bool> rows(N, false);

    vector<bool> left_digonals(2 * N - 1, false);
    vector<bool> Right_digonals(2 * N - 1, false);

    bool ans = solve(board, 0, rows, left_digonals, Right_digonals);

    if (ans == true)        printSol(board);
    else                    cout << "Solution Does not Exist\n";
    
}
