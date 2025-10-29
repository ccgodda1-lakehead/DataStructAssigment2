#pragma once

#include <iostream>
using std::string;
using std::ostream;

template <class T>
class DLList;

template <class T>
class DLLNode {
public:
    DLLNode(const T& val, DLLNode* next, DLLNode* prev);

    T get_val() const { return val; }
    DLLNode* get_next() const { return next; }
    DLLNode* get_prev() const { return prev; }

private:
    T val;
    DLLNode* next;
    DLLNode* prev;

    friend class DLList<T>;
};

template <class T>
DLLNode<T>::DLLNode(const T& val, DLLNode* next, DLLNode* prev)
{
    this->val = val;
    this->next = next;
    this->prev = prev;
}

// A doubly-linked list class to store elements of a generic type T
template <class T>
class DLList {
public:
    DLList();
    DLList(const DLList& other);
    ~DLList();

    bool is_empty() const;

    DLLNode<T>* head_node() const;
    DLLNode<T>* tail_node() const;
    T head_val() const;
    T tail_val() const;

    void add_to_head(const T& val);
    void add_to_tail(const T& val);
    void append(const DLList& otherList);

    void remove_head();
    void remove_tail();
    bool remove(const T& val);
    void clear();

    bool contains(const T& val) const;
    DLList& operator=(DLList other);
    
    //added methods
    DLList rmv_ret_negative();

private:
    DLLNode<T>* head;
    DLLNode<T>* tail;
};



template <class T>
DLList<T>::DLList()
{
    head = nullptr;
    tail = nullptr;
}

template <class T>
DLList<T>::DLList(const DLList<T>& other) {
    head = nullptr;
    tail = nullptr;
    append(other);
}

template <class T>
DLList<T>::~DLList()
{
    clear();
}

template <class T>
void DLList<T>::clear()
{
    DLLNode<T>* tmp = head;
    DLLNode<T>* del_node;

    while (tmp != nullptr) {
        del_node = tmp;
        tmp = tmp->next;
        delete del_node;
    }

    head = nullptr;
    tail = nullptr;
}

template <class T>
bool DLList<T>::is_empty() const
{
    return head == nullptr;
}

template <class T>
void DLList<T>::add_to_head(const T& val)
{
    DLLNode<T>* new_node = new DLLNode<T>(val, head, nullptr);

    if (head != nullptr)
        head->prev = new_node;

    head = new_node;
    if (tail == nullptr)
        tail = new_node;
}

template <class T>
void DLList<T>::add_to_tail(const T& val)
{
    DLLNode<T>* new_node = new DLLNode<T>(val, nullptr, tail);

    if (tail != nullptr) //If list is non-empty
        tail->next = new_node;

    tail = new_node;
    if (head == nullptr)
        head = new_node;
}

template <class T>
void DLList<T>::remove_head()
{
    DLLNode<T>* del_node = head;

    if (is_empty())
        return;

    if (head == tail) // if only one node in list
        head = tail = nullptr;
    else {
        head = del_node->next;
        head->prev = nullptr;
    }
    delete del_node;
}

template <class T>
void DLList<T>::remove_tail()
{
    if (is_empty())
        return;

    DLLNode<T>* del_node = tail;

    if (head == tail) // if only one node in list
        head = tail = nullptr;
    else {
        tail = del_node->prev;
        tail->next = nullptr;
    }

    delete del_node;
}

template <class T>
bool DLList<T>::remove(const T& val)
{
    if (is_empty())
        return false;

    if (val == head->val) {
        remove_head();
        return true;
    }

    if (val == tail->val) {
        remove_tail();
        return true;
    }

    // traverse list to find the node to be deleted
    for (DLLNode<T>* curr = head->next; curr != nullptr; curr = curr->next) {
        if (curr->val == val) {
            DLLNode<T>* pred = curr->prev;
            DLLNode<T>* succ = curr->next;
            pred->next = succ;
            succ->prev = pred;
            delete curr;
            return true;
        }
    }

    return false;
}

