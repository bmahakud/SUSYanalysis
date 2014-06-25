#include<iostream>
#include "TH1.h"
#include "TGraph.h"
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"

#include <vector>
using namespace std;

void newROC(){

class ROCplotter {

private:

  TTree* SIGtree, *BKGtree1, *BKGtree2;
  vector<TString> branchName;
  vector<int> bins;
  vector<double> start;
  vector<double> end;
  
  vector<int> lineColor;
  vector<int> lineStyle;
  vector<int> lineWidth;


  vector<TGraph*> ROC;

public:

  vector<TH1F*> SIGhisto;
  vector<TH1F*> BKGhisto1;
  vector<TH1F*> BKGhisto2;
  
  ROCplotter(TString sigFileName, 
	     TString bkgFileName1,
             TString bkgFileName2,
	     TString sigTreeName="SelectedTree", 
	     TString bkgTreeName1="SelectedTree",
             TString bkgTreeName2="SelectedTree"
	     ){

    TFile* sigFile = new TFile(sigFileName);
    SIGtree = (TTree*) sigFile->Get(sigTreeName);
    
    TFile* bkgFile1 = new TFile(bkgFileName1);
    BKGtree1 = (TTree*) bkgFile1->Get(bkgTreeName1);

    TFile* bkgFile2 = new TFile(bkgFileName2);
    BKGtree2 = (TTree*) bkgFile2->Get(bkgTreeName2);



  }

  ROCplotter(TTree* sigTree, 
	     TTree* bkgTree1,
             TTree* bkgTree2 ){

    SIGtree = sigTree;
    BKGtree1 = bkgTree1;
    BKGtree2 = bkgTree2;


  }


  ~ROCplotter(){

    delete SIGtree;
    delete BKGtree1;
    delete BKGtree2;    


    for( int i = 0 ; i < SIGhisto.size() ; i++ ){

      delete SIGhisto[i];
      delete BKGhisto1[i];
      delete BKGhisto2[i];
      
      delete ROC[i];

    }

  }

  TGraph* make(TString branchName_="ZZpseudoLD",
	       const int bins_=30, double start_=0., double end_=1.,
	       int lineColor_=1, int lineStyle_=1, int lineWidth_=2,
	       TString cutString=""
	       ){

    branchName.push_back(branchName_);
    bins.push_back      (bins_      );
    start.push_back     (start_     ); 
    end.push_back       (end_       );
    lineColor.push_back (lineColor_ );
    lineStyle.push_back (lineStyle_ );
    lineWidth.push_back (lineWidth_ );


    char drawString[150];
    
    sprintf(drawString,"%s>>SIGhisto(%i,%f,%f)",branchName_.Data(),bins_,start_,end_);
    SIGtree->Draw(drawString,cutString);
    
    sprintf(drawString,"%s>>BKGhisto1(%i,%f,%f)",branchName_.Data(),bins_,start_,end_);
    BKGtree1->Draw(drawString,cutString);

    sprintf(drawString,"%s>>BKGhisto2(%i,%f,%f)",branchName_.Data(),bins_,start_,end_);
    BKGtree2->Draw(drawString,cutString);


    
    cout << "making histograms" << endl;

    TH1F* SIGhisto_ = (TH1F*) gDirectory->Get("SIGhisto");
    cout << SIGhisto_ << endl;
	
    SIGhisto_->Scale(1/SIGhisto_->Integral(0,SIGhisto_->GetNbinsX()+1));
  //  SIGhisto.push_back( SIGhisto_ );


    TH1F* BKGhisto1_ = (TH1F*) gDirectory->Get("BKGhisto1");

    TH1F* BKGhisto2_ = (TH1F*) gDirectory->Get("BKGhisto2");

    BKGhisto1_->Scale(0.316);
    BKGhisto2_->Scale(6.28);

    TH1F* BKGhisto_ =new TH1F(*BKGhisto1_);
    BKGhisto_->Add(BKGhisto2_);


    BKGhisto_->Scale(1/BKGhisto_->Integral(0,BKGhisto_->GetNbinsX()+1));
  //  BKGhisto.push_back( BKGhisto_ );

    SIGhisto_->Draw();
    BKGhisto_->Draw("SAME");

    cout << "calculating efficiencies" << endl;

    double effSIG[bins_],effBKG[bins_];

    for(int i=0; i<bins_; i++){

      effSIG[i] = SIGhisto_->Integral(i, bins_+1);
      effBKG[i] = BKGhisto_->Integral(i, bins_+1);

    }

    cout << "making ROC curve" << endl;
    
    TGraph* ROC_ = new TGraph(bins_,effSIG,effBKG) ;

    ROC_->SetLineColor(lineColor_);
    ROC_->SetLineStyle(lineStyle_);
    ROC_->SetLineWidth(lineWidth_);
    ROC_->GetXaxis()->SetTitle("#epsilon_{SIG}");
    ROC_->GetYaxis()->SetTitle("#epsilon_{BKG}");

    ROC.push_back(ROC_);

    return ROC_;
    
  }  
};


              TString sigFileNamepT10AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT10AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT10AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT10AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT10AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT10AK10_SumJetMass_AnalysisTree.root";
              
              TString sigFileNamepT10AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT10AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT10AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT10AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT10AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT10AK12_SumJetMass_AnalysisTree.root";

              TString sigFileNamepT10AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT10AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT10AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT10AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT10AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT10AK15_SumJetMass_AnalysisTree.root";




             TString sigFileNamepT20AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT20AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT20AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT20AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT20AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT20AK10_SumJetMass_AnalysisTree.root";

              TString sigFileNamepT20AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT20AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT20AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT20AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT20AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT20AK12_SumJetMass_AnalysisTree.root";

              TString sigFileNamepT20AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT20AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT20AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT20AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT20AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT20AK15_SumJetMass_AnalysisTree.root"; 




              TString sigFileNamepT30AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT30AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT30AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT30AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT30AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT30AK10_SumJetMass_AnalysisTree.root";

              TString sigFileNamepT30AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT30AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT30AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT30AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT30AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT30AK12_SumJetMass_AnalysisTree.root";

              TString sigFileNamepT30AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT30AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT30AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT30AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT30AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT30AK15_SumJetMass_AnalysisTree.root";



              TString sigFileNamepT40AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT40AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT40AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT40AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT40AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT40AK10_SumJetMass_AnalysisTree.root";

              TString sigFileNamepT40AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT40AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT40AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT40AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT40AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT40AK12_SumJetMass_AnalysisTree.root";

              TString sigFileNamepT40AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT40AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT40AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT40AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT40AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT40AK15_SumJetMass_AnalysisTree.root";


             
              TString sigFileNamepT50AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT50AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT50AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT50AK10_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT50AK10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT50AK10_SumJetMass_AnalysisTree.root";

              TString sigFileNamepT50AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT50AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT50AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT50AK12_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT50AK12 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT50AK12_SumJetMass_AnalysisTree.root";

              TString sigFileNamepT50AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT50AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName1pT50AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_500HT1000_LPCSUSYPAT_SLIMpT50AK15_SumJetMass_AnalysisTree.root";
              TString bkgFileName2pT50AK15 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT50AK15_SumJetMass_AnalysisTree.root";




              TFile* sigFilepT10AK10 = new TFile(sigFileNamepT10AK10);
              TFile* bkgFile1pT10AK10 = new TFile(bkgFileName1pT10AK10);
              TFile* bkgFile2pT10AK10 = new TFile(bkgFileName2pT10AK10);

              TFile* sigFilepT10AK12 = new TFile(sigFileNamepT10AK12);
              TFile* bkgFile1pT10AK12 = new TFile(bkgFileName1pT10AK12);
              TFile* bkgFile2pT10AK12 = new TFile(bkgFileName2pT10AK12);

              TFile* sigFilepT10AK15 = new TFile(sigFileNamepT10AK15);
              TFile* bkgFile1pT10AK15 = new TFile(bkgFileName1pT10AK15);
              TFile* bkgFile2pT10AK15 = new TFile(bkgFileName2pT10AK15);

   

            

             


               TFile* sigFilepT20AK10 = new TFile(sigFileNamepT20AK10);
              TFile* bkgFile1pT20AK10 = new TFile(bkgFileName1pT20AK10);
              TFile* bkgFile2pT20AK10 = new TFile(bkgFileName2pT20AK10);

              TFile* sigFilepT20AK12 = new TFile(sigFileNamepT20AK12);
              TFile* bkgFile1pT20AK12 = new TFile(bkgFileName1pT20AK12);
              TFile* bkgFile2pT20AK12 = new TFile(bkgFileName2pT20AK12);

              TFile* sigFilepT20AK15 = new TFile(sigFileNamepT20AK15);
              TFile* bkgFile1pT20AK15 = new TFile(bkgFileName1pT20AK15);
              TFile* bkgFile2pT20AK15 = new TFile(bkgFileName2pT20AK15);




              TFile* sigFilepT30AK10 = new TFile(sigFileNamepT30AK10);
              TFile* bkgFile1pT30AK10 = new TFile(bkgFileName1pT30AK10);
              TFile* bkgFile2pT30AK10 = new TFile(bkgFileName2pT30AK10);

              TFile* sigFilepT30AK12 = new TFile(sigFileNamepT30AK12);
              TFile* bkgFile1pT30AK12 = new TFile(bkgFileName1pT30AK12);
              TFile* bkgFile2pT30AK12 = new TFile(bkgFileName2pT30AK12);

              TFile* sigFilepT30AK15 = new TFile(sigFileNamepT30AK15);
              TFile* bkgFile1pT30AK15 = new TFile(bkgFileName1pT30AK15);
              TFile* bkgFile2pT30AK15 = new TFile(bkgFileName2pT30AK15);





              TFile* sigFilepT40AK10 = new TFile(sigFileNamepT40AK10);
              TFile* bkgFile1pT40AK10 = new TFile(bkgFileName1pT40AK10);
              TFile* bkgFile2pT40AK10 = new TFile(bkgFileName2pT40AK10);

              TFile* sigFilepT40AK12 = new TFile(sigFileNamepT40AK12);
              TFile* bkgFile1pT40AK12 = new TFile(bkgFileName1pT40AK12);
              TFile* bkgFile2pT40AK12 = new TFile(bkgFileName2pT40AK12);

              TFile* sigFilepT40AK15 = new TFile(sigFileNamepT40AK15);
              TFile* bkgFile1pT40AK15 = new TFile(bkgFileName1pT40AK15);
              TFile* bkgFile2pT40AK15 = new TFile(bkgFileName2pT40AK15);





              TFile* sigFilepT50AK10 = new TFile(sigFileNamepT50AK10);
              TFile* bkgFile1pT50AK10 = new TFile(bkgFileName1pT50AK10);
              TFile* bkgFile2pT50AK10 = new TFile(bkgFileName2pT50AK10);

              TFile* sigFilepT50AK12 = new TFile(sigFileNamepT50AK12);
              TFile* bkgFile1pT50AK12 = new TFile(bkgFileName1pT50AK12);
              TFile* bkgFile2pT50AK12 = new TFile(bkgFileName2pT50AK12);

              TFile* sigFilepT50AK15 = new TFile(sigFileNamepT50AK15);
              TFile* bkgFile1pT50AK15 = new TFile(bkgFileName1pT50AK15);
              TFile* bkgFile2pT50AK15 = new TFile(bkgFileName2pT50AK15);


              

              ROCplotter* myROCpT10AK10 = new ROCplotter((TTree*)sigFilepT10AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT10AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT10AK10->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT10AK12 = new ROCplotter((TTree*)sigFilepT10AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT10AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT10AK12->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT10AK15 = new ROCplotter((TTree*)sigFilepT10AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT10AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT10AK15->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT20AK10 = new ROCplotter((TTree*)sigFilepT20AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT20AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT20AK10->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT20AK12 = new ROCplotter((TTree*)sigFilepT20AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT20AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT20AK12->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT20AK15 = new ROCplotter((TTree*)sigFilepT20AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT20AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT20AK15->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT30AK10 = new ROCplotter((TTree*)sigFilepT30AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT30AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT30AK10->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT30AK12 = new ROCplotter((TTree*)sigFilepT30AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT30AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT30AK12->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT30AK15 = new ROCplotter((TTree*)sigFilepT30AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT30AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT30AK15->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT40AK10 = new ROCplotter((TTree*)sigFilepT40AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT40AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT40AK10->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT40AK12 = new ROCplotter((TTree*)sigFilepT40AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT40AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT40AK12->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT40AK15 = new ROCplotter((TTree*)sigFilepT40AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT40AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT40AK15->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT50AK10 = new ROCplotter((TTree*)sigFilepT50AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT50AK10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT50AK10->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT50AK12 = new ROCplotter((TTree*)sigFilepT50AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT50AK12->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT50AK12->Get("TreeFiller/AnalysisTree"));
              ROCplotter* myROCpT50AK15 = new ROCplotter((TTree*)sigFilepT50AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile1pT50AK15->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile2pT50AK15->Get("TreeFiller/AnalysisTree"));

              
              




           //pT > 10 GeV
                TGraph* sjmpT10AK10 = myROCpT10AK10->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT10AK10->SetLineColor(1);
                sjmpT10AK10->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT10AK10->GetYaxis()->SetTitle("#epsilon_{bkg}");                



                TGraph* sjmpT10AK12 = myROCpT10AK12->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");     
                sjmpT10AK12->SetLineColor(2);
                sjmpT10AK12->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT10AK12->GetYaxis()->SetTitle("#epsilon_{bkg}");
                sjmpT10AK12->SetLineStyle(8);               

                TGraph* sjmpT10AK15 = myROCpT10AK15->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT10AK15->SetLineColor(3);
                sjmpT10AK15->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT10AK15->GetYaxis()->SetTitle("#epsilon_{bkg}");
    
          //pT > 10 GeV

//////////////////////////////////////pt > 20 GeV
                    TGraph* sjmpT20AK10 = myROCpT20AK10->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT20AK10->SetLineColor(4);
                sjmpT20AK10->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT20AK10->GetYaxis()->SetTitle("#epsilon_{bkg}");



                TGraph* sjmpT20AK12 = myROCpT20AK12->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT20AK12->SetLineColor(5);
                sjmpT20AK12->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT20AK12->GetYaxis()->SetTitle("#epsilon_{bkg}");


                TGraph* sjmpT20AK15 = myROCpT20AK15->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT20AK15->SetLineColor(6);
                sjmpT20AK15->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT20AK15->GetYaxis()->SetTitle("#epsilon_{bkg}");
//////////////////////////////////////////pt > 20 GeV



                 TGraph* sjmpT30AK10 = myROCpT30AK10->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT30AK10->SetLineColor(7);
                sjmpT30AK10->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT30AK10->GetYaxis()->SetTitle("#epsilon_{bkg}");



                TGraph* sjmpT30AK12 = myROCpT30AK12->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT30AK12->SetLineColor(8);
                sjmpT30AK12->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT30AK12->GetYaxis()->SetTitle("#epsilon_{bkg}");


                TGraph* sjmpT30AK15 = myROCpT30AK15->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT30AK15->SetLineColor(8);
                sjmpT30AK15->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT30AK15->GetYaxis()->SetTitle("#epsilon_{bkg}");


  ////////////////////////////////////////////////////pt > 40


               TGraph* sjmpT40AK10 = myROCpT40AK10->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT40AK10->SetLineColor(8);
                sjmpT40AK10->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT40AK10->GetYaxis()->SetTitle("#epsilon_{bkg}");



                TGraph* sjmpT40AK12 = myROCpT40AK12->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT40AK12->SetLineColor(8);
                sjmpT40AK12->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT40AK12->GetYaxis()->SetTitle("#epsilon_{bkg}");


                TGraph* sjmpT40AK15 = myROCpT40AK15->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT40AK15->SetLineColor(8);
                sjmpT40AK15->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT40AK15->GetYaxis()->SetTitle("#epsilon_{bkg}");





/////////////////////////////////////////////////////pT > 40



                TGraph* sjmpT50AK10 = myROCpT50AK10->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT50AK10->SetLineColor(8);
                sjmpT50AK10->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT50AK10->GetYaxis()->SetTitle("#epsilon_{bkg}");



                TGraph* sjmpT50AK12 = myROCpT50AK12->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT50AK12->SetLineColor(8);
                sjmpT50AK12->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT50AK12->GetYaxis()->SetTitle("#epsilon_{bkg}");


                TGraph* sjmpT50AK15 = myROCpT50AK15->make("sumJetMass_fattenedJets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500");
                sjmpT50AK15->SetLineColor(8);
                sjmpT50AK15->GetXaxis()->SetTitle("#epsilon_{sig}");
                sjmpT50AK15->GetYaxis()->SetTitle("#epsilon_{bkg}");



                TGraph* ht = myROCpT50AK15->make("Ht_patJetsAK5PFPt50Eta25",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>1000");
                sjmpT50AK15->SetLineColor(9);       
                TGraph* sjmAK12 = myROCpT50AK15->make("sumJetMass_ak1p2Jets",500,0.,2500.,2,1,2,"Ht_patJetsAK5PFPt50Eta25>500"); 



              
















            TCanvas* can = new TCanvas("can","can",500,500);

  

//  ht->Draw("AC");
//  sjm10->Draw("AC");
//  sjm20->Draw("same");
//  sjm30->Draw("same");
//  sjm40->Draw("same");
//  sjm50->Draw("same");
  sjmpT10AK10->Draw("AC");
  sjmpT10AK12->Draw("same");
  sjmpT10AK15->Draw("same");
   
  sjmpT20AK10->Draw("same");
  sjmpT20AK12->Draw("same");
  sjmpT20AK15->Draw("same");

  sjmpT30AK10->Draw("same");
  ht->Draw("same");
/*  sjmpT30AK12->Draw("same");
  sjmpT30AK15->Draw("same");


  sjmpT40AK10->Draw("same");
  sjmpT40AK12->Draw("same");
  sjmpT40AK15->Draw("same"); 


  sjmpT50AK10->Draw("same");
  sjmpT50AK12->Draw("same");
  sjmpT50AK15->Draw("same");
*/



 

leg = new TLegend(0.6,0.7,0.89,0.89);


   leg->AddEntry(sjmpT10AK10,"SumJetMass_fattenedJetspT>10_AK10 ","lp");
   leg->AddEntry(sjmpT10AK12,"SumJetMass_fattenedJetspT>10_AK12 ","lp");
   leg->AddEntry(sjmpT10AK15,"SumJetMass_fattenedJetspT>10_AK15 ","lp");

   leg->AddEntry(sjmpT20AK10,"SumJetMass_fattenedJetspT>20_AK10 ","lp");
   leg->AddEntry(sjmpT20AK12,"SumJetMass_fattenedJetspT>20_AK12 ","lp");
   leg->AddEntry(sjmpT20AK15,"SumJetMass_fattenedJetspT>20_AK15 ","lp");

   leg->AddEntry(sjmpT30AK10,"SumJetMass_fattenedJetspT>30_AK10 ","lp");
/*   leg->AddEntry(sjmpT30AK12,"SumJetMass_fattenedJetspT>30_AK12 ","lp");
   leg->AddEntry(sjmpT30AK15,"SumJetMass_fattenedJetspT>30_AK15 ","lp");

   leg->AddEntry(sjmpT40AK10,"SumJetMass_fattenedJetspT>40_AK10 ","lp");
   leg->AddEntry(sjmpT40AK12,"SumJetMass_fattenedJetspT>40_AK12 ","lp");
   leg->AddEntry(sjmpT40AK15,"SumJetMass_fattenedJetspT>40_AK15 ","lp");

   leg->AddEntry(sjmpT50AK10,"SumJetMass_fattenedJetspT>50_AK10 ","lp");
   leg->AddEntry(sjmpT50AK12,"SumJetMass_fattenedJetspT>50_AK12 ","lp");
   leg->AddEntry(sjmpT50AK15,"SumJetMass_fattenedJetspT>50_AK15 ","lp");
 
*/











leg->Draw();





























}
