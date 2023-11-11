#include "Customer.h"
/*!
    \brief  Customer buy product method
    \param Product& product, Factory& factory
*/
void Customer::buy_product(Product& product, std::shared_ptr<Factory> factory) {
    receipt.push_back({product.product_name, product.price});
    cost += product.price;
    factory->add_profit(product.price);
}
/*!
    \brief  Customer get receipt method 
*/
void Customer::get_receipt(){
    for(int i = 0; i < receipt.size(); i++)
        std::cout << "Name: " << receipt[i].first << " " <<  receipt[i].second << std::endl;
    std::cout << "End cost: " << cost << std::endl;
}
