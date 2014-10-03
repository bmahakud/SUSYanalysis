#include<iostream>
#include<vector>
#include "TH1.h"
#include "TGraph.h"
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
#include <fstream>
using namespace std;

double ErrorEff (int N_sig, int N_bkg, double E_sig, double E_bkg)
{
   double E_sig_err=sqrt((E_sig*(1-E_sig))/(N_sig));

   double E_bkg_err=sqrt((E_bkg*(1-E_bkg))/(N_bkg));


   double Ereff=sqrt(((E_sig_err*E_sig_err)/E_bkg)+((E_sig*E_sig*E_bkg_err*E_bkg_err)/(4*E_bkg*E_bkg*E_bkg)));
   

   return Ereff;

}








void MyROCnew(std::string HTmin="500",std::string HTmax="1000",std::string NJetsmin="3",std::string NJetsmax="5",std::string nPVmin="1",std::string nPVmax="15"){



int NJetsMin = atoi(NJetsmin.c_str());
int NJetsMax = atoi(NJetsmax.c_str());

int NPVmin=atoi(nPVmin.c_str());//new
int NPVmax=atoi(nPVmax.c_str());//new





double HT_Min=atoi(HTmin.c_str());
double HT_Max=atoi(HTmax.c_str());




cout <<"HT MIn = "<<HT_Min<<endl;





gROOT->ProcessLine(".L tdrstyle.C");
 setTDRStyle();

char cuts[300];

char njets_pav[50];

char ht_pav[50];

char npv_pav[50];

char filenameQCD[50];
char filenamettbar[50];
char filenameZJetnunu[50];
char filenameWJetlnu[50];

char filenameQCDpng[50];
char filenamettbarpng[50];
char filenameZJetnunupng[50];
char filenameWJetlnupng[50];






char signal[100];
//////////////////////////User Entry box
double htMin=HT_Min;
double htMax=HT_Max;
int njetsMin=NJetsMin;
int njetsMax=NJetsMax;

char filenameOverlaid[50];


sprintf(signal,"T1tttt(mGo=1100,mLSP=25)");










////////////////////////////////User Entry box





sprintf(cuts,"NJets_patJetsAK5PFPt50Eta25>=%i&&NJets_patJetsAK5PFPt50Eta25<=%i&&HT_patJetsAK5PFPt50Eta25>=%i&&HT_patJetsAK5PFPt50Eta25<=%i&&nVrtx>=%i&&nVrtx<=%i",njetsMin,njetsMax,htMin,htMax,NPVmin,NPVmax);

sprintf(filenameQCD,"QCD_%iHT%i_%iNjets%i_%inPV%i.pdf",htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);
sprintf(filenamettbar,"TTbar_%iHT%i_%iNjets%i_%inPV%i.pdf",htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);
sprintf(filenameZJetnunu,"ZJetnunu_%iHT%i_%iNjets%i_%inPV%i.pdf",htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);
sprintf(filenameWJetlnu,"WJetlnu_%iHT%i_%iNjets%i_%inPV%i.pdf",htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);

sprintf(filenameQCDpng,"QCD_%iHT%i_%iNjets%i_%inPV%i.png",htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);
sprintf(filenamettbarpng,"TTbar_%iHT%i_%iNjets%i_%inPV%i.png",htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);
sprintf(filenameZJetnunupng,"ZJetnunu_%iHT%i_%iNjets%i_%inPV%i.png",htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);
sprintf(filenameWJetlnupng,"WJetlnu_%iHT%i_%iNjets%i_%inPV%i.png",htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);



char BinQCD[100];
char Binttbar[100];
char BinZtonunu[100];
char BinWjetlnu[100];

sprintf(BinQCD,"QCD_%iHT%i_%iNjets%i",htMin,htMax,njetsMin,njetsMax);
sprintf(Binttbar,"TTbar_%iHT%i_%iNjets%i",htMin,htMax,njetsMin,njetsMax);
sprintf(BinZtonunu,"ZJetnunu_%iHT%i_%iNjets%i",htMin,htMax,njetsMin,njetsMax);
sprintf(BinWjetlnu,"WJetlnu_%iHT%i_%iNjets%i",htMin,htMax,njetsMin,njetsMax);


cout<<"Running on = "<<BinQCD<<endl;





sprintf(njets_pav,"%i#leqHT#leq%i",htMin,htMax);
sprintf(ht_pav,"%i#leqJets#leq%i",njetsMin,njetsMax);
sprintf(npv_pav,"%i#leqnPV#leq%i",NPVmin,NPVmax);

TPaveText *tex1 = new TPaveText(0.204698,0.7377622,0.4043624,0.8863636,"brNDC");
   tex1->SetBorderSize(0);
   tex1->SetFillStyle(0);
   tex1->SetTextAlign(11);
   tex1->SetTextFont(42);
   tex1->SetTextSize(0.04);
   text = tex1->AddText(signal);
   text = tex1->AddText(ht_pav);
   text = tex1->AddText(njets_pav);
   text = tex1->AddText(npv_pav);




//////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////



for(int k0=5;k0<10;k0++){
sprintf(Legname1,"leg_1D%i",k0);

leg_1D[k0]=new TLegend(0.4528112,0.4987047,0.6526104,0.6994819,NULL,"brNDC");
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











              TCanvas *ca = new TCanvas("ca","ca");
              TCanvas *cb = new TCanvas("cb","cb");
              //TCanvas *ccc = new TCanvas("ccc","ccc");
/*                          
              
              TFile* sigFile_T1tttt = new TFile("T1tttt.root");
              SIGtree_T1tttt = (TTree*) sigFile_T1tttt->Get("TreeFiller/AnalysisTree");
              
              TFile* bkgFile_QCD500 = new TFile("QCD500.root");
              BKGtree_QCD500 = (TTree*) bkgFile_QCD500->Get("TreeFiller/AnalysisTree");
              
              TFile* bkgFile_QCD1000 = new TFile("QCD1000.root");
              BKGtree_QCD1000 = (TTree*) bkgFile_QCD1000->Get("TreeFiller/AnalysisTree");

              TFile* bkgFile_ttbar = new TFile("TTbar.root");
              BKGtree_ttbar = (TTree*) bkgFile_ttbar->Get("TreeFiller/AnalysisTree");


              TFile* bkgFile4 = new TFile("Ztonunu.root");
              BKGtree_Ztonunu = (TTree*) bkgFile4->Get("TreeFiller/AnalysisTree");


              TFile* bkgFile5 = new TFile("WJetlnu.root");
              BKGtree_Wjetlnu = (TTree*) bkgFile5->Get("TreeFiller/AnalysisTree");


*/



TChain* SIGtree_T1tttt= new TChain("TreeFiller/AnalysisTree");
SIGtree_T1tttt->Add("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/SMS_T1tttt_mGo1100_mLSP25_*.root");


TChain* BKGtree_QCD500= new TChain("TreeFiller/AnalysisTree");
BKGtree_QCD500->Add("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/QCD_500HT1000_LPCSUSYPAT_SLIM*.root");


TChain* BKGtree_QCD1000= new TChain("TreeFiller/AnalysisTree");
BKGtree_QCD1000->Add("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/QCD_1000HTinf_LPCSUSYPAT_SLIM*.root");



TChain* BKGtree_ttbar= new TChain("TreeFiller/AnalysisTree");
BKGtree_ttbar->Add("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/TTJets_SemiLeptMGDecays_LPCSUSYPAT_SLIM*.root");




TChain* BKGtree_Ztonunu= new TChain("TreeFiller/AnalysisTree");
BKGtree_Ztonunu->Add("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/ZJetsToNuNu_400HTinf_LPCSUSYPAT_SLIM*.root");


TChain* BKGtree_Wjetlnu= new TChain("TreeFiller/AnalysisTree");
BKGtree_Wjetlnu->Add("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/WJetsToLNu_400HTInf_v2_LPCSUSYPAT_SLIM*.root");




int nVrtx;

BKGtree_ttbar->SetBranchAddress("nVrtx", &nVrtx);



             SIGtree_T1tttt->Draw("MET>>MET_T1tttt(30,0.000000,1000.000)",cuts);
             BKGtree_QCD500->Draw("MET>>MET_QCD500(30,0.000000,1000.000)",cuts);
             BKGtree_QCD1000->Draw("MET>>MET_QCD1000(30,0.000000,1000.000)",cuts);
             BKGtree_ttbar->Draw("MET>>MET_ttbar(30,0.000000,1000.000)",cuts);
             BKGtree_Ztonunu->Draw("MET>>MET_Ztonunu(30,0.000000,1000.000)",cuts);
             BKGtree_Wjetlnu->Draw("MET>>MET_Wjetlnu(30,0.000000,1000.000)",cuts);


             SIGtree_T1tttt->Draw("(MET/sqrt(HT_patJetsAK5PFPt50Eta25))>>METsig_T1tttt(50,0.000000,50.000)",cuts);
             BKGtree_QCD500->Draw("(MET/sqrt(HT_patJetsAK5PFPt50Eta25))>>METsig_QCD500(50,0.000000,50.000)",cuts);
             BKGtree_QCD1000->Draw("(MET/sqrt(HT_patJetsAK5PFPt50Eta25))>>METsig_QCD1000(50,0.000000,50.000)",cuts);
             BKGtree_ttbar->Draw("(MET/sqrt(HT_patJetsAK5PFPt50Eta25))>>METsig_ttbar(50,0.000000,50.000)",cuts);
             BKGtree_Ztonunu->Draw("(MET/sqrt(HT_patJetsAK5PFPt50Eta25))>>METsig_Ztonunu(50,0.000000,50.000)",cuts);
             BKGtree_Wjetlnu->Draw("(MET/sqrt(HT_patJetsAK5PFPt50Eta25))>>METsig_Wjetlnu(50,0.000000,50.000)",cuts);
            


             SIGtree_T1tttt->Draw("MHT_patJetsAK5PFPt30>>MHT_T1tttt(30,0.000000,1000.000)",cuts);
             BKGtree_QCD500->Draw("MHT_patJetsAK5PFPt30>>MHT_QCD500(30,0.000000,1000.000)",cuts);
             BKGtree_QCD1000->Draw("MHT_patJetsAK5PFPt30>>MHT_QCD1000(30,0.000000,1000.000)",cuts);
             BKGtree_ttbar->Draw("MHT_patJetsAK5PFPt30>>MHT_ttbar(30,0.000000,1000.000)",cuts);
             BKGtree_Ztonunu->Draw("MHT_patJetsAK5PFPt30>>MHT_Ztonunu(30,0.000000,1000.000)",cuts);
             BKGtree_Wjetlnu->Draw("MHT_patJetsAK5PFPt30>>MHT_Wjetlnu(30,0.000000,1000.000)",cuts);


///////////////////////////////////////////////////MET

            TH1F* sig_MET_T1tttt = (TH1F*) gDirectory->Get("MET_T1tttt");
            sig_MET_T1tttt->SetLineColor(kRed-2);
            sig_MET_T1tttt->SetLineWidth(2);

            TH1F* bkg_MET_QCD500 = (TH1F*) gDirectory->Get("MET_QCD500");
           


           TH1F* bkg_MET_QCD1000 = (TH1F*) gDirectory->Get("MET_QCD1000");
            


            TH1F* bkg_MET_ttbar = (TH1F*) gDirectory->Get("MET_ttbar");
            bkg_MET_ttbar->SetLineColor(kBlue-7);
            bkg_MET_ttbar->SetLineWidth(2);

            TH1F* bkg_MET_Ztonunu = (TH1F*) gDirectory->Get("MET_Ztonunu");
            bkg_MET_Ztonunu->SetLineColor(kCyan+1);
            bkg_MET_Ztonunu->SetLineWidth(2);


            TH1F* bkg_MET_Wjetlnu = (TH1F*) gDirectory->Get("MET_Wjetlnu");
            bkg_MET_Wjetlnu->SetLineColor(kGreen-3);
            bkg_MET_Wjetlnu->SetLineWidth(2);


int N_sig_MET=(int) sig_MET_T1tttt->GetEntries();

int N_QCD500_MET=(int) bkg_MET_QCD500->GetEntries();
int N_QCD1000_MET=(int) bkg_MET_QCD1000->GetEntries();

int N_QCD_MET=N_QCD500_MET+N_QCD1000_MET;

int N_ttbar_MET=(int) bkg_MET_ttbar->GetEntries();
 
int N_Ztonunu_MET=(int) bkg_MET_Ztonunu->GetEntries();

int N_Wjetlnu_MET= (int) bkg_MET_Wjetlnu->GetEntries(); 







/////////////////////////////////METsig

             TH1F* sig_METsig_T1tttt = (TH1F*) gDirectory->Get("METsig_T1tttt");
             sig_METsig_T1tttt->SetLineColor(kRed-2);
             sig_METsig_T1tttt->SetLineWidth(2);

            TH1F* bkg_METsig_QCD500 = (TH1F*) gDirectory->Get("METsig_QCD500");
           


            TH1F* bkg_METsig_QCD1000 = (TH1F*) gDirectory->Get("METsig_QCD1000");
           


            TH1F* bkg_METsig_ttbar = (TH1F*) gDirectory->Get("METsig_ttbar");
           bkg_METsig_ttbar->SetLineColor(kBlue-7);
           bkg_METsig_ttbar->SetLineWidth(2);

            TH1F* bkg_METsig_Ztonunu = (TH1F*) gDirectory->Get("METsig_Ztonunu");
            bkg_METsig_Ztonunu->SetLineColor(kCyan+1);
            bkg_METsig_Ztonunu->SetLineWidth(2);

            TH1F* bkg_METsig_Wjetlnu = (TH1F*) gDirectory->Get("METsig_Wjetlnu");
           bkg_METsig_Wjetlnu->SetLineColor(kGreen-3);
           bkg_METsig_Wjetlnu->SetLineWidth(2);


int N_sig_METsig=(int) sig_METsig_T1tttt->GetEntries();

int N_QCD500_METsig=(int) bkg_METsig_QCD500->GetEntries();
int N_QCD1000_METsig=(int) bkg_METsig_QCD1000->GetEntries();

int N_QCD_METsig=N_QCD500_METsig+N_QCD1000_METsig;

int N_ttbar_METsig=(int) bkg_METsig_ttbar->GetEntries();

int N_Ztonunu_METsig=(int) bkg_METsig_Ztonunu->GetEntries();

int N_Wjetlnu_METsig= (int) bkg_METsig_Wjetlnu->GetEntries();









   /////////////////////////////////////////MHT         
            TH1F* sig_MHT_T1tttt = (TH1F*) gDirectory->Get("MHT_T1tttt");
            sig_MHT_T1tttt->SetLineColor(kRed-2);
            sig_MHT_T1tttt->SetLineWidth(2);

            TH1F* bkg_MHT_QCD500 = (TH1F*) gDirectory->Get("MHT_QCD500");
           


           TH1F* bkg_MHT_QCD1000 = (TH1F*) gDirectory->Get("MHT_QCD1000");
         


           TH1F* bkg_MHT_ttbar = (TH1F*) gDirectory->Get("MHT_ttbar");
           bkg_MHT_ttbar->SetLineColor(kBlue-7);
           bkg_MHT_ttbar->SetLineWidth(2);

            TH1F* bkg_MHT_Ztonunu = (TH1F*) gDirectory->Get("MHT_Ztonunu");
            bkg_MHT_Ztonunu->SetLineColor(kCyan+1);
            bkg_MHT_Ztonunu->SetLineWidth(2);

            TH1F* bkg_MHT_Wjetlnu = (TH1F*) gDirectory->Get("MHT_Wjetlnu");
            bkg_MHT_Wjetlnu->SetLineColor(kGreen-3);
            bkg_MHT_Wjetlnu->SetLineWidth(2);     


int N_sig_MHT=(int) sig_MHT_T1tttt->GetEntries();

int N_QCD500_MHT=(int) bkg_MHT_QCD500->GetEntries();

int N_QCD1000_MHT=(int) bkg_MHT_QCD1000->GetEntries();

int N_QCD_MHT=N_QCD500_MHT+N_QCD1000_MHT;

int N_ttbar_MHT=(int) bkg_MHT_ttbar->GetEntries();

int N_Ztonunu_MHT=(int) bkg_MHT_Ztonunu->GetEntries();

int N_Wjetlnu_MHT= (int) bkg_MHT_Wjetlnu->GetEntries();



            sig_MET_T1tttt->Scale(0.0017139);
            bkg_MET_QCD500->Scale(7.186921);
            bkg_MET_QCD1000->Scale(0.3965216);
            bkg_MET_ttbar->Scale(0.08163392);
            bkg_MET_Ztonunu->Scale(0.1236920);
            bkg_MET_Wjetlnu->Scale(0.10425249);


            sig_METsig_T1tttt->Scale(0.0017139);
            bkg_METsig_QCD500->Scale(7.186921);
            bkg_METsig_QCD1000->Scale(0.3965216);
            bkg_METsig_ttbar->Scale(0.08163392);
            bkg_METsig_Ztonunu->Scale(0.1236920);
            bkg_METsig_Wjetlnu->Scale(0.10425249);


            sig_MHT_T1tttt->Scale(0.0017139);
            bkg_MHT_QCD500->Scale(7.186921);
            bkg_MHT_QCD1000->Scale(0.3965216);
            bkg_MHT_ttbar->Scale(0.08163392);
            bkg_MHT_Ztonunu->Scale(0.1236920);
            bkg_MHT_Wjetlnu->Scale(0.10425249);



//double Error_eff()


///////////////////////////adding QCD histos




           TH1F* bkg_MET_QCD=new TH1F(*bkg_MET_QCD500);
            bkg_MET_QCD->SetLineColor(kGray+1);
            bkg_MET_QCD->SetLineWidth(2);
            bkg_MET_QCD->Add(bkg_MET_QCD1000);
            


            
            TH1F* bkg_METsig_QCD=new TH1F(*bkg_METsig_QCD500);
            bkg_METsig_QCD->SetLineColor(kGray+1);
            bkg_METsig_QCD->SetLineWidth(2);
            bkg_METsig_QCD->Add(bkg_METsig_QCD1000);
            

            TH1F* bkg_MHT_QCD=new TH1F(*bkg_MHT_QCD500);
            bkg_MHT_QCD->SetLineColor(kGray+1);
            bkg_MHT_QCD->SetLineWidth(2);
            bkg_MHT_QCD->Add(bkg_MHT_QCD1000);
            


/*


sig_METsig_T1tttt->GetYaxis()->SetRange(0,0.5);
sig_MHT_T1tttt->GetYaxis()->SetRange(0,0.5);

bkg_METsig_QCD->GetYaxis()->SetRangeUser(0,0.5);
bkg_MHT_QCD->GetYaxis()->SetRangeUser(0,0.5);

*/
            








sig_MET_T1tttt->Scale(1/sig_MET_T1tttt->Integral(0,sig_MET_T1tttt->GetNbinsX()+1));
bkg_MET_QCD->Scale(1/bkg_MET_QCD->Integral(0,bkg_MET_QCD->GetNbinsX()+1));
bkg_MET_ttbar->Scale(1/bkg_MET_ttbar->Integral(0,bkg_MET_ttbar->GetNbinsX()+1));
bkg_MET_Ztonunu->Scale(1/bkg_MET_Ztonunu->Integral(0,bkg_MET_Ztonunu->GetNbinsX()+1));
bkg_MET_Wjetlnu->Scale(1/bkg_MET_Wjetlnu->Integral(0,bkg_MET_Wjetlnu->GetNbinsX()+1));


sig_METsig_T1tttt->Scale(1/sig_METsig_T1tttt->Integral(0,sig_METsig_T1tttt->GetNbinsX()+1));
bkg_METsig_QCD->Scale(1/bkg_METsig_QCD->Integral(0,bkg_METsig_QCD->GetNbinsX()+1));
bkg_METsig_ttbar->Scale(1/bkg_METsig_ttbar->Integral(0,bkg_METsig_ttbar->GetNbinsX()+1));
bkg_METsig_Ztonunu->Scale(1/bkg_METsig_Ztonunu->Integral(0,bkg_METsig_Ztonunu->GetNbinsX()+1));
bkg_METsig_Wjetlnu->Scale(1/bkg_METsig_Wjetlnu->Integral(0,bkg_METsig_Wjetlnu->GetNbinsX()+1));


sig_MHT_T1tttt->Scale(1/sig_MHT_T1tttt->Integral(0,sig_MHT_T1tttt->GetNbinsX()+1));
bkg_MHT_QCD->Scale(1/bkg_MHT_QCD->Integral(0,bkg_MHT_QCD->GetNbinsX()+1));
bkg_MHT_ttbar->Scale(1/bkg_MHT_ttbar->Integral(0,bkg_MHT_ttbar->GetNbinsX()+1));
bkg_MHT_Ztonunu->Scale(1/bkg_MHT_Ztonunu->Integral(0,bkg_MHT_Ztonunu->GetNbinsX()+1));
bkg_MHT_Wjetlnu->Scale(1/bkg_MHT_Wjetlnu->Integral(0,bkg_MHT_Wjetlnu->GetNbinsX()+1));




sig_MET_T1tttt->GetYaxis()->SetRangeUser(0,0.5);
bkg_MET_QCD->GetYaxis()->SetRangeUser(0,0.5);
bkg_MET_ttbar->GetYaxis()->SetRangeUser(0,0.5);
bkg_MET_Ztonunu->GetYaxis()->SetRangeUser(0,0.5);
bkg_MET_Wjetlnu->GetYaxis()->SetRangeUser(0,0.5);


sig_METsig_T1tttt->GetYaxis()->SetRangeUser(0,0.5);
bkg_METsig_QCD->GetYaxis()->SetRangeUser(0,0.5);
bkg_METsig_ttbar->GetYaxis()->SetRangeUser(0,0.5);
bkg_METsig_Ztonunu->GetYaxis()->SetRangeUser(0,0.5);
bkg_METsig_Wjetlnu->GetYaxis()->SetRangeUser(0,0.5);

sig_MHT_T1tttt->GetYaxis()->SetRangeUser(0,0.5);
bkg_MHT_QCD->GetYaxis()->SetRangeUser(0,0.5);
bkg_MHT_ttbar->GetYaxis()->SetRangeUser(0,0.5);
bkg_MHT_Ztonunu->GetYaxis()->SetRangeUser(0,0.5);
bkg_MHT_Wjetlnu->GetYaxis()->SetRangeUser(0,0.5);





//leg_1D[1]->AddEntry(ROC_MET_ttbar_T1tttt,"MET","l");


leg_1D[5]->AddEntry(sig_MET_T1tttt,"signal","l");
leg_1D[6]->AddEntry(sig_METsig_T1tttt,"signal","l");
leg_1D[7]->AddEntry(sig_MHT_T1tttt,"signal","l");

char Cname1[100];
 
TCanvas *c_1D[12]; 
for(int k0=0;k0<12;k0++){
sprintf(Cname1,"c_1D%i",k0);

c_1D[k0]=new TCanvas(Cname1,Cname1,1000,800);
c_1D[k0]->Range(-200,-0.07926829,1050,0.5304878);
}
///////////////MET
c_1D[0]->cd();
sig_MET_T1tttt->Draw();
bkg_MET_QCD->Draw("SAME");

leg_1D[5]->Draw();





c_1D[1]->cd();
sig_MET_T1tttt->Draw();
bkg_MET_ttbar->Draw("SAME");

leg_1D[5]->Draw();




c_1D[2]->cd();
sig_MET_T1tttt->Draw();
bkg_MET_Ztonunu->Draw("SAME");

leg_1D[5]->Draw();




c_1D[3]->cd();
sig_MET_T1tttt->Draw();
bkg_MET_Wjetlnu->Draw("SAME");

leg_1D[5]->Draw();
///////////////METsig




c_1D[4]->cd();
sig_METsig_T1tttt->Draw();
bkg_METsig_QCD->Draw("SAME");

leg_1D[6]->Draw();




c_1D[5]->cd();
sig_METsig_T1tttt->Draw();
bkg_METsig_ttbar->Draw("SAME");

leg_1D[6]->Draw();




c_1D[6]->cd();
sig_METsig_T1tttt->Draw();
bkg_METsig_Ztonunu->Draw("SAME");

leg_1D[6]->Draw();



c_1D[7]->cd();
sig_METsig_T1tttt->Draw();
bkg_METsig_Wjetlnu->Draw("SAME");

leg_1D[6]->Draw();

///////////////MHT




c_1D[8]->cd();
sig_MHT_T1tttt->Draw();
bkg_MHT_QCD->Draw("SAME");

leg_1D[7]->Draw();



c_1D[9]->cd();
sig_MHT_T1tttt->Draw();
bkg_MHT_ttbar->Draw("SAME");

leg_1D[7]->Draw();



c_1D[10]->cd();
sig_MHT_T1tttt->Draw();
bkg_MHT_Ztonunu->Draw("SAME");

leg_1D[7]->Draw();


c_1D[11]->cd();
sig_MHT_T1tttt->Draw();
bkg_MHT_Wjetlnu->Draw("SAME");

leg_1D[7]->Draw();

std::string start[12];


start[0]="MET,QCD";        
start[1]="MET,t#bar{t}";
start[2]="MET,Z(#rightarrow #nu #nu)+Jets";
start[3]="MET,W(#rightarrow l#nu)+Jets";
start[4]="METsig,QCD";
start[5]="METsig,t#bar{t}";
start[6]="METsig,Z(#rightarrow #nu #nu)+Jets";
start[7]="METsig,W(#rightarrow l#nu)+Jets";
start[8]="MHT,QCD";
start[9]="MHT,t#bar{t}";
start[10]="MHT,Z(#rightarrow #nu #nu)+Jets";
start[11]="MHT,W(#rightarrow l#nu)+Jets";


std::string ProcessVar[12];

ProcessVar[0]="MET_QCD";
ProcessVar[1]="MET_ttbar";
ProcessVar[2]="MET_Ztonunu";
ProcessVar[3]="MET_Wjetlnu";
ProcessVar[4]="METsig_QCD";
ProcessVar[5]="METsig_ttbar";
ProcessVar[6]="METsig_Ztonunu";
ProcessVar[7]="METsig_Wjetlnu";
ProcessVar[8]="MHT_QCD";
ProcessVar[9]="MHT_ttbar";
ProcessVar[10]="MHT_Ztonunu";
ProcessVar[11]="MHT_Wjetlnu";

















for(int i=0;i<12;i++){

        const char *startchar;
        const char *Process_var;

        Process_var =ProcessVar[i].c_str();   
        startchar = start[i].c_str();
        
         char processName[100];
         char processvar[100];

         sprintf(processName, "%s", startchar);


char filenameOverlap[100];
char filenameOverlappng[100];

sprintf(filenameOverlap,"File%s_%iHT%i_%iNjets%i_%inPV%i.pdf",Process_var,htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);
sprintf(filenameOverlappng,"File%s_%iHT%i_%iNjets%i_%inPV%i.png",Process_var,htMin,htMax,njetsMin,njetsMax,NPVmin,NPVmax);

cout<<"process = "<<processName<<endl;

TPaveText *tex2 = new TPaveText(0.4,0.65,0.7,0.9,"brNDC");
   tex2->SetBorderSize(0);
   tex2->SetFillStyle(0);
   tex2->SetTextAlign(11);
   tex2->SetTextFont(42);
   tex2->SetTextSize(0.04);
   texT = tex2->AddText(signal);
   texT = tex2->AddText(ht_pav);
   texT = tex2->AddText(njets_pav);
   texT = tex2->AddText(npv_pav);
   texT = tex2->AddText(processName);
   

  c_1D[i]->cd();
  tex2->Draw();
  
  c_1D[i]->SaveAs(filenameOverlap);
  c_1D[i]->SaveAs(filenameOverlappng);

}












double Ar_sig_MET_T1tttt[100],Ar_bkg_MET_QCD[100],Ar_bkg_MET_ttbar[100],Ar_bkg_MET_Ztonunu[100],Ar_bkg_MET_Wjetlnu[100];
double Ar_sig_METsig_T1tttt[100],Ar_bkg_METsig_QCD[100],Ar_bkg_METsig_ttbar[100],Ar_bkg_METsig_Ztonunu[100],Ar_bkg_METsig_Wjetlnu[100];
double Ar_sig_MHT_T1tttt[100],Ar_bkg_MHT_QCD[100],Ar_bkg_MHT_ttbar[100],Ar_bkg_MHT_Ztonunu[100],Ar_bkg_MHT_Wjetlnu[100];       


double Ar_bkg_MET_QCD_SbysqrtBKG[100],Ar_bkg_MET_ttbar_SbysqrtBKG[100],Ar_bkg_MET_Ztonunu_SbysqrtBKG[100],Ar_bkg_MET_Wjetlnu_SbysqrtBKG[100];

double Ar_bkg_MET_QCD_SbysqrtBKG_err[100],Ar_bkg_MET_ttbar_SbysqrtBKG_err[100],Ar_bkg_MET_Ztonunu_SbysqrtBKG_err[100],Ar_bkg_MET_Wjetlnu_SbysqrtBKG_err[100];




int bkg_MET_QCD_SbysqrtBKG_NUM=0;
int bkg_MET_ttbar_SbysqrtBKG_NUM=0;
int bkg_MET_Ztonunu_SbysqrtBKG_NUM=0;
int bkg_MET_Wjetlnu_SbysqrtBKG_NUM=0;


double Ar_bkg_METsig_QCD_SbysqrtBKG[100],Ar_bkg_METsig_ttbar_SbysqrtBKG[100],Ar_bkg_METsig_Ztonunu_SbysqrtBKG[100],Ar_bkg_METsig_Wjetlnu_SbysqrtBKG[100];

double Ar_bkg_METsig_QCD_SbysqrtBKG_err[100],Ar_bkg_METsig_ttbar_SbysqrtBKG_err[100],Ar_bkg_METsig_Ztonunu_SbysqrtBKG_err[100],Ar_bkg_METsig_Wjetlnu_SbysqrtBKG_err[100];








int bkg_METsig_QCD_SbysqrtBKG_NUM=0;
int bkg_METsig_ttbar_SbysqrtBKG_NUM=0;
int bkg_METsig_Ztonunu_SbysqrtBKG_NUM=0;
int bkg_METsig_Wjetlnu_SbysqrtBKG_NUM=0;




double Ar_bkg_MHT_QCD_SbysqrtBKG[100],Ar_bkg_MHT_ttbar_SbysqrtBKG[100],Ar_bkg_MHT_Ztonunu_SbysqrtBKG[100],Ar_bkg_MHT_Wjetlnu_SbysqrtBKG[100];


double Ar_bkg_MHT_QCD_SbysqrtBKG_err[100],Ar_bkg_MHT_ttbar_SbysqrtBKG_err[100],Ar_bkg_MHT_Ztonunu_SbysqrtBKG_err[100],Ar_bkg_MHT_Wjetlnu_SbysqrtBKG_err[100];






int bkg_MHT_QCD_SbysqrtBKG_NUM=0;
int bkg_MHT_ttbar_SbysqrtBKG_NUM=0;
int bkg_MHT_Ztonunu_SbysqrtBKG_NUM=0;
int bkg_MHT_Wjetlnu_SbysqrtBKG_NUM=0;

















     for(int i=0; i<100; i++){

      Ar_sig_MET_T1tttt[i] = sig_MET_T1tttt->Integral(i, 101);
      Ar_bkg_MET_QCD[i] = bkg_MET_QCD->Integral(i, 101);
      Ar_bkg_MET_ttbar[i] = bkg_MET_ttbar->Integral(i, 101); 
      Ar_bkg_MET_Ztonunu[i] = bkg_MET_Ztonunu->Integral(i, 101);
      Ar_bkg_MET_Wjetlnu[i] = bkg_MET_Wjetlnu->Integral(i, 101);

      Ar_sig_METsig_T1tttt[i] = sig_METsig_T1tttt->Integral(i, 101);
      Ar_bkg_METsig_QCD[i] = bkg_METsig_QCD->Integral(i, 101);
      Ar_bkg_METsig_ttbar[i] = bkg_METsig_ttbar->Integral(i, 101); 
      Ar_bkg_METsig_Ztonunu[i] = bkg_METsig_Ztonunu->Integral(i, 101);
      Ar_bkg_METsig_Wjetlnu[i] = bkg_METsig_Wjetlnu->Integral(i, 101);

      Ar_sig_MHT_T1tttt[i] = sig_MHT_T1tttt->Integral(i, 101);
      Ar_bkg_MHT_QCD[i] = bkg_MHT_QCD->Integral(i, 101);
      Ar_bkg_MHT_ttbar[i] = bkg_MHT_ttbar->Integral(i, 101); 
      Ar_bkg_MHT_Ztonunu[i] = bkg_MHT_Ztonunu->Integral(i, 101);
      Ar_bkg_MHT_Wjetlnu[i] = bkg_MHT_Wjetlnu->Integral(i, 101);



    cout<<"Bin number = "<<i<<endl;


double sbyb_MET_QCDminus=sig_MET_T1tttt->Integral(i-1, 101)/sqrt(bkg_MET_QCD->Integral(i-1, 101));
double sbyb_MET_ttbarminus=sig_MET_T1tttt->Integral(i-1, 101)/sqrt(bkg_MET_ttbar->Integral(i-1, 101));
double sbyb_MET_Ztonunuminus=sig_MET_T1tttt->Integral(i-1, 101)/sqrt(bkg_MET_Ztonunu->Integral(i-1, 101));   
double sbyb_MET_Wjetlnuminus=sig_MET_T1tttt->Integral(i-1, 101)/sqrt(bkg_MET_Wjetlnu->Integral(i-1, 101));



double sbyb_MET_QCD=sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_QCD->Integral(i, 101));

cout<<"S/sqrt(B) = "<<sbyb_MET_QCD<<endl;


double sbyb_MET_ttbar=sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_ttbar->Integral(i, 101));
double sbyb_MET_Ztonunu=sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_Ztonunu->Integral(i, 101));   
double sbyb_MET_Wjetlnu=sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_Wjetlnu->Integral(i, 101));

