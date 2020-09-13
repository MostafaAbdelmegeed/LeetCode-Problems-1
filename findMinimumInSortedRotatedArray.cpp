#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() <= 1) return nums.at(0); 
        int min = nums.at(nums.size() - 1);
        for (int i = nums.size()-2; i >= 0; i--) {
            cout << "Iteration #" << nums.size()-1-i << endl;
            printf("\tCurrent Comparison: (%d, %d), (%d, %d)\n", i, nums.at(i), i+1, nums.at(i+1));
            if (nums.at(i) < min) min = nums.at(i);
            if (nums.at(i) > nums.at(i+1)) break;
            printf("\tCurrent Minimum: %d\n", min);
        }
        return min;
    }
};

int main(){
    vector<int> testcase{3, 4, 5, 1, 2};
    Solution sol = Solution();
    int minimum = sol.findMin(testcase);
    printf("Final Minimum: %d\n", minimum);
    return 0;
}