#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Human{
public:
    std:: string name;
};

class Employee: public Human{
protected:
    int id;
    int salary;
public:
    virtual void work()=0;
};

class Manager: public Employee{
protected:
    void add_subordinates(){}
    void remove_subordinates(){}
public:
    std::vector <Employee> subordinates;
    void work() override{}
};

class Engineer: public Employee{
public:
    void work() override{}
};

class Machine{
public:
    std ::string name;
    int id;
    std::string type;
    int status;

    void start(){}
    void finish(){}
};

class RawMaterial{
public:
    std::string name;
    int amount;
    std::vector<std:: string> materials = {"wood", "wool", "metal", "web", "glass"};

    RawMaterial(){
        name = "web";
        amount = 1;
    }
    RawMaterial(const std::string& _name, int _amount){
        if (std::find(materials.begin(), materials.end(), _name) != materials.end()) {
            name = _name;
            amount = _amount;
            std::cout << "Raw material: " << name << " " << amount << std::endl;
        } 
        else throw "We don't provide this material: " + _name;
    }

};

class Product{
public:
    int id;
    int price;
    std::string product_name;

    Product() {}

    Product(int _id, int _price, std::string _prod_name){
        id = _id;
        price = _price;
        product_name = _prod_name;
    };
   // void manufacture();
};

class ProductionLine{
public:
    std::map<std::pair<std::string, std::string>, Product> product_map;

    ProductionLine(){
        product_map[{"wood", "wool"}] = Product(1, 100, "bed");
        product_map[{"wood", "metal"}] = Product(2, 100, "sword");
        product_map[{"wood", "web"}] = Product(3, 100, "fishing rod");
        product_map[{"wool", "web"}] = Product(4, 100, "textile");
        product_map[{"wood", "glass"}] = Product(5, 100, "snow globe");
        product_map[{"glass", "metal"}] = Product(6, 100, "glasses");
        
        product_map[{"wool", "wood"}] = Product(1, 100, "bed");
        product_map[{"metal" , "wood"}] = Product(2, 100, "sword");
        product_map[{"web", "wood"}] = Product(3, 100, "fishing rod");
        product_map[{"web", "wool"}] = Product(4, 100, "textile");
        product_map[{"glass", "wood"}] = Product(5, 100, "snow globe");
        product_map[{"metal", "glass"}] = Product(6, 100, "glasses");
    }

    Product manufacture(RawMaterial& mater1, RawMaterial& mater2){
        auto it = product_map.find({mater1.name, mater2.name});
        if (it != product_map.end()){
            Product product = it->second;
            std::cout << product.product_name <<std::endl;
            return product;
        }
        else {
            throw "No product found for the given materials";
        }
    }
};


class Supplier: public Human{
public:
    Supplier(){
    }


    void provide_materials(RawMaterial& mater){
        if (std::find(mater.materials.begin(), mater.materials.end(), mater.name) != mater.materials.end()) {
            std::cout << "Providing material: " << mater.name << std::endl;
            mater.amount += 5;
        } 
        else std::cout << "Material not allowed: " << mater.name << std::endl;
    }
};

class Customer: public Human{};

class Factory{};

int main(){

  try {
        // Create RawMaterials
        RawMaterial wood("wood", 10);
        RawMaterial wool("wool", 5);
        RawMaterial metal("metal", 3);
        Supplier supplier1;

        // Provide materials to the Supplier
        supplier1.provide_materials(wood);
        supplier1.provide_materials(wool);
        supplier1.provide_materials(metal);

        ProductionLine prline;
        prline.manufacture(wood, wool);
    } catch (const std::string& error_message) {
        std::cout << "Error: " << error_message << std::endl;
    }
    return 0;
}
