// Class_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Array
{
public:
    Array()
    {
        this->size = 5;
        this->ptr = new int[this->size];
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
        
        this->ptr = new int[size];
        for (int i = 0; i < size; i++)
            this->ptr[i] = array.ptr[i];       
    }

    Array& operator=(const Array& array)
    {
        if (this != &array)
        {
            delete[] ptr;
            this->size = array.size;

            this->ptr = new int[size];
            for (int i = 0; i < size; i++)
                this->ptr[i] = array.ptr[i];
        }
        return *this;
    }

    Array(Array&& arr)
    {
        if (this != &arr)
        {
            //this->size = arr.size;
            //this->ptr = new int[size];
            for (int i = 0; i < size; i++)
                this->ptr[i] = arr.ptr[i];
            
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
            this->ptr = new int[size];
            for (int i = 0; i < size; i++)
                this->ptr[i] = arr.ptr[i];
            
            delete[] arr.ptr;
            arr.ptr = nullptr;

            std::cout << "This is move assignment" << std::endl;
        }
        return *this;
    }

    int& operator[](int i)
    {
        if (i >= 0 && i <= this->size) 
            
            return this->ptr[i];
        else      
            return this->ptr[0];
    }

    int get_element(int i)
    {
        if (i >= 0 && i <= this->size)

            return this->ptr[i];
        else
            return 0;     
    }

    void print_array()
    {
        for (int i = 0; i < size; i++)
            std::cout << this->ptr[i] << std::endl;
    }

private:
    int* ptr;
    int size;

};

int main()
{
    Array array;
    Array array2 = array;
    Array array3;
    array3 = array2;

    std::cout << array[4] << std::endl;
    
    Array array5 = Array();
    Array array6 = std::move(array5);

    array3 = std::move(array2);
    return 0;
}

