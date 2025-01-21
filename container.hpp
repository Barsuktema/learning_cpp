#pragma once
#include <iostream>
#include <string> 

template <typename T>
class Array {
    public:
    Array() : m_data{}, m_size{0} {}

    int size() const { return m_size; }

    void push_back(T value) {
        T* new_data = new T[m_size + 1];
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }
        new_data[m_size] = value;
        delete [] m_data;
        m_data = new_data;
        m_size++;
    }

    void insert(T value, int m_pos) {
        int pos = m_pos;
        int ind = 0;
        bool ind_mid = false;
        T* new_data = new T[m_size + 1];
        for (size_t i = 0; i < m_size; ++i) {
            if (i == pos) {
                new_data[ind] = value;
                ind += 1;    
                new_data[ind] = m_data[i];
                ind_mid = true;
            } else {
                if (ind_mid == false) {
                    new_data[ind] = m_data[i];
                    ind += 1;
                } else {
                    new_data[ind+1] = m_data[i];
                    ind += 1;
                }
            }
        }
        if (m_pos == m_size) {
            new_data[m_size] = value;
        }

        delete [] m_data;
        m_data = new_data;
        m_size ++;
    }

    void erase(int ind) {
        T* new_data = new T[m_size - 1];
        int j = 0;
        for (size_t i = 0; i < m_size; ++i) {
            if (i == ind){
            } else {
                new_data[j] = m_data[i];
                j ++;
            }
        }
        delete[] m_data;
        m_data = new_data;
        m_size --;
    }


    void print() {
        for (size_t i = 0; i < m_size; ++i) {
            if (i != m_size - 1) {
                std::cout << m_data[i] << ",";
            } else {
                std::cout << m_data[i] << "\n";
            } 
        }
    }

    T &operator[](int ind) {
        return m_data[ind];
    }

    ~ Array() {
        delete[] m_data;
        m_size = 0;
    }

    private:
        T* m_data;
        size_t m_size;
};

template <typename T>
class List{
    public:

    List() :  m_last{}, m_size{0} {}

    struct Node {
        Node* next; 
        Node* prev; 
        T data; 
    };

    int size() const { return m_size; }

    void push_back(T value) {
        Node* new_node = new Node{}; 
        new_node->prev = m_last;
        new_node->next = nullptr;  
        new_node->data = value;
        if (m_size == 0) {
            m_start = new_node;
        } else {
            m_last->next = new_node;
        }
        m_last = new_node; 
        m_size += 1;
    }

    void print() {
        m_last = m_start;
        for (size_t i = 0; i < m_size; ++i) {
            if (i != m_size - 1) {
                std::cout << m_last->data << ",";
                m_last = m_last->next;
            } else {
                std::cout << m_last->data << "\n";
            } 
        }
    }

    T &operator[](int ind) {
        m_last = m_start;
        for (size_t i = 0; i < ind; ++i) {
            m_last = m_last->next;
        }
        return m_last->data;
    }

    void erase(int ind) {
        m_last = m_start;
        for (size_t i = 0; i < m_size; ++i) {
            if (i==ind) {
                tmp = m_last;
                Node* tmp_Node = m_last->next; 
                tmp_Node->next = tmp->next->next;
                tmp_Node->next->next->prev = tmp_Node;
                m_last->prev->next = tmp_Node;
                m_size -= 1;
                delete tmp_Node;
            }
            m_last = m_last->next;
        }
    }

    void insert(T value, int pos) {
        m_end = m_last;
        m_last = m_start;
        Node* newNode = new Node{};
        newNode->data = value;
        if (pos==0) {
            newNode->next = m_last;
            m_last->prev = newNode;
            newNode->prev = nullptr;
            m_start = newNode;
            m_size +=1;
        }
        if (pos >0 && pos < m_size) {
            for (size_t i = 0; i < m_size; ++i) {
                if (i==pos) {
                    newNode->next = m_last;
                    newNode->prev = m_last->prev;
                    tmp = newNode;
                    m_last->prev = tmp;
                    m_last->prev->prev->next = tmp;    
                    m_size += 1;
                }
                if (m_last->next != nullptr){
                    m_last = m_last->next;
                }
            }

        }
        if (pos==m_size) {
            newNode->next = nullptr;
            m_end->next = newNode;
            newNode->prev = m_end;
            m_last=m_end;
            m_size+=1;
        }
    }

    ~ List() {
        m_last = m_start;
        for (size_t i = 0; i < m_size; ++i) {
                tmp = m_last;
                delete m_last;
                m_last = tmp->next;
        }
        delete[] tmp;
        m_size = 0;
    }

    private:
        Node* m_last;
        Node* m_start;
        Node* tmp;
        size_t m_size = 0;
        Node* m_end;
};
