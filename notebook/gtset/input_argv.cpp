//
// [Ubuntu Gtest]
// build enviorment
// https://ithelp.ithome.com.tw/articles/10202905
//
// build command
// g++ input_argv.cpp -o input_argv -Igtest/include -Lgtest/lib -lgtest -lpthread
//
// test command
// ./input_argv num_win=1


#include <gtest/gtest.h>

#define HELLOWORLD "Hello World"
using namespace std;
int num_win = 5;

TEST(GoogleTest, HelloWorld) {
    for (int i=0; i<num_win; i++) {
        cout<<" win_num work "<<i<<endl;
    }
}

int main(int argc, char **argv) {
    // Hook input parameter we want.
    for (int i = 1; i < argc; ++i) {
        string parameter = argv[i];
        printf("arg %2d : %s\n", i, parameter.c_str());


        // Check win_num and set global variable.
        // We only support "num_win=" currently,
        // Please ref getopt(), if you prefer GNU command line style.
        if (parameter.compare(0, strlen("num_win="),"num_win=") == 0) {
            string num(parameter.begin() + strlen("num_win="), parameter.end());
            num_win = stoi(num);
        }
    }

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
