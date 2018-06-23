#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Singleton
{
private:
    static Singleton *m_instance;
    Singleton(){}
public:
    static Singleton *getInstance(){
        if(m_instance==NULL){
            m_instance = new Singleton();
        }
        return m_instance;
    }
};
Singleton* Singleton::m_instance = NULL;

int main(){
    Singleton *instance1 = Singleton::getInstance();
    Singleton *instance2 = Singleton::getInstance();

    if (instance1 == instance2)
    {
        printf("instance same \n");
        printf("instance1 address %p instance2 address %p \n", instance1, instance2);
    }

    delete instance1;
    return 0;
}
