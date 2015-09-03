#ifndef Cuts_h
#define Cuts_h

TCut presel_ee("lepPt[1]>20 && goodVtx && HLT_e1e2 == 1 && lepID[0]*lepID[1]==-11*11 && l1l2M>55");
TCut weight("xsection*totEveW*42");
TCut presel_mumu("lepPt[1]>20 && goodVtx && HLT_mu1mu2 == 1 && lepID[0]*lepID[1]==-13*13 && l1l2M>55");
TCut presel_emu("lepPt[1]>20 && goodVtx && (HLT_e1mu2 == 1 || HLT_mu1e2) && lepID[0]*lepID[1]==-11*13 && l1l2M>55");


TCut presel_DYee("isDYTauTau !=1 && lepPt[1]>20 && goodVtx && HLT_e1e2 == 1 && lepID[0]*lepID[1]==-11*11 && l1l2M>55");
TCut presel_DYtautauee("isDYTauTau == 1 && lepPt[1]>20 && goodVtx && HLT_e1e2 == 1 && lepID[0]*lepID[1]==-11*11 && l1l2M>55");

TCut presel_DYmumu("isDYTauTau !=1 && lepPt[1]>20 && goodVtx && HLT_mu1mu2 == 1 && lepID[0]*lepID[1]==-13*13 && l1l2M>55");
TCut presel_DYtautaumumu("isDYTauTau == 1 && lepPt[1]>20 && goodVtx && HLT_mu1mu2 == 1 && lepID[0]*lepID[1]==-13*13 && l1l2M>55");

TCut presel_DYemu("isDYTauTau !=1 && lepPt[1]>20 && goodVtx &&( HLT_e1mu2 == 1 || HLT_mu1e2) && lepID[0]*lepID[1]==-13*11 && l1l2M>55");
TCut presel_DYtautauemu("isDYTauTau == 1 && lepPt[1]>20 && goodVtx && (HLT_e1mu2 == 1 || HLT_mu1e2) && lepID[0]*lepID[1]==-11*13 && l1l2M>55");

Int_t nBins=300;
Float_t minBin=55;
Float_t maxBin=355;

Float_t bins1GeV[]={55,56,57,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,111,113,115,117,120,123,127,131,136,143,152,165,184,221,355};

Int_t  binnum = sizeof(bins1GeV)/sizeof(Float_t) - 1;

Color_t color[]={kBlue+4,kBlue+2,kBlue-3,kYellow,kOrange,kOrange+10};

#endif
