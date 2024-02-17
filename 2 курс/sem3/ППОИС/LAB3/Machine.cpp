#include "Machine.h"
/*!
    \brief Machine constructor
*/
Machine::Machine(){
    name = "Stanok";
    id = 221703;
    type = "Magic mixer";
    status = 0;
}
/*!
    \brief Machine constructor with params
    \param std::string _name, int _id, std::string _type
*/
Machine::Machine(std::string _name, int _id, std::string _type){
    name = _name;
    id = _id;
    type = _type;
    status = 0;
}
/*!
    \brief Machine getter for status
*/
int Machine::get_status(){
    return status;
}

/*!
    \brief Machine work start method
*/
void Machine::start(){
    status = 1;
    std::cout << "Machine started working" << std::endl;
}
/*!
    \brief Machine work finish method
*/
void Machine::finish(){
    status = 0;
    std::cout << "Machine finished working" << std::endl;
}
/*!
    \brief Machine produce method
    \param RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact
*/
Product Machine::produce(RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact){
    start();
    Product product = line.manufacture(mater1, mater2, fact);
    finish();
    return product;
}