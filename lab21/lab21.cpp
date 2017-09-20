//created by: nick ls
//created on: 9/19/17

//about: program is supposed to output info about windchills, taking in user input of "temperature and starting wind speed"
//then output the wind speed, windchill according to the old formula, and windchill according to new formula, and difference between the two windchills

#include <iostream>
#include <cmath>                    //math library, so i can use math functions
using namespace std;

struct windchill{
    double temperature           = 0.0;                                         //user's input for temperature
    double start_wind_speed      = 0.0;                                         //user's input for windspeed(velocity)
    double old_style_wind_chill  = 0.0;                                         //variable for catching value of old style wind chill
    double new_style_wind_chill  = 0.0;                                         //variable for catching value of new style wind chill
    double wind_chill_difference = 0.0;                                         //variable for catching value of difference between new and old style wind chill values
    double find_old_style_wind_chill(double tempF, double velocity);            //function for determining old style wind chill
    double find_new_style_wind_chill(double tempF, double velocity);            //function for determining new style wind chill
};

double windchill::find_old_style_wind_chill(double tempF, double velocity){                                         //definition of old style wind chill function
        return ((0.081 * (3.71 * sqrt(velocity) + 5.81 - 0.25 * velocity) * (tempF - 91.4)) + 91.4);
}
    
double windchill::find_new_style_wind_chill(double tempF, double velocity){                                         //definition of new style wind chill function
        return (35.74 + 0.6215 * tempF - (35.75 * (pow(velocity, 0.16))) + 0.4275 * tempF * (pow(velocity, 0.16)));
}

int main(){
    
    windchill problem1;                         //first object for first data set
    windchill problem2;                         //second object for second data set   
    windchill problem3;                         //third object for third data set
    
    cout << "Enter first temperature: ";        
    cin >> problem1.temperature;                //user inputs first temperature
    cout << "Enter first windspeed: ";
    cin >> problem1.start_wind_speed;           //user inputs first wind chill velocity
    
    cout << "Enter second temperature: ";
    cin >> problem2.temperature;                //user inputs second temperature
    cout << "Enter second windspeed: ";
    cin >> problem2.start_wind_speed;           //user inputs second wind chill velocity
    
    cout << "Enter third temperature: ";
    cin >> problem3.temperature;                //user inputs third temperature
    cout << "Enter third windspeed: ";  
    cin >> problem3.start_wind_speed;           //user inputs third wind chill velocity
    
    problem1.new_style_wind_chill = problem1.find_new_style_wind_chill(problem1.temperature, problem1.start_wind_speed);        //storing first new style wind chill in it's variable by using function
    problem1.old_style_wind_chill = problem1.find_old_style_wind_chill(problem1.temperature, problem1.start_wind_speed);        //storing first old style wind chill in it's variable by using function
    
    problem2.new_style_wind_chill = problem2.find_new_style_wind_chill(problem2.temperature, problem2.start_wind_speed);        //storing second new style wind chill in it's variable by using function
    problem2.old_style_wind_chill = problem2.find_old_style_wind_chill(problem2.temperature, problem2.start_wind_speed);        //storing second old style wind chill in it's variable by using function
    
    problem3.new_style_wind_chill = problem3.find_new_style_wind_chill(problem3.temperature, problem3.start_wind_speed);        //storing third new style wind chill in it's variable by using function
    problem3.old_style_wind_chill = problem3.find_old_style_wind_chill(problem3.temperature, problem3.start_wind_speed);        //storing third old style wind chill in it's variable by using function
    
    problem1.wind_chill_difference = problem1.new_style_wind_chill - problem1.old_style_wind_chill;             //storing wind chill difference between new and old style value's for data set 1
    problem2.wind_chill_difference = problem2.new_style_wind_chill - problem2.old_style_wind_chill;             //storing wind chill difference between new and old style value's for data set 2
    problem3.wind_chill_difference = problem3.new_style_wind_chill - problem3.old_style_wind_chill;             //storing wind chill difference between new and old style value's for data set 3
    
    //all the following is just the output of the data collected from above
    cout << "Data Set 1:          ";
    cout << "Wind Speed: " << problem1.start_wind_speed << "          ";
    cout << "Old Formula: " << problem1.old_style_wind_chill << "          ";
    cout << "New Formula: " << problem1.new_style_wind_chill << "          ";
    cout << "Difference of Old FROM New: " << problem1.wind_chill_difference << endl;
    
    cout << "Data Set 2:          ";
    cout << "Wind Speed: " << problem2.start_wind_speed << "          ";
    cout << "Old Formula: " << problem2.old_style_wind_chill << "          ";
    cout << "New Formula: " << problem2.new_style_wind_chill << "          ";
    cout << "Difference of Old FROM New: " << problem2.wind_chill_difference << endl;
    
    cout << "Data Set 3:          ";
    cout << "Wind Speed: " << problem3.start_wind_speed << "          ";
    cout << "Old Formula: " << problem3.old_style_wind_chill << "          ";
    cout << "New Formula: " << problem3.new_style_wind_chill << "          ";
    cout << "Difference of Old FROM New: " << problem3.wind_chill_difference << endl;
    
    return 0;
}