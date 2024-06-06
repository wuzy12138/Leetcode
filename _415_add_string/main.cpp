#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cassert>
#include <stack>
using namespace std;
//双指针，一位一位加
class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        string result = "";
        int carry = 0;
        // char c1 = '', c2 = '';
        while(p1 >= 0 && p2 >= 0){
            char c1 = num1[p1];
            char c2 = num2[p2];
            int temp = (c1 - '0') + (c2 - '0') + carry;
            carry = temp / 10;
            int digit = temp % 10;
            char resultC = digit + '0';
            result.push_back(resultC);
            p1--;
            p2--;
        }
        while(p1 >= 0){
            char c1 = num1[p1];
            // char c2 = nums[p2];
            int temp = (c1 - '0') + carry;
            carry = temp / 10;
            int digit = temp % 10;
            char resultC = digit + '0';
            result.push_back(resultC);
            p1--;
        }
        while(p2 >= 0){
            char c1 = num2[p2];
            // char c2 = nums[p2];
            int temp = (c1 - '0')+ carry;
            carry = temp / 10;
            int digit = temp % 10;
            char resultC = digit + '0';
            result.push_back(resultC);
            p2--;
        }
        if(carry == 1)
            result.push_back(carry + '0');
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution *s = new Solution();
    // vector<int> nums = {1,0,-1,0,-2,2};
    // int N = 3, W = 4;
    string num1 = "11";
    string num2 = "456";
    // nums = [1,0,-1,0,-2,2], target = 0
    // int target = 0;
    string result = s->addStrings(num1, num2);
    // string temp = "1234";
    // char c = temp();
    cout << result << endl;
    return 0;
}