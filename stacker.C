/*DY.root              TSlepSlep_125_120.root  WZ.root    run.sh
TChiWW_175_135.root  TSlepSlep_175_155.root  ZJet.root  runmac.C
TChiWZ_150_135.root  TSlepSlep_200_150.root  ZZ.root    stack
TChiWZ_300_270.root  TTJet.root              hists.h    test.root
TChiWZ_325_318.root  WJet.root               ntup.C     ~
TChiZZ_100_0.root    WW.root
*/

#include "/home/t3-ku/janguian/SignificanceCalculations/testzbi.cpp"

void stackbg(TFile* out, TFile* dy, TFile* wjet, TFile* ttjet, TFile* zjet, TFile* wz, TFile* ww , TFile* zz, std::string plotname,std::string seqnum, int opt){

	THStack* stk = new THStack( (plotname+seqnum).c_str(), "");
	TH1D* hdy = (TH1D*) dy->Get((plotname+seqnum).c_str());
	TH1D* hwjet = (TH1D*) wjet->Get((plotname+seqnum).c_str());
	TH1D* httjet = (TH1D*) ttjet->Get((plotname+seqnum).c_str());		
	TH1D* hzjet = (TH1D*) zjet->Get((plotname+seqnum).c_str());
	TH1D* hwz = (TH1D*) wz->Get((plotname+seqnum).c_str());
	TH1D* hww = (TH1D*) ww->Get((plotname+seqnum).c_str());
	TH1D* hzz = (TH1D*) zz->Get((plotname+seqnum).c_str());
	
	hdy->SetFillColor(kBlue);
	hwjet->SetFillColor(kGreen);
	httjet->SetFillColor(kRed);
	hdy->SetFillStyle(3004);
	hwjet->SetFillStyle(3005);
	httjet->SetFillStyle(3013);
	hzjet->SetFillColor(kMagenta);	
	hwz->SetFillColor(kBlue);
	hww->SetFillColor(kGreen);
	hzz->SetFillColor(kRed);

	if(opt==1){
	std::vector<std::string> cut{"nLep>2","L=2","(sign)","(flavor)","(jet)","bjet=0","MET>175","PTISR>200","RISR>0.5","mll<70","ID1","SIP1","ISO1","ID2","SIP2","ISO2","relIso1","reliso2"};
        for(int i=1; i<cut.size()+1; i++){
                hdy->GetXaxis()->SetBinLabel(i,cut[i-1].c_str());

        }
	}
	if(opt==2){
        std::vector<std::string> cut{"0 Jets","1 Jet","A,B Jet", "A,A | B,B",">2 Jets"};
        for(int i=1; i<cut.size()+1; i++){
                hdy->GetXaxis()->SetBinLabel(i,cut[i-1].c_str());

        }
        }

	stk->Add(hdy);
	stk->Add(hwjet);
	stk->Add(httjet);
	stk->Add(hzjet);
	stk->Add(hwz);
	stk->Add(hww);
	stk->Add(hzz);

//	std::vector<std::string> cut{"nLep>2","L=2","(sign)","(flavor)","bjet=0","MET>200","PTISR>200","ID1","SIP1","ISO1","ID2","SIP2","ISO2"};
//	for(int i=1; i<14; i++){
//		hdy->GetXaxis()->SetBinLabel(i,cut[i-1].c_str());
//		
//	}
  // h->Draw();
	
	TLegend *leg = new TLegend(0.1, 0.7, 0.3, 0.9);
	//leg -> SetNColumns(2);
	//leg -> SetHeader("Test");
	//leg -> SetFillColor(0);
	leg -> AddEntry(hdy, "DY", "f");
	leg -> AddEntry(hwjet, "WJet", "f");
	leg -> AddEntry(httjet, "TTBar", "f");
	leg -> AddEntry(hzjet, "ZNuNu", "f");
        leg -> AddEntry(hwz, "WZ", "f");
        leg -> AddEntry(hww, "WW", "f");
	leg -> AddEntry(hzz, "ZZ","f");
	//leg -> DrawClone("Same");
	
	TCanvas* c = new TCanvas((plotname+seqnum).c_str());
	stk->Draw("HIST");
	leg->Draw();
	out->WriteTObject(c);

	//out->WriteTObject(stk);

	//return stk;
	
}
void supersig(TFile* out, std::vector<TFile*> fsignals,std::vector<std::string> snames, std::vector<int> cols, std::string plotname, std::string seqnum, int opt){

	
	std::vector<TH1D*> signals;
	for(int i=0; i< fsignals.size(); i++){
		signals.push_back( (TH1D*) fsignals.at(i)->Get((plotname+seqnum).c_str()) );
		signals.at(i)->SetLineColor(cols.at(i));
		signals.at(i)->SetLineWidth(2);
//		if(i>4){
			//signals.at(i)->SetLineStyle(10);
//		}
		//signals.at(i)->SetLineStyle(
	}


	TLegend *leg = new TLegend(0.1,0.7, 0.3, 0.9);
	for(int i=0; i< signals.size(); i++){
		leg->AddEntry( signals.at(i), snames.at(i).c_str(), "l");
	}	


	
	TCanvas* c = new TCanvas(("S"+plotname+seqnum).c_str());
	if(opt==1){
	std::vector<std::string> cut{"nLep>2","L=2","(sign)","(flavor)","(jet)","bjet=0","MET>200","PTISR>200","RISR>0.5","mll<70","ID1","SIP1","ISO1","ID2","SIP2","ISO2","relIso1","reliso2"};
        for(int i=1; i<cut.size()+1; i++){
                signals.at(0)->GetXaxis()->SetBinLabel(i,cut[i-1].c_str());

        }
	}
	if(opt==2){
        std::vector<std::string> cut{"0 Jets","1 Jet","A,B Jet", "A,A | B,B",">2 Jets"};
        for(int i=1; i<cut.size()+1; i++){
                signals.at(0)->GetXaxis()->SetBinLabel(i,cut[i-1].c_str());

        }
        }


	TH1D* copy0 = (TH1D*)signals.at(0)->Clone();
	copy0->Scale( 1./copy0->Integral() );
	//signals.at(0)->Scale( 1./signals.at(0)->Integral() );

	//signals.at(0)->Draw("HIST");
	copy0->Draw("HIST");
	for(int i=1; i<signals.size(); i++){
		//signals.at(i)->Scale( 1./signals.at(i)->Integral() );
		//signals.at(i)->Draw("SAME HIST");
		TH1D* copyI =(TH1D*) signals.at(i)->Clone();
		copyI->Scale( 1./copyI->Integral() );
		copyI->Draw("SAME HIST");
	}
	leg->Draw();
	out->WriteTObject(c);


}
TH2D* matrix2d(TFile* out, TFile* f, std::vector<std::string> seqnum, std::string sample){

	int ncat = 4;
	TH1D* htest = (TH1D*) f->Get("hset1");
	TMatrixD mat( ncat ,htest->GetNbinsX());
	for(int i=0; i<seqnum.size(); i++){
		TH1D* h = (TH1D*) f->Get(("hset"+seqnum.at(i)).c_str());
	//	TMatrixD mat( ncat, h->GetNbins());
		Double_t x[h->GetNbinsX()];
		for(int j=1; j<=h->GetNbinsX(); j++){
			x[j-1] = h->GetBinContent(j);
		}
		TVectorD x1;
		x1.Use(h->GetNbinsX(), x);	
		TMatrixDRow(mat, i) = x1;
			
	}
	TCanvas* c = new TCanvas((sample+"hset2d").c_str());
	TH2D* p = new TH2D(mat);
	p->SetName((sample+"th2d").c_str());
	p->Draw("COLZ TEXT");
	out->WriteTObject(c);	
	return p;	
	

}
TH2D* add2dbg(TFile* out, std::vector<TH2D*> bgs){
	//TH2D* base = (TH2D*) out->Get((bgs.at(0)+"hset2d").c_str());
	TH2D* base = bgs.at(0);
	for(int i=1; i<bgs.size(); i++){
		//TH2D* app = (TH2D*) out->Get((bgs.at(i)+"hset2d").c_str());
		
		base->Add(bgs.at(i));	
	}
	base->SetName("stackth2dbg");
	TCanvas* c = new TCanvas("stack2dbg");
	base->Draw("COLZ TEXT");
	out->WriteTObject(c);
	
	return base;
}
void super2dwithsig( TFile* out, TH2D* stackedbg, TH2D* signal){
		std::string a(signal->GetName());
		stackedbg->SetBarOffset(0.2);
		stackedbg->SetMarkerColor(kRed);
		signal->SetBarOffset(-0.2);
		std::vector<std::string> cut{"nLep>2","L=2","(sign)","(flavor)","(jet)","bjet=0","MET>200","PTISR>200","RISR>0.5","mll<70","ID1","SIP1","ISO1","ID2","SIP2","ISO2","relIso1","reliso2"};
        for(int i=1; i<cut.size()+1; i++){
                stackedbg->GetXaxis()->SetBinLabel(i,cut[i-1].c_str());

        }
//	std::vector<std::string> cut2{"OSSF","OSSFe","OSSFmu","OSOF","SSSF","SSSFe","SSSFmu","SSOF"};
	std::vector<std::string> cut2{"0 jets", "=1 jet", "#geq 1 jet#", "#geq 2 jet"};
        for(int i=1; i<5; i++){
               stackedbg->GetYaxis()->SetBinLabel(i,cut2[i-1].c_str());

        }



		TCanvas* c = new TCanvas(("bgsuper_"+a).c_str());
		stackedbg->Draw("COLZ TEXT");
		signal->Draw("TEXT SAME");
		out->WriteTObject(c);

}

