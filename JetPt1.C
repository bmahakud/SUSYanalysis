#include<iostream>
using namespace std;


void stacked_QCDJetPt1(){

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


 SIGtree_T1tttt->Draw("Jet1Pt>>MHT_T1tttt(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_30to50->Draw("Jet1Pt>>MHT_QCD_Pt_30to50(160,0.000000,4000.000)",cuts);

BKGtree_QCD_Pt_50to80->Draw("Jet1Pt>>MHT_QCD_Pt_50to80(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_80to120->Draw("Jet1Pt>>MHT_QCD_Pt_80to120(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_120to170->Draw("Jet1Pt>>MHT_QCD_Pt_120to170(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_170to300->Draw("Jet1Pt>>MHT_QCD_Pt_170to300(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_300to470->Draw("Jet1Pt>>MHT_QCD_Pt_300to470(160,0.000000,4000.000)",cuts);

BKGtree_QCD_Pt_470to600->Draw("Jet1Pt>>MHT_QCD_Pt_470to600(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_600to800->Draw("Jet1Pt>>MHT_QCD_Pt_600to800(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_800to1000->Draw("Jet1Pt>>MHT_QCD_Pt_800to1000(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_1000to1400->Draw("Jet1Pt>>MHT_QCD_Pt_1000to1400(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_1400to1800->Draw("Jet1Pt>>MHT_QCD_Pt_1400to1800(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_1800to2400->Draw("Jet1Pt>>MHT_QCD_Pt_1800to2400(160,0.000000,4000.000)",cuts);
BKGtree_QCD_Pt_3200toinf->Draw("Jet1Pt>>MHT_QCD_Pt_3200toinf(160,0.000000,4000.000)",cuts);







TH1F* sig_MHT_T1tttt = (TH1F*) gDirectory->Get("MHT_T1tttt");
sig_MHT_T1tttt->SetLineColor(kRed-2);
sig_MHT_T1tttt->SetLineWidth(2);
TH1F* bkg_MHT_QCD_Pt_30to50 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_30to50");
bkg_MHT_QCD_Pt_30to50->SetLineColor(1);
bkg_MHT_QCD_Pt_30to50->SetFillColor(1);

TH1F* bkg_MHT_QCD_Pt_50to80 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_50to80");
bkg_MHT_QCD_Pt_50to80->SetLineColor(2);
bkg_MHT_QCD_Pt_50to80->SetFillColor(2);



TH1F* bkg_MHT_QCD_Pt_80to120 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_80to120");
bkg_MHT_QCD_Pt_80to120->SetLineColor(3);
bkg_MHT_QCD_Pt_80to120->SetFillColor(3);

TH1F* bkg_MHT_QCD_Pt_120to170 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_120to170");
bkg_MHT_QCD_Pt_120to170->SetLineColor(4);
bkg_MHT_QCD_Pt_120to170->SetFillColor(4);

TH1F* bkg_MHT_QCD_Pt_170to300 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_170to300");
bkg_MHT_QCD_Pt_170to300->SetLineColor(5);
bkg_MHT_QCD_Pt_170to300->SetFillColor(5);

TH1F* bkg_MHT_QCD_Pt_300to470 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_300to470");
bkg_MHT_QCD_Pt_300to470->SetLineColor(6);
bkg_MHT_QCD_Pt_300to470->SetFillColor(6);



TH1F* bkg_MHT_QCD_Pt_470to600 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_470to600");
bkg_MHT_QCD_Pt_470to600->SetLineColor(7);
bkg_MHT_QCD_Pt_470to600->SetFillColor(7);



TH1F* bkg_MHT_QCD_Pt_600to800 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_600to800");

bkg_MHT_QCD_Pt_600to800->SetLineColor(8);
bkg_MHT_QCD_Pt_600to800->SetFillColor(8);


TH1F* bkg_MHT_QCD_Pt_800to1000 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_800to1000");

bkg_MHT_QCD_Pt_800to1000->SetLineColor(9);
bkg_MHT_QCD_Pt_800to1000->SetFillColor(9);




TH1F* bkg_MHT_QCD_Pt_1000to1400 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_1000to1400");

bkg_MHT_QCD_Pt_1000to1400->SetLineColor(12);
bkg_MHT_QCD_Pt_1000to1400->SetFillColor(12);


TH1F* bkg_MHT_QCD_Pt_1400to1800 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_1400to1800");
bkg_MHT_QCD_Pt_1400to1800->SetLineColor(38);
bkg_MHT_QCD_Pt_1400to1800->SetFillColor(38);


TH1F* bkg_MHT_QCD_Pt_1800to2400 = (TH1F*) gDirectory->Get("MHT_QCD_Pt_1800to2400");

bkg_MHT_QCD_Pt_1800to2400->SetLineColor(46);
bkg_MHT_QCD_Pt_1800to2400->SetFillColor(46);


TH1F* bkg_MHT_QCD_Pt_3200toinf = (TH1F*) gDirectory->Get("MHT_QCD_Pt_3200toinf");

bkg_MHT_QCD_Pt_3200toinf->SetLineColor(41);
bkg_MHT_QCD_Pt_3200toinf->SetFillColor(41);




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




sig_MHT_T1tttt->Scale(1/sig_MHT_T1tttt->Integral());


/*
bkg_MHT_QCD_Pt_30to50->Scale(1/bkg_MHT_QCD_Pt_30to50->Integral());
bkg_MHT_QCD_Pt_50to80->Scale(1/bkg_MHT_QCD_Pt_50to80->Integral());
bkg_MHT_QCD_Pt_80to120->Scale(1/bkg_MHT_QCD_Pt_80to120->Integral());
bkg_MHT_QCD_Pt_120to170->Scale(1/bkg_MHT_QCD_Pt_120to170->Integral());
bkg_MHT_QCD_Pt_170to300->Scale(1/bkg_MHT_QCD_Pt_170to300->Integral());
bkg_MHT_QCD_Pt_300to470->Scale(1/bkg_MHT_QCD_Pt_300to470->Integral());
bkg_MHT_QCD_Pt_470to600->Scale(1/bkg_MHT_QCD_Pt_470to600->Integral());
bkg_MHT_QCD_Pt_600to800->Scale(1/bkg_MHT_QCD_Pt_600to800->Integral());
bkg_MHT_QCD_Pt_800to1000->Scale(1/bkg_MHT_QCD_Pt_800to1000->Integral());
bkg_MHT_QCD_Pt_1000to1400->Scale(1/bkg_MHT_QCD_Pt_1000to1400->Integral());
bkg_MHT_QCD_Pt_1400to1800->Scale(1/bkg_MHT_QCD_Pt_1400to1800->Integral());
bkg_MHT_QCD_Pt_1800to2400->Scale(1/bkg_MHT_QCD_Pt_1800to2400->Integral());
bkg_MHT_QCD_Pt_3200toinf->Scale(1/bkg_MHT_QCD_Pt_3200toinf->Integral());
*/








THStack *bkg_MHT_QCD = new THStack("hs","stacked QCD leading Jet pT distribution ");

bkg_MHT_QCD->Add(bkg_MHT_QCD_Pt_30to50);
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











char Legname1[100];
TLegend *leg_1D[10];
for(int k0=0;k0<5;k0++){
sprintf(Legname1,"leg_1D%i",k0);
leg_1D[k0]=new TLegend(0.22,0.3,0.82,0.9);
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




leg_1D[0]->AddEntry(sig_MHT_T1tttt,"T1tttt","l");

leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_30to50, "Pt_30to50" ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_50to80, "Pt_50to80" ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_80to120, "Pt_80to120" ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_120to170, "Pt_120to170" ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_170to300, "Pt_170to300" ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_300to470, "Pt_300to470" ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_470to600, "Pt_470to600" ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_600to800, "Pt_600to800" ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_800to1000,"Pt_800to1000"  ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_1000to1400,"Pt_1000to1400"  ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_1400to1800, "Pt_1400to1800" ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_1800to2400,"Pt_1800to2400"  ,"l");
leg_1D[0]->AddEntry(bkg_MHT_QCD_Pt_3200toinf, "Pt_3200toinf" ,"l");


















sig_MHT_T1tttt->GetYaxis()->SetTitle("Normalized to Unity");





TCanvas *hs_c=new TCanvas("Canvas","My canvas");

hs_c->cd();
bkg_MHT_QCD->Draw();
//sig_MHT_T1tttt->Draw("SAME");
hs_c->SaveAs("Stacked_QCDJet1Pt.png");
leg_1D[0]->Draw();



}
