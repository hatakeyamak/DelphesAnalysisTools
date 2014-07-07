// ===========================================================================
// 
//       Filename:  DelWeight.cc
// 
//    Description:  A hack to restore the event weight from BRIDGE
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

  // ========== TTbar =========
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

  // ========== BJ =========
  // ----- Z bosons
  // 
  weights_BJ.push_back(1.9448); decays.clear();
  decays = {23, 1, -1}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(1.52196); decays.clear();
  decays = {23, 2, -2}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(1.97475); decays.clear();
  decays = {23, 3, -3}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(1.50866); decays.clear();
  decays = {23, 4, -4}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(1.93337); decays.clear();
  decays = {23, 5, -5}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(0.444705); decays.clear();
  decays = {23, 11, -11}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(0.88668); decays.clear();
  decays = {23, 12, -12}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(0.445666); decays.clear();
  decays = {23, 13, -13}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(0.88658); decays.clear();
  decays = {23, 14, -14}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(0.440213); decays.clear();
  decays = {23, 15, -15}; decays_BJ.push_back(decays);
  
  // 
  weights_BJ.push_back(0.882622); decays.clear();
  decays = {23, 16, -16}; decays_BJ.push_back(decays);

  // ----- W bosons
  // 
  weights_BJ.push_back(0.647601); decays.clear();
  decays = {24, 12, -11}; decays_BJ.push_back(decays);

  // 
  weights_BJ.push_back(0.652597); decays.clear();
  decays = {24, 14, -13}; decays_BJ.push_back(decays);

  // 
  weights_BJ.push_back(0.646987); decays.clear();
  decays = {24, 16, -15}; decays_BJ.push_back(decays);

  // 
  weights_BJ.push_back(1.94393); decays.clear();
  decays = {24, 2, -1}; decays_BJ.push_back(decays);

  // 
  weights_BJ.push_back(1.95888); decays.clear();
  decays = {24, 4, -3}; decays_BJ.push_back(decays);

  // 
  weights_BJ.push_back(0.661128); decays.clear();
  decays = {-24, 11, -12}; decays_BJ.push_back(decays);

  // 
  weights_BJ.push_back(0.666378); decays.clear();
  decays = {-24, 13, -14}; decays_BJ.push_back(decays);

  // 
  weights_BJ.push_back(0.66777); decays.clear();
  decays = {-24, 15, -16}; decays_BJ.push_back(decays);

  // 
  weights_BJ.push_back(2.00819); decays.clear();
  decays = {-24, 1, -2}; decays_BJ.push_back(decays);

  // 
  weights_BJ.push_back(1.99654); decays.clear();
  decays = {-24, 3, -4}; decays_BJ.push_back(decays);
  
  // ----- Photons
  // 
  weights_BJ.push_back(1.91); decays.clear();
  decays = {22}; decays_BJ.push_back(decays);

}

