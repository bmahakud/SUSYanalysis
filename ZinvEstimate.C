#include<vector>
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
#include "/home/bibhu/Desktop/PhD/RA2bSUSYFromOct2015/src/ReadTree.cc"
#include "/home/bibhu/Desktop/PhD/RA2bSUSYFromOct2015/src/SetStyle.C"
#include "/home/bibhu/Desktop/PhD/RA2bSUSYFromOct2015/src/StackPlot.C"
#include "/home/bibhu/Desktop/PhD/RA2bSUSYFromOct2015/src/ComputeBin.C"
#include <stdio.h>
using namespace std;
void ZinvEstimate(){//main programme
     //Set Canvas Style
     TStyle *gStyle = new TStyle("gStyle","Style for P-TDR");
     SetStyle st;
     st.SetPars(gStyle);
     //finished setting canvas style
     DataMC plot;

     TString InputFilePathV3="/home/bibhu/Desktop/PhD/RA2bSUSYFromOct2015/SkimTrees/Run2ProductionV3/";

     TString InputFilePathV2="/home/bibhu/Desktop/PhD/RA2bSUSYFromOct2015/SkimTrees/Run2ProductionV2/";

     TChain* tZinv = new TChain("tree");
     tZinv->Add(InputFilePathV2+"tree_signal/tree_ZJetsToNuNu_HT*.root");
     ReadTree Zinv(tZinv);


     //reading the GJets MC
     TChain* tGJets = new TChain("tree");
     tGJets->Add(InputFilePathV3+"tree_GJet_CleanVars/tree_GJets_HT*.root");
     ReadTree GJets(tGJets);





     //reading QCD MC
     TChain* tQCD = new TChain("tree");
     tQCD->Add(InputFilePathV3+"tree_GJet_CleanVars/tree_QCD_HT*.root");
     ReadTree QCD(tQCD);

     //reading Single photon Data
     TChain* tData = new TChain("tree");
     tData->Add(InputFilePathV3+"tree_GJet_CleanVars/tree_SinglePhoton_*.root");
     ReadTree Data(tData);

     double Lumi=1286.553;


     int nBinsHT=13;
     int nBinsMHT=7;
     int nBinsPt=8;
     int nBinsNJ=6;
     int nBinsS=25;
     double HTbins[14]={500.,600.,700,800,900,1000.,1100,1200.,1300,1400,1500,1700,2000,3000};
     double MHTbins[8]={200.,300,400,500.,600,750.,1000,1500.};
     double Ptbins[9]={100,200.,300,400,500.,600,750.,1000,1500.};
     double NJetsbins[7]={4,5,6,7,8,9,12};

    /////////Three MHT Bins
    double MHTbin1Min=200;
    double MHTbin1Max=500;
    double MHTbin2Min=500;
    double MHTbin2Max=750;
    double MHTbin3Min=750;
    double MHTbin3Max=1500;



    ///////////Three MHT Bins

     

     int nBinAN=18;
     double nBinANmax=18.5;

     /////////////////////////////////////////////////////////////////////////////All user input changes above 
     TH1F *hHT_Zinv=new TH1F("hHT_Zinv","hHT_Zinv",nBinsHT,HTbins);
     TH1F *hMHT_Zinv=new TH1F("hMHT_Zinv","hMHT_Zinv",nBinsMHT,MHTbins);
     TH1F *hNJets_Zinv=new TH1F("hNJets_Zinv","hNJets_Zinv",nBinsNJ,NJetsbins);
     


     TH1F *hHT_GJets=new TH1F("hHT_GJets","hHT_GJets",nBinsHT,HTbins);
     TH1F *hMHT_GJets=new TH1F("hMHT_GJets","hMHT_GJets",nBinsMHT,MHTbins);
     TH1F *hNJets_GJets=new TH1F("hNJets_GJets","hNJets_GJets",nBinsNJ,NJetsbins);

     TH1F *hSieta_GJetsEB=new TH1F("hSieta_GJetsEB","hSieta_GJetsEB",nBinsS,0.006,0.0107);
     TH1F *hSieta_GJetsEC=new TH1F("hSieta_GJetsEC","hSieta_GJetsEC",nBinsS,0.01,0.0272);


     TH1F *hSieta_GJetsEBLow=new TH1F("hSieta_GJetsEBLow","hSieta_GJetsEBLow",nBinsS,0.006,0.0107);
     TH1F *hSieta_GJetsECLow=new TH1F("hSieta_GJetsECLow","hSieta_GJetsECLow",nBinsS,0.01,0.0272);

     TH1F *hSieta_GJetsEBMed=new TH1F("hSieta_GJetsEBMed","hSieta_GJetsEBMed",nBinsS,0.006,0.0107);
     TH1F *hSieta_GJetsECMed=new TH1F("hSieta_GJetsECMed","hSieta_GJetsECMed",nBinsS,0.01,0.0272);

     TH1F *hSieta_GJetsEBHigh=new TH1F("hSieta_GJetsEBHigh","hSieta_GJetsEBHigh",nBinsS,0.006,0.0107);
     TH1F *hSieta_GJetsECHigh=new TH1F("hSieta_GJetsECHigh","hSieta_GJetsECHigh",nBinsS,0.01,0.0272);
  

     TH1F *hPhPt_GJetsEB=new TH1F("hPhPt_GJetsEB","hPhPt_GJetsEB",nBinsPt,Ptbins);
     TH1F *hPhPt_GJetsEC=new TH1F("hPhPt_GJetsEC","hPhPt_GJetsEC",nBinsPt,Ptbins);




     TH1F *hHT_QCD=new TH1F("hHT_QCD","hHT_QCD",nBinsHT,HTbins);
     TH1F *hMHT_QCD=new TH1F("hMHT_QCD","hMHT_QCD",nBinsMHT,MHTbins);
     TH1F *hNJets_QCD=new TH1F("hNJets_QCD","hNJets_QCD",nBinsNJ,NJetsbins);

     TH1F *hSieta_QCDEB=new TH1F("hSieta_QCDEB","hSieta_QCDEB",nBinsS,0.006,0.0107);
     TH1F *hSieta_QCDEC=new TH1F("hSieta_QCDEC","hSieta_QCDEC",nBinsS,0.01,0.0272);     



     TH1F *hSieta_QCDEBLow=new TH1F("hSieta_QCDEBLow","hSieta_QCDEBLow",nBinsS,0.006,0.0107);
     TH1F *hSieta_QCDECLow=new TH1F("hSieta_QCDECLow","hSieta_QCDECLow",nBinsS,0.01,0.0272);

     TH1F *hSieta_QCDEBMed=new TH1F("hSieta_QCDEBMed","hSieta_QCDEBMed",nBinsS,0.006,0.0107);
     TH1F *hSieta_QCDECMed=new TH1F("hSieta_QCDECMed","hSieta_QCDECMed",nBinsS,0.01,0.0272);

     TH1F *hSieta_QCDEBHigh=new TH1F("hSieta_QCDEBHigh","hSieta_QCDEBHigh",nBinsS,0.006,0.0107);
     TH1F *hSieta_QCDECHigh=new TH1F("hSieta_QCDECHigh","hSieta_QCDECHigh",nBinsS,0.01,0.0272);

     TH1F *hPhPt_QCDEB=new TH1F("hPhPt_QCDEB","hPhPt_QCDEB",nBinsPt,Ptbins);
     TH1F *hPhPt_QCDEC=new TH1F("hPhPt_QCDEC","hPhPt_QCDEC",nBinsPt,Ptbins);
    



     TH1F *hHT_Data=new TH1F("hHT_Data","hHT_Data",nBinsHT,HTbins);
     TH1F *hMHT_Data=new TH1F("hMHT_Data","hMHT_Data",nBinsMHT,MHTbins);
     TH1F *hNJets_Data=new TH1F("hNJets_Data","hNJets_Data",nBinsNJ,NJetsbins);

     TH1F *hSieta_DataEB=new TH1F("hSieta_DataEB","hSieta_DataEB",nBinsS,0.006,0.0107);
     TH1F *hSieta_DataEC=new TH1F("hSieta_DataEC","hSieta_DataEC",nBinsS,0.01,0.0272);;


     TH1F *hSieta_DataEBLow=new TH1F("hSieta_DataEBLow","hSieta_DataEBLow",nBinsS,0.006,0.0107);
     TH1F *hSieta_DataECLow=new TH1F("hSieta_DataECLow","hSieta_DataECLow",nBinsS,0.01,0.0272);

     TH1F *hSieta_DataEBMed=new TH1F("hSieta_DataEBMed","hSieta_DataEBMed",nBinsS,0.006,0.0107);
     TH1F *hSieta_DataECMed=new TH1F("hSieta_DataECMed","hSieta_DataECMed",nBinsS,0.01,0.0272);

     TH1F *hSieta_DataEBHigh=new TH1F("hSieta_DataEBHigh","hSieta_DataEBHigh",nBinsS,0.006,0.0107);
     TH1F *hSieta_DataECHigh=new TH1F("hSieta_DataECHigh","hSieta_DataECHigh",nBinsS,0.01,0.0272);
    
     TH1F *hPhPt_DataEB=new TH1F("hPhPt_DataEB","hPhPt_DataEB",nBinsPt,Ptbins);
     TH1F *hPhPt_DataEC=new TH1F("hPhPt_DataEC","hPhPt_DataEC",nBinsPt,Ptbins);
    



     TH1F *h_NZinv18bin=new TH1F("h_NZinv18bin","h_NZinv18bin",nBinAN,0.5,nBinANmax); 
     //
     TH1F *h_NZinv18binC=new TH1F("h_NZinv18binC","h_NZinv18binC",nBinAN,0.5,nBinANmax);   

     //TH1F *EBestimate=new TH1F("EBestimate","EBestimate",18,0.5,18.5);
     //TH1F *ECestimate=new TH1F("ECestimate","ECestimate",18,0.5,18.5);

     TH1F *ZinvEstimate=new TH1F("ZinvEstimate","ZinvEstimate",nBinAN,0.5,nBinANmax);

     TH1F  *h_NGJets18bin=new TH1F("h_NGJets18binC","h_NGJets18binC",nBinAN,0.5,nBinANmax); 

     TH1F *h_NGJets18binEB=new TH1F("h_NGJets18binEB","h_NGJets18binEB",nBinAN,0.5,nBinANmax);
  
     TH1F *h_NGJets18binEC=new TH1F("h_NGJets18binEC","h_NGJets18binEC",nBinAN,0.5,nBinANmax);     


     TH1F *h_NQCD18binEB=new TH1F("h_NQCD18binEB","h_NQCD18binEB",nBinAN,0.5,nBinANmax);
  
     TH1F *h_NQCD18binEC=new TH1F("h_NQCD18binEC","h_NQCD18binEC",nBinAN,0.5,nBinANmax); 



     TH1F *h_Ndata18binEB=new TH1F("h_Ndata18binEB","h_Ndata18binEB",nBinAN,0.5,nBinANmax);
   
     TH1F *h_Ndata18binEC=new TH1F("h_Ndata18binEC","h_Ndata18binEC",nBinAN,0.5,nBinANmax);



     TH1F *h_ZgammaR18bin=new TH1F("h_ZgammaR18bin","h_ZgammmaR18bin",nBinAN,0.5,nBinANmax);

     
     TH1F *h_ZgammaRWSF=new TH1F("h_ZgammaRWSF","h_ZgammmaRWSF",nBinAN,0.5,nBinANmax);

 
        


     int maxEvents_Zinv=tZinv->GetEntries();
     cout<<"maxEventsZinv: "<<maxEvents_Zinv<<endl;

     for(int iEv=0;iEv<maxEvents_Zinv;iEv++){//Looping over Zinv MC///////////////////////////////////////
     tZinv->GetEntry(iEv);
     if(iEv % 1000000==0){cout<<"Event no Zinv : "<<iEv<<endl;}
     
     int binNumber_Zinv = computeBin( Zinv.MHTclean, Zinv.HTclean, Zinv.NJetsclean, k13TeV);

     double weight=0;
     if(binNumber_Zinv >-1  && Zinv.BTagsclean==0){//Filling Yield(N_Obsereved) in Zinv
                     
         

          h_NZinv18bin->Fill(binNumber_Zinv,(Lumi*Zinv.Weight));      
          h_NZinv18binC->Fill(binNumber_Zinv,(Lumi*Zinv.Weight));


       }

     
     }//Lopping over Zinv MC//////////////////////////////////////////////////////////


      cout<<"Zinv Observed MC: "<<h_NZinv18bin->Integral()<<endl;
      cout<<"First bin: "<<h_NZinv18bin->GetBinContent(0)<<endl;

      for(int i=1;i<19;i++){
      cout<<"Zinv Bin Content: "<<h_NZinv18bin->GetBinContent(i)<<endl;
           }


     int maxEvents_GJets=tGJets->GetEntries();
     cout<<"maxEventsGJets: "<<maxEvents_GJets<<endl;
     for(int iEv=0;iEv<maxEvents_GJets;iEv++){//Looping over GJets MC///////////////////////////////////////
     tGJets->GetEntry(iEv);
     if(iEv % 1000000==0){cout<<"Event no GJets : "<<iEv<<endl;}
     
      

     int binNumber_GJets = computeBin( GJets.MHTclean, GJets.HTclean, GJets.NJetsclean, k13TeV);
     int index=GJets.photonIndex();
    

     if(binNumber_GJets >-1 && GJets.BTagsclean==0 && index !=-1 && GJets.photon_nonPrompt->at(index) !=1){//Filling Yield(N_Obsereved) in GJets MC
         
 
         hHT_GJets->Fill(GJets.HTclean,Lumi*GJets.Weight);
         hMHT_GJets->Fill(GJets.MHTclean,Lumi*GJets.Weight);
         hNJets_GJets->Fill(GJets.NJetsclean,Lumi*GJets.Weight);  
         h_NGJets18bin->Fill(binNumber_GJets,Lumi*GJets.Weight);
       


         if(fabs(GJets.bestPhoton->at(0).Eta())< 1.4442){//barrel
         hSieta_GJetsEB->Fill(GJets.photon_sigmaIetaIeta->at(index),Lumi*GJets.Weight);
         h_NGJets18binEB->Fill(binNumber_GJets,Lumi*GJets.Weight);
         hPhPt_GJetsEB->Fill(GJets.photonCands->at(index).Pt(),Lumi*GJets.Weight);
         ////////////////////////////////////Sieta in MHT bins
         if(GJets.MHTclean >MHTbin1Min && GJets.MHTclean< MHTbin1Max){
         hSieta_GJetsEBLow->Fill(GJets.photon_sigmaIetaIeta->at(index),Lumi*GJets.Weight);
             }


         if(GJets.MHTclean >MHTbin2Min && GJets.MHTclean< MHTbin2Max){
         hSieta_GJetsEBMed->Fill(GJets.photon_sigmaIetaIeta->at(index),Lumi*GJets.Weight);
             }


         if(GJets.MHTclean >MHTbin3Min && GJets.MHTclean< MHTbin3Max){
         hSieta_GJetsEBHigh->Fill(GJets.photon_sigmaIetaIeta->at(index),Lumi*GJets.Weight);
             }
          

         /////////////////////////Sieta in MHT bins




              }//barrel
         if(fabs(GJets.bestPhoton->at(0).Eta())> 1.566 && fabs(GJets.bestPhoton->at(0).Eta())< 2.5){//endcap
         hSieta_GJetsEC->Fill(GJets.photon_sigmaIetaIeta->at(index),Lumi*GJets.Weight);
         h_NGJets18binEC->Fill(binNumber_GJets,Lumi*GJets.Weight);
         hPhPt_GJetsEC->Fill(GJets.photonCands->at(index).Pt(),Lumi*GJets.Weight);


         ////////////////////////////////////Sieta in MHT bins
         if(GJets.MHTclean >MHTbin1Min && GJets.MHTclean< MHTbin1Max){
         hSieta_GJetsECLow->Fill(GJets.photon_sigmaIetaIeta->at(index),Lumi*GJets.Weight);
             }


         if(GJets.MHTclean >MHTbin2Min && GJets.MHTclean< MHTbin2Max){
         hSieta_GJetsECMed->Fill(GJets.photon_sigmaIetaIeta->at(index),Lumi*GJets.Weight);
             }


         if(GJets.MHTclean >MHTbin3Min && GJets.MHTclean< MHTbin3Max){
         hSieta_GJetsECHigh->Fill(GJets.photon_sigmaIetaIeta->at(index),Lumi*GJets.Weight);
             }
          

         /////////////////////////Sieta in MHT bins










             }//endcap





         }//Filling Yield(N_Obsereved) in GJets MC





     }//Looping over GJets MC//////////////////////////////////////////////////////////////////////////


     int maxEvents_QCD=tQCD->GetEntries();
     cout<<"maxEventsQCD: "<<maxEvents_QCD<<endl;
     for(int iEv=0;iEv<maxEvents_QCD;iEv++){//Looping over QCD MC
     tQCD->GetEntry(iEv);
     if(iEv % 1000000==0){cout<<"Event no QCD : "<<iEv<<endl;}
     int binNumber_QCD = computeBin( QCD.MHTclean, QCD.HTclean, QCD.NJetsclean, k13TeV);
     int index=QCD.photonIndex();
     if(binNumber_QCD >-1 && QCD.BTagsclean==0 && index !=-1 && QCD.photon_nonPrompt->at(index) ==1 ){//Filling Yield(N_Obsereved) in QCD MC
         
         hHT_QCD->Fill(QCD.HTclean,Lumi*QCD.Weight);
         hMHT_QCD->Fill(QCD.MHTclean,Lumi*QCD.Weight);
         hNJets_QCD->Fill(QCD.NJetsclean,Lumi*QCD.Weight);
         


         if(fabs(QCD.bestPhoton->at(0).Eta())< 1.4442){//barrel
         hSieta_QCDEB->Fill(QCD.photon_sigmaIetaIeta->at(index),Lumi*QCD.Weight);
         h_NQCD18binEB->Fill(binNumber_QCD,Lumi*QCD.Weight);
         hPhPt_QCDEB->Fill(QCD.photonCands->at(index).Pt(),Lumi*QCD.Weight);


         ////////////////////////////////////Sieta in MHT bins
         if(QCD.MHTclean >MHTbin1Min && QCD.MHTclean< MHTbin1Max){
         hSieta_QCDEBLow->Fill(QCD.photon_sigmaIetaIeta->at(index),Lumi*QCD.Weight);
             }


         if(QCD.MHTclean >MHTbin2Min && QCD.MHTclean< MHTbin2Max){
         hSieta_QCDEBMed->Fill(QCD.photon_sigmaIetaIeta->at(index),Lumi*QCD.Weight);
             }


         if(QCD.MHTclean >MHTbin3Min && QCD.MHTclean< MHTbin3Max){
         hSieta_QCDEBHigh->Fill(QCD.photon_sigmaIetaIeta->at(index),Lumi*QCD.Weight);
             }
          

         /////////////////////////Sieta in MHT bins











              }//barrel
         if(fabs(QCD.bestPhoton->at(0).Eta())> 1.566 && abs(QCD.bestPhoton->at(0).Eta()) <2.5 ){//endcap
         hSieta_QCDEC->Fill(QCD.photon_sigmaIetaIeta->at(index),Lumi*QCD.Weight);
         h_NQCD18binEC->Fill(binNumber_QCD,Lumi*QCD.Weight);
         hPhPt_QCDEC->Fill(QCD.photonCands->at(index).Pt(),Lumi*QCD.Weight);
             }//endcap


         ////////////////////////////////////Sieta in MHT bins
         if(QCD.MHTclean >MHTbin1Min && QCD.MHTclean< MHTbin1Max){
         hSieta_QCDECLow->Fill(QCD.photon_sigmaIetaIeta->at(index),Lumi*QCD.Weight);
             }


         if(QCD.MHTclean >MHTbin2Min && QCD.MHTclean< MHTbin2Max){
         hSieta_QCDECMed->Fill(QCD.photon_sigmaIetaIeta->at(index),Lumi*QCD.Weight);
             }


         if(QCD.MHTclean >MHTbin3Min && QCD.MHTclean< MHTbin3Max){
         hSieta_QCDECHigh->Fill(QCD.photon_sigmaIetaIeta->at(index),Lumi*QCD.Weight);
             }
          

         /////////////////////////Sieta in MHT bins





         }//Filling Yield(N_Obsereved) in QCD MC




     }//Looping over QCD MC
 

     

     int maxEvents_Data=tData->GetEntries();
     //cout<<"maxEvents in Single Photon Data: "<<maxEvents_Data<<endl;
     for(int iEv=0;iEv<maxEvents_Data;iEv++){//Data
     tData->GetEntry(iEv);
     if(iEv % 1000000==0){cout<<"Event no Data : "<<iEv<<endl;}
     
      //cout<<"Event no: "<<iEv<<endl;
     int binNumber_Data = computeBin( Data.MHTclean, Data.HTclean, Data.NJetsclean, k13TeV);
     int index=Data.photonIndex();

     if(binNumber_Data >-1 && Data.BTagsclean==0 && index !=-1){//Filling Yield(N_Obsereved) in Data
            bool PassTrigger=false;
          
         for(int itr=0;itr<Data.TriggerNames->size();itr++){
             //cout<<"trigger size: "<<Data.TriggerNames->at(itr)<<endl;
             if(Data.TriggerNames->at(itr)=="HLT_Photon90_CaloIdL_PFHT500_v3" && Data.TriggerPass->at(itr)==1){
                PassTrigger=true;


               }

              }


         

         if(PassTrigger==true){//trigger pass
         
         hHT_Data->Fill(Data.HTclean);
         hMHT_Data->Fill(Data.MHTclean);
         hNJets_Data->Fill(Data.NJetsclean);



         if(fabs(Data.bestPhoton->at(0).Eta())< 1.4442){//barrel
         

         h_Ndata18binEB->Fill(binNumber_Data);
         hSieta_DataEB->Fill(Data.photon_sigmaIetaIeta->at(index));
         hPhPt_DataEB->Fill(Data.photonCands->at(index).Pt());


         ////////////////////////////////////Sieta in MHT bins
         if(Data.MHTclean >MHTbin1Min && Data.MHTclean< MHTbin1Max){
         hSieta_DataEBLow->Fill(Data.photon_sigmaIetaIeta->at(index));
             }


         if(Data.MHTclean >MHTbin2Min && Data.MHTclean< MHTbin2Max){
         hSieta_DataEBMed->Fill(Data.photon_sigmaIetaIeta->at(index));
             }


         if(Data.MHTclean >MHTbin3Min && Data.MHTclean< MHTbin3Max){
         hSieta_DataEBHigh->Fill(Data.photon_sigmaIetaIeta->at(index));
             }
          

         /////////////////////////Sieta in MHT bins










              }//barrel
         if(fabs(Data.bestPhoton->at(0).Eta())> 1.566 && fabs(Data.bestPhoton->at(0).Eta())< 2.5 ){//endcap
         h_Ndata18binEC->Fill(binNumber_Data);
         hSieta_DataEC->Fill(Data.photon_sigmaIetaIeta->at(index));
         hPhPt_DataEC->Fill(Data.photonCands->at(index).Pt());


         ////////////////////////////////////Sieta in MHT bins
         if(Data.MHTclean >MHTbin1Min && Data.MHTclean< MHTbin1Max){
         hSieta_DataECLow->Fill(Data.photon_sigmaIetaIeta->at(index));
             }


         if(Data.MHTclean >MHTbin2Min && Data.MHTclean< MHTbin2Max){
         hSieta_DataECMed->Fill(Data.photon_sigmaIetaIeta->at(index));
             }


         if(Data.MHTclean >MHTbin3Min && Data.MHTclean< MHTbin3Max){
         hSieta_DataECHigh->Fill(Data.photon_sigmaIetaIeta->at(index));
             }
          

         /////////////////////////Sieta in MHT bins










             }//endcap
             

         
         }//trigger pass 

         }//Filling Yield(N_Obsereved) in Data




     

     }//Data 


     //trigger efficiency
     



     ///////////////////////////defining legend
    char Legname1[100];
    TLegend *leg[24];
    for(int k0=0;k0<24;k0++){
    sprintf(Legname1,"leg_1D%i",k0);
    leg[k0]=new TLegend(0.5,0.7,0.80,0.89);
    leg[k0]->SetTextFont(62);
    leg[k0]->SetLineColor(1);
    leg[k0]->SetLineStyle(1);
    leg[k0]->SetLineWidth(3);
    leg[k0]->SetFillColor(0);
    leg[k0]->SetFillStyle(1001);
    leg[k0]->SetShadowColor(0);
    leg[k0]->SetDrawOption(0);
    leg[k0]->SetBorderSize(0);
    leg[k0]->SetTextSize(0.03);
    }


     ///////////////////////////////ZinvMC Yield

     //TCanvas *ZinvMCYield=new TCanvas("ZinvMC","ZinvMC");
     //ZinvMCYield->SetLogy();
     h_NZinv18bin->Sumw2();
     h_NZinv18bin->SetFillColor(1);
     h_NZinv18bin->SetFillStyle(1000);
     h_NZinv18bin->GetXaxis()->SetTitle("bin Number");
     h_NZinv18bin->GetYaxis()->SetTitle("Z/Gamma Ratio");
     //h_NZinv18bin->Draw("hist");

   //////////////////////////////////////////////Calculating Zgamma Ratio start
      TPaveText *tpav1 = new TPaveText(0.1956522,0.6247818,0.729097,0.8970332,"brNDC");

    tpav1->SetBorderSize(0);
    tpav1->SetFillStyle(0);
    tpav1->SetTextAlign(11);
    tpav1->SetTextFont(42);
    tpav1->SetTextSize(0.04);
    tpav1->AddText("HT >500");
    tpav1->AddText("#gamma p_{T} > 100 ");
    tpav1->AddText("NJets >=4");
    tpav1->AddText("MHT>200");
    tpav1->AddText("Btags=0");
    tpav1->AddText("#Delta #Phi_{1,2,3,4}>(0.5,0.5,0.3,0.3)");

    TPaveText *pCMS1 = new TPaveText(0.132107,0.9308003,0.8327759,0.9923583,"brNDC");

    pCMS1->SetBorderSize(0);
    pCMS1->SetFillStyle(0);
    pCMS1->SetTextAlign(11);
    pCMS1->SetTextFont(42);
    pCMS1->SetTextSize(0.04);
    pCMS1->AddText("CMS #it{Preliminary}                      #sqrt{s}= 13 TeV");

    
    
     TCanvas *cZgammaR=new TCanvas("cZGammaR","cZGammaR");
     TH1F *h_ZgR = (TH1F*)h_NZinv18bin->Clone("h_ZgR");

     h_ZgR->Divide(h_NGJets18bin);


     cZgammaR->cd();
     h_ZgR->Draw("E2");
     tpav1->Draw();
     pCMS1->Draw();
    
     cZgammaR->SaveAs("ZgammaRatioWOSF.png");
     cZgammaR->SaveAs("ZgammaRatioWOSF.pdf");
     cZgammaR->SaveAs("ZgammaRatioWOSF.gif");
     
     ///////////////////////////////////Calculating ZGamma ratio end




     
    /////////////////////////////////////////////////////Dealing with Data barrel

   



     TH1F *h_DataSimEB = (TH1F*)h_Ndata18binEB->Clone("h_DataSimEB");
     
     TH1F *h_DataSimEC = (TH1F*)h_Ndata18binEC->Clone("h_DataSimEC");
   

     TH1F *h_DataSimEBforErr = (TH1F*)h_NGJets18binEB->Clone("h_DataSimEBforErr");
     
     TH1F *h_DataSimECforErr = (TH1F*)h_NGJets18binEB->Clone("h_DataSimECforErr");
     
     h_DataSimEBforErr->Scale((1/h_DataSimEBforErr->Integral())*h_Ndata18binEB->Integral());
     h_DataSimECforErr->Scale((1/h_DataSimECforErr->Integral())*h_Ndata18binEC->Integral());
     
     /////////////////////Fill the empty bins with simulated data
        
     for(int i=1;i<(nBinAN+1);i++){//loop over bins

        h_DataSimEB->SetBinError(i,0.);
        h_DataSimEC->SetBinError(i,0.);

        


        }//loop over bins 
        


     

     TH1F *hEBPurity=new TH1F("hEBPurity","hEBPurity",nBinAN,0.5,nBinANmax);
     TH1F *hECPurity=new TH1F("hECPurity","hECPurity",nBinAN,0.5,nBinANmax);
     
     TH1F *hEBfrag=new TH1F("hEBfrag","hEBfrag",nBinAN,0.5,nBinANmax);
     TH1F *hECfrag=new TH1F("hECfrag","hECfrag",nBinAN,0.5,nBinANmax);    
                         //uncorel      //corel
     double ebpErr=sqrt((0.009*0.009)+(0.03*0.03));
     double ecpErr=sqrt((0.016*0.016)+(0.046*0.046));

     double ebpErrCorel=0.03;
     double ebpErrUnCorel=0.009;

     double ecpErrCorel=0.046;
     double ecpErrUnCorel=0.016;


     for(int i=1;i<(nBinAN+1);i++){//set purity stuff
          hEBPurity->SetBinContent(i,0.967);
          hEBPurity->SetBinError(i,ebpErr);
          hECPurity->SetBinContent(i,0.956);
          hECPurity->SetBinError(i,ecpErr);
          
          hEBfrag->SetBinContent(i,0.92);
          hEBfrag->SetBinError(i,0.04);
          hECfrag->SetBinContent(i,0.92);
          hECfrag->SetBinError(i,0.04);


         }//set purity stuff     


    

    const Int_t NumBins= nBinAN;
    double binNumber[nBinAN];
    double YieldEstimated[nBinAN];
    double YieldErrUp_Estimated[nBinAN];
    double YieldErrLow_Estimated[nBinAN];

    double YieldPredMC[nBinAN];
    double YieldErrUp_PredMC[nBinAN];
    double YieldErrLow_PredMC[nBinAN];

    double XErrLow[nBinAN];
    double XErrUp[nBinAN];


    double ZgRwSF[nBinAN];
    double ZgRwSF_sys_ErrUp[nBinAN];
    double ZgRwSF_sys_ErrLow[nBinAN];
    double ZgRwSF_stat_Err[nBinAN];



    for(int ibin=1;ibin<(nBinAN+1);ibin++){//loop over bin error calculation


       double SF=0.98;
       double SFup=1.03;
       double SFlow=0.93;
       double ZgRcentral=h_ZgR->GetBinContent(ibin)/0.98;
       double ZgRup=h_ZgR->GetBinContent(ibin)/1.03;
       double ZgRlow=h_ZgR->GetBinContent(ibin)/0.93;

       double ZgRcorelErrup=fabs(ZgRcentral-ZgRlow);
       double ZgRcorelErrlow=fabs(ZgRcentral-ZgRup);

       double ZgRsymErr=0.5*(sqrt((ZgRcorelErrup*ZgRcorelErrup)+(ZgRcorelErrlow*ZgRcorelErrlow)));
       double ZgRcorel_Rel_Errup=ZgRcorelErrup/ZgRcentral;
       double ZgRcorel_Rel_Errlow=ZgRcorelErrlow/ZgRcentral;

       

       //double ZgRcorelErr=sqrt((ZgRcorelErrup*ZgRcorelErrup)+(ZgRcorelErrlow*ZgRcorelErrlow));

       double ZgRuncorelErr=h_ZgR->GetBinError(ibin)/SF;

       double ZgRuncorel_Rel_Err=ZgRuncorelErr/ZgRcentral;
   
       double ZgRsymErrStat=h_ZgR->GetBinError(ibin)/SF;//h_ZgR->GetBinError(ibin);
       
       double ZgRallSymErr=sqrt((ZgRsymErr*ZgRsymErr)+(ZgRsymErrStat*ZgRsymErrStat));

       

       
       //important lines to be changed
       double ZgR=ZgRcentral;
       
       double ZgRerr=ZgRallSymErr;
   
       double ZgRerrUp=sqrt((ZgRcorelErrup*ZgRcorelErrup)+(ZgRuncorelErr*ZgRuncorelErr));
       double ZgRerrLow=sqrt((ZgRcorelErrlow*ZgRcorelErrlow)+(ZgRuncorelErr*ZgRuncorelErr));
     

       ////////////////////////////////////barrel starts
       int EBobs=h_DataSimEB->GetBinContent(ibin);
       double EBobsErr=h_DataSimEB->GetBinError(ibin);     

       double pEB=hEBPurity->GetBinContent(ibin);
       double pEBerr=hEBPurity->GetBinError(ibin);
       double pEB_Rel_err=pEBerr/pEB;


       int ECobs=h_DataSimEC->GetBinContent(ibin);
       double ECobsErr=h_DataSimEC->GetBinError(ibin);

       double pEC=hECPurity->GetBinContent(ibin);
       double pECerr=hECPurity->GetBinError(ibin);       
       double pEC_Rel_err=pECerr/pEC;

       double f=0.92;
       double ferr=0.04;
       double f_Rel_err=ferr/f;

       double YieldTotal=ZgR*(EBobs*pEB+ECobs*pEC)*f;
       double YieldTotalErr=0;
       double YieldTotal_Rel_Err=0;

       double YieldTotalErrUp=0;
       double YieldTotal_Rel_ErrUp=0;

       double YieldTotalErrLow=0;
       double YieldTotal_Rel_ErrLow=0;


       int Nobserved=EBobs+ECobs;

       
       double totalPurity=0;
       double totalPurityErr=0;
       double totalPurity_Rel_Err=0;
       
       double ZinvMCYield=h_NZinv18binC->GetBinContent(ibin);
       double ZinvMCYieldErr=h_NZinv18binC->GetBinError(ibin);
       double ZinvMCYield_Rel_Err=ZinvMCYieldErr/ZinvMCYield;


       if(Nobserved !=0){
          totalPurity=((EBobs*pEB+ECobs*pEC)*f)/Nobserved;
          double totalPurityErr1=(EBobs*pEBerr+ECobs*pECerr)/Nobserved;
          double totalPurityErr2=ferr;
          totalPurityErr=sqrt((totalPurityErr1*totalPurityErr1)+(totalPurityErr2*totalPurityErr2));
          totalPurity_Rel_Err=totalPurityErr/totalPurity;


          YieldTotalErr=Nobserved*(sqrt((ZgR*ZgR*totalPurityErr*totalPurityErr)+(totalPurity*totalPurity*ZgRerr*ZgRerr)));

          YieldTotal_Rel_Err=YieldTotalErr/YieldTotal; 


          YieldTotalErrUp=Nobserved*(sqrt((ZgR*ZgR*totalPurityErr*totalPurityErr)+(totalPurity*totalPurity*ZgRerrUp*ZgRerrUp)));

          YieldTotal_Rel_ErrUp=YieldTotalErrUp/YieldTotal;
          

          YieldTotalErrLow=Nobserved*(sqrt((ZgR*ZgR*totalPurityErr*totalPurityErr)+(totalPurity*totalPurity*ZgRerrLow*ZgRerrLow)));

          YieldTotal_Rel_ErrLow=YieldTotalErrLow/YieldTotal;



           }
        if(Nobserved ==0){

          double NobservedNew=h_DataSimEBforErr->GetBinContent(ibin)+h_DataSimECforErr->GetBinContent(ibin);
          double EBobsNew=h_DataSimEBforErr->GetBinContent(ibin);
          double ECobsNew=h_DataSimECforErr->GetBinContent(ibin);
          totalPurity=((EBobsNew*pEB+ECobsNew*pEC)*f)/NobservedNew;
          
          double totalPurityErr1=(EBobsNew*pEBerr+ECobsNew*pECerr)/NobservedNew;
          double totalPurityErr2=ferr;
          totalPurityErr=sqrt((totalPurityErr1*totalPurityErr1)+(totalPurityErr2*totalPurityErr2));
          totalPurity_Rel_Err=totalPurityErr/totalPurity;

          YieldTotalErr=NobservedNew*(sqrt((ZgR*ZgR*totalPurityErr*totalPurityErr)+(totalPurity*totalPurity*ZgRerr*ZgRerr)));

          double YieldTotalNew=ZgR*(EBobsNew*pEB+ECobsNew*pEC)*f;

          YieldTotal_Rel_Err=YieldTotalErr/YieldTotalNew;


          YieldTotalErrUp=NobservedNew*(sqrt((ZgR*ZgR*totalPurityErr*totalPurityErr)+(totalPurity*totalPurity*ZgRerrUp*ZgRerrUp)));

          YieldTotal_Rel_ErrUp=YieldTotalErrUp/YieldTotalNew;
          

          YieldTotalErrLow=NobservedNew*(sqrt((ZgR*ZgR*totalPurityErr*totalPurityErr)+(totalPurity*totalPurity*ZgRerrLow*ZgRerrLow)));

          YieldTotal_Rel_ErrLow=YieldTotalErrLow/YieldTotalNew;







           }


        

          double YieldErrWithStat=0;
          double YieldErrWithStatUp=0;
          double YieldErrWithStatLow=0;
          double NobsErr=sqrt(Nobserved);
          YieldErrWithStat=sqrt((ZgR*totalPurity*NobsErr)*(ZgR*totalPurity*NobsErr) + (Nobserved*totalPurity*ZgRerr)*(Nobserved*totalPurity*ZgRerr) + (Nobserved*ZgR*totalPurityErr)*(Nobserved*ZgR*totalPurityErr));
         
          YieldErrWithStatUp=sqrt((ZgR*totalPurity*NobsErr)*(ZgR*totalPurity*NobsErr) + (Nobserved*totalPurity*ZgRerrUp)*(Nobserved*totalPurity*ZgRerrUp) + (Nobserved*ZgR*totalPurityErr)*(Nobserved*ZgR*totalPurityErr));
         

          YieldErrWithStatLow=sqrt((ZgR*totalPurity*NobsErr)*(ZgR*totalPurity*NobsErr) + (Nobserved*totalPurity*ZgRerrLow)*(Nobserved*totalPurity*ZgRerrLow) + (Nobserved*ZgR*totalPurityErr)*(Nobserved*ZgR*totalPurityErr));
      
      
     ZgRwSF[ibin-1]=ZgR;
     ZgRwSF_sys_ErrUp[ibin-1]=ZgRcorelErrup;
     ZgRwSF_sys_ErrLow[ibin-1]=ZgRcorelErrlow;
     ZgRwSF_stat_Err[ibin-1]=ZgRuncorelErr;




      
      
      binNumber[ibin-1]=ibin;
      YieldEstimated[ibin-1]=YieldTotal;
      YieldErrUp_Estimated[ibin-1]=YieldErrWithStatUp;
      YieldErrLow_Estimated[ibin-1]=YieldErrWithStatLow;
  
      YieldPredMC[ibin-1]=ZinvMCYield;
      YieldErrUp_PredMC[ibin-1]=ZinvMCYieldErr;
      YieldErrLow_PredMC[ibin-1]=ZinvMCYieldErr;
      XErrLow[ibin-1]=0.5;
      XErrUp[ibin-1]=0.5;    






printf(" %i :%i |%i| %4.3f(%4.3f) |%i| %4.3f(%4.3f) |%4.3f(%4.3f,+%4.3f-%4.3f)| %4.3f(%4.3f) |%4.3f(%4.3f)| %4.3f(+%4.3f-%4.3f) |%4.3f(%4.3f)",ibin,Nobserved, EBobs,pEB,pEB_Rel_err,ECobs,pEC,pEC_Rel_err, ZgR,ZgRuncorel_Rel_Err,ZgRcorel_Rel_Errup,ZgRcorel_Rel_Errlow,f,f_Rel_err,totalPurity,totalPurity_Rel_Err,YieldTotal,YieldTotal_Rel_ErrUp,YieldTotal_Rel_ErrLow,ZinvMCYield,ZinvMCYield_Rel_Err);
//printf("%4.3f",ZinvMCYield);

      //printf("bin %i :%i | %4.3f(%4.3f) | %4.3f(%4.3f)  | %4.2f(%4.3f) ",ibin,Nobserved,ZgR,ZgRerr,totalPurity,totalPurityErr,YieldTotal,YieldTotalErr);

   //printf("bin %i :%i | %4.3f(%4.3f,+%4.3f-%4.3f) | %4.3f(%4.3f)  | %4.2f(+%4.3f-%4.3f) ",ibin,Nobserved,ZgR,ZgRuncorel_Rel_Err,ZgRcorel_Rel_Errup,ZgRcorel_Rel_Errlow,totalPurity,totalPurity_Rel_Err,YieldTotal,YieldTotal_Rel_ErrUp,YieldTotal_Rel_ErrLow);

     cout<<endl;
     

      
      double Percent=(int)round(100*(YieldTotalErr/YieldTotal));

      
      double maxErrorYield=max(YieldErrWithStatUp,YieldErrWithStatLow);
      ZinvEstimate->SetBinContent(ibin,YieldTotal);
      ZinvEstimate->SetBinError(ibin,maxErrorYield);

       /////////////////endcap ends

        

       }//loop over bin error calculation



      ////////////////////////Pred vs Estimated



     TPaveText *tpa = new TPaveText(0.5056522,0.6247818,0.829097,0.8970332,"brNDC");

      tpa->SetBorderSize(0);
      tpa->SetFillStyle(0);
      tpa->SetTextAlign(11);
      tpa->SetTextFont(42);
      tpa->SetTextSize(0.04);
      tpa->AddText("HT >500");
      tpa->AddText("N_{jets} >=4");
      tpa->AddText("MHT>200");
      tpa->AddText("Btags=0");
      tpa->AddText("#Delta #Phi_{1,2,3,4}>(0.5,0.5,0.3,0.3)");



      TPaveText *pCMS = new TPaveText(0.132107,0.9308003,0.8327759,0.9923583,"brNDC");

      pCMS->SetBorderSize(0);
      pCMS->SetFillStyle(0);
      pCMS->SetTextAlign(11);
      pCMS->SetTextFont(42);
      pCMS->SetTextSize(0.04);
      pCMS->AddText("CMS #it{Preliminary}       1.3 fb^{-1} #sqrt{s}= 13 TeV");

      


       TLegend *legP = new TLegend(0.2173913,0.2478185,0.5167224,0.4363002,NULL,"brNDC");
      legP->SetBorderSize(0);
      legP->SetTextFont(62);
      legP->SetTextSize(0.03);
      legP->SetLineColor(1);
      legP->SetLineStyle(1);
      legP->SetLineWidth(3);
      legP->SetFillColor(0);
      legP->SetFillStyle(1001);

      cout<<"Est: "<<ZinvEstimate->Integral()<<endl;
      cout<<"Pred: "<<h_NZinv18binC->Integral()<<endl;

     
     //////////////////////////////////ZGammaRatio

     c_ZgRwSF = new TCanvas("c_ZgRwSF","c_ZgRwSF");
     c_ZgRwSF->cd();
     
     

     gr_ZgRwSFsys = new TGraphAsymmErrors(NumBins,binNumber,ZgRwSF,XErrLow,XErrUp,ZgRwSF_sys_ErrLow,ZgRwSF_sys_ErrUp);
     gr_ZgRwSFsys->SetTitle("ZgammaRatio");
     gr_ZgRwSFsys->SetMarkerColor(4);
     gr_ZgRwSFsys->SetLineColor(4);
     gr_ZgRwSFsys->SetMarkerStyle(21);

     gr_ZgRwSFstat = new TGraphAsymmErrors(NumBins,binNumber,ZgRwSF,XErrLow,XErrUp,ZgRwSF_stat_Err,ZgRwSF_stat_Err);
     gr_ZgRwSFstat->SetTitle("ZgammaRatio");
     gr_ZgRwSFstat->SetMarkerColor(2);
     gr_ZgRwSFstat->SetLineColor(2);
     gr_ZgRwSFstat->SetMarkerStyle(21);

     TLegend *legPZgR = new TLegend(0.2173913,0.7478185,0.5167224,0.8563002,NULL,"brNDC");
      legPZgR->SetBorderSize(0);
      legPZgR->SetTextFont(62);
      legPZgR->SetTextSize(0.03);
      legPZgR->SetLineColor(1);
      legPZgR->SetLineStyle(1);
      legPZgR->SetLineWidth(3);
      legPZgR->SetFillColor(0);
      legPZgR->SetFillStyle(1001);

      legPZgR->AddEntry(gr_ZgRwSFsys,"Sys Error","l");
      legPZgR->AddEntry(gr_ZgRwSFstat,"Stat Error","l");

     TMultiGraph *mgZgR=new TMultiGraph();
     mgZgR->SetTitle(" ;ith Bin ; Z/#gamma Ratio ");
     
     mgZgR->Add(gr_ZgRwSFstat);
     mgZgR->Add(gr_ZgRwSFsys);

     mgZgR->Draw("AP");
     tpa->Draw();
     pCMS->Draw();
     legPZgR->Draw();

     c_ZgRwSF->SaveAs("ZGammaRatioWSF.png");
     c_ZgRwSF->SaveAs("ZGammaRatioWSF.pdf");
     c_ZgRwSF->SaveAs("ZGammaRatioWSF.gif");



     ///////////////////////////////ZGammaRatio







     cPredVsEstimated = new TCanvas("estvspred","estvspred");
     
       TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
       pad1->SetBottomMargin(0); // Upperand lower plot are joined
       pad1->Draw();             // Draw the upper pad: pad1
       gPad->Update();
       pad1->cd();               // pad1 becomes the current pad
       gPad->DrawFrame(0.5, 0.01, 18.5, 2000, "PredVsEst;ith Bin;Events");
       gPad->SetLogy();
     
     gr_estimated = new TGraphAsymmErrors(NumBins,binNumber,YieldEstimated,XErrLow,XErrUp,YieldErrLow_Estimated,YieldErrUp_Estimated);
     gr_estimated->SetTitle("Estimated");
     gr_estimated->SetMarkerColor(4);
     gr_estimated->SetLineColor(4);
     gr_estimated->SetMarkerStyle(21);
     

     gr_mcPred = new TGraphAsymmErrors(NumBins,binNumber,YieldPredMC,XErrLow,XErrUp,YieldErrLow_PredMC,YieldErrUp_PredMC);
     gr_mcPred->SetTitle("MC predicted");
     gr_mcPred->SetMarkerColor(2);
     gr_mcPred->SetLineColor(2);
     gr_mcPred->SetMarkerStyle(8);


      legP->AddEntry(gr_mcPred,"Zinv MC Pred ","P");
      
      legP->AddEntry(gr_estimated,"Estimated(from #gamma +Jets)","P");

    


     char TMgname1[100];
     TMultiGraph *TMg_1D[2];
     for(int k0=0;k0<2;k0++){
     sprintf(TMgname1,"TMg_1D%i",k0);
     TMg_1D[k0]=new TMultiGraph();
      }
     for(int j0=0;j0<2;j0++){
     TMg_1D[j0]->SetMinimum(0.01);
     TMg_1D[j0]->SetMaximum(2000);
      }
      
    TMg_1D[0]->SetTitle(" ;ith Bin ; Events ");

    TMg_1D[0]->Add(gr_mcPred);
    TMg_1D[0]->Add(gr_estimated);


    
    TMg_1D[0]->Draw("AP");
    TMg_1D[0]->GetXaxis()->SetLimits(0.5,18.5); 
   
    tpa->Draw();
    pCMS->Draw();
    legP->Draw();


   TGaxis *axis = new TGaxis( -5, 20, -5, 220, 20,220,510,"");
       axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
       axis->SetLabelSize(15);
       axis->Draw();



  cPredVsEstimated->cd();

      TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
      pad2->SetTopMargin(0);
      pad2->SetBottomMargin(0.2);
      pad2->SetGridy(); // vertical grid
      pad2->Draw();
      pad2->cd();       // pad2 becomes the current pad


   TH1F *h3 = (TH1F*)h_NZinv18binC->Clone("h3");
   h3->SetLineColor(kBlack);
   h3->SetMinimum(-1);  // Define Y ..
   h3->SetMaximum(3); // .. range
   h3->Sumw2();
   h3->SetStats(0);      // No statistics on lower plot
   h3->Divide(ZinvEstimate);
   h3->SetMarkerStyle(21);
   h3->SetMarkerColor(1);
   h3->Draw("ep");       // Draw the r
   h3->GetXaxis()->SetTitle("ith Bin"); // Remove the ratio title

   // Y axis ratio plot settings
   h3->GetYaxis()->SetTitle("Pred/Est");
   h3->GetYaxis()->SetNdivisions(505);

   h3->GetYaxis()->SetTitleSize(20);
   h3->GetYaxis()->SetTitleFont(43);
   h3->GetYaxis()->SetTitleOffset(1.55);
   h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetYaxis()->SetLabelSize(15);

   // X axis ratio plot settings
   h3->GetXaxis()->SetTitleSize(20);
   h3->GetXaxis()->SetTitleFont(43);
   h3->GetXaxis()->SetTitleOffset(3.);
   h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetXaxis()->SetLabelSize(15);


     cPredVsEstimated->SaveAs("PredVsEstimated.png");
     cPredVsEstimated->SaveAs("PredVsEstimated.gif");
     cPredVsEstimated->SaveAs("ZPredVsEstimated.pdf");



   

     
      
      
      






    /////////////////////////////Fill the empty bins with simulated data
     


       TCanvas *c[20];
   int a;

  double promptfrac=hSieta_GJetsEB->Integral()/(hSieta_GJetsEB->Integral()+hSieta_QCDEB->Integral());

  cout<<"prompt fraction: "<<promptfrac<<endl;

  

   plot.plotHist(hHT_Data,hHT_GJets,hHT_QCD,c[0],"","Data","MC","HT");
   cin>>a;
   plot.plotHist(hMHT_Data,hMHT_GJets,hMHT_QCD,c[1],"","Data","MC","MHT");
   cin>>a;
   plot.plotHist(hNJets_Data,hNJets_GJets,hNJets_QCD,c[2],"","Data","MC","Njets");
   cin>>a;
   plot.plotHist(hSieta_DataEB,hSieta_GJetsEB,hSieta_QCDEB,c[3],"EB","Data","MC","SigmaIetaIeta_EB");
   cin>>a;
   plot.plotHist(hSieta_DataEBLow,hSieta_GJetsEBLow,hSieta_QCDEBLow,c[4],"Low-MHT-EB","Data","MC","SigmaIetaIeta_EB");
   cin>>a;
   plot.plotHist(hSieta_DataEBMed,hSieta_GJetsEBMed,hSieta_QCDEBMed,c[5],"Med-MHT-EB","Data","MC","SigmaIetaIeta_EB");
   cin>>a;
   plot.plotHist(hSieta_DataEBHigh,hSieta_GJetsEBHigh,hSieta_QCDEBHigh,c[6],"High-MHT-EB","Data","MC","SigmaIetaIeta_EB");
   cin>>a;

   plot.plotHist(hSieta_DataEC,hSieta_GJetsEC,hSieta_QCDEC,c[7],"EE","Data","MC","SigmaIetaIeta_EE");
   cin>>a;
   plot.plotHist(hSieta_DataECLow,hSieta_GJetsECLow,hSieta_QCDECLow,c[8],"Low-MHT-EE","Data","MC","SigmaIetaIeta_EE");
   cin>>a;
   plot.plotHist(hSieta_DataECMed,hSieta_GJetsECMed,hSieta_QCDECMed,c[9],"Med-MHT-EE","Data","MC","SigmaIetaIeta_EE");
   cin>>a;
   plot.plotHist(hSieta_DataECHigh,hSieta_GJetsECHigh,hSieta_QCDECHigh,c[10],"High-MHT-EE","Data","MC","SigmaIetaIeta_EE");   


   cin>>a;
   
   plot.plotHist(hPhPt_DataEB,hPhPt_GJetsEB,hPhPt_QCDEB,c[11],"EB","Data","MC","PhotonPt_EB");

   cin>>a;

   plot.plotHist(hPhPt_DataEC,hPhPt_GJetsEC,hPhPt_QCDEC,c[12],"EE","Data","MC","PhotonPt_EE");

   cin>>a;

   plot.plotHist(h_Ndata18binEB,h_NGJets18binEB,h_NQCD18binEB,c[13],"EB","Data","MC","ith-Bin-EB");
   cin>>a;
   plot.plotHist(h_Ndata18binEC,h_NGJets18binEC,h_NQCD18binEC,c[14],"EE","Data","MC","ith-Bin-EE");



  
  

     
   







}//main programme
