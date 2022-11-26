#pragma once
#include <exception>
#include <iostream>
#include "IntArray.h"

using namespace std;

class bad_range : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad Range!";
    }
};

class bad_length : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad Length!";
    }
};

IntArray::IntArray() = default;

IntArray::IntArray(int length) : m_length{ length }
{
    if (length <= 0)
    {
        throw bad_length();
    }
    else
    {
        m_data = new int[length] {};
    }
    for (int i{ 0 }; i < length; ++i)
    {
        m_data[i] = i + 1;
    }
}

IntArray::~IntArray()
{
    delete[] m_data;
}

void IntArray::copyArray(IntArray& _arr)
{
    _arr.m_length = this->m_length;
    _arr.m_data = new int[_arr.m_length];
    for (int i{ 0 }; i < this->m_length; ++i)
        _arr.m_data[i] = this->m_data[i];
}

void IntArray::copyToArray(IntArray& _arr, bool ZeroFilling)
{
    if (_arr.m_length < this->m_length)
        throw bad_range();
    else
    {
        for (int i{ 0 }; i < this->m_length; ++i)
            _arr.m_data[i] = this->m_data[i];
        if (ZeroFilling && (_arr.m_length > this->m_length))
        {
            for (int i = m_length; i < _arr.m_length; ++i)
            {
                _arr.m_data[i] = 0;
            }
        }
    }
}

void IntArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int& IntArray::operator[](int index)
{
    if (index < 0 || index >= m_length)
    {
        throw bad_range();
    }
    return m_data[index];
}

void IntArray::reallocate(int newLength)
{
    erase();
    if (newLength <= 0)
        return;
    m_data = new int[newLength];
    m_length = newLength;
}

void IntArray::resize(int newLength)
{
    if (newLength == m_length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
        if (newLength > m_length)
        {
            for (int index = m_length; index < newLength; ++index)
            {
                data[index] = 0;
            }
        }
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

void IntArray::insertBefore(int value, int index)
{
    if (index < 0 || index > m_length)
    {
        throw bad_range();
    }

    int* data{ new int[m_length + 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    data[index] = value;

    for (int after{ index }; after < m_length; ++after)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntArray::remove(int index)
{
    if (index < 0 || index >= m_length)
    {
        throw bad_range();
    }

    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[m_length - 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    --m_length;
}

void IntArray::search(int request) const
{
    int results = 0;
    for (int i{ 0 }; i < m_length; ++i)
    {
        if (m_data[i] == request)
        {
            if (!results) std::cout << request << " found at: " << i;
            else cout << ", " << i;
            ++results;
        }
    }
    if (!results) cout << request << " not found!";
    cout << endl;
}

void IntArray::getValues() const
{
    for (int i{ 0 }; i < m_length; ++i)
        cout << m_data[i] << ' ';
    cout << endl;
}

void IntArray::insertAtBeginning(int value) { insertBefore(value, 0); }
void IntArray::insertAtEnd(int value) { insertBefore(value, m_length); }

int IntArray::getLength() const { return m_length; }

int IntArray::getValue(int num) const {
    if (num < 0 || num >= m_length)
        throw bad_range();
    return m_data[num];
}