
#include "/home/t3-ku/janguian/SignificanceCalculations/testzbi.cpp"
void stackrisrmperp(TFile* fsig ,std::vector<TFile*> bgs, std::string stag, std::string pname, TFile* fout){
	std::vector<TH2D*> risrmperpBG(bgs.size());
	for(int i=0; i<bgs.size(); i++){
		risrmperpBG.at(i) = (TH2D*) bgs.at(i)->Get(pname.c_str())->Clone();
	}
	TH2D* risrmperpS = (TH2D*) fsig->Get(pname.c_str())->Clone();

	TH2D* risrmperpSUPERBG = (TH2D*) risrmperpBG.at(0)->Clone();
	for(int i=1; i<risrmperpBG.size(); i++){
		risrmperpSUPERBG->Add(risrmperpBG.at(i));
	}
	risrmperpSUPERBG->SetBarOffset(0.3);
	risrmperpSUPERBG->SetMarkerColor(kRed);
	risrmperpS->SetBarOffset(0.);
	
	TH2D* zbi2d = (TH2D*) risrmperpS->Clone();
	int nbinsX = risrmperpS->GetNbinsX();
	int nbinsY = risrmperpS->GetNbinsY();
	double bincontentS, bincontentBG;
	double pb1, zb1;
	for(int i=1; i<=nbinsX; i++){
        	for(int j=1; j<=nbinsY; j++){
                	bincontentS = risrmperpS->GetBinContent(i,j);
               		bincontentBG = risrmperpSUPERBG->GetBinContent(i,j);
                	if(bincontentS > 0){
                		pb1 = pBi(bincontentS, bincontentBG, 0.1);
                		zb1 = zSingleSided(pb1);
                		zbi2d->SetBinContent(i,j,zb1);
                	}
                	else{
                        	zbi2d->SetBinContent(i,j,-1.);
                	}
       		 }
	}
	zbi2d->SetMarkerColor(kBlue);
	zbi2d->SetBarOffset(-0.3);

	TCanvas* Crisrmperp = new TCanvas(("Super"+pname+stag).c_str());
	zbi2d->SetMinimum(-1);
	zbi2d->SetStats(false);
	zbi2d->Draw("COLZ TEXT");
	risrmperpSUPERBG->Draw("TEXT SAME");
	risrmperpS->Draw("TEXT SAME");
	fout->WriteTObject(Crisrmperp);
	Crisrmperp->SaveAs(("./binstacks_/Super"+pname+stag+".pdf").c_str());

}


void binstacker(){

std::string PATH="./susy_ExecutionDirectory/";

TFile* DY = new TFile((PATH+"DY/Outfile.root").c_str());
TFile* WJet = new TFile((PATH+"WJet/Outfile.root").c_str());
TFile* TTJet = new TFile((PATH+"TTJet/Outfile.root").c_str());
TFile* ZJet = new TFile((PATH+"ZJet/Outfile.root").c_str());
TFile* WZ = new TFile((PATH+"WZ/Outfile.root").c_str());
TFile* WW = new TFile((PATH+"WW/Outfile.root").c_str());
TFile* ZZ = new TFile((PATH+"ZZ/Outfile.root").c_str());

std::vector<TFile*> bgs = {DY, WJet, TTJet, ZJet, WZ, WW, ZZ};

TFile* TSlepSlep_125_120 = new TFile((PATH+"TSlepSlepSMS_125_120/Outfile.root").c_str());
TFile* TSlepSlep_175_155 = new TFile((PATH+"TSlepSlepSMS_175_155/Outfile.root").c_str());
TFile* TChiWZ_300_270  = new TFile((PATH+"TChiWZ_ZToLLSMS_300_270/Outfile.root").c_str());
TFile* TChiWZ_325_318 = new TFile((PATH+"TChiWZ_ZToLLSMS_325_318/Outfile.root").c_str());
TFile* TChiWZ_425_405 = new TFile((PATH+"TChiWZ_ZToLLSMS_425_405/Outfile.root").c_str());
TFile* T2bW_300_270 = new TFile((PATH+"T2bWSMS_300_270/Outfile.root").c_str());
TFile* T2bW_425_415 = new TFile((PATH+"T2bWSMS_425_415/Outfile.root").c_str());
TFile* T2bW_526_516 = new TFile((PATH+"T2bWSMS_526_516/Outfile.root").c_str());
TFile* T2bW_526_505 = new TFile((PATH+"T2bWSMS_526_505/Outfile.root").c_str());

std::vector<TFile*> fs{ TSlepSlep_125_120, TSlepSlep_175_155, TChiWZ_300_270, TChiWZ_325_318, TChiWZ_425_405, T2bW_300_270, T2bW_425_415, T2bW_526_516, T2bW_526_505};
//sync this with fs
std::vector<std::string> stag{ "_ss125_120", "_ss175_155","_wz300_270", "_wz325_318","_wz425_405","_bw300_270","_bw425_415","_bw526_516","_bw526_505"};

std::vector<std::string> binType{ "1","1a","1b","1c","2a","2b","2c"};
TFile* out = new TFile("binstacks.root","RECREATE");

//stackrisrmperp(TChiWZ_300_270 ,bgs,"_wz300_270", "RISRMperp1" , out);
//stackrisrmperp(TChiWZ_300_270 ,bgs,"_wz300_270", "RISRMperp1a" , out);
//stackrisrmperp(TChiWZ_300_270 ,bgs,"_wz300_270", "RISRMperp1b" , out);
for(int i=0; i< fs.size(); i++){	
	for(int j=0; j<binType.size(); j++){
		stackrisrmperp(fs.at(i),bgs,stag.at(i), "RISRMperp"+binType.at(j), out);
	}	
}




}
