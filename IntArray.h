#pragma once
#include <exception>

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray();
    IntArray(int length);
    ~IntArray();
    void copyArray(IntArray& _arr);
    void copyToArray(IntArray& _arr, bool ZeroFilling = true);
    void erase();
    int& operator[](int index);
    void reallocate(int newLength);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);
    void search(int request) const;
    void getValues() const;
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int getLength() const;
    int getValue(int num) const;
};