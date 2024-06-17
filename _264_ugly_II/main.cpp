#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int p1 = 1, p2 = 1, p3 = 1;
        n -= 1;
        int num1 = 1, num2 = 1, num3 = 1, minVal = 1;
        while(n--){
            num1 = p1 * 2;
            num2 = p2 * 3;
            num2 = p3 * 5;
            minVal = min({num1, num2, num3});
            cout << minVal << endl;
            cout << p1 << " " << p2 << " " << p3 << endl;
            cout << num1 << " " << num2 << " " << num3 << endl;
            if (num1 == minVal) {
              p1++;
            }
            if(num2 == minVal){
                p2++;
            }
            if(num3 == minVal){
                p3++;
            }
        }
        return minVal;
    }
};

int main(){
    Solution *s = new Solution();
    cout << s->nthUglyNumber(12) << endl;
    ;
}