#include "Product.h"
/*!
    \brief Product constructor with params
    \param int _id, int _price, std::string _prod_name
*/
Product::Product(int _id = 0, int _price = 0, std::string _prod_name = ""){
    id = _id;
    price = _price;
    product_name = _prod_name;
}