#include <iostream>
#include <unordered_set>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    unordered_set<string> operators = {"+", "-", "*", "/"};
    int evalRPN(vector<string>& tokens) {
      stack<int> stack;
      for (string s : tokens) {
        //is digit
        if(operators.find(s) == operators.end()){
          cout << "s: " << s << endl;
          stack.push(stoi(s));
        }
        else{
            // cout << "s: " << s << endl;
            int digit1 = stack.top(); stack.pop();
            int digit2 = stack.top(); stack.pop();
            cout << digit1 << " " << digit2 << endl;
            
            int result = 0;
            if (s == "+") {
              result = digit2 + digit1;
            } else if (s == "-") {
              result = digit2 - digit1;
            } else if (s == "*") {
              result = digit2 * digit1;
            } else if (s == "/") {
              result = digit2 / digit1;
            }
            stack.push(result);
            cout << "result: " << result << endl;
        }
      }
      return stack.top();
    }
};

int main(){
    Solution *s = new Solution();
    // unordered_set<char> op = s->operators;
    vector<string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                             "/",  "*", "17", "+", "5", "+"};
    // vector<string> tokens = { "4", "13", "5", "/", "+" };

    cout << s->evalRPN(tokens) << endl;
}