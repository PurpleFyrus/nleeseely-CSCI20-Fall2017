//Nick LS
//Created on: 10/3/17

//assignment 2.0, This algorithm is solely in respect to a race and the attributes of the race and manipulating them.
/*The first part is taking in user input in the form of a runner's time for a race, the race distance, and the time of the person who placed first.
Then that information is manipulated so that the runner's speed in both Feet per second and Meters per second are output, then the difference in time between the runner and the person who placed first.
Finally the splits for the runner are output of each quarter of a mile increment, of the total distance.
It is assumed that the input is in miles and the times are minutes, then the remaining seconds.*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class runner_info {                                                             //Class used in this algorithm for later use with the runner's input
        private:
            double mins_;                                                       //Runner's Minutes
            double secs_;                                                       //Runner's remaining seconds after minutes.
            double race_distance_miles_;                                        //The distance of the race in miles.
            double first_place_time_;                                           //The time of the person who placed first in seconds (that includes minutes).
        public: //these are all declarations, definitions of the functions come after the class body
            void SetMins(double input_mins);                                    //Mutator function to assign a new value to the private variable mins_
            void SetSecs(double input_secs);                                    //Mutator function to assign a new value to the private variable secs_
            void SetRaceDistanceMiles(double input_miles);                      //Mutator function to assign a new value to the private variable race_distance_miles_
            void SetFirstPlaceTime(double input_time);                          //Mutator function to assign a new value to the priavte variable first_place_time_
            
            double GetRaceDistanceFeet();                                       //Accessor function used to convert and call the distance of the race in feet
            double GetRaceDistanceMeters();                                     //Accessor function used to convert and call the distance of the race in meters
            double GetRaceSpeedInFeet();                                        //Accessor function used to calculate and call the speed of the runner in feet per second
            double GetRaceSpeedInMeters();                                      //Accessor function used to calculate and call the speed of the runner in meters per second
            
            double GetFirstPlaceTime();                                         //Accessor function used to call the value of the private variable first_place_time_
            double GetMins() const;                                             //Accessor function used to call the value of the private variable mins_
            double GetSecs() const;                                             //Accessor function used to call the value of the private variable secs_
            
            double DetermineFullSecs(double input_mins, double input_secs);     //Function used to calculate the numbers of total seconds given the inputs of both minutes and seconds
            void Print();                                                       //Function used to cout all the results for the user to bask in the glory of the output
};

void runner_info::SetMins(double input_mins){
    mins_ = input_mins;
    return;
}

void runner_info::SetSecs(double input_secs){
    secs_ = input_secs;
    return;
}

void runner_info::SetRaceDistanceMiles(double input_miles){
    race_distance_miles_ = input_miles;
    return;
}

void runner_info::SetFirstPlaceTime(double input_time){
    first_place_time_ = input_time;
    return;
}

double runner_info::GetRaceDistanceFeet(){
    return race_distance_miles_ * 5280.0;       //Converts miles to feet
}

double runner_info::GetRaceDistanceMeters(){
    return race_distance_miles_ * 1609.34;      //Converts miles to meters
}

double runner_info::GetRaceSpeedInFeet(){
    return GetRaceDistanceFeet() / ((mins_ * 60) + secs_);      //Calculates speed by dividing total distance in feet by total time in seconds
}

double runner_info::GetRaceSpeedInMeters(){
    return GetRaceDistanceMeters() / ((mins_ * 60) + secs_);    //Calculates speed by dividing total distance in meters by total time in seconds
}

double runner_info::GetFirstPlaceTime(){                        
    return first_place_time_;
}

double runner_info::GetMins() const{
    return mins_;
}

double runner_info::GetSecs() const{
    return secs_;
}

double runner_info::DetermineFullSecs(double input_mins, double input_secs){            //Calculates total time by converting minutes to seconds and then adding that to overflow of seconds
    return (input_mins * 60) + input_secs;
}

void runner_info::Print(){                                      //everything is output 
    cout << "Runner's Time: " << mins_ << ":" << secs_ << endl;
    cout << "Race Distance in Miles: " << race_distance_miles_ << endl;
    cout << "Runner's Speed in Feet Per Second: " << GetRaceSpeedInFeet() << endl;
    cout << "Runner's Speed in Meters Per Second: " << GetRaceSpeedInMeters() << endl;
    cout << "Difference in time between first place and runner: " << abs(first_place_time_ - DetermineFullSecs(mins_, secs_)) << " seconds" << endl;      //abs() is used to ensure a positive number because why not
    return;
}

int main(){
    double runner_minutes           = 0.0;              //These are all place holder variables for user input to be then thrown into class specific functions
    double runner_seconds           = 0.0;
    double first_place_time_minutes = 0.0;
    double first_place_time_seconds = 0.0;
    double race_distance_miles      = 0.0;
    
    runner_info race1;                                  //Declaration of a new object using class runner_info.
    //Obviously what follows is the user input section
    cout << "Please enter race distance in miles: " << endl;
    cin >> race_distance_miles;
    
    cout << "Please enter runner's minutes ran: " << endl;
    cin >> runner_minutes;
    
    cout << "Please enter runner's seconds ran: " << endl;
    cin >> runner_seconds;
    
    cout << "Please enter first place's minutes ran: " << endl;
    cin >> first_place_time_minutes;
    
    cout << "Please enter first place's seconds ran: " << endl;
    cin >> first_place_time_seconds;
    
    //These next 10 lines are behind the scenes calculations for the purpose of finding answers using the tools provided by the runner_info object.
    race1.SetRaceDistanceMiles(race_distance_miles);
    race1.SetMins(runner_minutes);
    race1.SetSecs(runner_seconds);
    race1.SetFirstPlaceTime(race1.DetermineFullSecs(first_place_time_minutes, first_place_time_seconds));
    
    cout << endl;
    race1.Print();
    
    double number_of_quarter_miles = (race1.GetRaceDistanceFeet() / 1320);                                      //Divides the Race's distance in feet by 1320 feet (which is 1/4th of a mile) that way we know how many splits to output
    double time_split = race1.DetermineFullSecs(race1.GetMins(), race1.GetSecs()) / number_of_quarter_miles;    //Divides the runner's total time in seconds by the number of splits necessary so they can be accurate in their output
    
    cout << endl;
    cout << "Here are the Splits for the race for every quarter of a mile: " << endl;
    
    for (int i=0; i < number_of_quarter_miles; i++){        //this loop iterates enough times that there can be a split output for every quarter of a mile in the race's total distance.  
        cout << "Split #" << i + 1 << ": ";
        cout << time_split * (i + 1) << " seconds for " << (i+1) << " quarter(s) of a mile." << endl;       //Each split is just an addition of the total time divided by the number of quarter of miles in the race's total distance.
    }
    
    return 0;
}