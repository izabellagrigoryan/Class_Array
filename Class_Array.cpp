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
            this->ptr[i] = 23;
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
    };

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

    std::cout << array3[2] << std::endl;
    
    return 0;
}

