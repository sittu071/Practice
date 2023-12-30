#include <iostream>
#include <future>

using namespace std;

int square(int x){
    return x*x;
};


int main() {
    future<int> asyncFunction = async(&square, 10);
    for(int i = 1; i<10; i++) {
        cout<<square(i)<<endl;
    }
    cout<<asyncFunction.get()<<endl;
    return 0;
}