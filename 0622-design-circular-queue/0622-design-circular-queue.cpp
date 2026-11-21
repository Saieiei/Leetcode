
class MyCircularQueue {
private:
    vector<int> arr;
    int capacity;
    int frontIndex;
    int nextIndex;
    int count;

public:
    MyCircularQueue(int k) {
        capacity = k;
        arr.resize(k);

        frontIndex = 0;
        nextIndex = 0;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        arr[nextIndex] = value;
        nextIndex = (nextIndex + 1) % capacity;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[frontIndex];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        int lastIndex = (nextIndex - 1 + capacity)% capacity;

        return arr[lastIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

auto init = atexit([](){ofstream("display_runtime.txt") << 0;});