#include "TTree.h"
#include <vector>
#include <iostream>
#include "effArea.cc"
#include "photon.cc"
#include "TLorentzVector.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TChain.h"
#include "TString.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;
void photonEffRhoCorr(std::string cutType="Medium"){//main programme

const char *cut_Type;

cut_Type = cutType.c_str();



if(cutType =="Loose"){
cout<<"Running with Loose cuts . . . "<<endl;

float HtoECut_EB=0.028;
float HtoECut_EC=0.093;
float SigmaIetaCut_EB=0.0107;
float SigmaIetaCut_EC=0.0272;
float ChIsoCut_EB=2.67;
float ChIsoCut_EC=1.79;


float NeoIsoCut_EB_A=7.23;
float NeoIsoCut_EB_B=0.0028;
float NeoIsoCut_EB_C=0.5408;
float NeoIsoCut_EC_A=8.89;
float NeoIsoCut_EC_B=0.01725;
float NeoIsoCut_EC_C=0;


float GammaIsoCut_EB_A=2.11;
float GammaIsoCut_EB_B=0.0014;

float GammaIsoCut_EC_A=3.09;
float GammaIsoCut_EC_B=0.0091;

}else if(cutType=="Medium"){
cout<<"Running with Medium cuts . . . "<<endl;
float HtoECut_EB=0.012;
float HtoECut_EC=0.023;
float SigmaIetaCut_EB=0.0100;
float SigmaIetaCut_EC=0.0267;
float ChIsoCut_EB=1.79;
float ChIsoCut_EC=1.09;


float NeoIsoCut_EB_A=0.16;
float NeoIsoCut_EB_B=0.0028;
float NeoIsoCut_EB_C=0.5408;
float NeoIsoCut_EC_A=4.31;
float NeoIsoCut_EC_B=0.0172;
float NeoIsoCut_EC_C=0;


float GammaIsoCut_EB_A=1.90;
float GammaIsoCut_EB_B=0.0014;

float GammaIsoCut_EC_A=1.90;
float GammaIsoCut_EC_B=0.0091;

}else if(cutType=="Tight"){
cout<<"Running with Tight cuts . . . "<<endl;
float HtoECut_EB=0.010;
float HtoECut_EC=0.015;
float SigmaIetaCut_EB=0.0100;
float SigmaIetaCut_EC=0.0265;
float ChIsoCut_EB=1.66;
float ChIsoCut_EC=1.04;


float NeoIsoCut_EB_A=0.14;
float NeoIsoCut_EB_B=0.0028;
float NeoIsoCut_EB_C=0.5408;
float NeoIsoCut_EC_A=3.89;
float NeoIsoCut_EC_B=0.0172;
float NeoIsoCut_EC_C=0;


float GammaIsoCut_EB_A=1.40;
float GammaIsoCut_EB_B=0.0014;

float GammaIsoCut_EC_A=1.40;
float GammaIsoCut_EC_B=0.0091;



}else if(cutType !="Tight" && cutType !="Medium" && cutType !="Loose"){

cout<<"Error in Input String"<<endl;
break;

}




gROOT->ProcessLine(".L tdrstyle.C");
setTDRStyle();

 TChain* tG400 = new TChain("TreeMaker2/PreSelection");
  tG400->Add("NtuplesAll/PHYS14.GJets_HT-400to600_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");

 
 TChain* tG600 = new TChain("TreeMaker2/PreSelection");
 tG600->Add("NtuplesAll/PHYS14.GJets_HT-600toInf_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");




   UInt_t          RunNumG400;
   UInt_t          LumiBlockNumG400;
   UInt_t          EvtNumG400;
   Int_t           NVtxG400;
   Int_t           isoElectronTracksG400;
   Int_t           isoMuonTracksG400;
   Int_t           isoPionTracksG400;
   Int_t           LeptonsG400;
   Int_t           LeptonsNoMiniIsolationG400;
   Int_t           NJetsG400;
   Int_t           BTagsG400;
   Int_t           NumPhotonsG400;
   Int_t           NJetsNoPhotonsG400;
   Float_t         WeightG400;
   Float_t         HTG400;
   Float_t         MHTG400;
   Float_t         DeltaPhi1G400;
   Float_t         DeltaPhi2G400;
   Float_t         DeltaPhi3G400;
   Float_t         minDeltaPhiNG400;
   Float_t         DeltaPhiN1G400;
   Float_t         DeltaPhiN2G400;
   Float_t         DeltaPhiN3G400;
   Float_t         METPtG400;
   Float_t         METPhiG400;
   Float_t         rhoG400;
   Float_t         HTnoPhotonsG400;
   Float_t         MHTnoPhotonsG400;
   Float_t         DeltaPhi1noPhotonsG400;
   Float_t         DeltaPhi2noPhotonsG400;
   Float_t         DeltaPhi3noPhotonsG400;
   Float_t         DeltaPhiN1noPhotonsG400;
   Float_t         DeltaPhiN2noPhotonsG400;
   Float_t         DeltaPhiN3noPhotonsG400;
   Float_t         minDeltaPhiNnoPhotonsG400;
   Float_t         METnoPhotonsPtG400;
   Float_t         METnoPhotonsPhiG400;
   Float_t         ak1p2Jets_sumJetMassG400;
   Float_t         ak1p2JetsPt15Reclust_sumJetMassG400;
   Float_t         ak1p2JetsPt20Reclust_sumJetMassG400;
   Float_t         ak1p2JetsPt30Reclust_sumJetMassG400;
   UChar_t         JetIDG400;
   vector<int>     *MuonChargeG400;
   vector<int>     *ElectronChargeG400;
   vector<int>     *genParticles_PDGidG400;
   vector<int>     *ak1p2Jets_nSubjetsG400;
   vector<int>     *ak4Jets_chargedHadMultG400;
   vector<int>     *ak4Jets_neutralHadMultG400;
   vector<int>     *ak4Jets_photonMultG400;
   vector<int>     *ak4Jets_flavorG400;
   vector<double>  *photon_isEBG400;
   vector<double>  *photon_genMatchedG400;
   vector<double>  *photon_hadTowOverEMG400;
   vector<double>  *photon_hasPixelSeedG400;
   vector<double>  *photon_pfChargedIsoG400;
   vector<double>  *photon_pfChargedIsoRhoCorrG400;
   vector<double>  *photon_pfGammaIsoG400;
   vector<double>  *photon_pfGammaIsoRhoCorrG400;
   vector<double>  *photon_pfNeutralIsoG400;
   vector<double>  *photon_pfNeutralIsoRhoCorrG400;
   vector<double>  *photon_sigmaIetaIetaG400;
   vector<double>  *ak1p2Jets_tau1G400;
   vector<double>  *ak1p2Jets_tau2G400;
   vector<double>  *ak1p2Jets_tau3G400;
   vector<double>  *ak1p2Jets_tau4G400;
   vector<double>  *ak4Jets_CSVdiscG400;
   vector<double>  *ak4Jets_MVAdiscG400;
   vector<double>  *ak4Jets_chargeHadEfracG400;
   vector<double>  *ak4Jets_neutralHadEfracG400;
   vector<double>  *ak4Jets_photonEfracG400;
   vector<TLorentzVector> *MuonsG400;
   vector<TLorentzVector> *ElectronsG400;
   vector<TLorentzVector> *genParticlesG400;
   vector<TLorentzVector> *photonCandsG400;
   vector<TLorentzVector> *bestPhotonG400;
   vector<TLorentzVector> *ak4JetsNoPhotonsG400;
   vector<TLorentzVector> *ak1p2JetsG400;
   vector<TLorentzVector> *ak1p2JetsPt15ReclustG400;
   vector<TLorentzVector> *ak1p2JetsPt20ReclustG400;
   vector<TLorentzVector> *ak1p2JetsPt30ReclustG400;
   vector<TLorentzVector> *ak4JetsG400;
   vector<TLorentzVector> *ak4JetsRawG400;
   vector<TLorentzVector> *ak4GenJetsG400;


   UInt_t          RunNumG600;
   UInt_t          LumiBlockNumG600;
   UInt_t          EvtNumG600;
   Int_t           NVtxG600;
   Int_t           isoElectronTracksG600;
   Int_t           isoMuonTracksG600;
   Int_t           isoPionTracksG600;
   Int_t           LeptonsG600;
   Int_t           LeptonsNoMiniIsolationG600;
   Int_t           NJetsG600;
   Int_t           BTagsG600;
   Int_t           NumPhotonsG600;
   Int_t           NJetsNoPhotonsG600;
   Float_t         WeightG600;
   Float_t         HTG600;
   Float_t         MHTG600;
   Float_t         DeltaPhi1G600;
   Float_t         DeltaPhi2G600;
   Float_t         DeltaPhi3G600;
   Float_t         minDeltaPhiNG600;
   Float_t         DeltaPhiN1G600;
   Float_t         DeltaPhiN2G600;
   Float_t         DeltaPhiN3G600;
   Float_t         METPtG600;
   Float_t         METPhiG600;
   Float_t         rhoG600;
   Float_t         HTnoPhotonsG600;
   Float_t         MHTnoPhotonsG600;
   Float_t         DeltaPhi1noPhotonsG600;
   Float_t         DeltaPhi2noPhotonsG600;
   Float_t         DeltaPhi3noPhotonsG600;
   Float_t         DeltaPhiN1noPhotonsG600;
   Float_t         DeltaPhiN2noPhotonsG600;
   Float_t         DeltaPhiN3noPhotonsG600;
   Float_t         minDeltaPhiNnoPhotonsG600;
   Float_t         METnoPhotonsPtG600;
   Float_t         METnoPhotonsPhiG600;
   Float_t         ak1p2Jets_sumJetMassG600;
   Float_t         ak1p2JetsPt15Reclust_sumJetMassG600;
   Float_t         ak1p2JetsPt20Reclust_sumJetMassG600;
   Float_t         ak1p2JetsPt30Reclust_sumJetMassG600;
   UChar_t         JetIDG600;
   vector<int>     *MuonChargeG600;
   vector<int>     *ElectronChargeG600;
   vector<int>     *genParticles_PDGidG600;
   vector<int>     *ak1p2Jets_nSubjetsG600;
   vector<int>     *ak4Jets_chargedHadMultG600;
   vector<int>     *ak4Jets_neutralHadMultG600;
   vector<int>     *ak4Jets_photonMultG600;
   vector<int>     *ak4Jets_flavorG600;
   vector<double>  *photon_isEBG600;
   vector<double>  *photon_genMatchedG600;
   vector<double>  *photon_hadTowOverEMG600;
   vector<double>  *photon_hasPixelSeedG600;
   vector<double>  *photon_pfChargedIsoG600;
   vector<double>  *photon_pfChargedIsoRhoCorrG600;
   vector<double>  *photon_pfGammaIsoG600;
   vector<double>  *photon_pfGammaIsoRhoCorrG600;
   vector<double>  *photon_pfNeutralIsoG600;
   vector<double>  *photon_pfNeutralIsoRhoCorrG600;
   vector<double>  *photon_sigmaIetaIetaG600;
   vector<double>  *ak1p2Jets_tau1G600;
   vector<double>  *ak1p2Jets_tau2G600;
   vector<double>  *ak1p2Jets_tau3G600;
   vector<double>  *ak1p2Jets_tau4G600;
   vector<double>  *ak4Jets_CSVdiscG600;
   vector<double>  *ak4Jets_MVAdiscG600;
   vector<double>  *ak4Jets_chargeHadEfracG600;
   vector<double>  *ak4Jets_neutralHadEfracG600;
   vector<double>  *ak4Jets_photonEfracG600;
   vector<TLorentzVector> *MuonsG600;
   vector<TLorentzVector> *ElectronsG600;
   vector<TLorentzVector> *genParticlesG600;
   vector<TLorentzVector> *photonCandsG600;
   vector<TLorentzVector> *bestPhotonG600;
   vector<TLorentzVector> *ak4JetsNoPhotonsG600;
   vector<TLorentzVector> *ak1p2JetsG600;
   vector<TLorentzVector> *ak1p2JetsPt15ReclustG600;
   vector<TLorentzVector> *ak1p2JetsPt20ReclustG600;
   vector<TLorentzVector> *ak1p2JetsPt30ReclustG600;
   vector<TLorentzVector> *ak4JetsG600;
   vector<TLorentzVector> *ak4JetsRawG600;
   vector<TLorentzVector> *ak4GenJetsG600;
  
  
   	tG400->SetBranchAddress("RunNum", &RunNumG400);
   tG400->SetBranchAddress("LumiBlockNum", &LumiBlockNumG400);
   tG400->SetBranchAddress("EvtNum", &EvtNumG400);
   tG400->SetBranchAddress("NVtx", &NVtxG400);
   tG400->SetBranchAddress("isoElectronTracks", &isoElectronTracksG400);
   tG400->SetBranchAddress("isoMuonTracks", &isoMuonTracksG400);
   tG400->SetBranchAddress("isoPionTracks", &isoPionTracksG400);
   tG400->SetBranchAddress("Leptons", &LeptonsG400);
   tG400->SetBranchAddress("LeptonsNoMiniIsolation", &LeptonsNoMiniIsolationG400);
   tG400->SetBranchAddress("NJets", &NJetsG400);
   tG400->SetBranchAddress("BTags", &BTagsG400);
   tG400->SetBranchAddress("NumPhotons", &NumPhotonsG400);
   tG400->SetBranchAddress("NJetsNoPhotons", &NJetsNoPhotonsG400);
   tG400->SetBranchAddress("Weight", &WeightG400);
   tG400->SetBranchAddress("HT", &HTG400);
   tG400->SetBranchAddress("MHT", &MHTG400);
   tG400->SetBranchAddress("DeltaPhi1", &DeltaPhi1G400);
   tG400->SetBranchAddress("DeltaPhi2", &DeltaPhi2G400);
   tG400->SetBranchAddress("DeltaPhi3", &DeltaPhi3G400);
   tG400->SetBranchAddress("minDeltaPhiN", &minDeltaPhiNG400);
   tG400->SetBranchAddress("DeltaPhiN1", &DeltaPhiN1G400);
   tG400->SetBranchAddress("DeltaPhiN2", &DeltaPhiN2G400);
   tG400->SetBranchAddress("DeltaPhiN3", &DeltaPhiN3G400);
   tG400->SetBranchAddress("METPt", &METPtG400);
   tG400->SetBranchAddress("METPhi", &METPhiG400);
   tG400->SetBranchAddress("rho", &rhoG400);
   tG400->SetBranchAddress("HTnoPhotons", &HTnoPhotonsG400);
   tG400->SetBranchAddress("MHTnoPhotons", &MHTnoPhotonsG400);
   tG400->SetBranchAddress("DeltaPhi1noPhotons", &DeltaPhi1noPhotonsG400);
   tG400->SetBranchAddress("DeltaPhi2noPhotons", &DeltaPhi2noPhotonsG400);
   tG400->SetBranchAddress("DeltaPhi3noPhotons", &DeltaPhi3noPhotonsG400);
   tG400->SetBranchAddress("DeltaPhiN1noPhotons", &DeltaPhiN1noPhotonsG400);
   tG400->SetBranchAddress("DeltaPhiN2noPhotons", &DeltaPhiN2noPhotonsG400);
   tG400->SetBranchAddress("DeltaPhiN3noPhotons", &DeltaPhiN3noPhotonsG400);
   tG400->SetBranchAddress("minDeltaPhiNnoPhotons", &minDeltaPhiNnoPhotonsG400);
   tG400->SetBranchAddress("METnoPhotonsPt", &METnoPhotonsPtG400);
   tG400->SetBranchAddress("METnoPhotonsPhi", &METnoPhotonsPhiG400);
   tG400->SetBranchAddress("ak1p2Jets_sumJetMass", &ak1p2Jets_sumJetMassG400);
   tG400->SetBranchAddress("ak1p2JetsPt15Reclust_sumJetMass", &ak1p2JetsPt15Reclust_sumJetMassG400);
   tG400->SetBranchAddress("ak1p2JetsPt20Reclust_sumJetMass", &ak1p2JetsPt20Reclust_sumJetMassG400);
   tG400->SetBranchAddress("ak1p2JetsPt30Reclust_sumJetMass", &ak1p2JetsPt30Reclust_sumJetMassG400);
   tG400->SetBranchAddress("JetID", &JetIDG400);
   tG400->SetBranchAddress("MuonCharge", &MuonChargeG400);
   tG400->SetBranchAddress("ElectronCharge", &ElectronChargeG400);
   tG400->SetBranchAddress("genParticles_PDGid", &genParticles_PDGidG400);
   tG400->SetBranchAddress("ak1p2Jets_nSubjets", &ak1p2Jets_nSubjetsG400);
   tG400->SetBranchAddress("ak4Jets_chargedHadMult", &ak4Jets_chargedHadMultG400);
   tG400->SetBranchAddress("ak4Jets_neutralHadMult", &ak4Jets_neutralHadMultG400);
   tG400->SetBranchAddress("ak4Jets_photonMult", &ak4Jets_photonMultG400);
   tG400->SetBranchAddress("ak4Jets_flavor", &ak4Jets_flavorG400);
   tG400->SetBranchAddress("photon_isEB", & photon_isEBG400);
   tG400->SetBranchAddress("photon_genMatched", & photon_genMatchedG400);
   tG400->SetBranchAddress("photon_hadTowOverEM", & photon_hadTowOverEMG400);
   tG400->SetBranchAddress("photon_hasPixelSeed", & photon_hasPixelSeedG400);
   tG400->SetBranchAddress("photon_pfChargedIso", & photon_pfChargedIsoG400);
   tG400->SetBranchAddress("photon_pfChargedIsoRhoCorr", & photon_pfChargedIsoRhoCorrG400);
   tG400->SetBranchAddress("photon_pfGammaIso", & photon_pfGammaIsoG400);
   tG400->SetBranchAddress("photon_pfGammaIsoRhoCorr", & photon_pfGammaIsoRhoCorrG400);
   tG400->SetBranchAddress("photon_pfNeutralIso", & photon_pfNeutralIsoG400);
   tG400->SetBranchAddress("photon_pfNeutralIsoRhoCorr", & photon_pfNeutralIsoRhoCorrG400);
   tG400->SetBranchAddress("photon_sigmaIetaIeta", & photon_sigmaIetaIetaG400);
   tG400->SetBranchAddress("ak1p2Jets_tau1", & ak1p2Jets_tau1G400);
   tG400->SetBranchAddress("ak1p2Jets_tau2", & ak1p2Jets_tau2G400);
   tG400->SetBranchAddress("ak1p2Jets_tau3", & ak1p2Jets_tau3G400);
   tG400->SetBranchAddress("ak1p2Jets_tau4", & ak1p2Jets_tau4G400);
   tG400->SetBranchAddress("ak4Jets_CSVdisc", & ak4Jets_CSVdiscG400);
   tG400->SetBranchAddress("ak4Jets_MVAdisc", & ak4Jets_MVAdiscG400);
   tG400->SetBranchAddress("ak4Jets_chargeHadEfrac", & ak4Jets_chargeHadEfracG400);
   tG400->SetBranchAddress("ak4Jets_neutralHadEfrac", & ak4Jets_neutralHadEfracG400);
   tG400->SetBranchAddress("ak4Jets_photonEfrac", &ak4Jets_photonEfracG400);
   tG400->SetBranchAddress("Muons", &MuonsG400);
   tG400->SetBranchAddress("Electrons", &ElectronsG400);
   tG400->SetBranchAddress("genParticles", &genParticlesG400);
   tG400->SetBranchAddress("photonCands", &photonCandsG400);
   tG400->SetBranchAddress("bestPhoton", &bestPhotonG400);
   tG400->SetBranchAddress("ak4JetsNoPhotons", &ak4JetsNoPhotonsG400);
   tG400->SetBranchAddress("ak1p2Jets", &ak1p2JetsG400);
   tG400->SetBranchAddress("ak1p2JetsPt15Reclust", &ak1p2JetsPt15ReclustG400);
   tG400->SetBranchAddress("ak1p2JetsPt20Reclust", &ak1p2JetsPt20ReclustG400);
   tG400->SetBranchAddress("ak1p2JetsPt30Reclust", &ak1p2JetsPt30ReclustG400);
   tG400->SetBranchAddress("ak4Jets", &ak4JetsG400);
   tG400->SetBranchAddress("ak4JetsRaw", &ak4JetsRawG400);
   tG400->SetBranchAddress("ak4GenJets", &ak4GenJetsG400);

   photon photonsG400(tG400);
   
   tG600->SetBranchAddress("RunNum", &RunNumG600);
   tG600->SetBranchAddress("LumiBlockNum", &LumiBlockNumG600);
   tG600->SetBranchAddress("EvtNum", &EvtNumG600);
   tG600->SetBranchAddress("NVtx", &NVtxG600);
   tG600->SetBranchAddress("isoElectronTracks", &isoElectronTracksG600);
   tG600->SetBranchAddress("isoMuonTracks", &isoMuonTracksG600);
   tG600->SetBranchAddress("isoPionTracks", &isoPionTracksG600);
   tG600->SetBranchAddress("Leptons", &LeptonsG600);
   tG600->SetBranchAddress("LeptonsNoMiniIsolation", &LeptonsNoMiniIsolationG600);
   tG600->SetBranchAddress("NJets", &NJetsG600);
   tG600->SetBranchAddress("BTags", &BTagsG600);
   tG600->SetBranchAddress("NumPhotons", &NumPhotonsG600);
   tG600->SetBranchAddress("NJetsNoPhotons", &NJetsNoPhotonsG600);
   tG600->SetBranchAddress("Weight", &WeightG600);
   tG600->SetBranchAddress("HT", &HTG600);
   tG600->SetBranchAddress("MHT", &MHTG600);
   tG600->SetBranchAddress("DeltaPhi1", &DeltaPhi1G600);
   tG600->SetBranchAddress("DeltaPhi2", &DeltaPhi2G600);
   tG600->SetBranchAddress("DeltaPhi3", &DeltaPhi3G600);
   tG600->SetBranchAddress("minDeltaPhiN", &minDeltaPhiNG600);
   tG600->SetBranchAddress("DeltaPhiN1", &DeltaPhiN1G600);
   tG600->SetBranchAddress("DeltaPhiN2", &DeltaPhiN2G600);
   tG600->SetBranchAddress("DeltaPhiN3", &DeltaPhiN3G600);
   tG600->SetBranchAddress("METPt", &METPtG600);
   tG600->SetBranchAddress("METPhi", &METPhiG600);
   tG600->SetBranchAddress("rho", &rhoG600);
   tG600->SetBranchAddress("HTnoPhotons", &HTnoPhotonsG600);
   tG600->SetBranchAddress("MHTnoPhotons", &MHTnoPhotonsG600);
   tG600->SetBranchAddress("DeltaPhi1noPhotons", &DeltaPhi1noPhotonsG600);
   tG600->SetBranchAddress("DeltaPhi2noPhotons", &DeltaPhi2noPhotonsG600);
   tG600->SetBranchAddress("DeltaPhi3noPhotons", &DeltaPhi3noPhotonsG600);
   tG600->SetBranchAddress("DeltaPhiN1noPhotons", &DeltaPhiN1noPhotonsG600);
   tG600->SetBranchAddress("DeltaPhiN2noPhotons", &DeltaPhiN2noPhotonsG600);
   tG600->SetBranchAddress("DeltaPhiN3noPhotons", &DeltaPhiN3noPhotonsG600);
   tG600->SetBranchAddress("minDeltaPhiNnoPhotons", &minDeltaPhiNnoPhotonsG600);
   tG600->SetBranchAddress("METnoPhotonsPt", &METnoPhotonsPtG600);
   tG600->SetBranchAddress("METnoPhotonsPhi", &METnoPhotonsPhiG600);
   tG600->SetBranchAddress("ak1p2Jets_sumJetMass", &ak1p2Jets_sumJetMassG600);
   tG600->SetBranchAddress("ak1p2JetsPt15Reclust_sumJetMass", &ak1p2JetsPt15Reclust_sumJetMassG600);
   tG600->SetBranchAddress("ak1p2JetsPt20Reclust_sumJetMass", &ak1p2JetsPt20Reclust_sumJetMassG600);
   tG600->SetBranchAddress("ak1p2JetsPt30Reclust_sumJetMass", &ak1p2JetsPt30Reclust_sumJetMassG600);
   tG600->SetBranchAddress("JetID", &JetIDG600);
   tG600->SetBranchAddress("MuonCharge", &MuonChargeG600);
   tG600->SetBranchAddress("ElectronCharge", &ElectronChargeG600);
   tG600->SetBranchAddress("genParticles_PDGid", &genParticles_PDGidG600);
   tG600->SetBranchAddress("ak1p2Jets_nSubjets", &ak1p2Jets_nSubjetsG600);
   tG600->SetBranchAddress("ak4Jets_chargedHadMult", &ak4Jets_chargedHadMultG600);
   tG600->SetBranchAddress("ak4Jets_neutralHadMult", &ak4Jets_neutralHadMultG600);
   tG600->SetBranchAddress("ak4Jets_photonMult", &ak4Jets_photonMultG600);
   tG600->SetBranchAddress("ak4Jets_flavor", &ak4Jets_flavorG600);
   tG600->SetBranchAddress("photon_isEB", & photon_isEBG600);
   tG600->SetBranchAddress("photon_genMatched", & photon_genMatchedG600);
   tG600->SetBranchAddress("photon_hadTowOverEM", & photon_hadTowOverEMG600);
   tG600->SetBranchAddress("photon_hasPixelSeed", & photon_hasPixelSeedG600);
   tG600->SetBranchAddress("photon_pfChargedIso", & photon_pfChargedIsoG600);
   tG600->SetBranchAddress("photon_pfChargedIsoRhoCorr", & photon_pfChargedIsoRhoCorrG600);
   tG600->SetBranchAddress("photon_pfGammaIso", & photon_pfGammaIsoG600);
   tG600->SetBranchAddress("photon_pfGammaIsoRhoCorr", & photon_pfGammaIsoRhoCorrG600);
   tG600->SetBranchAddress("photon_pfNeutralIso", & photon_pfNeutralIsoG600);
   tG600->SetBranchAddress("photon_pfNeutralIsoRhoCorr", & photon_pfNeutralIsoRhoCorrG600);
   tG600->SetBranchAddress("photon_sigmaIetaIeta", & photon_sigmaIetaIetaG600);
   tG600->SetBranchAddress("ak1p2Jets_tau1", & ak1p2Jets_tau1G600);
   tG600->SetBranchAddress("ak1p2Jets_tau2", & ak1p2Jets_tau2G600);
   tG600->SetBranchAddress("ak1p2Jets_tau3", & ak1p2Jets_tau3G600);
   tG600->SetBranchAddress("ak1p2Jets_tau4", & ak1p2Jets_tau4G600);
   tG600->SetBranchAddress("ak4Jets_CSVdisc", & ak4Jets_CSVdiscG600);
   tG600->SetBranchAddress("ak4Jets_MVAdisc", & ak4Jets_MVAdiscG600);
   tG600->SetBranchAddress("ak4Jets_chargeHadEfrac", & ak4Jets_chargeHadEfracG600);
   tG600->SetBranchAddress("ak4Jets_neutralHadEfrac", & ak4Jets_neutralHadEfracG600);
   tG600->SetBranchAddress("ak4Jets_photonEfrac", &ak4Jets_photonEfracG600);
   tG600->SetBranchAddress("Muons", &MuonsG600);
   tG600->SetBranchAddress("Electrons", &ElectronsG600);
   tG600->SetBranchAddress("genParticles", &genParticlesG600);
   tG600->SetBranchAddress("photonCands", &photonCandsG600);
   tG600->SetBranchAddress("bestPhoton", &bestPhotonG600);
   tG600->SetBranchAddress("ak4JetsNoPhotons", &ak4JetsNoPhotonsG600);
   tG600->SetBranchAddress("ak1p2Jets", &ak1p2JetsG600);
   tG600->SetBranchAddress("ak1p2JetsPt15Reclust", &ak1p2JetsPt15ReclustG600);
   tG600->SetBranchAddress("ak1p2JetsPt20Reclust", &ak1p2JetsPt20ReclustG600);
   tG600->SetBranchAddress("ak1p2JetsPt30Reclust", &ak1p2JetsPt30ReclustG600);
   tG600->SetBranchAddress("ak4Jets", &ak4JetsG600);
   tG600->SetBranchAddress("ak4JetsRaw", &ak4JetsRawG600);
   tG600->SetBranchAddress("ak4GenJets", &ak4GenJetsG600);

   photon photonsG600(tG600);


TH1F *h_effHTG400_EB=new TH1F("h_effHTG400_EB","h_effT",600,500,3000);
TH1F *h_effHTG400_EC=new TH1F("h_effHTG400_EC","h_effT",600,500,3000);
TH1F *h_effHTG600_EB=new TH1F("h_effHTG600_EB","h_effT",600,500,3000);
TH1F *h_effHTG600_EC=new TH1F("h_effHTG600_EC","h_effT",600,500,3000);

TH1F *h_effHTG400_EBcut=new TH1F("h_effHTG400_EBcut","h_effT",600,500,3000);
TH1F *h_effHTG400_ECcut=new TH1F("h_effHTG400_ECcut","h_effT",600,500,3000);
TH1F *h_effHTG600_EBcut=new TH1F("h_effHTG600_EBcut","h_effT",600,500,3000);
TH1F *h_effHTG600_ECcut=new TH1F("h_effHTG600_ECcut","h_effT",600,500,3000);

TH1F *h_effHTG_EB=new TH1F("h_effHT_EB","h_effT",600,500,3000);
TH1F *h_effHTG_EC=new TH1F("h_effHT_EC","h_effT",600,500,3000);

TH1F *h_effHTG_EBcut=new TH1F("h_effHT_EBcut","h_effT",600,500,3000);
TH1F *h_effHTG_ECcut=new TH1F("h_effHT_ECcut","h_effT",600,500,3000);



TH1F *h_effMHTG400_EB=new TH1F("h_effMHTG400_EB","h_effT",600,200,3000);
TH1F *h_effMHTG400_EC=new TH1F("h_effMHTG400_EC","h_effT",600,200,3000);
TH1F *h_effMHTG600_EB=new TH1F("h_effMHTG600_EB","h_effT",600,200,3000);
TH1F *h_effMHTG600_EC=new TH1F("h_effMHTG600_EC","h_effT",600,200,3000);

TH1F *h_effMHTG400_EBcut=new TH1F("h_effMHTG400_EBcut","h_effT",600,200,3000);
TH1F *h_effMHTG400_ECcut=new TH1F("h_effMHTG400_ECcut","h_effT",600,200,3000);
TH1F *h_effMHTG600_EBcut=new TH1F("h_effMHTG600_EBcut","h_effT",600,200,3000);
TH1F *h_effMHTG600_ECcut=new TH1F("h_effMHTG600_ECcut","h_effT",600,200,3000);

TH1F *h_effMHTG_EB=new TH1F("h_effMHT_EB","h_effT",600,200,3000);
TH1F *h_effMHTG_EC=new TH1F("h_effMHT_EC","h_effT",600,200,3000);

TH1F *h_effMHTG_EBcut=new TH1F("h_effMHT_EBcut","h_effT",600,200,3000);
TH1F *h_effMHTG_ECcut=new TH1F("h_effMHT_ECcut","h_effT",600,200,3000);


TH1F *h_effNJetsG400_EB=new TH1F("h_effNJetsG400_EB","h_effT",20,0,20);
TH1F *h_effNJetsG400_EC=new TH1F("h_effNJetsG400_EC","h_effT",20,0,20);
TH1F *h_effNJetsG600_EB=new TH1F("h_effNJetsG600_EB","h_effT",20,0,20);
TH1F *h_effNJetsG600_EC=new TH1F("h_effNJetsG600_EC","h_effT",20,0,20);

TH1F *h_effNJetsG400_EBcut=new TH1F("h_effNJetsG400_EBcut","h_effT",20,0,20);
TH1F *h_effNJetsG400_ECcut=new TH1F("h_effNJetsG400_ECcut","h_effT",20,0,20);
TH1F *h_effNJetsG600_EBcut=new TH1F("h_effNJetsG600_EBcut","h_effT",20,0,20);
TH1F *h_effNJetsG600_ECcut=new TH1F("h_effNJetsG600_ECcut","h_effT",20,0,20);

TH1F *h_effNJetsG_EB=new TH1F("h_effNJets_EB","h_effT",20,0,20);
TH1F *h_effNJetsG_EC=new TH1F("h_effNJets_EC","h_effT",20,0,20);

TH1F *h_effNJetsG_EBcut=new TH1F("h_effNJets_EBcut","h_effT",20,0,20);
TH1F *h_effNJetsG_ECcut=new TH1F("h_effNJets_ECcut","h_effT",20,0,20);



TH1F *h_effBJetsG400_EB=new TH1F("h_effBJetsG400_EB","h_effT",10,0,10);
TH1F *h_effBJetsG400_EC=new TH1F("h_effBJetsG400_EC","h_effT",10,0,10);
TH1F *h_effBJetsG600_EB=new TH1F("h_effBJetsG600_EB","h_effT",10,0,10);
TH1F *h_effBJetsG600_EC=new TH1F("h_effBJetsG600_EC","h_effT",10,0,10);

TH1F *h_effBJetsG400_EBcut=new TH1F("h_effBJetsG400_EBcut","h_effT",10,0,10);
TH1F *h_effBJetsG400_ECcut=new TH1F("h_effBJetsG400_ECcut","h_effT",10,0,10);
TH1F *h_effBJetsG600_EBcut=new TH1F("h_effBJetsG600_EBcut","h_effT",10,0,10);
TH1F *h_effBJetsG600_ECcut=new TH1F("h_effBJetsG600_ECcut","h_effT",10,0,10);

TH1F *h_effBJetsG_EB=new TH1F("h_effBJets_EB","h_effT",10,0,10);
TH1F *h_effBJetsG_EC=new TH1F("h_effBJets_EC","h_effT",10,0,10);

TH1F *h_effBJetsG_EBcut=new TH1F("h_effBJets_EBcut","h_effT",10,0,10);
TH1F *h_effBJetsG_ECcut=new TH1F("h_effBJets_ECcut","h_effT",10,0,10);

  

int totalEBG400=0;
int totalECG400=0;
int totalEBG600=0;
int totalECG600=0;


int totalcutEBG400=0;
int totalcutECG400=0;
int totalcutEBG600=0;
int totalcutECG600=0;


int NumEvents=1000000000;

for( int iEv1 = 0 ;  iEv1 < tG400->GetEntries() ;  iEv1++){//event loop G400
    tG400->GetEntry(iEv1);
    if(iEv1==NumEvents)break;
    if( iEv1 % 5000 == 0 ) cout << "event: " << iEv1 << endl;

   
photonsG400.getPhotonsFromEvent( iEv1 );



	

if(HTnoPhotonsG400 > 500  && MHTnoPhotonsG400 >200 && NJetsNoPhotonsG400 >= 4  && LeptonsG400==0 && minDeltaPhiNnoPhotonsG400 > 6.){//base line conditions

for( unsigned int iPh = 0 ; iPh < photonsG400.fourVec->size() ; iPh++ ){ //photon loop G400

if(photonsG400.isGenMatched->at(iPh) ==1){//gen match condition
if(photonsG400.fourVec->at(iPh).Pt() > 100.){//Photon pT > 100 GeV







double EBphotonsG400 = photonsG400.isEB->at(iPh);

//cout<<"EB value = "<<EBphotonsG400<<endl;

if(EBphotonsG400==1){//EB Photons


h_effHTG400_EB->Fill(HTnoPhotonsG400);
h_effMHTG400_EB->Fill(MHTnoPhotonsG400);
h_effNJetsG400_EB->Fill(NJetsNoPhotonsG400);
h_effBJetsG400_EB->Fill(BTagsG400);




int htoeg400EB=0;
int pxlg400EB=0;
int sietag400EB=0;
int chisog400EB=0;
int neoisog400EB=0;
int gammisog400EB=0;


totalEBG400=totalEBG400+1;

if(photonsG400.hadTowOverEM->at(iPh) < HtoECut_EB){

htoeg400EB=5;

}


if(photonsG400.hasPixelSeed->at(iPh) !=1){
pxlg400EB=5;


}




if(photonsG400.sigmaIetaIeta->at(iPh) < SigmaIetaCut_EB){
sietag400EB=5;

}

double Pf_Ch_RhoCorrIsoG400EB=photonsG400.ChargedIsoRhoCorr( iEv1 , iPh , rhoG400);
if(Pf_Ch_RhoCorrIsoG400EB < ChIsoCut_EB){
chisog400EB=5;

}

double Pf_Nu_RhoCorrIsoG400EB=photonsG400.NeutralIsoRhoCorr( iEv1 , iPh , rhoG400);

if(Pf_Nu_RhoCorrIsoG400EB < (NeoIsoCut_EB_A + TMath::Exp(NeoIsoCut_EB_B*photonsG400.fourVec->at(iPh).Pt()+NeoIsoCut_EB_C))){
neoisog400EB=5;


}

double Pf_Gam_RhoCorrIsoG400EB=photonsG400.PhotonIsoRhoCorr( iEv1 , iPh , rhoG400);

if(Pf_Gam_RhoCorrIsoG400EB < (GammaIsoCut_EB_A + GammaIsoCut_EB_B*photonsG400.fourVec->at(iPh).Pt())){
gammisog400EB=5;



}



if(htoeg400EB==5 && pxlg400EB==5 && sietag400EB==5 && chisog400EB==5 && neoisog400EB==5 && gammisog400EB==5 ){

h_effHTG400_EBcut->Fill(HTnoPhotonsG400);
h_effMHTG400_EBcut->Fill(MHTnoPhotonsG400);
h_effNJetsG400_EBcut->Fill(NJetsNoPhotonsG400);
h_effBJetsG400_EBcut->Fill(BTagsG400);

}

}else if(EBphotonsG400 !=1){//EC photons

h_effHTG400_EC->Fill(HTnoPhotonsG400);
h_effMHTG400_EC->Fill(MHTnoPhotonsG400);
h_effNJetsG400_EC->Fill(NJetsNoPhotonsG400);
h_effBJetsG400_EC->Fill(BTagsG400);





int htoeg400EC=0;
int pxlg400EC=0;
int sietag400EC=0;
int chisog400EC=0;
int neoisog400EC=0;
int gammisog400EC=0;






if(photonsG400.hadTowOverEM->at(iPh) < HtoECut_EB){
htoeg400EC=5;


}


if(photonsG400.hasPixelSeed->at(iPh) !=1){
pxlg400EC=5;


}



if(photonsG400.sigmaIetaIeta->at(iPh) < SigmaIetaCut_EC){
sietag400EC=5;

}

double Pf_Ch_RhoCorrIsoG400EC =photonsG400.ChargedIsoRhoCorr( iEv1 , iPh , rhoG400);
if(Pf_Ch_RhoCorrIsoG400EC < ChIsoCut_EC){
chisog400EC=5;

}
double Pf_Nu_RhoCorrIsoG400EC=photonsG400.NeutralIsoRhoCorr( iEv1 , iPh , rhoG400);

if( Pf_Nu_RhoCorrIsoG400EC < (NeoIsoCut_EC_A + NeoIsoCut_EC_B*photonsG400.fourVec->at(iPh).Pt())){
neoisog400EC=5;


}

double Pf_Gam_RhoCorrIsoG400EC=photonsG400.PhotonIsoRhoCorr( iEv1 , iPh , rhoG400);
if( Pf_Gam_RhoCorrIsoG400EC < (GammaIsoCut_EC_A + GammaIsoCut_EC_B*photonsG400.fourVec->at(iPh).Pt())){
gammisog400EC=5;


}

if(htoeg400EC==5 && pxlg400EC==5 && sietag400EC==5 && chisog400EC==5 && neoisog400EC==5 && gammisog400EC==5 ){
h_effHTG400_ECcut->Fill(HTnoPhotonsG400);
h_effMHTG400_ECcut->Fill(MHTnoPhotonsG400);
h_effNJetsG400_ECcut->Fill(NJetsNoPhotonsG400);
h_effBJetsG400_ECcut->Fill(BTagsG400);

}


}//EC Photons up



}//Photon pT > 100 GeV
}//gen match condition


}//photon loop  G400
}//base line conditions




}// event loop G400





for( int iEv2 = 0 ;  iEv2 < tG600->GetEntries() ;  iEv2++){//event loop G600
    tG600->GetEntry(iEv2);
    if(iEv2==NumEvents)break;
    if( iEv2 % 5000 == 0 ) cout << "event: " << iEv2 << endl;

   
photonsG600.getPhotonsFromEvent( iEv2 );



	

if(HTnoPhotonsG600 > 500  && MHTnoPhotonsG600 >200 && NJetsNoPhotonsG600 >= 4  && LeptonsG600==0 && minDeltaPhiNnoPhotonsG600 > 6.){//base line conditions

for( unsigned int iPh = 0 ; iPh < photonsG600.fourVec->size() ; iPh++ ){ //photon loop G600

if(photonsG600.isGenMatched->at(iPh) ==1){//gen match condition
if(photonsG600.fourVec->at(iPh).Pt() > 100.){//Photon pT > 100 GeV







double EBphotonsG400 = photonsG600.isEB->at(iPh);

//cout<<"EB value = "<<EBphotonsG400<<endl;

if(EBphotonsG400==1){//EB Photons


h_effHTG600_EB->Fill(HTnoPhotonsG600);
h_effMHTG600_EB->Fill(MHTnoPhotonsG600);
h_effNJetsG600_EB->Fill(NJetsNoPhotonsG600);
h_effBJetsG600_EB->Fill(BTagsG600);




int htoeg600EB=0;
int pxlg600EB=0;
int sietag600EB=0;
int chisog600EB=0;
int neoisog600EB=0;
int gammisog600EB=0;


totalEBG600=totalEBG600+1;

if(photonsG600.hadTowOverEM->at(iPh) < HtoECut_EB){

htoeg600EB=5;

}


if(photonsG600.hasPixelSeed->at(iPh) !=1){
pxlg600EB=5;


}




if(photonsG600.sigmaIetaIeta->at(iPh) < SigmaIetaCut_EB){
sietag600EB=5;

}

double Pf_Ch_RhoCorrIsoG600EB=photonsG600.ChargedIsoRhoCorr( iEv2 , iPh , rhoG600);
if(Pf_Ch_RhoCorrIsoG600EB < ChIsoCut_EB){
chisog600EB=5;

}

double Pf_Nu_RhoCorrIsoG600EB=photonsG600.NeutralIsoRhoCorr( iEv2 , iPh , rhoG600);

if(Pf_Nu_RhoCorrIsoG600EB < (NeoIsoCut_EB_A + TMath::Exp(NeoIsoCut_EB_B*photonsG600.fourVec->at(iPh).Pt()+NeoIsoCut_EB_C))){
neoisog600EB=5;


}

double Pf_Gam_RhoCorrIsoG600EB=photonsG600.PhotonIsoRhoCorr( iEv2 , iPh , rhoG600);

if(Pf_Gam_RhoCorrIsoG600EB < (GammaIsoCut_EB_A + GammaIsoCut_EB_B*photonsG600.fourVec->at(iPh).Pt())){
gammisog600EB=5;



}



if(htoeg600EB==5 && pxlg600EB==5 && sietag600EB==5 && chisog600EB==5 && neoisog600EB==5 && gammisog600EB==5 ){

h_effHTG600_EBcut->Fill(HTnoPhotonsG600);
h_effMHTG600_EBcut->Fill(MHTnoPhotonsG600);
h_effNJetsG600_EBcut->Fill(NJetsNoPhotonsG600);
h_effBJetsG600_EBcut->Fill(BTagsG600);

}

}else if(EBphotonsG400 !=1){//EC photons

h_effHTG600_EC->Fill(HTnoPhotonsG600);
h_effMHTG600_EC->Fill(MHTnoPhotonsG600);
h_effNJetsG600_EC->Fill(NJetsNoPhotonsG600);
h_effBJetsG600_EC->Fill(BTagsG600);





int htoeg600EC=0;
int pxlg600EC=0;
int sietag600EC=0;
int chisog600EC=0;
int neoisog600EC=0;
int gammisog600EC=0;






if(photonsG600.hadTowOverEM->at(iPh) < HtoECut_EB){
htoeg600EC=5;


}


if(photonsG600.hasPixelSeed->at(iPh) !=1){
pxlg600EC=5;


}



if(photonsG600.sigmaIetaIeta->at(iPh) < SigmaIetaCut_EC){
sietag600EC=5;

}

double Pf_Ch_RhoCorrIsoG600EC =photonsG600.ChargedIsoRhoCorr( iEv2 , iPh , rhoG600);
if(Pf_Ch_RhoCorrIsoG600EC < ChIsoCut_EC){
chisog600EC=5;

}
double Pf_Nu_RhoCorrIsoG600EC=photonsG600.NeutralIsoRhoCorr( iEv2 , iPh , rhoG600);

if( Pf_Nu_RhoCorrIsoG600EC < (NeoIsoCut_EC_A + NeoIsoCut_EC_B*photonsG600.fourVec->at(iPh).Pt())){
neoisog600EC=5;


}

double Pf_Gam_RhoCorrIsoG600EC=photonsG600.PhotonIsoRhoCorr( iEv2 , iPh , rhoG600);
if( Pf_Gam_RhoCorrIsoG600EC < (GammaIsoCut_EC_A + GammaIsoCut_EC_B*photonsG600.fourVec->at(iPh).Pt())){
gammisog600EC=5;


}

if(htoeg600EC==5 && pxlg600EC==5 && sietag600EC==5 && chisog600EC==5 && neoisog600EC==5 && gammisog600EC==5 ){
h_effHTG600_ECcut->Fill(HTnoPhotonsG600);
h_effMHTG600_ECcut->Fill(MHTnoPhotonsG600);
h_effNJetsG600_ECcut->Fill(NJetsNoPhotonsG600);
h_effBJetsG600_ECcut->Fill(BTagsG600);

}


}//EC Photons up






}//Photon pT > 100 GeV
}//gen match condition


}//photon loop  G600
}//base line conditions




}// event loop G600


///////////////////////Event loop ends and starts produing the text files





cout<<"cut_Type"<<cut_Type<<endl;
char HTEBtxt[100];
char HTECtxt[100];
char MHTEBtxt[100];
char MHTECtxt[100];

char NJetsEBtxt[100];
char NJetsECtxt[100];

char BJetsEBtxt[100];
char BJetsECtxt[100];



sprintf(HTEBtxt, "HTEB%s.txt", cut_Type);
sprintf(HTECtxt, "HTEC%s.txt", cut_Type);
sprintf(MHTEBtxt, "MHTEB%s.txt", cut_Type);
sprintf(MHTECtxt, "MHTEC%s.txt", cut_Type);

sprintf(NJetsEBtxt, "NJetsEB%s.txt", cut_Type);
sprintf(NJetsECtxt, "NJetsEC%s.txt", cut_Type);


sprintf(BJetsEBtxt, "BJetsEB%s.txt", cut_Type);
sprintf(BJetsECtxt, "BJetsEC%s.txt", cut_Type);






///////////////////////////////HT
h_effHTG400_EBcut->Scale(0.075604015773398);
h_effHTG600_EBcut->Scale(0.0261385093009007);

h_effHTG400_ECcut->Scale(0.075604015773398);
h_effHTG600_ECcut->Scale(0.0261385093009007);



h_effHTG400_EB->Scale(0.075604015773398);
h_effHTG600_EB->Scale(0.0261385093009007);

h_effHTG400_EC->Scale(0.075604015773398);
h_effHTG600_EC->Scale(0.0261385093009007);



h_effHTG_EB->Add(h_effHTG400_EB);
h_effHTG_EB->Add(h_effHTG600_EB);

h_effHTG_EC->Add(h_effHTG400_EC);
h_effHTG_EC->Add(h_effHTG600_EC);


h_effHTG_EBcut->Add(h_effHTG400_EBcut);
h_effHTG_EBcut->Add(h_effHTG600_EBcut);

h_effHTG_ECcut->Add(h_effHTG400_ECcut);
h_effHTG_ECcut->Add(h_effHTG600_ECcut);


TAxis *xaxisHT_EB =h_effHTG_EB->GetXaxis();

TAxis *xaxisHT_EC =h_effHTG_EC->GetXaxis();

float phEffHT_EB=0;
float phEffHT_EC=0;



fstream pheffHTEB;

fstream pheffHTEC;

pheffHTEB.open(HTEBtxt,ios::out|ios::trunc);

pheffHTEC.open(HTECtxt,ios::out|ios::trunc);


for(int i=500;i<3000;i+=300){

int HTbinNumlow=xaxisHT_EB->FindBin(i);
int HTbinNumhigh=xaxisHT_EB->FindBin(i+300);


phEffHT_EB=h_effHTG_EBcut->Integral(HTbinNumlow,HTbinNumhigh)/h_effHTG_EB->Integral(HTbinNumlow,HTbinNumhigh);
phEffHT_EC=h_effHTG_ECcut->Integral(HTbinNumlow,HTbinNumhigh)/h_effHTG_EC->Integral(HTbinNumlow,HTbinNumhigh);


float ErrphEffHT_EB=sqrt(((phEffHT_EB)*(1-phEffHT_EB))/h_effHTG_EB->Integral(HTbinNumlow,HTbinNumhigh));
float ErrphEffHT_EC=sqrt(((phEffHT_EC)*(1-phEffHT_EC))/h_effHTG_EC->Integral(HTbinNumlow,HTbinNumhigh));



cout<<"Barrel Photon Efficiency HT: "<<i<<"to"<<i+300<<" = "<<phEffHT_EB<<" +- "<<ErrphEffHT_EB<<endl;
cout<<"Endcap Photon Efficiency HT: "<<i<<"to"<<i+300<<" = "<<phEffHT_EC<<" +- "<<ErrphEffHT_EC<<endl;

pheffHTEB<<phEffHT_EB<<" "<<ErrphEffHT_EB<<endl;

pheffHTEC<<phEffHT_EC<<" "<<ErrphEffHT_EC<<endl;

}





//////////////////////////////////////////////////////MHT
h_effMHTG400_EBcut->Scale(0.075604015773398);
h_effMHTG600_EBcut->Scale(0.0261385093009007);

h_effMHTG400_ECcut->Scale(0.075604015773398);
h_effMHTG600_ECcut->Scale(0.0261385093009007);



h_effMHTG400_EB->Scale(0.075604015773398);
h_effMHTG600_EB->Scale(0.0261385093009007);

h_effMHTG400_EC->Scale(0.075604015773398);
h_effMHTG600_EC->Scale(0.0261385093009007);



h_effMHTG_EB->Add(h_effMHTG400_EB);
h_effMHTG_EB->Add(h_effMHTG600_EB);

h_effMHTG_EC->Add(h_effMHTG400_EC);
h_effMHTG_EC->Add(h_effMHTG600_EC);


h_effMHTG_EBcut->Add(h_effMHTG400_EBcut);
h_effMHTG_EBcut->Add(h_effMHTG600_EBcut);

h_effMHTG_ECcut->Add(h_effMHTG400_ECcut);
h_effMHTG_ECcut->Add(h_effMHTG600_ECcut);



TAxis *xaxisMHT_EB =h_effMHTG_EB->GetXaxis();

TAxis *xaxisMHT_EC =h_effMHTG_EC->GetXaxis();

float phEffMHT_EB=0;
float phEffMHT_EC=0;

fstream pheffMHTEB;

fstream pheffMHTEC;

pheffMHTEB.open(MHTEBtxt,ios::out|ios::trunc);

pheffMHTEC.open(MHTECtxt,ios::out|ios::trunc);








for(int i=200;i<1500;i+=300){

int MHTbinNumlow=xaxisMHT_EB->FindBin(i);
int MHTbinNumhigh=xaxisMHT_EB->FindBin(i+300);


phEffMHT_EB=h_effMHTG_EBcut->Integral(MHTbinNumlow,MHTbinNumhigh)/h_effMHTG_EB->Integral(MHTbinNumlow,MHTbinNumhigh);
phEffMHT_EC=h_effMHTG_ECcut->Integral(MHTbinNumlow,MHTbinNumhigh)/h_effMHTG_EC->Integral(MHTbinNumlow,MHTbinNumhigh);


float ErrphEffMHT_EB=sqrt(((phEffMHT_EB)*(1-phEffMHT_EB))/h_effMHTG_EB->Integral(MHTbinNumlow,MHTbinNumhigh));
float ErrphEffMHT_EC=sqrt(((phEffMHT_EC)*(1-phEffMHT_EC))/h_effMHTG_EC->Integral(MHTbinNumlow,MHTbinNumhigh));



cout<<"Barrel Photon Efficiency MHT: "<<i<<"to"<<i+300<<" = "<<phEffMHT_EB<<" +- "<<ErrphEffMHT_EB<<endl;
cout<<"Endcap Photon Efficiency MHT: "<<i<<"to"<<i+300<<" = "<<phEffMHT_EC<<" +- "<<ErrphEffMHT_EC<<endl;

pheffMHTEB<<phEffMHT_EB<<" "<<ErrphEffMHT_EB<<endl;

pheffMHTEC<<phEffMHT_EC<<" "<<ErrphEffMHT_EC<<endl;
}

















///////////////////////////////////NJets

h_effNJetsG400_EBcut->Scale(0.075604015773398);
h_effNJetsG600_EBcut->Scale(0.0261385093009007);

h_effNJetsG400_ECcut->Scale(0.075604015773398);
h_effNJetsG600_ECcut->Scale(0.0261385093009007);



h_effNJetsG400_EB->Scale(0.075604015773398);
h_effNJetsG600_EB->Scale(0.0261385093009007);

h_effNJetsG400_EC->Scale(0.075604015773398);
h_effNJetsG600_EC->Scale(0.0261385093009007);



h_effNJetsG_EB->Add(h_effNJetsG400_EB);
h_effNJetsG_EB->Add(h_effNJetsG600_EB);

h_effNJetsG_EC->Add(h_effNJetsG400_EC);
h_effNJetsG_EC->Add(h_effNJetsG600_EC);


h_effNJetsG_EBcut->Add(h_effNJetsG400_EBcut);
h_effNJetsG_EBcut->Add(h_effNJetsG600_EBcut);

h_effNJetsG_ECcut->Add(h_effNJetsG400_ECcut);
h_effNJetsG_ECcut->Add(h_effNJetsG600_ECcut);






TAxis *xaxisNJets_EB =h_effNJetsG_EB->GetXaxis();

TAxis *xaxisNJets_EC =h_effNJetsG_EC->GetXaxis();

float phEffNJets_EB=0;
float phEffNJets_EC=0;


fstream pheffNJetsEB;

fstream pheffNJetsEC;

pheffNJetsEB.open(NJetsEBtxt,ios::out|ios::trunc);

pheffNJetsEC.open(NJetsECtxt,ios::out|ios::trunc);








for(int i=4;i<9;i++){


int NJetsbinNumlow=xaxisNJets_EB->FindBin(i);
int NJetsbinNumhigh=xaxisNJets_EB->FindBin(i+1);


phEffNJets_EB=h_effNJetsG_EBcut->Integral(NJetsbinNumlow,NJetsbinNumhigh)/h_effNJetsG_EB->Integral(NJetsbinNumlow,NJetsbinNumhigh);
phEffNJets_EC=h_effNJetsG_ECcut->Integral(NJetsbinNumlow,NJetsbinNumhigh)/h_effNJetsG_EC->Integral(NJetsbinNumlow,NJetsbinNumhigh);


float ErrphEffNJets_EB=sqrt(((phEffNJets_EB)*(1-phEffNJets_EB))/h_effNJetsG_EB->Integral(NJetsbinNumlow,NJetsbinNumhigh));
float ErrphEffNJets_EC=sqrt(((phEffNJets_EC)*(1-phEffNJets_EC))/h_effNJetsG_EC->Integral(NJetsbinNumlow,NJetsbinNumhigh));



cout<<"Barrel Photon Efficiency NJets: "<<i<<"to"<<i+1<<" = "<<phEffNJets_EB<<" +- "<<ErrphEffNJets_EB<<endl;
cout<<"Endcap Photon Efficiency NJets: "<<i<<"to"<<i+1<<" = "<<phEffNJets_EC<<" +- "<<ErrphEffNJets_EC<<endl;

pheffNJetsEB<<phEffNJets_EB<<" "<<ErrphEffNJets_EB<<endl;

pheffNJetsEC<<phEffNJets_EC<<" "<<ErrphEffNJets_EC<<endl;


}




//////////////////////////////////NBjets

h_effBJetsG400_EBcut->Scale(0.075604015773398);
h_effBJetsG600_EBcut->Scale(0.0261385093009007);

h_effBJetsG400_ECcut->Scale(0.075604015773398);
h_effBJetsG600_ECcut->Scale(0.0261385093009007);



h_effBJetsG400_EB->Scale(0.075604015773398);
h_effBJetsG600_EB->Scale(0.0261385093009007);

h_effBJetsG400_EC->Scale(0.075604015773398);
h_effBJetsG600_EC->Scale(0.0261385093009007);



h_effBJetsG_EB->Add(h_effBJetsG400_EB);
h_effBJetsG_EB->Add(h_effBJetsG600_EB);

h_effBJetsG_EC->Add(h_effBJetsG400_EC);
h_effBJetsG_EC->Add(h_effBJetsG600_EC);


h_effBJetsG_EBcut->Add(h_effBJetsG400_EBcut);
h_effBJetsG_EBcut->Add(h_effBJetsG600_EBcut);

h_effBJetsG_ECcut->Add(h_effBJetsG400_ECcut);
h_effBJetsG_ECcut->Add(h_effBJetsG600_ECcut);




////////////////////////////////////////////




TAxis *xaxisBJets_EB =h_effBJetsG_EB->GetXaxis();

TAxis *xaxisBJets_EC =h_effBJetsG_EC->GetXaxis();

float phEffBJets_EB=0;
float phEffBJets_EC=0;




fstream pheffBJetsEB;

fstream pheffBJetsEC;

pheffBJetsEB.open(BJetsEBtxt,ios::out|ios::trunc);

pheffBJetsEC.open(BJetsECtxt,ios::out|ios::trunc);


for(int i=0;i<4;i++){


int BJetsbinNumlow=xaxisBJets_EB->FindBin(i);
int BJetsbinNumhigh=xaxisBJets_EB->FindBin(i+1);


phEffBJets_EB=h_effBJetsG_EBcut->Integral(BJetsbinNumlow,BJetsbinNumhigh)/h_effBJetsG_EB->Integral(BJetsbinNumlow,BJetsbinNumhigh);
phEffBJets_EC=h_effBJetsG_ECcut->Integral(BJetsbinNumlow,BJetsbinNumhigh)/h_effBJetsG_EC->Integral(BJetsbinNumlow,BJetsbinNumhigh);


float ErrphEffBJets_EB=sqrt(((phEffBJets_EB)*(1-phEffBJets_EB))/h_effBJetsG_EB->Integral(BJetsbinNumlow,BJetsbinNumhigh));
float ErrphEffBJets_EC=sqrt(((phEffBJets_EC)*(1-phEffBJets_EC))/h_effBJetsG_EC->Integral(BJetsbinNumlow,BJetsbinNumhigh));



cout<<"Barrel Photon Efficiency BJets: "<<i<<"to"<<i+1<<" = "<<phEffBJets_EB<<" +- "<<ErrphEffBJets_EB<<endl;
cout<<"Endcap Photon Efficiency BJets: "<<i<<"to"<<i+1<<" = "<<phEffBJets_EC<<" +- "<<ErrphEffBJets_EC<<endl;



pheffBJetsEB<<phEffBJets_EB<<" "<<ErrphEffBJets_EB<<endl;

pheffBJetsEC<<phEffBJets_EC<<" "<<ErrphEffBJets_EC<<endl;




}



/////////calculation ends


}//main programme
