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
void PhotonIDIsoEff(){

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

 



TH1F *hIDeff =new TH1F("hIDeff","Photon ID variable  efficiencies ",4,0,4);




int NumEvents=300000;
int NumofGenMatchedPhotons=0;
int NumofEBGenMatchedPhotons=0;
int NumOfECGenMatchedPhotons=0;
int NumofhasnotPixelSeedPhotons=0;
int NumofhadTowOverEMPhotons=0;
int NumofPtcutPhotons=0;
int NumofsigmaIetaIetaPhotonsEB=0; 
int NumofsigmaIetaIetaPhotonsEC=0; 




for( int iEv1 = 0 ; iEv1<tG400->GetEntries(); iEv1++){//event loop
tG400->GetEntry(iEv1);
if(iEv1==NumEvents)break;
//if( iEv1 % 5000 == 0 ) cout << "event : " << iEv1 << endl;
//cout<<"Photon size = "<<photon_genMatchedG400->size()<<endl;
if(HTG400 > 500 && MHTG400 >200 && NJetsG400 >= 4  && LeptonsG400==0){//base line conditions


for(int iPh=0;iPh<photon_genMatchedG400->size();iPh++){//photon loop
if(photon_genMatchedG400->at(iPh) ==1){//gen match condition
NumofGenMatchedPhotons=NumofGenMatchedPhotons+1;
double pixelseed =photon_hasPixelSeedG400->at(iPh);
double HadOverEM = photon_hadTowOverEMG400->at(iPh);
double SigmaIeta = photon_sigmaIetaIetaG400->at(iPh);
double EBphotons =photon_isEBG400->at(iPh);

if(pixelseed !=1){NumofhasnotPixelSeedPhotons=NumofhasnotPixelSeedPhotons+1;}

if(HadOverEM < 0.05){NumofhadTowOverEMPhotons=NumofhadTowOverEMPhotons+1;}


if(EBphotons==1){
NumofEBGenMatchedPhotons=NumofEBGenMatchedPhotons+1;
if(SigmaIeta < 0.011){
NumofsigmaIetaIetaPhotonsEB=NumofsigmaIetaIetaPhotonsEB+1;
}

}else if(EBphotons !=1){

NumOfECGenMatchedPhotons=NumOfECGenMatchedPhotons+1;
if(SigmaIeta < 0.031){
NumofsigmaIetaIetaPhotonsEC=NumofsigmaIetaIetaPhotonsEC+1;
}

}





}//Gen match condition
}//photon loop



}//base line conditions

}//event loop


cout<<"NumofGenMatchedPhotons : "<<NumofGenMatchedPhotons<<endl;
cout<<"NumofhasnotPixelSeedPhotons: "<<NumofhasnotPixelSeedPhotons <<endl;
cout<<"NumofhadTowOverEMPhotons: "<<NumofhadTowOverEMPhotons <<endl;
cout<<"NumofEBGenMatchedPhotons: "<< NumofEBGenMatchedPhotons<<endl;
cout<<"NumOfECGenMatchedPhotons: "<<NumOfECGenMatchedPhotons <<endl;
cout<<"NumofsigmaIetaIetaPhotonsEB: "<< NumofsigmaIetaIetaPhotonsEB<<endl;
cout<<"NumofsigmaIetaIetaPhotonsEC: "<< NumofsigmaIetaIetaPhotonsEC<<endl;

float pixelEff=(float)NumofhasnotPixelSeedPhotons/(float)NumofGenMatchedPhotons;
float HaddEff=(float)NumofhadTowOverEMPhotons/(float)NumofGenMatchedPhotons;
float EBIetaEff=(float)NumofsigmaIetaIetaPhotonsEB/(float)NumofEBGenMatchedPhotons;
float ECIetaEff=(float)NumofsigmaIetaIetaPhotonsEC/(float)NumOfECGenMatchedPhotons;

float Xar[4];
float YEff[4];
float Yerr[4];


Xar[0]=0.5;
Xar[1]=1.5;
Xar[2]=2.5;
Xar[3]=3.5;

YEff[0]=pixelEff;
YEff[1]=HaddEff;
YEff[2]=EBIetaEff;
YEff[3]=ECIetaEff;


Yerr[0]=sqrt((pixelEff*(1-pixelEff))/NumofGenMatchedPhotons);
Yerr[1]=sqrt((HaddEff*(1-HaddEff))/NumofGenMatchedPhotons);
Yerr[2]=sqrt((EBIetaEff*(1-EBIetaEff))/NumofEBGenMatchedPhotons);
Yerr[3]=sqrt((ECIetaEff*(1-ECIetaEff))/NumOfECGenMatchedPhotons);

TGraphErrors *gh =new TGraphErrors(4,Xar,YEff,0,Yerr);
gh->SetMarkerColor(kBlue);
gh->SetMarkerStyle(21);




gh->Draw("AP");

const Int_t nx = 4;
char *months[nx] = {"PixelSeed(0)","HaddOverEM","SigmaIeta_EB","SigmaIeta_EC"};

TText *t = new TText();
   t->SetTextAlign(32);
   t->SetTextSize(0.025);
   t->SetTextFont(72);
   char *labels[4] = {"PixelSeed(0)","HaddOverEM","SigmaIeta_EB","SigmaIeta_EC"};

   t->DrawText(1,0.5,"PixelSeed(0)");
   t->DrawText(2,0.5,"HaddOverEM");
   t->DrawText(3,0.5,"SigmaIeta_EB");
   t->DrawText(4,0.5,"SigmaIeta_EC");

  // for (Int_t i=0;i<4;i++) {
  //     cout<<"Labels = "<<labels[i]<<endl;
  //    t->DrawText(0.5+i,Xar[i],labels[i]);
  // }













}//main programme
