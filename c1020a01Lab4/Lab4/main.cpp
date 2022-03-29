/*
 * File:main.cpp
 * Author: Logan Bowers
 * Description: Main file for Lab 4: Big 5 Assessment
 * 	This program implements a Big 5 Personality Assessment
 * 	using a templated Binary Search Tree
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include "big5Assessment.h"
#include "node.h"
#include "position.h"
#include "binarySearchTree.h"

using namespace std;

const char FILE_NAME[] = "assessments.bin";

/*
 * reportAssessment: Reports on a Big 5 Assessment
 * Paramaters: Pointer to a BinarySearchTree
 * Returns: Nothing
 */
void reportAssessment(BinarySearchTree<Assessment>* );

/*
 * addAssessment: Adds and assessment to the file
 * Parameters: None
 * Returns: Nothing
 */
void addAssessment(BinarySearchTree<Assessment>*);

/*
 * writeTree: Saves assessment data and writes it
 * 	back to file pre-order
 * Parameters: A pointer to a tree
 * Returns: Nothing
 */
void writeTree(BinarySearchTree<Assessment>*);

/*
 * removeAssessment: Removes an assessment from the tree
 * Parameters: A pointer to a tree
 * Returns: Nothing
 */
void removeAssessment(BinarySearchTree<Assessment>*);

int main()
{
	Assessment a;
	BinarySearchTree<Assessment> tree;
	ifstream inBin;
	char selection;
	string choice;
	cout << "Welcome to the Big 5 Report!\n";

	inBin.open(FILE_NAME, ios::in | ios::binary);

	if( ( !inBin.fail() ) )
	{	
		a.read(inBin);
		while(!inBin.eof())
		{
			// set key, calculate normTraits, and insert into tree
			a.setKey();
			a.calcNormTraits();
			tree.insert(a);
			a.read(inBin);
		}
	}
	inBin.close();

	do
	{
		cout << 
		"1 Add assessment\n"
		"2 Remove assessment\n"
		"3 Report assessment\n"
		"4 Pre-order print\n"
		"5 Exit and save\n";
		cout << "Option> ";
		cin >> choice;
		// set first character of choice = to selection 
		selection = choice[0];
		cout << endl;
		
		switch(selection)
		{
			case '1':
				addAssessment(&tree);
				cout << endl;
				break;

			case '2':
				removeAssessment(&tree);
				cout << endl;
				break;

			case '3':
				reportAssessment(&tree);
				cout << endl;
				break;

			case '4':
				tree.traverseAndPrint(tree.root(), PREORDER);
				cout << endl;
				break;

			case '5':
				writeTree(&tree);
				break;

			default:
				cout << "Invalid option " << selection << ", please try again.\n";
		}

	}while(selection != '5');
	
	cout << "Thank you for using the Big 5 Report!\n";
	return 0; 
}

/*
 * reportAssessment: Reports on a Big 5 Assessment
 * Paramaters: Pointer to a BinarySearchTree
 * Returns: Nothing
 */
void reportAssessment(BinarySearchTree<Assessment>* treePtr)
{
	Assessment a;
	char first[NUM_CHARACTERS];
	char last[NUM_CHARACTERS];
	cout << "First: ";
	cin >> first;
	cout << "Last: ";
	cin >> last;
	// Set name and key
	a.setFirst(first);
	a.setLast(last);
	a.makeLowUpFirst();
	a.setKey();

	Position<Assessment> p = treePtr->find(a);
	if(p.getItem() == a)
	{
		// Use of Assessment assignment operator 
		a = p.getItem();
		// Report 
		a.assessmentReport();
	}
	else
	{
		cout << a.getFirst() << " " << a.getLast() << " does not have and assessment.\n";;
	}
}

/*
 * addAssessment: Adds and assessment to the file
 * Parameters: None
 * Returns: Nothing
 */
void addAssessment(BinarySearchTree<Assessment>* treePtr)
{
	Assessment a;
	int ans; // question answer 
	char last[NUM_CHARACTERS];
	char first[NUM_CHARACTERS];
	int age;
	cout << "Last name: ";
	cin >> last;
	cout << "First name: ";
	cin >> first;

	// set name and key
	a.setFirst(first);
	a.setLast(last);
	a.makeLowUpFirst();
	a.setKey();

	Position<Assessment> p = treePtr->find(a);
	if(p.getItem() == a)
	{
		cout << a.getFirst() << " " << a.getLast() << " already has an assessment.\n";
	}
	else
	{
		cout << "Age: ";
		cin >> age;
		a.setAge(age);
		cout << "50 question answers: ";
		for(int i = 0; i < NUM_QUESTIONS; i++)
		{
			cin >> ans;
			// set each answer
			a.setAnswer(ans, i);
		}

		a.calcNormTraits();
		treePtr->insert(a);
	}

}

/*
 * writeTree: Saves assessment data and writes it
 * 	back to file pre-order
 * Parameters: A pointer to a tree
 * Returns: Nothing
 */
void writeTree(BinarySearchTree<Assessment>* treePtr)
{
	ofstream outBin;
	outBin.open(FILE_NAME, ios::out | ios::binary);
	
	// Calls preorderTraverseAndWrite, a function added to 
	// binarySearchTree.h 
	treePtr->preorderTraverseAndWrite( outBin, treePtr->root() );
	outBin.close();
}

/*
 * removeAssessment: Removes an assessment from the tree
 * Parameters: A pointer to a tree
 * Returns: Nothing
 */
void removeAssessment(BinarySearchTree<Assessment>* treePtr)
{
	Assessment a;
	char last[NUM_CHARACTERS];
	char first[NUM_CHARACTERS];
	cout << "Last name: ";
	cin >> last;
	cout << "First name: ";
	cin >> first;

	// set name and key
	a.setFirst(first);
	a.setLast(last);
	a.makeLowUpFirst();
	a.setKey();

	Position<Assessment> p = treePtr->find(a);
	if(p.getItem() == a)
	{
		cout << "Removed: " << p.getItem() << endl;
		treePtr->erase(p);
	}
	else
	{
		cout << a.getFirst() << " " << a.getLast() << " does not have an assessment.\n";
	}
}