double sbyb_MET_QCDplus=sig_MET_T1tttt->Integral(i+1, 101)/sqrt(bkg_MET_QCD->Integral(i+1, 101));
double sbyb_MET_ttbarplus=sig_MET_T1tttt->Integral(i+1, 101)/sqrt(bkg_MET_ttbar->Integral(i+1, 101));
double sbyb_MET_Ztonunuplus=sig_MET_T1tttt->Integral(i+1, 101)/sqrt(bkg_MET_Ztonunu->Integral(i+1, 101));   
double sbyb_MET_Wjetlnuplus=sig_MET_T1tttt->Integral(i+1, 101)/sqrt(bkg_MET_Wjetlnu->Integral(i+1, 101));






//cout <<"MET-Esignal/sqrt(Ebkg_z) = "<<sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_Ztonunu->Integral(i, 101))<<endl;






if(sbyb_MET_QCD>sbyb_MET_QCDplus && sbyb_MET_QCD > sbyb_MET_QCDminus ){
//cout <<"MET-Esignal/sqrt(Ebkg_QCD) = "<<sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_QCD->Integral(i, 101))<<endl;

Ar_bkg_MET_QCD_SbysqrtBKG[bkg_MET_QCD_SbysqrtBKG_NUM]=sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_QCD->Integral(i, 101));

