//created by: nick ls
//created on: 9/14/17

//the following algorithm is designed to determine the average velocity of a jet taking off from a catapult launcher on
//an aircraft carrier. Also it will determine how fast the jet took off in the measurement of time

#include <iostream>
using namespace std;

struct takeoff_info{
            double speed        = 0.0;      //speed of jet at launch from the air craft carrier
            double distance     = 0.0;      //how long the runway is
            double time         = 0.0;      //how long it takes the jet to takeoff from the AC carrier
            double acceleration = 0.0;      //how fast the acceleration of the jet is during takeoff
};

int main() {
    
    takeoff_info attempt1;                  //declaration of the object
    
    attempt1.speed = 100.0;                 //currently in km/hr units
    attempt1.distance = 700.0;              //currently in meters
    
    attempt1.speed = (attempt1.speed * 1000) / 3600;    //this is the conversion from km/hr to m/s so we get the right output
    
    attempt1.time = attempt1.distance / attempt1.speed;     //this is how we find the takeoff time, by dividing the distance by the speed
    
    cout << "Current time after dividing distance by speed: " << attempt1.time << " seconds for complete launch." << endl; 
    
    attempt1.acceleration = (2 * attempt1.distance) / (attempt1.time * attempt1.time);  //this is the equation to determine the acceleration based off of the (distance X 2) divided by the time squared
    
    cout << "Final acceleration after dividing speed by time: " << attempt1.acceleration << " meters per second per second." << endl;
    
    return 0;
    
}

//the following are all the attempts inputs and outputs

/* Attempt A    278 km/hr    92m
Current time after dividing distance by speed: 1.19137 seconds for complete launch.
Final acceleration after dividing speed by time: 129.636 meters per second per second.
*/

/* Attempt B    278 km/hr   700m
Current time after dividing distance by speed: 9.06475 seconds for complete launch.
Final acceleration after dividing speed by time: 17.0379 meters per second per second.
*/

/* Attempt C    200 km/hr   60m
Current time after dividing distance by speed: 1.08 seconds for complete launch.
Final acceleration after dividing speed by time: 102.881 meters per second per second.
*/

/* Attempt D    100 km/hr   700m
Current time after dividing distance by speed: 25.2 seconds for complete launch.
Final acceleration after dividing speed by time: 2.20459 meters per second per second.
*/