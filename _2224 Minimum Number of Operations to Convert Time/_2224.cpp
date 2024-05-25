#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
 private:
  vector<int> memo;

 public:
  int dp(int diff, vector<int>& choices) {
    if (dp(diff, choices) == 0) return 0;
    if (dp(diff, choices) < 0) return -1;
    if (memo[diff] != -666) {
      return memo[diff];
    }
    int res = INT_MAX;
    for (int choice : choices) {
      int subprob = dp(diff - choice, choices);
      if (subprob == -1) {
        continue;
      }
      res = min(res, subprob + 1);
    }
    memo[diff] = res == INT_MAX ? -1 : res;
    return memo[diff];
  }
  int convertTime(string current, string correct) {
    int currentHour = stoi(current.substr(0, 2));
    int correctHour = stoi(correct.substr(0, 2));
    int currentMin = stoi(current.substr(3, 2));
    int correctMin = stoi(correct.substr(3, 2));
    int minuteDiff =
        (correctHour - currentHour) * 60 + (correctMin - currentMin);
    memo = vector<int>(minuteDiff + 1, -666);
    int temp[4] = {1, 5, 15, 60};
    vector<int> choices(temp, temp + 4);
    return dp(minuteDiff, choices);
  }
};

int main(){
    Solution *s = new Solution();
    cout << (s -> convertTime("02:30", "04:35"));
}