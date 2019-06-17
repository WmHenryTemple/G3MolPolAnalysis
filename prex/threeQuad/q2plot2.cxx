#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

  //   q1    q2    q3    q4   dpl    th   phi    nsim     n1arm    n2arm  anp   err    tmean  hld
  //  0.28  1.48  0.00  0.34  3.03  0.00  0.00  20000.      0.      0.  0.0000 0.000  0.000 3.00  


int q1plot()
{

  gStyle->SetTitleFontSize(0.06);
  gStyle->SetTitleSize(0.0,"t");
  gStyle->SetTitleSize(0.05,"y");
  gStyle->SetTitleSize(0.05,"x");  
  gStyle->SetTitleOffset(0.35,"y");    
  gStyle->SetTitleY(1.1);    

  float q1,q2,q3,q4,dpl,th,phi,nsim,n1arm,n2arm,anp,err,tmean,hld,levch,ler; 
  ifstream in;
  in.open("q2.dat");

  Int_t pts=11;
  Int_t j=0; //setting #

  Float_t coin[pts],azz[pts],lev[pts],coinCorr[pts],azzCorr[pts];
  Float_t field[pts];
  Float_t lerr[pts];  
  Float_t anpp,n2armm;
  //************************************************************
  //**********         Main Loop To Read dat file    ***********
  //************************************************************
  while(1){

    for (int i=0;i<3;i++){ //read three lines last line has levch. first has coin and azz
      in >> q1 >> q2 >> q3 >> q4 >>dpl >> th >> phi >> nsim >> n1arm >> n2armm >> anpp >> err >> tmean >> hld >> levch >>ler;
      if(i==0){
	n2arm=n2armm;
	anp=anpp;
      }
    }

    coin[j]=n2arm*.63572/1000;
    coinCorr[j]=n2arm*(1+levch)*.63572/1000;
    azz[j]=anp;
    azzCorr[j]=anp*(1+levch);
    lev[j]=levch*100;
    lerr[j]=ler*100;
    field[j]=q2;
    cout <<coin[j]<<"\t"<<field[j]<<endl;
    j++;
    if(!in.good())break;
  }

    //  TGraph *gr1=new TGraph(pts,q2f,coin);
  TCanvas *c1=new TCanvas("c1","c1",1200,800);
  c1->Divide(1,3,0.0001,0.001,0);
  c1->cd(1);
  gPad->SetTickx(1);
  c1->SetGridy();
  c1->SetTopMargin(0);
  c1->SetBottomMargin(0);  

  TGraphErrors *gr1=new TGraphErrors(pts,field,coin,0,0);
    TGraphErrors *gr2=new TGraphErrors(pts,field,coinCorr,0,0);
  TGraphErrors *gr3=new TGraphErrors(pts,field,azz,0,0);
    TGraphErrors *gr4=new TGraphErrors(pts,field,azzCorr,0,0);
    TGraphErrors *gr5=new TGraphErrors(pts,field,lev,0,lerr);            

    TLegend *leg=new TLegend(.75,.8,.9,.9);
    leg->AddEntry(gr4,"Levchuk Corrected","p");
    gr1->GetYaxis()->SetTitle("Coincidence Rates (kHz/#mum/#muA)");
    gr4->GetYaxis()->SetTitle("Analyzing Power");
    gr5->GetYaxis()->SetTitle("Levchuk Correction (%)");        
    gr4->GetYaxis()->SetRangeUser(0.76,0.8);
    gr4->GetYaxis()->SetDecimals(4);    
    gr1->GetYaxis()->SetRangeUser(0,18);
    gr5->GetYaxis()->SetRangeUser(-5,5);

    gr4->GetXaxis()->SetTitle("Field (kG)");
    gr1->GetXaxis()->SetTitle("Field (kG)");
    gr5->GetXaxis()->SetTitle("Field (kG)");

    gr1->SetMarkerSize(1);
    gr1->SetMarkerStyle(20);
    gr2->SetMarkerSize(1);
    gr2->SetMarkerStyle(22);
    gr2->SetMarkerColor(kRed);    
    

    gr1->Draw("acp");
    gr2->Draw("scp");
    leg->Draw();

    c1->cd(2);
    gr3->SetMarkerSize(1);
    gr3->SetMarkerStyle(20);
    gr4->SetMarkerSize(1);
    gr4->SetMarkerStyle(22);
    gr4->SetMarkerColor(kRed);    
    
    gr4->Draw("acp");
    gr3->Draw("scp");
    leg->Draw();
    Float_t y1=0.76538175; //1
    Float_t y2=0.76921825; //4
    Float_t y3=0.7665327;//2
    Float_t y4=0.7680673;// 3     
    //    Float_t x1=field[0];
    //    Float_t x2=field[pts-1];    
       Float_t x1=gr1->GetXaxis()->GetXmin();
       Float_t x2=gr1->GetXaxis()->GetXmax();    
       x1=x1+.05*(x2-x1);
       x2=x2-.05*(x2-x1);	 
       TBox *box1=new TBox(x1,y1,x2,y2);
    TBox *box2=new TBox(x1,y3,x2,y4);    
    //    TBox *box=new TBox(2.9,.77,3.1,.79);    
    //       TBox *box=new TBox(c1->GetUxmin(),c1->GetUymin(),c1->GetUxmax(),c1->GetUymax());
    box1->SetFillColor(41);
    box1->Draw("same ");
    box2->SetFillColor(46);
    box2->Draw("same ");    
    gr4->Draw("scp");
    gr3->Draw("scp");
    leg->Draw();

    TPaveText *pt = new TPaveText(0.15,.35,0.22,.47,"blNDC");
    pt->SetBorderSize(1);
    pt->AddText("#pm 0.1%");
    ((TText*)pt->GetListOfLines()->Last())->SetTextColor(46);
    pt->AddText("#pm 0.25%");
    ((TText*)pt->GetListOfLines()->Last())->SetTextColor(41);    
    pt->Draw();
    
    c1->cd(3);
    gr5->SetMarkerSize(1);
    gr5->SetMarkerStyle(20);    
    gr5->Draw("acp");
    
  in.close();
  return 0;
}