// ===========================================================================
double DelWeight::weight(int isample, std::vector<GenParticle> GenParticles){

  //
  bool debug = false;

  double weight=1.;

  vector<int> PIDv;
  vector<int> M1v;
  vector<int> M2v;
  int M1=-1;
  int M2=-1;
  int PIDM1 = 0;
  int PIDM2 = 0;
  int offset = 0;
  int PIDnext1,PIDnext2,PIDnext3;
  int PIDprev1,PIDprev2;
  vector<int> Wdaughters;
  PIDv.clear();
  M1v.clear();
  M2v.clear();
  Wdaughters.clear();

  vector<int> bosonDecays;
  vector<int> Zdaughters;
  bosonDecays.clear();
  Zdaughters.clear();
  
  //KH - sometimes b or bar or W+ or W- are missing in the gen particle record
  //KH - keep its log
  int bMissing = 0;
  int bbarMissing = 0;
  int WplusMissing = 0;
  int WminusMissing = 0;

  //==================================================
  if (isample == 1){ // TTbar sample

    for (int i = 0; i < (int)(GenParticles.size()); ++i){
      GenParticle *p = &GenParticles.at(i);
      PIDv.push_back(p->PID);
      
      // Check the PID of the "neighbor" particle
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
	if (PIDnext2==-5 && PIDnext3!=-24) WminusMissing = 1;
        //KH(to be revisted)-ends
      }
      //KH(to be revisited): This shouldn't be necessary, but sometime (5,24) is missing
      if (p->PID==-5 && PIDnext1==-24 && offset==0){  // (b,W)=(-5,-24) pair should have the parent top=-6
	std::vector<int>::iterator it = find (PIDv.begin(), PIDv.end(), -6);
	//offset = p->M1 - (int)(it - PIDv.begin());
	offset = p->M1 - std::distance(PIDv.begin(), it);
	//KH(to be revisited): should be PIDprev2=5 & PIDprev1=24, but sometimes missing one of them
	if (PIDprev1==5 ) WplusMissing = 1;
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
      if ( ( PIDM1==24 || PIDM1==-24) && abs(p->PID)!=24 ) Wdaughters.push_back(p->PID);
      if ((int)Wdaughters.size() == 4) break; 

      //KH(to be revisited)
      if ((int)Wdaughters.size()==0 && bMissing==1 && (abs(p->PID)==-24) ){
	                                                                // 5 24 -5 -24 --> 24 -5 -24 // Done
	offset += 1;
	bMissing = 2;
	if (debug) std::cout << "test1" << std::endl;
      }
      if ((int)Wdaughters.size()==0 && WplusMissing==1) {               // 5 24 -5 -24 --> 5 -5 -24  // Done
	if ( (p->PID + PIDnext1 ) == 1 ) { 
	  Wdaughters.push_back(p->PID); 
	  Wdaughters.push_back(PIDnext1); 
	  offset += 1;
	  WplusMissing = 2;
	  if (debug) std::cout << "test2" << std::endl;
	}
      }
      if ((int)Wdaughters.size()==2 && bbarMissing==1){                 // 5 24 -5 -24 --> 5 24 -24  // Done
	offset += 1;
	bbarMissing = 2;
	if (debug) std::cout << "test3" << std::endl;
      }
      if ((int)Wdaughters.size()==2 && WminusMissing==1){                // 5 24 -5 -24 --> 5 24 -5   // Done
	if ( (p->PID + PIDnext1 ) == -1 ) { 
	  Wdaughters.push_back(p->PID); 
	  Wdaughters.push_back(PIDnext1); 
	  WminusMissing = 2;
	  if (debug) std::cout << "test4" << std::endl;
	}
      }
      //KH(to be revisted)-ends

    }//end of loop over "particles in history" 
    if (debug) std::cout << std::endl;

    //
    if ((int)Wdaughters.size() != 4 ){ // Not finding four daughters

      if ((int)Wdaughters.size() == 3 ){ // If three daughters are found, give it a try

	//KH(to be revisited): this shouldn't happen, but sometimes missing one of the W daughters, and
	//                     Wdaughters vector includes 24 or -24
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
      }

      if (weight==1.) {
	std::cout << "WARNING: TTbar event, but not finding four W daughters from two W bosons." << std::endl;
	for(std::vector<int>::iterator itt = Wdaughters.begin(); itt != Wdaughters.end(); ++itt) 
	  std::cout << *itt << " ";
	std::cout << std::endl;
      }

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

    if (debug) {
      std::cout << weight << " ";
      for(std::vector<int>::iterator itt = Wdaughters.begin(); itt != Wdaughters.end(); ++itt) 
	std::cout << *itt << " ";
      std::cout << std::endl;
    }

  }
  //==================================================
  else if (isample == 2){ // BJ sample

    //
    // Fill PIDv vector
    for (int i = 0; i < (int)(GenParticles.size()); ++i){
      GenParticle *p = &GenParticles.at(i);
      PIDv.push_back(p->PID);
      M1v.push_back(p->M1);
      M2v.push_back(p->M2);
    }

    if (debug) {
      for (int i = 0; i < PIDv.size(); i++ ){
	std::cout << PIDv[i] << "(" << M1v[i] << "," << M2v[i] << ")";
      }
      std::cout << std::endl;
    }

    //
    // Photons
    std::vector<int>::iterator it = find (PIDv.begin(), PIDv.end(), 22);
    if (it != PIDv.end()) {

      bosonDecays.push_back(22);

      // Find the iterator 
      std::vector<std::vector<int> >::iterator it = find (decays_BJ.begin(), decays_BJ.end(), bosonDecays);

      int index_BJ = std::distance(decays_BJ.begin(), it);
      weight = weights_BJ[index_BJ];

      if (debug) std::cout << "Photons: weight = " << weight << std::endl;
      return weight;

    } 

    //
    // Z bosons
    it = find (PIDv.begin(), PIDv.end(), 23);
    int index = std::distance(PIDv.begin(), it);
    if (it != PIDv.end()) {

      for(std::vector<std::vector<int> >::iterator itt = decays_BJ.begin(); itt != decays_BJ.end(); ++itt){
  	if ( (*itt)[0]==23 ){
	  //if ( (int)(*itt).size()==3 )
	  //  std::cout << "itt vector = " << (*itt)[0] << " " << (*itt)[1] << " " << (*itt)[2] << std::endl;
	  int index_BJ = std::distance(decays_BJ.begin(), itt);
	  // look for daughters
	  //std::vector<int>::iterator it1 = find(PIDv.begin()+index, PIDv.end(), (*itt)[1] );
	  for (std::vector<int>::iterator it1 = PIDv.begin()+index; it1 != PIDv.end(); ++it1){
	  if ( *it1 == (*itt)[1] ){
	  int index1 = std::distance(PIDv.begin(), it1);
	  //std::vector<int>::iterator it2 = find (PIDv.begin()+index1, PIDv.end(), (*itt)[2] );
	  //int index2 = std::distance(PIDv.begin(), it2);
	  std::vector<int>::iterator it2 = it1 + 1;
	  int index2 = index1 + 1;
	  if ( *it2 == (*itt)[2] ) {
	  if (debug) std::cout << "*it1,*it2 = " << *it1 << " " << *it2 << std::endl;
	  if (it1 != PIDv.end() && it2 != PIDv.end()){
	    if (debug) std::cout << "*it1,*it2 = " << *it1 << " " << *it2 << std::endl;
	    // check their mother index
	    if (debug) std::cout << "index1,index2 = " << index1 << " " << index2 << std::endl;
	    if (debug) std::cout << "M1v[index1/index2] = " 
				 << M1v[index1] << " " << M1v[index2] << std::endl;
	    if (M1v[index1]==M1v[index2]){
	      weight = weights_BJ[index_BJ];	      
	      if (debug) {
		std::cout << "Zs: weight = " << weight << std::endl;
		std::cout << (*itt)[0] << " " << (*itt)[1] << " " << (*itt)[2] << std::endl;
	      }
	      return weight;
	    } else {
	      if (debug) std::cout << "M1v[index1/index2] = " 
				   << M1v[index1] << " " << M1v[index2] << std::endl;
	    }
	  } // if it1
	  } // if *it2
	  } // if *it1
	  } // for it1 
	}  
      } 
      if (weight==1.) {
	std::cout << "WARNING: Z event, but Z daughters are not identified." << std::endl;
      }      
    } // Z 

    //
    // W- bosons
    it = find (PIDv.begin(), PIDv.end(), -24);
    index = std::distance(PIDv.begin(), it);
    if (it != PIDv.end()) {

      for(std::vector<std::vector<int> >::iterator itt = decays_BJ.begin(); itt != decays_BJ.end(); ++itt){
  	if ( (*itt)[0]==-24 ){
	  //if ( (int)(*itt).size()==3 )
	  //  std::cout << "itt vector = " << (*itt)[0] << " " << (*itt)[1] << " " << (*itt)[2] << std::endl;
	  int index_BJ = std::distance(decays_BJ.begin(), itt);
	  // look for daughters
	  //std::vector<int>::iterator it1 = find (PIDv.begin()+index, PIDv.end(), (*itt)[1] );
	  for (std::vector<int>::iterator it1 = PIDv.begin()+index; it1 != PIDv.end(); ++it1){
	  if ( *it1 == (*itt)[1] ){
	  int index1 = std::distance(PIDv.begin(), it1);
	  //std::vector<int>::iterator it2 = find (PIDv.begin()+index1, PIDv.end(), (*itt)[2] );
	  //int index2 = std::distance(PIDv.begin(), it2);
	  std::vector<int>::iterator it2 = it1 + 1;
	  int index2 = index1 + 1;
	  if ( *it2 == (*itt)[2] ) {
	  if (debug) std::cout << "*it1,*it2 = " << *it1 << " " << *it2 << std::endl;
	  if (it1 != PIDv.end() && it2 != PIDv.end()){
	    if (debug) std::cout << "*it1,*it2 = " << *it1 << " " << *it2 << std::endl;
	    // check their mother index
	    if (debug) std::cout << "index1,index2 = " << index1 << " " << index2 << std::endl;
	    if (debug) std::cout << "M1v[index1/index2] = " 
				 << M1v[index1] << " " << M1v[index2] << std::endl;
	    if (M1v[index1]==M1v[index2]){
	      weight = weights_BJ[index_BJ];	      
	      if (debug){
		std::cout << "W-s: weight = " << weight << std::endl;
		std::cout << (*itt)[0] << " " << (*itt)[1] << " " << (*itt)[2] << std::endl;
	      }
	      return weight;
	    } else {
	      if (debug) std::cout << "M1v[index1/index2] = " 
				   << M1v[index1] << " " << M1v[index2] << std::endl;
	    }
	  } // if it1
	  } // if *it2
	  } // if *it1
	  } // for it1 
	}  
      } 
      if (weight==1.) {
	std::cout << "WARNING: W- event, but W- daughters are not identified." << std::endl;
      }      
    } // W- 

    //
    // W+ bosons
    it = find (PIDv.begin(), PIDv.end(), 24);
    index = std::distance(PIDv.begin(), it);
    if (it != PIDv.end()) {

      for(std::vector<std::vector<int> >::iterator itt = decays_BJ.begin(); itt != decays_BJ.end(); ++itt){
  	if ( (*itt)[0]==24 ){
	  //if ( (int)(*itt).size()==3 )
	  //  std::cout << "itt vector = " << (*itt)[0] << " " << (*itt)[1] << " " << (*itt)[2] << std::endl;
	  int index_BJ = std::distance(decays_BJ.begin(), itt);
	  // look for daughters
	  std::vector<int>::iterator it1 = find (PIDv.begin()+index, PIDv.end(), (*itt)[1] );
	  for (std::vector<int>::iterator it1 = PIDv.begin()+index; it1 != PIDv.end(); ++it1){
	  if ( *it1 == (*itt)[1] ){
	  int index1 = std::distance(PIDv.begin(), it1);
	  //std::vector<int>::iterator it2 = find (PIDv.begin()+index1, PIDv.end(), (*itt)[2] );
	  //int index2 = std::distance(PIDv.begin(), it2);
	  std::vector<int>::iterator it2 = it1 + 1;
	  int index2 = index1 + 1;
	  if ( *it2 == (*itt)[2] ) {
	  if (debug) std::cout << "*it1,*it2 = " << *it1 << " " << *it2 << std::endl;
	  if (it1 != PIDv.end() && it2 != PIDv.end()){
	    if (debug) std::cout << "*it1,*it2 = " << *it1 << " " << *it2 << std::endl;
	    // check their mother index
	    if (debug) std::cout << "index1,index2 = " << index1 << " " << index2 << std::endl;
	    if (debug) std::cout << "M1v[index1/index2] = " 
				 << M1v[index1] << " " << M1v[index2] << std::endl;
	    if (M1v[index1]==M1v[index2]){
	      weight = weights_BJ[index_BJ];	      
	      if (debug){
		std::cout << "W+s: weight = " << weight << std::endl;
		std::cout << (*itt)[0] << " " << (*itt)[1] << " " << (*itt)[2] << std::endl;
	      }
	      return weight;
	    } else {
	      if (debug) std::cout << "M1v[index1/index2] = " 
				   << M1v[index1] << " " << M1v[index2] << std::endl;
	    }
	  } // if it1
	  } // if *it2
	  } // if *it1
	  } // for it1 
	}  
      }
      if (weight==1.) {
	std::cout << "WARNING: W+ event, but W+ daughters are not identified." << std::endl;
      }      
    } // W+

  }
  //==================================================
  else { // Any other samples

    weight = 1.;

  }

  return weight;

}