Ar_bkg_MET_QCD_SbysqrtBKG_err[bkg_MET_QCD_SbysqrtBKG_NUM]=ErrorEff(N_sig_MET,N_QCD_MET,sig_MET_T1tttt->Integral(i, 101),bkg_MET_QCD->Integral(i, 101));


//
bkg_MET_QCD_SbysqrtBKG_NUM=bkg_MET_QCD_SbysqrtBKG_NUM+1;

}



if(sbyb_MET_ttbar>sbyb_MET_ttbarplus && sbyb_MET_ttbar > sbyb_MET_ttbarminus){


Ar_bkg_MET_ttbar_SbysqrtBKG[bkg_MET_ttbar_SbysqrtBKG_NUM]=sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_ttbar->Integral(i, 101));

Ar_bkg_MET_ttbar_SbysqrtBKG_err[bkg_MET_ttbar_SbysqrtBKG_NUM]=ErrorEff(N_sig_MET,N_ttbar_MET,sig_MET_T1tttt->Integral(i, 101),bkg_MET_ttbar->Integral(i, 101));



//cout <<"MET-Esignal/sqrt(Ebkg_ttbar) = "<<sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_ttbar->Integral(i, 101))<<endl;

bkg_MET_ttbar_SbysqrtBKG_NUM=bkg_MET_ttbar_SbysqrtBKG_NUM+1;

}


