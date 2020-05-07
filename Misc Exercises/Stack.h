#include "List_Node.h"
#include <iostream>

template<class T>
class Stack {
    List_Node<T>* head; 
    int curr_size;

public:
    Stack() : head{nullptr}, curr_size{0} {}

    ~Stack() {
        while(head != nullptr) {
            List_Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
    }

    T top() {
        return head->data;
    }

    void push(T data) {
        List_Node<T>* temp = new List_Node<T>(data);
        temp->next = head;
        head = temp;
        curr_size++; 
    }

    T pop() {
        if(curr_size > 0) {
            List_Node<T>* temp = head;
            T data = head->data;
            head = head->next;
            delete temp;
            curr_size--;            
        }

        return 0;
    }

    int size() {
        return curr_size;
    }

    void print() {
        List_Node<T>* curr_node = head;

        std::cout << "Stack Nodes: "; 
        while(curr_node != nullptr) {
            std::cout << curr_node->data << " ";
            curr_node = curr_node->next;
        }
        std::cout << std::endl;
    }

};