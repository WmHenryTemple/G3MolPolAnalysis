#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

  //   q1    q2    q3    q4   dpl    th   phi    nsim     n1arm    n2arm  anp   err    tmean  hld
  //  0.28  1.48  0.00  0.34  3.03  0.00  0.00  20000.      0.      0.  0.0000 0.000  0.000 3.00  


int plotFromDat()
{
  float q1,q2,q3,q4,dpll,th,phi,nsim,n1arm,n2arm,anp,err,tmean,hld,levch,ler; 
  ifstream in;
  in.open("azz.dat");

  Int_t pts=7;
  Int_t j=0; //setting #

  Float_t coin[pts],azz[pts],lev[pts],coinCorr[pts],azzCorr[pts];
  Float_t dpl[pts];
  Float_t lerr[pts];  
  while(1){

    for (int i=0;i<3;i++){ //read three lines and store last
      in >> q1 >> q2 >> q3 >> q4 >>dpll >> th >> phi >> nsim >> n1arm >> n2arm >> anp >> err >> tmean >> hld >> levch >>ler;
      }
    coin[j]=n2arm;
    coinCorr[j]=n2arm*(1+levch);
    azz[j]=anp;
    azzCorr[j]=anp*(1+levch);    
    lev[j]=levch;
    lerr[j]=ler;
    dpl[j]=dpll;
    cout <<coin[j]<<"\t"<<dpl[j]<<endl;
    j++;
      if(!in.good())break;
  }

  //  TGraph *gr1=new TGraph(pts,q2f,coin);
  TCanvas *c1=new TCanvas("c1","c1",600,800);
  c1->Divide(1,3);
  c1->cd(1);
  TGraphErrors *gr1=new TGraphErrors(pts,dpl,coin,0,0);
    TGraphErrors *gr2=new TGraphErrors(pts,dpl,coinCorr,0,0);
  TGraphErrors *gr3=new TGraphErrors(pts,dpl,azz,0,0);
    TGraphErrors *gr4=new TGraphErrors(pts,dpl,azzCorr,0,0);
    TGraphErrors *gr5=new TGraphErrors(pts,dpl,lev,0,lerr);            
    gr2->SetTitle("Coincidence");
    gr4->SetTitle("Analyzing Power");
    gr5->SetTitle("Levchuk Correction");        
    
    gr1->SetMarkerSize(1);
    gr1->SetMarkerStyle(20);
    gr2->SetMarkerSize(1);
    gr2->SetMarkerStyle(22);
    gr2->SetMarkerColor(kRed);    
    
    gr2->Draw("ap");
    gr1->Draw("sp");

    c1->cd(2);
    gr3->SetMarkerSize(1);
    gr3->SetMarkerStyle(20);
    gr4->SetMarkerSize(1);
    gr4->SetMarkerStyle(22);
    gr4->SetMarkerColor(kRed);    
    
    gr4->Draw("ap");
    gr3->Draw("sp");

    c1->cd(3);
    gr5->SetMarkerSize(1);
    gr5->SetMarkerStyle(20);    
    gr5->Draw("ap");
    
  in.close();
  return 0;
}

