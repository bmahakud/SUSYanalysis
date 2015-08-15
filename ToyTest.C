from ROOT import *

### measurable
x = RooRealVar("x","x",0,100)

### signal model
gausMean = RooRealVar("mean","mean",40,0,70)
#gausMean.setConstant(True)
gausSigma = RooRealVar("sigma","sigma",10,0,50)
gausSigma.setConstant(True)
gauss = RooGaussian("gauss","gauss",x,gausMean,gausSigma)



### histograms for saving results
fitVal = TH1F("fitVal","fitVal Mean",100,0,100)
fitError = TH1F("fitError","fitError Mean",300,0,30)

fitValSigma = TH1F("fitValSigma","fitVal Sigma",50,0,50)
fitErrorSigma = TH1F("fitErrorSigma","fitError Sigma",30,-10,30)


### loop over n toys
for i in range(10) : 

    ### make sure to reset all of the floated parameters!
    gausMean.setVal(40)
    #gausSigma.setVal(10)
    ### generate a single toy dataset
    data = gauss.generate(RooArgSet(x),100)

    ### fit and grab results
    gauss.fitTo(data)
    
    ### fill fitted value
    fitVal.Fill( gausMean.getVal() )
    fitValSigma.Fill( gausSigma.getVal() )
    #print "Get Mean Value : ",gausMean.getVal()
   
    ### fill relative error from fit
    fitError.Fill( gausMean.getError() / gausMean.getVal() )
    fitErrorSigma.Fill( gausSigma.getError() / gausSigma.getVal() )


### plots everything
plot = x.frame()
data.plotOn(plot)
gauss.plotOn(plot)
gauss.paramOn(plot);

print "Chi square",plot.chiSquare()

canModel = TCanvas("canModel","canModel")
plot.Draw()

canFitVal = TCanvas("canFitVal","canFigVal",500,500)
fitVal.Draw()

canFitErr = TCanvas("canFitErr","canFitErr",500,500)
fitError.Draw()


canFitValSigma = TCanvas("canFitValSigma","canFigValSigma",500,500)
fitValSigma.Draw()

canFitErrSigma = TCanvas("canFitErrSigma","canFitErrSigma",500,500)
fitErrorSigma.Draw()

