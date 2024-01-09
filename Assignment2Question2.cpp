/* 
 Name: Rayan Kaleem Mohammed
 Athabasca University ID: 3669212
 Description: Books data informat- a few books with their information
 Date: November 27th, 2023
*/

/*
  Documentataion for Assignment 2 - Q2
 
 Program Name: Books data informat

 Program Purpose:
   Demonstrates a list of 3 books and their information including, title, author, publisher .. etc.
   It utilizes get/set methods and classes to do so.

 Compile: (assuming MinGW-W64  is running): g++ -o Assignment2Question2 Assignment2Question2.cpp
 Execution (assuming MinGW-W64 is running): .\Assignment2Question2
 
 Notes: Main must return type int
 
 Classes: 
 Book class - holding variables and get/set methods for creating book elemnts of information:
	methods: GET methods and SET methods hold same context but each with either get or set infront based on function 
	title , IsbnNuM, author,  edition,  publisher, year
	get - used for retriving private value variables - so external don't access it 
	set - allows for modifying the value without changing original 


 Variables:
private section - variables used withget/set methods

string title - string variable to hold title         
long long IsbnNuM	- holding ISBN number			
string author - string variable for author
int edition	- integer for edition
string publisher - string for publisher name 
int year - int for year the book was published
*/

/*
 Test plan layout:
 Normal case : ( Only 1 case which is outputting the books of choice)

 The Divergent series: 

 Book 1: 
 Title : Divergent
 Author : Veronica Roth
 Edition : 1
 Publisher : Harper Collins Children Books
 Year Published : 2011
 ISBN Number : 9780062024022

 Book 2: 
 Title : Insurgent
 Author : Veronica Roth
 Edition : 1
 Publisher : Katherine Tegen Books
 Year Published : 2012
 ISBN Number : 9780062024046

 Book 3: 
 Title : Allegiant
 Author : Veronica Roth
 Edition : 1
 Publisher :  Harper Collins Children Books
 Year Published : 2013
 ISBN Number : 9780062287335

 (Other case): This would be different for everyone as others will have diffrent types of books as output
 
 Discussion:
	This program utilizes classes and get/set methods to create a a series of books with their updated information.
	The program will display 3 books (or as many books dependant on the creator) with all the provided information of the private variables.
	This code displays the divergent series of books and takes no input from user.

*/

#include <iostream>								// initial declarations 
using namespace std;
#include <string>						


class Book{             // Book class defined 

private:                // Declarations of attributes with according data types 
string title;                   //  (Under private class)
long long IsbnNuM;				// for larger number use
string author;
int edition;
string publisher;
int year;

public:

// Getter Methods -Retrive private value  
string gettitle() {		
    return title;						 
}
string getauthor() {			
    return author;						 
}
string getpublisher() {			
    return publisher;						 
}
long long  getIsbnNuM() {		
    return IsbnNuM;						 
}					 
int getedition() {			
    return edition;						 
}
int getYear()  {
	return year;
}
 
// Setter Methods - Modify vlaue of the private

void settittle(string newertitle){
	title = newertitle;
}
void setauthor(string newerauthor){
	author = newerauthor;
}
void setpublisher(string newerpublisher){
	publisher = newerpublisher;
}
void setIsbnNuM( long long newerIsbnNuM){ 	// For really long numbers - long long - can strore 64bits rather then 32 like int
	IsbnNuM = newerIsbnNuM;
}
void setedition(int neweredition){
	edition = neweredition;
}
void setYear( int newerYear){
	year = newerYear;
}

};

// Output statements: (Created) 3 books with attributes

int main(){

Book bookA;							// Book A - objects created and setted the values 
bookA.settittle("Divergent");
bookA.setauthor("Veronica Roth");
bookA.setpublisher("Harper Collins Children Books");
bookA.setIsbnNuM(9780062024022); 
bookA.setedition(1);
bookA.setYear(2011);

Book bookB;							// Book B - objects created and setted the values 
bookB.settittle("Insurgent");
bookB.setauthor("Veronica Roth");
bookB.setpublisher("Katherine Tegen Books");
bookB.setIsbnNuM(9780062024046); 
bookB.setedition(1);
bookB.setYear(2012);

Book bookC;							// Book C - objects created and setted the values 
bookC.settittle("Allegiant");
bookC.setauthor("Veronica Roth");
bookC.setpublisher(" Harper Collins Children Books");
bookC.setIsbnNuM(9780062287335); 
bookC.setedition(1);
bookC.setYear(2013);

// Displayed books atrributes - utilized get methods - as they are read-only and work better
std:: cout << " The Divergent series: " << std::endl;
std::cout << endl;
std:: cout <<" Book 1: "<< std::endl;
std:: cout <<" Title : "<< bookA.gettitle() << std::endl;
std:: cout <<" Author : "<< bookA.getauthor() << std::endl;
std:: cout <<" Edition : "<< bookA.getedition() << std::endl;
std:: cout <<" Publisher : "<< bookA.getpublisher() << std::endl;
std:: cout <<" Year Published : " << bookA.getYear() << std::endl;
std:: cout <<" ISBN Number : " << bookA.getIsbnNuM() << std::endl;

std::cout << endl;
std:: cout <<" Book 2: "<< std::endl;
std:: cout <<" Title : "<< bookB.gettitle() << std::endl;
std:: cout <<" Author : "<< bookB.getauthor() << std::endl;
std:: cout <<" Edition : "<< bookB.getedition() << std::endl;
std:: cout <<" Publisher : "<< bookB.getpublisher() << std::endl;
std:: cout <<" Year Published : " << bookB.getYear() << std::endl;
std:: cout <<" ISBN Number : " << bookB.getIsbnNuM() << std::endl;

std::cout << endl;
std:: cout <<" Book 3: "<< std::endl;
std:: cout <<" Title : "<< bookC.gettitle() << std::endl;
std:: cout <<" Author : "<< bookC.getauthor() << std::endl;
std:: cout <<" Edition : "<< bookC.getedition() << std::endl;
std:: cout <<" Publisher : "<< bookC.getpublisher() << std::endl;
std:: cout <<" Year Published : " << bookC.getYear() << std::endl;
std:: cout <<" ISBN Number : " << bookC.getIsbnNuM() << std::endl;

};