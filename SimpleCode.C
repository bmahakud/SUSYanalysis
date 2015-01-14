#include<iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

using namespace std;



void test_code(){



TChain* SIGtree_T1tttt= new TChain("TreeMaker2/PreSelection");
SIGtree_T1tttt->Add("PHYS14.SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");


TChain* BKGtree_bkg= new TChain("TreeMaker2/PreSelection");
BKGtree_bkg->Add("PHYS14.TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");




vector<double> *tau4_ak12_sig;
vector<TLorentzVector> *ak1p2Jets_sig;





SIGtree_T1tttt->SetBranchAddress("ak1p2Jets_tau4",&tau4_ak12_sig);


SIGtree_T1tttt->SetBranchAddress("ak1p2Jets",&ak1p2Jets_sig);

vector<double> *tau4_ak12_bkg;
vector<TLorentzVector> *ak1p2Jets_bkg;





BKGtree_bkg->SetBranchAddress("ak1p2Jets_tau4",&tau4_ak12_bkg);

BKGtree_bkg->SetBranchAddress("ak1p2Jets",&ak1p2Jets_bkg);




int n_sig = (int) SIGtree_T1tttt->GetEntries();

int n_bkg = (int) BKGtree_bkg->GetEntries();





for (int i = 0; i < n_sig; ++i) {//loop over entries 

SIGtree_T1tttt->GetEntry(i);
cout<<"Event number = "<<i<<endl;
cout <<"tau4 size "<< tau4_ak12_sig->size() << endl;

cout <<"jet size "<< ak1p2Jets_sig->size() << endl;







}//loop over entries 























}
