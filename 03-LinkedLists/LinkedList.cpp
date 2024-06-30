#include <iostream>

using namespace std;

class LinkedList {
    private:
        struct Node {
            int value;
            Node* next;
            public:
                Node(int val) {
                    value = val;
                    next = nullptr;
                }
        };

        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList(int* params, int size) {
            Node* tempNode = new Node(params[0]);

            head = tempNode;

            for (int i = 1; i < size; i++) {
                tempNode->next = new Node(params[i]);
                tempNode = tempNode->next;
            }

            tail = tempNode;
            length = size;
        };

        Node* get(int index) {
            Node* curr = head;
            for (int i = 0; i < index; i++) curr = curr->next;
            return curr;
        }

        bool set(int index, int value) {
            if (index < 0 || index >= length) return false;
            
            Node* temp = get(index);

            if (!temp) return false;

            temp->value = value;
            return true;
        }

        void print_list() {
            Node* curr = head;
            printf("H(%d) [", head->value);
            for (int i = 0; i < length; i++) {
                printf(" %d ->", curr->value);
                curr = curr->next;
            }
            printf(" ] T(%d)\n", tail->value);
        }

        void append(int value) {
            Node* newNode = new Node(value);
            tail->next = newNode;
            tail = newNode;
            length++;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            length++;
        }

        bool insert(int index, int value) {
            if (index < 0 || index > length) return false;

            if (index == 0) {
                prepend(value);
                return true;
            } else if (index == length) {
                append(value);
                return true;
            }

            Node* pre = get(index-1);
            Node* newNode = new Node(value);

            newNode->next = pre->next;
            pre->next = newNode;

            length++;

            return true;
        }

        void deleteFirst() {
            if (length == 0) return;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
                length--;
                return;
            }

            Node* temp = head;
            head = head->next;
            delete temp;

            length--;
        }

        void deleteLast() {
            if (length == 0) return;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
                length--;
                return;
            }

            Node* temp = get(length-1);
            tail = temp;
            delete temp->next;
            temp->next = nullptr;

            length--;
        }

        bool remove(int index) {
            if (index < 0 || index >= length) return false;
            if (index == 0) {
                deleteFirst();
                return true;
            } else if (index == length-1) {
                deleteLast();
                return true;
            }

            Node* pre = get(index-1);
            Node* temp = pre->next;
            pre->next = pre->next->next;

            delete temp;
            length--;
            return true;
        }

        void reverse() {
            Node* temp = head;
            head = tail;
            tail = temp;

            Node* after = nullptr;
            Node* before = nullptr;

            while (temp) {
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
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
        
        void reverseBetween(int m, int n) {
            // 1. Initial Check:
            // If the list is empty, there's nothing to reverse.
            // So, exit the function without doing anything.
            if (head == nullptr) return;
        
            // 2. Dummy Node Creation:
            // We initiate a new 'dummy' node with value 0.
            // This is a trick to simplify the edge cases.
            Node* dummy = new Node(0);
        
            // Connect our actual list right after the dummy node.
            // So, the dummy node temporarily stands before the head.
            dummy->next = head;
        
            // 3. Positioning 'prev':
            // Start with 'prev' pointing to the dummy node.
            Node* prev = dummy;
        
            // Move 'prev' up to the node just before the starting
            // point of the section we want to reverse.
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }
        
            // 4. Setting up 'current':
            // 'current' is set right after 'prev'.
            // It marks the start of the section to be reversed.
            Node* current = prev->next;
        
            // 5. Main Reversal Logic:
            // We now enter our core reversal loop.
            for (int i = 0; i < n - m; i++) {
                // 'temp' points to the node that's next in line
                // for our reversal process.
                Node* temp = current->next;
        
                // Detach 'temp' from the current sequence by
                // making 'current' skip over 'temp'.
                current->next = temp->next;
        
                // To move 'temp' to the start of our reversed section,
                // we first let 'temp' point to whatever node 'prev' is pointing to.
                temp->next = prev->next;
        
                // Finally, we adjust 'prev' to point to 'temp', thereby
                // moving 'temp' to the front of the reversed section.
                prev->next = temp;
            }
        
            // 6. Updating Head:
            // If our reversed section included the original head of the list,
            // our list's head would have changed. 
            // So, we need to update the head of our list.
            head = dummy->next;
        
            // 7. Cleanup:
            // The dummy node has served its purpose.
            // We free up its memory to avoid memory leaks.
            delete dummy;
        }


        void getLength() {
            printf("Length: %d\n", length);
        }
};

int main() {
    int _arr[10] = { 12, 23, 24, 1, 2, 3, 4, 19, 12, 12 };
    LinkedList* arr = new LinkedList(_arr, 10);

    arr->print_list();

    arr->reverseBetween(1, 5);
    arr->removeDuplicates();

    arr->print_list();

    return 0;
}