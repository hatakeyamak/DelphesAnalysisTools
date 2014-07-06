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

// ===========================================================================
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

// ===========================================================================
double DelWeight::weight(int isample, std::vector<GenParticle> GenParticles){

  //
  bool debug = false;

  double weight=1.;

  vector<int> PIDv;
  int M1=-1;
  int M2=-1;
  int PIDM1 = 0;
  int PIDM2 = 0;
  int offset = 0;
  int PIDnext1,PIDnext2,PIDnext3;
  int PIDprev1,PIDprev2;
  vector<int> Wdaughters;
  PIDv.clear();
  Wdaughters.clear();
  
  //KH
  int bMissing = 0;
  int bbarMissing = 0;
  int WplusMissing = 0;
  int WminusMissing = 0;

  if (isample == 1){ // TTbar sample

    for (int i = 0; i < (int)(GenParticles.size()); ++i){
      GenParticle *p = &GenParticles.at(i);
      PIDv.push_back(p->PID);
      
      // Check the PID of the next particle
      PIDnext1 = 0;
      if ( i < (int)(GenParticles.size()) - 1 ){
	GenParticle *pp = &GenParticles.at(i+1);
	PIDnext1 = pp->PID;
      }
      PIDnext2 = 0;
      if ( i < (int)(GenParticles.size()) - 2 ){
	GenParticle *pp = &GenParticles.at(i+2);
	PIDnext2 = pp->PID;
      }
      PIDnext3 = 0;
      if ( i < (int)(GenParticles.size()) - 3 ){
	GenParticle *pp = &GenParticles.at(i+3);
	PIDnext3 = pp->PID;
      }
      PIDprev1 = 0;
      if ( i > 1 ){
	GenParticle *pp = &GenParticles.at(i-1);
	PIDprev1 = pp->PID;
      }
      PIDprev2 = 0;
      if ( i > 2 ){
	GenParticle *pp = &GenParticles.at(i-2);
	PIDprev2 = pp->PID;
      }

      // Find out the offset to associate the mother based on M1
      if (p->PID==5 && PIDnext1==24 && offset==0){  // (b,W)=(5,24) pair should have the parent top=6
	std::vector<int>::iterator it = find (PIDv.begin(), PIDv.end(), 6);
	//offset = p->M1 - (int)(it - PIDv.begin());
	offset = p->M1 - std::distance(PIDv.begin(), it);
	//KH(to be revisited): should be PIDnext2=-5 & PIDnext3=-24, but sometimes missing one of them
	if (PIDnext2==-24) bbarMissing =1;
	if (PIDnext2==-5 && PIDnext3!=-24) WplusMissing = 1;
        //KH(to be revisted)-ends
      }
      //KH(to be revisited): This shouldn't be necessary, but sometime (5,24) is missing
      if (p->PID==-5 && PIDnext1==-24 && offset==0){  // (b,W)=(-5,-24) pair should have the parent top=-6
	std::vector<int>::iterator it = find (PIDv.begin(), PIDv.end(), -6);
	//offset = p->M1 - (int)(it - PIDv.begin());
	offset = p->M1 - std::distance(PIDv.begin(), it);
	//KH(to be revisited): should be PIDprev2=5 & PIDprev1=24, but sometimes missing one of them
	if (PIDprev1==5 ) WminusMissing = 1;
	if (PIDprev1==24 && PIDprev2!=5) bMissing = 1;
      }
      //KH(to be revisted)-ends

      // Mother indexes
      M1 = p->M1 - offset;
      M2 = p->M2 - offset;

      // Mother PIDs
      if (debug) std::cout << p->PID;
      if (M1>0 && M1<(int)(PIDv.size())){ PIDM1 = PIDv[M1]; if (debug) std::cout << "(" << M1 << "," << PIDM1 << ")";}
      if (M2>0 && M2<(int)(PIDv.size())){ PIDM2 = PIDv[M2]; if (debug) std::cout << "(" << M2 << "," << PIDM2 << ")";}
      if (debug) std::cout << ",";

      // Fill the Wdaughter information
      if ( ( PIDM1==24 || PIDM1==-24) ) Wdaughters.push_back(p->PID);
      if ((int)Wdaughters.size() == 4) break; 

      //KH(to be revisited)
      if ((int)Wdaughters.size()==0 && bMissing==1){                    // 5 24 -5 -24 --> 24 -5 -24 // Done
	offset += 1;
	if (debug) std::cout << "test1" << std::endl;
      }
      if ((int)Wdaughters.size()==0 && WminusMissing==1) {               // 5 24 -5 -24 --> 5 -5 -24  // Done
	if ( (p->PID + PIDnext1 ) == 1 ) { 
	  Wdaughters.push_back(p->PID); 
	  Wdaughters.push_back(PIDnext1); 
	  if (debug) std::cout << "test2" << std::endl;
	}
      }
      if ((int)Wdaughters.size()==2 && bbarMissing==1){                 // 5 24 -5 -24 --> 5 24 -24  // Done
	offset += 1;
	if (debug) std::cout << "test3" << std::endl;
      }
      if ((int)Wdaughters.size()==2 && WplusMissing==1){                // 5 24 -5 -24 --> 5 24 -5   // Done
	if ( (p->PID + PIDnext1 ) == -1 ) { 
	  Wdaughters.push_back(p->PID); 
	  Wdaughters.push_back(PIDnext1); 
	  if (debug) std::cout << "test4" << std::endl;
	}
      }
      //KH(to be revisted)-ends

    }//end of loop over "particles in history" 
    if (debug) std::cout << std::endl;

    if ((int)Wdaughters.size() != 4 ){ // Not finding four daughters
      std::cout << "WARNING: TTbar event, but not finding four W daughters from two W bosons." << std::endl;
	for(std::vector<int>::iterator itt = Wdaughters.begin(); itt != Wdaughters.end(); ++itt) 
	  std::cout << *itt << " ";
	std::cout << std::endl;
    } else {                           
      std::vector<std::vector<int> >::iterator it = find (decays_TT.begin(), decays_TT.end(), Wdaughters);
      if (it == decays_TT.end()) {     // Not recognizing this W decay pattern

	//KH(to be revisited): this shouldn't happen, but sometimes missing one of the W daughters, and
	//                     Wdaughters vector includes 24 or -24
	//for(int i=0; i<3; i++){
	for(std::vector<std::vector<int> >::iterator itt = decays_TT.begin(); itt != decays_TT.end(); ++itt){
	  std::vector<int>::iterator it0 = find ((*itt).begin(), (*itt).end(), Wdaughters[0]);
	  std::vector<int>::iterator it1 = find ((*itt).begin(), (*itt).end(), Wdaughters[1]);
	  std::vector<int>::iterator it2 = find ((*itt).begin(), (*itt).end(), Wdaughters[2]);
	  if (it0 != (*itt).end() && it1 != (*itt).end() && it2 != (*itt).end()) {
	    int index_TT = std::distance(decays_TT.begin(), itt);
	    weight = weights_TT[index_TT];
	    if (debug){
	      std::cout << "REMARK: Not finding this exact W decay, but the best attempt is made." << std::endl;
	    }
	  }
	}
	//}

	if (weight==1.) {
	  std::cout << "WARNING: Not recognizing this W daecay in a TTbar event" << std::endl;
	  for(std::vector<int>::iterator itt = Wdaughters.begin(); itt != Wdaughters.end(); ++itt) 
	    std::cout << *itt << " ";
	  std::cout << std::endl;
	}
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


