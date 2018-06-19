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
    HawaiiPizza(){m_name="Hawaii pizza";}
};

class TunaPizza : public Pizza{
public:
    TunaPizza(){m_name="Tuna pizza";}
};

/* 下面使用PizzaFactory類別來處理披薩的產生，而PizzaStore類別負責披薩產生的後續處理。*/

class PizzaFactory{
public:
    Pizza *createPizza(string name);
};

// single factory create all possilbe products.
Pizza *PizzaFactory::createPizza(string name){
    Pizza *ret;
    if(name=="Hawaii")
    {
        ret = new HawaiiPizza();
    }
    if(name=="Tuna")
    {
        ret = new TunaPizza();
    }
    return ret;
}

class PizzaStore{
private:
    PizzaFactory m_PizzaFactory;
public:
    PizzaStore(PizzaFactory factory){m_PizzaFactory=factory;}
    Pizza *orderPizza(string name);
};


Pizza *PizzaStore::orderPizza(string name){
    Pizza *ret = m_PizzaFactory.createPizza(name);
    ret->bake();
    ret->deliver();
    return ret;
}

int main() {
    // create myPizzaFactory 處理披薩的產生
    PizzaFactory myPizzaFactory;

    // create myPizzaStore 負責披薩產生的後續處理
    PizzaStore myPizzaStore(myPizzaFactory);

    
    Pizza *myHawaiiPizza = myPizzaStore.orderPizza("Hawaii");
    Pizza *myTunaPizza = myPizzaStore.orderPizza("Tuna");

    delete myHawaiiPizza;
    delete myTunaPizza;
    return 0;
}
