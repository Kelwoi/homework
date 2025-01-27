#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
struct Node
{
    T data;
    Node* next, * prev;
    Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
        :data(data), prev(prev), next(next)
    {}
};

template<typename T>
class List
{
public:
    List() = default;
    ~List();
    void addHead(const T& data);
    void removeHead();
    void print() const;
    void printR() const;
    bool empty() const;
    void removeByData(const T& data);


    void insertAt(const T& data, size_t position);
    void removeAt(size_t position);
    size_t findElement(const T& data) const;
    int searchAndReplace(const T& search, const T& replace);
    void reverse();

private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t size = 0;

    Node<T>* findNode(const T& data);
};

template<typename T>
List<T>::~List()
{
    while (!empty())
        removeHead();
}

template<typename T>
inline void List<T>::addHead(const T& data)
{
    auto tmp = new Node<T>(data, nullptr, head);
    if (empty())
        tail = tmp;
    if (!empty())
        head->prev = tmp;
    head = tmp;
    ++size;
}

template<typename T>
inline void List<T>::removeHead()
{
    if (empty())
        return;
    auto tmp = head;
    head = head->next;
    delete tmp;
    if (empty())
        tail = nullptr;
    else
        head->prev = nullptr;
    --size;
}

template<typename T>
inline void List<T>::print() const
{
    if (empty())
    {
        cout << "List is empty" << endl;
        return;
    }
    auto tmp = head;
    cout << "List :: \t";
    while (tmp != nullptr)
    {
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }
    cout << endl;
}

template<typename T>
inline void List<T>::printR() const
{
    if (empty())
    {
        cout << "List is empty" << endl;
        return;
    }
    auto tmp = tail;
    cout << "List :: \t";
    while (tmp != nullptr)
    {
        cout << tmp->data << "\t";
        tmp = tmp->prev;
    }
    cout << endl;
}

template<typename T>
inline bool List<T>::empty() const
{
    return head == nullptr;
}

template<typename T>
inline void List<T>::removeByData(const T& data)
{
    auto find = findNode(data);
    if (find == nullptr)
        return;
    if (find == head)
    {
        removeHead();
        return;
    }
    if (find == tail)
    {
       
        tail = tail->prev;
        tail->next = nullptr;
        delete find;
        --size;
        return;
    }
    find->prev->next = find->next;
    find->next->prev = find->prev;

    delete find;
    --size;
}

template<typename T>
inline Node<T>* List<T>::findNode(const T& data)
{
    auto tmp = head;
    while (tmp != nullptr && tmp->data != data)
    {
        tmp = tmp->next;
    }
    return tmp;
}


template<typename T>
inline void List<T>::insertAt(const T& data, size_t position)
{
    if (position > size)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 0)
    {
        addHead(data);
        return;
    }
    if (position == size)
    {
        auto tmp = new Node<T>(data, tail, nullptr);
        tail->next = tmp;
        tail = tmp;
        ++size;
        return;
    }

    auto current = head;
    for (size_t i = 0; i < position; ++i)
        current = current->next;

    auto newNode = new Node<T>(data, current->prev, current);
    current->prev->next = newNode;
    current->prev = newNode;
    ++size;
}


template<typename T>
inline void List<T>::removeAt(size_t position)
{
    if (position >= size)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 0)
    {
        removeHead();
        return;
    }
    if (position == size - 1)
    {
        auto tmp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete tmp;
        --size;
        return;
    }

    auto current = head;
    for (size_t i = 0; i < position; ++i)
        current = current->next;

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    --size;
}


template<typename T>
inline size_t List<T>::findElement(const T& data) const
{
    auto current = head;
    size_t position = 0;
    while (current != nullptr)
    {
        if (current->data == data)
            return position;
        current = current->next;
        ++position;
    }
    return -1; 
}


template<typename T>
inline int List<T>::searchAndReplace(const T& search, const T& replace)
{
    auto current = head;
    int count = 0;
    while (current != nullptr)
    {
        if (current->data == search)
        {
            current->data = replace;
            ++count;
        }
        current = current->next;
    }
    return count > 0 ? count : -1;
}


template<typename T>
inline void List<T>::reverse()
{
    if (empty())
        return;

    auto current = head;
    Node<T>* tmp = nullptr;

    while (current != nullptr)
    {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }

    tmp = head;
    head = tail;
    tail = tmp;
}

