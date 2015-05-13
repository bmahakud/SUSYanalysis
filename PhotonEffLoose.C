#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "photon.cc"
#include "TChain.h"
#include "computeBin.C" 
#include "TString.h"
#include "TLorentzVector.h"
#include <vector>
#include <iostream>
using namespace std;
void PhotonEffEgammaLoose(){



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

gROOT->ProcessLine(".L tdrstyle.C");
setTDRStyle();

 TChain* tG400 = new TChain("TreeMaker2/PreSelection");
  tG400->Add("NtuplesAll/PHYS14.GJets_HT-400to600_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");

 
 TChain* tG600 = new TChain("TreeMaker2/PreSelection");
 tG600->Add("NtuplesAll/PHYS14.GJets_HT-600toInf_Tune4C_13TeV-madgraph-tauola_*_RA2AnalysisTree.root");



   Int_t           NVtxG400;
   Int_t           isoTracksG400 ;
   Int_t           LeptonsG400;
   Int_t           LeptonsNoMiniIsolationG400 ;
   Int_t           NJetsG400 ;
   Int_t           BTagsG400 ;
   Int_t           PhotonsG400 ;
   Int_t           NJetsNoPhotonsG400 ;
   Float_t         WeightG400 ;
   Float_t         HTG400 ;
   Float_t         MHTG400 ;
   Float_t         DeltaPhi1G400 ;
   Float_t         DeltaPhi2G400 ;
   Float_t         DeltaPhi3G400 ;
   Float_t         minDeltaPhiNG400 ;
   Float_t         DeltaPhiN1G400 ;
   Float_t         DeltaPhiN2G400 ;
   Float_t         DeltaPhiN3G400 ;
   Float_t         METPtG400 ;
   Float_t         METPhiG400 ;
   Float_t         minDeltaPhiG400 ;
   Float_t         ak1p2Jets_sumJetMassG400 ;
   Float_t         HTnoPhotonsG400 ;
   Float_t         MHTnoPhotonsG400 ;
   Float_t         DeltaPhi1noPhotonsG400 ;
   Float_t         DeltaPhi2noPhotonsG400 ;
   Float_t         DeltaPhi3noPhotonsG400 ;
   Float_t         DeltaPhiN1noPhotonsG400 ;
   Float_t         DeltaPhiN2noPhotonsG400 ;
   Float_t         DeltaPhiN3noPhotonsG400 ;
   Float_t         minDeltaPhiNnoPhotonsG400 ;
   Float_t         METnoPhotonsPtG400 ;
   Float_t         METnoPhotonsPhiG400 ;
   UShort_t        MuonsNumG400 ;
   Float_t         MuonsPtG400 [2];   //[MuonsNum]
   Float_t         MuonsEtaG400 [2];   //[MuonsNum]
   Float_t         MuonsPhiG400 [2];   //[MuonsNum]
   Float_t         MuonsEG400 [2];   //[MuonsNum]
   UShort_t        ElectronsNumG400 ;
   Float_t         ElectronsPtG400 [2];   //[ElectronsNum]
   Float_t         ElectronsEtaG400 [2];   //[ElectronsNum]
   Float_t         ElectronsPhiG400 [2];   //[ElectronsNum]
   Float_t         ElectronsEG400 [2];   //[ElectronsNum]
   vector<int>     *genParticles_PDGidG400 ;
   vector<int>     *genParticles_parentG400 ;
   vector<int>     *ak1p2Jets_nSubjetsG400 ;
   vector<int>     *ak4Jets_passedJetIDG400 ;
   vector<int>     *ak4Jets_chargedHadMultG400 ;
   vector<int>     *ak4Jets_neutralHadMultG400 ;
   vector<int>     *ak4Jets_photonMultG400 ;
   vector<int>     *ak4Jets_flavorG400 ;
   vector<int>     *ak4JetsRaw_chargedHadMultG400 ;
   vector<int>     *ak4JetsRaw_neutralHadMultG400 ;
   vector<int>     *ak4JetsRaw_photonMultG400 ;
   vector<int>     *ak4JetsRaw_flavorG400 ;
   vector<double>  *deltaPhiNG400 ;
   vector<double>  *photon_isEBG400 ;
   vector<double>  *photon_genMatchedG400 ;
   vector<double>  *photon_hadTowOverEMG400 ;
   vector<double>  *photon_hasPixelSeedG400 ;
   vector<double>  *photon_pfChargedIsoG400 ;
   vector<double>  *photon_pfChargedIsoRhoCorrG400 ;
   vector<double>  *photon_pfGammaIsoG400 ;
   vector<double>  *photon_pfGammaIsoRhoCorrG400 ;
   vector<double>  *photon_pfNeutralIsoG400 ;
   vector<double>  *photon_pfNeutralIsoRhoCorrG400 ;
   vector<double>  *photon_sigmaIetaIetaG400 ;
  
   vector<double>  *ak4Jets_CSVdiscG400;
   vector<double>  *ak4Jets_chargeHadEfracG400;
   vector<double>  *ak4Jets_neutralHadEfracG400;
   vector<double>  *ak4Jets_photonEfracG400;
   vector<double>  *ak4JetsRaw_CSVdiscG400;
   vector<double>  *ak4JetsRaw_chargeHadEfracG400;
   vector<double>  *ak4JetsRaw_neutralHadEfracG400;
   vector<double>  *ak4JetsRaw_photonEfracG400;
   vector<TLorentzVector> *genParticlesG400;
   vector<TLorentzVector> *photonProdG400;
   vector<TLorentzVector> *ak1p2JetsG400;
   vector<TLorentzVector> *ak4JetsG400;
   vector<TLorentzVector> *ak4JetsRawG400;
   vector<TLorentzVector> *bestPhotonG400;
   vector<TLorentzVector> *ak4JetsNoPhotonsG400;
   vector<TLorentzVector> *ak4GenJetsG400;

   Int_t           NVtxG600 ;
   Int_t           isoTracksG600 ;
   Int_t           LeptonsG600;
   Int_t           LeptonsNoMiniIsolationG600 ;
   Int_t           NJetsG600 ;
   Int_t           BTagsG600 ;
   Int_t           PhotonsG600 ;
   Int_t           NJetsNoPhotonsG600 ;
   Float_t         WeightG600 ;
   Float_t         HTG600 ;
   Float_t         MHTG600 ;
   Float_t         DeltaPhi1G600 ;
   Float_t         DeltaPhi2G600 ;
   Float_t         DeltaPhi3G600 ;
   Float_t         minDeltaPhiNG600 ;
   Float_t         DeltaPhiN1G600 ;
   Float_t         DeltaPhiN2G600 ;
   Float_t         DeltaPhiN3G600 ;
   Float_t         METPtG600 ;
   Float_t         METPhiG600 ;
   Float_t         minDeltaPhiG600 ;
   Float_t         ak1p2Jets_sumJetMassG600 ;
   Float_t         HTnoPhotonsG600 ;
   Float_t         MHTnoPhotonsG600 ;
   Float_t         DeltaPhi1noPhotonsG600 ;
   Float_t         DeltaPhi2noPhotonsG600 ;
   Float_t         DeltaPhi3noPhotonsG600 ;
   Float_t         DeltaPhiN1noPhotonsG600 ;
   Float_t         DeltaPhiN2noPhotonsG600 ;
   Float_t         DeltaPhiN3noPhotonsG600 ;
   Float_t         minDeltaPhiNnoPhotonsG600 ;
   Float_t         METnoPhotonsPtG600 ;
   Float_t         METnoPhotonsPhiG600 ;
   UShort_t        MuonsNumG600 ;
   Float_t         MuonsPtG600 [2];   //[MuonsNum]
   Float_t         MuonsEtaG600 [2];   //[MuonsNum]
   Float_t         MuonsPhiG600 [2];   //[MuonsNum]
   Float_t         MuonsEG600 [2];   //[MuonsNum]
   UShort_t        ElectronsNumG600 ;
   Float_t         ElectronsPtG600 [2];   //[ElectronsNum]
   Float_t         ElectronsEtaG600 [2];   //[ElectronsNum]
   Float_t         ElectronsPhiG600 [2];   //[ElectronsNum]
   Float_t         ElectronsEG600 [2];   //[ElectronsNum]
   vector<int>     *genParticles_PDGidG600 ;
   vector<int>     *genParticles_parentG600 ;
   vector<int>     *ak1p2Jets_nSubjetsG600 ;
   vector<int>     *ak4Jets_passedJetIDG600 ;
   vector<int>     *ak4Jets_chargedHadMultG600 ;
   vector<int>     *ak4Jets_neutralHadMultG600 ;
   vector<int>     *ak4Jets_photonMultG600 ;
   vector<int>     *ak4Jets_flavorG600 ;
   vector<int>     *ak4JetsRaw_chargedHadMultG600 ;
   vector<int>     *ak4JetsRaw_neutralHadMultG600 ;
   vector<int>     *ak4JetsRaw_photonMultG600 ;
   vector<int>     *ak4JetsRaw_flavorG600 ;
   vector<double>  *deltaPhiNG600 ;
   vector<double>  *photon_isEBG600 ;
   vector<double>  *photon_genMatchedG600 ;
   vector<double>  *photon_hadTowOverEMG600 ;
   vector<double>  *photon_hasPixelSeedG600 ;
   vector<double>  *photon_pfChargedIsoG600 ;
   vector<double>  *photon_pfChargedIsoRhoCorrG600 ;
   vector<double>  *photon_pfGammaIsoG600 ;
   vector<double>  *photon_pfGammaIsoRhoCorrG600 ;
   vector<double>  *photon_pfNeutralIsoG600 ;
   vector<double>  *photon_pfNeutralIsoRhoCorrG600 ;
   vector<double>  *photon_sigmaIetaIetaG600 ;
  
   vector<double>  *ak4Jets_CSVdiscG600;
   vector<double>  *ak4Jets_chargeHadEfracG600;
   vector<double>  *ak4Jets_neutralHadEfracG600;
   vector<double>  *ak4Jets_photonEfracG600;
   vector<double>  *ak4JetsRaw_CSVdiscG600;
   vector<double>  *ak4JetsRaw_chargeHadEfracG600;
   vector<double>  *ak4JetsRaw_neutralHadEfracG600;
   vector<double>  *ak4JetsRaw_photonEfracG600;
   vector<TLorentzVector> *genParticlesG600;
   vector<TLorentzVector> *photonProdG600;
   vector<TLorentzVector> *ak1p2JetsG600;
   vector<TLorentzVector> *ak4JetsG600;
   vector<TLorentzVector> *ak4JetsRawG600;
   vector<TLorentzVector> *bestPhotonG600;
   vector<TLorentzVector> *ak4JetsNoPhotonsG600;
   vector<TLorentzVector> *ak4GenJetsG600;



  
  
   tG400->SetBranchAddress("NVtx", &NVtxG400);
   tG400->SetBranchAddress("isoTracks", &isoTracksG400);
   tG400->SetBranchAddress("Leptons", &LeptonsG400);
   tG400->SetBranchAddress("LeptonsNoMiniIsolation", &LeptonsNoMiniIsolationG400);
   tG400->SetBranchAddress("NJets", &NJetsG400);
   tG400->SetBranchAddress("BTags", &BTagsG400);
   tG400->SetBranchAddress("Photons", &PhotonsG400);
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
   tG400->SetBranchAddress("minDeltaPhi", &minDeltaPhiG400);
   tG400->SetBranchAddress("ak1p2Jets_sumJetMass", &ak1p2Jets_sumJetMassG400);
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
   tG400->SetBranchAddress("MuonsNum", &MuonsNumG400);
   tG400->SetBranchAddress("MuonsPt", &MuonsPtG400);
   tG400->SetBranchAddress("MuonsEta", &MuonsEtaG400);
   tG400->SetBranchAddress("MuonsPhi", &MuonsPhiG400);
   tG400->SetBranchAddress("MuonsE", &MuonsEG400);
   tG400->SetBranchAddress("ElectronsNum", &ElectronsNumG400);
   tG400->SetBranchAddress("ElectronsPt", &ElectronsPtG400);
   tG400->SetBranchAddress("ElectronsEta", &ElectronsEtaG400);
   tG400->SetBranchAddress("ElectronsPhi", &ElectronsPhiG400);
   tG400->SetBranchAddress("ElectronsE", &ElectronsEG400);
   tG400->SetBranchAddress("genParticles_PDGid", &genParticles_PDGidG400);
   tG400->SetBranchAddress("genParticles_parent", &genParticles_parentG400);
   tG400->SetBranchAddress("ak1p2Jets_nSubjets", &ak1p2Jets_nSubjetsG400);
   tG400->SetBranchAddress("ak4Jets_passedJetID", &ak4Jets_passedJetIDG400);
   tG400->SetBranchAddress("ak4Jets_chargedHadMult", &ak4Jets_chargedHadMultG400);
   tG400->SetBranchAddress("ak4Jets_neutralHadMult", &ak4Jets_neutralHadMultG400);
   tG400->SetBranchAddress("ak4Jets_photonMult", &ak4Jets_photonMultG400);
   tG400->SetBranchAddress("ak4Jets_flavor", &ak4Jets_flavorG400);
   tG400->SetBranchAddress("ak4JetsRaw_chargedHadMult", &ak4JetsRaw_chargedHadMultG400);
   tG400->SetBranchAddress("ak4JetsRaw_neutralHadMult", &ak4JetsRaw_neutralHadMultG400);
   tG400->SetBranchAddress("ak4JetsRaw_photonMult", &ak4JetsRaw_photonMultG400);
   tG400->SetBranchAddress("ak4JetsRaw_flavor", &ak4JetsRaw_flavorG400);
   tG400->SetBranchAddress("deltaPhiN", &deltaPhiNG400);
   tG400->SetBranchAddress("photon_isEB", &photon_isEBG400);
   tG400->SetBranchAddress("photon_genMatched", &photon_genMatchedG400);
   tG400->SetBranchAddress("photon_hadTowOverEM", &photon_hadTowOverEMG400);
   tG400->SetBranchAddress("photon_hasPixelSeed", &photon_hasPixelSeedG400);
   tG400->SetBranchAddress("photon_pfChargedIso", &photon_pfChargedIsoG400);
   tG400->SetBranchAddress("photon_pfChargedIsoRhoCorr", &photon_pfChargedIsoRhoCorrG400);
   tG400->SetBranchAddress("photon_pfGammaIso", &photon_pfGammaIsoG400);
   tG400->SetBranchAddress("photon_pfGammaIsoRhoCorr", &photon_pfGammaIsoRhoCorrG400);
   tG400->SetBranchAddress("photon_pfNeutralIso", &photon_pfNeutralIsoG400);
   tG400->SetBranchAddress("photon_pfNeutralIsoRhoCorr", &photon_pfNeutralIsoRhoCorrG400);
   tG400->SetBranchAddress("photon_sigmaIetaIeta", &photon_sigmaIetaIetaG400);
  
   tG400->SetBranchAddress("ak4Jets_CSVdisc", &ak4Jets_CSVdiscG400);
   tG400->SetBranchAddress("ak4Jets_chargeHadEfrac", &ak4Jets_chargeHadEfracG400);
   tG400->SetBranchAddress("ak4Jets_neutralHadEfrac", &ak4Jets_neutralHadEfracG400);
   tG400->SetBranchAddress("ak4Jets_photonEfrac", &ak4Jets_photonEfracG400);
   tG400->SetBranchAddress("ak4JetsRaw_CSVdisc", &ak4JetsRaw_CSVdiscG400);
   tG400->SetBranchAddress("ak4JetsRaw_chargeHadEfrac", &ak4JetsRaw_chargeHadEfracG400);
   tG400->SetBranchAddress("ak4JetsRaw_neutralHadEfrac", &ak4JetsRaw_neutralHadEfracG400);
   tG400->SetBranchAddress("ak4JetsRaw_photonEfrac", &ak4JetsRaw_photonEfracG400);
   tG400->SetBranchAddress("genParticles", &genParticlesG400);
   tG400->SetBranchAddress("photonProd", &photonProdG400);
   tG400->SetBranchAddress("ak1p2Jets", &ak1p2JetsG400);
   tG400->SetBranchAddress("ak4Jets", &ak4JetsG400);
   tG400->SetBranchAddress("ak4JetsRaw", &ak4JetsRawG400);
   tG400->SetBranchAddress("bestPhoton", &bestPhotonG400);
   tG400->SetBranchAddress("ak4JetsNoPhotons", &ak4JetsNoPhotonsG400);
   tG400->SetBranchAddress("ak4GenJets", &ak4GenJetsG400);


   
   tG600->SetBranchAddress("NVtx", &NVtxG600);
   tG600->SetBranchAddress("isoTracks", &isoTracksG600);
   tG600->SetBranchAddress("Leptons", &LeptonsG600);
   tG600->SetBranchAddress("LeptonsNoMiniIsolation", &LeptonsNoMiniIsolationG600);
   tG600->SetBranchAddress("NJets", &NJetsG600);
   tG600->SetBranchAddress("BTags", &BTagsG600);
   tG600->SetBranchAddress("Photons", &PhotonsG600);
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
   tG600->SetBranchAddress("minDeltaPhi", &minDeltaPhiG600);
   tG600->SetBranchAddress("ak1p2Jets_sumJetMass", &ak1p2Jets_sumJetMassG600);
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
   tG600->SetBranchAddress("MuonsNum", &MuonsNumG600);
   tG600->SetBranchAddress("MuonsPt", &MuonsPtG600);
   tG600->SetBranchAddress("MuonsEta", &MuonsEtaG600);
   tG600->SetBranchAddress("MuonsPhi", &MuonsPhiG600);
   tG600->SetBranchAddress("MuonsE", &MuonsEG600);
   tG600->SetBranchAddress("ElectronsNum", &ElectronsNumG600);
   tG600->SetBranchAddress("ElectronsPt", &ElectronsPtG600);
   tG600->SetBranchAddress("ElectronsEta", &ElectronsEtaG600);
   tG600->SetBranchAddress("ElectronsPhi", &ElectronsPhiG600);
   tG600->SetBranchAddress("ElectronsE", &ElectronsEG600);
   tG600->SetBranchAddress("genParticles_PDGid", &genParticles_PDGidG600);
   tG600->SetBranchAddress("genParticles_parent", &genParticles_parentG600);
   tG600->SetBranchAddress("ak1p2Jets_nSubjets", &ak1p2Jets_nSubjetsG600);
   tG600->SetBranchAddress("ak4Jets_passedJetID", &ak4Jets_passedJetIDG600);
   tG600->SetBranchAddress("ak4Jets_chargedHadMult", &ak4Jets_chargedHadMultG600);
   tG600->SetBranchAddress("ak4Jets_neutralHadMult", &ak4Jets_neutralHadMultG600);
   tG600->SetBranchAddress("ak4Jets_photonMult", &ak4Jets_photonMultG600);
   tG600->SetBranchAddress("ak4Jets_flavor", &ak4Jets_flavorG600);
   tG600->SetBranchAddress("ak4JetsRaw_chargedHadMult", &ak4JetsRaw_chargedHadMultG600);
   tG600->SetBranchAddress("ak4JetsRaw_neutralHadMult", &ak4JetsRaw_neutralHadMultG600);
   tG600->SetBranchAddress("ak4JetsRaw_photonMult", &ak4JetsRaw_photonMultG600);
   tG600->SetBranchAddress("ak4JetsRaw_flavor", &ak4JetsRaw_flavorG600);
   tG600->SetBranchAddress("deltaPhiN", &deltaPhiNG600);
   tG600->SetBranchAddress("photon_isEB", &photon_isEBG600);
   tG600->SetBranchAddress("photon_genMatched", &photon_genMatchedG600);
   tG600->SetBranchAddress("photon_hadTowOverEM", &photon_hadTowOverEMG600);
   tG600->SetBranchAddress("photon_hasPixelSeed", &photon_hasPixelSeedG600);
   tG600->SetBranchAddress("photon_pfChargedIso", &photon_pfChargedIsoG600);
   tG600->SetBranchAddress("photon_pfChargedIsoRhoCorr", &photon_pfChargedIsoRhoCorrG600);
   tG600->SetBranchAddress("photon_pfGammaIso", &photon_pfGammaIsoG600);
   tG600->SetBranchAddress("photon_pfGammaIsoRhoCorr", &photon_pfGammaIsoRhoCorrG600);
   tG600->SetBranchAddress("photon_pfNeutralIso", &photon_pfNeutralIsoG600);
   tG600->SetBranchAddress("photon_pfNeutralIsoRhoCorr", &photon_pfNeutralIsoRhoCorrG600);
   tG600->SetBranchAddress("photon_sigmaIetaIeta", &photon_sigmaIetaIetaG600);
  
   tG600->SetBranchAddress("ak4Jets_CSVdisc", &ak4Jets_CSVdiscG600);
   tG600->SetBranchAddress("ak4Jets_chargeHadEfrac", &ak4Jets_chargeHadEfracG600);
   tG600->SetBranchAddress("ak4Jets_neutralHadEfrac", &ak4Jets_neutralHadEfracG600);
   tG600->SetBranchAddress("ak4Jets_photonEfrac", &ak4Jets_photonEfracG600);
   tG600->SetBranchAddress("ak4JetsRaw_CSVdisc", &ak4JetsRaw_CSVdiscG600);
   tG600->SetBranchAddress("ak4JetsRaw_chargeHadEfrac", &ak4JetsRaw_chargeHadEfracG600);
   tG600->SetBranchAddress("ak4JetsRaw_neutralHadEfrac", &ak4JetsRaw_neutralHadEfracG600);
   tG600->SetBranchAddress("ak4JetsRaw_photonEfrac", &ak4JetsRaw_photonEfracG600);
   tG600->SetBranchAddress("genParticles", &genParticlesG600);
   tG600->SetBranchAddress("photonProd", &photonProdG600);
   tG600->SetBranchAddress("ak1p2Jets", &ak1p2JetsG600);
   tG600->SetBranchAddress("ak4Jets", &ak4JetsG600);
   tG600->SetBranchAddress("ak4JetsRaw", &ak4JetsRawG600);
   tG600->SetBranchAddress("bestPhoton", &bestPhotonG600);
   tG600->SetBranchAddress("ak4JetsNoPhotons", &ak4JetsNoPhotonsG600);
   tG600->SetBranchAddress("ak4GenJets", &ak4GenJetsG600);


TH1F *h_HTG400=new TH1F("h_HTG400","400HT600",300,0,3000);
TH1F *h_HTG600=new TH1F("h_HTG600","600HTInf",300,0,3000);
TH1F *h_HTG=new TH1F("h_HTG","400HTInf",300,0,3000);
h_HTG->SetLineWidth(2);
h_HTG->GetXaxis()->SetTitle("HT");
h_HTG->GetYaxis()->SetTitle("Events");
h_HTG->SetLineColor(2);


TH1F *h_MHTG400=new TH1F("h_MHTG400","MHT_400HT600",300,0,3000);
TH1F *h_MHTG600=new TH1F("h_MHTG600","MHT_600HTInf",300,0,3000);
TH1F *h_MHTG=new TH1F("h_MHTG","MHT_400HTInf",300,0,3000);
h_MHTG->SetLineWidth(2);
h_MHTG->GetXaxis()->SetTitle("MHT");
h_MHTG->GetYaxis()->SetTitle("Events");
h_MHTG->SetLineColor(2);

TH1F *h_NJetsG400=new TH1F("h_NJetsG400","NJets_400HT600",20,0,20);
TH1F *h_NJetsG600=new TH1F("h_NJetsG600","NJets_600HTInf",20,0,20);
TH1F *h_NJetsG=new TH1F("h_NJetsG","NJets_400HTInf",20,0,20);
h_NJetsG->SetLineWidth(2);
h_NJetsG->GetXaxis()->SetTitle("NJets");
h_NJetsG->GetYaxis()->SetTitle("Events");
h_NJetsG->SetLineColor(2);

TH1F *h_minDPhiNG400=new TH1F("h_minDPhiNG400","minDPhiN_400HT600",180,0,60);
TH1F *h_minDPhiNG600=new TH1F("h_minDPhiNG600","minDPhiN_600HTInf",180,0,60);
TH1F *h_minDPhiNG=new TH1F("h_minDPhiNG","minDPhiN_400HTInf",180,0,60);
h_minDPhiNG->SetLineWidth(2);
h_minDPhiNG->GetXaxis()->SetTitle("#Delta #Phi_{min}");
h_minDPhiNG->GetYaxis()->SetTitle("Events");
h_minDPhiNG->SetLineColor(2);

TH1F *h_PhpTG400=new TH1F("h_PhpTG400","PhotonpTG400",200,0,2000);
TH1F *h_PhpTG600=new TH1F("h_PhpTG600","PhotonpTG600",200,0,2000);
TH1F *h_PhpTG=new TH1F("h_PhpTG","PhotonpTG",200,0,2000);
h_PhpTG->SetLineWidth(2);
h_PhpTG->GetXaxis()->SetTitle("#gamma p_{T}");
h_PhpTG->GetYaxis()->SetTitle("Events");
h_PhpTG->SetLineColor(2);


//////////////////////////////Barrel///////////////////////
TH1F *h_HadToEMG400EB=new TH1F("h_HadToEMG400EB","400HadOverEM600",100,0,0.17);
TH1F *h_HadToEMG600EB=new TH1F("h_HadToEMG600EB","600HadOverEMInf",100,0,0.17);
TH1F *h_HadToEMGEB=new TH1F("h_HadToEMGEB","400HadOverEMInf",100,0,0.17);
h_HadToEMGEB->SetLineWidth(2);
h_HadToEMGEB->GetXaxis()->SetTitle("E_{had}/E_{em}");
h_HadToEMGEB->GetYaxis()->SetTitle("Events");
h_HadToEMGEB->SetLineColor(2);
TH1F *h_PixelSG400EB=new TH1F("h_PixelSG400EB","400PixelS600",20,0,2);
TH1F *h_PixelSG600EB=new TH1F("h_PixelSG600EB","600PixelSInf",20,0,2);
TH1F *h_PixelSGEB=new TH1F("h_PixelSG","400PixelSInf",20,0,2);
h_PixelSGEB->SetLineWidth(2);
h_PixelSGEB->GetXaxis()->SetTitle("PixelSeed");
h_PixelSGEB->GetYaxis()->SetTitle("Events");
h_PixelSGEB->SetLineColor(2);


TH1F *h_HadToEMG400EB_cut=new TH1F("h_HadToEMG400EB_cut","400HadOverEM600",100,0,0.17);
TH1F *h_HadToEMG600EB_cut=new TH1F("h_HadToEMG600EB_cut","600HadOverEMInf",100,0,0.17);
TH1F *h_HadToEMGEB_cut=new TH1F("h_HadToEMGEB_cut","400HadOverEMInf",100,0,0.17);
h_HadToEMGEB_cut->SetLineWidth(2);
h_HadToEMGEB_cut->GetXaxis()->SetTitle("E_{had}/E_{em}");
h_HadToEMGEB_cut->GetYaxis()->SetTitle("Events");
h_HadToEMGEB_cut->SetLineColor(2);
TH1F *h_PixelSG400EB_cut=new TH1F("h_PixelSG400EB_cut","400PixelS600",20,0,2);
TH1F *h_PixelSG600EB_cut=new TH1F("h_PixelSG600EB_cut","600PixelSInf",20,0,2);
TH1F *h_PixelSGEB_cut=new TH1F("h_PixelSGEB_cut","400PixelSInf",20,0,2);
h_PixelSGEB_cut->SetLineWidth(2);
h_PixelSGEB_cut->GetXaxis()->SetTitle("PixelSeed");
h_PixelSGEB_cut->GetYaxis()->SetTitle("Events");
h_PixelSGEB_cut->SetLineColor(2);

////////////////////////////Barrel////////////////////////////




////////////////////////////////Endcap


TH1F *h_HadToEMG400EC=new TH1F("h_HadToEMG400EC","400HadOverEM600",100,0,0.17);
TH1F *h_HadToEMG600EC=new TH1F("h_HadToEMG600EC","600HadOverEMInf",100,0,0.17);
TH1F *h_HadToEMGEC=new TH1F("h_HadToEMGEC","400HadOverEMInf",100,0,0.17);
h_HadToEMGEC->SetLineWidth(2);
h_HadToEMGEC->GetXaxis()->SetTitle("E_{had}/E_{em}");
h_HadToEMGEC->GetYaxis()->SetTitle("Events");
h_HadToEMGEC->SetLineColor(2);
TH1F *h_PixelSG400EC=new TH1F("h_PixelSG400EC","400PixelS600",20,0,2);
TH1F *h_PixelSG600EC=new TH1F("h_PixelSG600EC","600PixelSInf",20,0,2);
TH1F *h_PixelSGEC=new TH1F("h_PixelSC","400PixelSInf",20,0,2);
h_PixelSGEC->SetLineWidth(2);
h_PixelSGEC->GetXaxis()->SetTitle("PixelSeed");
h_PixelSGEC->GetYaxis()->SetTitle("Events");
h_PixelSGEC->SetLineColor(2);


TH1F *h_HadToEMG400EC_cut=new TH1F("h_HadToEMG400EC_cut","400HadOverEM600",100,0,0.17);
TH1F *h_HadToEMG600EC_cut=new TH1F("h_HadToEMG600EC_cut","600HadOverEMInf",100,0,0.17);
TH1F *h_HadToEMGEC_cut=new TH1F("h_HadToEMGEC_cut","400HadOverEMInf",100,0,0.17);
h_HadToEMGEC_cut->SetLineWidth(2);
h_HadToEMGEC_cut->GetXaxis()->SetTitle("E_{had}/E_{em}");
h_HadToEMGEC_cut->GetYaxis()->SetTitle("Events");
h_HadToEMGEC_cut->SetLineColor(2);

TH1F *h_PixelSG400EC_cut=new TH1F("h_PixelSG400EC_cut","400PixelS600",20,0,2);
TH1F *h_PixelSG600EC_cut=new TH1F("h_PixelSG600EC_cut","600PixelSInf",20,0,2);
TH1F *h_PixelSGEC_cut=new TH1F("h_PixelSGEC_cut","400PixelSInf",20,0,2);
h_PixelSGEC_cut->SetLineWidth(2);
h_PixelSGEC_cut->GetXaxis()->SetTitle("PixelSeed");
h_PixelSGEC_cut->GetYaxis()->SetTitle("Events");
h_PixelSGEC_cut->SetLineColor(2);





//////////////////////////////Endcap



///+++++++++++++++++++++++++++++++++++



//////////////////////////////////////////////////Histograms before cut  start
//Barrel Photon
TH1F *h_SIetaG400EB=new TH1F("h_SIetaG400EB","400SIetaIeta600",70,0,0.07);
TH1F *h_SIetaG600EB=new TH1F("h_IetaG600EB","600SIetaIetaInf",70,0,0.07);
TH1F *h_SIetaGEB=new TH1F("h_IetaGEB","400SIetaIetaInf",70,0,0.07);

h_SIetaGEB->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
h_SIetaGEB->GetYaxis()->SetTitle("Events");
h_SIetaGEB->SetLineColor(2);
h_SIetaGEB->SetFillColor(2);

TH1F *h_pfChIsoG400EB=new TH1F("h_pfChIsoG400EB","400pfChIsoRhoCorr600",4000,0,500);
TH1F *h_pfChIsoG600EB=new TH1F("h_pfChIsoG600EB","600pfChIsoRhoCorrInf",4000,0,500);
TH1F *h_pfChIsoGEB=new TH1F("h_pfChIsoGEB","400pfChIsoRhoCorrInf",4000,0,500);

h_pfChIsoGEB->GetXaxis()->SetTitle("pfChargedIsolationRhoCorr");
h_pfChIsoGEB->GetYaxis()->SetTitle("Events");
h_pfChIsoGEB->SetLineColor(2);
h_pfChIsoGEB->SetFillColor(2);



TH1F *h_pfNIsoG400EB=new TH1F("h_pfNIsoG400EB","400pfNIsoRhoCorr600",2000,0,500);
TH1F *h_pfNIsoG600EB=new TH1F("h_pfNIsoG600EB","600pfNIsoRhoCorrInf",2000,0,500);
TH1F *h_pfNIsoGEB=new TH1F("h_pfNIsoGEB","400pfNIsoRhoCorrInf",2000,0,500);

h_pfNIsoGEB->GetXaxis()->SetTitle("pfNeutralIsolationRhoCorr");
h_pfNIsoGEB->GetYaxis()->SetTitle("Events");
h_pfNIsoGEB->SetLineColor(2);
h_pfNIsoGEB->SetFillColor(2);
TH1F *h_pfGammaIsoG400EB=new TH1F("h_pfGammaIsoG400EB","400pfGammaIsoRhoCorr600",2000,0,500);
TH1F *h_pfGammaIsoG600EB=new TH1F("h_pfGammaIsoG600EB","600pfGammaIsoRhoCorrInf",2000,0,500);
TH1F *h_pfGammaIsoGEB=new TH1F("h_pfGammaIsoGEB","400pfGammaIsoRhoCorrInf",2000,0,500);

h_pfGammaIsoGEB->GetXaxis()->SetTitle("pfGammaIsolationRhoCorr");
h_pfGammaIsoGEB->GetYaxis()->SetTitle("Events");
h_pfGammaIsoGEB->SetLineColor(2);
h_pfGammaIsoGEB->SetFillColor(2);


//Endcap Photon

TH1F *h_SIetaG400EC=new TH1F("h_SIetaG400EC","400SIetaIeta600",70,0,0.07);
TH1F *h_SIetaG600EC=new TH1F("h_IetaG600EC","600SIetaIetaInf",70,0,0.07);
TH1F *h_SIetaGEC=new TH1F("h_IetaGEC","400SIetaIetaInf",70,0,0.07);
h_SIetaGEC->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
h_SIetaGEC->GetYaxis()->SetTitle("Events");
h_SIetaGEC->SetLineColor(6);
h_SIetaGEC->SetFillColor(6);


TH1F *h_pfChIsoG400EC=new TH1F("h_pfChIsoG400EC","400pfChIsoRhoCorr600",4000,0,500);
TH1F *h_pfChIsoG600EC=new TH1F("h_pfChIsoG600EC","600pfChIsoRhoCorrInf",4000,0,500);
TH1F *h_pfChIsoGEC=new TH1F("h_pfChIsoGEC","400pfChIsoRhoCorrInf",4000,0,500);
h_pfChIsoGEC->GetXaxis()->SetTitle("pfChargedIsolationRhoCorr");
h_pfChIsoGEC->GetYaxis()->SetTitle("Events");
h_pfChIsoGEC->SetLineColor(6);
h_pfChIsoGEC->SetFillColor(6);

TH1F *h_pfNIsoG400EC=new TH1F("h_pfNIsoG400EC","400pfNIsoRhoCorr600",2000,0,500);
TH1F *h_pfNIsoG600EC=new TH1F("h_pfNIsoG600EC","600pfNIsoRhoCorrInf",2000,0,500);
TH1F *h_pfNIsoGEC=new TH1F("h_pfNIsoGEC","400pfNIsoRhoCorrInf",2000,0,500);
h_pfNIsoGEC->GetXaxis()->SetTitle("pfNeutralIsolationRhoCorr");
h_pfNIsoGEC->GetYaxis()->SetTitle("Events");
h_pfNIsoGEC->SetLineColor(6);
h_pfNIsoGEC->SetFillColor(6);
TH1F *h_pfGammaIsoG400EC=new TH1F("h_pfGammaIsoG400EC","400pfGammaIsoRhoCorr600",2000,0,500);
TH1F *h_pfGammaIsoG600EC=new TH1F("h_pfGammaIsoG600EC","600pfGammaIsoRhoCorrInf",2000,0,500);
TH1F *h_pfGammaIsoGEC=new TH1F("h_pfGammaIsoGEC","400pfGammaIsoRhoCorrInf",2000,0,500);

h_pfGammaIsoGEC->GetXaxis()->SetTitle("pfGammaIsolationRhoCorr");
h_pfGammaIsoGEC->GetYaxis()->SetTitle("Events");
h_pfGammaIsoGEC->SetLineColor(6);
h_pfGammaIsoGEC->SetFillColor(6);
//////////////////////////////Histograms before cut ends here


///////////////////////////////Histograms after cut starts here


//Barrel Photon
TH1F *h_SIetaG400EB_cut=new TH1F("h_SIetaG400EB_cut","400SIetaIeta600",70,0,0.07);
TH1F *h_SIetaG600EB_cut=new TH1F("h_IetaG600EB_cut","600SIetaIetaInf",70,0,0.07);
TH1F *h_SIetaGEB_cut=new TH1F("h_IetaGEB_cut","400SIetaIetaInf",70,0,0.07);

h_SIetaGEB_cut->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
h_SIetaGEB_cut->GetYaxis()->SetTitle("Events");
h_SIetaGEB_cut->SetLineColor(4);
h_SIetaGEB_cut->SetFillColor(4);
TH1F *h_pfChIsoG400EB_cut=new TH1F("h_pfChIsoG400EB_cut","400pfChIsoRhoCorr600",4000,0,500);
TH1F *h_pfChIsoG600EB_cut=new TH1F("h_pfChIsoG600EB_cut","600pfChIsoRhoCorrInf",4000,0,500);
TH1F *h_pfChIsoGEB_cut=new TH1F("h_pfChIsoGEB_cut","400pfChIsoRhoCorrInf",4000,0,500);

h_pfChIsoGEB_cut->GetXaxis()->SetTitle("pfChargedIsolationRhoCorr");
h_pfChIsoGEB_cut->GetYaxis()->SetTitle("Events");
h_pfChIsoGEB_cut->SetLineColor(4);
h_pfChIsoGEB_cut->SetFillColor(4);



TH1F *h_pfNIsoG400EB_cut=new TH1F("h_pfNIsoG400EB_cut","400pfNIsoRhoCorr600",2000,0,500);
TH1F *h_pfNIsoG600EB_cut=new TH1F("h_pfNIsoG600EB_cut","600pfNIsoRhoCorrInf",2000,0,500);
TH1F *h_pfNIsoGEB_cut=new TH1F("h_pfNIsoGEB_cut","400pfNIsoRhoCorrInf",2000,0,500);

h_pfNIsoGEB_cut->GetXaxis()->SetTitle("pfNeutralIsolationRhoCorr");
h_pfNIsoGEB_cut->GetYaxis()->SetTitle("Events");
h_pfNIsoGEB_cut->SetLineColor(4);
h_pfNIsoGEB_cut->SetFillColor(4);
TH1F *h_pfGammaIsoG400EB_cut=new TH1F("h_pfGammaIsoG400EB_cut","400pfGammaIsoRhoCorr600",100,0,500);
TH1F *h_pfGammaIsoG600EB_cut=new TH1F("h_pfGammaIsoG600EB_cut","600pfGammaIsoRhoCorrInf",100,0,500);
TH1F *h_pfGammaIsoGEB_cut=new TH1F("h_pfGammaIsoGEB_cut","400pfGammaIsoRhoCorrInf",100,0,500);

h_pfGammaIsoGEB_cut->GetXaxis()->SetTitle("pfGammaIsolationRhoCorr");
h_pfGammaIsoGEB_cut->GetYaxis()->SetTitle("Events");
h_pfGammaIsoGEB_cut->SetLineColor(4);
h_pfGammaIsoGEB_cut->SetFillColor(4);


//Endcap Photon

TH1F *h_SIetaG400EC_cut=new TH1F("h_SIetaG400EC_cut","400SIetaIeta600",70,0,0.07);
TH1F *h_SIetaG600EC_cut=new TH1F("h_IetaG600EC_cut","600SIetaIetaInf",70,0,0.07);
TH1F *h_SIetaGEC_cut=new TH1F("h_IetaGEC_cut","400SIetaIetaInf",70,0,0.07);
h_SIetaGEC_cut->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
h_SIetaGEC_cut->GetYaxis()->SetTitle("Events");
h_SIetaGEC_cut->SetLineColor(9);
h_SIetaGEC_cut->SetFillColor(9);


TH1F *h_pfChIsoG400EC_cut=new TH1F("h_pfChIsoG400EC_cut","400pfChIsoRhoCorr600",4000,0,500);
TH1F *h_pfChIsoG600EC_cut=new TH1F("h_pfChIsoG600EC_cut","600pfChIsoRhoCorrInf",4000,0,500);
TH1F *h_pfChIsoGEC_cut=new TH1F("h_pfChIsoGEC_cut","400pfChIsoRhoCorrInf",4000,0,500);
h_pfChIsoGEC_cut->GetXaxis()->SetTitle("pfChargedIsolationRhoCorr");
h_pfChIsoGEC_cut->GetYaxis()->SetTitle("Events");
h_pfChIsoGEC_cut->SetLineColor(9);
h_pfChIsoGEC_cut->SetFillColor(9);

TH1F *h_pfNIsoG400EC_cut=new TH1F("h_pfNIsoG400EC_cut","400pfNIsoRhoCorr600",2000,0,500);
TH1F *h_pfNIsoG600EC_cut=new TH1F("h_pfNIsoG600EC_cut","600pfNIsoRhoCorrInf",2000,0,500);
TH1F *h_pfNIsoGEC_cut=new TH1F("h_pfNIsoGEC_cut","400pfNIsoRhoCorrInf",2000,0,500);
h_pfNIsoGEC_cut->GetXaxis()->SetTitle("pfNeutralIsolationRhoCorr");
h_pfNIsoGEC_cut->GetYaxis()->SetTitle("Events");
h_pfNIsoGEC_cut->SetLineColor(9);
h_pfNIsoGEC_cut->SetFillColor(9);
TH1F *h_pfGammaIsoG400EC_cut=new TH1F("h_pfGammaIsoG400EC_cut","400pfGammaIsoRhoCorr600",2000,0,500);
TH1F *h_pfGammaIsoG600EC_cut=new TH1F("h_pfGammaIsoG600EC_cut","600pfGammaIsoRhoCorrInf",2000,0,500);
TH1F *h_pfGammaIsoGEC_cut=new TH1F("h_pfGammaIsoGEC_cut","400pfGammaIsoRhoCorrInf",2000,0,500);

h_pfGammaIsoGEC_cut->GetXaxis()->SetTitle("pfGammaIsolationRhoCorr");
h_pfGammaIsoGEC_cut->GetYaxis()->SetTitle("Events");
h_pfGammaIsoGEC_cut->SetLineColor(9);
h_pfGammaIsoGEC_cut->SetFillColor(9);




TH1F *h_effHTG400_EB=new TH1F("h_effHTG400_EB","h_effT",300,0,3000);
TH1F *h_effHTG400_EC=new TH1F("h_effHTG400_EC","h_effT",300,0,3000);
TH1F *h_effHTG600_EB=new TH1F("h_effHTG600_EB","h_effT",300,0,3000);
TH1F *h_effHTG600_EC=new TH1F("h_effHTG600_EC","h_effT",300,0,3000);

TH1F *h_effHT_EB=new TH1F("h_effHT_EB","h_effT",300,0,3000);
TH1F *h_effHT_EC=new TH1F("h_effHT_EC","h_effT",300,0,3000);

TH1F *h_effHT_EBcut=new TH1F("h_effHT_EBcut","h_effT",300,0,3000);
TH1F *h_effHT_ECcut=new TH1F("h_effHT_ECcut","h_effT",300,0,3000);

int totalEBG400=0;
int totalECG400=0;
int totalEBG600=0;
int totalECG600=0;


int totalcutEBG400=0;
int totalcutECG400=0;
int totalcutEBG600=0;
int totalcutECG600=0;




//////////////////////////////Histograms after cut ends here

int NumEvents=1000000;


for( int iEv1 = 0 ; iEv1<tG400->GetEntries(); iEv1++){//event loopGJets 400HTInf
tG400->GetEntry(iEv1);
if( iEv1 % 5000 == 0 ) cout << "event : " << iEv1 << endl;
if(iEv1==NumEvents)break;

if(HTnoPhotonsG400 > 500 && MHTnoPhotonsG400 >200 && NJetsNoPhotonsG400 >= 4  && LeptonsG400==0 && minDeltaPhiNnoPhotonsG400 > 6.){//base line conditions


for(int iPh=0;iPh<photon_genMatchedG400->size();iPh++){//photon loop
if(photon_genMatchedG400->at(iPh) ==1){//gen match condition
if(photonProdG400->at(iPh).Pt() > 100.){//Photon pT > 100 GeV


h_HTG400->Fill(HTnoPhotonsG400);

h_MHTG400->Fill(MHTnoPhotonsG400);

h_NJetsG400->Fill(NJetsNoPhotonsG400);

h_minDPhiNG400->Fill(minDeltaPhiNnoPhotonsG400);

h_PhpTG400->Fill(photonProdG400->at(iPh).Pt());




double EBphotons =photon_isEBG400->at(iPh);

if(EBphotons==1){//EB Photons

h_SIetaG400EB->Fill(photon_sigmaIetaIetaG400->at(iPh));

h_pfChIsoG400EB->Fill(photon_pfChargedIsoRhoCorrG400->at(iPh));

h_pfNIsoG400EB->Fill(photon_pfNeutralIsoRhoCorrG400->at(iPh));

h_pfGammaIsoG400EB->Fill(photon_pfGammaIsoRhoCorrG400->at(iPh));


h_HadToEMG400EB->Fill(photon_hadTowOverEMG400->at(iPh));


h_PixelSG400EB->Fill(photon_hasPixelSeedG400->at(iPh));


int htoeg400EB=0;
int pxlg400EB=0;
int sietag400EB=0;
int chisog400EB=0;
int neoisog400EB=0;
int gammisog400EB=0;


totalEBG400=totalEBG400+1;




if(photon_hadTowOverEMG400->at(iPh) < HtoECut_EB/*0.05*/){

htoeg400EB=5;
h_HadToEMG400EB_cut->Fill(photon_hadTowOverEMG400->at(iPh));
}


if(photon_hasPixelSeedG400->at(iPh) !=1){
pxlg400EB=5;
h_PixelSG400EB_cut->Fill(photon_hasPixelSeedG400->at(iPh));

}




if(photon_sigmaIetaIetaG400->at(iPh) < SigmaIetaCut_EB){
sietag400EB=5;
h_SIetaG400EB_cut->Fill(photon_sigmaIetaIetaG400->at(iPh));
}


if(photon_pfChargedIsoRhoCorrG400->at(iPh) < ChIsoCut_EB){
chisog400EB=5;
h_pfChIsoG400EB_cut->Fill(photon_pfChargedIsoRhoCorrG400->at(iPh));
}


if(photon_pfNeutralIsoRhoCorrG400->at(iPh) < (NeoIsoCut_EB_A + TMath::Exp(NeoIsoCut_EB_B*photonProdG400->at(iPh).Pt()+NeoIsoCut_EB_C))){
neoisog400EB=5;
h_pfNIsoG400EB_cut->Fill(photon_pfNeutralIsoRhoCorrG400->at(iPh));

}


if(photon_pfGammaIsoRhoCorrG400->at(iPh) < (GammaIsoCut_EB_A + GammaIsoCut_EB_B*photonProdG400->at(iPh).Pt())){
gammisog400EB=5;

h_pfGammaIsoG400EB_cut->Fill(photon_pfGammaIsoRhoCorrG400->at(iPh));

}

if(htoeg400EB==5 /*&& pxlg400EB=5*/ && sietag400EB==5 && chisog400EB==5 && neoisog400EB==5 && gammisog400EB==5 ){

h_effHTG400_EB->Fill(HTnoPhotonsG400);
totalcutEBG400=totalcutEBG400+1;

}

}else if(EBphotons !=1){//EC photons


int htoeg400EC=0;
int pxlg400EC=0;
int sietag400EC=0;
int chisog400EC=0;
int neoisog400EC=0;
int gammisog400EC=0;

totalECG400=totalECG400+1;




h_SIetaG400EC->Fill(photon_sigmaIetaIetaG400->at(iPh));

h_pfChIsoG400EC->Fill(photon_pfChargedIsoRhoCorrG400->at(iPh));

h_pfNIsoG400EC->Fill(photon_pfNeutralIsoRhoCorrG400->at(iPh));

h_pfGammaIsoG400EC->Fill(photon_pfGammaIsoRhoCorrG400->at(iPh));



h_HadToEMG400EC->Fill(photon_hadTowOverEMG400->at(iPh));


h_PixelSG400EC->Fill(photon_hasPixelSeedG400->at(iPh));

if(photon_hadTowOverEMG400->at(iPh) < HtoECut_EB/*0.05*/){
htoeg400EC=5;

h_HadToEMG400EC_cut->Fill(photon_hadTowOverEMG400->at(iPh));
}


if(photon_hasPixelSeedG400->at(iPh) !=1){
pxlg400EC=5;
h_PixelSG400EC_cut->Fill(photon_hasPixelSeedG400->at(iPh));

}



if(photon_sigmaIetaIetaG400->at(iPh) < SigmaIetaCut_EC){
sietag400EC=5;
h_SIetaG400EC_cut->Fill(photon_sigmaIetaIetaG400->at(iPh));
}


if(photon_pfChargedIsoRhoCorrG400->at(iPh) < ChIsoCut_EC){
chisog400EC=5;
h_pfChIsoG400EC_cut->Fill(photon_pfChargedIsoRhoCorrG400->at(iPh));
}


if(photon_pfNeutralIsoRhoCorrG400->at(iPh) < (NeoIsoCut_EC_A + NeoIsoCut_EC_B*photonProdG400->at(iPh).Pt())){
neoisog400EC=5;
h_pfNIsoG400EC_cut->Fill(photon_pfNeutralIsoRhoCorrG400->at(iPh));

}


if(photon_pfGammaIsoRhoCorrG400->at(iPh) < (GammaIsoCut_EC_A + GammaIsoCut_EC_B*photonProdG400->at(iPh).Pt())){
gammisog400EC=5;
h_pfGammaIsoG400EC_cut->Fill(photon_pfGammaIsoRhoCorrG400->at(iPh));

}

if(htoeg400EC==5 /*&& pxlg400EB=5*/ && sietag400EC==5 && chisog400EC==5 && neoisog400EC==5 && gammisog400EC==5 ){
h_effHTG400_EC->Fill(HTnoPhotonsG400);
totalcutECG400=totalcutECG400+1;

}





}//EC Photons up


}//Photon pT > 100 GeV
}//gen match condition
}//Photon loop


}//base line conditions
}//event loop GJets 400HTInf



for( int iEv2 = 0 ; iEv2<tG600->GetEntries(); iEv2++){//event loop GJets 600HTInf
tG600->GetEntry(iEv2);
if( iEv2 % 5000 == 0 ) cout << "event : " << iEv2 << endl;
if(iEv2==NumEvents)break;
if(HTnoPhotonsG600 > 500 && MHTnoPhotonsG600 >200 && NJetsNoPhotonsG600 >= 4  && LeptonsG600==0 && minDeltaPhiNnoPhotonsG600 > 6.){//base line conditions



for(int iPh=0;iPh<photon_genMatchedG600->size();iPh++){//photon loop
if(photon_genMatchedG600->at(iPh) ==1){//gen match condition
if(photonProdG600->at(iPh).Pt() > 100.){//Photon pT > 100 GeV

h_HTG600->Fill(HTnoPhotonsG600);

h_MHTG600->Fill(MHTnoPhotonsG600);

h_NJetsG600->Fill(NJetsNoPhotonsG600);

h_minDPhiNG600->Fill(minDeltaPhiNnoPhotonsG600);


h_PhpTG600->Fill(photonProdG600->at(iPh).Pt());


//cout<<"test = 1"<<endl;







double EBphotons =photon_isEBG600->at(iPh);

if(EBphotons==1){//EB Photons




int htoeg600EB=0;
int pxlg600EB=0;
int sietag600EB=0;
int chisog600EB=0;
int neoisog600EB=0;
int gammisog600EB=0;

totalEBG600=totalEBG600+1;





h_SIetaG600EB->Fill(photon_sigmaIetaIetaG600->at(iPh));

h_pfChIsoG600EB->Fill(photon_pfChargedIsoRhoCorrG600->at(iPh));

h_pfNIsoG600EB->Fill(photon_pfNeutralIsoRhoCorrG600->at(iPh));

h_pfGammaIsoG600EB->Fill(photon_pfGammaIsoRhoCorrG600->at(iPh));




h_HadToEMG600EB->Fill(photon_hadTowOverEMG600->at(iPh));


h_PixelSG600EB->Fill(photon_hasPixelSeedG600->at(iPh));

if(photon_hadTowOverEMG600->at(iPh) < HtoECut_EB){
htoeg600EB=5;

h_HadToEMG600EB_cut->Fill(photon_hadTowOverEMG600->at(iPh));
}
//cout<<"test = 2"<<endl;

if(photon_hasPixelSeedG600->at(iPh) !=1){
pxlg600EB=5;
h_PixelSG600EB_cut->Fill(photon_hasPixelSeedG600->at(iPh));

}

//cout<<"test = 3"<<endl;
if(photon_sigmaIetaIetaG600->at(iPh) < SigmaIetaCut_EB){
sietag600EB=5;
h_SIetaG600EB_cut->Fill(photon_sigmaIetaIetaG600->at(iPh));
}


if(photon_pfChargedIsoRhoCorrG600->at(iPh) < ChIsoCut_EB){
chisog600EB=5;
h_pfChIsoG600EB_cut->Fill(photon_pfChargedIsoRhoCorrG600->at(iPh));
}



if(photon_pfNeutralIsoRhoCorrG600->at(iPh) < (NeoIsoCut_EB_A+ TMath::Exp(NeoIsoCut_EB_B*photonProdG600->at(iPh).Pt()+NeoIsoCut_EB_C))){
neoisog600EB=5;
h_pfNIsoG600EB_cut->Fill(photon_pfNeutralIsoRhoCorrG600->at(iPh));

}


if(photon_pfGammaIsoRhoCorrG600->at(iPh) < (GammaIsoCut_EB_A + GammaIsoCut_EB_B*photonProdG600->at(iPh).Pt())){
gammisog600EB=5;
h_pfGammaIsoG600EB_cut->Fill(photon_pfGammaIsoRhoCorrG600->at(iPh));

}

if(htoeg600EB==5 /*&& pxlg400EB=5*/ && sietag600EB==5 && chisog600EB==5 && neoisog600EB==5 && gammisog600EB==5 ){
h_effHTG600_EB->Fill(HTnoPhotonsG600);
totalcutEBG600=totalcutEBG600+1;

}


}else if(EBphotons !=1){//EC photons



int htoeg600EC=0;
int pxlg600EC=0;
int sietag600EC=0;
int chisog600EC=0;
int neoisog600EC=0;
int gammisog600EC=0;


totalECG600=totalECG600+1;



h_SIetaG600EC->Fill(photon_sigmaIetaIetaG600->at(iPh));

h_pfChIsoG600EC->Fill(photon_pfChargedIsoRhoCorrG600->at(iPh));

h_pfNIsoG600EC->Fill(photon_pfNeutralIsoRhoCorrG600->at(iPh));

h_pfGammaIsoG600EC->Fill(photon_pfGammaIsoRhoCorrG600->at(iPh));





h_HadToEMG600EC->Fill(photon_hadTowOverEMG600->at(iPh));


h_PixelSG600EC->Fill(photon_hasPixelSeedG600->at(iPh));

if(photon_hadTowOverEMG600->at(iPh) < HtoECut_EC){
htoeg600EC=5;
h_HadToEMG600EC_cut->Fill(photon_hadTowOverEMG600->at(iPh));
}

//cout<<"test = 4"<<endl;

//cout<<"pixel seed = "<<photon_hasPixelSeedG600->at(iPh)<<endl;

if(photon_hasPixelSeedG600->at(iPh) !=1){
pxlg600EC=5;
h_PixelSG600EC_cut->Fill(photon_hasPixelSeedG600->at(iPh));

}

//cout<<"test = 5"<<endl;

if(photon_sigmaIetaIetaG600->at(iPh) < SigmaIetaCut_EC){
sietag600EC=5;
h_SIetaG600EC_cut->Fill(photon_sigmaIetaIetaG600->at(iPh));
}


if(photon_pfChargedIsoRhoCorrG600->at(iPh) < ChIsoCut_EB){
chisog600EC=5;
h_pfChIsoG600EC_cut->Fill(photon_pfChargedIsoRhoCorrG600->at(iPh));
}


if(photon_pfNeutralIsoRhoCorrG600->at(iPh) < (NeoIsoCut_EC_A + NeoIsoCut_EC_B*photonProdG600->at(iPh).Pt())){
neoisog600EC=5;
h_pfNIsoG600EC_cut->Fill(photon_pfNeutralIsoRhoCorrG600->at(iPh));

}


if(photon_pfGammaIsoRhoCorrG600->at(iPh) < (GammaIsoCut_EC_A + GammaIsoCut_EC_B*photonProdG600->at(iPh).Pt())){
 gammisog600EC=5;
h_pfGammaIsoG600EC_cut->Fill(photon_pfGammaIsoRhoCorrG600->at(iPh));

}


if(htoeg600EC==5 /*&& pxlg400EB=5*/ && sietag600EC==5 && chisog600EC==5 && neoisog600EC==5 && gammisog600EC==5 ){
h_effHTG600_EC->Fill(HTnoPhotonsG600);
totalcutECG600=totalcutECG600+1;

}




}//EC Photons




}//Photon pT > 100 GeV
}//gen match condition
}//Photon loop








}//base line conditions
}//event loop GJets 600HTInf







h_effHTG400_EB->Scale(0.075604015773398);
h_effHTG600_EB->Scale(0.0261385093009007);

h_effHTG400_EC->Scale(0.075604015773398);
h_effHTG600_EC->Scale(0.0261385093009007);



h_effHTG_EB->Add(h_effHTG400_EB);
h_effHTG_EB->Add(h_effHTG600_EB);

h_effHTG_EC->Add(h_effHTG400_EC);
h_effHTG_EC->Add(h_effHTG600_EC);


TCanvas *HT_Eff=new TCanvas("MyCanvas","My Canvas");

HT_Eff->Divide(2,2);

HT_Eff->cd(1);
h_effHTG_EB->Draw();

HT_Eff->cd(2);
h_effHTG_EC->Draw();




TPaveText *tex1 = new TPaveText(0.55698,0.6377622,0.8043624,0.8863636,"brNDC");
tex1->SetBorderSize(0);
tex1->SetFillStyle(0);
tex1->SetTextAlign(11);
tex1->SetTextFont(42);
tex1->SetTextSize(0.04);
text = tex1->AddText("#gamma(Gen matched)  + Jets");
text = tex1->AddText("HT > 500");
text = tex1->AddText("MHT > 200");
text = tex1->AddText("Leptons==0");
text = tex1->AddText("n_{Jets} >=4");
text = tex1->AddText("#Delta #Phi_{min} > 6. ");
text = tex1->AddText("#gamma p_{T} > 100 GeV");




TPaveText *tex1EB = new TPaveText(0.5504698,0.6377622,0.8043624,0.8863636,"brNDC");
tex1EB->SetBorderSize(0);
tex1EB->SetFillStyle(0);
tex1EB->SetTextAlign(11);
tex1EB->SetTextFont(42);
tex1EB->SetTextSize(0.04);
text = tex1EB->AddText("#gamma(Gen matched, Barrel)  + Jets");
text = tex1EB->AddText("HT > 500");
text = tex1EB->AddText("MHT > 200");
text = tex1EB->AddText("Leptons==0");
text = tex1EB->AddText("n_{Jets} >=4");
text = tex1EB->AddText("#Delta #Phi_{min} > 6. ");
text = tex1EB->AddText("#gamma p_{T} > 100 GeV");



TPaveText *tex1EC = new TPaveText(0.554698,0.6377622,0.8043624,0.8863636,"brNDC");
tex1EC->SetBorderSize(0);
tex1EC->SetFillStyle(0);
tex1EC->SetTextAlign(11);
tex1EC->SetTextFont(42);
tex1EC->SetTextSize(0.04);
text = tex1EC->AddText("#gamma(Gen matched, Endcap)  + Jets");
text = tex1EC->AddText("HT > 500");
text = tex1EC->AddText("MHT > 200");
text = tex1EC->AddText("Leptons==0");
text = tex1EC->AddText("n_{Jets} >=4");
text = tex1EC->AddText("#Delta #Phi_{min} > 6. ");
text = tex1EC->AddText("#gamma p_{T} > 100 GeV");




/*
int totalEBG400=0;
int totalECG400=0;
int totalEBG600=0;
int totalECG600=0;


int totalcutEBG400=0;
int totalcutECG400=0;
int totalcutEBG600=0;
int totalcutECG600=0;
*/

float TotaleffEBG400=(float)totalcutEBG400/(float)totalEBG400;
float TotaleffECG400=(float)totalcutECG400/(float)totalECG400;

float TotaleffEBG600=(float)totalcutEBG600/(float)totalEBG600;
float TotaleffECG600=(float)totalcutECG600/(float)totalECG600;



float ErrTotaleffEBG400=sqrt(((TotaleffEBG400)*(1+TotaleffEBG400))/totalEBG400);
float ErrTotaleffECG400=sqrt(((TotaleffECG400)*(1+TotaleffECG400))/totalECG400);
float ErrTotaleffEBG600=sqrt(((TotaleffEBG600)*(1+TotaleffEBG600))/totalEBG600);
float ErrTotaleffECG600=sqrt(((TotaleffEBG600)*(1+TotaleffEBG600))/totalEBG600);

cout<<"Barrel Eff(G400) =  "<<TotaleffEBG400<<"  +-  "<<ErrTotaleffEBG400<<endl;
cout<<"Endcap Eff(G400) =  "<<TotaleffECG400<<"  +-  "<<ErrTotaleffECG400<<endl;
cout<<"Barrel Eff(G600) =  "<<TotaleffEBG600<<"  +-  "<<ErrTotaleffEBG600<<endl;
cout<<"Endcap Eff(G600) =  "<<TotaleffECG600<<"  +-  "<<ErrTotaleffECG600<<endl;



TCanvas *c_BaseVars=new TCanvas("BaseVars","BaseVars");
c_BaseVars->Divide(2,2);


h_HTG400->Scale(0.075604015773398);
h_HTG600->Scale(0.0261385093009007);


h_HTG->Add(h_HTG400);
h_HTG->Add(h_HTG600);



h_MHTG400->Scale(0.075604015773398);
h_MHTG600->Scale(0.0261385093009007);
h_MHTG->Add(h_MHTG400);
h_MHTG->Add(h_MHTG600);


h_NJetsG400->Scale(0.075604015773398);
h_NJetsG600->Scale(0.0261385093009007);
h_NJetsG->Add(h_NJetsG400);
h_NJetsG->Add(h_NJetsG600);

h_minDPhiNG400->Scale(0.075604015773398);
h_minDPhiNG600->Scale(0.0261385093009007);
h_minDPhiNG->Add(h_minDPhiNG400);
h_minDPhiNG->Add(h_minDPhiNG600);


c_BaseVars->cd(1);
gPad->SetLogy(); 
h_HTG->Draw();
tex1->Draw();


c_BaseVars->cd(2);
gPad->SetLogy(); 
h_MHTG->Draw();
tex1->Draw();
c_BaseVars->cd(3);
h_NJetsG->Draw();
tex1->Draw();
c_BaseVars->cd(4);
h_minDPhiNG->Draw();
tex1->Draw();


h_PhpTG400->Scale(0.075604015773398);
h_PhpTG600->Scale(0.0261385093009007);

h_PhpTG->Add(h_PhpTG400);
h_PhpTG->Add(h_PhpTG600);

TCanvas *c_PhpT=new TCanvas("PhpT","Photon pT");

c_PhpT->cd();
h_PhpTG->Draw();
tex1->Draw();

TCanvas *c_HemPx=new TCanvas("HemPx","HemPx");

c_HemPx->Divide(2,1);


//c_HemPx->cd(1);
//h_HadToEMG->Draw();
//tex1->Draw();

//c_HemPx->cd(2);
//h_PixelSG->Draw();
//tex1->Draw();

///////////////////////////histos after cut ends here








/////////////////////////histos after cut ends here

////////////Barrel
h_HadToEMG400EB->Scale(0.075604015773398);
h_HadToEMG600EB->Scale(0.0261385093009007);

h_HadToEMGEB->Add(h_HadToEMG400EB);
h_HadToEMGEB->Add(h_HadToEMG600EB);

h_PixelSG400EB->Scale(0.075604015773398);
h_PixelSG600EB->Scale(0.0261385093009007);

h_PixelSGEB->Add(h_PixelSG400EB);
h_PixelSGEB->Add(h_PixelSG600EB);

h_HadToEMG400EB_cut->Scale(0.075604015773398);
h_HadToEMG600EB_cut->Scale(0.0261385093009007);
h_HadToEMGEB_cut->Add(h_HadToEMG400EB_cut);
h_HadToEMGEB_cut->Add(h_HadToEMG600EB_cut);

h_PixelSG400EB_cut->Scale(0.075604015773398);
h_PixelSG600EB_cut->Scale(0.0261385093009007);

h_PixelSGEB_cut->Add(h_PixelSG400EB_cut);
h_PixelSGEB_cut->Add(h_PixelSG600EB_cut);



////////////Barrel

/////////////Endcap

h_HadToEMG400EC->Scale(0.075604015773398);
h_HadToEMG600EC->Scale(0.0261385093009007);

h_HadToEMGEC->Add(h_HadToEMG400EC);
h_HadToEMGEC->Add(h_HadToEMG600EC);

h_PixelSG400EC->Scale(0.075604015773398);
h_PixelSG600EC->Scale(0.0261385093009007);

h_PixelSGEC->Add(h_PixelSG400EC);
h_PixelSGEC->Add(h_PixelSG600EC);

h_HadToEMG400EC_cut->Scale(0.075604015773398);
h_HadToEMG600EC_cut->Scale(0.0261385093009007);
h_HadToEMGEC_cut->Add(h_HadToEMG400EC_cut);
h_HadToEMGEC_cut->Add(h_HadToEMG600EC_cut);

h_PixelSG400EC_cut->Scale(0.075604015773398);
h_PixelSG600EC_cut->Scale(0.0261385093009007);

h_PixelSGEC_cut->Add(h_PixelSG400EC_cut);
h_PixelSGEC_cut->Add(h_PixelSG600EC_cut);

/////////////Endcap



/////////////////////////////////////histos before cuts starts here
/////////////Barrel Photons

h_SIetaG400EB->Scale(0.075604015773398);
h_SIetaG600EB->Scale(0.0261385093009007);
h_SIetaGEB->Add(h_SIetaG400EB);
h_SIetaGEB->Add(h_SIetaG600EB);



h_pfChIsoG400EB->Scale(0.075604015773398);
h_pfChIsoG600EB->Scale(0.0261385093009007);
h_pfChIsoGEB->Add(h_pfChIsoG400EB);
h_pfChIsoGEB->Add(h_pfChIsoG600EB);


h_pfNIsoG400EB->Scale(0.075604015773398);
h_pfNIsoG600EB->Scale(0.0261385093009007);
h_pfNIsoGEB->Add(h_pfNIsoG400EB);
h_pfNIsoGEB->Add(h_pfNIsoG600EB);


h_pfGammaIsoG400EB->Scale(0.075604015773398);
h_pfGammaIsoG600EB->Scale(0.0261385093009007);
h_pfGammaIsoGEB->Add(h_pfGammaIsoG400EB);
h_pfGammaIsoGEB->Add(h_pfGammaIsoG600EB);

//EndcapPhotons

h_SIetaG400EC->Scale(0.075604015773398);
h_SIetaG600EC->Scale(0.0261385093009007);
h_SIetaGEC->Add(h_SIetaG400EC);
h_SIetaGEC->Add(h_SIetaG600EC);



h_pfChIsoG400EC->Scale(0.075604015773398);
h_pfChIsoG600EC->Scale(0.0261385093009007);
h_pfChIsoGEC->Add(h_pfChIsoG400EC);
h_pfChIsoGEC->Add(h_pfChIsoG600EC);


h_pfNIsoG400EC->Scale(0.075604015773398);
h_pfNIsoG600EC->Scale(0.0261385093009007);
h_pfNIsoGEC->Add(h_pfNIsoG400EC);
h_pfNIsoGEC->Add(h_pfNIsoG600EC);


h_pfGammaIsoG400EC->Scale(0.075604015773398);
h_pfGammaIsoG600EC->Scale(0.0261385093009007);
h_pfGammaIsoGEC->Add(h_pfGammaIsoG400EC);
h_pfGammaIsoGEC->Add(h_pfGammaIsoG600EC);
/////////////////////////////////////////////////////histograms before cuts ends here




///////////////////////////////////Histograms after cuts starts here
/////////////Barrel Photons

h_SIetaG400EB_cut->Scale(0.075604015773398);
h_SIetaG600EB_cut->Scale(0.0261385093009007);
h_SIetaGEB_cut->Add(h_SIetaG400EB_cut);
h_SIetaGEB_cut->Add(h_SIetaG600EB_cut);



h_pfChIsoG400EB_cut->Scale(0.075604015773398);
h_pfChIsoG600EB_cut->Scale(0.0261385093009007);
h_pfChIsoGEB_cut->Add(h_pfChIsoG400EB_cut);
h_pfChIsoGEB_cut->Add(h_pfChIsoG600EB_cut);


h_pfNIsoG400EB_cut->Scale(0.075604015773398);
h_pfNIsoG600EB_cut->Scale(0.0261385093009007);
h_pfNIsoGEB_cut->Add(h_pfNIsoG400EB_cut);
h_pfNIsoGEB_cut->Add(h_pfNIsoG600EB_cut);


h_pfGammaIsoG400EB_cut->Scale(0.075604015773398);
h_pfGammaIsoG600EB_cut->Scale(0.0261385093009007);
h_pfGammaIsoGEB_cut->Add(h_pfGammaIsoG400EB_cut);
h_pfGammaIsoGEB_cut->Add(h_pfGammaIsoG600EB_cut);

//EndcapPhotons

h_SIetaG400EC_cut->Scale(0.075604015773398);
h_SIetaG600EC_cut->Scale(0.0261385093009007);
h_SIetaGEC_cut->Add(h_SIetaG400EC_cut);
h_SIetaGEC_cut->Add(h_SIetaG600EC_cut);



h_pfChIsoG400EC_cut->Scale(0.075604015773398);
h_pfChIsoG600EC_cut->Scale(0.0261385093009007);
h_pfChIsoGEC_cut->Add(h_pfChIsoG400EC_cut);
h_pfChIsoGEC_cut->Add(h_pfChIsoG600EC_cut);


h_pfNIsoG400EC_cut->Scale(0.075604015773398);
h_pfNIsoG600EC_cut->Scale(0.0261385093009007);
h_pfNIsoGEC_cut->Add(h_pfNIsoG400EC_cut);
h_pfNIsoGEC_cut->Add(h_pfNIsoG600EC_cut);


h_pfGammaIsoG400EC_cut->Scale(0.075604015773398);
h_pfGammaIsoG600EC_cut->Scale(0.0261385093009007);
h_pfGammaIsoGEC_cut->Add(h_pfGammaIsoG400EC_cut);
h_pfGammaIsoGEC_cut->Add(h_pfGammaIsoG600EC_cut);


///////////////////////////////////Histograms after cuts ends here




TCanvas *c_IDIso =new TCanvas("IDIso","IDIso");
c_IDIso->Divide(2,2);

c_IDIso->cd(1);
h_SIetaGEB->Draw();
//h_SIetaGEB_cut->Draw("SAME");
tex1EB->Draw();


c_IDIso->cd(2);
h_pfChIsoGEB->Draw();
//h_pfChIsoGEB_cut->Draw("SAME");
tex1EB->Draw();

c_IDIso->cd(3);
h_pfNIsoGEB->Draw();
//h_pfNIsoGEB_cut->Draw("SAME");
tex1EB->Draw();
c_IDIso->cd(4);
h_pfGammaIsoGEB->Draw();
//h_pfGammaIsoGEB_cut->Draw("SAME");
tex1EB->Draw();




TCanvas *c_IDIso_cut =new TCanvas("IDIso_cut","IDIso_cut");
c_IDIso_cut->Divide(2,2);

c_IDIso_cut->cd(1);
h_SIetaGEC->Draw();
//h_SIetaGEC_cut->Draw("SAME");
tex1EC->Draw();
c_IDIso_cut->cd(2);
h_pfChIsoGEC->Draw();
//h_pfChIsoGEC_cut->Draw("SAME");
tex1EC->Draw();

c_IDIso_cut->cd(3);
h_pfNIsoGEC->Draw();
//h_pfNIsoGEC_cut->Draw("SAME");
tex1EC->Draw();
c_IDIso_cut->cd(4);
h_pfGammaIsoGEC->Draw();
//h_pfGammaIsoGEC_cut->Draw("SAME");
tex1EC->Draw();




float pixelEffEB=h_PixelSGEB_cut->Integral()/h_PixelSGEB->Integral();
float HaddEffEB=h_HadToEMGEB_cut->Integral()/h_HadToEMGEB->Integral();

float pixelEffEC=h_PixelSGEC_cut->Integral()/h_PixelSGEC->Integral();
float HaddEffEC=h_HadToEMGEC_cut->Integral()/h_HadToEMGEC->Integral();

float EBIetaEff=h_SIetaGEB_cut->Integral()/h_SIetaGEB->Integral();
float ECIetaEff=h_SIetaGEC_cut->Integral()/h_SIetaGEC->Integral();








float ChIsoEffEB= h_pfChIsoGEB_cut->Integral()/h_pfChIsoGEB->Integral();
float NeoIsoEffEB=h_pfNIsoGEB_cut->Integral()/h_pfNIsoGEB->Integral();
float GammaIsoEffEB= h_pfGammaIsoGEB_cut->Integral()/h_pfGammaIsoGEB->Integral();

float ChIsoEffEC=h_pfChIsoGEC_cut->Integral()/h_pfChIsoGEC->Integral();
float NeoIsoEffEC=h_pfNIsoGEC_cut->Integral()/h_pfNIsoGEC->Integral(); 
float GammaIsoEffEC= h_pfGammaIsoGEC_cut->Integral()/h_pfGammaIsoGEC->Integral();












float Xar[6];
float YEff[6];
float Yerr[6];




float XarIso[6];
float YEffIso[6];
float YerrIso[6];



Xar[0]=0.5;
Xar[1]=1.5;
Xar[2]=2.5;
Xar[3]=3.5;
Xar[4]=4.5;
Xar[5]=5.5;

XarIso[0]=0.5;
XarIso[1]=1.5;
XarIso[2]=2.5;
XarIso[3]=3.5;
XarIso[4]=4.5;
XarIso[5]=5.5;


YEff[0]=pixelEffEB;
YEff[1]=pixelEffEC;
YEff[2]=HaddEffEB;
YEff[3]=HaddEffEC;
YEff[4]=EBIetaEff;
YEff[5]=ECIetaEff;

YEffIso[0]=ChIsoEffEB;
YEffIso[1]=ChIsoEffEC;
YEffIso[2]=NeoIsoEffEB;
YEffIso[3]=NeoIsoEffEC;
YEffIso[4]=GammaIsoEffEB;
YEffIso[5]=GammaIsoEffEC;



Yerr[0]=sqrt((pixelEffEB*(1+pixelEffEB))/h_PixelSGEB->Integral());
Yerr[1]=sqrt((pixelEffEC*(1+pixelEffEC))/h_PixelSGEC->Integral());
Yerr[2]=sqrt((HaddEffEB*(1+HaddEffEB))/h_HadToEMGEB->Integral());
Yerr[3]=sqrt((HaddEffEC*(1+HaddEffEC))/h_HadToEMGEC->Integral());
Yerr[4]=sqrt((EBIetaEff*(1+EBIetaEff))/h_SIetaGEB->Integral());
Yerr[5]=sqrt((ECIetaEff*(1+ECIetaEff))/h_SIetaGEC->Integral());


cout<<"pixelEffEB ="<<h_PixelSGEB_cut->Integral()<<"/"<<h_PixelSGEB->Integral()<<" = "<<pixelEffEB<<"+-"<<Yerr[0] <<endl;
cout<<"HaddEffEB = "<< h_HadToEMGEB_cut->Integral()<<"/"<< h_HadToEMGEB->Integral()<<"= "<< HaddEffEB<<"+-"<<Yerr[1] <<endl;

cout<<"pixelEffEC ="<<h_PixelSGEC_cut->Integral()<<"/"<<h_PixelSGEC->Integral()<<" = "<<pixelEffEC<<"+-"<<Yerr[2] <<endl;
cout<<"HaddEffEC = "<< h_HadToEMGEC_cut->Integral()<<"/"<< h_HadToEMGEC->Integral()<<"= "<< HaddEffEC<<"+-"<<Yerr[3] <<endl;

cout<<"EBIetaEff = "<<h_SIetaGEB_cut->Integral() <<"/"<<h_SIetaGEB->Integral() <<"="<<EBIetaEff<<"+-"<< Yerr[4] <<endl;
cout<<"ECIetaEff = "<<h_SIetaGEC_cut->Integral() <<"/"<<h_SIetaGEC->Integral() <<"="<<ECIetaEff<<"+-"<<Yerr[5]  <<endl;








YerrIso[0]=sqrt((ChIsoEffEB*(1+ChIsoEffEB))/h_pfChIsoGEB->Integral());
YerrIso[1]=sqrt((ChIsoEffEC*(1+ChIsoEffEC))/h_pfChIsoGEC->Integral());
YerrIso[2]=sqrt((NeoIsoEffEB*(1+NeoIsoEffEB))/h_pfNIsoGEB->Integral());
YerrIso[3]=sqrt((NeoIsoEffEC*(1+NeoIsoEffEC))/h_pfNIsoGEC->Integral());
YerrIso[4]=sqrt((GammaIsoEffEB*(1+GammaIsoEffEB))/h_pfGammaIsoGEB->Integral());
YerrIso[5]=sqrt((GammaIsoEffEC*(1+GammaIsoEffEC))/h_pfGammaIsoGEC->Integral());

cout<<"ChIsoEffEB"<<h_pfChIsoGEB_cut->Integral() <<"/"<<h_pfChIsoGEB->Integral() <<" ="<<ChIsoEffEB<<"+-"<<YerrIso[0] <<endl;
cout<<"NeoIsoEffEB"<<h_pfNIsoGEB_cut->Integral() <<"/"<<h_pfNIsoGEB->Integral() <<" ="<< NeoIsoEffEB<<"+-"<<YerrIso[1]<<endl;
cout<<"GammaIsoEffEB"<<h_pfGammaIsoGEB_cut->Integral() <<"/"<<h_pfGammaIsoGEB->Integral() <<" ="<< GammaIsoEffEB<<"+-"<< YerrIso[2]<<endl;
cout<<"ChIsoEffEC"<<h_pfChIsoGEC_cut->Integral() <<"/"<<h_pfChIsoGEC->Integral() <<" ="<<ChIsoEffEC<<"+-"<<YerrIso[3] <<endl;
cout<<"NeoIsoEffEC"<<h_pfNIsoGEC_cut->Integral() <<"/"<<h_pfNIsoGEC->Integral() <<" ="<<NeoIsoEffEC<<"+-"<<YerrIso[4] <<endl;
cout<<"GammaIsoEffEC"<<h_pfGammaIsoGEC_cut->Integral() <<"/"<<h_pfGammaIsoGEC->Integral() <<" =" <<GammaIsoEffEC<<"+-"<< YerrIso[5]<<endl;





TCanvas *c_IDVarEff=new TCanvas("c_IDVarEff","c_IDVarEff");


TGraphErrors *gh =new TGraphErrors(6,Xar,YEff,0,Yerr);
gh->SetMarkerColor(kBlue);
gh->SetMarkerStyle(21);

gh->Draw("AP");
tex1->Draw();
//const Int_t nx = 6;
//char *months[nx] = {"PixelSeed_EB(0)","HaddOverEM_EB","PixelSeed_EC(0)","HaddOverEM_EC","SigmaIeta_EB","SigmaIeta_EC"};

TText *t = new TText();
   t->SetTextAlign(32);
   t->SetTextSize(0.025);
   t->SetTextFont(72);
   char *labels[6] = {"PixelSeed_EB(0)","PixelSeed_EC(0)","HaddOverEM_EB","HaddOverEM_EC","SigmaIeta_EB","SigmaIeta_EC"};

   t->DrawText(1,0.5,"PixelSeed_EB(0)");
   t->DrawText(2,0.5,"PixelSeed_EC(0)");

   t->DrawText(3,0.5,"HaddOverEM_EB");
   t->DrawText(4,0.5,"HaddOverEM_EC");

   t->DrawText(5,0.5,"SigmaIeta_EB");
   t->DrawText(6,0.5,"SigmaIeta_EC");




TCanvas *c_IsoVarEffi=new TCanvas("c_IsoVarEffi","Photon Isolation Eff");

TGraphErrors *ghIso =new TGraphErrors(6,XarIso,YEffIso,0,YerrIso);
ghIso->SetMarkerColor(kBlue);
ghIso->SetMarkerStyle(21);

ghIso->Draw("AP");
tex1->Draw();
//const Int_t nxIso = 6;
//char *monthsIso[nxIso] = {"ChIsoEB","ChIsoEC","NeoIsoEB","NeoIsoEC","GammaIsoEB","GammaIsoEC"};


TText *tIso = new TText();
   tIso->SetTextAlign(32);
   tIso->SetTextSize(0.025);
   tIso->SetTextFont(72);
   char *labelsIso[6] = {"ChIsoEB","ChIsoEC","NeoIsoEB","NeoIsoEC","GammaIsoEB","GammaIsoEC"};

   tIso->DrawText(1,0.5,"ChIso_EB");
   tIso->DrawText(2,0.5,"ChIso_EC");
   tIso->DrawText(3,0.5,"NeoIso_EB");
   tIso->DrawText(4,0.5,"Neoso_EC");
   tIso->DrawText(5,0.5,"GammaIso_EB");
   tIso->DrawText(6,0.5,"GammaIso_EC");















}
