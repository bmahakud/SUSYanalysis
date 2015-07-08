#include<iostream>
#include"TH1F.h"
using namespace std;

void Teff(){



   TCanvas* c1 = new TCanvas("example1","",600,400);
   c1->SetFillStyle(1001);
   c1->SetFillColor(kWhite);

   TCanvas* c2 = new TCanvas("example2","",600,400);
   c2->SetFillStyle(1001);
   c2->SetFillColor(kWhite);


   TH1F *hp=new TH1F("hp","hp",100,0,10);

   TH1F *hT=new TH1F("hT","hT",1000,-10,10);



  
   TEfficiency* pEff1 = new TEfficiency("eff1","my efficiency1;x;#epsilon",10,0,10);

   TEfficiency* pEff2 = new TEfficiency("eff2","my efficiency2;y;#epsilon",10,0,10);

   TEfficiency* pEff3 = new TEfficiency("eff3","my efficiency3;z;#epsilon",10,0,10);



   TRandom3 rand3;
  
   TRandom2 rand2;

   bool bPassed1;
   bool bPassed2;
   double x,y,z;

   for(int i=0; i<10000; ++i)
   {
      
      x = rand3.Uniform(10);
      y = rand2.Uniform(10);


      
      bPassed1 = rand3.Rndm() < TMath::Gaus(x,5,4);
      bPassed2 = rand2.Rndm() < TMath::Gaus(y,2,3);

      cout<<"Bool = "<<bPassed1<<endl;

      pEff1->Fill(bPassed1,x);
      pEff2->Fill(bPassed2,y);


   }


pEff1->SetWeight(100);

pEff2->SetWeight(200);


pEff1->Add(pEff2);




   c1->cd();
   pEff1->Draw("AP");





}
