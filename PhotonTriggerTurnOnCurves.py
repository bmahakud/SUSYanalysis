from ROOT import *
from labels import *
from photonUtils import *
from array import array
gROOT.ProcessLine(".L tdrstyle.C")
gROOT.ProcessLine("setTDRStyle()")

tree1 = TChain("TreeMaker2/PreSelection")
tree1.Add("/eos/uscms/store/user/bmahakud/PhotonTriggerStudy17thJuly2015/Spring15.GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root")
#tree1.Add("/uscms_data/d3/bmahakud/LatestAllHadronicSUSY/CMSSW_7_4_1/src/AWhitbeck/SuSySubstructure/test/test_RA2AnalysisTree.root")



photon90_PFHT500_HT_1 = TEfficiency("photon90_PFHT500_HT","photon90_PFHT500_HT",30,100,700)
photon90_PFHT500_pT_1 = TEfficiency("photon90_PFHT500_pT","photon90_PFHT500_pT",50,75,125)
photon90_1 = TEfficiency("photon90","photon90",50,75,125)

nEvents1 = tree1.GetEntries()

for iEvt1 in range( nEvents1 ) :

    #if iEvt > 100000 : break

    if iEvt1 % 10000 == 0 : print iEvt1,"of",nEvents1

    tree1.GetEntry( iEvt1 )

    HT1         = getattr( tree1 , "HT"          )
    HTclean1    = getattr( tree1 , "HTclean"     )
    MHTclean1   = getattr( tree1 , "MHTclean"    )
    NJetsclean1 = getattr( tree1 , "NJetsclean"  )
    triggerBit1 = getattr( tree1 , "PassTrigger" )
    photons1    = getattr( tree1 , "photonCands" )
    bestPhoton1 = getattr( tree1 , "bestPhoton"  )
    deltaPhi1_1  = getattr( tree1 , "DeltaPhi1clean")
    deltaPhi2_1  = getattr( tree1 , "DeltaPhi2clean")
    deltaPhi3_1  = getattr( tree1 , "DeltaPhi3clean")

    # bit 13: photon90
    # bit 14: photon75
    # btt 15: photon90_PFHT500
    
    bestPhotonIndex1 = -1 
    ss1=1    


    for iPhoton1 in range( len( photons1 ) ) :
        if passID( tree1 , iEvt1 , iPhoton1 ) and passIsolation( tree1 , iEvt1 , iPhoton1 ) : 
            bestPhotonIndex1 = iPhoton1
            break

    if bestPhotonIndex1 == -1 : continue
    if deltaPhi1_1 < 0.5 or deltaPhi2_1 < 0.5 or deltaPhi3_1 < 0.3 : continue
    #if MHTclean < 200. : continue

    ### in current configuration bit 14 is the relative
    if ss1==1 :
        if HTclean1 > 500.  :
            photon90_PFHT500_pT_1.Fill( triggerBit1[7] , photons1[bestPhotonIndex1].Pt() )
        if photons1[bestPhotonIndex1].Pt() > 100. :
            photon90_PFHT500_HT_1.Fill( triggerBit1[7] , HTclean1 )
  
#####################################
#####################################
#####################################
#####################################

tree2 = TChain("TreeMaker2/PreSelection")
tree2.Add("/eos/uscms/store/user/bmahakud/PhotonTriggerStudy17thJuly2015/Spring15.GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root")

photon90_PFHT500_HT_2 = TEfficiency("photon90_PFHT500_HT_2","photon90_PFHT500_HT_2",30,100,700)
photon90_PFHT500_pT_2 = TEfficiency("photon90_PFHT500_pT_2","photon90_PFHT500_pT_2",50,75,125)
photon90_2 = TEfficiency("photon90_2","photon90_2",50,75,125)

nEvents2 = tree2.GetEntries()

