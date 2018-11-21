/*	Project:    Gene
	Name:       Michael Fliess
    Partner:    PARTNER'S NAME IF ANY
    Class:      example: CSC 1810 - Section 2
*/

#include <iostream>
#include <fstream>
#include <vector>

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

//-------------------------------------------
//Chromosome Class Start
//--------------------------------------------

class Chromosome
{
  private:
	vector<Gene> GeneVector;

  public:
	Chromosome()
	{
	}
	Chromosome(int vecSizeEnter)
	{
		this->GeneVector.resize(vecSizeEnter);
	}
	void AnalyzeGenotype()
	{
		unsigned int i = 0;
		while (i < GeneVector.size())
		{
			cout << "Gene " << i + 1 << endl;
			cout << "Name:		" << GeneVector.at(i).GetGeneName() << endl;
			cout << "Genetic trait:		" << GeneVector.at(i).GetGeneTraitType() << endl;

			Allele outAllele;
			outAllele = GeneVector.at(i).GetExpressedTrait();
			cout << "Expressed Allele:		" << outAllele.GetVName() << " - " << outAllele.GetVType() << endl;

			Gene out = GeneVector.at(i);
			Allele outA = out.GetAlleleA();
			Allele outB = out.GetAlleleB();
			cout << "Nucleotide Sequence:		" << outA.GetNTS() << outB.GetNTS() << endl;
			i++;
		}
	}
	void InputFromFile(ifstream &intoStream)
	{
		unsigned int i = 0;
		intoStream.open("genefile.csv");

		while (i < GeneVector.size())
		{
			Gene input;
			string a;
			string b;
			Allele AA;
			Allele BB;
			string c;
			string d;
			string e;
			string f;
			string g;
			string h;

			/*while (intoStream.is_open())
			{
				if (intoStream.peek() == ',')
				{
					intoStream.ignore(1);
				}
			}*/

			intoStream >> a;
			input.SetGeneName(a);
			intoStream >> b;
			input.SetGeneTraitType(b);
			intoStream >> c;
			AA.SetVName(c);
			intoStream >> d;
			AA.SetVType(d);
			intoStream >> e;
			AA.SetNTS(e);
			intoStream >> f;
			BB.SetVName(f);
			intoStream >> g;
			BB.SetVType(g);
			intoStream >> h;
			BB.SetNTS(h);

			input.SetAlleleA(AA);
			input.SetAlleleB(BB);
			GeneVector.at(i) = input;
			i++;
		}
		intoStream.close();
	}
	void OutputToFile(ofstream &outChrome)
	{
		unsigned int i = 0;
		outChrome.open("output.txt");

		while (i < GeneVector.size())
		{
			outChrome << "Chromosome " << i + 1 << endl;
			outChrome << GeneVector.at(i).GetGeneName() << ", ";
			outChrome << GeneVector.at(i).GetGeneTraitType() << ", ";
			Gene out = GeneVector.at(i);
			Allele outA = out.GetAlleleA();
			Allele outB = out.GetAlleleB();
			outChrome << outA.GetVName() << ", ";
			outChrome << outA.GetVType() << ", ";
			outChrome << outA.GetNTS() << ", ";
			outChrome << outB.GetVName() << ", ";
			outChrome << outB.GetVType() << ", ";
			outChrome << outB.GetNTS() << ", ";
			outChrome << endl;

			cout << "Printing..." << endl;

			i++;
		}

		outChrome.close();
	}
	void AddGene(Gene adder)
	{
		GeneVector.push_back(adder);
	}
	Gene FindGene(string searcher)
	{
		unsigned int i = 0;
		Gene nullGene;

		while (i < GeneVector.size())
		{
			if (GeneVector.at(i).GetGeneName() == searcher)
			{
				return GeneVector.at(i);
			}
			i++;
		}

		return nullGene;
	}
	vector<Gene> returnVector()
	{
		return GeneVector;
	}
	void SetGeneVector(vector<Gene> setter)
	{
		this->GeneVector = setter;
	}
};

//--------------------------------------------
//GeneSequencer Class Start
//--------------------------------------------

class GeneSequencer
{
  private:
  public:
	Chromosome CreateChromosome()
	{
		int GeneCount;
		cout << "How many Genes are in your Chromosome?" << endl;
		cin >> GeneCount;
		cin.clear();
		cin.ignore(1);
		cout << endl
			 << endl;

		Chromosome returner(GeneCount);
		return returner;
	}
	Chromosome ImportChromosome(ifstream &inStream)
	{
		int GeneCount;
		cout << "How many genes are you importing to your Chromosome from file?" << endl;
		cin >> GeneCount;
		cin.clear();
		cin.ignore(1);
		cout << endl
			 << endl;

		Chromosome returner(GeneCount);
		returner.InputFromFile(inStream);
		return returner;
	}
	void ExportChromosome(Chromosome exportChrome, ofstream &streamOut)
	{
		exportChrome.OutputToFile(streamOut);
	}
	Chromosome DoMeiosis(Chromosome A, Chromosome B)
	{
		vector<Gene> aVec = A.returnVector();
		vector<Gene> bVec = B.returnVector();

		aVec.insert(aVec.end(), bVec.begin(), bVec.end());

		Chromosome returner;
		returner.SetGeneVector(aVec);

		return returner;
	}
	void SequenceChromosome(Chromosome entry)
	{
		entry.AnalyzeGenotype();
	}
};

//--------------------------------
//Seperate Menu Function
//--------------------------------

void MenuFunc()
{
	cout << "Note: Importing and exporting works with included csv file and text file, has not been tested with outide csv file yet. " << endl;

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