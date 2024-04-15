#ifndef LIST_H
#define LIST_H

template <typename T>
class Node {
public:
    Node* m_next;
    T m_data;

    Node(T data = T(), Node* next = nullptr) : m_data(data), m_next(next) {}

    ~Node() {
        delete m_next;
    }
};

template <typename T>
class List {
public:
    bool empty() const;
    void push_back(T);
    int size() const;
    T& operator[](int id);

    List();
    ~List();

private:
    Node<T>* m_head;
    int m_size;

    Node<T>* at(int id);
};

#endif // LIST_H

#include "List.cpp" // Include the implementation file here
