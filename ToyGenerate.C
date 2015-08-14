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

using namespace RooFit ;
using namespace std;
void ToyGenerate()
{


  RooRealVar SigmaIe("SigmaIe","SigmaIeta",0.002,0.0232) ;

  RooRealVar mean1_sig("mean1_sig","mean1_sig",0.009167,0.006,0.012);
  mean1_sig.setConstant(true);
  RooRealVar sigma1_sig("sigma1_sig","sigma1_sig",0.000552,0.0000023,0.00055200);
  sigma1_sig.setConstant(true);

  RooGaussian Gauss1_sig("Gauss1_sig","Gauss1_sig",SigmaIe,mean1_sig,sigma1_sig);


  RooRealVar sigma2_sig("sigma2_sig","sigma2_sig",0.000300,0.00005,0.0005);
  sigma2_sig.setConstant(true);

  RooGaussian Gauss2_sig("Gauss2_sig","Gauss2_sig",SigmaIe,mean1_sig,sigma2_sig); 


  RooRealVar fracGauss1_sig("fracGauss1","fracGauss1",0.46,0.1,0.6);
  fracGauss1_sig.setConstant(true);


  RooAddPdf Twogausspdf_sig("Twogauss","Twogauss", RooArgList(Gauss1_sig,Gauss2_sig),RooArgList(fracGauss1_sig));



  RooRealVar slope_cheb_sig("slope","slope",1.0,0.9,1.3);
  slope_cheb_sig.setConstant(true);

  RooChebychev cheb_sig("cheb_sig","cheb_sig",SigmaIe,slope_cheb_sig);

  RooRealVar fracTwogauss_sig("fracTwogauss_sig","fracTwogauss_sig",0.948,0.001,1.00);
  fracTwogauss_sig.setConstant(true);


  RooAddPdf TwogaussChebpdf_sig("pdf","total Pdf", RooArgList(Twogausspdf_sig,cheb_sig),RooArgList(fracTwogauss_sig));

  //bkg
  RooRealVar sigma1_bkg("sigma1_bkg","sigma1_bkg",0.00154,0.00002,0.002);
  sigma1_bkg.setConstant(true);

  RooRealVar mean1_bkg("mean1_bkg","mean1_bkg",0.01100,0.011,0.22);
  mean1_bkg.setConstant(true);
  RooGaussian Gauss1_bkg("gtop2","gtop2",SigmaIe,mean1_bkg,sigma1_bkg);



  RooRealVar mean2_bkg("mean2_bkg","mean2_bkg",0.011441,0.002,0.022);
  mean2_bkg.setConstant(true);

  RooRealVar sigma2_bkg("sigma2_bkg","sigma2_bkg",0.00208,0.0000023,0.555200);
  sigma2_bkg.setConstant(true);

  RooRealVar alpha_bkg("alpha_bkg","alpha_bkg",21,0,100);
  alpha_bkg.setConstant(true);

  RooRealVar n_bkg("n_bkg","n_bkg",2,0,100);
  n_bkg.setConstant(true);

  RooRealVar  frac_CB_bkg("frac_CB_bkg","frac_CB_bkg",0.7,0.0,1.0);
  frac_CB_bkg.setConstant(true);

  RooCBShape  crystalBall_bkg("CBall_bkg","Crystal ball",SigmaIe,mean2_bkg,sigma2_bkg,alpha_bkg,n_bkg);


  RooAddPdf CB_Gausspdf("CBGausspdf","CBGausspdf", RooArgList(crystalBall_bkg,Gauss1_bkg),RooArgList(frac_CB_bkg));



  RooRealVar  fracSigBkg("fracSigBkg","fracSigBkg",0.6,0,1);
  fracSigBkg.setConstant(false);
  
  
  // build combined model
  RooAddPdf model("model","model",TwogaussChebpdf_sig,CB_Gausspdf,fracSigBkg);



  TH1F *fitVal =new TH1F("fitVal","fitVal",200,0,1);
  fitVal->SetLineWidth(2);
  TH1F *fitError =new TH1F("fitError","fitError",500,0.01,0.04);
  fitError->SetLineWidth(2);

  RooPlot* frame_Sigbkg = SigmaIe.frame(Title("Model Sig+Bkg")) ;

  for(int i=0;i<1000;i++){
     
   fracSigBkg.setVal(0.6);

   RooDataSet *data = model.generate(SigmaIe,2000) ;


   model.fitTo(*data);
  
   fitVal->Fill( fracSigBkg.getVal() );

   fitError->Fill( fracSigBkg.getError() / fracSigBkg.getVal() );
   

  
   if(i==99){
    

    data->plotOn(frame_Sigbkg) ;
    model.plotOn(frame_Sigbkg);
   }


   }


  


  //RooPlot* frame_Sigbkg = SigmaIe.frame(Title("Model Sig+Bkg")) ;

  //data->plotOn(frame_Sigbkg) ;
  //model.plotOn(frame_Sigbkg);


  TCanvas *canModel =new TCanvas("canModel","canModel");
  canModel->cd();
  frame_Sigbkg->Draw();

   TCanvas *canFitVal =new TCanvas("canFitVal","canFigVal",500,500);
   canFitVal->cd();
   fitVal->Draw();

   TCanvas *canFitErr =new TCanvas("canFitErr","canFitErr",500,500);
   canFitErr->cd();
   fitError->Draw();


  canModel->SaveAs("canModel.pdf");
  canFitVal->SaveAs("canFitVal.pdf");
  canFitErr->SaveAs("canFitErr.pdf");











}
