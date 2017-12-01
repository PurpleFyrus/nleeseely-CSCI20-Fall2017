#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MyClass.h"
using namespace std;

/*
 *  This class is to show how to
 *  break our class into an interface and implementation
 *  file. It will set a member variable to 0 on initialization
 *  and output it using the Output() function.
 */
 
int randomNumber(){
   srand(time(0));
   return ((rand()% 10) + 1);
}

// Program starts here
int main() {
  // Create a MyClass Object
  MyClass object;

  //Send a number to the Object
  object.SetNumber(randomNumber());

  // Call the output member function
  object.Output();

  // This ends our program
  return 0;
}