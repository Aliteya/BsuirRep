#include "Factory.h"

/*!
    \brief Factory constructor
*/
Factory::Factory(){
    name = "Workbench";
    profit = 1000;
}
/*!
    \brief Factory constructor with params
    \param string _name, int _profit
*/
Factory::Factory(std::string _name, int _profit){
    name = _name;
    profit = _profit;
}
/*!
    \brief Factory hello method
*/
void Factory::hello(){
    std::cout << "Hello you in " << name << " the filial of Feel Good Inc." << std:: endl; 
}
/*!
    \brief Factory profit getter
*/
int Factory::get_profit(){
    return profit;
}
/*!
    \brief Factory profit adder
*/
void Factory::add_profit(int _price){
    profit += _price;
}
/*!
    \brief Factory profit subtractor
*/
void Factory::subtract_profit(int _cost){
    if (profit - _cost >= 0)
        profit -= _cost;
    else throw std::logic_error("This factory is bankrupt");
}