#include "TTree.h"
#include <vector>
#include <iostream>
#include "effArea.cc"
#include "TLorentzVector.h"

using namespace std;

class photon{

public:

  TTree* t;
  int num;
  vector<TLorentzVector> *fourVec, *genParticles;
  vector<double> *isEB;
  vector<double> *isGenMatched;
  vector<double> *hadTowOverEM,*sigmaIetaIeta;
  vector<double> *pfChargedIso,*pfNeutralIso,*pfGammaIso;
  vector<double> *pfGammaIsoRhoCorr,*pfNeutralIsoRhoCorr,*pfChargedIsoRhoCorr;
  //vector<bool> *passElectronConvVeto; 
  vector<int> *hasPixelSeed, *genParPDGid;
  effArea* effAreas;

  TLorentzVector genPhoton;

  photon(TTree* t_){

    t = t_;

    effAreas = new effArea();
    effAreas->addEffA( 0.0,   1.0,   0.0234, 0.0053, 0.078 );
    effAreas->addEffA( 1.0,   1.479, 0.0189, 0.0130, 0.0629 );
    effAreas->addEffA( 1.479, 2.0,   0.0171, 0.0057, 0.0264 );
    effAreas->addEffA( 2.0,   2.2,   0.0129, 0.0070, 0.0462 );
    effAreas->addEffA( 2.2,   2.3,   0.0110, 0.0152, 0.0740 );
    effAreas->addEffA( 2.3,   2.4,   0.0074, 0.0232, 0.0924 );
    effAreas->addEffA( 2.4,   99.,   0.0035, 0.1709, 0.1484 );
		
    //cout << "copied TTree pointer, zeroing vectors" << endl;
    isEB = 0 ; isGenMatched = 0 ;
    fourVec = 0 ;
    hadTowOverEM = 0 ; sigmaIetaIeta = 0 ;
    pfChargedIso = 0 ; pfNeutralIso = 0 ; pfGammaIso = 0 ;
    pfGammaIsoRhoCorr = 0 ; pfNeutralIsoRhoCorr = 0 ; pfChargedIsoRhoCorr = 0 ;
    hasPixelSeed = 0 ;
    genParticles = 0;
    genParPDGid = 0;

    //cout << "set NPhotons" << endl;
    t->SetBranchAddress( "photonCands" , &fourVec );

    //cout << "set kinematics" << endl;
    t->SetBranchAddress( "photon_isEB" , &isEB );
    t->SetBranchAddress( "photon_genMatched" , &isGenMatched );

    //cout << "set fiducial vars" << endl;
    t->SetBranchAddress( "photon_hadTowOverEM" , &hadTowOverEM );
    t->SetBranchAddress( "photon_sigmaIetaIeta" , &sigmaIetaIeta );

    //cout << "set shower vars" << endl;
    t->SetBranchAddress( "photon_pfChargedIso" , &pfChargedIso );
    t->SetBranchAddress( "photon_pfNeutralIso" , &pfNeutralIso );
    t->SetBranchAddress( "photon_pfGammaIso" , &pfGammaIso );
			
    //cout << "set pf isolation vars" << endl;
    t->SetBranchAddress( "photon_pfGammaIsoRhoCorr" , &pfGammaIsoRhoCorr );
    t->SetBranchAddress( "photon_pfNeutralIsoRhoCorr" , &pfNeutralIsoRhoCorr );
    t->SetBranchAddress( "photon_pfChargedIsoRhoCorr" , &pfChargedIsoRhoCorr );

    //cout << "set cone isolation vars" << endl;
    t->SetBranchAddress( "photon_hasPixelSeed" , &hasPixelSeed );

    t->SetBranchAddress( "genParticles" , &genParticles );
    t->SetBranchAddress( "genParticles_PDGid" , &genParPDGid );

    //cout << "set vetos" << endl;

  };

