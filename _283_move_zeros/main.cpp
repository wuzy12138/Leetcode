#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int left = 0;
    int right = 0;
    while (right < nums.size()) {
      if (nums[right] != 0) {
        nums[left] = nums[right];
        // cout << left << endl;
        left++;
      }
      right++;
    }
    while (left < nums.size()) {
      nums[left] = 0;
      left++;
    }
  }
};

int main(){
    Solution *s = new Solution();
    vector<int> nums = {0, 1, 0, 3, 10};
    s->moveZeroes(nums);
    for (int num : nums) {
      cout << num << " ";
    }
}