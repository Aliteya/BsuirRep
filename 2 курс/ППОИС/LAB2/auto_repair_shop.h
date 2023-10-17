#pragma once
#include <iostream> 
#include <string> 
#include <vector> 
#include "windows.h"

class auto_repair_shop { 
public: 
    int car_counter; 
    std::string name; 
    std::vector<std::pair<std::string, int>> our_exp; 
    int engine_price; 
    int suspension_price; 
    int battery_price; 
    int brakers_price; 
    int profit;

    auto_repair_shop();
    auto_repair_shop(std::string _name);
    void greet();
    void see_ya();
    void exp_list();
};

class car_part { 
public: 
    int condition;    
    virtual void part_say() = 0; 
    virtual void part_repair() = 0; 
};

class Engine : public car_part { 
public: 
    void part_say() override; 
    void part_repair() override; 
};

class Suspension : public car_part { 
public: 
    void part_say() override; 
    void part_repair() override; 
};

class Battery : public car_part { 
public: 
    void part_say() override; 
    void part_repair() override; 
};

class Brakes : public car_part { 
public: 
    void part_say() override; 
    void part_repair() override; 
};

class car { 
public: 
    int condition; 
    std::string car_name; 
    int e_cond; 
    int s_cond; 
    int bat_cond; 
    int br_cond; 
    Engine engine; 
    Suspension suspension; 
    Battery battery; 
    Brakes brakes;

    car();
    car(std::string _car_name, int _e_cond, int _s_cond, int _bat_cond, int _br_cond);
    ~car();
    void car_disaster();
    void car_say();
    void car_repair(auto_repair_shop& shop);
    void make_exp_list(auto_repair_shop& shop);
};

class human { 
protected: 
    std::string name; 
public:
    human(); 
    human(std::string _name); 
};

class master : public human { 
public: 
    master(); 
    master(std::string _name); 
    void start_repair(car& my_car, auto_repair_shop& shop); 
};

class ordinary_worker : public human { 
public: 
    ordinary_worker(); 
    ordinary_worker(std::string _name); 
    void start_check(car& my_car, master& my_master, auto_repair_shop& shop); 
};

class cashier : public human { 
public: 
    cashier(); 
    cashier(std::string _name); 
    void profit_check(auto_repair_shop& shop); 
};

class client : public human { 
public: 
    client(); 
    client(std::string _name); 
    void request_car_repair(car& my_car, auto_repair_shop& shop, ordinary_worker& my_ord, master& my_master); 
};