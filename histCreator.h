#ifndef histCreator_h
#define histCreator_h

#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TCut.h"
#include <string>
#include <iostream>
#include "any2string.h"
#include "TSystem.h"

#include "TH1.h"

class histCreator
{
	Bool_t isData;
	mutable string fileName;
	mutable TCut Cut;
	mutable Double_t minBin, maxBin;
	mutable Int_t  nBin;
	mutable Bool_t Fill;
	mutable Int_t Color;
	mutable Bool_t goFast;
	mutable string plotName;
	TFile* File;
	TTree* Tree;
	ULong64_t NumEntr;
	string Type;
	string variableName;

public:	TH1F* Hist;
public:
	histCreator(Bool_t isdata,string filename, TCut cut, Double_t minbin, Double_t maxbin, Int_t nbin, Bool_t fill, Int_t color, Bool_t gofast, string plotname, string variablename);

};

#endif
