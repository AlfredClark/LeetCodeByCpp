#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        int val = head->val;
        ListNode *p = head;
        while (p->next) {
            if (p->next->val == val) {
                ListNode *d = p->next;
                p->next = p->next->next;
                delete (d);
            } else {
                val = p->next->val;
                p = p->next;
            }
        }
        return head;
    }
};

int main() {
    Solution solution;

    return 0;
}

