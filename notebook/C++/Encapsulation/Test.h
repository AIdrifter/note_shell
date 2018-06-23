// forward declartion

class Ball;

class Test {
public:
    Test();
    Test(Ball*); /* we don't use any Ball's operation here*/

    Ball* ball();
    void ball(Ball*);

private:
    Ball *_ball; // 名稱
};

