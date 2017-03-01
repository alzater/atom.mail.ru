// stack.h

#include "assert.h"

template <typename T>
class Stack
{
    public:
        Stack();
        Stack(size_t size);
        ~Stack();

        T& top();

        bool empty();
        size_t size();

        void push(const T& elem);
        void pop();

        bool ok();
        std::string dump();

    private:
        static const size_t DEFAULT_DATA_SIZE = 10;

    private:
        T* _data;
        size_t _top;
        size_t _dataSize;
};

template <typename T>
Stack<T>::Stack()
{
    _top = 0;
    _dataSize = DEFAULT_DATA_SIZE;
    _data = static_cast<T*>( operator new[] (_dataSize * sizeof(T)) );
}

template <typename T>
Stack<T>::Stack(size_t size)
{
    _top = 0;
    _dataSize = size;
    _data = static_cast<T*>( operator new[] (_dataSize * sizeof(T)) );
}

template <typename T>
Stack<T>::~Stack()
{
    for( int i = 0; i < _top; ++i )
        _data[i].~T();

    delete[] _data;
}

template <typename T>
T& Stack<T>::top()
{
    assert(_top);

    return _data[_top - 1];
}

template <typename T>
bool Stack<T>::empty()
{
    return _top == 0;
}

template <typename T>
size_t Stack<T>::size()
{
    return _top;
}

template <typename T>
void Stack<T>::push(const T& elem)
{
    assert(_top < _dataSize);

    new (_data + _top++) T(elem);
}

template <typename T>
void Stack<T>::pop()
{
    assert(_top);

    _data[--_top].~T();
}

template <typename T>
bool Stack<T>::ok()
{
    return _data && (_top < _dataSize);
}

template <typename T>
std::string Stack<T>::dump()
{
    std::string res;

    const bool isOk = ok();
    if( isOk )
        res += "Object is good\n";
    else
        res += "Object is bad\n";

    res += "data pointer: " + std::to_string(_data) + "\n";
    res += "top element number: " + std::to_string(_top) + "\n";
    res += "max elements: " + std::to_string(_dataSize) + "\n";
    if( isOk )
    {
        res += "elements: [";

        for( int i = 0; i < _top; ++i )
        {
            res += std::to_string(_data[i]);
            if( i < _top - 1 )
                res += ", ";
        }

        res += "]\n";
    }
}
