#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include "Human.h"
#include "Product.h"
#include "Factory.h"

class Customer : public Human {
public:
    std::vector<std::pair<std::string, int>> receipt;
    int cost = 0; 

    void buy_product(Product& product, std::shared_ptr<Factory> factory);
    void get_receipt();
};
#endif