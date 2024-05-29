#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> states;
    vector<int> result;
    bool isIllu(int lampRow, int lampCol, int row, int col){
        if(lampRow == row || lampCol == col || abs(lampRow - row) == abs(lampCol - col)){
            return true;
        }
        return false;
    }
    bool isAdjacent(vector<int> lamp1, vector<int> lamp2){
      int lamp1Row = lamp1[0], lamp1Col = lamp1[1], lamp2Row = lamp2[0], lamp2Col = lamp2[1];
      if (abs(lamp1Row - lamp1Col) <= 1 || abs(lamp2Row - lamp2Col) <= 1) {
        return true;
      }
        return false;
    }
    void backtrack(vector<vector<int>>& grid, vector<int>& lamp, int row, vector<vector<int>>& queries){
        if(row == lamp.size()){
            for(vector<int> query : queries){
                states.push_back(grid[query[0]][query[1]]);
            }
            return;
        }
        int n = grid.size();
        for(int col = 0; col < n; ++col){
            if(!isIllu(lamp[0], lamp[1], row, col)){
                continue;
            }
            grid[row][col] = 1;
            backtrack(grid, lamp, row + 1, queries);
            grid[row][col] = 0;
        }
    }



    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for(auto query : queries){
          states.push_back(grid[query[0]][query[1]]);
        }
        //initial state of queries
        for(auto lamp : lamps){
            backtrack(grid, lamp, 0, queries);
        }
        for(auto query : queries){
            result.push_back(grid[query[0]][query[1]]);
            
            for (auto it = lamps.begin(); it != lamps.end(); ) {
                if (isAdjacent(*it, query)) {
                    it = lamps.erase(it);  // erase 会返回下一个有效的迭代器
                } else {
                    ++it;  // 只有在不删除元素时才移动迭代器
                }
            }
            for(auto lamp : lamps){
                backtrack(grid, lamp, 0, queries);
            }
        }
        
        return result;
    }
};



int main(){
    Solution *s = new Solution();
    // vector<stri> test = {1,2,3};
    int n = 5;
    vector<vector<int>> lamps = {{0, 0}, {4, 4}};
    vector<vector<int>> queries = {{1, 1}, {1, 0}};
    // int target = 60;
    vector<int> res = s->gridIllumination(n, lamps, queries);
    // cout << res << endl;
    // for (auto item : res){
    //     for (auto ele : item){
    //         cout << ele << endl;
    //     }
    //     cout << "----" << endl;
    // }
    for(auto item : res){
        cout << item << endl;
        cout << "----" << endl;
    }
    return 0;
}