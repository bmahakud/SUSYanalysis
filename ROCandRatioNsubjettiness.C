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
void ratioPlots(std::string HTmin="500",std::string HTmax="100000",std::string NJetsmin="3",std::string NJetsmax="20",std::string MHTmin="200",std::string MHTmax="100000",std::string NLeptonsmin="0",std::string NLeptonsmax="0"){

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



sprintf(cuts,"NJets>=%i&&NJets<=%i&&HT>=%i&&HT<=%i&&METPt>=%i&&METPt<=%i&&Leptons>=%i&&Leptons<=%i",njetsMin,njetsMax,htMin,htMax,mhtMin,mhtMax,nlepMin,nlepMax);









TChain* SIGtree_T1tttt= new TChain("TreeMaker2/PreSelection");
SIGtree_T1tttt->Add("PHYS14.SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");
TChain* BKGtree_bkg= new TChain("TreeMaker2/PreSelection");
BKGtree_bkg->Add("PHYS14.TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");


TCanvas *ca = new TCanvas("ca","ca");
TCanvas *cb = new TCanvas("cb","cb");



SIGtree_T1tttt->Draw("HT>>HT_HTJets_sig(400,0.000000,4000.000)",cuts);
SIGtree_T1tttt->Draw("MHT>>MHT_MHTJets_sig(400,0.000000,4000.000)",cuts);

SIGtree_T1tttt->Draw("ak1p2Jets_tau4[0]/ak1p2Jets_tau3[0]>>tau4by3_ak1p2Jets_sig(50,0.000000,2.000)",cuts);
SIGtree_T1tttt->Draw("ak1p2Jets_tau4[0]/ak1p2Jets_tau2[0]>>tau4by2_ak1p2Jets_sig(50,0.000000,2.000)",cuts);
SIGtree_T1tttt->Draw("ak1p2Jets_tau4[0]/ak1p2Jets_tau1[0]>>tau4by1_ak1p2Jets_sig(50,0.000000,2.000)",cuts);
SIGtree_T1tttt->Draw("ak1p2Jets_tau3[0]/ak1p2Jets_tau2[0]>>tau3by2_ak1p2Jets_sig(50,0.000000,2.000)",cuts);
SIGtree_T1tttt->Draw("ak1p2Jets_tau3[0]/ak1p2Jets_tau1[0]>>tau3by1_ak1p2Jets_sig(50,0.000000,2.000)",cuts);
SIGtree_T1tttt->Draw("ak1p2Jets_tau2[0]/ak1p2Jets_tau1[0]>>tau2by1_ak1p2Jets_sig(50,0.000000,2.000)",cuts);



BKGtree_bkg->Draw("HT>>HT_HTJets_bkg(400,0.000000,4000.000)",cuts);
BKGtree_bkg->Draw("MHT>>MHT_MHTJets_bkg(400,0.000000,4000.000)",cuts);


BKGtree_bkg->Draw("ak1p2Jets_tau4[0]/ak1p2Jets_tau3[0]>>tau4by3_ak1p2Jets_bkg(50,0.000000,2.000)",cuts);
BKGtree_bkg->Draw("ak1p2Jets_tau4[0]/ak1p2Jets_tau2[0]>>tau4by2_ak1p2Jets_bkg(50,0.000000,2.000)",cuts);
BKGtree_bkg->Draw("ak1p2Jets_tau4[0]/ak1p2Jets_tau1[0]>>tau4by1_ak1p2Jets_bkg(50,0.000000,2.000)",cuts);
BKGtree_bkg->Draw("ak1p2Jets_tau3[0]/ak1p2Jets_tau2[0]>>tau3by2_ak1p2Jets_bkg(50,0.000000,2.000)",cuts);
BKGtree_bkg->Draw("ak1p2Jets_tau3[0]/ak1p2Jets_tau1[0]>>tau3by1_ak1p2Jets_bkg(50,0.000000,2.000)",cuts);
BKGtree_bkg->Draw("ak1p2Jets_tau2[0]/ak1p2Jets_tau1[0]>>tau2by1_ak1p2Jets_bkg(50,0.000000,2.000)",cuts);









TH1F* sig_HT_HTJets = (TH1F*) gDirectory->Get("HT_HTJets_sig");
sig_HT_HTJets->SetLineColor(2);
sig_HT_HTJets->SetLineWidth(2);
//->GetXaxis()->SetTitle("");



TH1F* sig_MHT_MHTJets = (TH1F*) gDirectory->Get("MHT_MHTJets_sig");
sig_MHT_MHTJets->SetLineColor(2);
sig_MHT_MHTJets->SetLineWidth(2);



TH1F* sig_tau4by3_ak1p2Jets = (TH1F*) gDirectory->Get("tau4by3_ak1p2Jets_sig");
sig_tau4by3_ak1p2Jets->SetLineColor(2);
sig_tau4by3_ak1p2Jets->SetLineWidth(2);
sig_tau4by3_ak1p2Jets->GetXaxis()->SetTitle("tau4/tau3");
sig_tau4by3_ak1p2Jets->GetYaxis()->SetTitle("Normalized to Unity");


TH1F* sig_tau4by2_ak1p2Jets = (TH1F*) gDirectory->Get("tau4by2_ak1p2Jets_sig");
sig_tau4by2_ak1p2Jets->SetLineColor(2);
sig_tau4by2_ak1p2Jets->SetLineWidth(2);
sig_tau4by2_ak1p2Jets->GetXaxis()->SetTitle("tau4/tau2");
sig_tau4by2_ak1p2Jets->GetYaxis()->SetTitle("Normalized to Unity");


TH1F* sig_tau4by1_ak1p2Jets = (TH1F*) gDirectory->Get("tau4by1_ak1p2Jets_sig");
sig_tau4by1_ak1p2Jets->SetLineColor(2);
sig_tau4by1_ak1p2Jets->SetLineWidth(2);
sig_tau4by1_ak1p2Jets->GetXaxis()->SetTitle("tau4/tau1");
sig_tau4by1_ak1p2Jets->GetYaxis()->SetTitle("Normalized to Unity");

TH1F* sig_tau3by2_ak1p2Jets = (TH1F*) gDirectory->Get("tau3by2_ak1p2Jets_sig");
sig_tau3by2_ak1p2Jets->SetLineColor(2);
sig_tau3by2_ak1p2Jets->SetLineWidth(2);
sig_tau3by2_ak1p2Jets->GetXaxis()->SetTitle("tau3/tau2");
sig_tau3by2_ak1p2Jets->GetYaxis()->SetTitle("Normalized to Unity");


TH1F* sig_tau3by1_ak1p2Jets = (TH1F*) gDirectory->Get("tau3by1_ak1p2Jets_sig");
sig_tau3by1_ak1p2Jets->SetLineColor(2);
sig_tau3by1_ak1p2Jets->SetLineWidth(2);
sig_tau3by1_ak1p2Jets->GetXaxis()->SetTitle("tau3/tau1");
sig_tau3by1_ak1p2Jets->GetYaxis()->SetTitle("Normalized to Unity");


TH1F* sig_tau2by1_ak1p2Jets = (TH1F*) gDirectory->Get("tau2by1_ak1p2Jets_sig");
sig_tau2by1_ak1p2Jets->SetLineColor(2);
sig_tau2by1_ak1p2Jets->SetLineWidth(2);
sig_tau2by1_ak1p2Jets->GetXaxis()->SetTitle("tau2/tau1");
sig_tau2by1_ak1p2Jets->GetYaxis()->SetTitle("Normalized to Unity");


TH1F* bkg_HT_HTJets = (TH1F*) gDirectory->Get("HT_HTJets_bkg");
bkg_HT_HTJets->SetLineColor(4);
bkg_HT_HTJets->SetLineWidth(2);

TH1F* bkg_MHT_MHTJets = (TH1F*) gDirectory->Get("MHT_MHTJets_bkg");
bkg_MHT_MHTJets->SetLineColor(4);
bkg_MHT_MHTJets->SetLineWidth(2);

TH1F* bkg_tau4by3_ak1p2Jets = (TH1F*) gDirectory->Get("tau4by3_ak1p2Jets_bkg");
bkg_tau4by3_ak1p2Jets->SetLineColor(4);
bkg_tau4by3_ak1p2Jets->SetLineWidth(2);

TH1F* bkg_tau4by2_ak1p2Jets = (TH1F*) gDirectory->Get("tau4by2_ak1p2Jets_bkg");
bkg_tau4by2_ak1p2Jets->SetLineColor(4);
bkg_tau4by2_ak1p2Jets->SetLineWidth(2);

TH1F* bkg_tau4by1_ak1p2Jets = (TH1F*) gDirectory->Get("tau4by1_ak1p2Jets_bkg");
bkg_tau4by1_ak1p2Jets->SetLineColor(4);
bkg_tau4by1_ak1p2Jets->SetLineWidth(2);

TH1F* bkg_tau3by2_ak1p2Jets = (TH1F*) gDirectory->Get("tau3by2_ak1p2Jets_bkg");
bkg_tau3by2_ak1p2Jets->SetLineColor(4);
bkg_tau3by2_ak1p2Jets->SetLineWidth(2);


TH1F* bkg_tau3by1_ak1p2Jets = (TH1F*) gDirectory->Get("tau3by1_ak1p2Jets_bkg");
bkg_tau3by1_ak1p2Jets->SetLineColor(4);
bkg_tau3by1_ak1p2Jets->SetLineWidth(2);


TH1F* bkg_tau2by1_ak1p2Jets = (TH1F*) gDirectory->Get("tau2by1_ak1p2Jets_bkg");
bkg_tau2by1_ak1p2Jets->SetLineColor(4);
bkg_tau2by1_ak1p2Jets->SetLineWidth(2);






sig_HT_HTJets->Scale(1/sig_HT_HTJets->Integral());
sig_MHT_MHTJets->Scale(1/sig_MHT_MHTJets->Integral());
sig_tau4by3_ak1p2Jets->Scale(1/sig_tau4by3_ak1p2Jets->Integral());
sig_tau4by2_ak1p2Jets->Scale(1/sig_tau4by2_ak1p2Jets->Integral());
sig_tau4by1_ak1p2Jets->Scale(1/sig_tau4by1_ak1p2Jets->Integral());
sig_tau3by2_ak1p2Jets->Scale(1/sig_tau3by2_ak1p2Jets->Integral());
sig_tau3by1_ak1p2Jets->Scale(1/sig_tau3by1_ak1p2Jets->Integral());
sig_tau2by1_ak1p2Jets->Scale(1/sig_tau2by1_ak1p2Jets->Integral());


bkg_HT_HTJets->Scale(1/bkg_HT_HTJets->Integral());
bkg_MHT_MHTJets->Scale(1/bkg_MHT_MHTJets->Integral());
bkg_tau4by3_ak1p2Jets->Scale(1/bkg_tau4by3_ak1p2Jets->Integral());
bkg_tau4by2_ak1p2Jets->Scale(1/bkg_tau4by2_ak1p2Jets->Integral());
bkg_tau4by1_ak1p2Jets->Scale(1/bkg_tau4by1_ak1p2Jets->Integral());
bkg_tau3by2_ak1p2Jets->Scale(1/bkg_tau3by2_ak1p2Jets->Integral());
bkg_tau3by1_ak1p2Jets->Scale(1/bkg_tau3by1_ak1p2Jets->Integral());
bkg_tau2by1_ak1p2Jets->Scale(1/bkg_tau2by1_ak1p2Jets->Integral());



leg_1D[1]->AddEntry(sig_tau4by3_ak1p2Jets,"tau4/tau3(T1tttt)","l");
leg_1D[1]->AddEntry(bkg_tau4by3_ak1p2Jets,"tau4/tau3(ttbar)","l");


leg_1D[2]->AddEntry(sig_tau4by2_ak1p2Jets,"tau4/tau2(T1tttt)","l");
leg_1D[2]->AddEntry(bkg_tau4by2_ak1p2Jets,"tau4/tau2(ttbar)","l");


leg_1D[3]->AddEntry(sig_tau4by1_ak1p2Jets,"tau4/tau1(T1tttt)","l");
leg_1D[3]->AddEntry(bkg_tau4by1_ak1p2Jets,"tau4/tau1(ttbar)","l");


leg_1D[4]->AddEntry(sig_tau3by2_ak1p2Jets,"tau3/tau2(T1tttt)","l");
leg_1D[4]->AddEntry(bkg_tau3by2_ak1p2Jets,"tau3/tau2(ttbar)","l");


leg_1D[5]->AddEntry(sig_tau3by1_ak1p2Jets,"tau3/tau1(T1tttt)","l");
leg_1D[5]->AddEntry(bkg_tau3by1_ak1p2Jets,"tau3/tau1(ttbar)","l");


leg_1D[6]->AddEntry(sig_tau2by1_ak1p2Jets,"tau2/tau1(T1tttt)","l");
leg_1D[6]->AddEntry(bkg_tau2by1_ak1p2Jets,"tau2/tau1(ttbar)","l");





char Cname1[100];
TCanvas *c_1D[6];
for(int k0=0;k0<6;k0++){
sprintf(Cname1,"c_1D%i",k0);
c_1D[k0]=new TCanvas(Cname1,Cname1,1000,800);
c_1D[k0]->Divide(2,2);
}



c_1D[0]->cd(1);
sig_tau4by3_ak1p2Jets->Draw();
bkg_tau4by3_ak1p2Jets->Draw("SAME");
leg_1D[1]->Draw();



c_1D[0]->cd(2);
sig_tau4by2_ak1p2Jets->Draw();
bkg_tau4by2_ak1p2Jets->Draw("SAME");
leg_1D[2]->Draw();


c_1D[0]->cd(3);
sig_tau4by1_ak1p2Jets->Draw();
bkg_tau4by1_ak1p2Jets->Draw("SAME");
leg_1D[3]->Draw();


c_1D[0]->cd(4);
sig_tau3by2_ak1p2Jets->Draw();
bkg_tau3by2_ak1p2Jets->Draw("SAME");
leg_1D[4]->Draw();


c_1D[1]->cd(1);
sig_tau3by1_ak1p2Jets->Draw();
bkg_tau3by1_ak1p2Jets->Draw("SAME");
leg_1D[5]->Draw();


c_1D[1]->cd(2);
sig_tau2by1_ak1p2Jets->Draw();
bkg_tau2by1_ak1p2Jets->Draw("SAME");

leg_1D[6]->Draw();







double Ar_sig_HT_HTJets[500];
double Ar_sig_MHT_MHTJets[500];

double Ar_sig_tau4by3_ak1p2Jets[500];
double Ar_sig_tau4by2_ak1p2Jets[500];
double Ar_sig_tau4by1_ak1p2Jets[500];
double Ar_sig_tau3by2_ak1p2Jets[500];
double Ar_sig_tau3by1_ak1p2Jets[500];
double Ar_sig_tau2by1_ak1p2Jets[500];


double Ar_bkg_HT_HTJets[500];
double Ar_bkg_MHT_MHTJets[500];

double Ar_bkg_tau4by3_ak1p2Jets[500];
double Ar_bkg_tau4by2_ak1p2Jets[500];
double Ar_bkg_tau4by1_ak1p2Jets[500];
double Ar_bkg_tau3by2_ak1p2Jets[500];
double Ar_bkg_tau3by1_ak1p2Jets[500];
double Ar_bkg_tau2by1_ak1p2Jets[500];



for(int i=0; i<500; i++){


Ar_sig_HT_HTJets[i] =sig_HT_HTJets->Integral(i, 501);
Ar_sig_MHT_MHTJets[i] =sig_MHT_MHTJets->Integral(i, 501);
Ar_sig_tau4by3_ak1p2Jets[i] =sig_tau4by3_ak1p2Jets->Integral(i, 501);
Ar_sig_tau4by2_ak1p2Jets[i] =sig_tau4by2_ak1p2Jets->Integral(i, 501);
Ar_sig_tau4by1_ak1p2Jets[i] =sig_tau4by1_ak1p2Jets->Integral(i, 501);
Ar_sig_tau3by2_ak1p2Jets[i] =sig_tau3by2_ak1p2Jets->Integral(i, 501);
Ar_sig_tau3by1_ak1p2Jets[i] =sig_tau3by1_ak1p2Jets->Integral(i, 501);
Ar_sig_tau2by1_ak1p2Jets[i] =sig_tau2by1_ak1p2Jets->Integral(i, 501);

Ar_bkg_HT_HTJets[i] =bkg_HT_HTJets->Integral(i, 501);
Ar_bkg_MHT_MHTJets[i] =bkg_MHT_MHTJets->Integral(i, 501);
Ar_bkg_tau4by3_ak1p2Jets[i] =bkg_tau4by3_ak1p2Jets->Integral(i, 501);
Ar_bkg_tau4by2_ak1p2Jets[i] =bkg_tau4by2_ak1p2Jets->Integral(i, 501);
Ar_bkg_tau4by1_ak1p2Jets[i] =bkg_tau4by1_ak1p2Jets->Integral(i, 501);
Ar_bkg_tau3by2_ak1p2Jets[i] =bkg_tau3by2_ak1p2Jets->Integral(i, 501);
Ar_bkg_tau3by1_ak1p2Jets[i] =bkg_tau3by1_ak1p2Jets->Integral(i, 501);
Ar_bkg_tau2by1_ak1p2Jets[i] =bkg_tau2by1_ak1p2Jets->Integral(i, 501);




}



TGraph* HT_ROC= new TGraph(500,Ar_sig_HT_HTJets,Ar_bkg_HT_HTJets);
HT_ROC->SetLineColor(1);
HT_ROC->SetLineWidth(2);

TGraph* MHT_ROC= new TGraph(500,Ar_sig_MHT_MHTJets,Ar_bkg_MHT_MHTJets);
MHT_ROC->SetLineColor(2);
MHT_ROC->SetLineWidth(2);


TGraph* tau4by3_ak1p2Jets_ROC= new TGraph(500,Ar_sig_tau4by3_ak1p2Jets,Ar_bkg_tau4by3_ak1p2Jets);
tau4by3_ak1p2Jets_ROC->SetLineColor(1);
tau4by3_ak1p2Jets_ROC->SetLineWidth(2);


TGraph* tau4by2_ak1p2Jets_ROC= new TGraph(500,Ar_sig_tau4by2_ak1p2Jets,Ar_bkg_tau4by2_ak1p2Jets);
tau4by2_ak1p2Jets_ROC->SetLineColor(2);
tau4by2_ak1p2Jets_ROC->SetLineWidth(2);

TGraph* tau4by1_ak1p2Jets_ROC= new TGraph(500,Ar_sig_tau4by1_ak1p2Jets,Ar_bkg_tau4by1_ak1p2Jets);
tau4by1_ak1p2Jets_ROC->SetLineColor(3);
tau4by1_ak1p2Jets_ROC->SetLineWidth(2);


TGraph* tau3by2_ak1p2Jets_ROC= new TGraph(500,Ar_sig_tau3by2_ak1p2Jets,Ar_bkg_tau3by2_ak1p2Jets);
tau3by2_ak1p2Jets_ROC->SetLineColor(4);
tau3by2_ak1p2Jets_ROC->SetLineWidth(2);

TGraph* tau3by1_ak1p2Jets_ROC= new TGraph(500,Ar_sig_tau3by1_ak1p2Jets,Ar_bkg_tau3by1_ak1p2Jets);
tau3by1_ak1p2Jets_ROC->SetLineColor(5);
tau3by1_ak1p2Jets_ROC->SetLineWidth(2);


TGraph* tau2by1_ak1p2Jets_ROC= new TGraph(500,Ar_sig_tau2by1_ak1p2Jets,Ar_bkg_tau2by1_ak1p2Jets);
tau2by1_ak1p2Jets_ROC->SetLineColor(7);
tau2by1_ak1p2Jets_ROC->SetLineWidth(2);



//leg_1D[0]->AddEntry(HT_ROC,"HT","l");
leg_1D[0]->AddEntry(tau4by3_ak1p2Jets_ROC,"tau4/tau3","l");
leg_1D[0]->AddEntry(tau4by2_ak1p2Jets_ROC,"tau4/tau2","l");
leg_1D[0]->AddEntry(tau4by1_ak1p2Jets_ROC,"tau4/tau1","l");
leg_1D[0]->AddEntry(tau3by2_ak1p2Jets_ROC,"tau3/tau2","l");
leg_1D[0]->AddEntry(tau3by1_ak1p2Jets_ROC,"tau3/tau1","l");
leg_1D[0]->AddEntry(tau2by1_ak1p2Jets_ROC,"tau2/tau1","l");



char TMgname1[100];
TMultiGraph *TMg_1D[5];
for(int k0=0;k0<5;k0++){
sprintf(TMgname1,"TMg_1D%i",k0);
TMg_1D[k0]=new TMultiGraph();
}

TMg_1D[0]->SetTitle(" ROC curve ; #epsilon_{T1tttt} ; #epsilon_{ttbar}");
//TMg_1D[0]->Add(HT_ROC);
//TMg_1D[0]->Add(MHT_ROC);
TMg_1D[0]->Add(tau4by3_ak1p2Jets_ROC);
TMg_1D[0]->Add(tau4by2_ak1p2Jets_ROC);
TMg_1D[0]->Add(tau4by1_ak1p2Jets_ROC);
TMg_1D[0]->Add(tau3by2_ak1p2Jets_ROC);
TMg_1D[0]->Add(tau3by1_ak1p2Jets_ROC);
TMg_1D[0]->Add(tau2by1_ak1p2Jets_ROC);





TCanvas *c= new TCanvas("c","c");
c->cd();
TMg_1D[0]->Draw("APC");

leg_1D[0]->Draw();
tex1->Draw();















}
