#include <iostream>
#include <string>
#include <vector>
#include "windows.h"

class auto_repair_shop{
public: 
    int car_counter;
  std::  string name;
  std:: vector<std :: pair <std :: string, int>> our_exp; 
    int engine_price;
    int suspension_price;
    int battery_price;
    int brakers_price;  
    int profit;


    auto_repair_shop(){
        car_counter = 0;
        name = "Aush";
        profit = 0;
        engine_price = 450;
        suspension_price = 300;
        battery_price = 50;
        brakers_price = 150;
    }

    auto_repair_shop(std :: string _name){
        car_counter = 0;
        this->name = _name;
        profit = 0; 
        engine_price = 450;
        suspension_price = 300;
        battery_price = 50;
        brakers_price = 150;
    }
    
    void greet(){
        std:: cout << "Welcome to our repair shop " << name << std :: endl;
        std :: cout << "Our prices: engine repair "<< engine_price << ", suspension repair " << suspension_price 
        << ", battery repair " << battery_price << ", brakers repair " << brakers_price << std :: endl;
    }

    void see_ya(){
        std:: cout << "we help " << car_counter << " cars" << std :: endl;
    }
 
    void exp_list(){
        for(int j = 0; j < our_exp.size(); j ++){
            std :: cout << "Mark: " << our_exp[j].first << " | Number of repaired: " << our_exp[j].second << std :: endl;  
        }
    }
};


class car_part{
public:
    int condition;
    virtual void part_say() = 0;
    virtual void part_repair() = 0;
};

class Engine : public car_part{
public:
    void part_say() override{
        if (this->condition == 0)
        std::  cout << "engine say BTOOOOOOM" << std:: endl; 
    }
    
    void part_repair() override{
        int array[4];
        srand(time(0));
    std :: cout << "To fix the engine you need to run the pistons in the correct order" << std :: endl;
        for (int i = 0; i < 4; i++)
            array[i] = 1 + rand() % 8;
        int piston;    
        for (int i = 0; i < 4; i++){
            std:: cout << "Start " << array[i] << " piston" << std :: endl;
            std :: cin >> piston;
            if (piston != array[i]){
        std::   cin.clear();
        std::   cin.ignore();
        std::   cin >> piston;
            }
        }
        this->condition = 1;
    }
};

class Suspension : public car_part{
public:
    void part_say() override{
        if (this->condition == 0)
        std::  cout << "suspension say PSSSSSSSSSSGGGIIII" << std:: endl; 
    }
      
    void part_repair() override{
        std :: cout << "To fix the suspension you need to guess the balancing number from 1 to 100" << std :: endl;
        int corr_num = 1 + rand() % 100;
        int user_num;
        std :: cin >> user_num;
        while(user_num != corr_num){
            if(user_num < corr_num){
                std:: cout << "Too low! Try again: ";
            } 
            else {
                std:: cout << "Too high! Try again: ";
            }
            std:: cin.clear();
            std:: cin.ignore();
            std:: cin >> user_num;
        }
        std:: cout << "The suspension are now repaired" << std:: endl;
        this->condition = 1;
    }
}; 

class Battery: public car_part{
public:
    void part_say(){
        if (this->condition == 0)
        std::  cout << "battery say PICPICPIC" << std:: endl; 
    }
      
    void part_repair() override{
        std :: cout << "The battery is charging, please wait" << std :: endl;
        for(int i = 0; i <= 100; i += 10){
    std::   cout << "battery is " << i << " percent charged" << std:: endl;
            Sleep(500);
        }
        this->condition = 1;
    }
}; 

class Brakes: public car_part{
public:
    void part_say(){
        if (this->condition == 0)
        std::  cout << "brakers say ATTENTION FIRE ON THE FLOOR" << std:: endl; 
    }
      
    void part_repair() override{
        std :: cout << "A cool car doesn't need brakes" << std :: endl;
        this->condition = 1;
    }
}; 
class car{
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
    
    car(){
        condition = 1;
        car_name = "Mitsubishi Carisma 1997";
        e_cond = 1;
        s_cond = 1;
        bat_cond = 1;
        br_cond = 1;
    }  

    car(std::string _car_name, int _e_cond, int _s_cond, int _bat_cond, int _br_cond){
        condition = 1;
        car_name = _car_name;
        e_cond = _e_cond;
        s_cond = _s_cond;
        bat_cond = _bat_cond;
        br_cond = _br_cond;
    }  