if(sbyb_MET_Ztonunu>sbyb_MET_Ztonunuplus && sbyb_MET_Ztonunu > sbyb_MET_Ztonunuminus){

Ar_bkg_MET_Ztonunu_SbysqrtBKG[bkg_MET_Ztonunu_SbysqrtBKG_NUM]=sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_Ztonunu->Integral(i, 101));

Ar_bkg_MET_Ztonunu_SbysqrtBKG_err[bkg_MET_Ztonunu_SbysqrtBKG_NUM]=ErrorEff(N_sig_MET,N_Ztonunu_MET,sig_MET_T1tttt->Integral(i, 101),bkg_MET_Ztonunu->Integral(i, 101));



//cout <<"MET-Esignal/sqrt(Ebkg_Ztonunu) = "<<sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_Ztonunu->Integral(i, 101))<<endl;

bkg_MET_Ztonunu_SbysqrtBKG_NUM=bkg_MET_Ztonunu_SbysqrtBKG_NUM+1;


}


if(sbyb_MET_Wjetlnu>sbyb_MET_Wjetlnuplus && sbyb_MET_Wjetlnu > sbyb_MET_Wjetlnuminus){

Ar_bkg_MET_Wjetlnu_SbysqrtBKG[bkg_MET_Wjetlnu_SbysqrtBKG_NUM]=sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_Wjetlnu->Integral(i, 101));

