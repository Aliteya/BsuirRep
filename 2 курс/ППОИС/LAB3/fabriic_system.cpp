#include "fabriic_system.h"

Factory::Factory(){
    name = "Workbench";
    profit = 1000;
}

Factory::Factory(std::string _name, int _profit){
    name = _name;
    profit = _profit;
}

void Factory::hello(){
    std::cout << "Hello you in " << name << " the filial of Feel Good Inc." << std:: endl; 
}

int Factory::get_profit(){
    return profit;
}

void Factory::add_profit(int _price){
    profit += _price;
}

void Factory::subtract_profit(int _cost){
    if (profit - _cost >= 0)
        profit -= _cost;
    else throw std::logic_error("This factory is bankrupt");
}

Product::Product(){}

Product::Product(int _id, int _price, std::string _prod_name){
    id = _id;
    price = _price;
    product_name = _prod_name;
}

Product::~Product(){}

RawMaterial::RawMaterial(){
    name = "web";
    amount = 1;
}

RawMaterial::RawMaterial(const std::string& _name, int _amount){
    if (std::find(materials.begin(), materials.end(), _name) != materials.end()) {
        name = _name;
        amount = _amount;
        std::cout << "Raw material: " << name << " " << amount << std::endl;
    } 
    else throw std:: runtime_error("We don't provide this material: " + _name);
}

RawMaterial::~RawMaterial(){}

ProductionLine::ProductionLine(){
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

Machine::Machine(){
    name = "Stanok";
    id = 221703;
    type = "Magic mixer";
    status = 0;
}

Machine::Machine(std::string _name, int _id, std::string _type){
    name = _name;
    id = _id;
    type = _type;
    status = 0;
}

int Machine::get_status(){
    return status;
}

Machine::~Machine(){}

void Machine::start(){
    status = 1;
    std::cout << "Machine started working" << std::endl;
}

void Machine::finish(){
    status = 0;
    std::cout << "Machine finished working" << std::endl;
}

Product Machine::produce(RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact){
    start();
    Product product = line.manufacture(mater1, mater2, fact);
    finish();
    return product;
}

Human::Human() {
    name = "Ryan Gosling";
}

Human::Human(std::string _name) {
    name = _name;
}

Human::~Human() {}

Employee::Employee() {
    id = 0;
    salary = 0;
    factory = nullptr;
}

Employee::Employee(std::string _name, int _id, int _salary, Factory* _factory) {
    name = _name;
    id = _id;
    salary = _salary;
    factory = _factory;
}

Employee::~Employee() {}

int Employee::get_salary() {
    return salary;
}

int Employee::get_id() {
    return id;
}

Engineer::Engineer() {}

Engineer::Engineer(std::string _name, int _id, int _salary, Factory* _factory) {
    name = _name;
    id = _id;
    salary = _salary;
    factory = _factory;
}

Engineer::~Engineer() {}

void Engineer::work(){
    std::cout << "Engineer is working" << std::endl;
}

Product Engineer::operateMachine(Machine& machine, RawMaterial& mater1, RawMaterial& mater2, ProductionLine& line, Factory& fact) {
    std::cout << "Engineer is operating the machine" << std::endl;
    return machine.produce(mater1, mater2, line, fact);
}

Manager::Manager() {}

Manager::Manager(std::string _name, int _id, int _salary, Factory* _factory) {
    name = _name;
    id = _id;
    salary = _salary;
    factory = _factory;
}

Manager::~Manager() {}

void Manager::work() {
    std::cout << "Manager is working" << std::endl;
}

void Manager::add_subordinates(Engineer* _engineer) {
    subordinates.push_back(_engineer);
}

void Manager::pay_salary() {
    for (int i = 0; i < subordinates.size(); i++) {
        double salary = subordinates[i]->get_salary();
        factory->subtract_profit(salary);
        std::cout << "Paying $" << salary << " to " << subordinates[i]->get_id() << std::endl;
    }
}

Supplier::Supplier() {}

Supplier::~Supplier() {}

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

void Customer::buy_product(Product& product, Factory& factory) {
    receipt.push_back({product.product_name, product.price});
    cost += product.price;
    factory.add_profit(product.price);
}

void Customer::get_receipt(){
    for(int i = 0; i < receipt.size(); i++)
        std::cout << "Name: " << receipt[i].first << " " <<  receipt[i].second << std::endl;
    std::cout << "End cost: " << cost << std::endl;
}
