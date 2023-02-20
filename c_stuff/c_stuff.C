#include <iostream>
#include <cstdio>
#include <TFile.h>
#include <TH2.h>
#include <array>
#include <boost/multi_array.hpp>
#include <boost/format.hpp>


void one_dim_array()
{
  std::array<double, 20> a;
  for (auto& x: a)
    x=NAN;
}

void binomials2(int max)
{
	std::vector<std::vector<int>> binomials;
    for (int i=0; i<max; i++)
    {
       auto& w=binomials.emplace_back();
       w.push_back(1);
       for (int j=1; j<=i; j++)
	   {
	      w.push_back(binomials[i-1][j-1]+binomials[i-1][j]);
	   }
	   w.push_back(1);
    }

    for (int i=0; i<max; i++)
      {
	    for (int j=0; j<=i; j++)
	      std::cout << " " << binomials[i][j];
	    std::cout << "\n";
      }
}

void binomials(int max)
  {
    boost::multi_array<int, 2> binomials(boost::extents[max][max]);
    for (int i=0; i<max; i++)
      for (int j=0; j<max; j++)
	binomials[i][j]=0;
    
    for (int i=0; i<max; i++)
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
  auto str=(boost::format("hist_%03d_%02d")% det% ch).str();
  auto f=TFile::Open("foo.root");
  auto* h=f->Get<TH1D>(str.c_str());
  assert(h);
  h->Print();
}

int c_stuff()
{
  one_dim_array();
  binomials2(8);
  dump_hist(2, 8);
  return 0;
}

int main()
{
	return c_stuff();
}