Ar_bkg_MET_Wjetlnu_SbysqrtBKG_err[bkg_MET_Wjetlnu_SbysqrtBKG_NUM]=ErrorEff(N_sig_MET,N_Wjetlnu_MET,sig_MET_T1tttt->Integral(i, 101),bkg_MET_Wjetlnu->Integral(i, 101));



//cout <<"MET-Esignal/sqrt(Ebkg_Wjetlnu) = "<<sig_MET_T1tttt->Integral(i, 101)/sqrt(bkg_MET_Wjetlnu->Integral(i, 101))<<endl;

bkg_MET_Wjetlnu_SbysqrtBKG_NUM=bkg_MET_Wjetlnu_SbysqrtBKG_NUM+1;
}


   


double sbyb_METsig_QCDminus=sig_METsig_T1tttt->Integral(i-1, 101)/sqrt(bkg_METsig_QCD->Integral(i-1, 101));
double sbyb_METsig_ttbarminus=sig_METsig_T1tttt->Integral(i-1, 101)/sqrt(bkg_METsig_ttbar->Integral(i-1, 101));
double sbyb_METsig_Ztonunuminus=sig_METsig_T1tttt->Integral(i-1, 101)/sqrt(bkg_METsig_Ztonunu->Integral(i-1, 101));   
double sbyb_METsig_Wjetlnuminus=sig_METsig_T1tttt->Integral(i-1, 101)/sqrt(bkg_METsig_Wjetlnu->Integral(i-1, 101));



double sbyb_METsig_QCD=sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_QCD->Integral(i, 101));
double sbyb_METsig_ttbar=sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_ttbar->Integral(i, 101));
double sbyb_METsig_Ztonunu=sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_Ztonunu->Integral(i, 101));   
double sbyb_METsig_Wjetlnu=sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_Wjetlnu->Integral(i, 101));

