// Class_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
template <typename T>

class Array
{
public:
    Array()
    {
        this->size = 5;
        this->ptr = new T[this->size];
        for (int i = 0; i < this->size; i++)
            this->ptr[i] = rand()%100 + 1;

        print_array();
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

    Array(Array&& arr)
    {
        if (this != &arr)
        {
            this->size = arr.size;
            this->ptr = arr.ptr;
            
            arr.ptr = nullptr;

            std::cout << "This is move constructor" << std::endl;
        }
    }

    Array& operator=(Array&& arr) 
    {
        if (this != &arr)
        {
            delete[] this->ptr;
            this->ptr = nullptr;

            this->size = arr.size;
            this->ptr = new T[size];
            for (int i = 0; i < size; i++)
                this->ptr[i] = arr.ptr[i];
            
            delete[] arr.ptr;
            arr.ptr = nullptr;

            std::cout << "This is move assignment" << std::endl;
        }
        return *this;
    }

    T& operator[](int i)
    {
        if (i >= 0 && i <= this->size) 
            
            return this->ptr[i];
        else      
            return this->ptr[0];
    }

    void print_array()
    {
        for (int i = 0; i < size; i++)
            std::cout << this->ptr[i] << ",  " ;
        std::cout << std::endl;
    }

private:
    T* ptr;
    int size;

};

int main()
{
    Array<int> array;
    Array<int> array2 = array;
    Array<int> array3;
    array3 = array2;

    std::cout << array[4] << std::endl;
    
    Array<char> array4;
    Array<char> array5 = Array<char>();
    
    Array<char> array6 = std::move(Array<char>());
    return 0;
}

