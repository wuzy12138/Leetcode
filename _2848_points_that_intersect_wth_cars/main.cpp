#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> record;
        for(vector<int> num : nums){
          for (int i = num[0]; i <= num[1]; ++i){
            record.insert(i);
          }
        }
        return record.size();
    }
};

int main(){
    Solution *s = new Solution();
    // vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> nums = {{3, 6}, {1, 5}, {4, 7}};
    // nums = [1,0,-1,0,-2,2], target = 0
    // int target = 0;
    int result = s->numberOfPoints(nums);
    cout << result << endl;
    return 0;
}