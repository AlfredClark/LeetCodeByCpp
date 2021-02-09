#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        vector<short> count1(26, 0);
        vector<short> count2(26, 0);
        for (char s: s1)
            count1[s - 'a']++;
        int len = s1.length();
        for (int i = 0; i < len; ++i)
            count2[s2[i] - 'a']++;
        if (count1 == count2)
            return true;
        for (int i = len; i < s2.length(); ++i) {
            count2[s2[i] - 'a']++;
            count2[s2[i - len] - 'a']--;
            if (count1 == count2)
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s1 = "ooabo";
    string s2 = "eidbaooo";
    cout << solution.checkInclusion(s1, s2);
    return 0;
}
