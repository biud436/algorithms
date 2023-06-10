#include <iostream>
#include <string>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
    ~Node() {
        delete next;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;
    int size;
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    void push(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        ++size;
    }

    int pop() {
        if (head == nullptr) {
            return -1;
        } else {
            int data = head->data;
            Node* node = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            node->next = nullptr;
            delete node;
            --size;
            return data;
        }
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getFront() {
        if (head == nullptr) {
            return -1;
        } else {
            return head->data;
        }
    }

    int getBack() {
        if (tail == nullptr) {
            return -1;
        } else {
            return tail->data;
        }
    }

    ~Queue() {
        delete head;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    Queue queue;

    for (int i = 0; i < n; ++i) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push") {
            int num;
            std::cin >> num;

            queue.push(num);
        } else if (cmd == "pop") {
            int num = queue.pop();

            std::cout << num << '\n';
        } else if (cmd == "size") {
            int size = queue.getSize();

            std::cout << size << '\n';
        } else if (cmd == "empty") {
            bool empty = queue.isEmpty();

            std::cout << empty << '\n';
        } else if (cmd == "front") {
            int front = queue.getFront();

            std::cout << front << '\n';
        } else if (cmd == "back") {
            int back = queue.getBack();

            std::cout << back << '\n';
        }
    }

    return 0;
}