    ~car(){  }
    
    void car_disaster(){
        engine.condition = e_cond;
        suspension.condition = s_cond;
        battery.condition = bat_cond;
        brakes.condition = br_cond;
        if(!e_cond || !s_cond || !bat_cond || !br_cond){
            this->condition = 0;
        }
        if(!e_cond){
            engine.part_say();
        }
        if(!s_cond){
            suspension.part_say();
        }
        if(!bat_cond){
            battery.part_say();
        }
        if(!br_cond){
            brakes.part_say();
        }
    }

    void car_say(){
        if (this->condition == 0)
        std::cout << "bibika has sad eyes" << std::endl; 
        else std::cout << "your car " << car_name << " normally working" << std::endl;
    }

    void car_repair(auto_repair_shop& shop){
        if (this->condition == 0){
            
            std::cout << "in the game you can drive without any rules, but... in life, be careful on the road. And fasten your seat belt." << std::endl;
            
            if(!e_cond){
                engine.part_repair();
                shop.profit += shop.engine_price; 
                e_cond = 1;

            }
            if(!s_cond){
                suspension.part_repair();
                shop.profit += shop.suspension_price;
                s_cond = 1;
            }
            if(!bat_cond){
                battery.part_repair();
                shop.profit += shop.battery_price;
                bat_cond = 1;
            }
            if(!br_cond){
                brakes.part_repair();
                shop.profit += shop.brakers_price;
                br_cond = 1;
            }

        shop.car_counter++;
        make_exp_list(shop);
        this->condition = 1;
        } 
    }

    void make_exp_list(auto_repair_shop& shop){
        for(int i = 0; i < shop.our_exp.size(); i++){
            if(shop.our_exp[i].first == car_name){
                shop.our_exp[i].second++;
                return;
            }
        }
        shop.our_exp.push_back({car_name, 1});
    }
};

class human{
protected:
    std :: string name;
public:
    human(){
        name = "Ryan Gosling";
    }

    human(std :: string _name){
        name = _name;
    }
};


class master : public human {
public:
    master(): human("Ryan Gosling") {}
    master(std::string _name) : human(_name) {}

    void start_repair(car& my_car, auto_repair_shop& shop){
        std :: cout << "Hello lets start the repair" << std:: endl;
        my_car.car_repair(shop);
    }

};

class ordinary_worker : public human {
public:
    ordinary_worker(): human("Ryan Gosling") {}
    ordinary_worker(std::string _name) : human(_name) {}

    void start_check(car& my_car, master& my_master,auto_repair_shop& shop) {
        my_car.car_disaster();
        if (my_car.condition == 0){
        std :: cout << "I cant repair it alone, i should say it to my master" << std :: endl;
        my_master.start_repair(my_car, shop);}
        else std:: cout << "Your car is intact" << std:: endl;
    }
};

class cashier: public human {
public:
    cashier(): human("Ryan Gosling") {}
    cashier(std::string _name) : human(_name) {}

    void profit_check(auto_repair_shop& shop){
        std :: cout << "Our profit: " << shop.profit << "BYN" << std :: endl;
    }

};

class client : public human{
public:
    client(): human("Misha Chess") {}

    client(std::string _name): human(_name) {}

    void request_car_repair(car& my_car, auto_repair_shop& shop, ordinary_worker& my_ord, master& my_master) {
        std::cout << "Requesting car repair for " << my_car.car_name << " at " << shop.name << std::endl;
        my_ord.start_check(my_car, my_master, shop);
    }

};

int main() {
    // Создание объектов для каждого класса
    auto_repair_shop shop("My Auto Repair Shop");
    client myClient("John Doe");
    ordinary_worker myWorker("Worker Bob");
    master myMaster("Master Steve");
    cashier myCashier("Cashier Alice");
    car myCar("Tesla Model S", 0, 0, 0, 0); // Создаем автомобиль с поврежденными деталями

    // Приветствие в автомастерской
    shop.greet();

    // Клиент делает запрос на ремонт автомобиля
    myClient.request_car_repair(myCar, shop, myWorker, myMaster);

    // Проверка прибыли автомастерской после ремонта
    myCashier.profit_check(shop);

    // Проверка списка автомобилей, которые были отремонтированы
    shop.exp_list();

    // Проверка состояния автомобиля после ремонта
    myCar.car_say();

    // Завершение работы автомастерской
    shop.see_ya();

    return 0;
}
