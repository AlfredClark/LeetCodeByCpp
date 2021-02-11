#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<>> pq;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int num: nums)
            pq.push(num);
        while (pq.size() > k)
            pq.pop();
    }

    int add(int val) {
        if (pq.size() < k)
            pq.push(val);
        else if (val > pq.top()) {
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    int k = 3;
    int num[] = {};
    int test[] = {3, 5, 10, 9, 4};
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    auto *obj = new KthLargest(k, nums);
    for (int i : test) {
        cout << obj->add(i) << " ";
    }
    return 0;
}
