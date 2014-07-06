
This is a simple hack to give event weights to Delphes samples made from
snowmass LHE files made using BRIDGE.

For compile:
needs -std=c++0x flag

In your analysis code:

\#include "Delphes/external/ExRootAnalysis/ExRootTreeReader.h"
\#include "Delphes/classes/DelphesClasses.h"
\#include "DelWeight.h"

Before event loop:
    // For Delphes weights
    DelWeight dw;
    dw.initialize();
    vector<GenParticle> GenParticlevec;

Inside event loop:

    GenParticlevec.clear();
    for (int i = 0; i < branchParticle->GetEntries(); ++i)
      {
        GenParticle * particle = (GenParticle*)branchParticle->At(i);
        GenParticlevec.push_back(*particle);
      }//end of loop over "particles in history" 
    std::cout << std::endl;

double weight = dw.weight(1, GenParticlevec)
