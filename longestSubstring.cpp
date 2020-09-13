#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
    bool contains(string s, char c){
        return s.find(c) != string::npos;
    }

    int lengthOfLongestSubstring(string s) {
        string comparand = "";
        int longest = 0;
        for (int i = 0; i < s.length(); i++) {
            comparand += s[i];
            for (int j = i+1; j < s.length(); j++) {

                if (contains(comparand, s[j])) {
                    if (comparand.length() > longest) longest = comparand.length();
                    comparand = "";
                    break;
                } else {
                    comparand += s[j];
                }   
            }
            if (comparand.length() > longest) longest = comparand.length();
            comparand = "";
        }
        return longest;
    }
};

int main(){
    string testCase1 = "aaaaaa";
    Solution solution = Solution();
    printf("%d\n",solution.lengthOfLongestSubstring(testCase1));
    return 0;
}