double sbyb_METsig_QCDplus=sig_METsig_T1tttt->Integral(i+1, 101)/sqrt(bkg_METsig_QCD->Integral(i+1, 101));
double sbyb_METsig_ttbarplus=sig_METsig_T1tttt->Integral(i+1, 101)/sqrt(bkg_METsig_ttbar->Integral(i+1, 101));
double sbyb_METsig_Ztonunuplus=sig_METsig_T1tttt->Integral(i+1, 101)/sqrt(bkg_METsig_Ztonunu->Integral(i+1, 101));   
double sbyb_METsig_Wjetlnuplus=sig_METsig_T1tttt->Integral(i+1, 101)/sqrt(bkg_METsig_Wjetlnu->Integral(i+1, 101));

//cout <<"METsig-Esignal/sqrt(Ebkg_QCD) = "<<sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_QCD->Integral(i, 101))<<endl;

if(sbyb_METsig_QCD>sbyb_METsig_QCDplus && sbyb_METsig_QCD > sbyb_METsig_QCDminus ){


Ar_bkg_METsig_QCD_SbysqrtBKG[bkg_METsig_QCD_SbysqrtBKG_NUM]=sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_QCD->Integral(i, 101));

Ar_bkg_METsig_QCD_SbysqrtBKG_err[bkg_METsig_QCD_SbysqrtBKG_NUM]=ErrorEff(N_sig_METsig,N_QCD_METsig,sig_METsig_T1tttt->Integral(i, 101),bkg_METsig_QCD->Integral(i, 101));


bkg_METsig_QCD_SbysqrtBKG_NUM=bkg_METsig_QCD_SbysqrtBKG_NUM+1;

}



if(sbyb_METsig_ttbar>sbyb_METsig_ttbarplus && sbyb_METsig_ttbar > sbyb_METsig_ttbarminus){


Ar_bkg_METsig_ttbar_SbysqrtBKG[bkg_METsig_ttbar_SbysqrtBKG_NUM]=sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_ttbar->Integral(i, 101));

Ar_bkg_METsig_ttbar_SbysqrtBKG_err[bkg_METsig_ttbar_SbysqrtBKG_NUM]=ErrorEff(N_sig_METsig,N_ttbar_METsig,sig_METsig_T1tttt->Integral(i, 101),bkg_METsig_ttbar->Integral(i, 101));





//cout <<"METsig-Esignal/sqrt(Ebkg_ttbar) = "<<sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_ttbar->Integral(i, 101))<<endl;

bkg_METsig_ttbar_SbysqrtBKG_NUM=bkg_METsig_ttbar_SbysqrtBKG_NUM+1;

}


if(sbyb_METsig_Ztonunu>sbyb_METsig_Ztonunuplus && sbyb_METsig_Ztonunu > sbyb_METsig_Ztonunuminus){

Ar_bkg_METsig_Ztonunu_SbysqrtBKG[bkg_METsig_Ztonunu_SbysqrtBKG_NUM]=sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_Ztonunu->Integral(i, 101));

Ar_bkg_METsig_Ztonunu_SbysqrtBKG_err[bkg_METsig_Ztonunu_SbysqrtBKG_NUM]=ErrorEff(N_sig_METsig,N_Ztonunu_METsig,sig_METsig_T1tttt->Integral(i, 101),bkg_METsig_Ztonunu->Integral(i, 101));


//cout <<"METsig-Esignal/sqrt(Ebkg_Ztonunu) = "<<sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_Ztonunu->Integral(i, 101))<<endl;

bkg_METsig_Ztonunu_SbysqrtBKG_NUM=bkg_METsig_Ztonunu_SbysqrtBKG_NUM+1;

}


if(sbyb_METsig_Wjetlnu>sbyb_METsig_Wjetlnuplus && sbyb_METsig_Wjetlnu > sbyb_METsig_Wjetlnuminus){

Ar_bkg_METsig_Wjetlnu_SbysqrtBKG[bkg_METsig_Wjetlnu_SbysqrtBKG_NUM]=sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_Wjetlnu->Integral(i, 101));

Ar_bkg_METsig_Wjetlnu_SbysqrtBKG_err[bkg_METsig_Wjetlnu_SbysqrtBKG_NUM]=ErrorEff(N_sig_METsig,N_Wjetlnu_METsig,sig_METsig_T1tttt->Integral(i, 101),bkg_METsig_Wjetlnu->Integral(i, 101));



//cout <<"METsig-Esignal/sqrt(Ebkg_Wjetlnu) = "<<sig_METsig_T1tttt->Integral(i, 101)/sqrt(bkg_METsig_Wjetlnu->Integral(i, 101))<<endl;

bkg_METsig_Wjetlnu_SbysqrtBKG_NUM=bkg_METsig_Wjetlnu_SbysqrtBKG_NUM+1;

}










double sbyb_MHT_QCDminus=sig_MHT_T1tttt->Integral(i-1, 101)/sqrt(bkg_MHT_QCD->Integral(i-1, 101));
double sbyb_MHT_ttbarminus=sig_MHT_T1tttt->Integral(i-1, 101)/sqrt(bkg_MHT_ttbar->Integral(i-1, 101));
double sbyb_MHT_Ztonunuminus=sig_MHT_T1tttt->Integral(i-1, 101)/sqrt(bkg_MHT_Ztonunu->Integral(i-1, 101));   
double sbyb_MHT_Wjetlnuminus=sig_MHT_T1tttt->Integral(i-1, 101)/sqrt(bkg_MHT_Wjetlnu->Integral(i-1, 101));



double sbyb_MHT_QCD=sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_QCD->Integral(i, 101));
double sbyb_MHT_ttbar=sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_ttbar->Integral(i, 101));
double sbyb_MHT_Ztonunu=sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_Ztonunu->Integral(i, 101));   
double sbyb_MHT_Wjetlnu=sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_Wjetlnu->Integral(i, 101));

double sbyb_MHT_QCDplus=sig_MHT_T1tttt->Integral(i+1, 101)/sqrt(bkg_MHT_QCD->Integral(i+1, 101));
double sbyb_MHT_ttbarplus=sig_MHT_T1tttt->Integral(i+1, 101)/sqrt(bkg_MHT_ttbar->Integral(i+1, 101));
double sbyb_MHT_Ztonunuplus=sig_MHT_T1tttt->Integral(i+1, 101)/sqrt(bkg_MHT_Ztonunu->Integral(i+1, 101));   
double sbyb_MHT_Wjetlnuplus=sig_MHT_T1tttt->Integral(i+1, 101)/sqrt(bkg_MHT_Wjetlnu->Integral(i+1, 101));



if(sbyb_MHT_QCD>sbyb_MHT_QCDplus && sbyb_MHT_QCD > sbyb_MHT_QCDminus ){
Ar_bkg_MHT_QCD_SbysqrtBKG[bkg_MHT_QCD_SbysqrtBKG_NUM]=sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_QCD->Integral(i, 101));
//cout <<"MHT-Esignal/sqrt(Ebkg_QCD) = "<<sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_QCD->Integral(i, 101))<<endl;
Ar_bkg_MHT_QCD_SbysqrtBKG_err[bkg_MHT_QCD_SbysqrtBKG_NUM]=ErrorEff(N_sig_MHT,N_QCD_MHT,sig_MHT_T1tttt->Integral(i, 101),bkg_MHT_QCD->Integral(i, 101));




bkg_MHT_QCD_SbysqrtBKG_NUM=bkg_MHT_QCD_SbysqrtBKG_NUM+1;

}



if(sbyb_MHT_ttbar>sbyb_MHT_ttbarplus && sbyb_MHT_ttbar > sbyb_MHT_ttbarminus){
Ar_bkg_MHT_ttbar_SbysqrtBKG[bkg_MHT_ttbar_SbysqrtBKG_NUM]=sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_ttbar->Integral(i, 101));
Ar_bkg_MHT_ttbar_SbysqrtBKG_err[bkg_MHT_ttbar_SbysqrtBKG_NUM]=ErrorEff(N_sig_MHT,N_ttbar_MHT,sig_MHT_T1tttt->Integral(i, 101),bkg_MHT_ttbar->Integral(i, 101));


//cout <<"MHT-Esignal/sqrt(Ebkg_ttbar) = "<<sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_ttbar->Integral(i, 101))<<endl;

