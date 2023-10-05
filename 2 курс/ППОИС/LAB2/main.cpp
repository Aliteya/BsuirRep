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
    virtual void car_say() = 0;
    virtual void car_repair() = 0;
};

class Engine : public car_part{
public:
    void car_say() override{
        if (this->condition == 0)
        std::  cout << "engine say BTOOOOOOM" << std:: endl; 
    }
    
    void car_repair() override{
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
    }
};

class Suspension : public car_part{
public:
    void car_say() override{
        if (this->condition == 0)
        std::  cout << "suspension say PSSSSSSSSSSGGGIIII" << std:: endl; 
    }
      
    void car_repair() override{
        int array[4];
        srand(time(0));
    std :: cout << "To fix the engine you need to run the pistons in the correct order" << std :: endl;
        for (int i = 0; i < 4; i++)
            array[i] = 1 + rand() % 4;
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
    }
}; 

class Battery: public car_part{
public:
    void car_say(){
        if (this->condition == 0)
        std::  cout << "battery say PICPICPIC" << std:: endl; 
    }
      
    void car_repair() override{
        std :: cout << "The battery is charging, please wait" << std :: endl;
        for(int i = 0; i <= 100; i+=10){
    std::   cout << "battery is " << i << " percent charged" << std:: endl;
            Sleep(500);
        }
    }
}; 

class Brakes: public car_part{
public:
    void car_say(){
        if (this->condition == 0)
        std::  cout << "brakers say ATTENTION FIRE ON THE FLOOR" << std:: endl; 
    }
      
    void car_repair() override{
        int array[4];
        srand(time(0));
    std :: cout << "To fix the engine you need to run the pistons in the correct order" << std :: endl;
        for (int i = 0; i < 4; i++)
            array[i] = 1 + rand() % 4;
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
    }
}; 

class car: auto_repair_shop{
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
            engine.car_say();
        }
        if(!s_cond){
            suspension.car_say();
        }
        if(!bat_cond){
            battery.car_say();
        }
        if(!br_cond){
            brakes.car_say();
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
                engine.car_repair();
                engine.condition = 1;
            }
            if(!suspension.condition){
                suspension.car_repair();
                suspension.condition = 1;
            }
            if(!battery.condition){
                battery.car_repair();
                battery.condition = 1;
            }
            if(!brakes.condition){
                brakes.car_repair();
                brakes.condition = 1;
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

fcar.car_disaster(0, 1, 0, 1);

fcar.car_repair(aush);
aush.greet();
return 0;
}