  bool getGenPhoton(){

    int genIndex = -1;

    TLorentzVector temp;

    for(unsigned int iPh = 0 ; iPh < genParPDGid->size() ; iPh++)
     // cout<<"PdgId = "<<genParPDGid->at(iPh)<<endl;
      if( genParPDGid->at(iPh) == 22 ) genIndex = iPh ; 
   
    if( genIndex == -1 ){
      cout << "ERROR - photon::getGenPhoton(): didn't find a gen photon" << endl;
      return false;
    }else{
      //cout << "genParticle: " << genParticles->at(genIndex).Pt() << " " <<  genParticles->at(genIndex).Eta() << " " <<  genParticles->at(genIndex).Phi() << " " <<  genParticles->at(genIndex).E() << endl;
      genPhoton.SetPtEtaPhiE( genParticles->at(genIndex).Pt() , genParticles->at(genIndex).Eta() , genParticles->at(genIndex).Phi() , genParticles->at(genIndex).E() );
      //cout << "genPhoton: " << genPhoton.Pt() << " " << genPhoton.Eta() << " " << genPhoton.Phi() << " " << genPhoton.E() << endl;
      return true;
    }

  };

  bool passAcceptance(){

    if( !getGenPhoton() ){
      return false;
    }

    if( fabs( genPhoton.Eta() ) > 2.5 ) 
      cout << "genPhoton.Eta(): " << genPhoton.Eta() << endl; 
    
    if( fabs( genPhoton.Eta() ) < 1.4442 || ( fabs( genPhoton.Eta() ) > 1.566 && fabs( genPhoton.Eta() ) < 2.5 ) ) return true;
    else return false;
    
  };
  
  bool passID( unsigned int iPh ){

   

    if( hasPixelSeed->at(iPh) == 1 || 
	fourVec->at(iPh).Pt() < 100. ) return false;
    
    if( isEB->at(iPh) ){
      
      if( hadTowOverEM->at(iPh) > 0.028 || sigmaIetaIeta->at(iPh) > 0.0107 ) return false;
      
    }else{
      
      if( hadTowOverEM->at(iPh) > 0.093 || sigmaIetaIeta->at(iPh) > 0.0272 ) return false;
      
    }

    return true;

  };










  bool passISO(int iEvent , unsigned int iPh , double rho){
    
    getPhotonsFromEvent( iEvent );

    double Pf_Ch_RhoCorrIso= effAreas->rhoCorrectedIso( pfCh , pfChargedIso->at(iPh) , fourVec->at(iPh).Eta() , rho );
    double Pf_Ne_RhoCorrIso = effAreas->rhoCorrectedIso( pfNu , pfNeutralIso->at(iPh) , fourVec->at(iPh).Eta() , rho );
    double Pf_Gam_RhoCorrIso = effAreas->rhoCorrectedIso( pfGam , pfGammaIso->at(iPh) , fourVec->at(iPh).Eta() , rho );


    if( isEB->at(iPh) ){
      
      if( Pf_Ch_RhoCorrIso > 2.67 ) return false;
      if( Pf_Ne_RhoCorrIso > (7.23 + TMath::Exp(0.0028*fourVec->at(iPh).Pt()+0.5408)) ) return false;
      if( Pf_Gam_RhoCorrIso > (1.40 + 0.0014*fourVec->at(iPh).Pt()) ) return false;
      
    }else{
      
      if( Pf_Ch_RhoCorrIso > 1.79 ) return false;
      if( Pf_Ne_RhoCorrIso > (3.89 + 0.0172*fourVec->at(iPh).Pt()) ) return false;
      if( Pf_Gam_RhoCorrIso > (1.40 + 0.0091*fourVec->at(iPh).Pt()) ) return false;
      
    }

    return true;

  };

  bool passGenMatch( unsigned int iPh ){

    if ( !getGenPhoton() ){
      return false ; 
    }
  
    double dR = sqrt( pow( fourVec->at(iPh).Eta() - genPhoton.Eta() , 2 ) + 
		      pow( fourVec->at(iPh).Phi() - genPhoton.Phi() , 2 ) ) ; 

    //cout << " ph eta: " << fourVec->at(iPh).Eta() << " ph phi: " << fourVec->at(iPh).Phi() << endl;
    //cout << " gen eta: " << genPhoton.Eta() << " gen phi: " << genPhoton.Phi() << endl;
    //cout << " dR: " << dR << " ";
    if( dR < 0.2 ) return true ;
    else return false ; 
    
  };

