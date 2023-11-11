#ifndef RAWMATERIAL_H
#define RAWMATERIAL_H

#include <iostream>
#include <string>
#include <vector>

class RawMaterial{
public:
    std::string name;
    int amount;
    std::vector<std:: string> materials = {"wood", "wool", "metal", "web", "glass"};

    RawMaterial();
    RawMaterial(const std::string& _name, int _amount);
};

#endif