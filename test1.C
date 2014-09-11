{
	TH1 *h = new TH1F("h","h",100,0,100);
	int sum = 0;
	for (int i=1; i<101; i++){
		if (i%2 == 0){
			sum = sum + i;
			h->Fill(i);
		}
	}
	cout << sum <<endl;
	h->Draw();

}