bkg_MHT_ttbar_SbysqrtBKG_NUM=bkg_MHT_ttbar_SbysqrtBKG_NUM+1;
}


if(sbyb_MHT_Ztonunu>sbyb_MHT_Ztonunuplus && sbyb_MHT_Ztonunu > sbyb_MHT_Ztonunuminus){
Ar_bkg_MHT_Ztonunu_SbysqrtBKG[bkg_MHT_Ztonunu_SbysqrtBKG_NUM]=sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_Ztonunu->Integral(i, 101));
Ar_bkg_MHT_Ztonunu_SbysqrtBKG_err[bkg_MHT_Ztonunu_SbysqrtBKG_NUM]=ErrorEff(N_sig_MHT,N_Ztonunu_MHT,sig_MHT_T1tttt->Integral(i, 101),bkg_MHT_Ztonunu->Integral(i, 101));

//cout <<"MHT-Esignal/sqrt(Ebkg_Ztonunu) = "<<sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_Ztonunu->Integral(i, 101))<<endl;

bkg_MHT_Ztonunu_SbysqrtBKG_NUM=bkg_MHT_Ztonunu_SbysqrtBKG_NUM+1;
}


if(sbyb_MHT_Wjetlnu>sbyb_MHT_Wjetlnuplus && sbyb_MHT_Wjetlnu > sbyb_MHT_Wjetlnuminus){
Ar_bkg_MHT_Wjetlnu_SbysqrtBKG[bkg_MHT_Wjetlnu_SbysqrtBKG_NUM]=sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_Wjetlnu->Integral(i, 101));

Ar_bkg_MHT_Wjetlnu_SbysqrtBKG_err[bkg_MHT_Wjetlnu_SbysqrtBKG_NUM]=ErrorEff(N_sig_MHT,N_Wjetlnu_MHT,sig_MHT_T1tttt->Integral(i, 101),bkg_MHT_Wjetlnu->Integral(i, 101));


//cout <<"MHT-Esignal/sqrt(Ebkg_Wjetlnu) = "<<sig_MHT_T1tttt->Integral(i, 101)/sqrt(bkg_MHT_Wjetlnu->Integral(i, 101))<<endl;

bkg_MHT_Wjetlnu_SbysqrtBKG_NUM=bkg_MHT_Wjetlnu_SbysqrtBKG_NUM+1;

}










      }



ofstream writeQCD_MET;
ofstream writeQCD_METsig;
ofstream writeQCD_MHT;


ofstream writettbar_MET;
ofstream writettbar_METsig;
ofstream writettbar_MHT;


ofstream writeZtonunu_MET;
ofstream writeZtonunu_METsig;
ofstream writeZtonunu_MHT;

ofstream writeWjetlnu_MET;
ofstream writeWjetlnu_METsig;
ofstream writeWjetlnu_MHT;



char QCD_METfileName[100];
char QCD_METsigfileName[100];
char QCD_MHTfileName[100];

char ttbar_METfileName[100];
char ttbar_METsigfileName[100];
char ttbar_MHTfileName[100];

char Ztonunu_METfileName[100];
char Ztonunu_METsigfileName[100];
char Ztonunu_MHTfileName[100];

char Wjetlnu_METfileName[100];
char Wjetlnu_METsigfileName[100];
char Wjetlnu_MHTfileName[100];




sprintf(QCD_METfileName,"QCD_MET.txt");
sprintf(QCD_METsigfileName,"QCD_METsig.txt");
sprintf(QCD_MHTfileName,"QCD_MHT.txt");

sprintf(ttbar_METfileName,"ttbar_MET.txt");
sprintf(ttbar_METsigfileName,"ttbar_METsig.txt");
sprintf(ttbar_MHTfileName,"ttbar_MHT.txt");


sprintf(Ztonunu_METfileName,"Ztonunu_MET.txt");
sprintf(Ztonunu_METsigfileName,"Ztonunu_METsig.txt");
sprintf(Ztonunu_MHTfileName,"Ztonunu_MHT.txt");

sprintf(Wjetlnu_METfileName,"Wjetlnu_MET.txt");
sprintf(Wjetlnu_METsigfileName,"Wjetlnu_METsig.txt");
sprintf(Wjetlnu_MHTfileName,"Wjetlnu_MHT.txt");



//, std::ofstream::out | std::ofstream::app

writeQCD_MET.open(QCD_METfileName,std::ofstream::out | std::ofstream::app);
writeQCD_METsig.open(QCD_METsigfileName,std::ofstream::out | std::ofstream::app);
writeQCD_MHT.open(QCD_MHTfileName,std::ofstream::out | std::ofstream::app);


writeQCD_MET<<Ar_bkg_MET_QCD_SbysqrtBKG[0]<<" "<<Ar_bkg_MET_QCD_SbysqrtBKG_err[0]<<endl;

writeQCD_METsig<<Ar_bkg_METsig_QCD_SbysqrtBKG[0]<<" "<<Ar_bkg_METsig_QCD_SbysqrtBKG_err[0]<<endl;

writeQCD_MHT<<Ar_bkg_MHT_QCD_SbysqrtBKG[0]<<" "<<Ar_bkg_MHT_QCD_SbysqrtBKG_err[0]<<endl;


writettbar_MET.open(ttbar_METfileName,std::ofstream::out | std::ofstream::app);
writettbar_METsig.open(ttbar_METsigfileName,std::ofstream::out | std::ofstream::app);
writettbar_MHT.open(ttbar_MHTfileName,std::ofstream::out | std::ofstream::app);


writettbar_MET<<Ar_bkg_MET_ttbar_SbysqrtBKG[0]<<" "<<Ar_bkg_MET_ttbar_SbysqrtBKG_err[0]<<endl;

writettbar_METsig<<Ar_bkg_METsig_ttbar_SbysqrtBKG[0]<<" "<<Ar_bkg_METsig_ttbar_SbysqrtBKG_err[0]<<endl;

writettbar_MHT<<Ar_bkg_MHT_ttbar_SbysqrtBKG[0]<<" "<<Ar_bkg_MHT_ttbar_SbysqrtBKG_err[0]<<endl;


writeZtonunu_MET.open(Ztonunu_METfileName,std::ofstream::out | std::ofstream::app);
writeZtonunu_METsig.open(Ztonunu_METsigfileName,std::ofstream::out | std::ofstream::app);
writeZtonunu_MHT.open(Ztonunu_MHTfileName,std::ofstream::out | std::ofstream::app);


writeZtonunu_MET<<Ar_bkg_MET_Ztonunu_SbysqrtBKG[0]<<" "<<Ar_bkg_MET_Ztonunu_SbysqrtBKG_err[0]<<endl;

writeZtonunu_METsig<<Ar_bkg_METsig_Ztonunu_SbysqrtBKG[0]<<" "<<Ar_bkg_METsig_Ztonunu_SbysqrtBKG_err[0]<<endl;

writeZtonunu_MHT<<Ar_bkg_MHT_Ztonunu_SbysqrtBKG[0]<<" "<<Ar_bkg_MHT_Ztonunu_SbysqrtBKG_err[0]<<endl;


writeWjetlnu_MET.open(Wjetlnu_METfileName,std::ofstream::out | std::ofstream::app);
writeWjetlnu_METsig.open(Wjetlnu_METsigfileName,std::ofstream::out | std::ofstream::app);
writeWjetlnu_MHT.open(Wjetlnu_MHTfileName,std::ofstream::out | std::ofstream::app);


writeWjetlnu_MET<<Ar_bkg_MET_Wjetlnu_SbysqrtBKG[0]<<" "<<Ar_bkg_MET_Wjetlnu_SbysqrtBKG_err[0]<<endl;

writeWjetlnu_METsig<<Ar_bkg_METsig_Wjetlnu_SbysqrtBKG[0]<<" "<<Ar_bkg_METsig_Wjetlnu_SbysqrtBKG_err[0]<<endl;

writeWjetlnu_MHT<<Ar_bkg_MHT_Wjetlnu_SbysqrtBKG[0]<<" "<<Ar_bkg_MHT_Wjetlnu_SbysqrtBKG_err[0]<<endl;














