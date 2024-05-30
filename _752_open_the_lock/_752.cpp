#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    string plusOne(string s, int j){
        char ch[s.length()+1];
        strcpy(ch, s.c_str());
        if(ch[j] == '9'){
          ch[j] = '0';
        }
        else{
          ch[j]++;
        }
        string res(ch);
        return res;
    }
    string minusOne(string s, int j){
        char ch[s.length()+1];
        strcpy(ch, s.c_str());
        if(ch[j] == '0'){
          ch[j] = '9';
        }
        else{
          ch[j]--;
        }
        string res(ch);
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads;
        for (string deadend : deadends) {
          deads.insert(deadend);
        }
        queue<string> q;
        unordered_set<string> visited;
        int step = 0;
        q.push("0000");
        visited.insert("0000");

        while (!q.empty()) {
          int sz = q.size();
          for(int i = 0; i < sz; ++i){
            string cur = q.front();
            q.pop();
            // cout << cur << endl;
            if(deads.count(cur)){
              continue;
            }
            if(cur == target){
              return step;
            }
            for(int j = 0; j < 4; ++j){
              string up = plusOne(cur, j);
              string down = minusOne(cur, j);
              if (!visited.count(up)){ 
                q.push(up);
                visited.insert(up);
              }
              if (!visited.count(down)){
                q.push(down);
                visited.insert(down);
              }
            }
          }
          step += 1;
        }
        return -1;
    }
};

int main(){
    Solution *s = new Solution();

    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    // vector<string> deadends = {"8888"};
    // vector<string> deadends = {"8887", "8889", "8878", "8898",
    //                            "8788", "8988", "7888", "9888"};

    string target = "0202";
    // string target = "0009";
    // string target = "8888";
    cout << s->openLock(deadends, target) << endl;
}