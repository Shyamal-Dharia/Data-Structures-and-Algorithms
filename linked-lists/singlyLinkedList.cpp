// Big thanks! Implemented by following this video https://www.youtube.com/watch?v=q8gdBn9RPeI&list=PLDzeHZWIZsTr54_TH_NK4ibFojS4mmQA6

#include<iostream>
using namespace std;

// Class Node for creating a node
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // Destructor to free memory
    ~Node() {
        // Output a message when memory is freed
        cout << "Memory is freed for node with data: " << data << endl;
        if (this->next != nullptr) {
            delete next;
            this->next = nullptr;
        }
    }
};

// Function to insert a new node at the head of the linked list
void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data); // Create a new node with the given data
    newNode->next = head; // Set the new node's next to the current head
    head = newNode; // Update the head to point to the new node
}

// Function to insert a new node at the tail of the linked list
void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data); // Create a new node with the given data
    if (tail == nullptr) {
        tail = newNode; // If the list is empty, set the tail to the new node
    } else {
        tail->next = newNode; // Set the current tail's next to the new node
        tail = newNode; // Update the tail to point to the new node
    }
}

// Function to insert a new node at a specified position in the linked list
void InsertAtPosition(Node* &head, Node* &tail, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data); // Insert at the head if position is 1
        if (tail == nullptr) {
            tail = head; // Update the tail if it was null
        }
        return;
    }
    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp != nullptr) {
        temp = temp->next; // Traverse the list to the (position-1)th node
        count++;
    }
    if (temp == nullptr) {
        // Position is beyond the current size, insert at the tail
        insertAtTail(tail, data);
    } else {
        Node* newNode = new Node(data); // Create a new node with the given data
        newNode->next = temp->next; // Set the new node's next to the next of the (position-1)th node
        temp->next = newNode; // Update the (position-1)th node's next to the new node
        if (temp == tail) {
            tail = newNode; // Update the tail if adding at the end
        }
    }
}

// Function to delete a node at a specified position in the linked list
void deleteNode(int position, Node* &head, Node* &tail) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        if (head == nullptr) {
            tail = nullptr; // If the list is empty, update the tail as well
        }
    } else {
        Node* curr = head;
        Node* prev = nullptr;
        int count = 1;
        while (count < position && curr != nullptr) {
            prev = curr;
            curr = curr->next; // Traverse to the node to be deleted
            count++;
        }
        if (curr != nullptr) {
            prev->next = curr->next; // Update the previous node's next to skip the deleted node
            curr->next = nullptr;
            delete curr; // Delete the node to be deleted
            if (prev->next == nullptr) {
                tail = prev; // Update tail if the last node was deleted
            }
        }
    }
}

// Function to print the elements of the linked list
void print(Node* &head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a new node
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    InsertAtPosition(head, tail, 4, 22);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(4, head, tail);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    // Clean up memory by deleting all nodes
    delete head;

    return 0;
}
