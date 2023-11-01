#ifndef FABRIIC_SYSTEM_H
#define FABRIIC_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Factory{
protected:
    int profit;
public:
    std:: string name;

    Factory();
    Factory(std::string _name, int _profit);
    void hello();
    int get_profit();
    void add_profit(int _price);
    void subtract_profit(int _cost);
};

class Product{
public:
    int id;
    int price;
    std::string product_name;

    Product();
    Product(int _id, int _price, std::string _prod_name);
   ~Product();
};

class RawMaterial{
public:
    std::string name;
    int amount;
    std::vector<std:: string> materials = {"wood", "wool", "metal", "web", "glass"};

    RawMaterial();
    RawMaterial(const std::string& _name, int _amount);
    ~RawMaterial();
};


class ProductionLine{
public:
    std::map<std::pair<std::string, std::string>, Product> product_map;

    ProductionLine();
    Product manufacture(RawMaterial& mater1, RawMaterial& mater2, Factory& fact);
};

class Machine{
protected:
    int status;
public:
    std ::string name;
    int id;
    std::string type;

    Machine();
    Machine(std::string _name, int _id, std::string _type);
    int get_status();
    ~Machine();
    void start();
    void finish();
    Product produce(RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact);
};

class Human {
public:
    std::string name;

    Human();
    Human(std::string _name);
    ~Human();
};

class Employee : public Human {
protected:
    int id;
    int salary;
    Factory* factory;

public:
    Employee();
    Employee(std::string _name, int _id, int _salary, Factory* _factory);
    ~Employee();
    virtual void work() = 0;
    int get_salary();
    int get_id();
};

class Engineer : public Employee {
public:
    Engineer();
    Engineer(std::string _name, int _id, int _salary, Factory* _factory);
    ~Engineer();
    void work() override;
    Product operateMachine(Machine& machine, RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact);
};

class Manager : public Employee {
public:
    std::vector<Engineer*> subordinates;

    Manager();
    Manager(std::string _name, int _id, int _salary, Factory* _factory);
    ~Manager();
    void work() override;
    void add_subordinates(Engineer* _engineer);
    void pay_salary();
};

class Supplier : public Human {
public:
    std::map<std::string, int> material_prices = {{"wood", 100}, {"wool", 200}, {"metal", 300}, {"web", 20}, {"glass", 50}};

    Supplier();
    ~Supplier();
    void provide_materials(RawMaterial& mater, Factory& fact);
};

class Customer : public Human {
public:
    std::vector<std::pair<std::string, int>> receipt;
    int cost = 0; 

    void buy_product(Product& product, Factory& factory);
    void get_receipt();
};
#endif