#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class MonotonicQueue {
 private:
  deque<int> d;
 public:
    void push(int x){
        while(!d.empty() && d.back() < x){
          d.pop_back();
        }
        d.push_back(x);
    }
    int max(){
        return d.front();
    }
    void pop(int n){
        if(n == d.front()){
          d.pop_front();
        }
    }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue mq;
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if(i < k - 1){
        mq.push(nums[i]);
      }
      else{
        mq.push(nums[i]);
        res.push_back(mq.max());
        mq.pop(nums[i - k + 1]);
      }
    }
    return res;
  }
};

int main(){
    Solution *s = new Solution();
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = s->maxSlidingWindow(nums, k);
    for(auto b : res){
      cout << b << " ";
    }
}