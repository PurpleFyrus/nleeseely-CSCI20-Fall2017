//Created by: Nick LS
//Created on: 10/31/17

/*The following is just a class definition and its later use. It's functions include the ability to 
print the elements in an array, find the minimum and maximum value in the array, find the sum of the 
elements in the array, find the number of even and odd numbers in the array, search for a value in the array
and finally tell you if the values in the array are sorted. */

#include <iostream>
using namespace std;

class ArrayTools{                                                      
    
    public:
        ArrayTools();
        ArrayTools(int inputArray[], int inputArraySize);
        void Print();
        int Find_min(int lowerIndex, int higherIndex);
        int Find_max(int lowerIndex, int higherIndex);
        int Find_sum();
        int Num_even();
        int Num_odd();
        int Search(int desiredValue);
        int Is_sorted();
        
    private:
        int my_array_size = 10;                                   
        int my_array[10];                                            
    
};

ArrayTools::ArrayTools(){
    my_array[0] = 0;
    my_array[1] = 0;
    my_array[2] = 0;
    my_array[3] = 0;
    my_array[4] = 0;
    my_array[5] = 0;
    my_array[6] = 0;
    my_array[7] = 0;
    my_array[8] = 0;
    my_array[9] = 0;
    return;
}

ArrayTools::ArrayTools(int inputArray[], int inputArraySize) {            
    for (int i = 0; i < inputArraySize; i++) {
        my_array[i] = inputArray[i];
    }
    my_array_size = inputArraySize;
}

void ArrayTools::Print() { 
    for (int i = 0; i < my_array_size; i++) {                     
    cout << my_array[i] << endl;
    }
    return;
}

int ArrayTools::Find_min(int lowerIndex, int higherIndex) {     

    int lowerValue = my_array[lowerIndex];            

    for (int i = lowerIndex; i <= higherIndex; i++) {          

        if (my_array[i] < lowerValue) {                 
            lowerValue = my_array[i];                    
        }
        }
    
    return lowerValue;                        
}




int ArrayTools::Find_max(int lowerIndex, int higherIndex) {     

    int higherValue = my_array[lowerIndex];          
    
    for (int i = lowerIndex; i <= higherIndex; i++) {        

        if (my_array[i] > higherValue) {           
            higherValue = my_array[i];                
        }
        }
    
    return higherValue;         
}




int ArrayTools::Find_sum() {                        

    int sum = 0;                                   
    
    for (int i = 0; i < my_array_size; i++) {                         
        sum += my_array[i];
    }

    return sum;                    
}




int ArrayTools::Num_even() {           
    
    int evenCount = 0;                  
    
    for (int i = 0; i < my_array_size; i++) {      
        
        if ((my_array[i] % 2) == 0) {         
        ++evenCount;
        }
        
    }  
    return evenCount;  
}
    
    


int ArrayTools::Num_odd() {               
    
    int oddCount = 0;              
    
    for (int i = 0; i < my_array_size; i++) {                  
        
        if ((my_array[i] % 2) == 1) {               
        ++oddCount;
        }
        
    }
    return oddCount;               
}




int ArrayTools::Search(int desiredValue) {        
    
    int foundLocation = -1;                                 
    
    for (int i = 0; i < my_array_size; i++) {                  
        if (desiredValue == my_array[i]) {                       
        foundLocation = i;                                          
        break;                                                
        }
        else {
        }
        
    }
    
    return foundLocation;                                     
}




int ArrayTools::Is_sorted() {                         
    
    int isItSorted = 0;                                          
    int lowerValue = my_array[0];                                         
    
    for (int i = 0; i < my_array_size; i++) {                               
        if (my_array[i] >= lowerValue) {                                   
            lowerValue = my_array[i];                                      
        }
        else {                                                                
            isItSorted = 1;
        }
    }
    return isItSorted;                                                      
}

int main() {
    
int da_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int searched_value = 6;


ArrayTools fudge(da_array, 10);

fudge.Print();

cout << "Max: " << fudge.Find_max(0, 9) << endl;
cout << "Min: " << fudge.Find_min(0, 9) << endl;
cout << "Sum: " << fudge.Find_sum() << endl;
cout << "Number of even Numbers: " << fudge.Num_even() << endl;
cout << "Number of odd Numbers: " << fudge.Num_odd() << endl;
cout << "The value " << searched_value << " is stored in index: " << fudge.Search(searched_value)+1 << endl;

if (fudge.Is_sorted() == 0) {
    cout << "The array is sorted" << endl;
}
else{
    cout << "The array is not sorted" << endl;
}



return 0;
}