void stackrisrmperp(TFile* fsig ,std::vector<TFile*> bgs, std::string stag, std::string cat, TFile* fout){

std::vector<TH2D*> risrmperpBG{};
risrmperpBG.push_back((TH2D*) bgs[0]->Get(("RISRMperp"+cat).c_str() ));
risrmperpBG.push_back((TH2D*) bgs[1]->Get(("RISRMperp"+cat).c_str()  ));
risrmperpBG.push_back((TH2D*) bgs[2]->Get(("RISRMperp"+cat).c_str() ));
risrmperpBG.push_back((TH2D*) bgs[3]->Get(("RISRMperp"+cat).c_str() ));
risrmperpBG.push_back((TH2D*) bgs[4]->Get(("RISRMperp"+cat).c_str() ));
risrmperpBG.push_back( (TH2D*) bgs[5]->Get(("RISRMperp"+cat).c_str() ));
risrmperpBG.push_back((TH2D*)  bgs[6]->Get(("RISRMperp"+cat).c_str() ));


TH2D* risrmperpS1 = (TH2D*) fsig->Get(("RISRMperp"+cat).c_str() );
//TH2D* risrmperpS2 = (TH2D*) TChiWZ_325_318->Get("hrisrmperp1");
TH2D* risrmperpsuper = (TH2D*) risrmperpBG.at(0)->Clone();
for(int i=1; i<risrmperpBG.size(); i++){
        risrmperpsuper->Add(risrmperpBG.at(i));
}
risrmperpsuper->SetBarOffset(0.3);
risrmperpsuper->SetMarkerColor(kRed);
risrmperpS1->SetBarOffset(0);

TH2D* zbi2d = (TH2D*) risrmperpsuper->Clone();
int nbinsX,nbinsY;
nbinsX = risrmperpS1->GetNbinsX();
nbinsY = risrmperpS1->GetNbinsY();
double bincontentS, bincontentBG;
double pb1, zb1;
for(int i=1; i<=nbinsX; i++){
	for(int j=1; j<=nbinsY; j++){
		bincontentS = risrmperpS1->GetBinContent(i,j);
		bincontentBG = risrmperpsuper->GetBinContent(i,j);
		if(bincontentS > 0){
		pb1 = pBi(bincontentS, bincontentBG, 0.1);
		zb1 = zSingleSided(pb1);		
		zbi2d->SetBinContent(i,j,zb1);	
		}
		else{
			zbi2d->SetBinContent(i,j,-1);
		}
	}
}

zbi2d->SetMarkerColor(kBlue);
zbi2d->SetBarOffset(-0.3);

//TH2D* risrmperpsuper2 =(TH2D*) risrmperpsuper->Clone();
//risrmperpsuper2->SetBarOffset(0.2);
//risrmperpsuper2->SetMarkerColor(kRed);
//risrmperpS2->SetBarOffset(-0.2);

TCanvas* Crisrmperp = new TCanvas(("risrmperpSuper"+cat+stag).c_str());
zbi2d->SetMinimum(-1);
zbi2d->SetStats(false);
zbi2d->Draw("COLZ TEXT");
risrmperpsuper->Draw("TEXT SAME");
//risrmperpsuper->Draw("COLZ TEXT");
risrmperpS1->Draw("TEXT SAME");
//zbi2d->Draw("TEXT SAME");
fout->WriteTObject(Crisrmperp);





//TCanvas* Crisrmperp2 = new TCanvas("risrmperpSuper_wz325_318");
//risrmperpsuper2->Draw("COLZ TEXT");
//risrmperpS2->Draw(" TEXT SAME");
//fout->WriteTObject(Crisrmperp2);

	
}



