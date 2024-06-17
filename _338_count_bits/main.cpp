#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bits(int n){
        int count = 0;
        while(n > 0){ 
            if((n & 1) == 1){
                count++;
            }
            n >>= 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; ++i){
            res.push_back(bits(i));
        }
        return res;
    }
};

int main(){
    Solution *s = new Solution();
    cout << s->bits(5) << endl;
}