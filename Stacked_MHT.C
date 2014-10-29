#include<iostream>
using namespace std;


void stacked(){

TChain* SIGtree_T1tttt= new TChain("RA2TreeMaker2/RA2PreSelection");
SIGtree_T1tttt->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola.root");

TChain* BKGtree_QCD_Pt_30to50= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_30to50->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-30to50_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_50to80= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_50to80->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-50to80_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_80to120= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_80to120->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-80to120_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_120to170= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_120to170->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-120to170_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_170to300= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_170to300->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-170to300_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_300to470= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_300to470->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-300to470_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_470to600= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_470to600->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-470to600_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_600to800= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_600to800->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-600to800_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_800to1000= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_800to1000->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-800to1000_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_1000to1400= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_1000to1400->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-1000to1400_Tune4C_13TeV_pythia8.root");

TChain* BKGtree_QCD_Pt_1400to1800= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_1400to1800->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-1400to1800_Tune4C_13TeV_pythia8.root");


TChain* BKGtree_QCD_Pt_1800to2400= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_1800to2400->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-1800to2400_Tune4C_13TeV_pythia8.root");


TChain* BKGtree_QCD_Pt_3200toinf= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_QCD_Pt_3200toinf->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.QCD_Pt-3200_Tune4C_13TeV_pythia8.root");


TChain* BKGtree_WJetsToLNu_HT_400to600= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_WJetsToLNu_HT_400to600->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.WJetsToLNu_HT-400to600_Tune4C_13TeV-madgraph-tauola.root");


TChain* BKGtree_WJetsToLNu_HT_600toInf= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_WJetsToLNu_HT_600toInf->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.WJetsToLNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola.root");


TChain* BKGtree_ZJetsToNuNu_HT_400to600= new TChain("RA2TreeMaker2/RA2PreSelection");
BKGtree_ZJetsToNuNu_HT_400to600->Add("/eos/uscms/store/user/awhitbe1/RA2Tree_13TeV_25ns20PU_V1/25ns20PU.ZJetsToNuNu_HT-400to600_Tune4C_13TeV-madgraph-tauola.root");



char cuts[300];
sprintf(cuts,"");


 SIGtree_T1tttt->Draw("MHT>>MHT_T1tttt(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_30to50->Draw("MHT>>MHT_QCD_Pt_30to50(30,0.000000,1000.000)",cuts);

BKGtree_QCD_Pt_50to80->Draw("MHT>>MHT_QCD_Pt_50to80(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_80to120->Draw("MHT>>MHT_QCD_Pt_80to120(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_120to170->Draw("MHT>>MHT_QCD_Pt_120to170(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_170to300->Draw("MHT>>MHT_QCD_Pt_170to300(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_300to470->Draw("MHT>>MHT_QCD_Pt_300to470(30,0.000000,1000.000)",cuts);

BKGtree_QCD_Pt_470to600->Draw("MHT>>MHT_QCD_Pt_470to600(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_600to800->Draw("MHT>>MHT_QCD_Pt_600to800(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_800to1000->Draw("MHT>>MHT_QCD_Pt_800to1000(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_1000to1400->Draw("MHT>>MHT_QCD_Pt_1000to1400(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_1400to1800->Draw("MHT>>MHT_QCD_Pt_1400to1800(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_1800to2400->Draw("MHT>>MHT_QCD_Pt_1800to2400(30,0.000000,1000.000)",cuts);
BKGtree_QCD_Pt_3200toinf->Draw("MHT>>MHT_QCD_Pt_3200toinf(30,0.000000,1000.000)",cuts);



BKGtree_WJetsToLNu_HT_400to600->Draw("MHT>>MHT_WJetsToLNu_HT_400to600(30,0.000000,1000.000)",cuts);

BKGtree_WJetsToLNu_HT_600toInf->Draw("MHT>>MHT_WJetsToLNu_HT_600toInf(30,0.000000,1000.000)",cuts);

BKGtree_ZJetsToNuNu_HT_400to600->Draw("MHT>>MHT_ZJetsToNuNu_HT_400to600(30,0.000000,1000.000)",cuts);




TH1F* sig_MHT_T1tttt = (TH1F*) gDirectory->Get("MHT_T1tttt");
sig_MHT_T1tttt->SetLineColor(kRed-2);
sig_MHT_T1tttt->SetLineWidth(2);
TH1F* bkg_MHT_QCD_Pt_30to50 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_30to50");
TH1F* bkg_MHT_QCD_Pt_50to80 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_50to80");
TH1F* bkg_MHT_QCD_Pt_80to120 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_80to120");
TH1F* bkg_MHT_QCD_Pt_120to170 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_120to170");
TH1F* bkg_MHT_QCD_Pt_170to300 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_170to300");
TH1F* bkg_MHT_QCD_Pt_300to470 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_300to470");
TH1F* bkg_MHT_QCD_Pt_470to600 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_470to600");
TH1F* bkg_MHT_QCD_Pt_600to800 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_600to800");
TH1F* bkg_MHT_QCD_Pt_800to1000 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_800to1000");
TH1F* bkg_MHT_QCD_Pt_1000to1400 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_1000to1400");
TH1F* bkg_MHT_QCD_Pt_1400to1800 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_1400to1800");
TH1F* bkg_MHT_QCD_Pt_1800to2400 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_1800to2400");
TH1F* bkg_MHT_QCD_Pt_3200toinf = (TH1F*) gDirectory->Get("MHT_QCD_Pt_3200toinf");






TH1F* bkg_MHT_WJetsToLNu_HT_400to600 = (TH1F*) gDirectory->Get("MHT_WJetsToLNu_HT_400to600");
TH1F* bkg_MHT_WJetsToLNu_HT_600toInf = (TH1F*) gDirectory->Get("MHT_WJetsToLNu_HT_600toInf");



TH1F* bkg_MHT_ZJetsToNuNu_HT_400to600 = (TH1F*) gDirectory->Get("MHT_ZJetsToNuNu_HT_400to600");
bkg_MHT_ZJetsToNuNu_HT_400to600->SetFillColor(kCyan+1);
bkg_MHT_ZJetsToNuNu_HT_400to600->SetLineWidth(2);
bkg_MHT_ZJetsToNuNu_HT_400to600->SetLineColor(kCyan+1);

sig_MHT_T1tttt->Scale(0.000675722135);

bkg_MHT_QCD_Pt_30to50->Scale(166666.36226694);
bkg_MHT_QCD_Pt_50to80->Scale(23396.820445117 );
bkg_MHT_QCD_Pt_80to120->Scale(3131.6423524 );
bkg_MHT_QCD_Pt_120to170->Scale(513.2152938);
bkg_MHT_QCD_Pt_170to300->Scale(215.59132057);
bkg_MHT_QCD_Pt_300to470->Scale(13.8425874 );
bkg_MHT_QCD_Pt_470to600->Scale(1.01049879);
bkg_MHT_QCD_Pt_600to800->Scale(0.29298235);
bkg_MHT_QCD_Pt_800to1000->Scale(0.049130417);
bkg_MHT_QCD_Pt_1000to1400->Scale(0.014227425);
bkg_MHT_QCD_Pt_1400to1800->Scale(0.0012535831);
bkg_MHT_QCD_Pt_1800to2400->Scale(0.00017288129);
bkg_MHT_QCD_Pt_3200toinf->Scale(0.0000002762710);
bkg_MHT_WJetsToLNu_HT_400to600->Scale(0.11732062560);
bkg_MHT_WJetsToLNu_HT_600toInf->Scale(0.05002656913);
bkg_MHT_ZJetsToNuNu_HT_400to600->Scale(0.01347190708);



TH1F* bkg_MHT_QCD=new TH1F(*bkg_MHT_QCD_Pt_30to50);

bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_50to80);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_80to120);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_120to170);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_170to300);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_300to470);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_470to600);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_600to800);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_800to1000);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_1000to1400);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_1400to1800);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_1800to2400);
bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_3200toinf);

