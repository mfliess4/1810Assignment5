#pragma once
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
		//output.open("output.txt");
		output << nucleotideSequence << ", " << variantName << ", " << variantType << ", ";
		//output.close();
	}
	bool RunUnitTests()
	{
		bool testOutcome = 1;
		Allele test;
		test.SetNTS("aaa");
		if (test.GetNTS() == "aaa")
		{
			cout << "Allele test pass." << endl;
			testOutcome = 1;
		}
		else
		{
			cout << "Allele test fail." << endl;
			testOutcome = 0;
		}
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