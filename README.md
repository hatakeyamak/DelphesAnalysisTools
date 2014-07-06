
This is a simple hack to give event weights to Delphes samples made from
snowmass LHE files made using BRIDGE.

Obtain this code:

    git clone git@github.com:hatakeyamak/DelphesAnalysisTools.git

For compile:
needs -std=c++0x flag

In your analysis code:

    #include "Delphes/external/ExRootAnalysis/ExRootTreeReader.h"
    #include "Delphes/classes/DelphesClasses.h"
    #include "DelWeight.h"

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
    int isample = 1; // 1: TTbar, 0: All other samples
    double weight = dw.weight(isample, GenParticlevec)
