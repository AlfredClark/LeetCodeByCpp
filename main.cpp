#include <bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    /** In stack & Out stack **/
    stack<int> in_stack, out_stack;

    /** Convert input stack to output stack **/
    void in_to_out() {
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        in_stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out_stack.empty())
            in_to_out();
        int ele = out_stack.top();
        out_stack.pop();
        return ele;
    }

    /** Get the front element. */
    int peek() {
        if (out_stack.empty())
            in_to_out();
        return out_stack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

int main() {

    return 0;
}