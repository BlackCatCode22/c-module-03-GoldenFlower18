#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }
    
    // Insert node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        // If list is empty
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        // Traverse to last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        // Add new node at the end
        temp->next = newNode;
    }
    
    // Delete node by value
    void deleteNode(int value) {
        // If list is empty
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        // If head node has the value
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        // Search for the node to delete
        Node* temp = head;
        Node* prev = nullptr;
        
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        
        // If value not found
        if (temp == nullptr) {
            cout << "Value " << value << " not found in the list\n";
            return;
        }
        
        // Delete the node
        prev->next = temp->next;
        delete temp;
    }
    
    // Display all nodes
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
    
    // Destructor to free memory
    ~LinkedList() {
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
    LinkedList list;
    
    // Insert some nodes
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    
    cout << "Original list: ";
    list.display();
    
    // Delete a node
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();
    
    // Try to delete a non-existent value
    list.deleteNode(25);
    
    // Insert more nodes
    list.insertAtEnd(50);
    cout << "After inserting 50: ";
    list.display();
    
    return 0;
}