template <class T>
bool DLList<T>::contains(const T& val) const
{
    DLLNode<T>* curr;

    for (curr = head; curr != nullptr; curr = curr->next) {
        if (curr->val == val)
            return true;
    }

    return false;
}

template <class T>
DLLNode<T>* DLList<T>::head_node() const
{
    return head;
}

template <class T>
DLLNode<T>* DLList<T>::tail_node() const
{
    return tail;
}

template <class T>
T DLList<T>::head_val() const
{
    if (is_empty())
        throw string("ERROR: Attempting to retrieve a value of the head from an empty list.");

    return head->val;
}

template <class T>
T DLList<T>::tail_val() const
{
    if (is_empty())
        throw string("ERROR: Attempting to retrieve a value of the tail from an empty list.");

    return tail->val;
}

template <class T>
void DLList<T>::append(const DLList& other)
{
    DLLNode<T>* temp1 = other.head;
    DLLNode<T>* temp2 = other.tail;

    while (temp1 != temp2) {
        add_to_tail(temp1->val);
        temp1 = temp1->next;
    }

    if (temp1 != nullptr)
        add_to_tail(temp1->val);
}

// copy assignment
template <class T>
DLList<T>& DLList<T>::operator=(DLList<T> other)
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);

    return *this;
}

template<class T>
ostream& operator<<(ostream& out, const DLList<T>& list) {
    out << "[";

    DLLNode<T>* curr = list.head_node();
    while (curr != nullptr) {
        out << curr->get_val();
        if (curr->get_next() != nullptr)
            out << ", ";
        curr = curr->get_next();
    }
    out << "]";

    return out;
}


//memeber functions
template <class T>
DLList<T> DLList<T>::rmv_ret_negative() {

    /*
    * Similar to replaceVal, create another list. look through list, if curr < 0
    * put it in neg array and delete.
    */

    DLLNode<T>* curr = head;
    DLList<T> negList;

    while (curr != nullptr) {
        if (curr->val < 0) {

            std::cout << "removed" << std::endl;

            negList.add_to_tail(curr->val);

            bool Changed = false;;

            if (curr == head) {
                remove_head();
                Changed = true;
            }

            if (curr == tail) {
                remove_tail();
                Changed = true;
            }

            if (Changed == false) {
                DLLNode<T>* pred = curr->prev;
                DLLNode<T>* succ = curr->next;
                pred->next = succ;
                succ->prev = pred;

                DLLNode<T>* newCurr = curr->get_next();

                delete curr;

                curr = newCurr;
            }

        }
        else {
            std::cout << "not Removed" << std::endl;


            curr = curr->get_next();
        }
    }

    return negList;

}

//non memeber functions
template<class T>
int replaceVal(DLList<T>& list, T f, T r) {

    
    DLLNode<T>* curr;
    DLList<T> newList;
    int count = 0;

    for (curr = list.head_node(); curr != nullptr; curr = curr->get_next()) {
        if (curr->get_val() == f) {


            /*
            need to set the curr node to the newnode via a replace, since it is a non memeber
            function it can not do that directly....

            add a replace function? could work but also idk if that's what teach is expecting
            set the pointer of curr to new node, tried didn't work I may just be dumb and doign it wrong

            maybe like.. remove curr from the DLLlist and add new, it would techincally work
            but it wouldn't really add at the same place..

            can create a whole other copy of the DLL and start copying it over but when you reach a curr
            you do an r instead.


            dont need this anymore
            DLLNode<T> newNode(r, curr->get_next(), curr->get_prev());

            */
            newList.add_to_tail(r);
            
            count++;

        }
        else {
            newList.add_to_tail(curr->get_val());
        }
    }

    list = newList;

    return count;
}


//I used this method to create a random mainDll list for testing
template <class T>
void DllListFillRandomInt(DLList<T>& list) {

    //makes it truely random
    srand(time(0));

    //adding ran varaibles to tail
    for (int i = 0; i <= 10; i++) {
        list.add_to_tail((rand() % 10)- 3);
    }

    //adding ones to make sure certain test functions run
    list.add_to_head(0);
}
