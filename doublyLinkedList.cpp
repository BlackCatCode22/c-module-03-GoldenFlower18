#include <iostream>
using namespace std;

// Upgraded Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;    // New pointer to previous node
    
    // Constructor to initialize node
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;    // Added tail pointer for efficient insertion at end
    
public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    // Insert node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        // If list is empty
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        
        // Add new node at the end
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    
    // Delete node by value
    void deleteNode(int value) {
        // If list is empty
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        
        // Search for the node to delete
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        
        // If value not found
        if (temp == nullptr) {
            cout << "Value " << value << " not found in the list\n";
            return;
        }
        
        // If node to delete is head
        if (temp == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;  // List becomes empty
            }
        }
        // If node to delete is tail
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // If node to delete is in the middle
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        
        delete temp;
    }
    
    // Display all nodes forward
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
    
    // Display all nodes backward
    void displayBackward() {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = tail;
        cout << "Backward: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "nullptr\n";
    }
    
    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Main function to test the implementation
int main() {
    DoublyLinkedList list;
    
    // Insert some nodes
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    
    cout << "Original list:\n";
    list.displayForward();
    list.displayBackward();
    
    // Delete a node
    list.deleteNode(20);
    cout << "\nAfter deleting 20:\n";
    list.displayForward();
    list.displayBackward();
    
    // Try to delete a non-existent value
    list.deleteNode(25);
    
    // Insert more nodes
    list.insertAtEnd(50);
    cout << "\nAfter inserting 50:\n";
    list.displayForward();
    list.displayBackward();
    
    return 0;
}