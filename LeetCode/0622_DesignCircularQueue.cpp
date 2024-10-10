// LeetCode 0622. Design Circular Queue
// https://leetcode.com/problems/design-circular-queue/

#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> q;
    int front;
    int rear;

public:
    MyCircularQueue(int k) {
        q.resize(k, -1);
        front = 0;  // ptr head
        rear = 0;   // ptr after tail
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        q[rear] = value;
        rear = (rear + 1) % q.size();
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        q[front] = -1;
        front = (front + 1) % q.size();
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        int Idx = rear - 1;
        if (Idx < 0)
            Idx += q.size();
        return q[Idx];
    }

    bool isEmpty() {
        if (rear == front && q[front] == -1)
            return true;
        return false;
    }

    bool isFull() {
        if (rear == front && q[front] != -1)
            return true;
        return false;
    }
};