// ===========================================================================
// 
//       Filename:  DelWeight.cc
// 
//    Description:  A hack to restore the event  
// 
//        Version:  1.0
//       Compiler:  g++
// 
//         Author:  Zhenbin Wu (benwu), benwu@fnal.gov
//                  K.H., hatake@fnal.gov
// 
// ===========================================================================

#include "DelWeight.h"

void DelWeight::initialize(){
  
  vector<int> decays;

  // ----- Dileptons
  // [W+->e+nu, W-->e-nu]
  weights_TT.push_back(0.378136); decays.clear();
  decays = {12, -11, 11, -12}; decays_TT.push_back(decays);

  // [W+->e+nu, W-->mu-nu]
  weights_TT.push_back(0.381138); decays.clear();
  decays = {12, -11, 13, -14}; decays_TT.push_back(decays);

  // [W+->e+nu, W-->tay-nu]
  weights_TT.push_back(0.381934); decays.clear();
  decays = {12, -11, 15, -16}; decays_TT.push_back(decays);

  // [W+->mu+nu, W-->e-nu]
  weights_TT.push_back(0.381053); decays.clear();
  decays = {14, -13, 11, -12}; decays_TT.push_back(decays);

  // [W+->mu+nu, W-->mu-nu]
  weights_TT.push_back(0.384079); decays.clear();
  decays = {14, -13, 13, -14}; decays_TT.push_back(decays);

  // [W+->mu+nu, W-->tay-nu]
  weights_TT.push_back(0.384881); decays.clear();
  decays = {14, -13, 15, -16}; decays_TT.push_back(decays);

  // [W+->tau+nu, W-->e-nu]
  weights_TT.push_back(0.377777); decays.clear();
  decays = {16, -15, 11, -12}; decays_TT.push_back(decays);

  // [W+->tau+nu, W-->mu-nu]
  weights_TT.push_back(0.380777); decays.clear();
  decays = {16, -15, 13, -14}; decays_TT.push_back(decays);

  // [W+->tau+nu, W-->tay-nu]
  weights_TT.push_back(0.381572); decays.clear();
  decays = {16, -15, 15, -16}; decays_TT.push_back(decays);

  // ----- Lepton+Jets
  // [W+->e+nu, W-->scbar]
  weights_TT.push_back(1.14193); decays.clear();
  decays = {12, -11, 3, -4}; decays_TT.push_back(decays);

  // [W+->csbar, W-->e-nu]
  weights_TT.push_back(1.1438); decays.clear();
  decays = {4, -3, 11, -12}; decays_TT.push_back(decays);

  // [W+->e+nu, W-->dubar]
  weights_TT.push_back(1.14859); decays.clear();
  decays = {12, -11, 1, -2}; decays_TT.push_back(decays);

  // [W+->udbar, W-->e-nu]
  weights_TT.push_back(1.13507); decays.clear();
  decays = {2, -1, 11, -12}; decays_TT.push_back(decays);


  // [W+->mu+nu, W-->scbar]
  weights_TT.push_back(1.15074); decays.clear();
  decays = {14, -13, 3, -4}; decays_TT.push_back(decays);

  // [W+->csbar, W-->mu-nu]
  weights_TT.push_back(1.15288); decays.clear();
  decays = {4, -3, 13, -14}; decays_TT.push_back(decays);

  // [W+->mu+nu, W-->dubar]
  weights_TT.push_back(1.15745); decays.clear();
  decays = {14, -13, 1, -2}; decays_TT.push_back(decays);

  // [W+->udbar, W-->mu-nu]
  weights_TT.push_back(1.14408); decays.clear();
  decays = {2, -1, 13, -14}; decays_TT.push_back(decays);


  // [W+->tau+nu, W-->scbar]
  weights_TT.push_back(1.14085); decays.clear();
  decays = {16, -15, 3, -4}; decays_TT.push_back(decays);

  // [W+->csbar, W-->tau-nu]
  weights_TT.push_back(1.15529); decays.clear();
  decays = {4, -3, 15, -16}; decays_TT.push_back(decays);

  // [W+->tau+nu, W-->dubar]
  weights_TT.push_back(1.1475); decays.clear();
  decays = {16, -15, 1, -2}; decays_TT.push_back(decays);

  // [W+->udbar, W-->tau-nu]
  weights_TT.push_back(1.14647); decays.clear();
  decays = {2, -1, 15, -16}; decays_TT.push_back(decays);

  // ----- All hadronic
  // [W+->udbar, W-->dubar]
  weights_TT.push_back(3.44778); decays.clear();
  decays = {2, -1, 1, -2}; decays_TT.push_back(decays);

  // [W+->udbar, W-->scbar]
  weights_TT.push_back(3.42778); decays.clear();
  decays = {2, -1, 3, -4}; decays_TT.push_back(decays);

  // [W+->udbar, W-->dubar]
  weights_TT.push_back(3.4743); decays.clear();
  decays = {4, -3, 1, -2}; decays_TT.push_back(decays);

  // [W+->udbar, W-->dubar]
  weights_TT.push_back(3.45414); decays.clear();
  decays = {4, -3, 3, -4}; decays_TT.push_back(decays);

}

