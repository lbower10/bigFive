/*
 * File: big5Assessment.h
 * Author: Logan Bowers
 * Description: Contains declaration for a
 * Big 5 Assessment class and functions, constructors,
 * etc. used to operate on it
 */

#ifndef BIG5ASSESSMENT_H
#define BIG5ASSESSMENT_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MIN_AGE = 0;
const int NUM_QUESTIONS = 50;
const int NUM_TRAITS = 5;
const int NUM_CHARACTERS = 40;
const int DEFAULT_ANSWER = 3;

enum Traits{
	EXTROVERSION, AGREEABLNESS, CONSCIENT,
	NEUROTICISM, OPENTOEXP
};

class Assessment
{
public:
// Constructors & destructor
Assessment();
Assessment(char* f, char* L, int a, int q[]);
Assessment(const Assessment& a);
virtual ~Assessment() {}

// Set and get functions for private data
void setFirst(char * f){
	strcpy(firstName, f);
}

const char* getFirst() const{
	return firstName;
}

void setLast(char * L){
	strcpy(lastName, L);
}

const char* getLast() const{
	return lastName;
}

void setAge(int a){
	if(a < MIN_AGE)
		age = MIN_AGE;
	else
		age = a;
}

int getAge() const{
	return age;
}

void setAnswer(int a,int index){
	if(a > 5 || a < 1) answers[index] = DEFAULT_ANSWER; 
	else 			   answers[index] = a;
}

int getAnswers(int i) const{
	return answers[i];
}

void setTraits(double nT[]){
	for(int i = 0; i < NUM_TRAITS; i++)
	{
		normTraits[i] = nT[i];
	}
}

const double* getTraits() const{
	return normTraits;
}

// Assessment must have a first and last name to set key
void setKey(){
	char temp1[NUM_CHARACTERS];
	char temp2[NUM_CHARACTERS];
	strcpy(temp1, firstName);
	strcpy(temp2, lastName);
	makeLower(temp1);
	makeLower(temp2);

	strcpy(key, temp2);
	strcat(key, temp1);
}
const char* getKey(){
	return key;
}
void makeLower(char temp[]);
void makeLowUpFirst();
void calcNormTraits();
void assessmentReport();

// Operators 
Assessment& operator=(const Assessment& a);
friend bool operator<(Assessment a1, Assessment a2);
friend bool operator==(Assessment a1, Assessment a2);
friend ostream& operator<<(ostream& out, const Assessment& a);
istream& read(istream& in);
ostream& write( ostream& outBin );
friend istream& operator>>(istream& inStream, Assessment& a);

private:
char firstName[NUM_CHARACTERS];
char lastName[NUM_CHARACTERS];
int age;
int answers[NUM_QUESTIONS];
double normTraits[NUM_TRAITS];
// Key has max length of 80 + 1 for \0
char key[(NUM_CHARACTERS * 2) + 1];
};



#endif