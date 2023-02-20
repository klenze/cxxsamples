#include <iostream>
#include <vector>
#include <numeric>

#include <TFile.h>
#include <TTree.h>
#include <TLeaf.h>
#include <TH2.h>
int main()
{
  bool b;
  bool c=b;
/*
  if (b)
	std::cout << "hello!\n";
  auto* f=new TFile("califa_s509_main0209_0001_tree.root");
  auto* evt=f->Get<TTree>("evt");
  auto* enleaf=evt->GetLeaf("CalifaClusterCone.fEnergy");

  auto* hist=new TH2I("mult_vs_sum", "", 10, 0, 10, 100, 0, 5000);
  
  const int n=evt->GetEntriesFast();  
  for (int i=0; i<n; i++)
    {
      evt->GetEntry(i, 1);
      std::vector<double> energies;
      for (int p=0; p<enleaf->GetLen(); p++)
	     energies.push_back( enleaf->GetValue(p) );

      if (energies.size()==0)
	     continue;
      
      auto sum=std::accumulate(energies.begin(), energies.end(), 0.0);
      hist->Fill(energies.size(), sum);
    }

  auto* out=TFile::Open("hist.root", "recreate");
  out->WriteTObject(hist);
  out->Close();
*/
  return 0;
}

int memleak()
{
  return main();
}
