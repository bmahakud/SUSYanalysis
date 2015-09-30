#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooPlot.h"
#include "TTree.h"
#include "TH1D.h"
#include "TRandom.h"
#include<iostream>
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include<vector>
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
#include "ReadTree.cc"
#include "PlotHisto.C"
#include "SetStyle.C"


using namespace std;
using namespace RooFit ;
void Fit2(){


   double rangeMax=0.02;
   double rangeMin=0.005;
   int nBins=40;

   TH1F *hpromptSRreal=new TH1F("hpromptSRreal","hpromptSRreal",nBins,rangeMin,rangeMax);
   hpromptSRreal->SetLineWidth(2);

   TH1F *htotalSRreal=new TH1F("htotalSRreal","htotalSRreal",nBins,rangeMin,rangeMax);
   htotalSRreal->SetLineWidth(2);


   TH1F *hpromptSR=new TH1F("hpromptSR","hpromptSR",nBins,rangeMin,rangeMax);
   hpromptSR->SetLineWidth(2);

   

   TH1F *hnonpromptSR=new TH1F("hnonpromptSR","hnonpromptSR",nBins,rangeMin,rangeMax);
   hnonpromptSR->SetLineWidth(2);

   TH1F *hnonpromptSB=new TH1F("hnonpromptSB","hnonpromptSB",nBins,rangeMin,rangeMax);
   hnonpromptSB->SetLineWidth(2);

   TH1F *htotalSR=new TH1F("htotalSR","htotalSR",nBins,rangeMin,rangeMax);
   htotalSR->SetLineWidth(2);
   



    TChain* t1 = new TChain("SimpleTree");
    t1->Add("GJets400HTInfWQHTB.root");//SignalGJets3.root");
    ReadTree read1(t1);


    TChain* t2 = new TChain("SimpleTree");
    t2->Add("QCD500HTInfWQHTBFull.root");//QCD80toInf.root");
    ReadTree read2(t2);



   int maxEvents1=t1->GetEntries();
    cout<<"maxEventsGJets: "<<maxEvents1<<endl;
    for(int i1=0;i1<maxEvents1;i1++){//GJets loop
    t1->GetEntry(i1);
    if(i1 % 1000000==0){cout<<"Event no GJets : "<<i1<<endl;}

   if(read1.nonPrompt !=1 && read1.BaseLine()==true && read1.evWeight<3. && read1.dPhi1>0.5 && read1.dPhi2>0.5 && read1.dPhi3 > 0.3 && read1.PGN==1 && read1.IchSR==1){//prompt 
 
   
   hpromptSR->Fill(read1.SigmaIetaIeta,read1.evWeight);
   if(read1.SigmaIetaIeta < 0.02){
    htotalSR->Fill(read1.SigmaIetaIeta,read1.evWeight);  
       }

   if(read1.SigmaIetaIeta < 0.0107){
      hpromptSRreal->Fill(read1.SigmaIetaIeta,read1.evWeight);
      htotalSRreal->Fill(read1.SigmaIetaIeta,read1.evWeight);

       }



   }//prompt


   }//GJets loop





   int maxEvents2=t2->GetEntries();
    cout<<"maxEventsQCD: "<<maxEvents2<<endl;
    for(int i2=0;i2<maxEvents2;i2++){//QCD loop
    t2->GetEntry(i2);
    if(i2 % 1000000==0){cout<<"Event no QCD : "<<i2<<endl;}

    if(read2.nonPrompt ==1 && read2.BaseLine()==true  && read2.PGN==1 ){//non prompt 
   
   if(read2.IchSR==1 && read2.dPhi1>0.5 && read2.dPhi2>0.5 && read2.dPhi3 > 0.3 && read2.SigmaIetaIeta < 0.02){//2
   hnonpromptSR->Fill(read2.SigmaIetaIeta,read2.evWeight);
   
   
   htotalSR->Fill(read2.SigmaIetaIeta,read2.evWeight);///
   if(read2.SigmaIetaIeta < 0.0107){//1
      
      htotalSRreal->Fill(read2.SigmaIetaIeta,read2.evWeight);

       }//1


      }//2
       
       

   if(read2.IchSB==1 && read2.SigmaIetaIeta < 0.02){//3
   hnonpromptSB->Fill(read2.SigmaIetaIeta,read2.evWeight);
   
       }//3
    
   


   }//non prompt





   }//QCD loop




  //hnonpromptSR->Draw();
   

  TCanvas *cRoo=new TCanvas("cRoo","cRoo",850,850);
  cRoo->Divide(2,2);

  RooRealVar SIeta("SIeta","#sigma_{i#etai#eta}",rangeMin,rangeMax);

  RooDataHist dataSR("dataSR","dataSR",SIeta,Import(*htotalSR));

  hpromptSR->Scale(1/hpromptSR->Integral());
  hnonpromptSB->Scale(1/hnonpromptSB->Integral());

  RooDataHist pdfdata1("pdfdata1","pdfdata1",SIeta,Import(*hpromptSR));
  RooDataHist pdfdata2("pdfdata2","pdfdata2",SIeta,Import(*hnonpromptSB));


  RooHistPdf histpdf1("histpdf1","histpdf1",SIeta,pdfdata1,0);
  RooHistPdf histpdf2("histpdf2","histpdf2",SIeta,pdfdata2,0);


  RooRealVar Fitfrac("Fitfrac","Fitfrac",0.7,0.,1);

  RooAddPdf pdf("pdf","PSR-NPSB-PDF", RooArgList(histpdf1,histpdf2),Fitfrac);


  RooPlot* frame1 = SIeta.frame(Title("pdf from SR,Prompt"));
  pdfdata1.plotOn(frame1);
  histpdf1.plotOn(frame1);
  cRoo->cd(1);
  frame1->Draw(); 

  RooPlot* frame2 = SIeta.frame(Title("pdf from SB,nonPrompt"));
  pdfdata2.plotOn(frame2);
  histpdf2.plotOn(frame2);
  cRoo->cd(2);
  frame2->Draw();


  RooPlot* frame3 = SIeta.frame(Title("pdf from SR-Prompt+SB-nonPrompt"));
  
  cRoo->cd(3);
  pdf.plotOn(frame3,Components(RooArgList(histpdf1)), LineColor(kRed),LineStyle(2), LineWidth(3));
  pdf.plotOn(frame3,Components(RooArgList(histpdf2)), LineColor(kGreen),LineStyle(2), LineWidth(3));
  pdf.plotOn(frame3,Components(RooArgList(pdf)), LineColor(kBlue),LineStyle(1), LineWidth(2));
  frame3->Draw();

  TPaveText *tpav_txt = new TPaveText(0.53043478,0.4148342,0.7652174,0.8010471,"brNDC");

  tpav_txt->SetBorderSize(0);
  tpav_txt->SetFillStyle(0);
  tpav_txt->SetTextAlign(11);
  tpav_txt->SetTextFont(42);
  tpav_txt->SetTextSize(0.04);
  double RealFrac=hpromptSRreal->Integral()/htotalSRreal->Integral();
  int Percent = (int)round(100*hpromptSRreal->Integral()/htotalSRreal->Integral());

  char Rfrac[100];
  sprintf(Rfrac,"RealFraction: %i",Percent); 
  tpav_txt->AddText(Rfrac);

  cRoo->cd(4);
  gPad->cd();
  RooPlot* frame4 = SIeta.frame(Title("Fitting to SR data"));

  dataSR.plotOn(frame4);
  pdf.fitTo(dataSR);
  pdf.plotOn(frame4);
  pdf.paramOn(frame4);
  pdf.plotOn(frame4,Components(RooArgList(histpdf1)), LineColor(kRed),LineStyle(2), LineWidth(3));
  pdf.plotOn(frame4,Components(RooArgList(histpdf2)), LineColor(kGreen),LineStyle(2), LineWidth(3));
  pdf.plotOn(frame4,Components(RooArgList(pdf)), LineColor(kBlue),LineStyle(1), LineWidth(2));
  
  SIeta.setRange("SR",0.005,0.0107) ;
  RooAbsReal* fracP = histpdf1.createIntegral(SIeta,NormSet(SIeta),Range("SR"));
  RooAbsReal* Ip=histpdf1.createIntegral(SIeta);
  double fracP_val=fracP->getVal();
  double P_val=Ip->getVal();
  double promptIntegral=fracP_val*P_val;

  RooAbsReal* fracNP = histpdf2.createIntegral(SIeta,NormSet(SIeta),Range("SR"));
  RooAbsReal* Inp=histpdf2.createIntegral(SIeta);
  double fracNP_val=fracNP->getVal();
  double NP_val=Inp->getVal();
  double nonpromptIntegral=fracNP_val*NP_val;
  

  cout<<"fracP:  "<<fracP_val<<endl;
  cout<<"fracNP:  "<<fracNP_val<<endl;

  cout<<" P_val: "<<P_val<<endl;


  cout<<"NP_val: "<<NP_val<<endl;

  cout<<"Integral Prompt after Fit pdf : "<<promptIntegral<<endl;
  cout<<"Integral non Prompt after Fit pdf : "<<nonpromptIntegral<<endl;




  

  
  frame4->Draw();
  tpav_txt->Draw();
    float chosenEff = 0.0107;
    TLine *line =new TLine(chosenEff,0,chosenEff,500);
    line->SetLineColor(kOrange+8);
    line->SetLineWidth(2);
    line->Draw();





  cout<<"real fraction: "<<hpromptSRreal->Integral()/htotalSRreal->Integral()<<endl;

  std::cout<<"Chisquare/ndof ="<<frame4->chiSquare()<<std::endl;


  cRoo->SaveAs("Fitresult.png");
  cRoo->SaveAs("Fitresult.gif");







}