  void deletePhoton(int iPhoton ){

    //cout << "deletePhoton" << endl;
    //cout << "iPhoton: " << iPhoton << " will be deleted" << endl;
    fourVec->erase( fourVec->begin() + iPhoton );
    isEB->erase( isEB->begin() + iPhoton );
    isGenMatched->erase( isGenMatched->begin() + iPhoton );
    hadTowOverEM->erase( hadTowOverEM->begin() + iPhoton );
    sigmaIetaIeta->erase( sigmaIetaIeta->begin() + iPhoton );
    pfChargedIso->erase( pfChargedIso->begin() + iPhoton );
    pfNeutralIso->erase( pfNeutralIso->begin() + iPhoton );
    pfGammaIso->erase( pfGammaIso->begin() + iPhoton );
    pfGammaIsoRhoCorr->erase( pfGammaIsoRhoCorr->begin() + iPhoton );
    pfNeutralIsoRhoCorr->erase( pfNeutralIsoRhoCorr->begin() + iPhoton );
    pfChargedIsoRhoCorr->erase( pfChargedIsoRhoCorr->begin() + iPhoton );
    hasPixelSeed->erase( hasPixelSeed->begin() + iPhoton );

  };

  bool passIDcuts( int iEvent , int iPhoton ){

    //cout << "photon::passIDcuts" << endl;

    getPhotonsFromEvent( iEvent );
		
    if( isEB->at(iPhoton) ){

      if( hasPixelSeed->at(iPhoton) == 1 ) return false;
      if( hadTowOverEM->at(iPhoton) > 0.05 ) return false;
      if( sigmaIetaIeta->at(iPhoton) > 0.011 ) return false;

    }else{

      if( hasPixelSeed->at(iPhoton) == 1 ) return false;
      if( hadTowOverEM->at(iPhoton) > 0.05 ) return false;
      if( sigmaIetaIeta->at(iPhoton) > 0.031 ) return false;

    }

    return true;

  };


  bool passIsoCuts( int iEvent , int iPhoton , double rho ){

    getPhotonsFromEvent( iEvent );

    double chIso = effAreas->rhoCorrectedIso( pfCh , pfChargedIso->at(iPhoton) , fourVec->at(iPhoton).Eta() , rho );
    double nuIso = effAreas->rhoCorrectedIso( pfNu , pfNeutralIso->at(iPhoton) , fourVec->at(iPhoton).Eta() , rho );
    double gamIso = effAreas->rhoCorrectedIso( pfGam , pfGammaIso->at(iPhoton) , fourVec->at(iPhoton).Eta() , rho );

    if( isEB ){
		
      if( chIso > 0.7 ) return false;
      if( nuIso > 0.4 + 0.04*fourVec->at(iPhoton).Pt() ) return false;
      if( gamIso > 0.5 + 0.005*fourVec->at(iPhoton).Pt() ) return false;
		
    }else{

      if( chIso > 0.5 ) return false;
      if( nuIso > 1.5 + 0.04*fourVec->at(iPhoton).Pt() ) return false;
      if( gamIso > 1.0 + 0.005*fourVec->at(iPhoton).Pt() ) return false;

    }

    return true;

  };

  void getPhotonsFromEvent(int iEvent , bool print = false ){

    //cout << "photon::getPhotonsFromEvent" << endl;

    t->GetEntry( iEvent );

    //cout << "got entry" << endl;

    // for some reason there is a problem with this... maybe NPhotons is not really being filled?
    /*
      if( num != pt->size() ){
      cout << "num: " << num << " pt size: " << pt->size() << endl;
      return;
      }
    */

    if( print ){

      cout << "printing..." << endl;



    }

  };

  void printPhotons(int iEvent){

    getPhotonsFromEvent(iEvent);
    printPhotons();

  };
	
  void printPhotons(){

    cout << "============" << endl;
    cout << "num photons: " << fourVec->size() << endl;
    cout << "============" << endl;	

    for( unsigned int i = 0 ; i < fourVec->size() ; i++ ){
      cout << "iPhoton: " << i << endl;
      cout << "pt: " << fourVec->at(i).Pt() << endl;	
      cout << "eta: " << fourVec->at(i).Eta() << endl;
      cout << "phi: " << fourVec->at(i).Phi() << endl;
      cout << "energy: " << fourVec->at(i).E() << endl;
      cout << " - - - - - - " << endl;
    }// end loop over photon candidates

  };
	

};

