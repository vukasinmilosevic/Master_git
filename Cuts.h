#ifndef Cuts_h
#define Cuts_h

TCut presel_ee("lepPt[1]>20 && goodVtx && HLT_e1e2 == 1 && lepID[0]*lepID[1]==-11*11 && l1l2M>55");
TCut weight("xsection*totEveW*40.02");


#endif
