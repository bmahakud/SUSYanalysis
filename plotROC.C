void plotROC(//TString sigFileName = "/uscms_data/d2/awhitbe1/workArea/RA2studies/CMSSW_5_3_8_patch1/src/AWhitbeck/SuSySubstructure/test/T1tttt_mLSP-200_mGo-1000_condorSub/T1tttt_mG1000_mLSP200_LPCSUSYPAT_SumJetMass_AnalysisTree.root", 

              TString sigFileName = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATlowpT3_SumJetMass_AnalysisTree.root",


	     //TString bkgFileName = "QCD_condorSub/QCDsample_LPCSUSYPAT_ALL_SumJetMass_AnalysisTree.root"
	     // TString bkgFileName = "/eos/uscms/store/user/awhitbe1/RA2studies/CMSSW_5_3_8_patch1/src/AWhitbeck/SuSySubstructure/test/TTJet_SemiLept_condorSub/TTJets_SemiLept_LPCSUSYPAT_ALL_SumJetMass_AnalysisTree.root"
                TString bkgFileName = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT0_SumJetMass_AnalysisTree.root",

	     //TString bkgFileName = "WJetsToLNu_400HTinf_condorSub/WJetsToLNu_400HTinf_LPCSUSYPAT_ALL_SumJetMass_AnalysisTree.root"
	     //TString bkgFileName = "ZJetsToNuNu_400HTinf_condorSub/ZJetsToNuNu_400HTinf_LPCSUSYPAT_ALL_SumJetMass_AnalysisTree.root"

             TString sigFileName10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT10_SumJetMass_AnalysisTree.root",
             TString bkgFileName10 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT10_SumJetMass_AnalysisTree.root",

              TString sigFileName20 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT20_SumJetMass_AnalysisTree.root",
             TString bkgFileName20 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT20_SumJetMass_AnalysisTree.root",

              TString sigFileName30 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT30_SumJetMass_AnalysisTree.root",
             TString bkgFileName30 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT30_SumJetMass_AnalysisTree.root",


              TString sigFileName40 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT40_SumJetMass_AnalysisTree.root",
             TString bkgFileName40 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT40_SumJetMass_AnalysisTree.root",


             TString sigFileName50 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/SMS-T5tttt_mGo-800_mStop-250_mLSP_50_8TeV_LPCSUSYPATpT50_SumJetMass_AnalysisTree.root",
             TString bkgFileName50 = "/afs/cern.ch/user/b/bmahakud/work/SUSYfile/QCD_1000HTinf_LPCSUSYPAT_SLIMpT50_SumJetMass_AnalysisTree.root"

            












	     ){

//  gROOT->ProcessLine(".L tdrstyle.C");
//  setTDRStyle();

  gROOT->ProcessLine(".L rocCurve.C++");

  TFile* sigFile = new TFile(sigFileName);  
  TFile* bkgFile = new TFile(bkgFileName);

  TFile* sigFile10 = new TFile(sigFileName10);
  TFile* bkgFile10 = new TFile(bkgFileName10);

  TFile* sigFile20 = new TFile(sigFileName20);
  TFile* bkgFile20 = new TFile(bkgFileName20);

 TFile* sigFile30 = new TFile(sigFileName30);
  TFile* bkgFile30 = new TFile(bkgFileName30);

  TFile* sigFile40 = new TFile(sigFileName40);
  TFile* bkgFile40 = new TFile(bkgFileName40);

  TFile* sigFile50 = new TFile(sigFileName50);
  TFile* bkgFile50 = new TFile(bkgFileName50);




  ROCplotter* myROC = new ROCplotter((TTree*)sigFile->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile->Get("TreeFiller/AnalysisTree"));

  ROCplotter* myROC10 = new ROCplotter((TTree*)sigFile10->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile10->Get("TreeFiller/AnalysisTree"));

  ROCplotter* myROC20 = new ROCplotter((TTree*)sigFile20->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile20->Get("TreeFiller/AnalysisTree"));

  ROCplotter* myROC30 = new ROCplotter((TTree*)sigFile30->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile30->Get("TreeFiller/AnalysisTree"));

  ROCplotter* myROC40 = new ROCplotter((TTree*)sigFile40->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile40->Get("TreeFiller/AnalysisTree"));

  ROCplotter* myROC50 = new ROCplotter((TTree*)sigFile50->Get("TreeFiller/AnalysisTree"),(TTree*)bkgFile50->Get("TreeFiller/AnalysisTree"));
  
    






  TGraph* sjm = myROC.make("sumJetMass_ak1p2Jets",
			   500,0.,2500.,
			   2,1,2,
			   "Ht_patJetsAK5PF>1000");
sjm->SetLineColor(8);


TGraph* ht = myROC.make("Ht_patJetsAK5PF",
			  500,0.,2500.,
			  4,2,2,
			  "Ht_patJetsAK5PF>1000.");

TGraph* sjm10 = myROC10.make("sumJetMass_fattenedJets",
                         500,0.,2500.,
                         2,1,2,
                         "Ht_patJetsAK5PF>1000.");

TGraph* sjm20 = myROC20.make("sumJetMass_fattenedJets",
                         500,0.,2500.,
                         2,1,2,
                       "Ht_patJetsAK5PF>1000.");

sjm20->SetLineColor(3);




TGraph* sjm30 = myROC30.make("sumJetMass_fattenedJets",
                         500,0.,2500.,
                         2,1,2,
                         "Ht_patJetsAK5PFPt30>1000.");

sjm30->SetLineColor(4);


TGraph* sjm40 = myROC40.make("sumJetMass_fattenedJets",
                         500,0.,2500.,
                         2,1,2,
                         "Ht_patJetsAK5PFPt30>1000.");
sjm40->SetLineColor(5);

TGraph* sjm50 = myROC50.make("sumJetMass_fattenedJets",
                         500,0.,2500.,
                         2,1,2,
                         "Ht_patJetsAK5PFPt30>1000.");

sjm50->SetLineColor(6);

  TCanvas* can = new TCanvas("can","can",500,500);

  ht->GetXaxis()->SetTitle("#epsilon_{sig}");
  ht->GetYaxis()->SetTitle("#epsilon_{bkg}");

  ht->Draw("AC");
  sjm10->Draw("same");    
  sjm20->Draw("same");
  sjm30->Draw("same");
  sjm40->Draw("same");
  sjm50->Draw("same");
  sjm->Draw("same");


leg = new TLegend(0.6,0.7,0.89,0.89);


   leg->AddEntry(sjm10,"pT > 10 GeV ","lp");
   leg->AddEntry(sjm20,"pT > 20 GeV ","lp");
   leg->AddEntry(sjm30,"pT > 30 GeV ","lp"); 
   leg->AddEntry(sjm40,"pT > 40 GeV ","lp"); 
   leg->AddEntry(sjm50,"pT > 50 GeV ","lp");
   leg->AddEntry(ht,"Ht_patJetsAK5","lp");
   leg->AddEntry(sjm,"SumJet mass AK12 ","lp");

leg->Draw();






  
}
