#include <cassert>
#include "TChain.h"
#include "TH1.h"
#include "TVector2.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include "TSystem.h"
#include "TClonesArray.h"
#include "TLorentzVector.h"
#include <vector>
#include <map>
#include <boost/assign/list_of.hpp>
#include "Delphes/external/ExRootAnalysis/ExRootTreeReader.h"
#include "Delphes/classes/DelphesClasses.h"
using namespace std;

class DelWeight
{
 public:
  void initialize();
  double weight(int isample, std::vector<GenParticle> GenParticles);
 private:
  std::vector<double> weights_TT;
  std::vector<std::vector<int> > decays_TT;
  std::vector<double> weights_BJ;
  std::vector<std::vector<int> > decays_BJ;
};
