//You can implement a move constructor to efficiently transfer ownership of resources 
//(in this case, the dynamically allocated name array) from one object to another.
// Here's an example with the move constructor added:
//A move constructor in C++ is a special member function introduced to efficiently transfer
// ownership of resources from one object to another. It is used when creating a 
//new object by moving the resources of an existing object, avoiding unnecessary copying. 
//Here are some reasons why a move constructor is needed:

/*
In C++, the use of && in a move constructor's parameter list indicates an rvalue reference. An rvalue reference is a reference that can bind to an rvalue, which typically represents a temporary object or a value that is about to be moved.

The move constructor with an rvalue reference is a key feature of move semantics in C++. It allows for the efficient transfer of resources (like dynamically allocated memory) from one object to another without unnecessary copying. The move constructor is invoked when an object is being moved, and it takes advantage of the fact that an rvalue reference can bind to temporary objects.

Here's a basic explanation of how move semantics work:

Copy Constructor:

The copy constructor (MyClass(const MyClass& other)) is used for creating a new object as a copy of an existing object. It involves copying the values from the source object to the newly created object.
Move Constructor:

The move constructor (MyClass(MyClass&& other) noexcept) is used for efficiently transferring ownership of resources from one object to another. It takes advantage of the fact that an rvalue reference (MyClass&&) can bind to temporary objects or objects that are about to be discarded. Instead of copying, the move constructor can "move" the resources by transferring ownership, which is often more efficient.*/




#include <bits/stdc++.h>
using namespace std;

class CpConstructor     {
    char* name;
    public:
        CpConstructor(const char* pName) {
            size_t len = strlen(pName) + 1;
            name = new char[len];
            strcpy(name, pName);
        }

        CpConstructor(CpConstructor&& cpObj) noexcept{
            strcpy(name, cpObj.name); 
            cpObj.name = nullptr;
        }

        ~CpConstructor() {
            cout<<"destructor called"<<endl;
            delete []name;
        }

        void display() {
            cout<<name<<endl;
        }
};


int main() {

    CpConstructor* obj1 = new CpConstructor("mausam");
    obj1->display();
    CpConstructor* obj2 = new CpConstructor(move(*obj1));
    delete obj1;
    obj2->display();
   
    return 0;
}
