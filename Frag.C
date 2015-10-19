#define SimpleTree_cxx
#include "SimpleTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void SimpleTree::Loop()
{

   TH1F *hC=new TH1F("hC","hC",100,0,10);
   TH1F *hT=new TH1F("hT","hT",100,0,10);

//   In a ROOT session, you can do:
//      root> .L SimpleTree.C
//      root> SimpleTree t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   int NumBPhotons=0;
   int NumBgenPhotons=0;
   int NumBgenFragPhotons=0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      unsigned int num=1;

     if(bestPhotonE->size() >= 1){//best photon event
      NumBPhotons++;
      TLorentzVector BestPhoton;
      TLorentzVector BestGenPhoton;
      BestPhoton.SetPxPyPzE(bestPhotonPx->at(0),bestPhotonPy->at(0) ,bestPhotonPz->at(0) ,bestPhotonE->at(0) );
      for(int i=0;i<genPhotonPx->size();i++){//gen photon loop
    
       TLorentzVector GenPhoton;
       GenPhoton.SetPxPyPzE(genPhotonPx->at(i),genPhotonPy->at(i) ,genPhotonPz->at(i) ,genPhotonE->at(i) );              

       double deltaR=BestPhoton.DeltaR(GenPhoton);
       double PtRatio=GenPhoton.Pt()/BestPhoton.Pt();

       if(deltaR<0.1 && PtRatio >0.5 && PtRatio < 2. && GenPhoton.Pt() > 100. && (fabs(genPhotonMother->at(i)) <= 22 || fabs(genPhotonMother->at(i)) == 2212) ){//gen matched photon
          NumBgenPhotons++;
          //cout<<"Event "<<endl;
          BestGenPhoton.SetPxPyPzE(genPhotonPx->at(i),genPhotonPy->at(i) ,genPhotonPz->at(i) ,genPhotonE->at(i) );

          int passdelR=0;
          double minDelR=100;
          int Qposition=-1;
          TLorentzVector GenQuarkmin;

          
          for(int iq=0;iq<genQuarkE->size();iq++){//gen quark loop
                 
             TLorentzVector GenQuark;
             GenQuark.SetPxPyPzE(genQuarkPx->at(iq),genQuarkPy->at(iq) ,genQuarkPz->at(iq) ,genQuarkE->at(iq) );

             double delRQuarkPh=BestPhoton.DeltaR(GenQuark);//uncomment to bestGenPhoton
          
             cout<<"Event: "<<jentry<<" : "<<BestPhoton.Pt() <<"  "<<BestPhoton.Eta()<<"  "<<BestPhoton.Phi()<<" |  "<<BestGenPhoton.Pt() <<"  "<<BestGenPhoton.Eta()<<"  "<<BestGenPhoton.Phi() <<" | "<<GenQuark.Pt()<<"  "<<GenQuark.Eta()<<"  "<<GenQuark.Phi()<<endl;                    



                 if(delRQuarkPh<minDelR){

                      minDelR=delRQuarkPh;
                      Qposition=iq;
                      
                      GenQuarkmin.SetPxPyPzE(genQuarkPx->at(iq),genQuarkPy->at(iq) ,genQuarkPz->at(iq) ,genQuarkE->at(iq) );

                                         }

               

              if(delRQuarkPh<0.4){
                   passdelR=1;
                   }

               }//gen quark loop



               if(Qposition !=-1){

                  //scout<<"Event: "<<jentry<<" : "<<BestPhoton.Pt() <<"  "<<BestPhoton.Eta()<<"  "<<BestPhoton.Phi()<<" |  "<<BestGenPhoton.Pt() <<"  "<<BestGenPhoton.Eta()<<"  "<<BestGenPhoton.Phi() <<" | "<<GenQuarkmin.Pt()<<"  "<<GenQuarkmin.Eta()<<"  "<<GenQuarkmin.Phi()<<endl;


                    }





            hT->Fill(minDelR,evWeight);

            if(minDelR>0.4){
            hC->Fill(minDelR,evWeight);
                }
             if(passdelR == 0){NumBgenFragPhotons++;}

         



          }//gen matched  photon

     



 
            }

          }//best photon event











   }//event loop

cout<<"number of best photons:  "<<NumBPhotons<<endl;
cout<<"number of best gen photons:  "<<NumBgenPhotons<<endl;
cout<<"number of best gen Frag photons:  "<<NumBgenFragPhotons<<endl;


hT->GetXaxis()->SetTitle("DeltaRmin(quark,photon)");
hT->GetYaxis()->SetTitle("Events");

cout<<"PassIntegral:  "<<hC->Integral()<<endl;
cout<<"FullIntegral:  "<<hT->Integral()<<endl;
hT->Draw("hist");



}
