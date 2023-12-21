#include <bits/stdc++.h>
using namespace std;

class File
{
    private:
        unique_ptr<char[]> fileName;
    
    public:
        File(const char* name) {
            size_t len = strlen(name) + 1U;
            fileName = make_unique<char[]>(len);
            strcpy(fileName.get(), name);
        }

        File(File&& obj) noexcept {
           fileName = move(obj.fileName);
        }

        void display()
        {
            cout<<fileName.get()<<endl;
        }

};

int main()
{
    File file1("DbEncrypted File!");
    File file2(move(file1));
    file2.display();
    file1.display();
    file2.display();
    return 0;
}
