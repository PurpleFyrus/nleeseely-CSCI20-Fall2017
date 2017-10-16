//Created by: Nick LS

//The following algorithm is supposed to simulate madlibs
//User inputs words which are assigned to string variables, and they get a story back out of it using a combination of their 

#include <iostream>
#include <string>                   //This library is used to allow the use of string datatype variables in the algorithm.

using namespace std;

int main() {
    //All these string variables are used in the story as plot points
    string tool_1 = "tool_1"; //This is the first tool used in the story.
    string tool_2 = "tool_2"; //This is the second tool used in the story.
    string nurse_1 = "nurse_1"; //This is the name used in the story for the nurse.
    string item_1 = "item_1"; //This is the first item used in the story.
    string item_2 = "item_2"; //This is the second item used in the story.
    string place_1 = "place_1"; //This is the place used in the story.
    
    cout << "For the following 6 inputs, please use only lowercase, letters, and no spaces" << endl;
    
    cout << "Please enter where you are from" << endl;
    cin >> place_1;                                                                 //User inputs the place here, which is assigned to the corresponding variable.
    
    cout << "Please enter a Tool you would use normally" << endl;
    cin >> tool_1;                                                                  //User inputs a tool word
    
    cout << "Please enter another Tool you would use normally" << endl;
    cin >> tool_2;                                                                  //User inputs one more word for a tool
    
    cout << "Please enter a name you just utterly detest" << endl;
    cin >> nurse_1;                                                                 //User inputs a name of someone they dislike, which is used for the nurse later on.
    
    cout << "Please enter an item you would hate to lose" << endl;
    cin >> item_1;                                                                  //User inputs an item.
    
    cout << "Please enter an item you would hate to have" << endl;
    cin >> item_2;                                                                  //User inputs one more item.
    //Then everything is used here and there among a bunch of string literals to print a story.
    cout << "It was a normal sunny day in " << place_1 << ", when suddenly you " << endl;
    cout << "find that there is a dog lying in the road, injured. You can't possibly" << endl;
    cout << "leave that dog to die, so you quickly load it into your car's back seat " << endl;
    cout << "with your beloved " << item_1 << ". You quickly make your way to the local" << endl;
    cout << "vet hospital where you stumble into the front door to see the Doctor on staff." << endl;
    cout << "The Doctor quickly ushers you into the surgery room where the dog is then " << endl;
    cout << "placed on top of the table. Then the Doctor asks the Nurse " << nurse_1 << " for" << endl;
    cout << "their handy " << tool_1 << " to reach into the already open dog. The Doctor " << endl;
    cout << "pulls with all their might to finally retreive an entrails covered " << item_2 << "." << endl;
    cout << "The Doctor still thinks they haven't gotten everything out so they get out their " << endl;
    cout << tool_2 << " and with it reach DEEP INSIDE to finally pull out the thing most bothering " << endl;
    cout << "the dog. It appeared to be a recently ingested " << item_1 << " but thank goodness it's " << endl;
    cout << "no longer in the dog. The Doctor makes sure to throw the gross blood covered " << item_1 << endl;
    cout << "into the trash and thanks you for your help. " << endl;
    cout << "And they all lived Happily ever after, especially " << nurse_1 << ", they even managed" << endl;
    cout << "to win the lottery! but not you!!!" << endl;
    
    return 0;
}