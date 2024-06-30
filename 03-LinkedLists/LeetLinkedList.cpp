#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }
        
        void partitionList(int x) {
            if (length == 0 || length == 1) return;
            
            Node* left = head;
            Node* right = head;
            Node* temp = left;
            
            while (left != nullptr) {
                while (left != nullptr && left->value < x) left = left->next;
                right = left;
                while (right != nullptr && right->value > x) right = right->next;
                temp = right;

                if (!right || !left || right == left) return;

                right->value = left->value;
                left->value = temp->value;
            }
        }
        
        void removeDuplicates() {
            Node* current = head;
            Node* runner = head;
            
            while (current) {
                runner = current;
                while (runner->next) {
                    if (runner->next->value == current->value) {
                        Node* temp = runner->next;
                        runner->next = runner->next->next;
                        delete temp;
                        length--;
                    }
                    runner = runner->next;
                }

                current = current->next;
            }
        }
};


int main () {
    cout << "\n------ Test: RemoveDuplicatesHasDuplicates ------\n";
    
    LinkedList list(1);
    list.append(2);
    list.append(2);
    list.append(3);
    
    cout << "BEFORE:    ";
    list.printList();
    
    list.removeDuplicates();
    
    cout << "AFTER:     ";
    list.printList();
    
    // Check for duplicates
    Node* current = list.getHead();
    bool noDuplicates = true;
    
    while (current && current->next) {
        if (current->value == current->next->value) {
            noDuplicates = false;
            break;
        }
        current = current->next;
    }
    return 0;
}
