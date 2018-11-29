#include <iostream>
using namespace std;

static int num = 0;
class TestClass
{
public:
    int a;
    float b;
    TestClass(float f)
    {
        a = 55;
        b = f;
        ++num;
    }
};
TestClass test(32);

int main(int argc,char *argv[])
{
    std::cout<<"Int: "<<test.a<<std::endl;
    std::cout<<"Float: "<<test.b<<std::endl;
    std::cout<<"Constructor has been called "<<num<<" times"<<std::endl;
    while(true);
    return 0;
}

