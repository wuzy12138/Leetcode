#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int solNum = 0;
    bool isValid(vector<string> board, int row, int col){
        int n = board.size();
        for(int i = 0; i < n; ++i){
            if (board[i][col] == 'Q'){
                return false;
            }
        }
        int rowTemp = row, colTemp = col;
        // upper left
        while(rowTemp >= 0 && colTemp >= 0){
            if(board[rowTemp][colTemp] == 'Q'){
                return false;
            }
            rowTemp --;
            colTemp --;
        }
        rowTemp = row;
        colTemp = col;
        // upper right
        while(rowTemp >= 0 && colTemp < n){
            if(board[rowTemp][colTemp] == 'Q'){
                return false;
            }
            rowTemp --;
            colTemp ++;
        }
        return true;
    }
    void backtrack(vector<string> board, int row){
        if(row == board.size()){
            solNum += 1;
            return;
        }
        int n = board[row].size();
        for (int i = 0; i < n; ++i) {
            if(!isValid(board, row, i)){
                continue;
            }
            board[row][i] = 'Q';
            backtrack(board, row + 1);
            board[row][i] = '.';
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return solNum;
    }
};

int main(){
    Solution *s = new Solution();
    // vector<stri> test = {1,2,3};
    int n = 4;
    // int target = 60;
    int res = s->totalNQueens(n);
    cout << res << endl;
    // for (auto item : res){
    //     for (auto ele : item){
    //         cout << ele << endl;
    //     }
    //     cout << "----" << endl;
    // }
    return 0;
}