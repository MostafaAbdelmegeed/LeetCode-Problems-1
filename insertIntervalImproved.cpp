#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<int> temp = newInterval;
        int first = -1, last = -1;
        for (int i = 0; i < intervals.size(); i++){
            if (isOverlapping(newInterval, intervals.at(i))) {
                if (first == -1) first = i;
                temp = merge(temp, intervals.at(i));
            } else if (first != -1) {
                last = i;
                break;
            } else if (compare(newInterval, intervals.at(i)) == -1) {
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            } else if (i == intervals.size() - 1) intervals.push_back(newInterval);
        }
        if (first != -1 && last == -1) last = intervals.size();
        if (first != -1) {
            intervals.insert(intervals.begin() + first, temp);
            if (last-first == 1) intervals.erase(intervals.begin() + first + 1);
            else intervals.erase(intervals.begin() + first + 1 , intervals.begin() + last + 1);
        } 
        return intervals;
    }

    bool isOverlapping(vector<int> i1, vector<int> i2) {
        if (i1.at(0) == i2.at(0) || i1.at(0) == i2.at(1) || i2.at(0) == i1.at(1) || i1.at(1) == i2.at(1)) return true;
        if (i1.at(0) > i2.at(0) && i1.at(0) < i2.at(1)) return true;
        if (i1.at(0) < i2.at(0) && i1.at(1) > i2.at(0)) return true;
        if (i1.at(0) < i2.at(0) && i1.at(1) > i2.at(1)) return true;
        if (i1.at(0) > i2.at(0) && i1.at(1) < i2.at(1)) return true;
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
    vector<vector<int>> intervals{{2,4},{5,7},{8,10},{11,13}};
    vector<int> newInterval{3,6};
    printf("Inputs:\n\tIntervals: [");
    for(vector<int> x: intervals) {
        printf("[%d, %d], ", x.at(0), x.at(1));
    }
    printf("]\n");
    printf("\tNew Interval: [%d, %d]\n", newInterval.at(0), newInterval.at(1));
    Solution sol = Solution();
    printf("isOverlapping(): %d\n", sol.isOverlapping(newInterval, intervals.at(0)));
    vector<vector<int>> result = sol.insert(intervals, newInterval);
    printf("Results:\n\t[");
    for(vector<int> x: result){
        printf("[%d, %d], ", x.at(0),x.at(1));
    }
    printf("]\n");
    return 0;
}