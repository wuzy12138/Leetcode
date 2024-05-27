#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int left = 0;
        int right = r * c - 1;

        while(left <= right){
            int mid = (left + right) / 2;
            // num = i * r + j
            int newR = mid / c;
            int newC = mid % c ;
            if(matrix[newR][newC] == target){
                return true;
            }
            else if(matrix[newR][newC] > target){
                right = mid - 1;
            }
            else if(matrix[newR][newC] < target){
                left = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    Solution *s = new Solution();
    vector<vector<int>> test = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 60;
    cout << (s->searchMatrix(test, target)) << endl;
    return 0;
}