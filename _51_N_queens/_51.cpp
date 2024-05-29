#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    int solveNum = 0;
    bool isValid(vector<string> board, int row, int col){
        int n = board.size();
        // // horizontal
        // for(int i = 0; i < n; ++i){
        //     if (board[row][i] == 'Q'){
        //         return false;
        //     }
        // }
        // vertical
        for(int i = 0; i < n; ++i){
            if (board[i][col] == 'Q'){
                return false;
            }
        }
        // // toward right bottom
        int rowTemp = row, colTemp = col;
        // while(rowTemp < n && colTemp < n){
        //     if(board[rowTemp][colTemp] == 'Q'){
        //         return false;
        //     }
        //     rowTemp++;
        //     colTemp++;
        // }

        // toward upper left
        rowTemp = row;
        colTemp = col;
        while(rowTemp >= 0 && colTemp >= 0){
            if(board[rowTemp][colTemp] == 'Q'){
                return false;
            }
            rowTemp--;
            colTemp--;
        }

        // toward upper right 
        rowTemp = row;
        colTemp = col;
        while(rowTemp >= 0 && colTemp < n){
            if(board[rowTemp][colTemp] == 'Q'){
                return false;
            }
            rowTemp--;
            colTemp++;
        }

        // // toward left bottom
        // rowTemp = row;
        // colTemp = col;
        // while(rowTemp < n && colTemp >= 0){
        //     if(board[rowTemp][colTemp] == 'Q'){
        //         return false;
        //     }
        //     rowTemp++;
        //     colTemp--;
        // }
        return true;
    }
    void backtrack(vector<string> board, int row) {
      if (row == board.size()) {
        result.push_back(board);
        solveNum++;
        return;
      }
      int n = board[row].size();
      for (int i = 0; i < n; ++i){
        if (!isValid(board, row, i)) {
            continue;
        }
        board[row][i] = 'Q';
        backtrack(board, row + 1);
        board[row][i] = '.';
      }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return result;
    }
};

int main(){
    Solution *s = new Solution();
    // vector<stri> test = {1,2,3};
    int n = 4;
    // int target = 60;
    vector<vector<string>> res = s->solveNQueens(n);
    for (auto item : res){
        for (auto ele : item){
            cout << ele << endl;
        }
        cout << "----" << endl;
    }
    cout << s->solveNum << endl;
    return 0;
}