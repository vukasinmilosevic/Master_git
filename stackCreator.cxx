#include "THStack.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TFile.h"
#include "TTree.h"
#include "TCut.h"
#include <string>
#include "any2string.h"
#include "TSystem.h"
#include "TMath.h"
#include "Cuts.h"

#include "TH1.h"
#include "histCreator.h"
#include "dataList.C"
#include "dataNamesList.C"
#include <string>
#include "mcList.C"
#include "mcNamesList.C"

#include "stackCreator.h"

using namespace std;

ClassImp(stackCreator)

stackCreator::stackCreator( string variableName, TLegend *Legend, Bool_t isData )
{

dataList();
dataNamesList();
mcList();
mcNamesList();
histCreator *A;
Stack=new THStack(variableName.c_str(),variableName.c_str());
int a=0; 
if (isData) a=1; else a=2;
cout<<"a= "<<a<< endl;
for (int i=0; i<a; i++)
{
if (isData){
	A=new histCreator(false,myFileNames[i].c_str(),presel_ee,-2.5,2.5,25,false,1,false,"eta_plot",variableName);
	Legend->AddEntry(A->Hist,Names[i].c_str(),"PL");
	cout<<"data"<<endl;
	    }
	else {
	A=new histCreator(false,myFileNames_mc[i].c_str(),presel_ee*weight,-2.5,2.5,25,false,5,false,"eta_plot",variableName);
	Legend->AddEntry(A->Hist,Names_mc[i].c_str(),"F");
	cout<<"mc"<<endl;
		
		}   
	 
Stack->Add(A->Hist);


}




}

