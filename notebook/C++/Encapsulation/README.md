# Encapsulation
- 如果您的類別定義有單一參數的建構函式（或除了第一個參數之外，其它參數都有預設值的建構函式），則預設會有自動轉換的作用，例如：
```C++
class Ball {
public:
    Ball(const char*);
   ...
};
```
- 則您可以使用以下的方式來建構物件並初始化：
```C++
Ball ball = "Green ball";
```

- 預設的轉換行為是由編譯器施行的，但有時是有危險的，如果您不希望編譯器自作主張，則您可以使用explicit修飾，告訴編譯器不要自作主張：

```C++
class Ball {
public:
    explicit Ball(const char*);
   ...
};
```
## auto_ptr 自動管理配置資源
## const and mutable
## friend
```C++
/* ball.h */
class Ball;

int compare(Ball&, Ball&);

class Ball {
public:
    Ball(double, char*);

    double radius() {
        return _radius;
    }

    char* name() {
        return _name;
    }

    void radius(double radius) {
        _radius = radius;
    }

    void name(char *name) {
        _name = name;
    }

    // 宣告朋友函式
    friend int compare(Ball&, Ball&);

private:
    double _radius; // 半徑
    char *_name; // 名稱

/* ball.cpp */
#include "Ball.h"

// compare 為 Ball 的 friend
int compare(Ball &b1, Ball &b2) {
    // 可直接存取私用成員
    if(b1._radius == b2._radius)
        return 0;
    else if(b1._radius > b2._radius)
        return 1;
    else
        return -1;
}

Ball::Ball(double radius, char *name) {
    _radius = radius;
    _name = name;
}
```

- 使用friend函式通常是基於效率的考量，以直接存取私用成員而不透過函式呼叫的方式，來省去函式呼叫的負擔，另外您也可以使用friend來重載 （Overload）運算子，之後的主題中會介紹。

- 您也可以將某個類別宣告為friend類別，被宣告為friend的類別可以直接存取私用成員，例如：

```C++
class Ball;

int compare(Ball&, Ball&);

class Ball {
public:
    ....

    // 宣告朋友類別
    friend class SomeClass;

private:
    ....
};
```
## object pointer
## this pointer
- 當您使用Ball類別新增兩個物件`b1(1, "RBall")`與`b2(2, "GBall")`時，b1與b2會各自擁有自己的_radius與_name資料成員，然而**函式成員**卻只有一份。

```C++

void name(string& name) {
    _name = name;
}

/*
* b1呼叫name()方法時，this儲存的就是b1的記憶體位址，
* 而使用b2呼叫name()方法時，this儲存的就是b2的記憶體位址，
* 所以 name()總是可以正確的得知該傳回哪一個物件的_name資料
*
*/
void name(string& name) {
    this-> _name = name;
}

```
## static member and static function
- 由於靜態成員是屬於class而不是object，所以當您呼叫static function時，並不會傳入object的address，所以static function中不會有this指標

```C++
/* Ball.h */
nclude <string>
using namespace std;

class Ball {
public:
    // 宣告靜態成員
    static double PI;
    // const 靜態成員可以在類別定義中初始化
    // static const double PI = 3.14159;

     // 宣告靜態函式
    static double toRadian(double);

    Ball();
    Ball(double, const char*);
    Ball(double, string&);

    double radius() {
        return _radius;
    }

    string& name() {
        return _name;
    }

    void radius(double radius) {
        _radius = radius;
    }

    void name(const char *name) {
        _name = name;
    }

    void name(string& name) {
        _name = name;
    }

    double volumn() {
        return (4 / 3 * PI * _radius * _radius * _radius);
    }

private:
    double _radius; // 半徑
    string _name; // 名稱
};


/* Ball.cpp */
#include <string>
#include "Ball.h"
using namespace std;

// 非const靜態成員要在類別定義外初始化
double Ball::PI = 3.14159;


// 實作靜態函式
double Ball::toRadian(double angle) {
    return 3.14159 / 180 * angle;
}

// 預設建構函式
Ball::Ball() {
    _radius = 0.0;
    _name = "noname ball";
}

Ball::Ball(double radius, const char *name) {
    _radius = radius;
    _name = name;
}

Ball::Ball(double radius, string &name) {
    _radius = radius;
    _name = name;
}





/* main.cpp */

#include <iostream>
#include "Ball.h"
using namespace std;

int main() {
    cout << Ball::PI
         << endl;


cout << "角度90等於徑度"
         << Ball::toRadian(90)
         << endl

    return 0;
}

```


## C++ Compiler : g++ instruction
```bash
# Generate Assembly : file.s
g++ -S file.cpp

# Generate file.exe(ignore -c)
g++ file.cpp  -o file

# Generate file.exe from object and cpp files
g++ file.cpp  obj.o -o file.exe

# Show all the warning
gcc -Wall -o main main.c

# Warning as error
gcc -Wall -Werror -o main main.c

# Compile two object file and combine it to test.cgi
g++ -c -o Ball.o Ball.cpp
g++ -c -o main.o main.cpp
# Link
g++ -o test.cgi Ball.o main.o
```
