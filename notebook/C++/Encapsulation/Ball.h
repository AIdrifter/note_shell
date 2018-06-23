#include <string>
using namespace std;



class Ball {
public:
    // constructcor
    Ball();
    Ball(double, const char*);
    Ball(double, string&);

    // 實作於類別定義中的函式會自動inline
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
        return (4 / 3 * 3.14159 * _radius * _radius * _radius);
    }

    // desctructor
    ~Ball();

/*
 * 在類別封裝時，有一個基本原則是：資訊的最小化公開。如果屬性可以不公開就不公開，如果要取得或設定物件的某些屬性，也是儘量透過方法成員來進行。
 */

private:
    double _radius; // 半徑
    string _name; // 名稱
};
