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



# C++ Compiler : g++ instruction
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
