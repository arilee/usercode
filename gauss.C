{

  TRandom3 r;
  TH1 * h = new TH1F("h","h",100,-5,5);
  for(int i = 0; i < 100000; i++){
    double x = r.Gaus(0, 1);
    h->Fill(x);
  }
  h->Draw();
  h->SetStats(0);
  h->SetTitle("gaussian distribution");
  h->GetYaxis()->SetTitle("Entries");
  h->GetXaxis()->SetTitle("Mass (GeV)");
}

