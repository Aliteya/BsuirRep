#include "Manager.h"
/*!
    \brief Manager constructor with params
    \param string _name, int _id, int _salary, std::shared_ptr<Factory> _factory
*/
Manager::Manager(std::string _name, int _id, int _salary, std::shared_ptr<Factory> _factory) {
    name = _name;
    id = _id;
    salary = _salary;
    factory = _factory;
}
/*!
    \brief  Manager work method
*/
void Manager::work() {
    std::cout << "Manager is working" << std::endl;
}
/*!
    \brief  Manager add subordinates method
    \param std::shared_ptr<Engineer> _engineer
*/
void Manager::add_subordinates(std::shared_ptr<Engineer> _engineer) {
    subordinates.push_back(_engineer);
}
/*!
    \brief  Manager pay salary for subordinates method
*/
void Manager::pay_salary() const{
    for (int i = 0; i < subordinates.size(); i++) {
        double salary = subordinates[i]->get_salary();
        factory->subtract_profit(salary);
        std::cout << "Paying $" << salary << " to " << subordinates[i]->get_id() << std::endl;
    }
}