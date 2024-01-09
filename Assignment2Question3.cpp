/* 
 Name: Rayan Kaleem Mohammed
 Athabasca University ID: 3669212
 Description: Elevator movement program - Creating an elevator in bulding and moving it accordingly.
 Date:November 27th, 2023
*/

/*
  Documentataion for Assignment 2 - Q3
 
 Program Name: Elevator movement program 

 Program Purpose:
   Demonstrates a creation of Elevators amongst a N-storey building to move accordingly using 
   floor methods and classes. 

 Compile: (assuming MinGW-W64  is running): g++ -o Assignment2Question3 Assignment2Question3.cpp
 Execution (assuming MinGW-W64 is running): .\Assignment2Question3
 
 Notes: Main must return type int
 
 Classes:
 Elevator Class - Holds different functions of creating moving the elevator in a building. Contains 2 constructors , deconstructor,  1 method and a getter function

 functioons/methods:
 MovingFloor - method that takes an int - responsible for moving elvator in the confined building
 getNumfloors - metho to gte the number of
~Elevator() - deconstructor of class for termination `
  
 Variables:
  Numfloors - int - floor varible used to create building size and manipulate movement of elevator in the building
  floornum - int - stors value of floors tempoarily befor transferring
  floorspace - int - handles the applicability to move elevator in building - sets proper bounds.
	
*/

/*
 Test plan layout:
 Normal case: ( Only 1 case based on no user input):

Scenario 1: 
Elevator Created in a defualt 5 Storey Building. 
Elevator moves to floor 4
Elevator ending: elevator returned to the first floor.

Scenario 2:
Elevator Created in a 8 Storey Building.
Elevator moves to floor 3
Elevator ending: elevator returned to the first floor.

Scenario 3:
Elevator Created in a defualt 5 Storey Building.
Elevator moves to floor 3
Elevator moves to floor 5
Elevator ending: elevator returned to the first floor.

Scenario 4:
Elevator Created in a 12 Storey Building.
Elevator moves to floor 9
17 Floor doesn't exist
Elevator ending: elevator returned to the first floor.

Scenario 5:
Elevator Created in a defualt 5 Storey Building.
Elevator moves to floor 2
Elevator ending: elevator returned to the first floor.

Elevator Created in a 18 Storey Building.
Elevator moves to floor 11
Elevator ending: elevator returned to the first floor.

Other case - There would be other cases based on each creator and choices of elevator and building creations
 
 Discussion:
	This program utilizes a class to operate the creation of elevators with 2 constructors and a set of methods to move them.
	The program uses the class and movingfloor method to create buildings with elevators and dictate it's movement in various scenarios.
	The display is done by creator and is read-only as no input from user.


*/

#include <iostream>								// initial declarations 
using namespace std;
#include <string>							 


class Elevator {		// Elevator class created

private:

int Numfloors; // used by constructors to distinguish number of floors variable

public:

Elevator() : Numfloors(5)  { // initializer list 
	std:: cout << "Elevator Created in a defualt 5 Storey Building. " << std::endl;
};		 // Defined default constructor - creates 5 storey building

Elevator(int floornum) : Numfloors(floornum){ // stores value in floornum and transfers variable to Numfloors
	std:: cout << "Elevator Created in a " << Numfloors << " Storey Building. " << std::endl;
}; // Parameterized constructor that initilizes N floors on the building

// Method for moving floors

void MovingFloor(int floorspace){
	if (floorspace >= 1 && floorspace <= Numfloors){
		std:: cout << "Elevator moves to floor " << floorspace << std::endl;
	}else{
		std::cout << floorspace  << " Floor doesn't exist " << std:: endl;
	}
};

// method for termination - no method acc its a destructor - used when object is out of scope and""Cleaned up".
~Elevator(){
	std:: cout << "Elevator ending: elevator returned to the first floor." << std:: endl; // acts as the finalize method termination statement but wing a destructor 
};

};

int main() {

// Creating 5 different scenarios using 2 given constructors and each will end with termination as the elevator will no longer "be in use" and will be out of scope - printing the terimnation statement

// Scenario 1:
{
	std::cout<< "Scenario 1: " << std::endl;
	Elevator Structure1;			// Created default 5 storey building
	Structure1.MovingFloor(4);		// Moved to floor 4 -triggers termination as object is about to be cleaned
	
}
// Scenario 2
{
	std:: cout << endl;
	std::cout<< "Scenario 2: " << std::endl;
	Elevator Structure2(8);			// Created a custom 8 storey building -paraemetrized constructor
	Structure2.MovingFloor(3);		// Moved to floor 3 -triggers termination as object is about to be cleaned
	
}
//Scenario 3
{
	std:: cout << endl;
	std::cout<< "Scenario 3: " << std::endl;
	Elevator Structure3;			// Created default 5 storey building		// Combining 2 shifts with elevator
	Structure3.MovingFloor(3);		// Moved to floor 3 
	Structure3.MovingFloor(2);		// The right after move to floor 2 - triggers termination as object is about to be cleaned 
	
}		
// Scenario 4
{
	std:: cout << endl;
	std::cout<< "Scenario 4: " << std::endl;
	Elevator Structure4(12);		// Created custom 12 storey building
	Structure4.MovingFloor(9);		// Moved to floor 9 -triggers termination as object is about to be cleaned
	Structure4.MovingFloor(17);		// Moving to floor 17 - doesn't exist - testing floor moving method and triggering termination
	
}
// Scenario 5
{
	std:: cout << endl;
	std::cout<< "Scenario 5: " << std::endl;
	Elevator Structure5;			// Created default 5 storey building
	Structure5.MovingFloor(2);		// Moved to floor 2 
}{
	std::cout << endl;
	Elevator Structure6(18);		// Created custom 18 storey building
	Structure6.MovingFloor(11); 	// Moving to floor 11 - triggering termination
}	// Created a scenario introducing 2 elevators to test creating multiple elevators and its function 

};