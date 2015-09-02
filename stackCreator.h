#ifndef stackCreator_h
#define stackCreator_h

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
class stackCreator
{

public: 

THStack* Stack;
public:
	stackCreator(TLegend *Legend, Bool_t isData );
};
#endif
