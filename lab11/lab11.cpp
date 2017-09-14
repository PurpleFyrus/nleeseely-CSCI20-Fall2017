//Created By: Nick LS
//Created on: 8-24-2017
//Purpose of Algorithm: To compare user input numbers to a randomly generated number, and tell
//the user to keep guessing until the user guesses right. Also take into account everytime the
//user guesses wrong and give thema final score of 1 out of 10.



/* First state your variables

    Randomly Generated Number
    User Input Number
    High Boundary Number
    Low Boundary Number
    User Tries Tally Number
    
Then take into account all possible user inputs
    1.  User inputs the correct number
    2.  User inputs a number outside the boundary numbers
    3.  User inputs the wrong number within the boundary numbers
    
Then decide what happens for each instance
    1.  User is greeted with a "You win!" expression and app ends
    2.  User is greeted with a "You need to pick a valid number between Boundary Numbers A & B" and asks for a new guess
    3.  User's number is compared to the random number and then:
        a.  If the input number is Higher than the random number output "Go lower!" and subtract 1 from the 10 points tally
        b.  If the input number is Lower than the random number output "Go higher!" and subtract 1 from the 10 points tally 
    4.  Also need to take into account when user's Tally Number reaches 0, by outputting "Game over" and then restart the loop
        
*/