for iEvt2 in range( nEvents2 ) :

    #if iEvt > 100000 : break

    if iEvt2 % 10000 == 0 : print iEvt2,"of",nEvents2

    tree2.GetEntry( iEvt2 )

    HT2         = getattr( tree2 , "HT"          )
    HTclean2    = getattr( tree2 , "HTclean"     )
    MHTclean2   = getattr( tree2 , "MHTclean"    )
    NJetsclean2 = getattr( tree2 , "NJetsclean"  )
    triggerBit2 = getattr( tree2 , "PassTrigger" )
    photons2    = getattr( tree2 , "photonCands" )
    bestPhoton2 = getattr( tree2 , "bestPhoton"  )
    deltaPhi1_2  = getattr( tree2 , "DeltaPhi1clean")
    deltaPhi2_2  = getattr( tree2 , "DeltaPhi2clean")
    deltaPhi3_2  = getattr( tree2 , "DeltaPhi3clean")

    # bit 13: photon90
    # bit 14: photon75
    # btt 15: photon90_PFHT500
    
    bestPhotonIndex2 = -1 
    ss2=2
    for iPhoton2 in range( len( photons2 ) ) :
        if passID( tree2 , iEvt2 , iPhoton2 ) and passIsolation( tree2 , iEvt2 , iPhoton2 ) : 
            bestPhotonIndex2 = iPhoton2
            break

    if bestPhotonIndex2 == -1 : continue
    if deltaPhi1_2 < 0.5 or deltaPhi2_2 < 0.5 or deltaPhi3_2 < 0.3 : continue
    #if MHTclean < 200. : continue

    ### in current configuration bit 14 is the relative
    if ss2==2 :
        if HTclean2 > 500.  :
            photon90_PFHT500_pT_2.Fill( triggerBit2[7] , photons2[bestPhotonIndex2].Pt() )
        if photons2[bestPhotonIndex2].Pt() > 100. :
            photon90_PFHT500_HT_2.Fill( triggerBit2[7] , HTclean2 )



################################################
###############################################
###############################################
  # pEff_pT1_ =TEfficiency(*photon90_PFHT500_pT_1)
  # pEff_pT1_.SetNameTitle("peff1weighted","peff1weighted")

pList_pT = TList()
pList_pT.Add(photon90_PFHT500_pT_1)
pList_pT.Add(photon90_PFHT500_pT_2)

Weights = array("d", [1.102242033,0.370477092])

#pEffSumWithWeights_pT=TGraphAsymmErrors()


pEffSumWithWeights_pT = TEfficiency.Combine(pList_pT,"",2,Weights)


can_Comb_pT = TCanvas("can_Comb_pT","can_Comb_pT",500,500)
pEffSumWithWeights_pT.SetMarkerColor(4)
pEffSumWithWeights_pT.SetMarkerStyle(8)
pEffSumWithWeights_pT.SetTitle(";pT [GeV];Efficiency")
pEffSumWithWeights_pT.Draw("AP")

legpT_comb = TLegend(.5,.2,.9,.4)
legpT_comb.SetFillColor(0)
legpT_comb.SetBorderSize(0)
legpT_comb.AddEntry(pEffSumWithWeights_pT,"HLT_Photon90_PFHT500_v1","p")

legpT_comb.Draw()

can_Comb_pT.SaveAs("can_Comb_pT.png")


pList_HT = TList()
pList_HT.Add(photon90_PFHT500_HT_1)
pList_HT.Add(photon90_PFHT500_HT_2)

#pEffSumWithWeights_HT=TGraphAsymmErrors()
pEffSumWithWeights_HT = TEfficiency.Combine(pList_HT,"",2,Weights)


can_Comb_HT = TCanvas("can_Comb_HT","can_Comb_HT",500,500)
pEffSumWithWeights_HT.SetMarkerColor(4)
pEffSumWithWeights_HT.SetMarkerStyle(8)
pEffSumWithWeights_HT.SetTitle(";HT [GeV];Efficiency")
pEffSumWithWeights_HT.Draw("AP")

legHT_comb = TLegend(.5,.2,.9,.4)
legHT_comb.SetFillColor(0)
legHT_comb.SetBorderSize(0)
legHT_comb.AddEntry(pEffSumWithWeights_HT,"HLT_Photon90_PFHT500_v1","p")

