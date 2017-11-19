//Created by: Nick LS
//Created on: 11/18/17

/*the following program is supposed to take an input source file, use the data found in it to determine the gpa for however many students
and then output it to an html file. The source file's format has the first and last name on the first line, the number of classes on the second line
and then for each consecutive line a number representing the credit hours of the course and the letter grade the student got. Once the student's classes are
all taken in, the next student (if any) is then done the same for.*/

#include <iostream>
#include <fstream>          //used to define stream objects to direct the flow of data in and out of this program
#include <string>           //used to allow string data type variables
#include <cstring> 
#include <cctype>  
#include <cstdlib> 
#include <iomanip>
using namespace std;

double calculateGradePoints(double credit_hours, char letter_grade){        //The user inputs their class's credit hours and the letter grade they got.
    double temp_grade_points = 0;
    
    if(letter_grade == 'A'){temp_grade_points = 4 * credit_hours;}      //Depending on what letter grade they got is how many credits they got total
    
    else if(letter_grade == 'B'){temp_grade_points = 3 * credit_hours;}
    
    else if(letter_grade == 'C'){temp_grade_points = 2 * credit_hours;}
    
    else if(letter_grade == 'D'){temp_grade_points = 1 * credit_hours;}
    
    else{temp_grade_points = 0 * credit_hours; }      //And if they entered something besides letters A-F they might as well get an F cuz they can't Spell right
    
    return temp_grade_points;   //The total grade points for that class are then returned for later use
}

double calculateGPA(double grade_points, double credit_hours){      //GPA is calculated with the total grade points and the total credit hours
    double temp_gpa = 0.0;
    
    temp_gpa = grade_points / credit_hours;                         //The Calculation is just grade points divided by credit hours
    
    return temp_gpa;                                                //The GPA is then returned for later output.
}

int main() {
    
    ifstream fin;           //An in stream is created
    ofstream fout;          //Along with an out stream
    
    int num_students = 0;
    string student_first_name[10];        //used to store student names.
    string student_last_name[10];       //used to store student's last name.
    double classes[10];               //Used to store student's # of classes taken.
    double temp_hours;      //Used to collect total hours of classes
    char temp_letter;       //Used to determine grade points
    double hours[10];                  //Used to store overall hours for each student.
    char letter_grade[10];          //Used to store the input letter grade.
    double grade_points[10];        //Used to store the then determined grade points for each grade.
    double gpa[10];                 //Used to store the semester gpa.
    
    fin.open("source.txt");     //We first open the stream for the source file
    
    int i = 0;
    
    while (!fin.eof()){
        
        fin >> student_first_name[i];       //Takes in the first name
        fin >> student_last_name[i];        //Then takes in the last name
        fin >> classes[i];                  //Then takes in the number of classes the student of the iteration is taking
        
            for (int j = classes[i]; j > 0; j--){       //This then loops enough times to take in the input of each class
                fin >> temp_hours;          //The hours are taken in for the class
                fin >> temp_letter;         //Then the letter grade is taken in for the class
                
                grade_points[i] = grade_points[i] + calculateGradePoints(temp_hours, temp_letter);  //Then the grade points based on the letter grade are calculated and added to total grade points for this student.
                hours[i] = hours[i] + temp_hours;           //Then the hours of the class are added to the total hours for this student.
            }
            
        gpa[i] = calculateGPA(grade_points[i], hours[i]); //Then finally using the grade points, and hours the GPA is calculated for the iteration's student.
        
        num_students = num_students + 1;    //This is a counter that counts how many students are in the source file
        ++i;
    }

    fin.close();    //We then close the source file since we dont need it anymore
    
    fout.open("output.html");       //Then we open the output file
    
    fout << "<html>" << endl;       //Start the html formatting

    
    for (int i = 0; i < num_students - 1; i++) {                                 //loops through all class units and grades and outputs them to HTML file
        fout << "<p>" << "Student Name: " << student_first_name[i] << " " << student_last_name[i] << "</p>" << endl;                           //outputs student name to HTML file
        fout << "<p>" << "GPA: " << setprecision(3) << gpa[i] << "</p>" << endl;  //outputs header for proceeding grades (and number of classes) to HTML file
    }
    
    fout << "</html>" << endl;      //And then we end the html formatting
        
    fout.close();                   //And finally we close the html file to finish.
    
    return 0;
    
}