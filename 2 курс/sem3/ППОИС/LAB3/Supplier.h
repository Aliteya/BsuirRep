#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <iostream>
#include <string>
#include <map>
#include "Human.h"
#include "RawMaterial.h"
#include "Factory.h"

class Supplier : public Human {
public:
    std::map<std::string, int> material_prices = {{"wood", 100}, {"wool", 200}, {"metal", 300}, {"web", 20}, {"glass", 50}};

    void provide_materials(RawMaterial& mater, Factory& fact);
};
#endif