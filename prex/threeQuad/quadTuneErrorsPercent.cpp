{
  gStyle->SetOptFit(1111);

  double q1f[11]={-10,-8,-6,-4,-2,0,2,4,6,8,10};
  double q1cp[11]={506,1167,3617,12859,26852,25615,23141,20048,17154,13980,10716};
  double q1ap[11]={.7378, .7555, .7738, .7745, .7660, .7673, .7694, .7716, .7734, .7750, .7764};
  double q1ape[11]={.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003};

  double q2f[11]={-10,-8,-6,-4,-2,0,2,4,6,8,10};
  double q2cp[11]={21450,
		   25391,
		   26921,
		   26710,
		   26220,
		   25615,
		   24991,
		   24387,
		   23741,
		   23050,
		   22288};
  double q2ap[11]={0.7708,
		   0.7676,
		   0.7663,
		   0.7665,
		   0.7669,
		   0.7673,
		   0.7678,
		   0.7683,
		   0.7687,
		   0.7693,
		   0.7698};
  double q2ape[11]={.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003};

  double q4f[11]={-10,-8,-6,-4,-2,0,2,4,6,8,10};
  double q4cp[11]={19543,
		   23445,
		   26306,
		   26362,
		   26045,
		   25615,
		   25121,
		   24520,
		   23918,
		   23320,
		   22524};
  double q4ap[11]={0.772,
		   0.769,
		   0.7665,
		   0.7666,
		   0.7669,
		   0.7673,
		   0.7678,
		   0.7683,
		   0.7688,
		   0.7693,
		   0.7698};
  double q4ape[11]={.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003};

  double dpf[11]={-10,-8,-6,-4,-2,0,2,4,6,8,10};
  double dpcp[11]={25778,
		   25789,
		   25796,
		   25707,
		   25791,
		   25615,
		   25224,
		   24590,
		   23790,
		   22619,
		   21212};
  double dpap[11]={0.7672,
		   0.7672,
		   0.7672,
		   0.7672,
		   0.7672,
		   0.7673,
		   0.7676,
		   0.768,
		   0.7686,
		   0.7692,
		   0.77};
  double dpape[11]={.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003,.0003};

  double x[2]={11,12};
  double y[2]={.7673,.7673};
  double err[2]={.0007673,.003836};
  
  double qfe[11]={0,0,0,0,0,0,0};
  double qfee[11]={0,0,0,0,0, 0,0,0,0,0,0};  


  TGraph *gr1 = new TGraph{11,q1f,q1cp};
  TGraph *gr3 = new TGraph{11,q2f,q2cp};
  TGraph *gr5 = new TGraph{11,q4f,q4cp};
  TGraph *gr7 = new TGraph{11,dpf,dpcp};
  TGraphErrors *gr2 = new TGraphErrors{11,q1f,q1ap,qfee,q1ape};
  TGraphErrors *gr4 = new TGraphErrors{11,q2f,q2ap,qfe,q2ape};
  TGraphErrors *gr6 = new TGraphErrors{11,q4f,q4ap,qfe,q4ape};
  TGraphErrors *gr8 = new TGraphErrors{11,dpf,dpap,qfe,dpape};
  TGraphErrors *gr9 = new TGraphErrors{2,x,y,qfe,err};
  
    TCanvas *c1= new TCanvas("c1","Plot Area",1);
    c1->Divide(1,2);
    c1->cd(1);
    
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(20);
  gr1->SetMarkerSize(.75);
  gr3->SetMarkerColor(kRed);
  gr3->SetMarkerStyle(20);  
  gr3->SetMarkerSize(.75);
  gr5->SetMarkerColor(kBlack);
  gr5->SetMarkerStyle(20);
  gr5->SetMarkerSize(.75);
  gr7->SetMarkerColor(kMagenta);
  gr7->SetMarkerStyle(20);
  gr7->SetMarkerSize(.75); 
  

  
  gr2->SetMarkerColor(kBlue);
  gr2->SetMarkerStyle(33);
  gr2->SetMarkerSize(0.7);

  gr4->SetMarkerColor(kRed);
  gr4->SetMarkerStyle(33);
  gr4->SetMarkerSize(0.7);

  gr6->SetMarkerColor(kBlack);
  gr6->SetMarkerStyle(33);
  gr6->SetMarkerSize(0.7);

  gr8->SetMarkerColor(kMagenta);
  gr8->SetMarkerStyle(33);
  gr8->SetMarkerSize(0.7);

 gr1->GetXaxis()->SetRangeUser(-50,50);
 gr2->GetXaxis()->SetRangeUser(-50,50); 
  
  gr1->Draw("acp");
  gr3->Draw("scp");
  gr5->Draw("scp");
  gr7->Draw("scp");  
  gr9->Draw("sp");

  TLegend *legend2 = new TLegend(0.1,0.7,0.48,0.9);
   
  legend2->AddEntry(gr1,"Q1","p");
  legend2->AddEntry(gr3,"Q2","p");
  legend2->AddEntry(gr5,"Q4","p");
  legend2->AddEntry(gr7,"Dipole","p");  

  legend2->Draw();

  c1->cd(2);
  gr2->Draw("acp");
  gr4->Draw("scp");
  gr6->Draw("scp");
  gr8->Draw("scp");    
  gr9->Draw("sp");

  
  gr1->SetTitle("Coincidence Pairs vs Magnetic Field");
  gr1->GetXaxis()->SetTitleSize(0.045);
  gr1->GetXaxis()->SetTitleOffset(0.9);
  gr1->GetYaxis()->SetTitleSize(0.05);
  gr1->GetYaxis()->SetTitleOffset(0.9);
  //  gr1->GetYaxis()->SetRangeUser(0,11000);
  gr1->GetYaxis()->SetTitle("Coincidence Pairs");
  gr1->GetXaxis()->SetTitle("Amount Detuned (Percent)");

  
  gr2->SetTitle("Analyzing Power vs Magnetic Field");
  gr2->GetXaxis()->SetTitleSize(0.045);
  gr2->GetXaxis()->SetTitleOffset(0.9);
  gr2->GetYaxis()->SetTitleSize(0.05);
  gr2->GetYaxis()->SetTitleOffset(0.9);
  //  gr2->GetYaxis()->SetRangeUser(0.76,0.78);
  gr2->GetYaxis()->SetTitle("Analyzing Power");
  gr2->GetXaxis()->SetTitle("Amount Detuned (Percent)");
  gr2->GetXaxis()->SetRangeUser(-15,15);

  

  
  TLegend *legend = new TLegend(0.1,0.7,0.48,0.9);
   
  legend->AddEntry(gr2,"Q1","p");
  legend->AddEntry(gr4,"Q2","p");
  legend->AddEntry(gr6,"Q4","p");
  legend->AddEntry(gr8,"Dipole","p");  
  legend->Draw();
 
}
