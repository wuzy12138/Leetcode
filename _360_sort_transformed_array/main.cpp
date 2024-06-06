#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int solve(int a, int b, int c, int x){
        return a * x * x + b * x + c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        vector<int> result(n, 0);
        int p = r;
        // vector<int> result;
        while(l <= r){
            int n1 = nums[l];
            int n2 = nums[r];
            // cout << "d1 = " << abs(n1 - min) << "; d2 = " << abs(n2 - min) << endl;
            // cout << "a1 = " << solve(a, b, c, n1) << "; a2 = " << solve(a, b, c, n2) << endl;
            if(a > 0){
                float min = - b / 2 / float(a);
                if (abs(n1 - min) > abs(n2 - min)) {
                    result[p] = (solve(a, b, c, n1));
                    l++;
                } else {
                    result[p] = (solve(a, b, c, n2));
                    r--;
                }
            }
            else if(a < 0){
                float min = - b / 2 / float(a);
                if (abs(n1 - min) < abs(n2 - min)) {
                    result[p] = (solve(a, b, c, n1));
                    l++;
                } else {
                    result[p] = (solve(a, b, c, n2));
                    r--;
                }
            }
            else{
                if(b >= 0){
                  result.push_back(solve(a, b, c, n1));
                  l++;
                }
                else{
                  result.push_back(solve(a, b, c, n2));
                  r--;
                }
            }
            p--;
        }
        return result;
    }
};


int main(){
    Solution *s = new Solution();
    // vector<int> nums = {0,1,1};
    // [-4,-2,2,4], 
    vector<int> nums = {-4,-2,2,4};
    int a = -1, b = 3, c = 5;
    // int a = 1, b = 3, c = 5;
    // vector<int> nums =
    // {1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,1};
    vector<int> result = s->sortTransformedArray(nums, a, b, c);
    for(int i : result){
      cout << i << endl;
    }
    return 0;
}