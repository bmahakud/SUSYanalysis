#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "Photon.cc"
#include "TChain.h"
#include "computeBinBtag.C" 
#include "TString.h"
#include "TLorentzVector.h"
#include <vector>
#include <iostream>

using namespace std;

void ComputeYieldBJet(TString process ="GJets400HT600" ){//main programme


if(process=="GJets400HT600"){


  TString outputFile = "yields_GJets400HT600_RA2b_24bin.root";
  bool photonEfficiencies = true;

  TChain* t = new TChain("TreeMaker2/PreSelection");
  t->Add("/home/bibhu/Desktop/Cern/PhDstartNewAnalysis/SUSYnew2015/PhotonStudies/PhotonPlusJets/NtuplesAll/PHYS14.GJets_HT-400to600_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");


}else if(process=="GJets600HTInf"){

  TString outputFile = "yields_GJets600HTInf_RA2b_24bin.root";
  bool photonEfficiencies = true;
  TChain* t = new TChain("TreeMaker2/PreSelection");
  t->Add("/home/bibhu/Desktop/Cern/PhDstartNewAnalysis/SUSYnew2015/PhotonStudies/PhotonPlusJets/NtuplesAll/PHYS14.GJets_HT-600toInf_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");



}else if(process=="ZJetsToNuNu400HT600"){

  TString outputFile = "yields_ZJetsToNuNu400HT600_RA2b_24bin.root";
  bool photonEfficiencies = false;
  TChain* t = new TChain("TreeMaker2/PreSelection");
  t->Add("/home/bibhu/Desktop/Cern/PhDstartNewAnalysis/SUSYnew2015/PhotonStudies/PhotonPlusJets/NtuplesAll/PHYS14.ZJetsToNuNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");


}else if(process=="ZJetsToNuNu600HTInf"){


  TString outputFile = "yields_ZJetsToNuNu600HTInf_RA2b_24bin.root";
  bool photonEfficiencies = false;
  TChain* t = new TChain("TreeMaker2/PreSelection");
  t->Add("/home/bibhu/Desktop/Cern/PhDstartNewAnalysis/SUSYnew2015/PhotonStudies/PhotonPlusJets/NtuplesAll/PHYS14.ZJetsToNuNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");



}else{

cout<<"Error in input file name "<<endl;

cout<<"Only following names are acceptable"<<endl;

cout<<"1 : "<<"GJets400HT600"<<endl;
cout<<"2 : "<<"GJets600HTInf"<<endl;
cout<<"3 : "<<"ZJetsToNuNu400HT600"<<endl;
cout<<"4 : "<<"ZJetsToNuNu600HTInf"<<endl;

break;

}



  vector<TLorentzVector> *jets = 0;
  float HT, MHT,mindPhinoPhotons; 
  int NJets, BTags;
  float Rho;


  t->SetBranchAddress( "ak4Jets" , &jets);
  t->SetBranchAddress( "HTnoPhotons" , &HT );
  t->SetBranchAddress( "MHTnoPhotons" , &MHT );
  t->SetBranchAddress( "NJetsNoPhotons" , &NJets );
  t->SetBranchAddress( "BTags" , &BTags );
  t->SetBranchAddress("minDeltaPhiNnoPhotons",&mindPhinoPhotons);
  t->SetBranchAddress("rho", &Rho);
  photon photons(t);

   


  TH1F* gen = new TH1F("gen","gen",24,0.5,24.5);
  gen->SetLineWidth(2);
  TH1F* accepted = new TH1F("accepted","accepted",24,0.5,24.5);
  accepted->SetLineWidth(2);
  accepted->SetLineColor(4);
  TH1F* IDed = new TH1F("IDed","IDed",24,0.5,24.5);
  IDed->SetLineWidth(2);
  IDed->SetLineColor(4);
  IDed->SetLineStyle(2);
  TH1F* ISOed = new TH1F("ISOed","ISOed",24,0.5,24.5);
  ISOed->SetLineWidth(2);
  ISOed->SetLineColor(6);
  ISOed->SetLineStyle(1);
  TH1F* Matched = new TH1F("Matched","Matched",24,0.5,24.5);
  Matched->SetLineWidth(2);
  Matched->SetLineColor(6);
  Matched->SetLineStyle(2);




  // yields versus njets
  TH2F* gen_njets = new TH2F("gen_njets","gen_njets",5,3.5,8.5,2,200,500);
  TH2F* accepted_njets = new TH2F("accepted_njets","accepted_njets",5,3.5,8.5,2,200,500);
  TH2F* IDed_njets = new TH2F("IDed_njets","IDed_njets",5,3.5,8.5,2,200,500);
  TH2F* ISOed_njets = new TH2F("ISOed_njets","ISOed_njets",5,3.5,8.5,2,200,500);
  TH2F* Matched_njets = new TH2F("Matched_njets","Matched_njets",5,3.5,8.5,2,200,500);

  // yields versus nbtags
  TH2F* gen_btags = new TH2F("gen_btags","gen_btags",3,-0.5,2.5,2,200,500);
  TH2F* accepted_btags = new TH2F("accepted_btags","accepted_btags",3,-0.5,2.5,2,200,500);
  TH2F* IDed_btags = new TH2F("IDed_btags","IDed_btags",3,-0.5,2.5,2,200,500);
  TH2F* ISOed_btags = new TH2F("ISOed_btags","ISOed_btags",3,-0.5,2.5,2,200,500);
  TH2F* Matched_btags = new TH2F("Matched_btags","Matched_btags",3,-0.5,2.5,2,200,500);

  //yields versus HT
  TH1F* gen_HT = new TH1F("gen_HT","gen_HT",20,500,2500);
  TH1F* accepted_HT = new TH1F("accepted_HT","accepted_HT",20,500,2500);
  TH1F* IDed_HT = new TH1F("IDed_HT","IDed_HT",20,500,2500);
  TH1F* ISOed_HT = new TH1F("ISOed_HT","ISOed_HT",20,500,2500);
  TH1F* Matched_HT = new TH1F("Matched_HT","Matched_HT",20,500,2500);

  //yields versus MHT
  TH1F* gen_MHT = new TH1F("gen_MHT","gen_MHT",18,200,2000);
  TH1F* accepted_MHT = new TH1F("accepted_MHT","accepted_MHT",18,200,2000);
  TH1F* IDed_MHT = new TH1F("IDed_MHT","IDed_MHT",18,200,2000);
  TH1F* ISOed_MHT = new TH1F("ISOed_MHT","ISOed_MHT",18,200,2000);
  TH1F* Matched_MHT = new TH1F("Matched_MHT","Matched_MHT",18,200,2000);






  int numEvents=10000000000;

 for( int iEv = 0 ; iEv < t->GetEntries() ; iEv++){//event loop

    if(iEv==numEvents){
     break;

      }
    t->GetEntry(iEv);
    if( iEv % 5000 == 0 ) cout << "event: " << iEv << endl;

    photons.getPhotonsFromEvent( iEv );

vector< unsigned int > passIDphotons, passIDISOphotons;
int bin = computeBin( MHT, HT, NJets , BTags, k13TeV,mindPhinoPhotons );

//if(bin!=-1){
//cout<<"bin number = "<<bin<<endl;
//}


    gen->Fill( bin );
    if( bin > 0 ){
      gen_njets->Fill( NJets , MHT ) ;
      gen_btags->Fill( BTags , MHT ) ;
      gen_HT->Fill( HT ) ;
      gen_MHT->Fill( MHT ) ;
      }


 if( photonEfficiencies ){
      //cout << "gen eta: " << photons.genPhoton.Eta() << endl;
      if( photons.passAcceptance() ){
	//cout << "passed acceptance cut" << endl;
	accepted->Fill( bin );
	if( bin > 0 ){
	  accepted_njets->Fill( NJets , MHT ) ;
	  accepted_btags->Fill( BTags , MHT ) ;
	  accepted_HT->Fill( HT ) ;
	  accepted_MHT->Fill( MHT ) ;
	}
	for( unsigned int iPh = 0 ; iPh < photons.fourVec->size() ; iPh++ ){
	  //cout << "iPh: " << iPh << "/" << photons.fourVec->size() << endl;
	  if( photons.passID( iPh ) && photons.fourVec->at( iPh ).Pt() > 100. )
	    passIDphotons.push_back( iPh );
	}
	if( passIDphotons.size() > 0 ){
	  IDed->Fill( bin );
	  if( bin > 0 ){
	    IDed_njets->Fill( NJets , MHT ) ;
	    IDed_btags->Fill( BTags , MHT ) ;
	    IDed_HT->Fill( HT ) ;
	    IDed_MHT->Fill( MHT ) ;
	  }
	}
	for( unsigned int iPh = 0 ; iPh < passIDphotons.size() ; iPh++ ){
	  if( photons.passISO( iEv, passIDphotons[iPh] ,Rho ) )
	    passIDISOphotons.push_back( passIDphotons[iPh] );
	}
	if( passIDISOphotons.size() > 0){
	  ISOed->Fill( bin );
	  if( bin > 0 ){
	    ISOed_njets->Fill( NJets , MHT ) ;
	    ISOed_btags->Fill( BTags , MHT ) ;
	    ISOed_HT->Fill( HT ) ;
	    ISOed_MHT->Fill( MHT ) ;
	  }
	  if( photons.passGenMatch( passIDISOphotons[0] ) ){
	    Matched->Fill( bin );
	    if( bin > 0 ){
	      Matched_njets->Fill( NJets , MHT ) ;
	      Matched_btags->Fill( BTags , MHT ) ;
	      Matched_HT->Fill( HT ) ;
	      Matched_MHT->Fill( MHT ) ;
	    }
	  }
	}
      }
    }






}//event loop


gen->Draw();
accepted->Draw();
IDed->Draw("SAME");
ISOed->Draw("SAME");
Matched->Draw("SAME");

TFile *f = new TFile(outputFile,"RECREATE");
if(f){
  gen->Write();
  gen_njets->Write();
  gen_btags->Write();
  gen_HT->Write();
  gen_MHT->Write();
  accepted->Write();
  accepted_njets->Write();
  accepted_btags->Write();
  accepted_HT->Write();
  accepted_MHT->Write();
  IDed->Write();
  IDed_njets->Write();
  IDed_btags->Write();
  IDed_HT->Write();
  IDed_MHT->Write();
  ISOed->Write();
  ISOed_njets->Write();
  ISOed_btags->Write();
  ISOed_HT->Write();
  ISOed_MHT->Write();
  Matched->Write();
  Matched_njets->Write();
  Matched_btags->Write();
  Matched_HT->Write();
  Matched_MHT->Write();

}




}//main programme
