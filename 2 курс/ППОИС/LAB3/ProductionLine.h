#ifndef PRODUCTIONLINE_H
#define PRODUCTIONLINE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Product.h"
#include "RawMaterial.h"
#include "Factory.h"

class ProductionLine{
public:
    std::map<std::pair<std::string, std::string>, Product> product_map;

    ProductionLine();
    Product manufacture(RawMaterial& mater1, RawMaterial& mater2, Factory& fact);
};
#endif