#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include "RawMaterial.h"
#include "ProductionLine.h"
#include "Factory.h"

class Machine{
protected:
    int status;
public:
    std ::string name;
    int id;
    std::string type;

    Machine();
    Machine(std::string _name, int _id, std::string _type);
    int get_status();
    void start();
    void finish();
    Product produce(RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact);
};
#endif