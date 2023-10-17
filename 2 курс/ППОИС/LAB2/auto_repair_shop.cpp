#include "auto_repair_shop.h"

auto_repair_shop::auto_repair_shop(){
    car_counter = 0;
    name = "Aush";
    profit = 0;
    engine_price = 450;
    suspension_price = 300;
    battery_price = 50;
    brakers_price = 150;
}

auto_repair_shop::auto_repair_shop(std :: string _name){
    car_counter = 0;
    this->name = _name;
    profit = 0; 
    engine_price = 450;
    suspension_price = 300;
    battery_price = 50;
    brakers_price = 150;
}
    
void auto_repair_shop::greet(){
    std:: cout << "Welcome to our repair shop " << name << std :: endl;
    std :: cout << "Our prices: engine repair "<< engine_price << ", suspension repair " << suspension_price 
        << ", battery repair " << battery_price << ", brakers repair " << brakers_price << std :: endl;
}

void auto_repair_shop::see_ya(){
    std:: cout << "we help " << car_counter << " cars" << std :: endl;
}
 
void auto_repair_shop::exp_list(){
    for(int j = 0; j < our_exp.size(); j ++){
        std :: cout << "Mark: " << our_exp[j].first << " | Number of repaired: " << our_exp[j].second << std :: endl;  
    }
}


void Engine ::part_say(){
    if (this->condition == 0)
    std::  cout << "engine say BTOOOOOOM" << std:: endl; 
}
    
void Engine ::part_repair(){
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

void Suspension ::part_say(){
    if (this->condition == 0)
    std::  cout << "suspension say PSSSSSSSSSSGGGIIII" << std:: endl; 
}
      
void Suspension ::part_repair(){
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

void Battery::part_say(){
    if (this->condition == 0)
    std::  cout << "battery say PICPICPIC" << std:: endl; 
}
      
void Battery::part_repair(){
    std :: cout << "The battery is charging, please wait" << std :: endl;
    for(int i = 0; i <= 100; i += 10){
   std::cout << "battery is " << i << " percent charged" << std:: endl;
        Sleep(500);
    }
    this->condition = 1;
}

void Brakes::part_say(){
    if (this->condition == 0)
    std::  cout << "brakers say ATTENTION FIRE ON THE FLOOR" << std:: endl; 
}
      
void Brakes::part_repair(){
    std :: cout << "A cool car doesn't need brakes" << std :: endl;
    this->condition = 1;
}

car::car(){
    condition = 1;
    car_name = "Mitsubishi Carisma 1997";
    e_cond = 1;
    s_cond = 1;
    bat_cond = 1;
    br_cond = 1;
}  

car::car(std::string _car_name, int _e_cond, int _s_cond, int _bat_cond, int _br_cond){
    condition = 1;
    car_name = _car_name;
    e_cond = _e_cond;
    s_cond = _s_cond;
    bat_cond = _bat_cond;
    br_cond = _br_cond;
}  

car::~car(){}
    
void car::car_disaster(){
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

void car::car_say(){
    if (this->condition == 0)
    std::cout << "bibika has sad eyes" << std::endl; 
    else std::cout << "your car " << car_name << " normally working" << std::endl;
}

void car::car_repair(auto_repair_shop& shop){
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

void car::make_exp_list(auto_repair_shop& shop){
    for(int i = 0; i < shop.our_exp.size(); i++){
        if(shop.our_exp[i].first == car_name){
            shop.our_exp[i].second++;
            return;
        }
    }
    shop.our_exp.push_back({car_name, 1});
}

human::human(){
    name = "Ryan Gosling";
}

human::human(std :: string _name){
    name = _name;
}

master::master(): human("Ryan Gosling") {}

master::master(std::string _name) : human(_name) {}

void master::start_repair(car& my_car, auto_repair_shop& shop){
    std :: cout << "Hello lets start the repair" << std:: endl;
    my_car.car_repair(shop);
}

ordinary_worker::ordinary_worker(): human("Ryan Gosling") {}
ordinary_worker::ordinary_worker(std::string _name) : human(_name) {}

void ordinary_worker::start_check(car& my_car, master& my_master,auto_repair_shop& shop) {
    my_car.car_disaster();
    if (my_car.condition == 0){
    std :: cout << "I cant repair it alone, i should say it to my master" << std :: endl;
    my_master.start_repair(my_car, shop);}
    else std:: cout << "Your car is intact" << std:: endl;
}

cashier::cashier(): human("Ryan Gosling") {}
cashier::cashier(std::string _name) : human(_name) {}

void cashier::profit_check(auto_repair_shop& shop){
    std :: cout << "Our profit: " << shop.profit << "BYN" << std :: endl;
}

client::client(): human("Misha Chess") {}

client::client(std::string _name): human(_name) {}

void client::request_car_repair(car& my_car, auto_repair_shop& shop, ordinary_worker& my_ord, master& my_master) {
    std::cout << "Requesting car repair for " << my_car.car_name << " at " << shop.name << std::endl;
    my_ord.start_check(my_car, my_master, shop);
}