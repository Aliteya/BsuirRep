#include "Supplier.h"
/*!
    \brief  Supplier provide material method
    \param RawMaterial& mater, Factory& fact
*/
void Supplier::provide_materials(RawMaterial& mater, Factory& fact) {
    if (std::find(mater.materials.begin(), mater.materials.end(), mater.name) != mater.materials.end()) {
        std::cout << "Providing material: " << mater.name << std::endl;
        mater.amount += 5;
        int cost = material_prices[mater.name];
        fact.subtract_profit(cost);
    } else {
        std::cout << "Material not allowed: " << mater.name << std::endl;
    }
}