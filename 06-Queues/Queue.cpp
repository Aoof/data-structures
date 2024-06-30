#include <iostream>

using namespace std;

class Queue {
    private:
        struct Node {
            int value;
            Node* next;
            Node(int value) {
                this->value = value;
                next = nullptr;
            }
        };
        Node* first;
        Node* last;
        int length;
    public:
        Queue(int value) {
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        void printQueue() {
            Node* current = first;
            while (current) {
                cout << current->value << endl << "↓" << endl;
                current = current->next;
            }
        }

        void getLength() {
            cout << "Length: " << this->length << endl;
        }

        void getFirst() {
            cout << "First: " << this->first->value << endl;
        }

        void getLast() {
            cout << "Last: " << this->last->value << endl;
        }

        void enqueue(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                first = newNode;
                last = newNode;
            } else {
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        int dequeue() {
            if (length == 0) return INT_MIN;
            Node* temp = first;
            int cachedVal = first->value;
            if (length == 1) {
                first = nullptr;
                last = nullptr;
            } else {
                first = first->next;
                delete temp;
            }
            length--;
            return cachedVal;
        }
};

int main() {
    Queue* myQueue = new Queue(2);
    myQueue->enqueue(12);

    return 0;
}