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

        CpConstructor(const CpConstructor& cpObj) {
            size_t len = strlen(cpObj.name) + 1;
            name = new char[len];
            strcpy(name, cpObj.name);
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
    CpConstructor* obj2 = new CpConstructor(*obj1);
    delete obj1;
    obj2->display();
   
    return 0;
}
