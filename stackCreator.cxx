#include "THStack.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TMath.h"
#include "TCut.h"
#include "Cuts.h"
#include "histCreator.h"
#include "dataList.C"
#include "dataNamesList.C"
#include <string>
#include "mcList.C"
#include "mcNamesList.C"

#include "stackCreator.h"

using namespace std;

ClassImp(stackCreator)

stackCreator::stackCreator(TLegend *Legend, Bool_t isData )
{
string  variableName="l1l2M";
dataList();
dataNamesList();
mcList();
mcNamesList();
histCreator *A[10];
Stack=new THStack(variableName.c_str(),variableName.c_str());
int a=0; 
if (isData) a=1; else a=6;
cout<<"a= "<<a<< endl;
for (int i=0; i<a; i++)
{
if (isData){
	//A[i]=new histCreator(false,myFileNames[i].c_str(),presel_ee,minBin,maxBin,nBins,false,1,false,"eta_plot",variableName);
	A[i]=new histCreator(false,myFileNames[i].c_str(),presel_ee,bins1GeV,binnum,false,1,false,"eta_plot",variableName);
	Legend->AddEntry(A[i]->Hist,Names[i].c_str(),"PL");
	cout<<"data"<<endl;
	    }
	else {
	//A[i]=new histCreator(false,myFileNames_mc[i].c_str(),presel_ee*weight,minBin,maxBin,nBins,false,5,false,"eta_plot",variableName);
	if (Names_mc[i]=="DY#tau#tau")
			{
	A[i]=new histCreator(false,myFileNames_mc[i].c_str(),presel_DYtautauee*weight,bins1GeV,binnum,false,color[i],false,"eta_plot",variableName);
cout<<"ok"<<endl;
			}
else  if (Names_mc[i]=="DY(ee)")
			{
	A[i]=new histCreator(false,myFileNames_mc[i].c_str(),presel_DYee*weight,bins1GeV,binnum,false,color[i],false,"eta_plot",variableName);
			}
	else
	{
	A[i]=new histCreator(false,myFileNames_mc[i].c_str(),presel_ee*weight,bins1GeV,binnum,false,color[i],false,"eta_plot",variableName);
	cout<< "DY signal"<<endl;
	}
	Legend->AddEntry(A[i]->Hist,Names_mc[i].c_str(),"F");
	cout<<"mc"<<endl;
		
		}   
	
for (int j=1;j<=binnum;j++)

{
A[i]->Hist->SetBinContent(j,1.0*A[i]->Hist->GetBinContent(j)/(A[i]->Hist->GetBinWidth(j)));
A[i]->Hist->SetBinError(j,1.0* A[i]->Hist->GetBinError(j)/A[i]->Hist->GetBinWidth(j));
} 
Stack->Add(A[i]->Hist);


}




}


