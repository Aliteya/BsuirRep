#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product{
public:
    int id;
    int price;
    std::string product_name;

    Product(int _id, int _price, std::string _prod_name);
};
#endif