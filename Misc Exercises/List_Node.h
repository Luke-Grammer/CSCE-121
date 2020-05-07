
template <class T>
struct List_Node {
    List_Node* next;
    List_Node* prev;
    T data;

    List_Node(T data) : data{data}, next{nullptr}, prev{nullptr} {
        
    }
};