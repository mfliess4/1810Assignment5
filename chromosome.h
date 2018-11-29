#pragma once
//#include "allele.h"
//#include "gene.h"
#include <vector>

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

			//intoStream >> a;
			getline(intoStream, a, ',');
			input.SetGeneName(a);
			getline(intoStream, b, ',');
			input.SetGeneTraitType(b);
			getline(intoStream, c, ',');
			AA.SetVName(c);
			getline(intoStream, d, ',');
			AA.SetVType(d);
			getline(intoStream, e, ',');
			AA.SetNTS(e);
			getline(intoStream, f, ',');
			BB.SetVName(f);
			getline(intoStream, g, ',');
			BB.SetVType(g);
			getline(intoStream, h, ',');
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
	bool RunUnitTests()
	{
		Chromosome test(5);
		bool testOutcome;
		vector<Gene> a;
		a = test.returnVector();
		if (a.size() > 0)
		{
			cout << "Chromosome test pass." << endl;
			testOutcome = 1;
		}
		else
		{
			cout << "Chromosome test fail." << endl;
			testOutcome = 0;
		}

		return testOutcome;
	}
};