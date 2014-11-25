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
void MyROCnew(std::string HTmin="500",std::string HTmax="100000",std::string NJetsmin="8",std::string NJetsmax="20",std::string MHTmin="200",std::string MHTmax="100000"){

int NJetsMin = atoi(NJetsmin.c_str());
int NJetsMax = atoi(NJetsmax.c_str());


double HT_Min=atoi(HTmin.c_str());
double HT_Max=atoi(HTmax.c_str());

double MHT_Min=atoi(MHTmin.c_str());
double MHT_Max=atoi(MHTmax.c_str());

gROOT->ProcessLine(".L tdrstyle.C");
setTDRStyle();

char cuts[300];
char njets_pav[50];
char ht_pav[50];








char filenamettbar[50];

char signal[100];

double htMin=HT_Min;
double htMax=HT_Max;

double mhtMin=MHT_Min;
double mhtMax=MHT_Max;

int njetsMin=NJetsMin;
int njetsMax=NJetsMax;

char filenameOverlaid[50];


char Legname1[100];
TLegend *leg_1D[10];
for(int k0=0;k0<5;k0++){
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
text = tex1->AddText("NJets>=8");
text = tex1->AddText("MHT > 200");



sprintf(cuts,"NJets_HTJets>=%i&&NJets_HTJets<=%i&&HT_HTJets>=%i&&HT_HTJets<=%i&&MHT_MHTJets>=%i&&MHT_MHTJets<=%i",njetsMin,njetsMax,htMin,htMax,mhtMin,mhtMax);


TChain* SIGtree_T1tttt= new TChain("TreeFiller/AnalysisTree");
SIGtree_T1tttt->Add("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V11/25ns20PU.SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_*_SumJetMass_AnalysisTree.root");

TChain* BKGtree_ttbar= new TChain("TreeFiller/AnalysisTree");
BKGtree_ttbar->Add("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V11/25ns20PU.TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_*_SumJetMass_AnalysisTree.root");


TCanvas *ca = new TCanvas("ca","ca");
TCanvas *cb = new TCanvas("cb","cb");
cout<<"test-1"<<endl;

SIGtree_T1tttt->Draw("HT_HTJets>>HT_HTJets_signal(400,0.000000,4000.000)",cuts);
SIGtree_T1tttt->Draw("HT_MHTJets>>MHT_MHTJets_signal(400,0.000000,4000.000)",cuts);
SIGtree_T1tttt->Draw("sumJetMass_ak1p2Jets>>sumJetMass_ak1p2Jets_signal(400,0.000000,4000.000)",cuts);
SIGtree_T1tttt->Draw("sumJetMass_fattenedJetsPt10>>sumJetMass_fattenedJetsPt10_signal(400,0.000000,4000.000)",cuts);
SIGtree_T1tttt->Draw("sumJetMass_fattenedJetsPt20>>sumJetMass_fattenedJetsPt20_signal(400,0.000000,4000.000)",cuts);
SIGtree_T1tttt->Draw("sumJetMass_fattenedJetsPt30>>sumJetMass_fattenedJetsPt30_signal(400,0.000000,4000.000)",cuts);
SIGtree_T1tttt->Draw("sumJetMass_fattenedJetsPt50>>sumJetMass_fattenedJetsPt50_signal(400,0.000000,4000.000)",cuts);

cout<<"test-2"<<endl;
BKGtree_ttbar->Draw("HT_HTJets>>HT_HTJets_ttbar(400,0.000000,4000.000)",cuts);
cout<<"test-3"<<endl;
BKGtree_ttbar->Draw("HT_MHTJets>>MHT_MHTJets_ttbar(400,0.000000,4000.000)",cuts);
cout<<"test-4"<<endl;
BKGtree_ttbar->Draw("sumJetMass_ak1p2Jets>>sumJetMass_ak1p2Jets_ttbar(400,0.000000,4000.000)",cuts);
cout<<"test-5"<<endl;
BKGtree_ttbar->Draw("sumJetMass_fattenedJetsPt10>>sumJetMass_fattenedJetsPt10_ttbar(400,0.000000,4000.000)",cuts);
cout<<"test-6"<<endl;
BKGtree_ttbar->Draw("sumJetMass_fattenedJetsPt20>>sumJetMass_fattenedJetsPt20_ttbar(400,0.000000,4000.000)",cuts);
cout<<"test-7"<<endl;
BKGtree_ttbar->Draw("sumJetMass_fattenedJetsPt30>>sumJetMass_fattenedJetsPt30_ttbar(400,0.000000,4000.000)",cuts);
cout<<"test-8"<<endl;
BKGtree_ttbar->Draw("sumJetMass_fattenedJetsPt50>>sumJetMass_fattenedJetsPt50_ttbar(400,0.000000,4000.000)",cuts);
cout<<"test-9"<<endl;


TH1F* sig_HT_HTJets = (TH1F*) gDirectory->Get("HT_HTJets_signal");

TH1F* sig_MHT_MHTJets = (TH1F*) gDirectory->Get("MHT_MHTJets_signal");

TH1F* sig_sumJetMass_ak1p2Jets  = (TH1F*) gDirectory->Get("sumJetMass_ak1p2Jets_signal");

TH1F* sig_sumJetMass_fattenedJetsPt10 = (TH1F*) gDirectory->Get("sumJetMass_fattenedJetsPt10_signal");
TH1F* sig_sumJetMass_fattenedJetsPt20 = (TH1F*) gDirectory->Get("sumJetMass_fattenedJetsPt20_signal");
TH1F* sig_sumJetMass_fattenedJetsPt30 = (TH1F*) gDirectory->Get("sumJetMass_fattenedJetsPt30_signal");
TH1F* sig_sumJetMass_fattenedJetsPt50 = (TH1F*) gDirectory->Get("sumJetMass_fattenedJetsPt50_signal");



TH1F* ttbar_HT_HTJets = (TH1F*) gDirectory->Get("HT_HTJets_ttbar");

TH1F* ttbar_MHT_MHTJets = (TH1F*) gDirectory->Get("MHT_MHTJets_ttbar");

TH1F* ttbar_sumJetMass_ak1p2Jets  = (TH1F*) gDirectory->Get("sumJetMass_ak1p2Jets_ttbar");

TH1F* ttbar_sumJetMass_fattenedJetsPt10 = (TH1F*) gDirectory->Get("sumJetMass_fattenedJetsPt10_ttbar");
TH1F* ttbar_sumJetMass_fattenedJetsPt20 = (TH1F*) gDirectory->Get("sumJetMass_fattenedJetsPt20_ttbar");
TH1F* ttbar_sumJetMass_fattenedJetsPt30 = (TH1F*) gDirectory->Get("sumJetMass_fattenedJetsPt30_ttbar");
TH1F* ttbar_sumJetMass_fattenedJetsPt50 = (TH1F*) gDirectory->Get("sumJetMass_fattenedJetsPt50_ttbar");


sig_HT_HTJets->Scale(1/sig_HT_HTJets->Integral());
sig_MHT_MHTJets->Scale(1/sig_MHT_MHTJets->Integral());
sig_sumJetMass_ak1p2Jets->Scale(1/sig_sumJetMass_ak1p2Jets->Integral());
sig_sumJetMass_fattenedJetsPt10->Scale(1/sig_sumJetMass_fattenedJetsPt10->Integral());
sig_sumJetMass_fattenedJetsPt20->Scale(1/sig_sumJetMass_fattenedJetsPt20->Integral());
sig_sumJetMass_fattenedJetsPt30->Scale(1/sig_sumJetMass_fattenedJetsPt30->Integral());
sig_sumJetMass_fattenedJetsPt50->Scale(1/sig_sumJetMass_fattenedJetsPt50->Integral());


ttbar_HT_HTJets->Scale(1/ttbar_HT_HTJets->Integral());
ttbar_MHT_MHTJets->Scale(1/ttbar_MHT_MHTJets->Integral());
ttbar_sumJetMass_ak1p2Jets->Scale(1/ttbar_sumJetMass_ak1p2Jets->Integral());
ttbar_sumJetMass_fattenedJetsPt10->Scale(1/ttbar_sumJetMass_fattenedJetsPt10->Integral());
ttbar_sumJetMass_fattenedJetsPt20->Scale(1/ttbar_sumJetMass_fattenedJetsPt20->Integral());
ttbar_sumJetMass_fattenedJetsPt30->Scale(1/ttbar_sumJetMass_fattenedJetsPt30->Integral());
ttbar_sumJetMass_fattenedJetsPt50->Scale(1/ttbar_sumJetMass_fattenedJetsPt50->Integral());


double Ar_sig_HT_HTJets[500];
double Ar_sig_MHT_MHTJets[500];
double Ar_sig_sumJetMass_ak1p2Jets[500];
double Ar_sig_sumJetMass_fattenedJetsPt10[500];
double Ar_sig_sumJetMass_fattenedJetsPt20[500];
double Ar_sig_sumJetMass_fattenedJetsPt30[500];
double Ar_sig_sumJetMass_fattenedJetsPt50[500];

double Ar_ttbar_HT_HTJets[500];
double Ar_ttbar_MHT_MHTJets[500];
double Ar_ttbar_sumJetMass_ak1p2Jets[500];
double Ar_ttbar_sumJetMass_fattenedJetsPt10[500];
double Ar_ttbar_sumJetMass_fattenedJetsPt20[500];
double Ar_ttbar_sumJetMass_fattenedJetsPt30[500];
double Ar_ttbar_sumJetMass_fattenedJetsPt50[500];



for(int i=0; i<500; i++){
Ar_sig_HT_HTJets[i] =sig_HT_HTJets->Integral(i, 501);

Ar_sig_MHT_MHTJets[i]=sig_MHT_MHTJets->Integral(i, 501);
Ar_sig_sumJetMass_ak1p2Jets[i]=sig_sumJetMass_ak1p2Jets->Integral(i, 501);

Ar_sig_sumJetMass_fattenedJetsPt10[i]=sig_sumJetMass_fattenedJetsPt10->Integral(i, 501);
Ar_sig_sumJetMass_fattenedJetsPt20[i]=sig_sumJetMass_fattenedJetsPt20->Integral(i, 501);
Ar_sig_sumJetMass_fattenedJetsPt30[i]=sig_sumJetMass_fattenedJetsPt30->Integral(i, 501);
Ar_sig_sumJetMass_fattenedJetsPt50[i]=sig_sumJetMass_fattenedJetsPt50->Integral(i, 501);

Ar_ttbar_HT_HTJets[i] =ttbar_HT_HTJets->Integral(i, 501);

Ar_ttbar_MHT_MHTJets[i]=ttbar_MHT_MHTJets->Integral(i, 501);
Ar_ttbar_sumJetMass_ak1p2Jets[i]=ttbar_sumJetMass_ak1p2Jets->Integral(i, 501);

Ar_ttbar_sumJetMass_fattenedJetsPt10[i]=ttbar_sumJetMass_fattenedJetsPt10->Integral(i, 501);
Ar_ttbar_sumJetMass_fattenedJetsPt20[i]=ttbar_sumJetMass_fattenedJetsPt20->Integral(i, 501);
Ar_ttbar_sumJetMass_fattenedJetsPt30[i]=ttbar_sumJetMass_fattenedJetsPt30->Integral(i, 501);
Ar_ttbar_sumJetMass_fattenedJetsPt50[i]=ttbar_sumJetMass_fattenedJetsPt50->Integral(i, 501);




}



TGraph* HT= new TGraph(500,Ar_sig_HT_HTJets,Ar_ttbar_HT_HTJets);
HT->SetLineColor(1);
HT->SetLineWidth(2);


TGraph* MHT= new TGraph(500,Ar_sig_MHT_MHTJets,Ar_ttbar_MHT_MHTJets);
MHT->SetLineColor(2);
MHT->SetLineWidth(2);


TGraph* SJM_1p2= new TGraph(500,Ar_sig_sumJetMass_ak1p2Jets,Ar_ttbar_sumJetMass_ak1p2Jets);
SJM_1p2->SetLineColor(3);
SJM_1p2->SetLineWidth(2);

TGraph* SJM_Pt10= new TGraph(500,Ar_sig_sumJetMass_fattenedJetsPt10,Ar_ttbar_sumJetMass_fattenedJetsPt10);
SJM_Pt10->SetLineColor(4);
SJM_Pt10->SetLineWidth(2);

TGraph* SJM_Pt20= new TGraph(500,Ar_sig_sumJetMass_fattenedJetsPt20,Ar_ttbar_sumJetMass_fattenedJetsPt20);
SJM_Pt20->SetLineColor(5);
SJM_Pt20->SetLineWidth(2);

TGraph* SJM_Pt30= new TGraph(500,Ar_sig_sumJetMass_fattenedJetsPt30,Ar_ttbar_sumJetMass_fattenedJetsPt30);
SJM_Pt30->SetLineColor(6);
SJM_Pt30->SetLineWidth(2);

TGraph* SJM_Pt50= new TGraph(500,Ar_sig_sumJetMass_fattenedJetsPt50,Ar_ttbar_sumJetMass_fattenedJetsPt50);
SJM_Pt50->SetLineColor(7);
SJM_Pt50->SetLineWidth(2);

TMultiGraph *mg_ttbar = new TMultiGraph();
mg_ttbar->SetTitle(" ROC curve ; #epsilon_{T1tttt} ; #epsilon_{t#bar{t}}");


mg_ttbar->Add(HT,"l");
mg_ttbar->Add(MHT,"l");
mg_ttbar->Add(SJM_1p2,"l");
mg_ttbar->Add(SJM_Pt10,"l");
mg_ttbar->Add(SJM_Pt20,"l");
mg_ttbar->Add(SJM_Pt30,"l");
mg_ttbar->Add(SJM_Pt50,"l");

leg_1D[0]->AddEntry(HT,"HT_HTJets","l");
leg_1D[0]->AddEntry(MHT,"HT_MHTJets","l");

leg_1D[0]->AddEntry(SJM_1p2,"SJM_ak1p2","l");
leg_1D[0]->AddEntry(SJM_Pt10,"SJM_fattenedJet_Pt10","l");
leg_1D[0]->AddEntry(SJM_Pt20,"SJM_fattenedJets_Pt20","l");
leg_1D[0]->AddEntry(SJM_Pt30,"SJM_fattenedJets_Pt30","l");
leg_1D[0]->AddEntry(SJM_Pt50,"SJM_fattenedJets_Pt50","l");


TCanvas *ROC=new TCanvas("My Canvas","Canvas");

ROC->cd();
mg_ttbar->Draw("AP");
leg_1D[0]->Draw();
tex1->Draw();
ROC->SaveAs("ROCT1ttttVsttbar.png");

}
