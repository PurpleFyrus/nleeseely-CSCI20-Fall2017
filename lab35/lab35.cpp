//Created by: Nick LS
//Created on: 10/24/2017

/*  The following file is designed to act as just a class declaration and definition 
so that it may be used in another file later on. It has the ability to take in values in the form
of Fahrenheit, Celsius and Kelvin, store them internally, and output them in any of those types
as well later. It has a print function and finally has 2 constructors to assign the value of 0 if
not value is given at the start and if a value is given at the start it assigns that to the variable
that is held internally. */

#include<iostream>
using namespace std;

class TemperatureConverter{                             //Class that we intend to use/make
    private:
        double kelvin_; //variable everything operates around
    public:
        TemperatureConverter();
        TemperatureConverter(double kelvinValue);
        
        void SetTempFromKelvin(double kelvinValue);
        double GetTempFromKelvin();
        
        void SetTempFromCelsius(double celsiusValue);
        void SetTempFromFahrenheit(double fahrenheitValue);
        
        double GetTempAsCelsius();
        double GetTempAsFahrenheit();
        
        void PrintTemperatures();
};

TemperatureConverter::TemperatureConverter(){
    kelvin_ = 0;            //Constructor that stores the value 0 in kelvin_ 
    return;
}

TemperatureConverter::TemperatureConverter(double kelvinValue){
    if(kelvinValue >= 0){       //Constructor that stores the value used from the start during declaration in kelvin_
        kelvin_ = kelvinValue;
    }
    else{
        cout << "Issue with Constructor, value inserted less than 0" << endl;           //If the input is less than 0 it won't work
    }
    return;
}

void TemperatureConverter::SetTempFromKelvin(double kelvinValue){                       //Setter for input of Kelvin into variable Kelvin
    if(kelvinValue >= 0){       //Stores the input value into the private variable, but only if it's not less than 0
        kelvin_ = kelvinValue;
    }
    else{
        cout << "Issue with Kelvin Setter, value inserted less than 0" << endl;
    }
    return;
}

double TemperatureConverter::GetTempFromKelvin(){                       //Getter for value stored in kelvin_.
    return kelvin_;
}

void TemperatureConverter::SetTempFromCelsius(double celsiusValue){                       //Setter for input of Celsius into variable Kelvin.
    if(celsiusValue >= -273.15){            //Only executes if input is not less than -273.15.
        kelvin_ = celsiusValue + 273.15;    //This is the calculation to convert from Celsius (the input) to Kelvin, and then store it into the private variable.
    }
    else{
        cout << "Issue with Celsius Setter, value inserted less than -273.15 degrees" << endl;
    }
    return;
}

void TemperatureConverter::SetTempFromFahrenheit(double fahrenheitValue){                       //Setter for input of Fahrenheit into variable Kelvin.
    if(fahrenheitValue >= -459.67){         //Only executes if the input is not less than -459.67.
        kelvin_ = (5 * (fahrenheitValue - 32) / 9) + 273.15;    //This is the calculation to convert from Fahrenheit (the input) to Kelvin, and then store it into the private varible.
    }
    else{
        cout << "Issue with Fahrenheit Setter, value inserted less than -459.67 degrees" << endl;
    }
    return;
}

double TemperatureConverter::GetTempAsCelsius(){        //Getter for value of kelvin_ in the units of Celsius.
    return (kelvin_ - 273.15);      //Executes conversion rate from Kelvin to Celsius.
}

double TemperatureConverter::GetTempAsFahrenheit(){     //Getter for value of kelvin_ in the units of Fahrenheit.
    return ((GetTempAsCelsius() * 9) / 5 + 32);     //Executes conversion rate from Kelvin to Fahrenheit.
}

void TemperatureConverter::PrintTemperatures(){         //Prints via cout all the values of the variable kelvin_ in each degree unit type.
    cout << "Kelvin: " << GetTempFromKelvin() << endl;
    cout << "Celsius: " << GetTempAsCelsius() << endl;
    cout << "Fahrenheit: " << GetTempAsFahrenheit() << endl;
    return;
}