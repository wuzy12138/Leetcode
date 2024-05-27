#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
 vector<vector<int>> memo;

public:
 int dp(string s, string t, int i, int j) {
   if (j == t.length()) {
     return 1;
   }
   if (s.length() - i < t.length() - j) {
     return 0;
   }
   if (memo[i][j] != -1) {
     return memo[i][j];
   }
   int res = 0;
   for (int k = i; k < s.length(); ++k) {
     if (s[k] == t[j]) res += dp(s, t, k + 1, j + 1);
   }
   memo[i][j] = res;
   return res;
    }
    int numDistinct(string s, string t) {
        memo = vector<vector<int>>(s.length(), vector<int>(t.length(), -1));
        return dp(s, t, 0, 0);
    }
};

int main(){
    Solution *s = new Solution();
    string s1 = "babgbag";
    string s2 = "bag";
    cout << (s->numDistinct(s1, s2)) << endl;
    return 0;
}