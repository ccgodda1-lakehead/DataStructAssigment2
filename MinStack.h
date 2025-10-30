#pragma once

// A Stack class based on an array implementation
// This is a bounded stack (has a fixed size).
class MinStack
{
public:
    MinStack(int cap);
    MinStack(const MinStack& other);
    ~MinStack();

    void push(const int& val);
    int pop();
    int top() const;

    bool is_empty() const;
    bool is_full() const;

    void clear();
    MinStack& operator=(MinStack other);

private:
    int* data;
    int capacity;
    int last;
};



MinStack::MinStack(int cap)
{
    if (cap <= 0)
        throw string("ERROR: Invalid capacity!");

    capacity = cap;
    data = new int[capacity];
    last = -1;
}


MinStack& MinStack::operator=(MinStack other) {
    swap(data, other.data);
    swap(capacity, other.capacity);
    swap(last, other.last);

    return *this;
}


MinStack::MinStack(const MinStack& other) {
    capacity = other.capacity;
    data = new int[capacity];

    last = other.last;
    for (int i = 0; i <= last; i++)
        data[i] = other.data[i];
}


MinStack::~MinStack()
{
    delete[] data;
}


void MinStack::push(const int& val)
{
    if (is_full())
        throw string("ERROR: Stack overflow!");

    last++;
    data[last] = val;
}


int MinStack::pop()
{
    if (is_empty())
        throw string("ERROR: Stack underflow!");

    int val = data[last];
    --last;
    return val;
}


int MinStack::top() const
{
    if (is_empty())
        throw string("ERROR: Attempting to retrieve an element from an empty stack!");

    return data[last];
}


bool MinStack::is_empty() const
{
    return last == -1;
}


bool MinStack::is_full() const
{
    return last == capacity - 1;
}

void MinStack::clear()
{
    last = -1;
}
