#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int myAtoi(string s) { 
    int sign = 1;
    int sum = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (c == '-') sign = -1;
      else{
        sum *= 10;
        int bit = c - '0';
        sum += bit;
      }
    }
    return sum * sign;
  }
};

int main(){
    Solution *s = new Solution();
    string str = "-42";
    int result = s->myAtoi(str);
    cout << result << endl;
}