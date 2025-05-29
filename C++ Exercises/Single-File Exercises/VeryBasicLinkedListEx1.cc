#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* one = nullptr;
    Node* two = nullptr;
    Node* three = nullptr;

    one = new Node;
    two = new Node;
    three = new Node;

    one->data = 15;
    two->data = 22;
    three->data = 19;

    one->next = two;
    two->next = three;
    three->next = nullptr;

    cout << one->data << endl;
    cout << one->next->data << endl;
    cout << one->next->next->data << endl;

    return 0;
}