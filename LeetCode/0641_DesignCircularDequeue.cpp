// LeetCode 0641. Design Circular Deque
// https://leetcode.com/problems/design-circular-deque/

#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> q;
    int front;
    int count;

public:
    MyCircularDeque(int k) {
        q.resize(k, -1);
        front = 0;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        front = front - 1;
        if (front < 0)
            front += q.size();

        q[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        int Idx = (front + count) % q.size();
        q[Idx] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        q[front] = -1;
        front = (front + 1) % q.size();
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        int Idx = (front + count - 1) % q.size();
        q[Idx] = -1;
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return q[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        int Idx = (front + count - 1) % q.size();
        return q[Idx];
    }

    bool isEmpty() {
        if (count == 0)
            return true;
        return false;
    }

    bool isFull() {
        if (count >= q.size())
            return true;
        return false;
    }
};