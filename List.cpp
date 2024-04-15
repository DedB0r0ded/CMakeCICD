#pragma once
#include "List.h"

template<typename T>
bool List<T>::empty() const {
    return m_size == 0;
}

template<typename T>
void List<T>::push_back(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (m_head == nullptr) {
        m_head = newNode;
    }
    else {
        Node<T>* current = m_head;
        while (current->m_next != nullptr) {
            current = current->m_next;
        }
        current->m_next = newNode;
    }
    m_size++;
}

template<typename T>
int List<T>::size() const {
    return m_size;
}

template<typename T>
T& List<T>::operator[](int id) {
    return at(id)->m_data;
}

template<typename T>
List<T>::List() : m_head(nullptr), m_size(0) {}

template<typename T>
List<T>::~List() {
    delete m_head;
}

template<typename T>
Node<T>* List<T>::at(int id) {
    if (id < 0 || id >= m_size) {
        return nullptr;
    }
    Node<T>* current = m_head;
    for (int i = 0; i < id; ++i) {
        current = current->m_next;
    }
    return current;
}
