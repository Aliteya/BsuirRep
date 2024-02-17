#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>

class Factory{
protected:
    int profit;
public:
    std:: string name;

    Factory();
    Factory(std::string _name, int _profit);
    void hello();
    int get_profit();
    void add_profit(int _price);
    void subtract_profit(int _cost);
};
#endif