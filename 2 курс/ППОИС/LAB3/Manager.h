#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Engineer.h"
#include "Factory.h"

class Manager : public Employee {
public:
    std::vector<std::shared_ptr<Engineer>> subordinates;

    Manager(std::string _name, int _id, int _salary, std::shared_ptr<Factory> _factory);
    void work() override;
    void add_subordinates(std::shared_ptr<Engineer> _engineer);
    void pay_salary() const;
};
#endif
