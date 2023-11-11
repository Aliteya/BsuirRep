#include "RawMaterial.h"
/*!
    \brief RawMaterial constructor
*/
RawMaterial::RawMaterial(){
    name = "web";
    amount = 1;
}
/*!
    \brief Product constructor with params
    \param const std::string& _name, int _amount
*/
RawMaterial::RawMaterial(const std::string& _name, int _amount){
    if (std::find(materials.begin(), materials.end(), _name) != materials.end()) {
        name = _name;
        amount = _amount;
        std::cout << "Raw material: " << name << " " << amount << std::endl;
    } 
    else throw std:: runtime_error("We don't provide this material: " + _name);
}