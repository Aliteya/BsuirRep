#include "ProductionLine.h"
/*!
    \brief ProductionLine constructor
*/
ProductionLine::ProductionLine(){
    product_map.insert({{"wood", "wool"}, Product(1, 100, "bed")});
    product_map.insert({{"wood", "metal"}, Product(2, 100, "sword")});
    product_map.insert({{"wood", "web"}, Product(3, 100, "fishing rod")});
    product_map.insert({{"wool", "web"}, Product(4, 100, "textile")});
    product_map.insert({{"wood", "glass"}, Product(5, 100, "snow globe")});
    product_map.insert({{"glass", "metal"}, Product(6, 100, "glasses")});
        
    product_map.insert({{"wool", "wood"}, Product(1, 100, "bed")});
    product_map.insert({{"metal" , "wood"}, Product(2, 100, "sword")});
    product_map.insert({{"web", "wood"}, Product(3, 100, "fishing rod")});
    product_map.insert({{"web", "wool"}, Product(4, 100, "textile")});
    product_map.insert({{"glass", "wood"}, Product(5, 100, "snow globe")});
    product_map.insert({{"metal", "glass"}, Product(6, 100, "glasses")});
}
/*!
    \brief ProductionLine method workbench
    \param RawMaterial& mater1, RawMaterial& mater2, Factory& fact
    \warning can make exeption "No product found for the given materials"
*/
Product ProductionLine::manufacture(RawMaterial& mater1, RawMaterial& mater2, Factory& fact){
    auto it = product_map.find({mater1.name, mater2.name});
    if (it != product_map.end()){
        Product product = it->second;
        std::cout << product.product_name <<std::endl;
        return product;
    }
    else {
        throw std::runtime_error("No product found for the given materials");
    }
}