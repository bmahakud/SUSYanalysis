#include<vector>
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
#include "ReadTree.cc"
#include "SetStyle.C"
#include <stdio.h>
using namespace std;
void FragAnalysis(){//main programme
    //Set Canvas Style
     TStyle *gStyle = new TStyle("gStyle","Style for P-TDR");
     SetStyle st;
     st.SetPars(gStyle);

     //read Tree
     TChain* tQCD = new TChain("SimpleTree");
     //tQCD->Add("QCDHT200toInf_Frag.root");
     //tQCD->Add("QCDHT200toInf_fragJetID.root");
     tQCD->Add("QCDPt80toInf_fragJetID.root");

     ReadTree QCD(tQCD);


     TH1F *h_delRminT=new TH1F("delRminT","delRminT",100,0,10);
     TH1F *h_delRminC=new TH1F("delRminC","delRminC",100,0,10);

     int maxEvents_QCD=tQCD->GetEntries();
     cout<<"maxEventsQCD: "<<maxEvents_QCD<<endl;
     for(int iEv=0;iEv<maxEvents_QCD;iEv++){//Looping over QCD
     tQCD->GetEntry(iEv);
     if(iEv % 10000==0){cout<<"Event no QCD : "<<iEv<<endl;}
     if(QCD.bestPhotonE->size() >=1){// Best photon event

      //Create Lorentz vectors for particles of interest
      TLorentzVector BestPhoton;
      TLorentzVector BestGenPhoton;
      TLorentzVector minGenQuark;
      TLorentzVector minGenGluon;
      

      //Fill best photon
      BestPhoton.SetPxPyPzE(QCD.bestPhotonPx->at(0), QCD.bestPhotonPy->at(0), QCD.bestPhotonPz->at(0) ,QCD.bestPhotonE->at(0));
      

     
    ////////////////////////////////////////////////////////////////////////////////
     bool bestGenPhotonFound=false;
     for(int iGenPh=0;iGenPh<QCD.genPhotonPx->size();iGenPh++){//gen photon loop
    
        TLorentzVector iGenPhoton;
        iGenPhoton.SetPxPyPzE(QCD.genPhotonPx->at(iGenPh),QCD.genPhotonPy->at(iGenPh) ,QCD.genPhotonPz->at(iGenPh) ,QCD.genPhotonE->at(iGenPh) );              

        double deltaR=BestPhoton.DeltaR(iGenPhoton);
        double PtRatio=iGenPhoton.Pt()/BestPhoton.Pt();

       if(deltaR<0.1 && PtRatio >0.5 && PtRatio < 2. && iGenPhoton.Pt() > 100. && QCD.genPhotonStatus->at(iGenPh)==1 && (fabs(QCD.genPhotonMother->at(iGenPh)) <= 22 || fabs(QCD.genPhotonMother->at(iGenPh)) == 2212) ){//gen matched stable prompt photon
          
          BestGenPhoton.SetPxPyPzE(QCD.genPhotonPx->at(iGenPh),QCD.genPhotonPy->at(iGenPh) ,QCD.genPhotonPz->at(iGenPh) ,QCD.genPhotonE->at(iGenPh) );
          bestGenPhotonFound=true;
                                                                                            }//gen matched stable prompt photon


                                                          }//gen photon loop
    ///////////////////////////////////////////////////////////////////////////////////


        
    //***************************************************************************parton loop
           bool QuarkAwayfromPhoton=false;
           bool GluonAwayfromPhoton=false;
           double deltaRmin=1000;
           bool deltaRminHasValue=false;

         if(bestGenPhotonFound==true){//best gen photon event



                        for(int iQ=0;iQ<QCD.genQuarkE->size();iQ++){//Loop over gen quark
                           
                            TLorentzVector iGenQuark;
                            iGenQuark.SetPxPyPzE(QCD.genQuarkPx->at(iQ),QCD.genQuarkPy->at(iQ) ,QCD.genQuarkPz->at(iQ) ,QCD.genQuarkE->at(iQ) );              
                           
                                         if(QCD.genQuarkStatus->at(iQ)==23){//status 23 quark

                                              double deltaR=BestGenPhoton.DeltaR(iGenQuark);
                                                                                if(deltaR<deltaRmin){
                                                                                      deltaRmin=deltaR;
                                                                                      deltaRminHasValue=true;
                                                                                               }



                                                                            }//status 23 quark


                             }//loop over gen quark
        
                              if(deltaRminHasValue==true){
                              h_delRminT->Fill(deltaRmin,226.*QCD.evWeight);
                              if(deltaRmin>0.4){h_delRminC->Fill(deltaRmin,226.*QCD.evWeight);}
                                }
                               




      deltaRmin=1000;
      deltaRminHasValue=false;
       for(int iG=0;iG<QCD.genGluonE->size();iG++){//Loop over gen gluon
                           
                            TLorentzVector iGenGluon;
                            iGenGluon.SetPxPyPzE(QCD.genGluonPx->at(iG),QCD.genGluonPy->at(iG) ,QCD.genGluonPz->at(iG) ,QCD.genGluonE->at(iG) );              
                           
                                         if(QCD.genGluonStatus->at(iG)==23){//status 23 gluon

                                              double deltaR=BestGenPhoton.DeltaR(iGenGluon);
                                                                                if(deltaR<deltaRmin){
                                                                                      deltaRmin=deltaR;
                                                                                      deltaRminHasValue=true;
                                                                                               }



                                                                            }//status 23 gluon


                             }//loop over gen gluon


                      if(deltaRminHasValue==true){
                              h_delRminT->Fill(deltaRmin,226.*QCD.evWeight);
                                 if(deltaRmin>0.4){h_delRminC->Fill(deltaRmin,226.*QCD.evWeight);}
                                  }

















                                     }//best gen photon event 

    //******************************************************************************parton loop









                                   }// Best photon event
      }//loop over QCD


   

   double aftercut=h_delRminC->Integral();
   double beforecut=h_delRminT->Integral();
   double frag=aftercut/beforecut;

   char Fragf[100];
   sprintf(Fragf,"FragFrac:  %4.2f",frag);


   TPaveText *tpav_txt = new TPaveText(0.53043478,0.4148342,0.8652174,0.8010471,"brNDC");

   tpav_txt->SetBorderSize(0);
   tpav_txt->SetFillStyle(0);
   tpav_txt->SetTextAlign(11);
   tpav_txt->SetTextFont(42);
   tpav_txt->SetTextSize(0.04);
   //tpav_txt->AddText("QCD HT(pythia8,madgraphMLM)");
   tpav_txt->AddText("QCD Pt(pythia8)");
   tpav_txt->AddText("HT >500");
   tpav_txt->AddText("#gamma p_{T} > 100 ");
   tpav_txt->AddText("NJets >=4");
   tpav_txt->AddText("BTags=0");
   tpav_txt->AddText("MHT>200");
   tpav_txt->AddText("#Delta #Phi (0.5,0.5,0.3,0.3)");
   tpav_txt->AddText("w/ JetID");
   tpav_txt->AddText(Fragf);
   
   TPaveText *pCMS = new TPaveText(0.132107,0.9308003,0.8327759,0.9923583,"brNDC");

    pCMS->SetBorderSize(0);
    pCMS->SetFillStyle(0);
    pCMS->SetTextAlign(11);
    pCMS->SetTextFont(42);
    pCMS->SetTextSize(0.04);
    pCMS->AddText("CMS #it{Simulation}       226pb^{-1} #sqrt{s}= 13 TeV");






   h_delRminT->GetXaxis()->SetTitle("DeltaR(parton,photon)");
   h_delRminT->GetYaxis()->SetTitle("Events");

   TCanvas *c=new TCanvas("c","c");
   c->cd();
   h_delRminT->Draw("hist");
   tpav_txt->Draw();
   pCMS->Draw();

   c->SaveAs("FragPlot.png");

   cout<<"DeltaR > 0.4 :  "<<h_delRminC->Integral()<<endl;
   cout<<"All DeltaR  :  "<<h_delRminT->Integral()<<endl;





}//main programme
