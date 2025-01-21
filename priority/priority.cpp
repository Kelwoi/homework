#include <iostream>
using namespace std;

struct PriorityQueueElement {
    int value;
    int priority;

    PriorityQueueElement(int v = 0, int p = 0) : value(v), priority(p) {}
};

class PriorityQueue {
private:
    PriorityQueueElement* queue;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) : capacity(cap), size(0) {
        queue = new PriorityQueueElement[capacity];
    }

    ~PriorityQueue() {
        delete[] queue;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return size == capacity;
    }

    void InsertWithPriority(int value, int priority) {
        if (IsFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        int i;
        
        for (i = size - 1; i >= 0; i--) {
            if (queue[i].priority < priority) {
                queue[i + 1] = queue[i];
            }
            else {
                break;
            }
        }

        queue[i + 1] = PriorityQueueElement(value, priority);
        size++;
    }

    PriorityQueueElement PullHighestPriorityElement() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return PriorityQueueElement();
        }

        PriorityQueueElement highest = queue[0];
        for (int i = 1; i < size; i++) {
            queue[i - 1] = queue[i];
        }
        size--;
        return highest;
    }

    PriorityQueueElement Peek() const {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return PriorityQueueElement();
        }
        return queue[0];
    }

    void Show() const {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << "Value: " << queue[i].value << ", Priority: " << queue[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue queue(5);

    queue.InsertWithPriority(10, 1);
    queue.InsertWithPriority(20, 3);
    queue.InsertWithPriority(30, 2);

    cout << "Queue after:" << endl;
    queue.Show();

    cout << "\nPeek:" << endl;
    PriorityQueueElement peek = queue.Peek();
    if (peek.priority != 0 || peek.value != 0) {
        cout << "Value: " << peek.value << ", Priority: " << peek.priority << endl;
    }

    cout << "\nDelete highest priority:" << endl;
    PriorityQueueElement highest = queue.PullHighestPriorityElement();
    if (highest.priority != 0 || highest.value != 0) {
        cout << "Value: " << highest.value << ", Priority: " << highest.priority << endl;
    }

    cout << "\nQueue after delete:" << endl;
    queue.Show();

    return 0;
}
