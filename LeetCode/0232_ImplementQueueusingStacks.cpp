// LeetCode 0232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/
// using two stack
// each operation Time Complexity : O(1)

#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {
    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        peek();
        int pop = output.top();
        output.pop();
        return pop;
    }

    int peek() {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};