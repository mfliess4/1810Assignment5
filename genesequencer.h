#pragma once
//#include "allele.h"
//#include "gene.h"
//#include "chromosome.h"

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
		/*vector<Gene> aVec = A.returnVector();
		vector<Gene> bVec = B.returnVector();

		aVec.insert(aVec.end(), bVec.begin(), bVec.end());

		Chromosome returner;
		returner.SetGeneVector(aVec);

		return returner;*/

		Allele setA;
		Allele setB;

		Gene geneA;
		Gene geneB;
		Gene mergedGene;

		Chromosome finalChrome;

		vector<Gene> aVec = A.returnVector();
		vector<Gene> bVec = B.returnVector();
		vector<Gene> finalVec(((bVec.size() + aVec.size()) / 2));

		geneA = aVec.at(0);
		geneB = bVec.at(0);

		setA = geneA.GetAlleleA();
		setB = geneB.GetAlleleB();

		mergedGene.SetAlleleA(setA);
		mergedGene.SetAlleleB(setB);

		finalVec.at(0) = mergedGene;
		finalChrome.SetGeneVector(finalVec);

		return finalChrome;
	}
	void SequenceChromosome(Chromosome entry)
	{
		entry.AnalyzeGenotype();
	}
	void PowerOnSelfTest()
	{
		Allele testA;
		Gene testG;
		Chromosome testC;

		bool boolA;
		bool boolG;
		bool boolC;

		boolA = testA.RunUnitTests();
		boolG = testG.RunUnitTests();
		boolC = testC.RunUnitTests();

		if (boolA == 1 && boolG == 1 && boolC == 1)
		{
			cout << "POST passed." << endl;
		}
		else
		{
			cout << "Post failed." << endl;
		}
	}
};