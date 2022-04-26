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

        int Size() const { //const -> does not modify internal values of IntArray
            return m_size;
        }

        bool IsEmpty() const {
            return (m_size==0);
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
}