/*
 * File: big5Assessment.cpp
 * Author: Logan Bowers
 * Description: Contains code for functions used to operate
 * on a Big 5 Assessment class
 */

#include "big5Assessment.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * assessmentReport: Displays a report of an assessment
 * 	in a neat table format
 * Parameters: None
 * Returns: Nothing
 */
void Assessment::assessmentReport()
{
	cout << setw(55) << "Last Name   First Name    Age      E     A     C     N     O\n";
	cout << setfill('-') << setw(63) << "-" << setfill(' ') << endl;
	cout << setw(12) << left << this->lastName << setw(14) << this->firstName << setw(6) <<
	this->age << "  ";// << setw(4); //<< "1" << setw(4) << "2" << setw(4) << "3" << setw(4)
	//<< "4" << setw(4) << "5" << endl;
	for(int i = 0; i < NUM_TRAITS; i++)
	{
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(1);
		cout << setw(4) << this->normTraits[i] << "  ";
	}
	cout << endl;
}

/*
 * makeLower: Lowercases a c-string
 * Parameters: One c-string temp
 * Precondition: First and last name have already been set
 * Returns: Nothing
 */
void Assessment::makeLower(char temp[])
{
	int length = strlen(temp);
	for(int i = 0; i < length; i++)
	{
		temp[i] = tolower(temp[i]);
	}
}

/*
 * makeLowUpFirst: lowercases cstring and
 * 	uppercases first char
 * Parameters: One cstring temp
 * Precondition: Firstname and last already set
 * Returns: Nothing
 */
void Assessment::makeLowUpFirst()
{
	int length1 = strlen(this->firstName);
	int length2 = strlen(this->lastName);
	for(int i = 0; i < length1; i++)
	{
		this->firstName[i] = tolower(this->firstName[i]);
	}
	for(int k = 0; k < length2; k++)
	{
		this->lastName[k] = tolower(this->lastName[k]);
	}

	this->firstName[0] = toupper(this->firstName[0]);
	this->lastName[0] = toupper(this->lastName[0]);
}

/*
 * operator<: compares keys for two assessments 
 * Parameters: Two assessments
 * Returns: true if if a1 firstName < a2 firstName,
 * else false
 */
bool operator<(Assessment a1, Assessment a2)
{
	return (strcmp(a1.key,  a2.key) < 0);
}

/*
 * operator==: compares keys for two assessments
 * Parameters: Two assessments
 * Returns: True if first names are ==, else false
 */
bool operator==(Assessment a1, Assessment a2)
{
	return (strcmp(a1.key, a2.key) == 0);
}

/*
 * operator<<: Prints an assessment
 * Parameters: output stream ref. out, const Assessment
 * 	ref. a
 * Returns: output stream ref. out
 */
ostream& operator<<(ostream& out, const Assessment& a)
{
	out << a.firstName << " " << a.lastName << " ";

	out << a.age << endl;
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		out << a.answers[i] << " ";
	}
	out << endl;
	//out << a.key << endl;
	return out;
}


// Default constructor
Assessment::Assessment()
{
	firstName[0] = '\0';
	lastName[0] = '\0';
	age = 0;
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		answers[i] = 0;
	}
	for(int k = 0; k < NUM_TRAITS; k++)
	{
		normTraits[k] = 0.0;
	}
	key[0] = '\0';
}

/* 
 * Four argument constructor: Sets all priv. data members
 * Parameters: char* for first and last name,
 * 	int for age, and array for questions
 */
Assessment::Assessment(char* f, char* L, int a, int q[])
{
	setFirst(f);
	setLast(L);
	setAge(a);
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		setAnswer(q[i], i);
	}
	setKey();
}


/* 
 * Copy constructor: Performs a deep copy of an assessment
 * Parameters: const ref. to an assessment 
 */
Assessment::Assessment(const Assessment& a)
{
	strcpy(this->firstName, a.firstName);
	strcpy(this->lastName, a.lastName);
	this->age = a.age;
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		this->answers[i] = a.answers[i];
	}
	for(int k = 0; k < NUM_TRAITS; k++)
	{
		this->normTraits[k] = a.normTraits[k];
	}
	strcpy(this->key, a.key);
}


/* Assignment operator: assigns one assessment
 * 	to another
 * Parameters: const ref. to an assessment
 * Returns: invoking object back with data
 * 	from parameter copied into it
 */
Assessment& Assessment::operator=( const Assessment& a)
{
	strcpy(this->firstName, a.firstName);
	strcpy(this->lastName, a.lastName);
	this->age = a.age;
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		this->answers[i] = a.answers[i];
	}
	
	for(int k = 0; k < NUM_TRAITS; k++)
	{
		this->normTraits[k] = a.normTraits[k];
	}
	strcpy(this->key, a.key);
	return *this;
}

/*
 * read: Reads data from binary file
 * Parameters: an istream& 
 * Returns: an istream
 */
istream& Assessment::read(istream& inBin)
{
	inBin.read( (char*)this, sizeof(Assessment) );

	return inBin;
}

/*
 * write: Writes data to a binary file
 * Parameters: an ostream&
 * Returns: an ostream
 */
ostream& Assessment::write( ostream& outBin )  
{
	
	outBin.write( (char*)this, sizeof(Assessment) );
   return outBin;
}

/*
 * operator>>: reads in assessment data
 * Parameters: an istream& and an Assessment&
 * Returns: an istream 
 */
istream& operator>>( istream& in,  Assessment& a)
{
	cout << "Last name: ";
	in >> a.firstName;
	cout << "First name: ";
	in >> a.lastName;
	
	
	cout << "Age: ";
	in >> a.age;
	cout << "50 question answers: ";
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		in >> a.answers[i];
	}
	return in;
}

/*
 * calcNormTraits: calculates an assessment's
 * 	normalized traits
 * Parameters: None
 * Precondition: Answers have been read in from assessment file
 * Postcondition: Invoking object's normalized traits have been calculated
 * Returns: Invoking object
 */
void Assessment::calcNormTraits()
{
	double extrov = 20+answers[0]-answers[5]+answers[10]-answers[15]
	+answers[20]-answers[25]+answers[30]-answers[35]+answers[40]-answers[45];
	
	double agreeable = 14-answers[1]+answers[6]-answers[11]+answers[16]-answers[21]
	+answers[26]-answers[31]+answers[36]+answers[41]+answers[46];
	
	double conscient = 14+answers[2]-answers[7]+answers[12]-answers[17]
	+answers[22]-answers[27]+answers[32]-answers[37]+answers[42]+answers[47];
	
	double neuro = 38-answers[3]+answers[8]-answers[13]+answers[18]-answers[23]
	-answers[28]-answers[33]-answers[38]-answers[43]-answers[48];
	
	double OTE = 8+answers[4]-answers[9]+answers[14]-answers[19]+answers[24]
	-answers[29]+answers[34]+answers[39]+answers[44]+answers[49];

	this->normTraits[EXTROVERSION] = (extrov + 10) / 10;
	this->normTraits[AGREEABLNESS] = (agreeable + 10) / 10;
	this->normTraits[CONSCIENT] = (conscient + 10) / 10;
	this->normTraits[NEUROTICISM] = (neuro + 10) / 10;
	this->normTraits[OPENTOEXP] = (OTE + 10) / 10;
}