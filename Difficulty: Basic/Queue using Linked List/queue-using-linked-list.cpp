class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
public:
    Node* front;
    Node* rear;
    int sz;

    myQueue() {
        front = rear = NULL;
        sz = 0;
    }

    bool isEmpty() {
        return sz == 0;
    }

    void enqueue(int x) {
        Node* newN = new Node(x);

        if(front == NULL) {
            front = rear = newN;
        }
        else {
            rear->next = newN;
            rear = newN;
        }

        sz++;
    }

    void dequeue() {
        if(isEmpty()) return;

        Node* temp = front;
        front = front->next;
        delete temp;
        sz--;

        if(front == NULL) {
            rear = NULL;
        }
    }

    int getFront() {
        if(isEmpty()) return -1;
        return front->data;
    }

    int getRear() {
        if(isEmpty()) return -1;
        return rear->data;
    }

    int size() {
        return sz;
    }
};
