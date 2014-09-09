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

void ROC_TestforQCD(){


gROOT->ProcessLine(".L tdrstyle.C");
 setTDRStyle();

char cuts[100];

sprintf(cuts,"NJets_patJetsAK5PFPt50Eta25>=8&&HT_patJetsAK5PFPt50Eta25>500");

              TCanvas *ca = new TCanvas("ca","ca");
              TCanvas *cb = new TCanvas("cb","cb");

              TFile* sigFile_T1tttt = new TFile("T1tttt.root");
              SIGtree_T1tttt = (TTree*) sigFile_T1tttt->Get("TreeFiller/AnalysisTree");
              
              TFile* bkgFile_QCD500 = new TFile("QCD500.root");
              BKGtree_QCD500 = (TTree*) bkgFile_QCD500->Get("TreeFiller/AnalysisTree");
              
              TFile* bkgFile_QCD1000 = new TFile("QCD1000.root");
              BKGtree_QCD1000 = (TTree*) bkgFile_QCD1000->Get("TreeFiller/AnalysisTree");
           


             SIGtree_T1tttt->Draw("MHT_patJetsAK5PFPt30>>MHT_T1tttt(300,0.0000,3000.000)",cuts);
             BKGtree_QCD500->Draw("MHT_patJetsAK5PFPt30>>MHT_QCD500(300,0.0000,3000.000)",cuts);
             BKGtree_QCD1000->Draw("MHT_patJetsAK5PFPt30>>MHT_QCD1000(300,0.0000,3000.000)",cuts);
           



            TH1F* sig_MHT_T1tttt = (TH1F*) gDirectory->Get("MHT_T1tttt");
            


            TH1F* bkg_MHT_QCD500 = (TH1F*) gDirectory->Get("MHT_QCD500");
          


            TH1F* bkg_MHT_QCD1000 = (TH1F*) gDirectory->Get("MHT_QCD1000");
           


            sig_MHT_T1tttt->Scale(0.0017);
            bkg_MHT_QCD500->Scale(5.582);
            bkg_MHT_QCD1000->Scale(0.307);


           TH1F* bkg_MHT_QCD=new TH1F(*bkg_MHT_QCD500);
           bkg_MHT_QCD->Add(bkg_MHT_QCD1000);


sig_MHT_T1tttt->Scale(1/sig_MHT_T1tttt->Integral(0.0000,sig_MHT_T1tttt->GetNbinsX()+1));
bkg_MHT_QCD->Scale(1/bkg_MHT_QCD500->Integral(0.0000,bkg_MHT_QCD->GetNbinsX()+1));



ca->cd();
sig_MHT_T1tttt->SetLineColor(2);
bkg_MHT_QCD->SetLineColor(3);

sig_MHT_T1tttt->Draw();
bkg_MHT_QCD->Draw("SAME");

double Ar_sig_MHT_T1tttt[500],Ar_bkg_MHT_QCD[500];




     for(int i=0; i<500; i++){

    

      Ar_sig_MHT_T1tttt[i] = sig_MHT_T1tttt->Integral(i, 501);
      Ar_bkg_MHT_QCD[i] = bkg_MHT_QCD->Integral(i, 501);
      

      }



TGraph* ROC_MHT_QCD_T1tttt= new TGraph(500,Ar_sig_MHT_T1tttt,Ar_bkg_MHT_QCD);
ROC_MHT_QCD_T1tttt->SetLineColor(4);
ROC_MHT_QCD_T1tttt->SetLineWidth(2);



TCanvas *c1 = new TCanvas("c1","QCD");

c1->cd();
TMultiGraph *mg_qcd = new TMultiGraph();
mg_qcd->SetTitle(" ROC curve ; #epsilon_{T1tttt} ;  #epsilon_{QCD}");

mg_qcd->Add(ROC_MHT_QCD_T1tttt,"l");
mg_qcd->Draw("AP");





}
