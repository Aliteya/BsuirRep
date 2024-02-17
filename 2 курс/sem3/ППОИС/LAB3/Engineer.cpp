#include "Engineer.h"
/*!
    \brief Engineer constructor with params
    \param string _name, int _id, int _salary,  std::shared_ptr<Factory> _factory
*/
Engineer::Engineer(std::string _name, int _id, int _salary,  std::shared_ptr<Factory> _factory) {
    name = _name;
    id = _id;
    salary = _salary;
    factory = _factory;
}

/*!
    \brief Engineer work method
*/
void Engineer::work(){
    std::cout << "Engineer is working" << std::endl;
}
/*!
    \brief Engineer operateMachine method
    \param Machine& machine, RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact
    \return Product
*/
Product Engineer::operateMachine(Machine& machine, RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line,  std::shared_ptr<Factory> fact) {
    std::cout << "Engineer is operating the machine" << std::endl;
    return machine.produce(mater1, mater2, line, *fact);
}