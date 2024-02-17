#pragma once
#include <iostream> 
#include <string> 
#include <vector> 
#include "windows.h"

class Auto_repair_shop { 
public: 
    int car_counter; 
    std::string name; 
    std::vector<std::pair<std::string, int>> our_exp; 
    int engine_price; 
    int suspension_price; 
    int battery_price; 
    int brakers_price; 
    int profit;

    Auto_repair_shop();
    Auto_repair_shop(std::string _name);
    void greet();
    void see_ya();
    void exp_list();
};

class Car_part { 
public: 
    int condition;    
    virtual void part_say() = 0; 
    virtual void part_repair() = 0; 
};

class Engine : public Car_part { 
public: 
    void part_say() override; 
    void part_repair() override; 
};

class Suspension : public Car_part { 
public: 
    void part_say() override; 
    void part_repair() override; 
};

class Battery : public Car_part { 
public: 
    void part_say() override; 
    void part_repair() override; 
};

class Brakes : public Car_part { 
public: 
    void part_say() override; 
    void part_repair() override; 
};

class Car { 
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

    Car();
    Car(std::string _car_name, int _e_cond, int _s_cond, int _bat_cond, int _br_cond);
    ~Car();
    void car_disaster();
    void car_say();
    void car_repair(Auto_repair_shop& shop);
    void make_exp_list(Auto_repair_shop& shop);
};

class Human { 
protected: 
    std::string name; 
public:
    Human(); 
    Human(std::string _name); 
};

class Master : public Human { 
public: 
    Master(); 
    Master(std::string _name); 
    void start_repair(Car& my_car, Auto_repair_shop& shop); 
};

class Ordinary_worker : public Human { 
public: 
    Ordinary_worker(); 
    Ordinary_worker(std::string _name); 
    void start_check(Car& my_car, Master& my_master, Auto_repair_shop& shop); 
};

class Cashier : public Human { 
public: 
    Cashier(); 
    Cashier(std::string _name); 
    void profit_check(Auto_repair_shop& shop); 
};

class Client : public Human { 
public: 
    Client(); 
    Client(std::string _name); 
    void request_car_repair(Car& my_car, Auto_repair_shop& shop, Ordinary_worker& my_ord, Master& my_master); 
};