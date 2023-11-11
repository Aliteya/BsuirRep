#ifndef ENGINEER_H
#define ENGINEER_H

#include <iostream>
#include <string>
#include "Employee.h"
#include "Machine.h"
#include "RawMaterial.h"
#include "ProductionLine.h"
#include "Factory.h"

class Engineer : public Employee {
public:
    Engineer(std::string _name, int _id, int _salary,  std::shared_ptr<Factory> _factory);
    void work() override;
    Product operateMachine(Machine& machine, RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line,  std::shared_ptr<Factory> fact);
};

#endif