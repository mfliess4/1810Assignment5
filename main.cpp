/*	Project:    Gene
	Name:       Michael Fliess
    Partner:    PARTNER'S NAME IF ANY
    Class:      example: CSC 1810 - Section 2
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "allele.h"
#include "gene.h"
#include "chromosome.h"
#include "genesequencer.h"

using namespace std;

//--------------------------------
//Seperate Menu Function
//--------------------------------

void MenuFunc()
{

	string menuNum;
	GeneSequencer a;
	Chromosome usrC;
	Chromosome usrD(5);
	ofstream fileOut; //Must pass this in when outputting to file, at least in allele class
	ifstream fileIn;

	cout << "Enter your menu selection, 1 - Create Chromosome, 2 - Analyze Chromosome," << endl;
	cout << "3 - Output Chromosome to File, 4 - Input Chromosome to file, 5 - Combine Chromosomes, 6 - Exit" << endl;

	getline(cin, menuNum);
	cout << endl;

	while (menuNum != "0" && menuNum != "6")
	{
		if (menuNum == ("1"))
		{
			cout << "Creating Chromosome..." << endl;
			usrC = a.CreateChromosome();
		}
		else if (menuNum == ("2"))
		{
			cout << "Start sequencing..." << endl;
			a.SequenceChromosome(usrC);
		}
		else if (menuNum == ("3"))
		{
			cout << "Exporting Chromosome..." << endl;
			a.ExportChromosome(usrC, fileOut);
		}
		else if (menuNum == ("4"))
		{
			cout << "Importing Chromosome..." << endl;
			usrC = a.ImportChromosome(fileIn);
		}
		else if (menuNum == ("5"))
		{
			cout << "Doing Meiosis..." << endl;
			usrC = a.DoMeiosis(usrC, usrD);
		}

		cout << "Enter menu choice again: ";
		getline(cin, menuNum);
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	GeneSequencer testA;
	testA.PowerOnSelfTest();
	MenuFunc();

	//Must pass in

	//Chromosome a(10);
	//GeneSequencer ab;
	//ab.SequenceChromosome(a);
	//a.AnalyzeGenotype();

	/*Gene test;
	bool testBool = test.RunUnitTests();*/

	// This causes the program to pause at its completion.
	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}