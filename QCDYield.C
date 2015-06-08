#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "Photon.cc"
#include "TChain.h"
#include "TString.h"
#include "TLorentzVector.h"
#include <vector>
#include <iostream>

using namespace std;

void QCDYield_lpc(){



  TChain* t_QCD500 = new TChain("TreeMaker2/PreSelection");
  t_QCD500->Add("/eos/uscms/store/user/awhitbe1/PHYS14productionV12/PHYS14.QCD_HT-500To1000_13TeV-madgraph_*_RA2AnalysisTree.root");

 
   TChain* t_QCD1000 = new TChain("TreeMaker2/PreSelection");
   t_QCD1000->Add("/eos/uscms/store/user/awhitbe1/PHYS14productionV12/PHYS14.QCD_HT_1000ToInf_13TeV-madgraph_*_RA2AnalysisTree.root");





  vector<TLorentzVector> *jets_QCD500 = 0;
  float HT_QCD500, MHT_QCD500,mindPhinoPhotons_QCD500; 
  int NJets_QCD500, BTags_QCD500,nleptons_QCD500;
  float Rho_QCD500;


  t_QCD500->SetBranchAddress( "ak4Jets" , &jets_QCD500);
  t_QCD500->SetBranchAddress( "HTclean" , &HT_QCD500 );
  t_QCD500->SetBranchAddress( "MHTclean" , &MHT_QCD500 );
  t_QCD500->SetBranchAddress( "NJetsclean" , &NJets_QCD500 );
  t_QCD500->SetBranchAddress( "BTags" , &BTags_QCD500 );
  t_QCD500->SetBranchAddress("minDeltaPhiNclean",&mindPhinoPhotons_QCD500);
  t_QCD500->SetBranchAddress("rho", &Rho_QCD500);
  t_QCD500->SetBranchAddress("Leptons", &nleptons_QCD500);

  photon photons_QCD500(t_QCD500);

  vector<TLorentzVector> *jets_QCD1000 = 0;
  float HT_QCD1000, MHT_QCD1000,mindPhinoPhotons_QCD1000; 
  int NJets_QCD1000, BTags_QCD1000,nleptons_QCD1000;
  float Rho_QCD1000;


  t_QCD1000->SetBranchAddress( "ak4Jets" , &jets_QCD1000);
  t_QCD1000->SetBranchAddress( "HTclean" , &HT_QCD1000 );
  t_QCD1000->SetBranchAddress( "MHTclean" , &MHT_QCD1000 );
  t_QCD1000->SetBranchAddress( "NJetsclean" , &NJets_QCD1000 );
  t_QCD1000->SetBranchAddress( "BTags" , &BTags_QCD1000 );
  t_QCD1000->SetBranchAddress("minDeltaPhiNclean",&mindPhinoPhotons_QCD1000);
  t_QCD1000->SetBranchAddress("rho", &Rho_QCD1000);
  t_QCD1000->SetBranchAddress("Leptons", &nleptons_QCD1000);

  photon photons_QCD1000(t_QCD1000);



   TH1F *h_effMHTQCD500_cut=new TH1F("h_effMHTQCD500_cut","h_effT",300,200,2000);
   TH1F *h_effMHTQCD1000_cut=new TH1F("h_effMHTQCD1000_cut","h_effT",300,200,2000);
   


   TH1F *h_effMHTQCD_cut=new TH1F("h_effMHT_cut","h_effT",300,200,2000);
   



  






   int numEvents=10000000000;

   cout<<"Total number of events present in QCD500  = "<<t_QCD500->GetEntries()<<endl;
   
   

////////////////////////////////////////////////////////////////////////////////////Starts running over QCD 500
    for( int iEv1 = 0 ; iEv1 < t_QCD500->GetEntries() ; iEv1++){//event loop QCD 500
    
    if(iEv1==numEvents){
     break;

      }
    t_QCD500->GetEntry(iEv1);
    if( iEv1 % 10000 == 0 ) cout << "event: " << iEv1 << endl;

    photons_QCD500.getPhotonsFromEvent( iEv1 );
        
     if(HT_QCD500> 500 && MHT_QCD500>200 &&NJets_QCD500>=4 && nleptons_QCD500==0 ){//Base line cuts

     for( unsigned int iPh = 0 ; iPh < photons_QCD500.fourVec->size() ; iPh++ ){//Photon Loop
      
       if( photons_QCD500.passID( iPh ) && photons_QCD500.passISO( iEv1, iPh ,Rho_QCD500 )){//photon ID Iso pass

         
         h_effMHTQCD500_cut->Fill(MHT_QCD500);

         }//photon IDIso pass


       }//Photon Loop

      }//BaseLine cuts

   }//event loop QCD 500

/////////////////////////////////////////Ends running over QCD 500


cout<<"Total number of events present in QCD1000  = "<<t_QCD1000->GetEntries()<<endl;
////////////////////////////////////////////////////////////////////////////////////Starts running over QCD 1000
    for( int iEv2 = 0 ; iEv2 < t_QCD1000->GetEntries() ; iEv2++){//event loop QCD 500
    
    if(iEv2==numEvents){
     break;

      }
    t_QCD1000->GetEntry(iEv2);
    if( iEv2 % 10000 == 0 ) cout << "event: " << iEv2 << endl;

    photons_QCD1000.getPhotonsFromEvent( iEv2 );
        
     if(HT_QCD1000> 500 && MHT_QCD1000>200 &&NJets_QCD1000>=4 && nleptons_QCD1000==0 ){//Base line cuts

     for( unsigned int iPh = 0 ; iPh < photons_QCD1000.fourVec->size() ; iPh++ ){//Photon Loop
      
       if( photons_QCD1000.passID( iPh ) && photons_QCD1000.passISO( iEv2, iPh ,Rho_QCD1000 )){//photon ID Iso pass

         
         h_effMHTQCD1000_cut->Fill(MHT_QCD1000);

         }//photon IDIso pass


       }//Photon Loop

      }//BaseLine cuts

   }//event loop QCD 500

/////////////////////////////////////////Ends running over QCD 1000





TCanvas *cMHT_total=new TCanvas("cMHTtotal","QCD Yield");




h_effMHTQCD500_cut->Scale(31.494653329);
h_effMHTQCD1000_cut->Scale(2.3063347046);




h_effMHTQCD_cut->Add(h_effMHTQCD500_cut);
h_effMHTQCD_cut->Add(h_effMHTQCD1000_cut);


cMHT_total->cd();
h_effMHTQCD_cut->Draw();

cMHT_total->SaveAs("QCDYield_MHT.png");

















}
