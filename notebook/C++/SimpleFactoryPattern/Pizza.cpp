#include <iostream>
#include <string>
using namespace std;

class Pizza{
public:
    string m_name;
    void bake(){cout << m_name << "bake" << endl;}
    void deliver(){cout << m_name << "deliver" << endl;}
};

class HawaiiPizza : public Pizza{
public:
    HawaiiPizza(){m_name="Hawaii";}
};

class TunaPizza : public Pizza{
public:
    TunaPizza(){m_name="Tuna";}
};

/* orderPizza()函式內部依參數來實體化類別，所以當增加口味更改時，修改orderPizza()函式是不可避免的 */
Pizza *orderPizza(string name){
    Pizza *ret;
    if(name == "Hawaii")
    {
        ret = new HawaiiPizza();
    }
    if(name == "Tuna")
    {
        ret = new TunaPizza();
    }
    ret->bake();
    ret->deliver();
    return ret;
}

int main() {
    Pizza *myHawaiiPizza = orderPizza("Hawaii");
    Pizza *myTunaPizza = orderPizza("Tuna");

    delete myHawaiiPizza;
    delete myTunaPizza;
    return 0;
}
