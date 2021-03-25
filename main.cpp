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
        if (head == nullptr)
            return head;
        auto *h = new ListNode(-1, head);
        ListNode *p = h;
        while (p->next && p->next->next) {
            if (p->next->val == p->next->next->val) {
                int val = p->next->val;
                while (p->next && p->next->val == val)
                    p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return h->next;
    }
};

int main() {
    Solution solution;

    return 0;
}

