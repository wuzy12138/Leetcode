#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> monotonic_stack(vector<int> nums){
    int n = nums.size();
    vector<int> res(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i){
      while(!s.empty() && s.top() <= nums[i]){
        s.pop();
      }
      res[i] = s.empty() ? -1 : s.top();
      s.push(nums[i]);
    }
    return res;
}

int main(){
    vector<int> nums = {10,6,8,5,11,9};
    vector<int> res = monotonic_stack(nums);

    for(int r : res){
      cout << "r: " << r << endl;
    }
    
}