#include "TLegend.h"
#include "stackCreator.h"
#include "TPaveText.h"
#include "TCanvas.h"
#include "Cuts.h"

TPaveText *pt1;
TPaveText *pt2;
TPaveText *pt3;

TLegend *Legend;

stackCreator *Data,*Mc;

void UpText()
{
  pt1 = new TPaveText(0.13,0.925,0.23,0.98,"blNDC");
  pt1->SetBorderSize(0);
  pt1->SetFillColor(0);
  pt1->SetFillStyle(0);
  pt1->SetTextFont(63);
  pt1->SetTextSize(25);
  pt1->AddText("CMS");

  pt2 = new TPaveText(0.21,0.91,0.475,0.98,"blNDC");
  pt2->SetBorderSize(0);
  pt2->SetFillColor(0);
  pt2->SetFillStyle(0);
  pt2->SetTextFont(53);
  pt2->SetTextSize(23);
  pt2->AddText("Preliminary");

  pt3 = new TPaveText(0.65,0.925,0.95,0.97,"blNDC");
  pt3->SetBorderSize(0);
  pt3->SetFillColor(0);
  pt3->SetFillStyle(0);
  pt3->SetTextFont(43);
  pt3->SetTextSize(20);
  pt3->AddText("42 pb^{-1} (13 TeV)");



}




void plotCreator(Bool_t ratioPlot)
{

Legend=new TLegend(0.72,0.71,1.0,0.91);

Data= new stackCreator(Legend,true);
Mc= new stackCreator(Legend,false);

UpText();

TCanvas *c1 = new TCanvas("Combined plots","Combined plots", 500,650);
c1->cd();
if (ratioPlot) 
	{

TPad *pad1 = new TPad("pad1","pad1",0., 0.35, 1., 1.);
      pad1->SetTopMargin(0.08);
      pad1->SetBottomMargin(0.015);

      pad1->Draw();
      pad1->cd();

	}
//Data->Stack->Draw();

//if (ratioPlot)  Data->Stack->GetXaxis()->SetLabelSize(0);
//Data->Stack->GetYaxis()->SetLabelSize(0.04);
//Mc->Stack->Draw("hist same");
//Data->Stack->Draw("same e1");
//Data->Stack->Draw("same axis");
Mc->Stack->Draw("hist");
Legend->Draw("same");

pt1->Draw("same");
pt2->Draw("same");
pt3->Draw("same");

/*
if (ratioPlot)
{


THStack *data=(THStack*)Data->Stack->Clone();
THStack *mc=(THStack*)Mc->Stack->Clone();
data->Sumw2();
data->SetStats(0);
data->Divide(mc);
data->SetMarkerStyle(21);

c1->cd();
TPad *pad2 = new TPad("pad2","pad2",0., 0., 1., 0.35);
pad2->SetTopMargin(0.1);
pad2->Draw();
pad2->cd();
pad2->SetBottomMargin(0.3);
pad2->SetGridy();
data->Draw("ep");
data->GetYaxis()->SetRangeUser(0.7,1.3);
data->GetYaxis()->SetLabelSize(0.07);
data->GetYaxis()->SetTitleSize(0);
data->GetXaxis()->SetLabelSize(0.07);
data->GetXaxis()->SetTitleSize(0.1);
data->GetXaxis()->SetTitleOffset(1.);
}
*/
}
