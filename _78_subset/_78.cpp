#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    
    void backtrack(vector<int>& nums, int start){
        res.push_back(track);

        for(int i = start; i < nums.size(); ++i){
            track.push_back(nums[i]);
            backtrack(nums, i + 1);
            track.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

int main(){
    Solution *s = new Solution();
    // vector<stri> test = {1,2,3};
    // int n = 4;
    // int target = 60;
    vector<int> test = {1, 2, 3};
    vector<vector<int>> res = s->subsets(test);
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