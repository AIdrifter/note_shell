#include <string>
#include <iostream>
#include "Ball.h"
using namespace std;

/*
 * 1.Constructor
 * 2.:: Class scope resolution
 * 3.如果您沒有定義預設建構函式，則編譯器會自動幫您產生一個無實作內容的預設 建構函式。
 */

Ball::Ball() {
    cout<<"Ball Constructor\n"<<endl;
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

Ball::~Ball() {
    cout<<"Ball desctructor\n"<<endl;
}
