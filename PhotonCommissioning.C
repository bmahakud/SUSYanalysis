#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "photon.cc"
#include "TChain.h"
#include "TString.h"
#include "TLorentzVector.h"
#include <vector>
#include <iostream>
using namespace std;


void computeYields(){

  TChain* t_mc = new TChain("TreeMaker2/PreSelection");
  t_mc->Add("/eos/uscms/store/user/awhitbe1/PHYS14productionV15/Spring15.DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_*_RA2AnalysisTree.root");

  TFile *f=new TFile("SpringMumuMC.root","RECREATE");



  TH1F *hmm =new TH1F("hmm","hmm",50,0,200);
  TH1F *hmmg =new TH1F("hmmg","hmmg",50,0,200);
  TH1F *hmmgm =new TH1F("hmmgm","hmmgm",50,0,200);  

  TH1F *phpT =new TH1F("phpT","phpT",100,0,500);
   
  TH1F *hToEB =new TH1F ("hToEB","hToEB",10,0,0.05);
  TH1F *hToEC =new TH1F ("hToEC","hToEC",10,0,0.05);

  TH1F *sieEB =new TH1F ("sieEB","sieEB",15,0.002,0.034);
  TH1F *sieEC =new TH1F ("sieEC","sieEC",15,0.002,0.034);


  TH1F *pfchEB =new TH1F ("pfchEB","pfchEB",15,0,3);
  TH1F *pfchEC =new TH1F ("pfchEC","pfchEC",15,0,3);

  TH1F *pfnEB =new TH1F ("pfnEB","pfnEB",15,0,3);
  TH1F *pfnEC =new TH1F ("pfnEC","pfnEC",15,0,3);

  TH1F *pfgEB =new TH1F ("pfgEB","pfgEB",15,0,3);
  TH1F *pfgEC =new TH1F ("pfgEC","pfgEC",15,0,3);








  TH1F *hdR =new TH1F("hdR","hdR",100,0,10);


  vector<TLorentzVector> *Jets_mc;
  vector<TLorentzVector> *Muons_mc;
  vector<int>     *MuonCharge_mc;
  float Rho_mc;
  t_mc->SetBranchAddress("rho", &Rho_mc);
  t_mc->SetBranchAddress( "ak4Jets" , &Jets_mc);
  t_mc->SetBranchAddress( "Muons" , &Muons_mc);
  t_mc->SetBranchAddress( "MuonCharge" , &MuonCharge_mc);
  photon photons_mc(t_mc); 

 

  //cout << "events: " << t->GetEntries() << endl;
  
  for( int iEv_mc = 0 ;  100000 ;  iEv_mc++){
    t_mc->GetEntry(iEv_mc);
    if( iEv_mc % 10000 == 0 ) cout << "event: " << iEv_mc << endl;

  
   int bestPhoton = -1;
  vector< unsigned int > Goodphotons;


   for( unsigned int iPh_mc = 0 ; iPh_mc < photons_mc.fourVec->size() ; iPh_mc++ ){//photon loop
 
  // cout <<"Photon Pt = "<<photons_mc.fourVec->at( iPh ).Pt()<<endl;

  if(photons_mc.passID( iPh_mc ) && photons_mc.passISO( iEv_mc, iPh_mc ,Rho_mc ) && photons_mc.passAcceptance()){

   Goodphotons.push_back(iPh_mc);


    }

   }//photon loop



  if(Muons_mc->size() >=2){//at least two muons
  
   int MuPlus=0;
   int MuMinus=0;
   double MuPpT=0;
   double MuMpT=0;
  
   TLorentzVector MuP;
   TLorentzVector MuM;

   for(int iMu_mc=0;iMu_mc < Muons_mc->size(); iMu_mc++){//mu counting
  // cout<<"Muon pt = "<<Muons_mc->at(iMu_mc).Pt()<<endl;
    if(MuonCharge_mc->at(iMu_mc)== 1){
    MuPlus=MuPlus+1;
    if(Muons_mc->at(iMu_mc).Pt() > MuPpT){//leading Mu plus
   
   MuP=&Muons_mc->at(iMu_mc);
   MuPpT=Muons_mc->at(iMu_mc).Pt();
    }//Leading Mu plus


      }   
    if(MuonCharge_mc->at(iMu_mc)== -1){
    MuMinus=MuMinus+1;
    if(Muons_mc->at(iMu_mc).Pt() > MuMpT){//leading Mu Minus

     MuM=&Muons_mc->at(iMu_mc);
     MuMpT=Muons_mc->at(iMu_mc).Pt();



      }//Leading Mu Minus




      }

     }//mu counting

   } //at least two muons    



   TLorentzVector FVmumu;
   TLorentzVector FVmumug;
 
    if(MuMinus >=1 && MuPlus >=1 && Goodphotons.size() >=1){//condition

   for(int i=0;i<Goodphotons.size();i++){//Good Photon loop

   TLorentzVector Ph_good;
   Ph_good=&photons_mc.fourVec->at( Goodphotons.at(i) );
   double DeltaRMuM=MuM.DeltaR(Ph_good);
   double DeltaRMuP=MuP.DeltaR(Ph_good);
    


    if(DeltaRMuM < 0.8 && DeltaRMuP < 0.8){
     
     if(DeltaRMuP > DeltaRMuM && MuPpT > 20 && MuMpT > 10  ){
     
      
     FVmumu=MuP+MuM;
     FVmumug=MuP+MuM+Ph_good;
    
     if( ( FVmumu.M() + FVmumug.M() ) < 180 && FVmumug.M() < 110 && FVmumug.M() > 70 ){//invariant mass cut

        hmm->Fill(FVmumu.M());
        hmmg->Fill(FVmumug.M());

      cout <<"Photon HOverE = "<<photons_mc.hadTowOverEM->at(Goodphotons.at(i))<<endl;


        }//invariant mass cut          
   
     


      

    
     }else if(DeltaRMuP < DeltaRMuM && MuMpT > 20 && MuPpT > 10){

     FVmumu=MuP+MuM;
     FVmumug=MuP+MuM+Ph_good;    


      if(( FVmumu.M() + FVmumug.M() ) < 180 && FVmumug.M() < 110 && FVmumug.M() > 70 ){//invariant mass cut

        hmm->Fill(FVmumu.M());
        hmmg->Fill(FVmumug.M());


        }//invariant mass cut


      }

    


     }
  
       }//good photon loop

      
   }//condition


 













    }
 


TCanvas *c1=new TCanvas("c1","c1");

TCanvas *c2=new TCanvas("c2","c2");



c1->cd();
hmm->Draw();
c2->cd();
hmmg->Draw(); 
}
