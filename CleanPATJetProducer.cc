
// -*- C++ -*-
//
// Package:    SuSySubstructure
// Class:      CleanPATJetProducer
// 
/*

 Description: Produces a collection of PAT jets. Those jets are rejected from the collection if a photon > 100 GeV is found within

*/
//
// Original Author: Bibhuprasad Mahakud 
//         Created: 5th March 2015
// 
// 

// system include files
#include <memory>
#include <DataFormats/PatCandidates/interface/Jet.h>
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "AWhitbeck/SuSySubstructure/interface/CleanPATJetProducer.h"
#include "AllHadronicSUSY/Utils/src/effArea.cc"
#include "TLorentzVector.h"

#include <vector>

CleanPATJetProducer::CleanPATJetProducer(const edm::ParameterSet& iConfig):
  jetCollection(iConfig.getUntrackedParameter<std::string>("jetCollection")),
  photonCollection(iConfig.getUntrackedParameter<edm::InputTag>("photonCollection")),
  rhoCollection(iConfig.getUntrackedParameter<edm::InputTag>("rhoCollection")),
  debug(iConfig.getUntrackedParameter<bool>("debug",true))
{
  produces< std::vector< TLorentzVector > >(""); 
}


CleanPATJetProducer::~CleanPATJetProducer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
CleanPATJetProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  // fill histograms for di-lepton system
  std::auto_ptr< std::vector< TLorentzVector > > purePhoton ( new std::vector< TLorentzVector > () );




  using namespace edm;
 // std::cout<<"test . . . "<<std::endl; 
  Handle< View< pat::Photon> > photonCands;
  iEvent.getByLabel( photonCollection ,photonCands);

  edm::Handle< double > rho_;
  iEvent.getByLabel(rhoCollection,rho_);
  double rho = *rho_;

  if( debug ) std::cout << "got photon collection" << std::endl;

  effArea* effAreas = new effArea();
  effAreas->addEffA( 0.0,   1.0,   0.012, 0.030, 0.148 );
  effAreas->addEffA( 1.0,   1.479, 0.010, 0.057, 0.130 );
  effAreas->addEffA( 1.479, 2.0,   0.014, 0.039, 0.112 );
  effAreas->addEffA( 2.0,   2.2,   0.012, 0.015, 0.216 );
  effAreas->addEffA( 2.2,   2.3,   0.016, 0.024, 0.262 );
  effAreas->addEffA( 2.3,   2.4,   0.020, 0.039, 0.260 );
  effAreas->addEffA( 2.4,   99.,   0.012, 0.072, 0.266 );
  double PhotonPt=0;
  for( View< pat::Photon >::const_iterator iPhoton = photonCands->begin();
        iPhoton != photonCands->end();
        ++iPhoton){//photon loop starts
 
  isBarrelPhoton=false;
  isEndcapPhoton=false;
  isGenMatched=false;
  passID=false;
  passIso=false;
  passAcc=false;

 
 
   double PhEta=iPhoton->eta();
   if(fabs(PhEta) < 1.4442  ){
    isBarrelPhoton=true;
     }
   else if(fabs(PhEta)>1.566 && fabs(PhEta)<2.5){
     isEndcapPhoton=true;
     }
   else {
    isBarrelPhoton=false;
    isEndcapPhoton=false;

     }

  if(isBarrelPhoton || isEndcapPhoton){
     passAcc=true;
      }
  
 // bool genPhoton,isgenMatched;
   isGenMatched=iPhoton->genPhoton() != NULL;

  
  
 
  if(isBarrelPhoton){
  
  if(iPhoton->hadTowOverEm() < 0.05 && iPhoton->hasPixelSeed()==true && iPhoton->sigmaIetaIeta() < 0.011){//id criterias
   passID=true;

    }//id criterias

     } 
  else if(isEndcapPhoton){
   if(iPhoton->hadTowOverEm() < 0.05 && iPhoton->hasPixelSeed()==true && iPhoton->sigmaIetaIeta() < 0.031){//id criterias barrel
   passID=true;

    }//id criterias endcap

   }
 else {
  passID=false;
  }




  
 
     chIso = effAreas->rhoCorrectedIso(  pfCh  , iPhoton->chargedHadronIso() , iPhoton->eta() , rho );
     nuIso = effAreas->rhoCorrectedIso(  pfNu  , iPhoton->neutralHadronIso() , iPhoton->eta() , rho );
     gamIso = effAreas->rhoCorrectedIso( pfGam , iPhoton->photonIso()        , iPhoton->eta() , rho );
   
     
   
   if(isBarrelPhoton){
       if(chIso <0.7 && nuIso <  (0.4 + 0.04*(iPhoton->pt()))  && gamIso < ( 0.5 + 0.005*(iPhoton->pt())) ){
         passIso=true;      
        }
     
      }
   else if(isEndcapPhoton){
      if(chIso <0.5 && nuIso <  (1.5 + 0.04*(iPhoton->pt()))  && gamIso < ( 1.0 + 0.005*(iPhoton->pt())) ){
         passIso=true;
        }

     }
   else{
      passIso=false;
     }

  if(isGenMatched && passAcc && passID && passIso && iPhoton->pt() > 100.0){//pure photons
   if(iPhoton->pt() > PhotonPt){ 
    purePhoton->clear();
    TLorentzVector temp;
    temp.SetPtEtaPhiE(iPhoton->pt(),
                      iPhoton->eta(),
                      iPhoton->phi(),
                      iPhoton->energy());
    purePhoton->push_back( temp );
    PhotonPt=iPhoton->pt();
   

    }
    
    
    }//pure photons

    

    }//photon loop


  cout<<"number of photons = "<<purePhoton->size()<<endl;


  // get jet collection
  Handle< View<pat::Jet> > jetCands;
  iEvent.getByLabel(jetCollection,jetCands);

  std::auto_ptr< std::vector< TLorentzVector > > part4Vec ( new std::vector< TLorentzVector > () );

  if( debug ){
    std::cout << "new events" << std::endl;
    std::cout << "===================" << std::endl;
  }

  for(View<pat::Jet>::const_iterator iPart = jetCands->begin(); iPart != jetCands->end(); ++iPart){//loop over ak4Jets
      
    if( debug ) {
	       std::cout << "input  p_{mu}: " 
		      << iPart->px() << " " 
		      << iPart->py() << " " 
		      << iPart->pz() << " " 
		      << iPart->energy() << std::endl;
    }// end debug

   if(purePhoton->size()==1){
   double PhEta=purePhoton->at(0).Eta();  
   double PhPhi=purePhoton->at(0).Phi();
  
   double jetEta=iPart->eta();
   double jetPhi=iPart->phi();

   double dEta=PhEta-jetEta;
   double dPhi=PhPhi-jetPhi;
   if (fabs(PhPhi-jetPhi) > 3.14159){
    dPhi= 2*3.14159-(PhPhi-jetPhi );
    }
  

   double dR=sqrt((dEta*dEta)+(dPhi*dPhi)); 
   if(dR > 0.4 ){//deltaR cut photon and jet
    TLorentzVector p4( iPart->px(),
                       iPart->py(),
                       iPart->pz(),
                       iPart->energy()
                       ) ;

        part4Vec->push_back( p4 ) ;
         }//photon and jet


     }else if(purePhoton->size()==0){
   
   
    TLorentzVector p4( iPart->px(), 
		       iPart->py(), 
		       iPart->pz(), 
		       iPart->energy() 
		       ) ;

    part4Vec->push_back( p4 ) ;
    }



  }// end loop over ak4Jets 

  iEvent.put(part4Vec); 
 
}


// ------------ method called once each job just before starting event loop  ------------
void 

CleanPATJetProducer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
CleanPATJetProducer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void 
CleanPATJetProducer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
CleanPATJetProducer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
CleanPATJetProducer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
CleanPATJetProducer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}


// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
CleanPATJetProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {

  /*
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
  */

}


#include "FWCore/Framework/interface/MakerMacros.h"

//define this as a plug-in
DEFINE_FWK_MODULE(CleanPATJetProducer);
