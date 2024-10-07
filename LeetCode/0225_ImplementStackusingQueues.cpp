// LeetCode 0225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/
// using one queue

#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> stack;

public:
    MyStack() {
    }

    void push(int x) {
        stack.push(x);

        for (int i = 1; i < stack.size(); ++i)
        {
            stack.push(stack.front());
            stack.pop();
        }
    }

    int pop() {
        int top = stack.front();
        stack.pop();
        return top;
    }

    int top() {
        return stack.front();
    }

    bool empty() {
        return stack.empty();
    }
};