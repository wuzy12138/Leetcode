#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <deque>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    deque<int> track;
    void backtrack(int start, int n, int k){
        if(track.size() == k){
          result.push_back(vector<int>(track.begin(), track.end()));
          return;
        }
        for(int i = start; i <= n; ++i){
            track.push_back(i);
            backtrack(i + 1, n, k);
            track.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return result;
    }
};

int main(){
    Solution *s = new Solution();
    // vector<stri> test = {1,2,3};
    // int n = 4;
    // int target = 60;
    vector<int> test = {1, 2, 3};
    vector<vector<int>> res = s->combine(4,2);
    cout << "start" << endl<<endl;
    for (auto item : res) {
      for (auto ele : item) {
        cout << ele << endl;
      }
      cout << "----" << endl;
    }
    // cout << s->solveNum << endl;
    return 0;
}