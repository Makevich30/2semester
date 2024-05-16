#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

// Односвязный список узлов
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Класс для работы со списком
class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void doubleEven() {
        Node* current = head;
        while (current != nullptr) {
            if (current->data % 2 == 0) {
                Node* newNode = new Node(current->data * 2);
                newNode->next = current->next;
                current->next = newNode;
                current = newNode->next;
            } else {
                current = current->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Класс для работы с двусвязным списком
class DoubleLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int d) : data(d), prev(nullptr), next(nullptr) {}
    };
    Node* head;

public:
    DoubleLinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void doubleEven() {
        Node* current = head;
        while (current != nullptr) {
            if (current->data % 2 == 0) {
                Node* newNode = new Node(current->data * 2);
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                current = newNode->next;
            } else {
                current = current->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    List list;
    DoubleLinkedList doubleList;
    stack<int> stackData;
    queue<int> queueData;

    int num;
    while (inputFile >> num) {
        list.insert(num);
        doubleList.insert(num);
        stackData.push(num);
        queueData.push(num);
    }
    inputFile.close();

    list.doubleEven();
    doubleList.doubleEven();

    cout << "List with stack:" << endl;
    while (!stackData.empty()) {
        int data = stackData.top();
        stackData.pop();
        cout << data << " ";
    }
    cout << endl;

    cout << "List with queue:" << endl;
    while (!queueData.empty()) {
        int data = queueData.front();
        queueData.pop();
        cout << data << " ";
    }
    cout << endl;

    cout << "List with single linked list:" << endl;
    list.display();

    doubleList.display();

    return 0;
}
