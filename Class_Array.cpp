// Class_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
template <typename T>

class Array
{
    T* ptr;
    int size;
public:
    
    explicit Array(int size) : size(size)
    {
        this->ptr = new T[this->size];
        for (int i = 0; i < this->size; i++)
            this->ptr[i] = rand()%100 + 1;
    }

    ~Array()
    {
        delete[] ptr;
    }

    Array(const Array& array)
    {
        this->size = array.size;
        
        this->ptr = new T[size];
        for (int i = 0; i < size; i++)
            this->ptr[i] = array.ptr[i];       
    }

    Array& operator=(const Array& array)
    {
        if (this != &array)
        {
            delete[] ptr;
            this->size = array.size;

            this->ptr = new T[size];
            for (int i = 0; i < size; i++)
                this->ptr[i] = array.ptr[i];
        }
        return *this;
    }

    Array(Array&& arr) noexcept
    {
        if (this != &arr)
        {
            this->size = arr.size;
            this->ptr = arr.ptr;
            
            arr.ptr = nullptr;

            //std::cout << "This is move constructor" << std::endl;
        }
    }

    Array& operator=(Array&& arr) noexcept
    {
        if (this != &arr)
        {
            delete[] this->ptr;
            this->ptr = nullptr;

            this->size = arr.size;            
            this->ptr = arr.ptr;

            arr.size = 0;
            arr.ptr = nullptr;

            //std::cout << "This is move assignment" << std::endl;
        }
        return *this;
    }

    T operator[](int i) const
    {
        if (i >= 0 && i <= this->size)

            return this->ptr[i];
        else
            return this->ptr[0];
    }

    T& operator[](int i)
    {
        if (i >= 0 && i <= this->size) 
            
            return this->ptr[i];
        else      
            return this->ptr[0];
    }

    int getsize()
    {
        return this->size;
    }

    void push_back(T element)
    {
        T* newptr = new T[size + 1];

        for (int i = 0; i < this->size; i++)
            newptr[i] = this->ptr[i];
        
        delete[] this->ptr;
        this->ptr = newptr;
        this->ptr[size] = element;
        this->size++;
    }

    void pop_back()
    {
        T* newptr = new T[size - 1];

        for (int i = 0; i < this->size - 1; i++)
            newptr[i] = this->ptr[i];

        delete[] this->ptr;
        this->ptr = newptr;
        
        this->size--;
    }

    void print_array()
    {
        for (int i = 0; i < size; i++)
            std::cout << this->ptr[i] << ",  " ;
        std::cout << std::endl;
    }
    
};

int main()
{
    Array<char> array4(4);
    Array<char> array5(3);
    array5 = std::move(Array<char>(7));
    
    Array<char> array = std::move(Array<char>(2));
    array.print_array();

    array.push_back('H');
    array.push_back('e');
    array.push_back('l');
    array.push_back('l');
    array.push_back('o');

    array.print_array();
    int i = array.getsize();
    std::cout << "The size of array  = " << i << std::endl;

    array.pop_back();
    array.pop_back();

    array.print_array();
    i = array.getsize();
    std::cout << "The size of array  = " << i << std::endl;

    return 0;
}

