
void one_dim_array()
{
  double a[20];
  for (int i=0; i<=20; i++)
    a[i]=NAN;
}


void binomials(int max)
  {
    int binomials[max][max];

    for (int i=0; i<max; i++)
      for (int j=0; j<max; j++)
	binomials[i][j]=0;
    
    for (int i=0; i<=max; i++)
      {
	binomials[i][0]=1;
	for (int j=1; j<=i; j++)
	  {
	    binomials[i][j]=binomials[i-1][j-1]+binomials[i-1][j];
	  }
	binomials[i][i]=1;
      }
    for (int i=0; i<max; i++)
      {
	for (int j=0; j<=i; j++)
	  std::cout << " " << binomials[i][j];
	std::cout << "\n";
      }
  }


void dump_hist(int det, int ch)
{
  char buf[10];
  sprintf(buf, "hist_%03d_%02d", det, ch);
  auto f=TFile::Open("foo.root");
  auto h=(TH2I*)(f->Get(buf));
  h->Print();
}

int c_stuff()
{
  one_dim_array();
  binomials(8);
  dump_hist(2, 8);
  return 0;
}
