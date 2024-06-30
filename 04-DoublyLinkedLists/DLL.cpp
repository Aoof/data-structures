#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* prev;
        Node* next;
        Node(int value) {
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        };
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        DoublyLinkedList(int values[], int size) {
            length = size;
            Node* temp = new Node(values[0]);

            head = temp;

            for (int i = 1; i < size; i++) {
                Node* newNode = new Node(values[i]);
                temp->next = newNode;
                newNode->prev = temp;
                temp = newNode;
            }

            tail = temp;
        }

        void printList() {
            Node* curr = head;
            printf("H(%d) [", head->value);
            while (curr) {
                printf((curr->next) ? " %d ->" : " %d", curr->value);
                curr = curr->next;
            }
            printf(" ] T(%d)\n", tail->value);
        }

        Node* get(int index) {
            if (index < 0 || index >= length) return nullptr;
            Node* current = head;
            for (int i = 0; i < index; i++) current = current->next;
            return current;
        }

        bool set(int index, int value) {
            if (index < 0 || index >= length) return false;
            Node* current = get(index);
            if (!current) return false;

            current->value = value;
            return true;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        bool insert(int index, int value) {
            if (index < 0 || index > length) return false;
            if (index == 0) {
                prepend(value);
                return true;
            }

            if (index == length) {
                append(value);
                return true;
            }

            Node* current = get(index);
            if (!current) return false;


            Node* newNode = new Node(value);
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;

            length++;
            
            return true;
        }

        void deleteFirst() {
            if (length == 0) return;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }

        void deleteLast() {
            if (length == 0) return;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }

        bool remove(int index) {
            if (length == 0 || index < 0 || index >= length) return false;
            if (length == 1) {
                Node* temp = head;
                head = nullptr;
                tail = nullptr;
                delete temp;
                return true;
            }

            Node* current = get(index);
            if (!current) return false;

            current->next->prev = current->prev;
            current->prev->next = current->next;

            delete current;
            return true;
        }

        void reverse() {
            if (length == 0 || length == 1) return;

            Node* temp = head;
            head = tail;
            tail = temp;

            while (temp) {
                Node* oldNext = temp->next;
                temp->next = temp->prev;
                temp->prev = oldNext;
                temp = oldNext;
            }
        }
};

int main() {
    int _arr[1] = {2};
    DoublyLinkedList* myDLL = new DoublyLinkedList(_arr, 1);
    // Test out the insertion commands
    myDLL->append(4);
    myDLL->prepend(1);
    myDLL->insert(2, 3);
    myDLL->reverse();
    myDLL->set(2, 5);
    myDLL->printList();
    return 0;
}