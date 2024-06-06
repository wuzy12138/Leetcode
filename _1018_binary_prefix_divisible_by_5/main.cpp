#include <iostream>
#include <vector>
using namespace std;
//乘以2 = 10 =》 整除5
//或者是只要匹配011，
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<bool> result;
        for (int i = 0; i < n; ++i) {
          sum = (sum * 2 + nums[i]) % 5;
          result.push_back(sum == 0);
        }
        return result;
    }
};

int main(){
    Solution *s = new Solution();
    // vector<int> nums = {0,1,1};
    vector<int> nums = {0, 1, 1, 1, 1, 1};
    // vector<int> nums =
    // {1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,1};
    vector<bool> result = s->prefixesDivBy5(nums);
    for(bool i : result){
      cout << i << endl;
    }
    return 0;
}