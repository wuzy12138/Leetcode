#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> nums = {1,2,3,4,5,6,7,8,9};

    void backtrack(vector<int>& track, vector<int>& nums, vector<bool>& used, int k, int n, int start){
        if(n == 0 && track.size() == 3){
            result.push_back(track);
            return;
        }
        int s = nums.size();
        for(int i = start; i < s; ++i){
            if(used[i] || n < 0){
                continue;
            }
            track.push_back(nums[i]);
            backtrack(track, nums, used, k, n - nums[i], i + 1);
            track.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> track;
        vector<bool> used(nums.size(), false);
        backtrack(track, nums, used, k, n, 0);
        return result;
    }
};

int main(){
    Solution *s = new Solution();
    // vector<stri> test = {1,2,3};
    // int n = 4;
    // int target = 60;
    vector<vector<int>> res = s->combinationSum3(3, 7);
    for (auto item : res){
        for (auto ele : item){
            cout << ele << endl;
        }
        cout << "----" << endl;
    }
    // cout << s->solveNum << endl;
    return 0;
}