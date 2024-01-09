/*
 Name: Rayan Kaleem Mohammed
 Athabasca University ID: 3669212
 Description: Rodent Behaviour list: A list of simillarities and differences of general rodent behaviours
 Date: December 3rd, 2023
*/

/*
  Documentataion for Assignment 2 - Q4

 Program Name: Rodent Behaviour list

 Program Purpose:
   Demonstrates a list of rodents, and their general behaviors with specific traits thet are specific to each one.
   Using overidding methods and child classes this program executes nicely.

 Compile: (assuming MinGW-W64  is running): g++ -o Assignment2Question4 Assignment2Question4.cpp
 Execution (assuming MinGW-W64 is running): .\Assignment2Question4

 Notes: Main must return type int

 Classes: 
 Rodent class: Main class holding all genral behavioral(5) methods that will be examined
 Child Classes: Hamster, Mouse, Gerbil, Guinea Pig - Has specific methods for each of their traits
 
 Variables:
No general variables - but 5 void methods 
sleep()
eat()
Groom()
Movement()
chew()
These all are void and are the examining factors
*/

/*
 Test plan layout:
 Normal case: ( Only 1 case based on no user input):

 Variety of Rodent Behaviours: 

 Rodent - (Mouse Behaviours):

 Mouse sleeping during the day - Nocturnal
 Mouse eating seeds
 Mouse moving quickly and run in sourroundings
 Rodent chewing
 Rodent grooming

 Rodent - (Hamster Behaviours):

 Hamster sleeping during the day - Nocturnal
 Hamster eating seeds
 Hamster moving in digging patterns and excercise wheels
 Rodent chewing
 Rodent grooming

 Rodent - (Gerbil Behaviours):

 Gerbil sleeping during night - Diurnal
 Gerbil eating grains
 Gerbil moving in burrowing patterns
 Rodent chewing
 Rodent grooming

 Rodent - (Guinea Pig Behaviours):

 Guinea Pig sleeping during day and night - Crepuscular creatures
 Guinea Pig eating grass and herbs
 Guinea Pig moving slowly and relaxed
 Rodent chewing
 Rodent grooming

 Other cases - different behaviors could have been examined based on creator

 Discussion:
	This program utilizes a class with various virtual methods of behaviors that will be overriden by specific rodent behaviours.
	The program is set to display the 4 rodents and their comparative behaviours distincly chosen by the creator
	The methods contains specific habits of the rodent in child classes which are displayed when called in main.
	
*/

#include <iostream> // initial declarations
using namespace std;
#include <string> //  declaration for Testing class - user input

class Rodent
{ // Rodent hierarchy class created

public:
	// Default behavioral methods - virtual used for overridden purposes
	virtual void sleep()				// sleep method
	{
		std::cout << " Rodent sleeping" << std::endl;
	};
	virtual void eat()	// eat method
	{
		std::cout << " Rodent eating" << std::endl;
	};
	virtual void Groom() 	// groom method
	{
		std::cout << " Rodent grooming" << std::endl;
	};
	virtual void movement() 	// movement method
	{
		std::cout << " Rodent Moving" << std::endl;
	};
	virtual void chew() 	//chewing method
	{
		std::cout << " Rodent chewing" << std::endl;
	};
};

// Child classes of different rodents - calling main class

class Mouse : public Rodent
{
public:
	// Overidding statements that are different about rodent
	void eat()
	{
		std::cout << " Mouse eating seeds" << std::endl;
	}
	void sleep()
	{
		std::cout << " Mouse sleeping during the day - Nocturnal" << std::endl;
	}
	void movement()
	{
		std::cout << " Mouse moving quickly and run in sourroundings " << std::endl;
	}
};
class Gerbil : public Rodent
{
public:
	// Overidding statements that are different about rodent
	void eat()
	{
		std::cout << " Gerbil eating grains " << std::endl;
	}
	void sleep()
	{
		std::cout << " Gerbil sleeping during night - Diurnal" << std::endl;
	}
	void movement()
	{
		std::cout << " Gerbil moving in burrowing patterns " << std::endl;
	}
};
class Hamster : public Rodent
{
public:
	// Overidding statements that are different about rodent
	void eat()
	{
		std::cout << " Hamster eating seeds" << std::endl;
	}
	void sleep()
	{
		std::cout << " Hamster sleeping during the day - Nocturnal" << std::endl;
	}
	void movement()
	{
		std::cout << " Hamster moving in digging patterns and excercise wheels " << std::endl;
	}
};
class GuineaPig : public Rodent
{
public:
	// Overidding statements that are different about rodent
	void eat()
	{
		std::cout << " Guinea Pig eating grass and herbs" << std::endl;
	}
	void sleep()
	{
		std::cout << " Guinea Pig sleeping during day and night - Crepuscular creatures" << std::endl;
	}
	void movement()
	{
		std::cout << " Guinea Pig moving slowly and relaxed " << std::endl;
	}
};

//  Create main calling instances of each rodent and behaviors 

// All rodents have 2 same behviors which are chewing and grooming as they all do it. But the other 3 behaviors are different amongst them
int main (){
std:: cout << "Variety of Rodent Behaviours: " << std::endl;
std::cout << endl;

Mouse mouse1;
std:: cout << " Rodent - (Mouse Behaviours): " << std:: endl;
std::cout << endl;
mouse1.sleep();
mouse1.eat();
mouse1.movement();		
mouse1.chew();
mouse1.Groom();
std::cout << endl;

Hamster hamster1;
std:: cout << " Rodent - (Hamster Behaviours): " << std:: endl;
std::cout << endl;
hamster1.sleep();
hamster1.eat();
hamster1.movement();		
hamster1.chew();
hamster1.Groom();
std::cout << endl;

Gerbil gerbil1;
std:: cout << " Rodent - (Gerbil Behaviours): " << std:: endl;
std::cout << endl;
gerbil1.sleep();
gerbil1.eat();
gerbil1.movement();		
gerbil1.chew();
gerbil1.Groom();
std::cout << endl;

GuineaPig Guinea1;
std:: cout << " Rodent - (Guinea Pig Behaviours): " << std:: endl;
std::cout << endl;
Guinea1.sleep();
Guinea1.eat();
Guinea1.movement();		
Guinea1.chew();
Guinea1.Groom();
std::cout << endl;
};
