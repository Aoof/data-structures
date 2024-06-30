#include <iostream>

using namespace std;

class Stack {
    private:
        struct Node {
            Node* next;
            int value;
            Node (int value) {
                this->value = value;
                this->next = nullptr;
            }
        };
        Node* top;
        int height;
    public:
        // Constructor
        Stack(int val) {
            Node* newNode = new Node(val);
            top = newNode;
            height = 1;
        }

        void printStack() {
            Node* current = top;
            while (current) {
                cout << current->value << endl << "↓" << endl;
                current = current->next;
            }
        }

        void getHeight() {
            cout << "Height: " << this->height << endl;
        }

        void getTop() {
            cout << "Top: " << this->top->value << endl;
        }

        // /Constructor

        void push(int value) {
            Node* newNode = new Node(value);

            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop() {
            if (height == 0) return INT_MIN;
            Node* temp = top;
            int val = temp->value;
            top = top->next;
            delete(temp);
            height--;

            return val;
        }
};

int main () {
    Stack* myStack = new Stack(2);
    myStack->push(3);
    myStack->printStack();
    return 0;
}