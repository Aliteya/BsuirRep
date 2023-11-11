#include "Employee.h"
/*!
    \brief Employee abstract class constructor
*/
Employee::Employee() {
    id = 0;
    salary = 0;
    factory = std::make_shared<Factory>();
}
/*!
    \brief Employee constructor with params
    \param string _name, int _id, int _salary,  std::shared_ptr<Factory> _factory
*/
Employee::Employee(std::string _name, int _id, int _salary,  std::shared_ptr<Factory> _factory) {
    name = _name;
    id = _id;
    salary = _salary;
    factory = _factory;
}

/*!
    \brief Employee salary getter
*/
int Employee::get_salary() {
    return salary;
}
/*!
    \brief Employee id getter
*/
int Employee::get_id() {
    return id;
}