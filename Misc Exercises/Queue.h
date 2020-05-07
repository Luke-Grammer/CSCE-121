#include "List_Node.h"
#include <iostream>

template <class T>
class Queue {
    List_Node<T>* head;
    List_Node<T>* tail;
    int curr_size;

public:
    Queue() : head{nullptr}, tail{nullptr}, curr_size{0} {}
    ~Queue() {
        List_Node<T>* temp = head;
        while(head != nullptr) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    void enqueue(T data) {
        List_Node<T>* temp = new List_Node<T>(data);

        if (tail == nullptr) {
            head = tail = temp;
            curr_size++;
            return;
        }

        temp->next = tail;
        tail->prev = temp;
        tail = temp;
        curr_size++;
    }

    T deque() {
        if (curr_size > 0) {
            T data = head->data;
            List_Node<T>* temp = head;
            delete head;            
            head = temp->prev;
            curr_size--;
            return data;
        }
        else return 0;
    }

    T front() {
        return head->data;
    }

    int size() {
        return curr_size;
    }

    void print() {
        List_Node<T>* curr_node = head;

        std::cout << "Queue Nodes: "; 
        while(curr_node != nullptr) {
            std::cout << curr_node->data << " ";
            curr_node = curr_node->prev;
        }
        std::cout << std::endl;
    }
};