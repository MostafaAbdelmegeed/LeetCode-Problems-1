#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /**
         * TODO: 1- Check whether there are overlapping intervals
         *       2- New Interval = (min_start, max_end)
         *       3- Remove all intervals with a start >= the new interval start and end <= new interval end
         *       4- insert the new Interval at the correct location
         */
        vector<vector<int>> result{};
        for (int i = 0; i < intervals.size(); i++) {
            if (compare(newInterval, intervals.at(i))) intervals.insert(vector::begin)
        }
        return result;
    }

    bool isOverlapping(vector<int> i1, vector<int> i2) {
        if (i1.at(0) == i2.at(0) || i1.at(1) == i2.at(1) || i1.at(0) == i2.at(1) || i2.at(0) == i1.at(1)) return true;
        if (i1.at(0) <= i2.at(0) && i1.at(1) >= i2.at(1)) return true;
        if (i2.at(0) <= i1.at(0) && i2.at(1) >= i1.at(1)) return true;
        if (i2.at(0) >= i1.at(0) && i2.at(1) <= i1.at(1)) return true;
        if (i1.at(0) >= i2.at(0) && i1.at(1) <= i2.at(1)) return true;
        return false;
    }

    vector<int> merge(vector<int> i1, vector<int> i2){
        if (!isOverlapping(i1, i2)) throw "Cannot merge non overlapping intervals!";
        else {
            return vector<int> {min(i1.at(0),i2.at(0)), max(i1.at(1), i2.at(1))};
        }
    }

    int compare(vector<int> i1, vector<int> i2) {
        if (i1.at(0) == i2.at(0) && i1.at(1) == i2.at(1)) return 0;
        if (i1.at(0) > i2.at(0)) return 1;
        if (i1.at(0) > i2.at(0) && i1.at(1) > i2.at(1)) return 1;
        else return -1;
    }
};

int main(){
    vector<vector<int>> intervals{{1,3},{6,9}};
    vector<int> newInterval1{2,5};
    vector<int> newInterval2{3,4};
    vector<int> newInterval3{10,12};
    printf("Inputs:\n\tIntervals: [");
    for(vector<int> x: intervals) {
        printf("[%d, %d], ", x.at(0), x.at(1));
    }
    printf("]\n");
    printf("\tNew Interval: [%d, %d]\n", newInterval3.at(0), newInterval3.at(1));
    Solution sol = Solution();
    printf("isOverlapping(): %d\n", sol.isOverlapping(newInterval1, newInterval3));
    printf("compare() test: %d\n", sol.compare(newInterval1, newInterval2) == -1);
    printf("merge() test: %d\n", sol.merge(newInterval1, newInterval2).at(0) == 2 && sol.merge(newInterval1, newInterval2).at(1) == 5);
    vector<vector<int>> result = sol.insert(intervals, newInterval3);
    printf("Results:\n\t[");
    for(vector<int> x: result){
        printf("[%d, %d], ", x.at(0),x.at(1));
    }
    printf("]\n");
    return 0;
}