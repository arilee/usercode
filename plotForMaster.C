void plotForMaster(){

  const int n = 4;

  TFile * f[n];
  f[0] = new TFile("vallot_SingleMuon_Run2015Dprompt_25ns.root");
  f[1] = new TFile("vallot_WJets_25ns.root");
  f[2] = new TFile("vallot_TTJets_aMC_25ns.root");
  f[3] = new TFile("vallot_ZJets_25ns.root");

  TTree * tree[n];

  for(int i = 0; i < n; i++){
    tree[i] = (TTree*) f[i]->Get("ttbarSingleLepton/tree");
  }

  TH1 * h_MET[n] ;

  for(int i = 0; i < n ; i++){
    h_MET[i] = new TH1F(Form("h_MET_%d",i),"MET distribution",20,0,200);
  }

  for(int i = 0; i < n ; i++){
    tree[i]->Project(Form("h_MET_%d",i),"Wmass");
  }

  double scale[n];
  scale[0] = 1.0;
  scale[1] = 61526.7 / 23577656.0 * 1263.0;
  scale[2] = 831.7 / 42784971.0 * 1263.0;
  scale[3] = 6025.2 / 26653505.0 * 1263.0;

  for(int i = 1; i < n; i++){
  h_MET[i]->Scale(scale[i]);
  }

  /*h_MET[1]->Draw();
  h_MET[2]->Draw("Same");
  h_MET[3]->Draw("Same");
  h_MET[0]->Draw("SameP");
  */

  TCanvas * c1 = new TCanvas();
  c1->cd();
  THStack *hs = new THStack("hs","");

  h_MET[0]->SetMarkerSize(0.4);
  h_MET[0]->SetMarkerStyle(20);
  h_MET[1]->SetFillColor(3);
  h_MET[2]->SetFillColor(2);
  h_MET[3]->SetFillColor(4);

  hs->Add(h_MET[1]);
  hs->Add(h_MET[2]);
  hs->Add(h_MET[3]);
  hs->Add(h_MET[0]);
  hs->Draw();

}
