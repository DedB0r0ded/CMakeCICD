#ifndef LIST_H
#define LIST_H

template <typename T>
class Node {
public:
    Node* m_next;
    T m_data;

    Node(T data = T(), Node* next = nullptr) : m_data(data), m_next(next) {}

    ~Node() {
      if(m_next)
        delete m_next;
    }
};

template <typename T>
class List {
public:
    bool empty() const;
    void push_back(T);
    T* pop_back();
    int size() const;
    T& operator[](int id);
    T at(int id);

    List();
    ~List();

private:
    Node<T>* m_head;
    int m_size;

    void deleteLast();
    Node<T>* get(int id);
};


template<typename T>
bool List<T>::empty() const {
  return m_size == 0;
}

template<typename T>
void List<T>::push_back(T data) {
  Node<T>* newNode = new Node<T>(data);

  if (m_head == nullptr)
    m_head = newNode;
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
inline T* List<T>::pop_back()
{
  T* ret = nullptr;

  switch (m_size) {
  case 0:
    return ret;
  case 1:
    *ret = m_head->m_data;
    break;
  default:
    *ret = at(m_size - 1);
    break;
  }  

  deleteLast();
  return ret;
}

template<typename T>
int List<T>::size() const {
  return m_size;
}

template<typename T>
T List<T>::at(int id) {
  return get(id)->m_data;
}

template<typename T>
T& List<T>::operator[](int id) {
  return get(id)->m_data;
}

template<typename T>
List<T>::List() : m_head(nullptr), m_size(0) {}

template<typename T>
List<T>::~List() {
  delete m_head;
}

template<typename T>
inline void List<T>::deleteLast()
{
  if (empty())
    return; // TODO: exception

  if (m_size == 1) {
    delete m_head;
    m_head = nullptr;
  }
  else {
    Node<T>* newLast = get(m_size - 1);
    Node<T>* last = newLast->m_next;
    delete last;
    newLast = nullptr;
  }

  m_size--;
  
}

template<typename T>
Node<T>* List<T>::get(int id) {
  if (id < 0 || id >= m_size) {
    return nullptr;
  }
  Node<T>* current = m_head;
  for (int i = 0; i < id; ++i) {
    current = current->m_next;
  }
  return current;
}



#endif // LIST_H
