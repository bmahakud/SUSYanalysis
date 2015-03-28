from ROOT import *

gROOT.ProcessLine(".L tdrstyle.C")
gROOT.ProcessLine("setTDRStyle()")

def combineSamples(total , histoA , weightA , histoB , weightB ):

    for i in range(total.GetNbinsX()):
        weightedSum = histoA.GetBinContent(i+1) * weightA + histoB.GetBinContent(i+1)*weightB
        total.SetBinContent(i+1, weightedSum)
        errorA = sqrt(histoA.GetBinContent(i+1))
        errorB = sqrt(histoB.GetBinContent(i+1))
        error = sqrt( weightA*weightA*errorA*errorA + weightB*weightB*errorB*errorB )
        total.SetBinError(i+1, error) 

    return total





fGJets400 = TFile("BaseLineVars.root")
fGJets600 = TFile("BaseLineVars.root")
fZinv400 = TFile("BaseLineVars.root")
fZinv600 = TFile("BaseLineVars.root")





Zinv400dPhi1 = TH1F( fZinv400.Get("dPhi1binZ400") )

Zinv600dPhi1 = TH1F( fZinv600.Get("dPhi1binZ600") )

ZinvdPhi1 = TH1F( Zinv400dPhi1  )
ZinvdPhi1.SetNameTitle("ZinvdPhi1","ZinvdPhi1")
ZinvdPhi1.GetXaxis().SetTitle("#Delta #Phi_{1}")
ZinvdPhi1.GetYaxis().SetTitle("Events")
combineSamples(ZinvdPhi1,Zinv400dPhi1,0.0144160859953796,Zinv600dPhi1,0.00489467814129328)



Zinv400dPhi2 = TH1F( fZinv400.Get("dPhi2binZ400") )

Zinv600dPhi2 = TH1F( fZinv600.Get("dPhi2binZ600") )


ZinvdPhi2 = TH1F( Zinv400dPhi2  )
ZinvdPhi2.SetNameTitle("ZinvdPhi2","ZinvdPhi2")
ZinvdPhi2.GetXaxis().SetTitle("#Delta #Phi_{2}")
ZinvdPhi2.GetYaxis().SetTitle("Events")
combineSamples(ZinvdPhi2,Zinv400dPhi2,0.0144160859953796,Zinv600dPhi2,0.00489467814129328)



Zinv400dPhi3 = TH1F( fZinv400.Get("dPhi3binZ400") )

Zinv600dPhi3 = TH1F( fZinv600.Get("dPhi3binZ600") )


ZinvdPhi3 = TH1F( Zinv400dPhi3  )
ZinvdPhi3.SetNameTitle("ZinvdPhi3","ZinvdPhi3")
ZinvdPhi3.GetXaxis().SetTitle("#Delta #Phi_{3}")
ZinvdPhi3.GetYaxis().SetTitle("Events")
combineSamples(ZinvdPhi3,Zinv400dPhi3,0.0144160859953796,Zinv600dPhi3,0.00489467814129328)



Zinv400mindPhiN = TH1F( fZinv400.Get("mindPhiNbinZ400") )

Zinv600mindPhiN = TH1F( fZinv600.Get("mindPhiNbinZ600") )


ZinvmindPhiN = TH1F( Zinv400mindPhiN )
ZinvmindPhiN.SetNameTitle("ZinvmindPhiN","ZinvmindPhiN")
ZinvmindPhiN.GetXaxis().SetTitle("min#Delta #Phi_{N}")
ZinvmindPhiN.GetYaxis().SetTitle("Events")

combineSamples(ZinvmindPhiN,Zinv400mindPhiN,0.0144160859953796,Zinv600mindPhiN,0.00489467814129328)



GJets400dPhi1 = TH1F( fGJets400.Get("dPhi1binG400") )

GJets600dPhi1 = TH1F( fGJets600.Get("dPhi1binG600") )

GJetsdPhi1 = TH1F( GJets400dPhi1  )
GJetsdPhi1.SetNameTitle("GJetsdPhi1","GJetsdPhi1")
GJetsdPhi1.GetXaxis().SetTitle("#Delta #Phi_{1}")
GJetsdPhi1.GetYaxis().SetTitle("Events")
combineSamples(GJetsdPhi1,GJets400dPhi1,0.075604015773398,GJets600dPhi1,0.0261385093009007)



GJets400dPhi2 = TH1F( fGJets400.Get("dPhi2binG400") )

GJets600dPhi2 = TH1F( fGJets600.Get("dPhi2binG600") )


GJetsdPhi2 = TH1F( GJets400dPhi2  )
GJetsdPhi2.SetNameTitle("GJetsdPhi2","GJetsdPhi2")
GJetsdPhi2.GetXaxis().SetTitle("#Delta #Phi_{2}")
GJetsdPhi2.GetYaxis().SetTitle("Events")
combineSamples(GJetsdPhi2,GJets400dPhi2,0.075604015773398,GJets600dPhi2,0.0261385093009007)



GJets400dPhi3 = TH1F( fGJets400.Get("dPhi3binG400") )

GJets600dPhi3 = TH1F( fGJets600.Get("dPhi3binG600") )


GJetsdPhi3 = TH1F( GJets400dPhi3  )
GJetsdPhi3.SetNameTitle("GJetsdPhi3","GJetsdPhi3")
GJetsdPhi3.GetXaxis().SetTitle("#Delta #Phi_{3}")
GJetsdPhi3.GetYaxis().SetTitle("Events")
combineSamples(GJetsdPhi3,GJets400dPhi3,0.075604015773398,GJets600dPhi3,0.0261385093009007)



GJets400mindPhiN = TH1F( fGJets400.Get("mindPhiNbinG400") )

GJets600mindPhiN = TH1F( fGJets600.Get("mindPhiNbinG600") )


GJetsmindPhiN = TH1F( GJets400mindPhiN )
GJetsmindPhiN.SetNameTitle("GJetsmindPhiN","GJetsmindPhiN")
GJetsmindPhiN.GetXaxis().SetTitle("min#Delta #Phi_{N}")
GJetsmindPhiN.GetYaxis().SetTitle("Events")
combineSamples(GJetsmindPhiN,GJets400mindPhiN,0.075604015773398,GJets600mindPhiN,0.0261385093009007)




can1 = TCanvas("can1","can1",500,500)

ZinvdPhi1.Draw("hist,e1")


can2 = TCanvas("can2","can2",500,500)

ZinvdPhi2.Draw("hist,e1")


can3 = TCanvas("can3","can3",500,500)

ZinvdPhi3.Draw("hist,e1")


can4 = TCanvas("can4","can4",500,500)

GJetsdPhi1.Draw("hist,e1")


can5 = TCanvas("can5","can5",500,500)

GJetsdPhi2.Draw("hist,e1")

can6 = TCanvas("can6","can6",500,500)

GJetsdPhi3.Draw("hist,e1")


canMinDPhiG = TCanvas("canMinDPhiNG","canMinDPhiG",500,500)

GJetsmindPhiN.Draw("hist,e1")


canMinDPhiZ = TCanvas("canMinDPhiNZ","canMinDPhiZ",500,500)

ZinvmindPhiN.Draw("hist,e1")








