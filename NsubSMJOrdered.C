void NsubSMJOrdered(){

gROOT->ProcessLine(".L tdrstyle.C");
setTDRStyle();

char tauNM[100];





sprintf(tauNM,"tau4/tau3");



int condition=1;

int n_sig_max=5000;
int n_bkg_max=10000;


double METPtcut=200;


TPaveText *tex1 = new TPaveText(0.204698,0.6377622,0.5043624,0.8863636,"brNDC");
tex1->SetBorderSize(0);
tex1->SetFillStyle(0);
tex1->SetTextAlign(11);
tex1->SetTextFont(42);
tex1->SetTextSize(0.04);
text = tex1->AddText("T1tttt,mGo=1500,mLSP=100");
text = tex1->AddText("HT > 500");
text = tex1->AddText("METpt > 400");
text = tex1->AddText("nLeptons==0");


TPaveText *tex2 = new TPaveText(0.504698,0.6377622,0.9043624,0.8863636,"brNDC");
tex2->SetBorderSize(0);
tex2->SetFillStyle(0);
tex2->SetTextAlign(11);
tex2->SetTextFont(42);
tex2->SetTextSize(0.04);
text = tex2->AddText("T1tttt,mGo=1200,mLSP=800");
text = tex2->AddText("HT > 500");
text = tex2->AddText("METpt > 400");
text = tex2->AddText("nLeptons==0");








double SMJcut=0;
double Jetptcut=0;




TH1F *h_tau_j1_sig= new TH1F("h_tau_j1_sig","1tau43",20,0.,1);
h_tau_j1_sig->SetLineColor(2);
h_tau_j1_sig->SetLineWidth(2);


TH1F *h_tau_j2_sig= new TH1F("h_tau_j2_sig","2tau43",20,0.,1);
h_tau_j2_sig->SetLineColor(2);
h_tau_j2_sig->SetLineWidth(2);


TH1F *h_tau_j3_sig= new TH1F("h_tau_j3_sig","3tau43",20,0.,1);
h_tau_j3_sig->SetLineColor(2);
h_tau_j3_sig->SetLineWidth(2);


TH1F *h_tau_j4_sig= new TH1F("h_tau_j4_sig","4tau43",20,0.,1);
h_tau_j4_sig->SetLineColor(2);
h_tau_j4_sig->SetLineWidth(2);


TH1F *h_Evsub_sig= new TH1F("h_Evsub_sig","Ev_sub_sig",50,0.,1);
h_Evsub_sig->SetLineColor(2);
h_Evsub_sig->SetLineWidth(2);


TH1F *h_sig_j1= new TH1F("h_sig_j1","NsubJets_sig_j1",10,0.,10);
h_sig_j1->SetLineColor(2);
h_sig_j1->SetLineWidth(2);

TH1F *h_sig_j2= new TH1F("h_sig_j2","NsubJets_sig_j2",10,0.,10);
h_sig_j2->SetLineColor(2);
h_sig_j2->SetLineWidth(2);

TH1F *h_sig_j3= new TH1F("h_sig_j3","NsubJets_sig_j3",10,0.,10);
h_sig_j3->SetLineColor(2);
h_sig_j3->SetLineWidth(2);


TH1F *h_sig_j4= new TH1F("h_sig_j4","NsubJets_sig_j4",10,0.,10);
h_sig_j4->SetLineColor(2);
h_sig_j4->SetLineWidth(2);


TH1F *h_sig_njets= new TH1F("h_sig_njets","NsubJets_sig_njets",20,0.,20);
h_sig_njets->SetLineColor(2);
h_sig_njets->SetLineWidth(2);



////////////////////////////////////starts background

TH1F *h_tau_j1_bkg= new TH1F("h_tau_j1_bkg","Leading pT Jet ",20,0.,1);
h_tau_j1_bkg->SetLineWidth(2);
h_tau_j1_bkg->SetLineColor(4);
h_tau_j1_bkg->GetXaxis()->SetTitle(tauNM);


TH1F *h_tau_j2_bkg= new TH1F("h_tau_j2_bkg","2nd Leading pT Jet",20,0.,1);
h_tau_j2_bkg->SetLineWidth(2);
h_tau_j2_bkg->SetLineColor(4);
h_tau_j2_bkg->GetXaxis()->SetTitle(tauNM);

TH1F *h_tau_j3_bkg= new TH1F("h_tau_j3_bkg","3rd Leading pT Jet",20,0.,1);
h_tau_j3_bkg->SetLineWidth(2);
h_tau_j3_bkg->SetLineColor(4);
h_tau_j3_bkg->GetXaxis()->SetTitle(tauNM);


TH1F *h_tau_j4_bkg= new TH1F("h_tau_j4_bkg","4th Leading pT Jet",20,0.,1);
h_tau_j4_bkg->SetLineWidth(2);
h_tau_j4_bkg->SetLineColor(4);
h_tau_j4_bkg->GetXaxis()->SetTitle(tauNM);


TH1F *h_Evsub_bkg= new TH1F("h_Evsub_bkg","Event subjettiness",50,0.,1);
h_Evsub_bkg->SetLineWidth(2);
h_Evsub_bkg->SetLineColor(4);
h_Evsub_bkg->GetXaxis()->SetTitle("Event Subjettiness");


TH1F *h_bkg_j1= new TH1F("h_bkg_j1","Leading pT Jet",10,0.,10);
h_bkg_j1->SetLineColor(4);
h_bkg_j1->SetLineWidth(2);
h_bkg_j1->GetXaxis()->SetTitle("nSubjets");


TH1F *h_bkg_j2= new TH1F("h_bkg_j2","2nd Leading pT Jet",10,0.,10);
h_bkg_j2->SetLineColor(4);
h_bkg_j2->SetLineWidth(2);
h_bkg_j2->GetXaxis()->SetTitle("nSubjets");


TH1F *h_bkg_j3= new TH1F("h_bkg_j3","3rd Leading pT Jet",10,0.,10);
h_bkg_j3->SetLineColor(4);
h_bkg_j3->SetLineWidth(2);
h_bkg_j3->GetXaxis()->SetTitle("nSubjets");


TH1F *h_bkg_j4= new TH1F("h_bkg_j4","4th Leading pT Jet",10,0.,10);
h_bkg_j4->SetLineColor(4);
h_bkg_j4->SetLineWidth(2);
h_bkg_j4->GetXaxis()->SetTitle("nSubjets");



TH1F *h_bkg_njets= new TH1F("h_bkg_njets","NsubJets_bkg_njets",20,0.,20);
h_bkg_njets->SetLineColor(4);
h_bkg_njets->SetLineWidth(2);
h_bkg_njets->GetXaxis()->SetTitle("n_skinny jets");












TChain* SIGtree_T1tttt= new TChain("TreeMaker2/PreSelection");
SIGtree_T1tttt->Add("T1tttt_mGo1500_mLSP100_RA2AnalysisTree_lowerCut_*.root");


TChain* BKGtree_bkg= new TChain("TreeMaker2/PreSelection");
BKGtree_bkg->Add("TTbar_RA2AnalysisTree_*.root");

vector<double> *tau1_ak12_sig;
vector<double> *tau2_ak12_sig;
vector<double> *tau3_ak12_sig;
vector<double> *tau4_ak12_sig;

vector<double> *Px_sig;
vector<double> *Py_sig;
vector<double> *Pz_sig;
vector<double> *E_sig;


vector<int> *nsubjets_sig;


Float_t  ak1p2Jets_sumJetMass_sig;
Int_t Njets_sig;
Float_t ht_sig;
Float_t MetJM_sig;
Int_t leptons_sig;


SIGtree_T1tttt->SetBranchAddress("ak12Jets_tau1",&tau1_ak12_sig);
SIGtree_T1tttt->SetBranchAddress("ak12Jets_tau2",&tau2_ak12_sig);
SIGtree_T1tttt->SetBranchAddress("ak12Jets_tau3",&tau3_ak12_sig);
SIGtree_T1tttt->SetBranchAddress("ak12Jets_tau4",&tau4_ak12_sig);
SIGtree_T1tttt->SetBranchAddress("n_Subjetsak12",&nsubjets_sig);
SIGtree_T1tttt->SetBranchAddress("ak1p2Jets_sumJetMass",&ak1p2Jets_sumJetMass_sig);


SIGtree_T1tttt->SetBranchAddress("ak12Jets_Px",&Px_sig);
SIGtree_T1tttt->SetBranchAddress("ak12Jets_Py",&Py_sig);
SIGtree_T1tttt->SetBranchAddress("ak12Jets_Pz",&Pz_sig);
SIGtree_T1tttt->SetBranchAddress("ak12Jets_E",&E_sig);


SIGtree_T1tttt->SetBranchAddress("NJets",&Njets_sig);
SIGtree_T1tttt->SetBranchAddress("Leptons",&leptons_sig);
SIGtree_T1tttt->SetBranchAddress("HT",&ht_sig);
SIGtree_T1tttt->SetBranchAddress("METPt",&MetJM_sig);



vector<double> *tau1_ak12_bkg;
vector<double> *tau2_ak12_bkg;
vector<double> *tau3_ak12_bkg;
vector<double> *tau4_ak12_bkg;

vector<double> *Px_bkg;
vector<double> *Py_bkg;
vector<double> *Pz_bkg;
vector<double> *E_bkg;



vector<int> *nsubjets_bkg;

Float_t  ak1p2Jets_sumJetMass_bkg;
Int_t Njets_bkg;
Float_t ht_bkg;
Float_t MetJM_bkg;
Int_t leptons_bkg;


BKGtree_bkg->SetBranchAddress("ak12Jets_tau1",&tau1_ak12_bkg);
BKGtree_bkg->SetBranchAddress("ak12Jets_tau2",&tau2_ak12_bkg);
BKGtree_bkg->SetBranchAddress("ak12Jets_tau3",&tau3_ak12_bkg);
BKGtree_bkg->SetBranchAddress("ak12Jets_tau4",&tau4_ak12_bkg);
BKGtree_bkg->SetBranchAddress("n_Subjetsak12",&nsubjets_bkg);
BKGtree_bkg->SetBranchAddress("ak1p2Jets_sumJetMass",&ak1p2Jets_sumJetMass_bkg);

BKGtree_bkg->SetBranchAddress("ak12Jets_Px",&Px_bkg);
BKGtree_bkg->SetBranchAddress("ak12Jets_Py",&Py_bkg);
BKGtree_bkg->SetBranchAddress("ak12Jets_Pz",&Pz_bkg);
BKGtree_bkg->SetBranchAddress("ak12Jets_E",&E_bkg);



BKGtree_bkg->SetBranchAddress("NJets",&Njets_bkg);
BKGtree_bkg->SetBranchAddress("Leptons",&leptons_bkg);
BKGtree_bkg->SetBranchAddress("HT",&ht_bkg);
BKGtree_bkg->SetBranchAddress("METPt",&MetJM_bkg);


int n_sig = (int) SIGtree_T1tttt->GetEntries();

int n_bkg = (int) BKGtree_bkg->GetEntries();



if(condition==0){
n_sig_max=n_sig;
n_bkg_max=n_bkg;
}




for (int i = 0; i < n_sig_max ; ++i) {//loop over signal entries 




SIGtree_T1tttt->GetEntry(i);
if(i%5000==0)cout<<"Running on Signal Event no = "<<i<<endl;


unsigned int jet_no1_sig=0;
unsigned int jet_no2_sig=0;
unsigned int jet_no3_sig=0;
unsigned int jet_no4_sig=0;

double JMlead1_sig=0.0;
double JMlead2_sig=0.0;
double JMlead3_sig=0.0;
double JMlead4_sig=0.0;
//cout<<"test1 "<<endl;

//////////////////////////////////////////***********
for(int j1=0;j1<Px_sig->size();j1++){//Leading pT Jet postion

double Px=Px_sig->at(j1);
double Py=Py_sig->at(j1);
double Pz=Pz_sig->at(j1);
double E=E_sig->at(j1);

double JM_sig=sqrt(E*E-(Px*Px+Py*Py+Pz*Pz));



if(JM_sig > JMlead1_sig ){
JMlead1_sig=JM_sig;
jet_no1_sig=j1;

} 

}//Leading pT Jet position

//cout<<"test2 "<<endl;

///////////////////////////////////////.........


//////////////////////////////////////****

for(int j2=0;j2<Px_sig->size();j2++){//2nd Leading pT Jet postion
//cout<<"test3 "<<endl;
double Px=Px_sig->at(j2);
double Py=Py_sig->at(j2);

double Pz=Pz_sig->at(j2);
double E=E_sig->at(j2);

double JM_sig=sqrt(E*E-(Px*Px+Py*Py+Pz*Pz));



if(JM_sig > JMlead2_sig && JM_sig !=JMlead1_sig){
JMlead2_sig=JM_sig;
jet_no2_sig=j2;

} 

}//2nd Leading pT Jet position

//cout<<"test4 "<<endl;


///////////////////////////////////////.....


////////////////////////////////*************

for(int j3=0;j3<Px_sig->size();j3++){//3rd Leading pT Jet postion

double Px=Px_sig->at(j3);
double Py=Py_sig->at(j3);

double Pz=Pz_sig->at(j3);
double E=E_sig->at(j3);

double JM_sig=sqrt(E*E-(Px*Px+Py*Py+Pz*Pz));



if(JM_sig > JMlead3_sig && JM_sig !=JMlead1_sig && JM_sig !=JMlead2_sig ){
JMlead3_sig=JM_sig;
jet_no3_sig=j3;

} 

}//3rd Leading pT Jet position






////////////////////////////////..................


for(int j4=0;j4<Px_sig->size();j4++){//4th Leading pT Jet postion

double Px=Px_sig->at(j4);
double Py=Py_sig->at(j4);

double Pz=Pz_sig->at(j4);
double E=E_sig->at(j4);

double JM_sig=sqrt(E*E-(Px*Px+Py*Py+Pz*Pz));

//cout<<"Jet Pt = "<<JM_sig<<endl;

if(JM_sig > JMlead4_sig && JM_sig !=JMlead1_sig && JM_sig !=JMlead2_sig && JM_sig !=JMlead3_sig && JM_sig){
JMlead4_sig=JM_sig;
jet_no4_sig=j4;

} 

}//4th Leading pT Jet position



//cout<<"Jet no 4 = "<<jet_no4_sig<<endl;
//cout<<"4th Leading pT Jet = "<<JMlead4_sig<<endl;



///////////////////////***************************


if (ht_sig > 500.0 && MetJM_sig > METPtcut && Njets_sig >= 3 && leptons_sig ==0){



double tau43j1_sig=tau4_ak12_sig->at(jet_no1_sig)/tau3_ak12_sig->at(jet_no1_sig);
double tau43j2_sig=tau4_ak12_sig->at(jet_no2_sig)/tau3_ak12_sig->at(jet_no2_sig);
double tau43j3_sig=tau4_ak12_sig->at(jet_no3_sig)/tau3_ak12_sig->at(jet_no3_sig);
double tau43j4_sig=tau4_ak12_sig->at(jet_no4_sig)/tau3_ak12_sig->at(jet_no4_sig);

h_tau_j1_sig->Fill(tau43j1_sig);

h_tau_j2_sig->Fill(tau43j2_sig);

h_tau_j3_sig->Fill(tau43j3_sig);

h_tau_j4_sig->Fill(tau43j4_sig);


h_sig_j1->Fill(nsubjets_sig->at(jet_no1_sig));

h_sig_j2->Fill(nsubjets_sig->at(jet_no2_sig));
h_sig_j3->Fill(nsubjets_sig->at(jet_no3_sig));
h_sig_j4->Fill(nsubjets_sig->at(jet_no4_sig));

h_sig_njets->Fill(Njets_sig);

double Ev_sub_sig=sqrt(sqrt(tau43j1_sig*tau43j2_sig*tau43j3_sig*tau43j4_sig));

h_Evsub_sig->Fill(Ev_sub_sig);

}


//}//pt cut 




}//loop over signal entries



//::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::         Running on Background                    ::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::


for (int i = 0; i < n_bkg_max; ++i) {//loop over bkgnal entries 

BKGtree_bkg->GetEntry(i);
if(i%5000==0)cout<<"Running on BKG Event no = "<<i<<endl;
if(ak1p2Jets_sumJetMass_bkg > SMJcut){//sum Jet mass cut















unsigned int jet_no1_bkg=0;
unsigned int jet_no2_bkg=0;
unsigned int jet_no3_bkg=0;
unsigned int jet_no4_bkg=0;

double JMlead1_bkg=0.0;
double JMlead2_bkg=0.0;
double JMlead3_bkg=0.0;
double JMlead4_bkg=0.0;


//////////////////////////////////////////***********
for(int j1=0;j1<Px_bkg->size();j1++){//Leading pT Jet postion

double Px=Px_bkg->at(j1);
double Py=Py_bkg->at(j1);
double Pz=Pz_bkg->at(j1);
double E=E_bkg->at(j1);


double JM_bkg=sqrt(E*E-(Px*Px+Py*Py+Pz*Pz));



if(JM_bkg > JMlead1_bkg){
JMlead1_bkg=JM_bkg;
jet_no1_bkg=j1;

} 

}//Leading pT Jet position



///////////////////////////////////////.........


//////////////////////////////////////****

for(int j2=0;j2<Px_bkg->size();j2++){//2nd Leading pT Jet postion

double Px=Px_bkg->at(j2);
double Py=Py_bkg->at(j2);
double Pz=Pz_bkg->at(j2);
double E=E_bkg->at(j2);


double JM_bkg=sqrt(E*E-(Px*Px+Py*Py+Pz*Pz));



if(JM_bkg > JMlead2_bkg && JM_bkg !=JMlead1_bkg ){
JMlead2_bkg=JM_bkg;
jet_no2_bkg=j2;

} 

}//2nd Leading pT Jet position




///////////////////////////////////////.....


////////////////////////////////*************

for(int j3=0;j3<Px_bkg->size();j3++){//3rd Leading pT Jet postion

double Px=Px_bkg->at(j3);
double Py=Py_bkg->at(j3);
double Pz=Pz_bkg->at(j3);
double E=E_bkg->at(j3);


double JM_bkg=sqrt(E*E-(Px*Px+Py*Py+Pz*Pz));



if(JM_bkg > JMlead3_bkg && JM_bkg !=JMlead1_bkg && JM_bkg !=JMlead2_bkg ){
JMlead3_bkg=JM_bkg;
jet_no3_bkg=j3;

} 

}//3rd Leading pT Jet position






////////////////////////////////..................


for(int j4=0;j4<Px_bkg->size();j4++){//4th Leading pT Jet postion

double Px=Px_bkg->at(j4);
double Py=Py_bkg->at(j4);
double Pz=Pz_bkg->at(j4);
double E=E_bkg->at(j4);


double JM_bkg=sqrt(E*E-(Px*Px+Py*Py+Pz*Pz));

//cout<<"Jet Pt = "<<JM_bkg<<endl;

if(JM_bkg > JMlead4_bkg && JM_bkg !=JMlead1_bkg && JM_bkg !=JMlead2_bkg && JM_bkg !=JMlead3_bkg ){
JMlead4_bkg=JM_bkg;
jet_no4_bkg=j4;

} 

}//4th Leading pT Jet position



//cout<<"Jet no 4 = "<<jet_no4_bkg<<endl;
//cout<<"4th Leading pT Jet = "<<JMlead4_bkg<<endl;



///////////////////////***************************


if (ht_bkg > 500.0 && MetJM_bkg > METPtcut && Njets_bkg >= 3 && leptons_bkg ==0){



double tau43j1_bkg=tau4_ak12_bkg->at(jet_no1_bkg)/tau3_ak12_bkg->at(jet_no1_bkg);
double tau43j2_bkg=tau4_ak12_bkg->at(jet_no2_bkg)/tau3_ak12_bkg->at(jet_no2_bkg);
double tau43j3_bkg=tau4_ak12_bkg->at(jet_no3_bkg)/tau3_ak12_bkg->at(jet_no3_bkg);
double tau43j4_bkg=tau4_ak12_bkg->at(jet_no4_bkg)/tau3_ak12_bkg->at(jet_no4_bkg);

h_tau_j1_bkg->Fill(tau43j1_bkg);

h_tau_j2_bkg->Fill(tau43j2_bkg);

h_tau_j3_bkg->Fill(tau43j3_bkg);

h_tau_j4_bkg->Fill(tau43j4_bkg);


h_bkg_j1->Fill(nsubjets_bkg->at(jet_no1_bkg));

h_bkg_j2->Fill(nsubjets_bkg->at(jet_no2_bkg));
h_bkg_j3->Fill(nsubjets_bkg->at(jet_no3_bkg));
h_bkg_j4->Fill(nsubjets_bkg->at(jet_no4_bkg));

h_bkg_njets->Fill(Njets_bkg);

double Ev_sub_bkg=sqrt(sqrt(tau43j1_bkg*tau43j2_bkg*tau43j3_bkg*tau43j4_bkg));

h_Evsub_bkg->Fill(Ev_sub_bkg);

}





}//sum Jet mass cut 

}//loop over bkgnal entries






h_tau_j1_sig->Scale(1/h_tau_j1_sig->Integral());
h_tau_j2_sig->Scale(1/h_tau_j2_sig->Integral());
h_tau_j3_sig->Scale(1/h_tau_j3_sig->Integral());
h_tau_j4_sig->Scale(1/h_tau_j4_sig->Integral());

h_sig_j1->Scale(1/h_sig_j1->Integral());
h_sig_j2->Scale(1/h_sig_j2->Integral());
h_sig_j3->Scale(1/h_sig_j3->Integral());
h_sig_j4->Scale(1/h_sig_j4->Integral());

h_sig_njets->Scale(1/h_sig_njets->Integral());


h_Evsub_sig->Scale(1/h_Evsub_sig->Integral());


h_tau_j1_bkg->Scale(1/h_tau_j1_bkg->Integral());
h_tau_j2_bkg->Scale(1/h_tau_j2_bkg->Integral());
h_tau_j3_bkg->Scale(1/h_tau_j3_bkg->Integral());
h_tau_j4_bkg->Scale(1/h_tau_j4_bkg->Integral());

h_Evsub_bkg->Scale(1/h_Evsub_bkg->Integral());

h_bkg_j1->Scale(1/h_bkg_j1->Integral());
h_bkg_j2->Scale(1/h_bkg_j2->Integral());
h_bkg_j3->Scale(1/h_bkg_j3->Integral());
h_bkg_j4->Scale(1/h_bkg_j4->Integral());

h_bkg_njets->Scale(1/h_bkg_njets->Integral());




char Legname1[100];
TLegend *leg_tau[10];
for(int k0=0;k0<10;k0++){
sprintf(Legname1,"leg_tau%i",k0);
leg_tau[k0]=new TLegend(0.2248322,0.5052448,0.4244966,0.6562937);
leg_tau[k0]->SetTextFont(62);
leg_tau[k0]->SetTextSize(0.04);
leg_tau[k0]->SetLineColor(1);
leg_tau[k0]->SetLineStyle(1);
leg_tau[k0]->SetLineWidth(7);
leg_tau[k0]->SetFillColor(0);
leg_tau[k0]->SetFillStyle(1001);
leg_tau[k0]->SetShadowColor(0);
leg_tau[k0]->SetDrawOption(0);
leg_tau[k0]->SetBorderSize(0);
}



char Legname1nsjet[100];
TLegend *leg_nsjet[10];
for(int k0=0;k0<10;k0++){
sprintf(Legname1nsjet,"leg_nsjet%i",k0);
leg_nsjet[k0]=new TLegend(0.608322,0.5052448,0.94966,0.6562937);
leg_nsjet[k0]->SetTextFont(62);
leg_nsjet[k0]->SetTextSize(0.04);
leg_nsjet[k0]->SetLineColor(1);
leg_nsjet[k0]->SetLineStyle(1);
leg_nsjet[k0]->SetLineWidth(7);
leg_nsjet[k0]->SetFillColor(0);
leg_nsjet[k0]->SetFillStyle(1001);
leg_nsjet[k0]->SetShadowColor(0);
leg_nsjet[k0]->SetDrawOption(0);
leg_nsjet[k0]->SetBorderSize(0);
}









leg_tau[0]->AddEntry(h_tau_j1_sig,"T1tttt,1st Jet","l");
leg_tau[0]->AddEntry(h_tau_j1_bkg,"ttbar,1st Jet","l");

leg_tau[1]->AddEntry(h_tau_j2_sig,"T1tttt,2nd Jet","l");
leg_tau[1]->AddEntry(h_tau_j2_bkg,"ttbar,2nd Jet","l");

leg_tau[2]->AddEntry(h_tau_j3_sig,"T1tttt,3rd Jet","l");
leg_tau[2]->AddEntry(h_tau_j3_bkg,"ttbar,3rd Jet","l");

leg_tau[3]->AddEntry(h_tau_j4_sig,"T1tttt,4th Jet","l");
leg_tau[3]->AddEntry(h_tau_j4_bkg,"ttbar,4th Jet","l");



leg_nsjet[0]->AddEntry(h_sig_j1,"T1tttt,1st Jet","l");
leg_nsjet[0]->AddEntry(h_bkg_j1,"ttbar,1st Jet","l");

leg_nsjet[1]->AddEntry(h_sig_j2,"T1tttt,2nd Jet","l");
leg_nsjet[1]->AddEntry(h_bkg_j2,"ttbar,2nd Jet","l");

leg_nsjet[2]->AddEntry(h_sig_j3,"T1tttt,3rd Jet","l");
leg_nsjet[2]->AddEntry(h_bkg_j3,"ttbar,3rd Jet","l");

leg_nsjet[3]->AddEntry(h_sig_j4,"T1tttt,4th Jet","l");
leg_nsjet[3]->AddEntry(h_bkg_j4,"ttbar,4th Jet","l");

leg_tau[4]->AddEntry(h_Evsub_sig,"T1tttt","l");
leg_tau[4]->AddEntry(h_Evsub_bkg,"ttbar","l");


leg_nsjet[5]->AddEntry(h_sig_njets,"T1tttt","l");
leg_nsjet[5]->AddEntry(h_bkg_njets,"ttbar","l");


/////////Plotting on Canvases

TCanvas *c1=new TCanvas("c1","c1");
c1->Divide(2,2);

TCanvas *c2=new TCanvas("c2","c2");
c2->Divide(2,2);

TCanvas *c3=new TCanvas("c3","c3");
//c3->cd(2,2);
TCanvas *c4=new TCanvas("c4","c4");

TCanvas *c5=new TCanvas("c5","c5");
c5->Divide(1,2);


c1->cd(1);
h_tau_j1_bkg->Draw();
h_tau_j1_sig->Draw("SAME");
leg_tau[0]->Draw();
tex1->Draw();


c1->cd(2);
h_bkg_j1->Draw();
h_sig_j1->Draw("SAME");
leg_nsjet[0]->Draw();
tex2->Draw();


c1->cd(3);

h_tau_j2_bkg->Draw();
h_tau_j2_sig->Draw("SAME");
leg_tau[1]->Draw();
tex1->Draw();


c1->cd(4);

h_bkg_j2->Draw();
h_sig_j2->Draw("SAME");
leg_nsjet[1]->Draw();
tex2->Draw();

c2->cd(1);
h_tau_j3_bkg->Draw();
h_tau_j3_sig->Draw("SAME");
leg_tau[2]->Draw();
tex1->Draw();


c2->cd(2);
h_bkg_j3->Draw();
h_sig_j3->Draw("SAME");
leg_nsjet[2]->Draw();
tex2->Draw();
c2->cd(3);
h_tau_j4_bkg->Draw();
h_tau_j4_sig->Draw("SAME");
leg_tau[3]->Draw();
tex1->Draw();
c2->cd(4);



h_bkg_j4->Draw();
h_sig_j4->Draw("SAME");
leg_nsjet[3]->Draw();
tex2->Draw();


c3->cd();

h_Evsub_bkg->Draw();
h_Evsub_sig->Draw("SAME");
leg_tau[4]->Draw();
tex1->Draw();


c4->cd();
h_bkg_njets->Draw();
h_sig_njets->Draw("SAME");
leg_nsjet[5]->Draw();
tex2->Draw();



h_tau_j1_bkg->GetXaxis()->SetTitle("1-#tau_{43}");

c5->cd(1);
h_tau_j1_bkg->Draw();
h_tau_j1_sig->Draw("SAME");
leg_tau[0]->Draw();
tex1->Draw();



c5->cd(2);
h_bkg_njets->Draw();
h_sig_njets->Draw("SAME");
leg_nsjet[5]->Draw();
tex2->Draw();






//////////////

}
