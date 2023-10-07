#include <iostream>
#include "windows.h"

class auto_repair_shop{
public:
    int car_counter;
    
    auto_repair_shop(){
        car_counter = 0;
    }
    
    ~auto_repair_shop(){

    }

    void greet(){
        std:: cout << "Welcome to our repair shop, we help " << car_counter << " cars" << std :: endl;
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
    Engine engine;
    Suspension suspension;
    Battery battery;
    Brakes brakes;
    
    car(){
        condition = 1;
    }  

    ~car(){

    }
    
    void car_disaster(int e_cond, int s_cond, int bat_cond, int br_cond){
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
        std::  cout << "bibika has sad eyes" << std:: endl; 
    }

    void car_repair(auto_repair_shop& shop){
        if (this->condition == 0){
            
            std:: cout << "in the game you can drive without any rules, but... in life, be careful on the road. And fasten your seat belt." << std:: endl;
            
            if(!engine.condition){
                engine.part_repair();
            }
            if(!suspension.condition){
                suspension.part_repair();
            }
            if(!battery.condition){
                battery.part_repair();
            }
            if(!brakes.condition){
                brakes.part_repair();
            }
        } 
        
        shop.car_counter++;

    }
};


int main(){

auto_repair_shop aush;
aush.greet();

car fcar;

fcar.car_say();

fcar.car_disaster(0, 0, 0, 0);

fcar.car_repair(aush);
aush.greet();
return 0;
}
