/*
Author: Satish Akhade(satish.sva@gmail.com)
Below code provide the use of time counter (chrono) to increase the temperatures and reset on base on requirement
*/
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
static float thermal_temp_lab=0; //coldlab
static float thermal_temp_room=0;
int counter=0;

class Flow 
{
    public:
        Flow()
        {
            std::cout << "Init the temperature Coldlab" << std::endl;
            thermal_temp_lab =10.00; // buffer
        }
        ~Flow()
        {
            std::cout << "Destructors got called" << std::endl;
        }
        float get_updated_coldlab(float temp)
        {
            thermal_temp_lab = temp + 0.01;
            return thermal_temp_lab;
        }
};

class RoomFlow : public Flow
{
    public:
        RoomFlow()
        {
            std::cout << "Init the temperature Room" << std::endl;
            thermal_temp_room =23.00; 
        }
        ~RoomFlow()
        {
            std::cout << "Destructors got called" << std::endl;
        }
        float get_updated_room_temp(float temp)
        {
            std::cout<< "Get the room temperature"<<std::endl;
            thermal_temp_room = temp + 0.001;
            return thermal_temp_room;
        }
        void temp_cross_limit(float temp_room, float temp_lab );
        void show_temp_lcd( float temp_room, float temp_lab)
        {
            std::cout << "Display fuction to show temperature value on the LCD every 5 second" << std::endl;
            std::cout << "Lab temperature: " << temp_lab<<" " << "Room temperature: " << temp_room << std::endl;
        }
        void check_second_counter(void);
};

void RoomFlow::temp_cross_limit(float temp_room, float temp_lab)
{
    if(temp_room > 30.0)
    {
        std::cout<< "Reset room temperature to initial state"<<std::endl;
        thermal_temp_room=24;
    }
    if(temp_lab > 15.0)
    {
        std::cout<< "Reset Lab temperature to initial state"<<std::endl;
        thermal_temp_lab=10;
    }
}

void RoomFlow::check_second_counter(void){
    while(true){
        if(counter >= 5)
        {
            std::cout<< "Reset counter to zero"<<std::endl;
            counter=0;
            show_temp_lcd((get_updated_room_temp(thermal_temp_room)),(get_updated_coldlab(thermal_temp_lab)));
            temp_cross_limit(thermal_temp_room,thermal_temp_lab);
        }
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout<< "Counter details:"<< counter << std::endl;
        counter++;
    }
}

int main(void){
    RoomFlow f2;
    RoomFlow *rmflow;
    rmflow = &f2;
    //Get initial temperature 
    thermal_temp_lab = rmflow->get_updated_coldlab(thermal_temp_lab);
    thermal_temp_room = rmflow->get_updated_room_temp(thermal_temp_room);
    rmflow->show_temp_lcd(thermal_temp_room,thermal_temp_lab);
    rmflow->check_second_counter();
    return 0;
}

//--------------------outPut------------------------
/*
Init the temperature Coldlab
Init the temperature Room
Get the room temperature
Display fuction to show temperature value on the LCD every 5 second
Lab temperature: 10.01 Room temperature: 23.001
Counter details:0
Counter details:1
Counter details:2
Counter details:3
Counter details:4
Reset counter to zero
Get the room temperature
Display fuction to show temperature value on the LCD every 5 second
Lab temperature: 10.02 Room temperature: 23.002
Counter details:0
Counter details:1
Counter details:2
Counter details:3
Counter details:4
Reset counter to zero
Get the room temperature
Display fuction to show temperature value on the LCD every 5 second
Lab temperature: 10.03 Room temperature: 23.003
Counter details:0
Counter details:1
Counter details:2
Counter details:3
Counter details:4
Reset counter to zero
Get the room temperature
Display fuction to show temperature value on the LCD every 5 second
Lab temperature: 10.04 Room temperature: 23.004
Counter details:0
Counter details:1
Counter details:2
Counter details:3
Counter details:4
Reset counter to zero
Get the room temperature
Display fuction to show temperature value on the LCD every 5 second
Lab temperature: 10.05 Room temperature: 23.005
---------------Continous till limit then it will reset the position---------
*/