double DelWeight::weight(int isample, std::vector<GenParticle> GenParticles){

  bool debug = false;

  double weight=1.;

  vector<int> PIDv;
  int M1=-1;
  int M2=-1;
  int PIDM1 = 0;
  int PIDM2 = 0;
  int offset = 0;
  
  vector<int> Wdaughters;

  if (isample == 1){ // TTbar sample

    for (int i = 0; i < (int)(GenParticles.size()); ++i){
      GenParticle *p = &GenParticles.at(i);
      PIDv.push_back(p->PID);
      
      if (p->PID==5 && offset==0){
	std::vector<int>::iterator it = find (PIDv.begin(), PIDv.end(), 6);
	//offset = p->M1 - (int)(it - PIDv.begin());
	offset = p->M1 - std::distance(PIDv.begin(), it);
      }

      // Mother indexes
      M1 = p->M1 - offset;
      M2 = p->M2 - offset;

      // Mother PIDs
      if (debug) std::cout << p->PID;
      if (M1>0 && M1<(int)(PIDv.size())){ PIDM1 = PIDv[M1]; if (debug) std::cout << "(" << M1 << "," << PIDM1 << ")";}
      if (M2>0 && M2<(int)(PIDv.size())){ PIDM2 = PIDv[M2]; if (debug) std::cout << "(" << M2 << "," << PIDM2 << ")";}
      if (debug) std::cout << ",";

      // Fill the Wdaughter information
      if ( ( PIDM1==24 || PIDM1==-24) && (p->PID!=24) ) Wdaughters.push_back(p->PID);
      if ((int)Wdaughters.size() == 4) break; 

    }//end of loop over "particles in history" 
    if (debug) std::cout << std::endl;

    if ((int)Wdaughters.size() != 4 ){ // Not finding four daughters
      std::cout << "TTbar event, but not finding four W daughters from two W bosons." << std::endl;
	for(std::vector<int>::iterator itt = Wdaughters.begin(); itt != Wdaughters.end(); ++itt) 
	  std::cout << *itt << " ";
	std::cout << std::endl;
    } else {                           
      std::vector<std::vector<int> >::iterator it = find (decays_TT.begin(), decays_TT.end(), Wdaughters);
      if (it == decays_TT.end()) {     // Not recognizing this W decay pattern
	std::cout << "Not recognizing this W daecay in a TTbar event" << std::endl;
	for(std::vector<int>::iterator itt = Wdaughters.begin(); itt != Wdaughters.end(); ++itt) 
	  std::cout << *itt << " ";
	std::cout << std::endl;
      } else {                         // Now determining the event weight
	int index_TT = std::distance(decays_TT.begin(), it);
	weight = weights_TT[index_TT];
      }
    }

  } 
  else { // Any other samples

    weight = 1.;

  }

  return weight;

}


