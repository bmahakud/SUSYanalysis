#include<iostream>
#include<vector>
#include "TH1.h"
#include "TGraph.h"
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
using namespace std;

void understandROC(){

TCanvas *c1 = new TCanvas("a1","b1");
TCanvas *c2 = new TCanvas("a2","b2");

    TFile* sigFile = new TFile("SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPAT_SumJetMass_AnalysisTree.root");
    SIGtree = (TTree*) sigFile->Get("TreeFiller/AnalysisTree");


   TFile* bkgFile = new TFile("QCD_1000HTinf_LPCSUSYPAT_SLIM_SumJetMass_AnalysisTree.root");
    BKGtree = (TTree*) bkgFile->Get("TreeFiller/AnalysisTree");

  

TString branchName_="sumJetMass_ak1p2Jets";


    char drawString[150];
    
   
   SIGtree->Draw("sumJetMass_ak1p2Jets>>SIGhist(500,0.000000,2500.000000)");
    
    
  
    BKGtree->Draw("sumJetMass_ak1p2Jets>>BKGhist(500,0.000000,2500.000000)");


    TH1F* SIGhisto_ = (TH1F*) gDirectory->Get("SIGhist");
    SIGhisto_->Scale(1/SIGhisto_->Integral(0,SIGhisto_->GetNbinsX()+1));


    TH1F* BKGhisto_ = (TH1F*) gDirectory->Get("BKGhist");
    BKGhisto_->Scale(1/BKGhisto_->Integral(0,BKGhisto_->GetNbinsX()+1));
 





   
   double effSIG[500],effBKG[500];

    for(int i=0; i<500; i++){

      effSIG[i] = SIGhisto_->Integral(i, 501);
      effBKG[i] = BKGhisto_->Integral(i, 501);

    }

  TGraph* ROC= new TGraph(500,effSIG,effBKG) ;

  c1->cd();
 ROC->Draw();



}
