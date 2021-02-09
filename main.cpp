#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int len=A.size(), size=0;
        vector<int> counter(len + 1);
        int dp=1;
        int last=0, res=0;
        for(int i:A) {
            size+=counter[i]++>0?0:1;
            if(size>K) {
                counter[A[last++]]=0;
                size--;
                dp=1;
            }
            if(size==K) {
                while(counter[A[last]]>1) {
                    counter[A[last++]]--;
                    dp++;
                }
                res+=dp;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    int nums[] = {1, 2, 3, 2, 1};
    vector<int> A(nums, nums + sizeof(nums) / sizeof (int));
    cout << solution.subarraysWithKDistinct(A, 2);
    return 0;
}
