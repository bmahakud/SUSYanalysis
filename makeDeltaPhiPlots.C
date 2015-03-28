#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TChain.h"
#include "TString.h"
#include <vector>
#include <iostream>

using namespace std;


void makeDeltaPhiPlots(){

  TChain* t1 = new TChain("TreeMaker2/PreSelection");
  t1->Add("/eos/uscms/store/user/awhitbe1/photonTesting/PHYS14.ZJetsToNuNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");

  TChain* t2 = new TChain("TreeMaker2/PreSelection");
  t2->Add("/eos/uscms/store/user/awhitbe1/photonTesting/PHYS14.ZJetsToNuNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");

  TChain* t3 = new TChain("TreeMaker2/PreSelection");
  t3->Add("/eos/uscms/store/user/awhitbe1/photonTesting/PHYS14.GJets_HT-400to600_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");

  TChain* t4 = new TChain("TreeMaker2/PreSelection");
  t4->Add("/eos/uscms/store/user/awhitbe1/photonTesting/PHYS14.GJets_HT-600toInf_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");

TFile *f = new TFile("BaseLineVars.root","RECREATE");


float HTt1, MHTt1,minDeltaPhiNt1,minDeltaPhiNnoPhotonst1,DeltaPhi1noPhotonst1,DeltaPhi2noPhotonst1,DeltaPhi3noPhotonst1;
  int NJetst1, BTagst1;

  t1->SetBranchAddress( "HTnoPhotons" , &HTt1 );
  t1->SetBranchAddress( "MHTnoPhotons" , &MHTt1 );
  t1->SetBranchAddress( "NJetsNoPhotons" , &NJetst1 );
  t1->SetBranchAddress( "BTags" , &BTagst1 );
  t1->SetBranchAddress("minDeltaPhiN",&minDeltaPhiNt1);
  t1->SetBranchAddress("DeltaPhi1noPhotons",&DeltaPhi1noPhotonst1);
  t1->SetBranchAddress("DeltaPhi2noPhotons",&DeltaPhi2noPhotonst1);
  t1->SetBranchAddress("DeltaPhi3noPhotons",&DeltaPhi3noPhotonst1);
  t1->SetBranchAddress("minDeltaPhiNnoPhotons",&minDeltaPhiNnoPhotonst1);


float HTt2, MHTt2,minDeltaPhiNt2,minDeltaPhiNnoPhotonst2,DeltaPhi1noPhotonst2,DeltaPhi2noPhotonst2,DeltaPhi3noPhotonst2;
  int NJetst2, BTagst2;

  t2->SetBranchAddress( "HTnoPhotons" , &HTt2 );
  t2->SetBranchAddress( "MHTnoPhotons" , &MHTt2 );
  t2->SetBranchAddress( "NJetsNoPhotons" , &NJetst2 );
  t2->SetBranchAddress( "BTags" , &BTagst2 );
  t2->SetBranchAddress("minDeltaPhiN",&minDeltaPhiNt2);
  t2->SetBranchAddress("DeltaPhi1noPhotons",&DeltaPhi1noPhotonst2);
  t2->SetBranchAddress("DeltaPhi2noPhotons",&DeltaPhi2noPhotonst2);
  t2->SetBranchAddress("DeltaPhi3noPhotons",&DeltaPhi3noPhotonst2);
  t2->SetBranchAddress("minDeltaPhiNnoPhotons",&minDeltaPhiNnoPhotonst2);



float HTt3, MHTt3,minDeltaPhiNt3,minDeltaPhiNnoPhotonst3,DeltaPhi1noPhotonst3,DeltaPhi2noPhotonst3,DeltaPhi3noPhotonst3;
  int NJetst3, BTagst3;

  t3->SetBranchAddress( "HTnoPhotons" , &HTt3 );
  t3->SetBranchAddress( "MHTnoPhotons" , &MHTt3 );
  t3->SetBranchAddress( "NJetsNoPhotons" , &NJetst3 );
  t3->SetBranchAddress( "BTags" , &BTagst3 );
  t3->SetBranchAddress("minDeltaPhiN",&minDeltaPhiNt3);
  t3->SetBranchAddress("DeltaPhi1noPhotons",&DeltaPhi1noPhotonst3);
  t3->SetBranchAddress("DeltaPhi2noPhotons",&DeltaPhi2noPhotonst3);
  t3->SetBranchAddress("DeltaPhi3noPhotons",&DeltaPhi3noPhotonst3);
  t3->SetBranchAddress("minDeltaPhiNnoPhotons",&minDeltaPhiNnoPhotonst3);

  float HTt4, MHTt4,minDeltaPhiNt4,minDeltaPhiNnoPhotonst4,DeltaPhi1noPhotonst4,DeltaPhi2noPhotonst4,DeltaPhi3noPhotonst4;
  int NJetst4, BTagst4;

  t4->SetBranchAddress( "HTnoPhotons" , &HTt4 );
  t4->SetBranchAddress( "MHTnoPhotons" , &MHTt4 );
  t4->SetBranchAddress( "NJetsNoPhotons" , &NJetst4 );
  t4->SetBranchAddress( "BTags" , &BTagst4 );
  t4->SetBranchAddress("minDeltaPhiN",&minDeltaPhiNt4);
  t4->SetBranchAddress("DeltaPhi1noPhotons",&DeltaPhi1noPhotonst4);
  t4->SetBranchAddress("DeltaPhi2noPhotons",&DeltaPhi2noPhotonst4);
  t4->SetBranchAddress("DeltaPhi3noPhotons",&DeltaPhi3noPhotonst4);
  t4->SetBranchAddress("minDeltaPhiNnoPhotons",&minDeltaPhiNnoPhotonst4);


  TH1F* dPhi1binG400 = new TH1F("dPhi1binG400","dPhi1bin",200,-10,10);
  TH1F* dPhi2binG400 = new TH1F("dPhi2binG400","dPhi2bin",200,-10,10);
  TH1F* dPhi3binG400 = new TH1F("dPhi3binG400","dPhi3bin",200,-10,10);
  TH1F* mindPhiNbinG400 = new TH1F("mindPhiNbinG400","mindPhiNbin",300,-50,50);


  TH1F* dPhi1binG600 = new TH1F("dPhi1binG600","dPhi1bin",200,-10,10);
  TH1F* dPhi2binG600 = new TH1F("dPhi2binG600","dPhi2bin",200,-10,10);
  TH1F* dPhi3binG600 = new TH1F("dPhi3binG600","dPhi3bin",200,-10,10);
  TH1F* mindPhiNbinG600 = new TH1F("mindPhiNbinG600","mindPhiNbin",300,-50,50);

  TH1F* dPhi1binZ400 = new TH1F("dPhi1binZ400","dPhi1bin",200,-10,10);
  TH1F* dPhi2binZ400 = new TH1F("dPhi2binZ400","dPhi2bin",200,-10,10);
  TH1F* dPhi3binZ400 = new TH1F("dPhi3binZ400","dPhi3bin",200,-10,10);
  TH1F* mindPhiNbinZ400 = new TH1F("mindPhiNbinZ400","mindPhiNbin",300,-50,50);

  TH1F* dPhi1binZ600 = new TH1F("dPhi1binZ600","dPhi1bin",200,-10,10);
  TH1F* dPhi2binZ600 = new TH1F("dPhi2binZ600","dPhi2bin",200,-10,10);
  TH1F* dPhi3binZ600 = new TH1F("dPhi3binZ600","dPhi3bin",200,-10,10);
  TH1F* mindPhiNbinZ600 = new TH1F("mindPhiNbinZ600","mindPhiNbin",300,-50,50);





  for(int i=0;i<t1->GetEntries();i++){//event loop G400
t1->GetEntry(i);

if(i%100000==0)std::cout<<"Evt = "<<i<<std::endl;
if(MHTt1 > 200 && HTt1 > 500 && NJetst1 >= 4){//baseline cut one
dPhi1binG400->Fill(DeltaPhi1noPhotonst1);
dPhi2binG400->Fill(DeltaPhi2noPhotonst1);
dPhi3binG400->Fill(DeltaPhi3noPhotonst1);
mindPhiNbinG400->Fill(minDeltaPhiNnoPhotonst1);

}///baseline cut one


}//event loop G400


 for(int i=0;i<t2->GetEntries();i++){//event loop G600
t2->GetEntry(i);

if(i%100000==0)std::cout<<"Evt = "<<i<<std::endl;
if(MHTt2 > 200 && HTt2 > 500 && NJetst2 >= 4){//baseline cut one
dPhi1binG600->Fill(DeltaPhi1noPhotonst2);
dPhi2binG600->Fill(DeltaPhi2noPhotonst2);
dPhi3binG600->Fill(DeltaPhi3noPhotonst2);
mindPhiNbinG600->Fill(minDeltaPhiNnoPhotonst2);

}///baseline cut one


}//event loop G600

  


 for(int i=0;i<t3->GetEntries();i++){//event loop Z400
t3->GetEntry(i);
if(i%100000==0)std::cout<<"Evt = "<<i<<std::endl;

if(MHTt3 > 200 && HTt3 > 500 && NJetst3 >= 4){//baseline cut one
dPhi1binZ400->Fill(DeltaPhi1noPhotonst3);
dPhi2binZ400->Fill(DeltaPhi2noPhotonst3);
dPhi3binZ400->Fill(DeltaPhi3noPhotonst3);
mindPhiNbinZ400->Fill(minDeltaPhiNnoPhotonst3);

}///baseline cut one


}//event loop Z400





 for(int i=0;i<t4->GetEntries();i++){//event loop Z600
t4->GetEntry(i);

if(i%100000==0)std::cout<<"Evt = "<<i<<std::endl;
if(MHTt4 > 200 && HTt4 > 500 && NJetst4 >= 4){//baseline cut one
dPhi1binZ600->Fill(DeltaPhi1noPhotonst4);
dPhi2binZ600->Fill(DeltaPhi2noPhotonst4);
dPhi3binZ600->Fill(DeltaPhi3noPhotonst4);
mindPhiNbinZ600->Fill(minDeltaPhiNnoPhotonst4);

}///baseline cut one


}//event loop Z600









f->Write();












}//main programme
