#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <memory>
#include <string>
#include "Factory.h"
#include "Human.h"

class Employee : public Human {
protected:
    int id;
    int salary;
    std::shared_ptr<Factory> factory;

public:
    Employee();
    Employee(std::string _name, int _id, int _salary,  std::shared_ptr<Factory> _factory);
    virtual void work() = 0;
    int get_salary();
    int get_id();
};
#endif