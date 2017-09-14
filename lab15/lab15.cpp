//created by: nick ls

//the following algorithm is supposed to simulate madlibs
//user inputs words, and they get a story back out of it

#include <iostream>
#include <string>

using namespace std;

int main() {
    //all these string variables are used in the story as plot points
    string tool_1;      //noun used later in the story
    string tool_2;      //noun #2
    string nurse_1;     //person's name
    string item_1;      //another noun
    string item_2;      //another noun
    string place_1;     //another noun
    
    cout << "For the following 6 inputs, please use only lowercase, letters, and no spaces" << endl;
    
    cout << "Please enter where you are from" << endl;
    cin >> place_1;
    
    cout << "Please enter a Tool you would use normally" << endl;
    cin >> tool_1;
    
    cout << "Please enter another Tool you would use normally" << endl;
    cin >> tool_2;
    
    cout << "Please enter a name you just utterly detest" << endl;
    cin >> nurse_1;
    
    cout << "Please enter an item you would hate to lose" << endl;
    cin >> item_1;
    
    cout << "Please enter an item you would hate to have" << endl;
    cin >> item_2;
    
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