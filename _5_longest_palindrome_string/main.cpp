#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  string judgePalindrome(string s, int l, int r) {
    while(l >= 0 && r < s.length() && s[l]==s[r]){
      r++;
      l--;
    }
    return s.substr(l + 1, r - l - 1);
  }
  string longestPalindrome(string s) {
    // string s1, s2;
    string res = "";
    for (int i = 0; i < s.length(); ++i) {
      string s1 = judgePalindrome(s, i, i);
      string s2 = judgePalindrome(s, i, i + 1);
      res = res.length() > s1.length() ? res : s1;
      res = res.length() > s2.length() ? res : s2;
    }
    return res;
  }
};

int main() {
  Solution *s = new Solution();
  cout << s->longestPalindrome("babaa") << endl;
  return 0;
}