legHT_comb.Draw()

can_Comb_HT.SaveAs("can_Comb_HT.png")




####################HT400




canHT_1 = TCanvas("canHT_1","canHT_1",500,500)

photon90_PFHT500_HT_1.SetMarkerStyle(8)
photon90_PFHT500_HT_1.SetMarkerColor(1)
photon90_PFHT500_HT_1.SetTitle(";HT [GeV];Efficiency")
photon90_PFHT500_HT_1.Draw()
legHT_1 = TLegend(.5,.2,.9,.4)
legHT_1.SetFillColor(0)
legHT_1.SetBorderSize(0)
legHT_1.AddEntry(photon90_PFHT500_HT_1,"HLT_Photon90_PFHT500_v1(HT400 Sample)","p")
legHT_1.Draw()
CMSlabel.Draw()
setLumi(-1.)
SqrtSlumi.Draw()
canHT_1.SaveAs("Photon90efficienciesVersusHT_Pt100_deltaPhiCuts_MHT200_HT400Sample.png")
canPt_1 = TCanvas("canPt_1","canPt_1",500,500)

gPad.Update()
photon90_PFHT500_pT_1.Draw()
gPad.Update()
photon90_PFHT500_pTgraph_1 = photon90_PFHT500_pT_1.GetPaintedGraph()
photon90_PFHT500_pTgraph_1.SetMarkerStyle(8)
photon90_PFHT500_pTgraph_1.SetMarkerColor(1)
photon90_PFHT500_pTgraph_1.Draw("SAME,p")

leg_1 = TLegend(.5,.2,.9,.4)
leg_1.SetFillColor(0)
leg_1.SetBorderSize(0)
leg_1.AddEntry(photon90_PFHT500_pTgraph_1,"HLT_Photon90_PFHT500_v1_HT400Sample","p")

leg_1.Draw()

CMSlabel.Draw()
setLumi(-1.)
SqrtSlumi.Draw()

canPt_1.SaveAs("Photon90efficienciesVersusPt_HTclean500_deltaPhiCuts_MHT200_HT400Sample.png")

############HT600


canHT_2 = TCanvas("canHT_2","canHT_2",500,500)

photon90_PFHT500_HT_2.SetMarkerStyle(8)
photon90_PFHT500_HT_2.SetMarkerColor(1)
photon90_PFHT500_HT_2.SetTitle(";HT [GeV];Efficiency")
photon90_PFHT500_HT_2.Draw()
legHT_2 = TLegend(.5,.2,.9,.4)
legHT_2.SetFillColor(0)
legHT_2.SetBorderSize(0)
legHT_2.AddEntry(photon90_PFHT500_HT_2,"HLT_Photon90_PFHT500_v1(HT600 Sample)","p")
legHT_2.Draw()
CMSlabel.Draw()
setLumi(-1.)
SqrtSlumi.Draw()
canHT_2.SaveAs("Photon90efficienciesVersusHT_Pt100_deltaPhiCuts_MHT200_HT600Sample.png")
canPt_2 = TCanvas("canPt_2","canPt_2",500,500)

gPad.Update()
photon90_PFHT500_pT_2.Draw()
gPad.Update()
photon90_PFHT500_pTgraph_2 = photon90_PFHT500_pT_2.GetPaintedGraph()
photon90_PFHT500_pTgraph_2.SetMarkerStyle(8)
photon90_PFHT500_pTgraph_2.SetMarkerColor(1)
photon90_PFHT500_pTgraph_2.Draw("SAME,p")

leg_2 = TLegend(.5,.2,.9,.4)
leg_2.SetFillColor(0)
leg_2.SetBorderSize(0)
leg_2.AddEntry(photon90_PFHT500_pTgraph_2,"HLT_Photon90_PFHT500_v1_HT600Sample","p")

leg_2.Draw()

CMSlabel.Draw()
setLumi(-1.)
SqrtSlumi.Draw()

canPt_2.SaveAs("Photon90efficienciesVersusPt_HTclean500_deltaPhiCuts_MHT200_HT600Sample.png")
