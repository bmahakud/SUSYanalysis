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

void MyROCnew(std::string HTmin="500",std::string HTmax="1000",std::string NJetsmin="3",std::string NJetsmax="5"){



int NJetsMin = atoi(NJetsmin.c_str());
int NJetsMax = atoi(NJetsmax.c_str());

double HT_Min=atoi(HTmin.c_str());
double HT_Max=atoi(HTmax.c_str());




cout <<"HT MIn = "<<HT_Min<<endl;





gROOT->ProcessLine(".L tdrstyle.C");
 setTDRStyle();

char cuts[300];

char njets_pav[50];

char ht_pav[50];

char filenameQCD[50];
char filenamettbar[50];
char filenameZJetnunu[50];
char filenameWJetlnu[50];
char signal[100];
//////////////////////////User Entry box
double htMin=HT_Min;
double htMax=HT_Max;
int njetsMin=NJetsMin;
int njetsMax=NJetsMax;

char filenameOverlaid[50];


sprintf(signal,"T1tttt(mGo=1100GeV ,mLSP=25 GeV)");




////////////////////////////////User Entry box





sprintf(cuts,"NJets_patJetsAK5PFPt50Eta25>=%i&&NJets_patJetsAK5PFPt50Eta25<=%i&&HT_patJetsAK5PFPt50Eta25>=%i&&HT_patJetsAK5PFPt50Eta25<=%i",njetsMin,njetsMax,htMin,htMax);

sprintf(filenameQCD,"QCD_%iHT%i_%iNjets%i.pdf",htMin,htMax,njetsMin,njetsMax);
sprintf(filenamettbar,"TTbar_%iHT%i_%iNjets%i.pdf",htMin,htMax,njetsMin,njetsMax);
sprintf(filenameZJetnunu,"ZJetnunu_%iHT%i_%iNjets%i.pdf",htMin,htMax,njetsMin,njetsMax);
sprintf(filenameWJetlnu,"WJetlnu_%iHT%i_%iNjets%i.pdf",htMin,htMax,njetsMin,njetsMax);





sprintf(njets_pav,"%i#leqHT#leq%i",htMin,htMax);
sprintf(ht_pav,"%i#leqJets#leq%i",njetsMin,njetsMax);


TPaveText *tex1 = new TPaveText(0.204698,0.7377622,0.4043624,0.8863636,"brNDC");
   tex1->SetBorderSize(0);
   tex1->SetFillStyle(0);
   tex1->SetTextAlign(11);
   tex1->SetTextFont(42);
   tex1->SetTextSize(0.04);
   text = tex1->AddText(signal);
   text = tex1->AddText(ht_pav);
   text = tex1->AddText(njets_pav);




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
SIGtree_T1tttt->Add("/eos/uscms/store/user/awhitbe1/SuSySubstructureAnalysisNtuples_V10/SMS_T1tttt_mGo1100_mLSP25*.root");


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



            sig_MET_T1tttt->Scale(0.00329);
            bkg_MET_QCD500->Scale(7.186921);
            bkg_MET_QCD1000->Scale(0.3965);
            bkg_MET_ttbar->Scale(0.08163);
            bkg_MET_Ztonunu->Scale(0.1237);
            bkg_MET_Wjetlnu->Scale(0.1042);


            sig_METsig_T1tttt->Scale(0.00329);
            bkg_METsig_QCD500->Scale(7.186921);
            bkg_METsig_QCD1000->Scale(0.3965);
            bkg_METsig_ttbar->Scale(0.08163);
            bkg_METsig_Ztonunu->Scale(0.1237);
            bkg_METsig_Wjetlnu->Scale(0.1042);


            sig_MHT_T1tttt->Scale(0.00329);
            bkg_MHT_QCD500->Scale(7.186921);
            bkg_MHT_QCD1000->Scale(0.3965);
            bkg_MHT_ttbar->Scale(0.08163);
            bkg_MHT_Ztonunu->Scale(0.1237);
            bkg_MHT_Wjetlnu->Scale(0.1042);






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





for(int i=0;i<12;i++){

        const char *startchar;
     
        startchar = start[i].c_str();
        
         char processName[100];
         sprintf(processName, "%s", startchar);


char filenameOverlap[100];
sprintf(filenameOverlap,"File%i_%iHT%i_%iNjets%i.pdf",i,htMin,htMax,njetsMin,njetsMax);


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
   texT = tex2->AddText(processName);


  c_1D[i]->cd();
  tex2->Draw();
  
  c_1D[i]->SaveAs(filenameOverlap);

}












double Ar_sig_MET_T1tttt[500],Ar_bkg_MET_QCD[500],Ar_bkg_MET_ttbar[500],Ar_bkg_MET_Ztonunu[500],Ar_bkg_MET_Wjetlnu[500];
double Ar_sig_METsig_T1tttt[500],Ar_bkg_METsig_QCD[500],Ar_bkg_METsig_ttbar[500],Ar_bkg_METsig_Ztonunu[500],Ar_bkg_METsig_Wjetlnu[500];
double Ar_sig_MHT_T1tttt[500],Ar_bkg_MHT_QCD[500],Ar_bkg_MHT_ttbar[500],Ar_bkg_MHT_Ztonunu[500],Ar_bkg_MHT_Wjetlnu[500];       




     for(int i=0; i<500; i++){

      Ar_sig_MET_T1tttt[i] = sig_MET_T1tttt->Integral(i, 501);
      Ar_bkg_MET_QCD[i] = bkg_MET_QCD->Integral(i, 501);
      Ar_bkg_MET_ttbar[i] = bkg_MET_ttbar->Integral(i, 501); 
      Ar_bkg_MET_Ztonunu[i] = bkg_MET_Ztonunu->Integral(i, 501);
      Ar_bkg_MET_Wjetlnu[i] = bkg_MET_Wjetlnu->Integral(i, 501);

      Ar_sig_METsig_T1tttt[i] = sig_METsig_T1tttt->Integral(i, 501);
      Ar_bkg_METsig_QCD[i] = bkg_METsig_QCD->Integral(i, 501);
      Ar_bkg_METsig_ttbar[i] = bkg_METsig_ttbar->Integral(i, 501); 
      Ar_bkg_METsig_Ztonunu[i] = bkg_METsig_Ztonunu->Integral(i, 501);
      Ar_bkg_METsig_Wjetlnu[i] = bkg_METsig_Wjetlnu->Integral(i, 501);

      Ar_sig_MHT_T1tttt[i] = sig_MHT_T1tttt->Integral(i, 501);
      Ar_bkg_MHT_QCD[i] = bkg_MHT_QCD->Integral(i, 501);
      Ar_bkg_MHT_ttbar[i] = bkg_MHT_ttbar->Integral(i, 501); 
      Ar_bkg_MHT_Ztonunu[i] = bkg_MHT_Ztonunu->Integral(i, 501);
      Ar_bkg_MHT_Wjetlnu[i] = bkg_MHT_Wjetlnu->Integral(i, 501);

      }


TGraph* ROC_MET_QCD_T1tttt= new TGraph(500,Ar_sig_MET_T1tttt,Ar_bkg_MET_QCD);
ROC_MET_QCD_T1tttt->SetLineColor(2);
ROC_MET_QCD_T1tttt->SetLineWidth(2);

TGraph* ROC_MET_ttbar_T1tttt= new TGraph(500,Ar_sig_MET_T1tttt,Ar_bkg_MET_ttbar);
ROC_MET_ttbar_T1tttt->SetLineColor(2);
ROC_MET_ttbar_T1tttt->SetLineWidth(2);

TGraph* ROC_MET_Ztonunu_T1tttt= new TGraph(500,Ar_sig_MET_T1tttt,Ar_bkg_MET_Ztonunu);
ROC_MET_Ztonunu_T1tttt->SetLineColor(2);
ROC_MET_Ztonunu_T1tttt->SetLineWidth(2);

TGraph* ROC_MET_Wjetlnu_T1tttt= new TGraph(500,Ar_sig_MET_T1tttt,Ar_bkg_MET_Wjetlnu);
ROC_MET_Wjetlnu_T1tttt->SetLineColor(2);
ROC_MET_Wjetlnu_T1tttt->SetLineWidth(2);

////////////////////////////////////////////////
TGraph* ROC_METsig_QCD_T1tttt= new TGraph(500,Ar_sig_METsig_T1tttt,Ar_bkg_METsig_QCD);
ROC_METsig_QCD_T1tttt->SetLineColor(3);
ROC_METsig_QCD_T1tttt->SetLineWidth(2);

TGraph* ROC_METsig_ttbar_T1tttt= new TGraph(500,Ar_sig_METsig_T1tttt,Ar_bkg_METsig_ttbar);
ROC_METsig_ttbar_T1tttt->SetLineColor(3);
ROC_METsig_ttbar_T1tttt->SetLineWidth(2);

TGraph* ROC_METsig_Ztonunu_T1tttt= new TGraph(500,Ar_sig_METsig_T1tttt,Ar_bkg_METsig_Ztonunu);
ROC_METsig_Ztonunu_T1tttt->SetLineColor(3);
ROC_METsig_Ztonunu_T1tttt->SetLineWidth(2);

TGraph* ROC_METsig_Wjetlnu_T1tttt= new TGraph(500,Ar_sig_METsig_T1tttt,Ar_bkg_METsig_Wjetlnu);
ROC_METsig_Wjetlnu_T1tttt->SetLineColor(3);
ROC_METsig_Wjetlnu_T1tttt->SetLineWidth(2);



TGraph* ROC_MHT_QCD_T1tttt= new TGraph(500,Ar_sig_MHT_T1tttt,Ar_bkg_MHT_QCD);
ROC_MHT_QCD_T1tttt->SetLineColor(4);
ROC_MHT_QCD_T1tttt->SetLineWidth(2);

TGraph* ROC_MHT_ttbar_T1tttt= new TGraph(500,Ar_sig_MHT_T1tttt,Ar_bkg_MHT_ttbar);
ROC_MHT_ttbar_T1tttt->SetLineColor(4);
ROC_MHT_ttbar_T1tttt->SetLineWidth(2);

TGraph* ROC_MHT_Ztonunu_T1tttt= new TGraph(500,Ar_sig_MHT_T1tttt,Ar_bkg_MHT_Ztonunu);
ROC_MHT_Ztonunu_T1tttt->SetLineColor(4);
ROC_MHT_Ztonunu_T1tttt->SetLineWidth(2);

TGraph* ROC_MHT_Wjetlnu_T1tttt= new TGraph(500,Ar_sig_MHT_T1tttt,Ar_bkg_MHT_Wjetlnu);
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





}
