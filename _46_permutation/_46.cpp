#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, vector<int>& track, vector<int>& used){
        if(track.size() == nums.size()){
            result.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i){
            if(used[i]){
              continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, track, used);
            track.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        vector<int> used(nums.size(), false);
        backtrack(nums, track, used);
        return result;
    }
};

int main(){
    Solution *s = new Solution();
    vector<int> test = {1,2,3};
    // int target = 60;
    vector<vector<int>> res = s->permute(test);
    for (auto item : res){
        for (auto ele : item){
            cout << ele << endl;
        }
        cout << "----" << endl;
    }
    return 0;
}