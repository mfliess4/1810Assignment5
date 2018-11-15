/*	Project:    Gene
	Name:       Michael Fliess
    Partner:    PARTNER'S NAME IF ANY
    Class:      example: CSC 1810 - Section 2
*/

#include <iostream>
#include <fstream>

using namespace std;

//-------------------------------
//ALLELE CLASS START
//-------------------------------
class Allele
{
  private:
	string nucleotideSequence;
	string variantName;
	string variantType;

  public:
	Allele()
	{
		nucleotideSequence = "null";
		variantName = "no name";
		variantType = "no type";
	}
	Allele(string nucSeq, string vName, string vType)
	{
		nucleotideSequence = nucSeq;
		variantName = vName;
		variantType = vType;
	}
	void WriteAlleleToFile(ofstream &output)
	{
		output.open("output.txt");
		output << this->nucleotideSequence << " " << this->variantName << " " << this->variantType << endl;
		output.close();
	}
	bool RunUnitTests()
	{
		bool testOutcome = 1;
		//Tests FIXME
		return testOutcome;
	}

	//Getters and Setters

	void SetNTS(string NTSentry)
	{
		this->nucleotideSequence = NTSentry;
	}
	string GetNTS()
	{
		return this->nucleotideSequence; //RETURNS, not prints!
	}
	void SetVName(string vNameEntry)
	{
		this->variantName = vNameEntry;
	}
	string GetVName()
	{ //Returns!
		return this->variantName;
	}
	void SetVType(string vTypeEntry)
	{
		this->variantType = vTypeEntry;
	}
	string GetVType()
	{
		return this->variantType;
	}
};

//------------------------------
//GENE CLASS START
//------------------------------
class Gene
{
  private:
	Allele A;
	Allele B;
	string name;
	string traitType;

  public:
	Gene()
	{
		//A.Allele(); This should be automatically set by allele constructors
		name = "default Gene name";
		traitType = "trait type null";
	}
	Gene(Allele intoA, Allele intoB)
	{
		this->A = intoA;
		this->B = intoB;
		name = "default Gene name";
		traitType = "trait type null";
	}

	//Getters and Setters
	Allele GetAlleleA()
	{
		return A;
	}
	void SetAlleleA(Allele intoAlleleA)
	{
		this->A = intoAlleleA;
	}
	Allele GetAlleleB()
	{
		return B;
	}
	void SetAlleleB(Allele intoAlleleB)
	{
		this->B = intoAlleleB;
	}
	string GetGeneName()
	{
		return this->name;
	}
	void SetGeneName(string entry)
	{
		this->name = entry;
	}
	string GetGeneTraitType()
	{
		return this->traitType;
	}
	void SetGeneTraitType(string entry)
	{
		this->traitType = entry;
	}

	//Gene Functions
	void WriteToFile(ofstream &output)
	{
		output.open("output.txt");
		output << "Gene Name: " << this->name << endl;
		output << "Gene Type: " << this->traitType << endl;
		output.close();
		this->A.WriteAlleleToFile(output);
		this->B.WriteAlleleToFile(output);
	}
	Allele GetExpressedTrait()
	{
		if (this->A.GetVType() == "dominant")
		{
			return A;
		}
		else if (this->B.GetVType() == "dominant")
		{
			return B;
		}
	}
	bool RunUnitTests()
	{
		Gene testGene;
		string GetGeneTest;

		testGene.SetGeneName("test gene");
		if (testGene.name != "test gene")
		{
			cout << "Set Gene name test fail." << endl;
		}
		else
		{
			cout << "Set Gene name test pass." << endl;
		}

		GetGeneTest = testGene.GetGeneName();
		if (GetGeneTest != "test gene")
		{
			cout << "Get Gene name test fail." << endl;
		}
		else
		{
			cout << "Get gene name test pass." << endl;
		}

		testGene.A.SetVName("hair");
		cout << testGene.A.GetVName() << endl;

		bool testOutcome = 1;
		return testOutcome;
	}
};

int main(int argc, char *argv[])
{

	ofstream fileOut; //Must pass this in when outputting to file, at least in allele class

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