void stacker(){

//std::string PATH="../sip2/";
//std::string PATH="../siploose/"; 
//std::string PATH="../";
//std::string PATH="../lomet/";
//std::string PATH="../reliso04cut/";
// std::string PATH="../relPF6/";
std::string PATH="./susy_ExecutionDirectory/";

TFile* DY = new TFile((PATH+"DY/Outfile.root").c_str());
TFile* WJet = new TFile((PATH+"WJet/Outfile.root").c_str());
TFile* TTJet = new TFile((PATH+"TTJet/Outfile.root").c_str());
TFile* ZJet = new TFile((PATH+"ZJet/Outfile.root").c_str());
TFile* WZ = new TFile((PATH+"WZ/Outfile.root").c_str());
TFile* WW = new TFile((PATH+"WW/Outfile.root").c_str());
TFile* ZZ = new TFile((PATH+"ZZ/Outfile.root").c_str());

std::vector<TFile*> bgs = {DY, WJet, TTJet, ZJet, WZ, WW, ZZ};

/*THStack *seq1stack = new THStack("seq1","");
TH1D* hset1dy = (TH1D*) DY->Get("hset1");
TH1D* hset1wjet = (TH1D*) WJet->Get("hset1");
seq1stack->Add(hset1dy);
seq1stack->Add(hset1wjet);
seq1stack->Draw("HIST TEXT");
*/

 TFile* out = new TFile("stacks.root","RECREATE");
 /*stackbg(out,DY,WJet,TTJet,ZJet,WZ,WW,ZZ, "hset","1"); 
 stackbg(out,DY,WJet,TTJet,ZJet,WZ,WW,ZZ, "hset","2");
 stackbg(out,DY,WJet,TTJet,ZJet,WZ,WW,ZZ, "hset","3");
 stackbg(out,DY,WJet,TTJet,ZJet,WZ,WW,ZZ, "hset","4");
 stackbg(out,DY,WJet,TTJet,ZJet,WZ,WW,ZZ, "hset","5");
 stackbg(out,DY,WJet,TTJet,ZJet,WZ,WW,ZZ, "hset","6");
 stackbg(out,DY,WJet,TTJet,ZJet,WZ,WW,ZZ, "hset","7");
 stackbg(out,DY,WJet,TTJet,ZJet,WZ,WW,ZZ, "hset","8");
*/
//	std::vector<std::string> num{"1","2","3","4","5","6","7","8"};
//	std::vector<std::string> num{"1","2","3","4"};
//	std::vector<std::string> name{"hset","RISRset", "mperpset", "mllset", "dphicmi", "hjetAB", "hptlepjetratio", "hmllmperpratio", "maxsip", "dphimetV","hmet","hmlmperp","hmltmperp","hplpj","hpltpjt","hdphiS","hdphiSI","minsip","hML","hMLT","hdphiCM", "hcosS", "hMX3a", "hMX3b", "hMX3abT", "hMX3bbT", "hMS", "hMSMperpratio", "hMSMllratio", "hMX3diff_MX3Sum", "hMX3diff_Mperp", "hMX3diff_aoverb", "hMX3diffa", "hMX3diffb", "hdphiCMIdphiSratio", "hdphiSdphiSIratio", "hdphiSdphiMETVratio", "hmaxabsMiniIso", "hmaxrelIso","hmaxrelMiniIso", "hminabsMiniIso", "hminrelIso", "hminrelMiniIso", "hmaxabsRelIso"};
	std::vector<std::string> name{"hset"};///,"RISRMperp"};
	std::vector<std::string> num{"1","2"};
int bopt =0; 
for(int i=0; i<name.size(); i++){
	if( name.at(i).compare("hset") == 0){
                bopt = 1;
        }
        else if( name.at(i).compare("hjetAB") == 0){
                bopt = 2;
        }
        else{
		bopt = 0;
	}

	for(int j=0; j<num.size(); j++){
		stackbg(out,DY,WJet,TTJet,ZJet,WZ,WW,ZZ, name.at(i), num.at(j), bopt);
	}
 } 



// TFile* TChiZZ_100_0 = new TFile((PATH+"TChiZZ_100_0.root").c_str());
// TFile* TChiWW_175_135 = new TFile((PATH+"TChiWW_175_135.root").c_str());
 TFile* TSlepSlep_125_120 = new TFile((PATH+"TSlepSlepSMS_125_120/Outfile.root").c_str());
// TFile* TChiWZ_150_135  = new TFile((PATH+"TChiWZ_150_135.root").c_str());
 TFile* TSlepSlep_175_155 = new TFile((PATH+"TSlepSlepSMS_175_155/Outfile.root").c_str());
 TFile* TChiWZ_300_270  = new TFile((PATH+"TChiWZ_ZToLLSMS_300_270/Outfile.root").c_str());
// TFile* TSlepSlep_200_150 = new TFile((PATH+"TSlepSlep_200_150.root").c_str());
 TFile* TChiWZ_325_318 = new TFile((PATH+"TChiWZ_ZToLLSMS_325_318/Outfile.root").c_str());
 TFile* T2bW_300_270 = new TFile((PATH+"T2bWSMS_300_270/Outfile.root").c_str());
 TFile* T2bW_425_415 = new TFile((PATH+"T2bWSMS_425_415/Outfile.root").c_str());
// TFile* TSlepSlep_400_360 = new TFile((PATH+"TSlepSlep_400_360.root").c_str());
// TFile* TSlepSlep_425_424 = new TFile((PATH+"TSlepSlep_425_424.root").c_str());

 //std::vector<TFile*> fs{TChiWZ_150_135,  TChiWZ_300_270, TChiWZ_325_318, TSlepSlep_125_120, TSlepSlep_175_155, TSlepSlep_200_150, TChiZZ_100_0, TChiWW_175_135};
//std::vector<TFile*> fs{TChiWZ_300_270};//, TSlepSlep_175_155, TChiWW_175_135};
std::vector<TFile*> fs{TChiWZ_300_270, TChiWZ_325_318, TSlepSlep_125_120, TSlepSlep_175_155, T2bW_300_270, T2bW_425_415};
//std::vector<TFile*> fs{TChiWZ_300_270, TSlepSlep_175_155, T2bW_300_270, TSlepSlep_125_120, TChiWZ_325_318, T2bW_425_415, TSlepSlep_400_360, TSlepSlep_425_424};
//std::vector<std::string> sname{"TChiWZ_300_270", "TSlepSlep_175_155","T2bW_300_270","TSlepSlep_125_120", "TChiWZ_325_318","T2bW_425_415", "TSlepSlep_400_360", "TSlepSlep_425_424"};//, "TChiWW_175_135"};
//std::vector<std::string> sname{"TChiWZ_300_270"};
std::vector<int> col{2,3,4,6,7,1,11,1}; 
std::vector<std::string> sname{  "TChiWZ_300_270", "TChiWZ_325_318", "TSlepSlep_125_120","TSlepSlep_175_155", "T2bW_300_270", "T2bW_425_415"};
 //std::vector<int> col{ 2,3,4,6,2,3,4,6}; 
int sopt=0;
int rescale = 1;
 for(int i=0; i<name.size(); i++){
	if( name.at(i).compare("hset") == 0){
		sopt = 1;
	}
	else if( name.at(i).compare("hjetAB") == 0){
                sopt = 2;
        }
        else{
                sopt = 0;
        }

	for(int j=0; j<num.size(); j++){
//		supersig(out, fs,sname, col, name.at(i), num.at(j), sopt);
	}
 }
std::vector<TH2D*> bg2d{};
bg2d.push_back( matrix2d(out, DY, num, "DY"));
bg2d.push_back(matrix2d(out, WJet, num, "WJet"));
bg2d.push_back(matrix2d(out, TTJet, num, "TTJet"));
bg2d.push_back(matrix2d(out, ZJet, num, "ZJet"));
bg2d.push_back(matrix2d(out, WZ, num, "WZ"));
bg2d.push_back(matrix2d(out, WW, num, "WW"));
bg2d.push_back(matrix2d(out, ZZ, num, "ZZ"));
std::vector<TH2D*> sig2d{};
for(int i=0; i<fs.size(); i++){
//sig2d.push_back(matrix2d(out, fs.at(i), num, sname.at(i)));
}


//add 2d bg
//std::vector<std::string> bgs{"DY", "Wjet", "TTJet", "ZJet", "WZ","WW","ZZ"};
TH2D* stackedbg = add2dbg(out,bg2d);
for(int i=0; i<sig2d.size(); i++){
//super2dwithsig( out, stackedbg, sig2d.at(i));
}



stackrisrmperp(TChiWZ_300_270 ,bgs,"_wz300_270", "1" , out);
stackrisrmperp(TChiWZ_300_270 ,bgs,"_wz300_270", "2" , out);
stackrisrmperp(TChiWZ_325_318,bgs,"_wz325_318","1",out);
stackrisrmperp(TChiWZ_325_318,bgs,"_wz325_318","2",out);
stackrisrmperp(TSlepSlep_175_155 ,bgs,"_ss175_155", "1" , out);
stackrisrmperp(TSlepSlep_175_155 ,bgs,"_ss175_155", "2" , out);
stackrisrmperp(TSlepSlep_125_120 ,bgs,"_ss125_120", "1" , out);
stackrisrmperp(TSlepSlep_125_120 ,bgs,"_ss125_120", "2" , out);
stackrisrmperp(T2bW_300_270, bgs,"_bw300_270","1",out);
stackrisrmperp(T2bW_300_270, bgs,"_bw300_270","2",out);
stackrisrmperp(T2bW_425_415, bgs,"_bw425_415","1",out);
stackrisrmperp(T2bW_425_415, bgs,"_bw425_415","2",out);
/*
stackrisrmperp(TSlepSlep_400_360, bgs, "_ss400_360","1",out);
stackrisrmperp(TSlepSlep_400_360, bgs, "_ss400_360","3",out);
stackrisrmperp(TSlepSlep_425_424, bgs, "_ss425_424","1",out);
stackrisrmperp(TSlepSlep_425_424, bgs, "_ss425_424","3",out);
*/
///stack risr mrat
//std::vector<TH2D*> risrmratBG{};
//risrmratBG.push_back((TH2D*) DY->Get("hmratrisr1"));
//risrmratBG.push_back((TH2D*) WJet->Get("hmratrisr1"));
//risrmratBG.push_back((TH2D*) TTJet->Get("hmratrisr1"));
//risrmratBG.push_back((TH2D*)  ZJet->Get("hmratrisr1"));
//risrmratBG.push_back((TH2D*)  WZ->Get("hmratrisr1"));
//risrmratBG.push_back( (TH2D*) WW->Get("hmratrisr1"));
//risrmratBG.push_back((TH2D*)  ZZ->Get("hmratrisr1"));

/*
TH2D* risrmratS1 = (TH2D*) TChiWZ_300_270->Get("hmratrisr1");
TH2D* risrmratS2 = (TH2D*) TChiWZ_325_318->Get("hmratrisr1");
TH2D* risrmratsuper = (TH2D*) risrmratBG.at(0)->Clone();
for(int i=1; i<risrmratBG.size(); i++){
        risrmratsuper->Add(risrmratBG.at(i));
}
risrmratsuper->SetBarOffset(0.2);
risrmratsuper->SetMarkerColor(kRed);
risrmratS1->SetBarOffset(-0.2);

TH2D* risrmratsuper2 =(TH2D*) risrmratsuper->Clone();
risrmratsuper2->SetBarOffset(0.2);
risrmratsuper2->SetMarkerColor(kRed);
risrmratS2->SetBarOffset(-0.2);

TCanvas* Crisrmrat = new TCanvas("risrmratSuper_wz300_270");
risrmratsuper->Draw("COLZ TEXT");
risrmratS1->Draw("TEXT SAME");
out->WriteTObject(Crisrmrat);

TCanvas* Crisrmrat2 = new TCanvas("risrmratSuper_wz325_318");
risrmratsuper2->Draw("COLZ TEXT");
risrmratS2->Draw(" TEXT SAME");
out->WriteTObject(Crisrmrat2);
*/


 out->Write();
 out->Close();




}
