#include "histCreator.h"

#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TCut.h"
#include <string>
#include "any2string.h"
#include "TSystem.h"

#include "TH1.h"

using namespace std;

ClassImp(histCreator)

histCreator::histCreator(Bool_t isdata,string filename, TCut cut, Double_t minbin, Double_t maxbin, Int_t nbin, Bool_t fill, Int_t color, Bool_t gofast, string plotname, string variablename) :
	isData(isdata),
	fileName(filename),
	Cut(cut),
	minBin(minbin),
	maxBin(maxbin),
	nBin(nbin),
	Fill(fill),
	Color(color),
	goFast(gofast),
	plotName(plotname),
	variableName(variablename)
{
	File=new TFile(fileName.c_str(), "OPEN" );
	Tree=(TTree*)File->Get("demo/events");
	NumEntr=Tree->GetEntries();
	
	if (goFast) NumEntr = ULong64_t (0.01*NumEntr);
	
//	Double_t label= (1.0*(maxBin-minBin)/nBin);//need to add this to histLabel!	
	string histLabel= ";"+variableName+" [GeV]  ; Events / ";	
	Hist= new TH1F(plotName.c_str(),histLabel.c_str() ,nBin,minBin,maxBin);
	cout<< histLabel<<endl;
	string var=variableName+">>"+plotName;		
	Tree->Draw(var.c_str(),Cut,"goff",NumEntr);
	Hist->Sumw2();
	Hist->SetStats(0);
	Hist->SetLineColor(Color);
	if (!isData) Hist->SetFillColor(Color);
	  else    Hist->SetFillColor(kWhite);
		
	
}


histCreator::histCreator(Bool_t isdata,string filename, TCut cut,Float_t binning[], Int_t nbins, Bool_t fill, Int_t color, Bool_t gofast, string plotname, string variablename) :
        isData(isdata),
        fileName(filename),
        Cut(cut),
        nBin(nbins),
        Fill(fill),
        Color(color),
        goFast(gofast),
        plotName(plotname),
        variableName(variablename)
{
        File=new TFile(fileName.c_str(), "OPEN" );
        Tree=(TTree*)File->Get("demo/events");
        NumEntr=Tree->GetEntries();

        if (goFast) NumEntr = ULong64_t (0.01*NumEntr);

        //Double_t label= (1.0*(maxBin-minBin)/nBin);//need to add this to histLabel!     
        string histLabel= ";"+variableName+" [GeV]  ; Events / ";
       
	Hist= new TH1F(plotName.c_str(),histLabel.c_str() ,nBin, binning);
        cout<< histLabel<<endl;
        string var=variableName+">>"+plotName;
        Tree->Draw(var.c_str(),Cut,"goff",NumEntr);
        Hist->Sumw2();
        Hist->SetStats(0);
        Hist->SetLineColor(Color);
        if (!isData) Hist->SetFillColor(Color);
        else    Hist->SetFillColor(kWhite);

 }
