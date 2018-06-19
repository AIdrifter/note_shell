#include "Test.h"
#include "Ball.h"

// Test.h 採用forward declartion
// Test.cpp include Ball.h 對ball class 做實際的operation
Test::Test() {
    _ball = new Ball;
}

Test::Test(Ball *ball) {
    _ball = ball;
}

Ball* Test::ball() {
    return _ball;
}

void Test::ball(Ball *ball) {
    _ball = ball;
}
