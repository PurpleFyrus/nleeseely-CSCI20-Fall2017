//nick ls lecture 23

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){

    for(int i=97; i<(97+26); i++){
        if(i%2==0){
            cout << static_cast<char>(i);
        }
    }
    
    return 0;
}