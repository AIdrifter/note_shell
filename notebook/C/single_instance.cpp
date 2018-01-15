#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class B{
 public:
  B() {
   printf ("new B\n");
  }
 ~B() {
   printf ("delete B\n");
 }
 static B& getInstance() {
   static B b;
   return b;
 }
 void printInstance() {
    printf ("instance = %p\n" , this );
 }
};

int main(){
   B::getInstance().printInstance();
   B::getInstance().printInstance();
   return 0;
}

