/* 
 Name: Rayan Kaleem Mohammed
 Athabasca University ID: 3669212
 Description: Animal sound generator with variuos descriptions
 Date: November 25th, 2023
*/

/*
  Documentataion for Assignment 2 - Q1
 
 Program Name: Animal sound generator

 Program Purpose:
   Demonstrates a layout of 4 animals and statements of their sound and identity as an animal. Also,
   includes a testing source where user chooses an animla and it displays their data and sound information

 Compile: (assuming MinGW-W64  is running): g++ -o Assignment2Question1 Assignment2Question1.cpp
 Execution (assuming MinGW-W64 is running): .\Assignment2Question1
 
 Notes: Main must return type int
 
 Classes: 
 Animal class - main class which holds the default sound method and identity constructor of animals.
 child classes: These classes are specific animals which contain a sound and defualt constroctor that override main class for each sound
 Pig, Sheep, Duck, Cow
 AnimalTest class - Testing class to create animal biodata based on user input

 Variables:
 Functions/methods - sound(), Testcase(), individual constructors
 sound() = Hold no data type as a void, and prints sound of specific animal .
 Testcase() =  void function - Asks user to enter letter based on animal and creates correct methods and bio data of said animal
 

*/
/*
 Test plan layout:



 Normal case: (List of animals with sounds with AnimalTest user input)
 This set of code is what stays neutral everytime we run the code 

 I am an animal
 I am a Pig
 oink

 I am an animal
 I am a Cow
 moo

 I am an animal
 I am a Duck
 quack

 I am an animal
 I am a Sheep
 baah

 Enter Which Animal (p = Pig , d = Duck, c = Cow, s = Sheep):

 This is where user input happens:

 Bad Case 1 (Numerical input):
 I am an animal
 I am a Pig
 oink

 I am an animal
 I am a Cow
 moo

 I am an animal
 I am a Duck
 quack

 I am an animal
 I am a Sheep
 baah

 Enter Which Animal (p = Pig , d = Duck, c = Cow, s = Sheep): 3
 - Terminates

 Bad Data case 2 (multiple letters):
  I am an animal
 I am a Pig
 oink

 I am an animal
 I am a Cow
 moo

 I am an animal
 I am a Duck
 quack

 I am an animal
 I am a Sheep
 baah

 Enter Which Animal (p = Pig , d = Duck, c = Cow, s = Sheep): ss
 -terminates

 Bad Data case 3 (Non -alpha input check)
 I am an animal
 I am a Pig
 oink

 I am an animal
 I am a Cow
 moo

 I am an animal
 I am a Duck
 quack

 I am an animal
 I am a Sheep
 baah

 Enter Which Animal (p = Pig , d = Duck, c = Cow, s = Sheep): g5(
	-terminates

Successful case :
 I am an animal
 I am a Pig
 oink

 I am an animal
 I am a Cow
 moo

 I am an animal
 I am a Duck
 quack

 I am an animal
 I am a Sheep
 baah

 Enter Which Animal (p = Pig , d = Duck, c = Cow, s = Sheep): p
 I am an animal
 I am a Pig
 oink
 		

 Discussion:
 	This program utilizes classes to organize the diffrent animal structures and elements for the sound() methods.
	This code has a genral table for 4 animals - pre coded with their identity and sound. 
	The input only allows the use for the 4 letters to test. It doesn't accept numbers, multiple letters or other characters.
	In other words, It is a general output with a 4 letter binding for user to test.
*/

#include <iostream>								// initial declarations 
using namespace std;
#include <string>							//  declaration for Testing class - user input 


class Animal {	// Animal class

public:

 virtual void sound() { 	// Default sound method - virtual used for overridden purposes
	std::cout << "An animal makes a sound based on the animal that it is." << endl;
}

Animal() {	// default Constructor
	std::cout << " I am an animal" << endl;	// default constructor output
}
};

// After  creating the base class - move onto child classes with inheritance:

class Cow: public Animal{		// calling parent class with each animal 

public:
Cow(){	// default Constructor with intended output sound
	std::cout << " I am a Cow" << endl;
}

void sound()  {					//default sound methods for each child class
	std::cout << " moo" << endl;
	std::cout << endl;
}
};

class Duck: public Animal{

public:
Duck(){	// default Constructor with intended output sound
	std::cout << " I am a Duck" << endl;
}
void sound() {
	std::cout << " quack" << endl;
	std::cout << endl;
}
};

class Sheep: public Animal{

public:
Sheep(){	// default Constructor with intended output sound
	std::cout << " I am a Sheep" << endl;
}

void sound()  {
	std::cout << " baah" << endl;
	std::cout << endl;
}
};

class Pig: public Animal{

public:
Pig(){	// default Constructor with intended output sound
	std::cout << " I am a Pig" << endl;
}

void sound()  {
	std::cout << " oink" << endl;
	std::cout << endl;
}

};

class Animaltest {			// Animal Test class 
public:

void TestCase(){ 		// Test case method function 
	string Case;		// initialize a string var
	std::cout << " Enter Which Animal (p = Pig , d = Duck, c = Cow, s = Sheep): ";	// Ask user for animal
	std:: cin >> Case;

	if (Case == "p"){				// Series of if-else statements to output the desired constructed animal and its sound
		Pig p;						
		p.sound();
	}else if (Case == "d"){
		Duck d;
		d.sound();
	}else if(Case == "c"){
		Cow c;
		c.sound();
	}else if (Case == "s"){
		Sheep s;
		s.sound();
	}
}

};

int main(){

Pig pignoise;	// instance variables created accordingly 
pignoise.sound();	//Calling overidden method for  outputting animal sounds
Cow cownoise;		
cownoise.sound();
Duck ducknoise;
ducknoise.sound();
Sheep sheepnoise;
sheepnoise.sound();

Animaltest Test;		//  Calling Testing class - AnimalTest
Test.TestCase();

};