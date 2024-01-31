#include <iostream>   
using namespace std;

class MyClass {
public:
    int* data;

    MyClass(int size) {  
        this->Size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }
        cout << "the constructor is called " << this << endl;
    }

    MyClass(const MyClass &other) { // implementation of the copy operation
        this->Size = other.Size;
        this->data = new int [other.Size]; // in the current object of the class, we take the data pointer and assign a value from another object to each element of the array pointed to by the pointer, which we copy
        for (int i = 0; i < other.Size; i++){
            this->data[i] = other.data[i];
        }
        cout << "the copy constructor is called " << this << endl;
    }

    ~MyClass() { 
        cout << "the destructor is called " << this << endl;
        delete[] data;
    }
private:
    int Size;
};

int main() {
    MyClass a(10);
    MyClass b(a);
    return 0;
}