#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& top, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void splitList(Node* head, stack<int>& negatives, stack<int>& positives) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data < 0)
            negatives.push(temp->data);
        else
            positives.push(temp->data);
        temp = temp->next;
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    Node* head = nullptr;
    int value;
    while (inputFile >> value) {
        push(head, value);
    }
    inputFile.close();

    stack<int> negatives;
    stack<int> positives;

    splitList(head, negatives, positives);

    while (!negatives.empty()) {
        outputFile << negatives.top() << " ";
        negatives.pop();
    }
    while (!positives.empty()) {
        outputFile << positives.top() << " ";
        positives.pop();
    }
    outputFile << endl;

    outputFile.close();

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
