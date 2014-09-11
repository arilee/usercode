{
   cout << " Hello" << endl;
   float x = 3.;
   float y = 5.;
   int   i = 101;
   cout <<" x = "<<x<<" y = "<<y<<" i = "<<i<< endl;

  TH1 *h = new TH1F("h","h",10, 0, 10);

  int sum = 0;
  for( int i = 0; i < 10; i++){
    sum = sum + i;
    h->Fill(i);
  }
  h->Fill(3);

  h->Draw();
  cout << "sum from 0 to 10 = " << sum << endl;


}