bkg_MHT_QCD->SetFillColor(kGray+1);
bkg_MHT_QCD->SetLineWidth(2);
bkg_MHT_QCD->SetLineColor(kGray+1);



TH1F* bkg_MHT_WJet=new TH1F(*bkg_MHT_WJetsToLNu_HT_400to600);
bkg_MHT_WJet->Add(bkg_MHT_WJetsToLNu_HT_600toInf);

bkg_MHT_WJet->SetFillColor(kGreen-3);
bkg_MHT_WJet->SetLineWidth(2); 
bkg_MHT_WJet->SetLineColor(kGreen-3);



TH1F* bkg_MHT_ZJet=new TH1F(*bkg_MHT_ZJetsToNuNu_HT_400to600);

sig_MHT_T1tttt->Scale(1/sig_MHT_T1tttt->Integral());
bkg_MHT_QCD->Scale(1/bkg_MHT_QCD->Integral());
//bkg_MHT_QCD->Scale(1/bkg_MHT_QCD->Integral());
bkg_MHT_WJet->Scale(1/bkg_MHT_WJet->Integral());
bkg_MHT_ZJet->Scale(1/bkg_MHT_ZJet->Integral());


char Legname1[100];
TLegend *leg_1D[10];
for(int k0=0;k0<5;k0++){
sprintf(Legname1,"leg_1D%i",k0);
leg_1D[k0]=new TLegend(0.2248322,0.5052448,0.4244966,0.7062937);
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
////
//
//
//



leg_1D[0]->AddEntry(sig_MHT_T1tttt,"T1tttt","l");
leg_1D[0]->AddEntry(bkg_MHT_QCD,"QCD","l");
leg_1D[0]->AddEntry(bkg_MHT_WJet,"WJet","l");
leg_1D[0]->AddEntry(bkg_MHT_ZJet,"ZJet","l");


sig_MHT_T1tttt->GetYaxis()->SetTitle("Normalized to Unity");

THStack *hs = new THStack("hs","stacked MHT distribution ");
//hs->GetYaxis()->SetTitle("Normalized to Unity");
//hs->Add(sig_MHT_T1tttt);
hs->Add(bkg_MHT_QCD);
hs->Add(bkg_MHT_WJet);
hs->Add(bkg_MHT_ZJet);

TCanvas *hs_c=new TCanvas("Canvas","My canvas");

hs_c->cd();
hs->Draw();
sig_MHT_T1tttt->Draw("SAME");
hs_c->SaveAs("Stacked.png");
leg_1D[0]->Draw();



}

