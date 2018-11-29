#pragma once
//#include "allele.h"
#include <iostream>
//#include "gene.h"
#include <fstream>

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
		A = intoA;
		B = intoB;
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
		//output.open("output.txt");
		output << this->name << ", ";
		output << this->traitType << ", ";
		//output.close();
		this->A.WriteAlleleToFile(output);
		this->B.WriteAlleleToFile(output);
	}
	Allele GetExpressedTrait() //EEEEERRRRRRRRRROOOOORRRRR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		Allele nullA;

		if (A.GetVType() == "dominant")
		{
			return A;
		}
		else if (B.GetVType() == "dominant")
		{
			return B;
		}
		else
		{
			return nullA;
		}

		//return this->B;
	}
	bool RunUnitTests()
	{
		Gene testGene;
		string GetGeneTest;
		bool testOutcome;

		testGene.SetGeneName("test gene");
		/*if (testGene.name != "test gene")
		{
			cout << "Set Gene name test fail." << endl;
		}
		else
		{
			cout << "Set Gene name test pass." << endl;
		}*/

		GetGeneTest = testGene.GetGeneName();
		if (GetGeneTest != "test gene")
		{
			cout << "Get Gene test fail." << endl;
			testOutcome = 0;
		}
		else
		{
			cout << "Get gene test pass." << endl;
			testOutcome = 1;
		}

		//testGene.A.SetVName("hair");
		//cout << testGene.A.GetVName() << endl;

		//bool testOutcome = 1;
		return testOutcome;
	}
};