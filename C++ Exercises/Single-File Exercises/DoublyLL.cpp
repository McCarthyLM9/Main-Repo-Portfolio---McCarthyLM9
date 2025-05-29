#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool remove(int val) {
        if (!head) return false;

        Node* curr = head;

        while (curr && curr->data != val) {
            curr = curr->next;
        }

        if (!curr) return false;

        if (curr == head) {
            head = curr->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } 
        else if (curr == tail) {
            tail = curr->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
        } 
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
        return true;
    }


    Node* getHead() const {
        return head;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void print() const {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void clear() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
        head = tail = nullptr;
    }

    ~LinkedList() {
        clear();
    }
};



int main() {
    vector<LinkedList> lists;

    
}