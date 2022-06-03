//to see memory leaks, compile with:
//clang++ -std=c++14 -fsanitize=address -g -O1 Array1.cpp
//-g -> additional debug information
//-O1 -> enable basic optimizations

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
};

//#define NDEBUG //no debug --- assert will not be executed
#include <cassert>

#include <iostream>
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

    try {
        cout << "Out of bound: " <<endl;
        b[15]=15;
    }catch(const IndexOutOfBoundsException& e) {
        cout << "Exception captured!!!" << endl;
    }
    return 0;
}