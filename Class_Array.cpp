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

    Array *array4 = new Array();
    Array *array5 = array4;
    Array *array6 = new Array();
    array5 = array6;

    int i = array.get_element(3);
    int j = array4->get_element(3);
    int k = array2.get_element(3);
    int l = array6->get_element(3);

    std::cout << &array << "  " << i << std::endl << &array2 << "  " << k << std::endl << &array3 << std::endl;
    std::cout << &array4 << "  " << j << std::endl << &array5 << std::endl << &array6 << "  " << l << std::endl;

    return 0;
}

