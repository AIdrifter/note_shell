#include <iostream>
#include <string>
using namespace std;

class Pizza{
public:
    string m_name;
    void bake(){cout << m_name << "bake" << endl;}
    void delever(){cout << m_name << "delever" << endl;}
};

class HawaiiPizza : public Pizza{
public:
    HawaiiPizza(){m_name="Hawaii pizza";}
};

class TunaPizza : public Pizza{
public:
    TunaPizza(){m_name="Tuna pizza";}
};

// Force to implement "create Pizza"
class PizzaFactory{
public:
    // pure virtual function
    virtual Pizza *createPizza() = 0;
};

class HawaiiPizzaFactory : public PizzaFactory{
public:
    Pizza *createPizza();
};

class TunaPizzaFactory : public PizzaFactory{
public:
    Pizza *createPizza();
};

/* 用HawaiiPizzaFactory和TunaPizzaFactory類別取代原本的PizzaFactory的功能 */
// 比單一factory相較, 不需要重寫PizzaFactory::createPizza（）
// 會產生大量factory sub class
Pizza *HawaiiPizzaFactory::createPizza(){
    Pizza *ret = new HawaiiPizza();
    return ret;
}

Pizza *TunaPizzaFactory::createPizza(){
    Pizza *ret = new TunaPizza();
    return ret;
}

class PizzaStore{
private:
    PizzaFactory *m_PizzaFactory;
public:
    PizzaStore(PizzaFactory *factory){m_PizzaFactory=factory;}
    void setFlavor(PizzaFactory *factory){m_PizzaFactory=factory;}
    Pizza *orderPizza();
};

Pizza *PizzaStore::orderPizza(){
    Pizza *ret = m_PizzaFactory->createPizza();
    ret->bake();
    ret->delever();
    return ret;
}

int main() {

    HawaiiPizzaFactory myHawaiiFactory;
    PizzaStore myPizzaStore(&myHawaiiFactory);
    Pizza *myHawaiiPizza = myPizzaStore.orderPizza();

    TunaPizzaFactory myTunaFactory;
    myPizzaStore.setFlavor(&myTunaFactory);
    Pizza *myTunaPizza = myPizzaStore.orderPizza();

    delete myHawaiiPizza;
    delete myTunaPizza;
    return 0;
}
