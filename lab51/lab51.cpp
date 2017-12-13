#include <iostream> 
#include <iostream> 
#include <cstring> 
using namespace std;   

int main() {
    int nameLength = 0;
    char *name = new char[20];      //Here we create a new pointer that is pointing to a new character we created just for it. We needed to give the character array a size, otherwise it wouldn't run.

    cout << "Please enter a 10 letter word or less" << endl;
    cin >> name;                //Has the user store a word in the character array "name"

    char *head  = name;        //assigns the memory locations "name" is pointing to, to the pointer "head"
    char *tail = name;         //assigns the memory locations "name" is pointing to, to the pointer "tail"
    nameLength = strlen(name); //assigns the length of the word stored in the variable "name" is pointing to, to "nameLength". Had to fix by removing the asterick

    cout << "Your word is " << name << endl;        //needed to replace firststr with the pointer "name"

    if (nameLength<10)          //executes only if the word is less than 10 characters
    {
         while (*head != '\0')  //While the pointer head is not holding the value '\0' it will keep looping
         {
                cout << *head;  //It outputs what is stored in the first location pointer "head" is pointing to,
                head++;         //And then adds 1 to head so that it will take a look at the next character in the character array.
         }
     }
     else
     {
          cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;      //This occurs if the word input is not less than 10
     }

     cout << endl;

     tail = &name[strlen(name) - 1];                                //the pointer tail is assigned the memory location of the last character in the character array "name"

     if (nameLength < 10)               //If the "name" is less than 10 characters long
     {
          while (tail != name - 1)          //A while loop initiates, as long as the pointer isn't referencing to the first character in the character array "name"
          {
                 cout << *tail;         //It outputs the character in the current memory location being referenced (starting from the end of the character array "name")
                 tail--;                //And then works it way to the first character in the variable "name".
          }
     }
     cout << endl;

     head = name;                       //The pointer "head" is then re-assigned "name" once more 
     tail = &name[strlen(name) - 1];    //The pointer "tail" is then assigned the last character in the array "name"

     head++;                            //It then adds 1 to head, changing it to the contents sans the first character
     tail--;                            //It subtracts 1 from tail, changing it to the second to last character in the array "name"

     if (*head == *tail)                //If they match up, they are a palindrome
     {
         cout << "It is an palindrome!" << endl;
     }
     else                               //If not, then they are not obviously. 
     {
         cout << "It is not an palindrome" << endl;
     }
     
     /*The biggest error would be the logical error of forgetting the fact that it needs to take into account the entire word, not just the middle, because words
     like "motor" can count as a palindrome even though it is not. There would need to be a loop that does what the two loops do, but compare the values each iteration
     and if ever there is a loop iteration where the values don't match up, then it would not count as a palindrome. */

     return 0; 
}