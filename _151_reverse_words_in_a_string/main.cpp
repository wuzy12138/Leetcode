#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int n = s.size();
        int r = n - 1;
        vector<string> wordList(n, "");
        int p = r;
        while (l < r) {
          while (s[l] == ' ') {
            l++;
          }
          while (s[r] == ' ') {
            r--;
          }
          if()
        }
    }
};


int main(){
    Solution *s = new Solution();
    string test = " a good   example      ";
    string result = s->reverseWords(test);
    cout << result << endl;
    return 0;
}