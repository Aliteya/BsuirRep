#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Factory{
public:
    std:: string name;
    int profit;

    Factory(){
        name = "Workbench";
        profit = 1000;
    }

    Factory(std::string _name, int _profit){
        name = _name;
        profit = _profit;
    }

    void add_profit(int _price){
        profit += _price;
    }

    void subtract_profit(int _cost){
        profit -= _cost;
    }
};

class Product{
public:
    int id;
    int price;
    std::string product_name;

    Product(){}

    Product(int _id, int _price, std::string _prod_name){
        id = _id;
        price = _price;
        product_name = _prod_name;
    };
   ~Product(){}
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
        else throw std:: runtime_error("We don't provide this material: " + _name);
    }

    ~RawMaterial(){}
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

    Product manufacture(RawMaterial& mater1, RawMaterial& mater2, Factory& fact){
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
};

class Machine{
protected:
    int status;
public:
    std ::string name;
    int id;
    std::string type;

    Machine(){
        name = "Stanok";
        id = 221703;
        type = "Magic mixer";
        status = 0;
    }

    Machine(std::string _name, int _id, std::string _type){
        name = _name;
        id = _id;
        type = _type;
        status = 0;
    }

    ~Machine(){}

    void start(){
        status = 1;
        std::cout << "Machine started working" << std::endl;
    }

    void finish(){
        status = 0;
        std::cout << "Machine finished working" << std::endl;
    }

    Product produce(RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact){
        start();
        Product product = line.manufacture(mater1, mater2, fact);
        finish();
        return product;
    }
};

class Human {
public:
    std::string name;

    Human() {
        name = "Ryan Gosling";
    }

    Human(std::string _name) {
        name = _name;
    }

    ~Human() {}
};

class Employee : public Human {
protected:
    int id;
    int salary;
    Factory* factory;

public:
    Employee() {
        id = 0;
        salary = 0;
        factory = nullptr;
    }

    Employee(std::string _name, int _id, int _salary, Factory* _factory) {
        name = _name;
        id = _id;
        salary = _salary;
        factory = _factory;
    }

    ~Employee() {}

    virtual void work() = 0;

    int get_salary() {
        return salary;
    }

    int get_id() {
        return id;
    }
};

class Engineer : public Employee {
public:
    Engineer() {}

    Engineer(std::string _name, int _id, int _salary, Factory* _factory) {
        name = _name;
        id = _id;
        salary = _salary;
        factory = _factory;
    }

    ~Engineer() {}

    void work() override {
        std::cout << "Engineer is working" << std::endl;
    }

    Product operateMachine(Machine& machine, RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact) {
        std::cout << "Engineer is operating the machine" << std::endl;
        return machine.produce(mater1, mater2, line, fact);
    }
};

class Manager : public Employee {
public:
    std::vector<Engineer*> subordinates;

    Manager() {}

    Manager(std::string _name, int _id, int _salary, Factory* _factory) {
        name = _name;
        id = _id;
        salary = _salary;
        factory = _factory;
    }

    ~Manager() {}

    void work() override {
        std::cout << "Manager is working" << std::endl;
    }

    void add_subordinates(Engineer* _engineer) {
        subordinates.push_back(_engineer);
    }

    void pay_salary() {
        for (int i = 0; i < subordinates.size(); i++) {
            double salary = subordinates[i]->get_salary();
            factory->subtract_profit(salary);
            std::cout << "Paying $" << salary << " to " << subordinates[i]->get_id() << std::endl;
        }
    }
};

class Supplier : public Human {
public:
    std::map<std::string, int> material_prices = {{"wood", 100}, {"wool", 200}, {"metal", 300}, {"web", 20}, {"glass", 50}};

    Supplier() {}

    ~Supplier() {}

    void provide_materials(RawMaterial& mater, Factory& fact) {
        if (std::find(mater.materials.begin(), mater.materials.end(), mater.name) != mater.materials.end()) {
            std::cout << "Providing material: " << mater.name << std::endl;
            mater.amount += 5;
            int cost = material_prices[mater.name];
            fact.subtract_profit(cost);
        } else {
            std::cout << "Material not allowed: " << mater.name << std::endl;
        }
    }
};

class Customer : public Human {
public:
    std::vector<std::pair<std::string, int>> receipt;

    void buy_product(Product& product, Factory& factory) {
        receipt.push_back({product.product_name, product.price});
        factory.add_profit(product.price);
        std::cout << "Bought product: " << product.product_name << std::endl;
    }
};

int main(){

  try {
    Factory factory;
    RawMaterial rawMaterial("wood", 5);
    RawMaterial rawMaterial2("wool", 6);
    ProductionLine productionLine;
    Machine machine("Stanok", 221703, "Magic mixer");
    Engineer engineer("John Doe", 123, 5000, &factory);
    Manager manager("Jane Smith", 456, 7000, &factory);
    Supplier supplier;
    Customer customer;

    factory.add_profit(100);
    factory.subtract_profit(50);
    Product product = productionLine.manufacture(rawMaterial, rawMaterial2, factory);;
    engineer.work();
    Product producedProduct = engineer.operateMachine(machine, rawMaterial, rawMaterial2, productionLine, factory);
    manager.work();
    manager.add_subordinates(&engineer);
    manager.pay_salary();
    supplier.provide_materials(rawMaterial, factory);
    customer.buy_product(product, factory);
    } catch (const std::string& error_message) {
        std::cout << "Error: " << error_message << std::endl;
    }
    return 0;
}
