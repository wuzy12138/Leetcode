#include <iostream>
#include<vector>
using namespace std;

class Solution {
 public:
  vector<int> preProd, postProd;
  void updatePrePost(vector<int>& nums) {
    int n = nums.size();
    preProd = vector<int>(n + 1, 1);
    postProd = vector<int>(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
      preProd[i] = preProd[i - 1] * nums[i - 1];
      postProd[i] = postProd[i - 1] * nums[n - i];
      cout << i - 1 << " " << n - i << endl;
      ;
    }
  }
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    updatePrePost(nums);
    vector<int> answer;
    for (int i = 1; i <= n; ++i) {
      answer.push_back(preProd[i - 1] * postProd[i - 1]);
    }
    return answer;
  }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution* s = new Solution();
    vector<int> answer = s->productExceptSelf(nums);
    vector<int> pre = s->preProd;
    vector<int> post = s->postProd;

    for(int a : answer){
      cout << a << endl;
    }
    for(int p : pre){
      cout << p << endl;
    }
    for(int p : pre){
      cout << p << endl;
    }
}