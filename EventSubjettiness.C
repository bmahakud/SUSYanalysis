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

void EventSubjettiness(std::string HTmin="500",std::string HTmax="100000",std::string NJetsmin="3",std::string NJetsmax="20",std::string MHTmin="200",std::string MHTmax="100000",std::string NLeptonsmin="0",std::string NLeptonsmax="0"){

gROOT->ProcessLine(".L tdrstyle.C");
setTDRStyle();

char Legname1[100];
TLegend *leg_1D[10];
for(int k0=0;k0<10;k0++){
sprintf(Legname1,"leg_1D%i",k0);
leg_1D[k0]=new TLegend(0.10,0.25,0.35,0.7);
leg_1D[k0]->SetTextFont(62);
leg_1D[k0]->SetTextSize(0.04);
leg_1D[k0]->SetLineColor(1);
leg_1D[k0]->SetLineStyle(1);
leg_1D[k0]->SetLineWidth(7);
leg_1D[k0]->SetFillColor(0);
leg_1D[k0]->SetFillStyle(1001);
leg_1D[k0]->SetShadowColor(0);
leg_1D[k0]->SetDrawOption(0);
leg_1D[k0]->SetBorderSize(0);
}


char njets_pav[50];
char ht_pav[50];
char signal[100];








int NleptonsMin = atoi(NLeptonsmin.c_str());
int NleptonsMax = atoi(NLeptonsmax.c_str());


int NJetsMin = atoi(NJetsmin.c_str());
int NJetsMax = atoi(NJetsmax.c_str());
double HT_Min=atoi(HTmin.c_str());
double HT_Max=atoi(HTmax.c_str());
double MHT_Min=atoi(MHTmin.c_str());
double MHT_Max=atoi(MHTmax.c_str());
//gROOT->ProcessLine(".L tdrstyle.C");
//setTDRStyle();
char cuts[300];

char filenamettbar[50];
char signal[100];
double htMin=HT_Min;
double htMax=HT_Max;
double mhtMin=MHT_Min;
double mhtMax=MHT_Max;
int njetsMin=NJetsMin;
int njetsMax=NJetsMax;
int nlepMin=NleptonsMin;
int nlepMax=NleptonsMax;

char filenameOverlaid[50];
char Legname1[100];
TLegend *leg_1D[10];
for(int k0=0;k0<10;k0++){
sprintf(Legname1,"leg_1D%i",k0);
leg_1D[k0]=new TLegend(0.10,0.25,0.35,0.7);
leg_1D[k0]->SetTextFont(62);
leg_1D[k0]->SetTextSize(0.04);
leg_1D[k0]->SetLineColor(1);
leg_1D[k0]->SetLineStyle(1);
leg_1D[k0]->SetLineWidth(7);
leg_1D[k0]->SetFillColor(0);
leg_1D[k0]->SetFillStyle(1001);
leg_1D[k0]->SetShadowColor(0);
leg_1D[k0]->SetDrawOption(0);
leg_1D[k0]->SetBorderSize(0);
}

sprintf(signal,"T1tttt(mGo=1500GeV ,mLSP=100 GeV)");
sprintf(njets_pav,"%i#leqHT#leq%i",htMin,htMax);
sprintf(ht_pav,"%i#leqJets#leq%i",njetsMin,njetsMax);
TPaveText *tex1 = new TPaveText(0.204698,0.7377622,0.4043624,0.8863636,"brNDC");
tex1->SetBorderSize(0);
tex1->SetFillStyle(0);
tex1->SetTextAlign(11);
tex1->SetTextFont(42);
tex1->SetTextSize(0.04);
text = tex1->AddText(signal);
text = tex1->AddText("HT>500");
text = tex1->AddText("NJets>=3");
text = tex1->AddText("METpt > 200");
text = tex1->AddText("nLeptons==0");


sprintf(signal,"T1tttt(mGo=1500GeV ,mLSP=100 GeV)");
sprintf(njets_pav,"%i#leqHT#leq%i",htMin,htMax);
sprintf(ht_pav,"%i#leqJets#leq%i",njetsMin,njetsMax);
TPaveText *tex1 = new TPaveText(0.204698,0.7377622,0.4043624,0.8863636,"brNDC");
tex1->SetBorderSize(0);
tex1->SetFillStyle(0);
tex1->SetTextAlign(11);
tex1->SetTextFont(42);
tex1->SetTextSize(0.04);
text = tex1->AddText(signal);
text = tex1->AddText("HT>500");
text = tex1->AddText("NJets>=3");
text = tex1->AddText("MHT > 200");



sprintf(cuts,"NJets>=%i&&NJets<=%i&&HT>=%i&&HT<=%i&&METPt>=%i&&METPt<=%i&&Leptons>=%i&&Leptons<=%i",njetsMin,njetsMax,htMin,htMax,mhtMin,mhtMax,nlepMin,nlepMax);









TChain* SIGtree_T1tttt= new TChain("TreeMaker2/PreSelection");
SIGtree_T1tttt->Add("PHYS14.SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");
TChain* BKGtree_bkg= new TChain("TreeMaker2/PreSelection");
BKGtree_bkg->Add("PHYS14.TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");


TCanvas *ca = new TCanvas("ca","ca");
TCanvas *cb = new TCanvas("cb","cb");


SIGtree_T1tttt->Draw("NJets>>NJets_sig(15,0.000000,15.000)",cuts);

SIGtree_T1tttt->Draw("((ak1p2Jets_tau4[0]/ak1p2Jets_tau3[0]+ak1p2Jets_tau4[1]/ak1p2Jets_tau3[1]+ak1p2Jets_tau4[2]/ak1p2Jets_tau3[2]+ak1p2Jets_tau4[3]/ak1p2Jets_tau3[3])/4)>>tau4by3_ak1p2Jets_sig(50,0.000000,1.000)",cuts);



BKGtree_bkg->Draw("NJets>>NJets_bkg(15,0.000000,15.000)",cuts);


BKGtree_bkg->Draw("((ak1p2Jets_tau4[0]/ak1p2Jets_tau3[0]+ak1p2Jets_tau4[1]/ak1p2Jets_tau3[1]+ak1p2Jets_tau4[2]/ak1p2Jets_tau3[2]+ak1p2Jets_tau4[3]/ak1p2Jets_tau3[3])/4)>>tau4by3_ak1p2Jets_bkg(50,0.000000,1.000)",cuts);



TH1F* sig_NJets = (TH1F*) gDirectory->Get("NJets_sig");
sig_NJets->SetLineColor(2);
sig_NJets->SetLineWidth(2);
sig_NJets->GetXaxis()->SetTitle("Num_fatjets");
sig_NJets->GetYaxis()->SetTitle("Normalized to Unity");


TH1F* sig_tau4by3_ak1p2Jets = (TH1F*) gDirectory->Get("tau4by3_ak1p2Jets_sig");
sig_tau4by3_ak1p2Jets->SetLineColor(2);
sig_tau4by3_ak1p2Jets->SetLineWidth(2);
sig_tau4by3_ak1p2Jets->GetXaxis()->SetTitle("Event subjettiness(mean of tau4/tau3)");
sig_tau4by3_ak1p2Jets->GetYaxis()->SetTitle("Normalized to Unity");


TH1F* bkg_NJets = (TH1F*) gDirectory->Get("NJets_bkg");
bkg_NJets->SetLineColor(4);
bkg_NJets->SetLineWidth(2);


TH1F* bkg_tau4by3_ak1p2Jets = (TH1F*) gDirectory->Get("tau4by3_ak1p2Jets_bkg");
bkg_tau4by3_ak1p2Jets->SetLineColor(4);
bkg_tau4by3_ak1p2Jets->SetLineWidth(2);

sig_NJets->Scale(1/sig_NJets->Integral());
bkg_NJets->Scale(1/bkg_NJets->Integral());

sig_tau4by3_ak1p2Jets->Scale(1/sig_tau4by3_ak1p2Jets->Integral());
bkg_tau4by3_ak1p2Jets->Scale(1/bkg_tau4by3_ak1p2Jets->Integral());


leg_1D[0]->AddEntry(sig_NJets,"T1tttt","l");
leg_1D[0]->AddEntry(bkg_NJets,"ttbar","l");


leg_1D[1]->AddEntry(sig_tau4by3_ak1p2Jets,"T1tttt","l");
leg_1D[1]->AddEntry(bkg_tau4by3_ak1p2Jets,"ttbar","l");


char Cname1[100];
TCanvas *c_1D[2];
for(int k0=0;k0<2;k0++){
sprintf(Cname1,"c_1D%i",k0);
c_1D[k0]=new TCanvas(Cname1,Cname1,1000,800);
c_1D[k0]->Divide(2,1);
}


c_1D[0]->cd(1);

sig_NJets->Draw();
bkg_NJets->Draw("SAME");
leg_1D[0]->Draw();
tex1->Draw();

c_1D[0]->cd(2);
sig_tau4by3_ak1p2Jets->Draw();
bkg_tau4by3_ak1p2Jets->Draw("SAME");
leg_1D[1]->Draw();
tex1->Draw();



}





















