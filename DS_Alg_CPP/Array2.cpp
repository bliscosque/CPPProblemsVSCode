//to see memory leaks, compile with:
//clang++ -std=c++14 -fsanitize=address -g -O1 Array1.cpp
//-g -> additional debug information
//-O1 -> enable basic optimizations

//#define NDEBUG //no debug --- assert will not be executed
#include <cassert>
#include <ostream>
#include <iostream>

class IndexOutOfBoundsException{};




class IntArray {
    private:
        int* m_ptr{nullptr}; //direct member initialization (C++11)
        int m_size{0}; //direct member initialization (C++11)

    public:
        IntArray() = default; //ask compiler to syntethize default constructor for this class

        explicit IntArray(int size) { //explicit prevents implicit conversion from Int to IntArray
            if (size !=0) {
                m_ptr=new int[size]{}; //{} inicialize with 0. Without it... will inicialize with garbage
                m_size=size;
            }
        }

        ~IntArray() { //destructor
            delete[] m_ptr; //delete que aponta para nulptr -> nao há problema
        }

        int Size() const { //const -> does not modify internal values of IntArray
            return m_size;
        }

        bool IsEmpty() const {
            return (m_size==0);
        }

        // int& operator[](int index) { //overload do [], para poder acessar diretamente os elementos -- must return int& because needs to change the parameter
        //     return m_ptr[index];
        // }

        int operator[](int index) const { //overload now with const element (does not change its value)
            return m_ptr[index];
        }

        
        bool IsValidIndex(int index) const { //checke if bounds are valid
            return (index >= 0) && (index < m_size);
        }

        int& operator[](int index) {
            if (!IsValidIndex(index)) {
                throw IndexOutOfBoundsException{};
            }
            return m_ptr[index];
        }

        //IntArray(const IntArray&) = delete; //o compilador nao gera o default copy constructor

        IntArray(const IntArray& source) {
            if (! source.IsEmpty()) {
                m_size = source.m_size;
                m_ptr = new int[m_size]{};
                for (int i = 0; i < m_size; i++) {
                    m_ptr[i] = source.m_ptr[i];
                }
            }
        }
};

std::ostream& operator<<(std::ostream& os, const IntArray& a) {
    os << "[ ";
    for (int i = 0; i < a.Size(); i++) {
        os << a[i] << ' ';
    }
    os << ']';
    return os;
}

int main() {
    using namespace std;
    
    cout << "Creating empty Array" << endl;
    IntArray a{};
    cout << "a.Size() is: " << a.Size() << endl;
    assert(a.IsEmpty()); //run-time check. Program continue if true

    cout << "----------------" << endl;
    cout << "Creating array with 10 elem" << endl;
    IntArray b{10};
    cout << "b.Size() is: " << b.Size() << endl;
    assert(!b.IsEmpty());
    b[0]=10;
    cout << "b[0] now is: " << b[0] << endl;

    for (int i=0;i<10;i++) {
        b[i]=i;
    }
    cout << "Matriz b: " << b << endl;

    IntArray c = b; //copy inicialization. Will fail if copy constructor is not implemented --- member-wised copy (only copy members, but pointer points to same element - shallow copy)
    cout << "Matriz c: " << c << endl;

    return 0;
}