TGraph* ROC_MET_QCD_T1tttt= new TGraph(100,Ar_sig_MET_T1tttt,Ar_bkg_MET_QCD);
ROC_MET_QCD_T1tttt->SetLineColor(2);
ROC_MET_QCD_T1tttt->SetLineWidth(2);

TGraph* ROC_MET_ttbar_T1tttt= new TGraph(100,Ar_sig_MET_T1tttt,Ar_bkg_MET_ttbar);
ROC_MET_ttbar_T1tttt->SetLineColor(2);
ROC_MET_ttbar_T1tttt->SetLineWidth(2);

TGraph* ROC_MET_Ztonunu_T1tttt= new TGraph(100,Ar_sig_MET_T1tttt,Ar_bkg_MET_Ztonunu);
ROC_MET_Ztonunu_T1tttt->SetLineColor(2);
ROC_MET_Ztonunu_T1tttt->SetLineWidth(2);

TGraph* ROC_MET_Wjetlnu_T1tttt= new TGraph(100,Ar_sig_MET_T1tttt,Ar_bkg_MET_Wjetlnu);
ROC_MET_Wjetlnu_T1tttt->SetLineColor(2);
ROC_MET_Wjetlnu_T1tttt->SetLineWidth(2);

////////////////////////////////////////////////
TGraph* ROC_METsig_QCD_T1tttt= new TGraph(100,Ar_sig_METsig_T1tttt,Ar_bkg_METsig_QCD);
ROC_METsig_QCD_T1tttt->SetLineColor(3);
ROC_METsig_QCD_T1tttt->SetLineWidth(2);

TGraph* ROC_METsig_ttbar_T1tttt= new TGraph(100,Ar_sig_METsig_T1tttt,Ar_bkg_METsig_ttbar);
ROC_METsig_ttbar_T1tttt->SetLineColor(3);
ROC_METsig_ttbar_T1tttt->SetLineWidth(2);

TGraph* ROC_METsig_Ztonunu_T1tttt= new TGraph(100,Ar_sig_METsig_T1tttt,Ar_bkg_METsig_Ztonunu);
ROC_METsig_Ztonunu_T1tttt->SetLineColor(3);
ROC_METsig_Ztonunu_T1tttt->SetLineWidth(2);

TGraph* ROC_METsig_Wjetlnu_T1tttt= new TGraph(100,Ar_sig_METsig_T1tttt,Ar_bkg_METsig_Wjetlnu);
ROC_METsig_Wjetlnu_T1tttt->SetLineColor(3);
ROC_METsig_Wjetlnu_T1tttt->SetLineWidth(2);



TGraph* ROC_MHT_QCD_T1tttt= new TGraph(100,Ar_sig_MHT_T1tttt,Ar_bkg_MHT_QCD);
ROC_MHT_QCD_T1tttt->SetLineColor(4);
ROC_MHT_QCD_T1tttt->SetLineWidth(2);

TGraph* ROC_MHT_ttbar_T1tttt= new TGraph(100,Ar_sig_MHT_T1tttt,Ar_bkg_MHT_ttbar);
ROC_MHT_ttbar_T1tttt->SetLineColor(4);
ROC_MHT_ttbar_T1tttt->SetLineWidth(2);

TGraph* ROC_MHT_Ztonunu_T1tttt= new TGraph(100,Ar_sig_MHT_T1tttt,Ar_bkg_MHT_Ztonunu);
ROC_MHT_Ztonunu_T1tttt->SetLineColor(4);
ROC_MHT_Ztonunu_T1tttt->SetLineWidth(2);

TGraph* ROC_MHT_Wjetlnu_T1tttt= new TGraph(100,Ar_sig_MHT_T1tttt,Ar_bkg_MHT_Wjetlnu);
ROC_MHT_Wjetlnu_T1tttt->SetLineColor(4);
ROC_MHT_Wjetlnu_T1tttt->SetLineWidth(2);

TCanvas *c1 = new TCanvas("c1","QCD");
TCanvas *c2 = new TCanvas("c2","TTbar");
TCanvas *c3 = new TCanvas("c3","Ztonunu");
TCanvas *c4 = new TCanvas("c4","Wjetlnu");



c1->cd();
TMultiGraph *mg_qcd = new TMultiGraph();
mg_qcd->SetTitle(" ROC curve ; #epsilon_{T1tttt} ;  #epsilon_{QCD}");
mg_qcd->Add(ROC_MET_QCD_T1tttt,"l");
mg_qcd->Add(ROC_METsig_QCD_T1tttt,"l");
mg_qcd->Add(ROC_MHT_QCD_T1tttt,"l");

leg_1D[0]->AddEntry(ROC_MET_QCD_T1tttt,"MET","l");
leg_1D[0]->AddEntry(ROC_METsig_QCD_T1tttt,"MET/#sqrt{HT}","l");
leg_1D[0]->AddEntry(ROC_MHT_QCD_T1tttt,"MHT","l");





mg_qcd->Draw("AP");
tex1->Draw();
leg_1D[0]->Draw();


c2->cd();
TMultiGraph *mg_ttbar = new TMultiGraph();
mg_ttbar->SetTitle(" ROC curve ; #epsilon_{T1tttt} ;  #epsilon_{t#bar{t}}");
mg_ttbar->Add(ROC_MET_ttbar_T1tttt,"l");
mg_ttbar->Add(ROC_METsig_ttbar_T1tttt,"l");
mg_ttbar->Add(ROC_MHT_ttbar_T1tttt,"l");
leg_1D[1]->AddEntry(ROC_MET_ttbar_T1tttt,"MET","l");
leg_1D[1]->AddEntry(ROC_METsig_ttbar_T1tttt,"MET/#sqrt{HT}","l");
leg_1D[1]->AddEntry(ROC_MHT_ttbar_T1tttt,"MHT","l");


mg_ttbar->Draw("AP");
tex1->Draw();
leg_1D[1]->Draw();


c3->cd();
TMultiGraph *mg_Ztonunu = new TMultiGraph();
mg_Ztonunu->SetTitle(" ROC curve ; #epsilon_{T1tttt} ;  #epsilon_{Z(#rightarrow #nu #nu)+Jets}");
mg_Ztonunu->Add(ROC_MET_Ztonunu_T1tttt,"l");
mg_Ztonunu->Add(ROC_METsig_Ztonunu_T1tttt,"l");
mg_Ztonunu->Add(ROC_MHT_Ztonunu_T1tttt,"l");

leg_1D[2]->AddEntry(ROC_MET_Ztonunu_T1tttt,"MET","l");
leg_1D[2]->AddEntry(ROC_METsig_Ztonunu_T1tttt,"MET/#sqrt{HT}","l");
leg_1D[2]->AddEntry(ROC_MHT_Ztonunu_T1tttt,"MHT","l");


mg_Ztonunu->Draw("AP");
tex1->Draw();
leg_1D[2]->Draw();
c4->cd();
TMultiGraph *mg_Wjetlnu = new TMultiGraph();
mg_Wjetlnu->SetTitle(" ROC curve ; #epsilon_{T1tttt} ;  #epsilon_{W(#rightarrow l #nu)+Jets}");
mg_Wjetlnu->Add(ROC_MET_Wjetlnu_T1tttt,"l");
mg_Wjetlnu->Add(ROC_METsig_Wjetlnu_T1tttt,"l");
mg_Wjetlnu->Add(ROC_MHT_Wjetlnu_T1tttt,"l");

leg_1D[3]->AddEntry(ROC_MET_Wjetlnu_T1tttt,"MET","l");
leg_1D[3]->AddEntry(ROC_METsig_Wjetlnu_T1tttt,"MET/#sqrt{HT}","l");
leg_1D[3]->AddEntry(ROC_MHT_Wjetlnu_T1tttt,"MHT","l");




mg_Wjetlnu->Draw("AP");
tex1->Draw();
leg_1D[3]->Draw();






c1->SaveAs(filenameQCD);
c2->SaveAs(filenamettbar);
c3->SaveAs(filenameZJetnunu);
c4->SaveAs(filenameWJetlnu);

c1->SaveAs(filenameQCDpng);
c2->SaveAs(filenamettbarpng);
c3->SaveAs(filenameZJetnunupng);
c4->SaveAs(filenameWJetlnupng);












}
