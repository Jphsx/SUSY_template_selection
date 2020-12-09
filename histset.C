#ifndef HISTS
#define HISTS
#include "TH1D.h"
#include "TH2D.h"
#include "TMath.h"
#include "ROOT/TThreadedObject.hxx"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "KUTree.h"
//#include "PCTools.h"
#include "Math/Vector3D.h"
#include "Math/Vector4D.h"
#include "TLorentzVector.h"
#include "SUSTools.h"
#include <iomanip>

using MyTH1D = ROOT::TThreadedObject<TH1D>;
using MyTH2D = ROOT::TThreadedObject<TH2D>;

// struct for derived quantities of each conversion


class histset{
    public:
       double PI =4.0*atan(1.0);
       histset();
       void init();
       void setweightoption();
       void AnalyzeEntry(KUTree& s);
       #include "Enums.h"
// make a big vector and load enumerated histograms onto the vector
       std::vector<MyTH1D*>  TH1Manager{};
       std::vector<MyTH2D*>  TH2Manager{};
// locate the histogram and perform pointer copying
       void FillTH1(int index, double x, double w);
       void FillSequence(bitset& bits, double w, int index);
       void FillTH2(int index, double x, double y, double w);
       void WriteHist();

	//helper f'n
	void FillBinSeqA(double RISR, double Mperp, double w, int index);
	void FillBinSeqB(double RISR, double Mperp, double w, int index);
	void FillBinSeqC(double RISR, double Mperp, double w, int index);
};

histset::histset(){
    std::vector<MyTH1D*>  Manager1(numTH1Hist);
    TH1Manager=Manager1;
    std::vector<MyTH2D*>  Manager2(numTH2Hist);
    TH2Manager=Manager2;
    init();
    setweightoption();
}

void histset::setweightoption(){
    for(int i=0; i<numTH1Hist; i++){
        auto hptr = TH1Manager.at(i)->Get();
        hptr->Sumw2(kTRUE);
    }
    for(int i=0; i<numTH2Hist; i++){
        auto hptr = TH2Manager.at(i)->Get();
        hptr->Sumw2(kTRUE);
    }
}

#include "Hists.h"     //Put the histogram declarations in one separate file


void histset::FillTH1(int index, double x, double w=1.0){
	//we must make pointer copies for performance reasons when trying to fill a histogram
	auto myhist = TH1Manager.at(index)->Get();
	myhist->Fill(x,w);
}

void histset::FillTH2(int index, double x, double y, double w=1.0){
	auto myhist = TH2Manager.at(index)->Get();
	myhist->Fill(x,y,w);
}

void histset::FillSequence(bitset& bits, double w, int index){
        bool flag = true;
        for(int i=0; i<bits._b.size(); i++){
                if( !bits.test(i) ) flag = false;
		if( flag) FillTH1(index, i, w);
        }

}

void histset::WriteHist(){

	TFile* outfile = new TFile("Outfile.root", "RECREATE");

	for(int i=0; i<numTH1Hist; i++){
	//do a check for entries, merge isn't safe for empty histograms
        auto hptr = TH1Manager.at(i)->Get();
	   if(hptr->GetEntries() > 0){
           auto histmerged = TH1Manager.at(i)->Merge();
           TH1D* h = (TH1D*) histmerged->Clone();
		   outfile->WriteObject(h, h->GetName() );
        }
        else{
           auto h = TH1Manager.at(i)->Get()->Clone();
           outfile->WriteObject(h, h->GetName() );
        }
	}


	for(int i=0; i<numTH2Hist; i++){
	//do a check for entries, merge isn't safe for empty histograms
        auto hptr = TH2Manager.at(i)->Get();
	    if(hptr->GetEntries() > 0){
           auto histmerged = TH2Manager.at(i)->Merge();
           TH2D* h = (TH2D*) histmerged->Clone();
		   outfile->WriteObject(h, h->GetName() );
        }
        else{
           auto h = TH2Manager.at(i)->Get()->Clone();
           outfile->WriteObject(h, h->GetName() );
        }
	}


	outfile->Close();
}
void histset::FillBinSeqA(double RISR, double Mperp, double w, int index){

        if( RISR <= 1 && RISR >0.9 && Mperp <=20 ){//bin0
                FillTH2(index,2,0,w);
        }
        if( RISR <= 0.9 && RISR > 0.8 && Mperp <=20){//bin1
                FillTH2(index,1,0,w);
        }
        if( RISR <= 0.8 && RISR > 0.6 && Mperp <=20){//bin2
                FillTH2(index,0,0,w);
        }
        if( RISR <= 1 && RISR> 0.9 && Mperp>20 && Mperp<=50){//bin3
                FillTH2(index,2,1,w);
        }
        if( RISR <= 0.9 && RISR > 0.8 && Mperp > 20 && Mperp<=50){//bin4
                FillTH2(index,1,1,w);
        }
        if( RISR <= 0.8 && RISR > 0.6 && Mperp > 20 && Mperp<=50){//bin5
                FillTH2(index,0,1,w);
        }
        if( RISR <= 1 && RISR> 0.9 && Mperp>50 && Mperp<=100){//bin6
                FillTH2(index,2,2,w);
        }
        if(RISR <=0.9 && RISR> 0.8 && Mperp>50 && Mperp<=100){//bin7
                FillTH2(index,1,2,w);
        }
        if(RISR <=0.8 && RISR> 0.6 && Mperp>50 && Mperp<=100){//bin8
                FillTH2(index,0,2,w);
        }
}

void histset::FillBinSeqB(double RISR, double Mperp, double w, int index){

        if( RISR <=1 && RISR>0.9 && Mperp <=20){//bin0
                FillTH2(index,2,0,w);
        }
        if( RISR <=0.9 && RISR>0.8 && Mperp <=20){//bin1
                FillTH2(index,1,0,w);
        }
        if( RISR <=0.8 && RISR>0.6 && Mperp <=50){//bin2
                FillTH2(index,0,0,w);
        }
        if( RISR <=1 && RISR>0.9 && Mperp>20 && Mperp<=50){//bin3
                FillTH2(index,2,1,w);
        }
        if( RISR <=0.9 && RISR>0.8 && Mperp>20 && Mperp<=50){//bin4
                FillTH2(index,1,1,w);
        }
        if( RISR <=1 && RISR>0.8 && Mperp >50 && Mperp<=100){//bin5
                FillTH2(index,2,2,w);
        }
        if( RISR <=0.8 && RISR>0.6 && Mperp>50 && Mperp<=100){//bin6
                FillTH2(index,0,2,w);
        }


}
void histset::FillBinSeqC(double RISR, double Mperp, double w, int index){

	if( RISR <=1 && RISR>0.95 && Mperp <=10){//bin0
		FillTH2(index,3,0,w);
	}
	if( RISR <=0.95 && RISR>0.9 && Mperp <=10){//bin1
		FillTH2(index,2,0,w);
	}
	if( RISR <=0.9 && RISR>0.8 && Mperp <=20){//bin2
		FillTH2(index,1,0,w);
	}	
	if( RISR <=0.8 && RISR>0.6 && Mperp<= 50){//bin3
		FillTH2(index,0,0,w);
	}
	if( RISR <=1 && RISR> 0.95 && Mperp >10 && Mperp<=20){//bin4
		FillTH2(index,3,1,w);
	}
	if( RISR <=0.95 && RISR>0.9 && Mperp >10 && Mperp<=20){//bin5
		FillTH2(index,2,1,w);
	}
	if( RISR <=1 && RISR>0.9 && Mperp>20 && Mperp<=50){//bin6
		FillTH2(index,3,2,w);
	}	
	if( RISR<=0.9 && RISR>0.8 && Mperp>20 && Mperp<=50){
		FillTH2(index,1,2,w);
	}
	if( RISR<=1 && RISR>0.8 && Mperp>50 && Mperp<=100){
		FillTH2(index,3,3,w);
	}
	if( RISR<=0.8 && RISR>0.6 && Mperp>50 && Mperp<=100){
		FillTH2(index,0,3,w);
	}

}

void histset::AnalyzeEntry(KUTree& s){
	
	#include "localTreeMembers.h"     //All the variable incantations needed
	double w = weight*137.;
//	std::cout<<"x";
	FillTH1( id_nLep, Nlep ,w);

	for(int i=0; i<Nlep; i++){
		FillTH1( id_ptLep, PT_lep[i], w);	
	}

	FillTH2( id_RISRMperp, RISR, Mperp, w);


///////////////graham snippet of usefule quantitites///
    int Nposl = 0;
    int Nnegl = 0;
    int Nidentified = 0;
    int Nisolated = 0;
    int Nprompt = 0;
// Count leptons: positive, negative, IDd, isolated, prompt.
    double maxsip3d = 0.0;
    double maxisovalue = 0.0;
    for(int i=0; i<Nlep; i++){
        if((ID_lep)[i] >=3)Nidentified +=1;
        if((MiniIso_lep)[i]*(PT_lep)[i] < 6.0)Nisolated +=1;
        if((MiniIso_lep)[i]*(PT_lep)[i] > maxisovalue)maxisovalue = (MiniIso_lep)[i]*(PT_lep)[i];
        if(abs((SIP3D_lep)[i]) < 4.0)Nprompt +=1;
        if(abs((SIP3D_lep)[i]) > maxsip3d) maxsip3d = abs((SIP3D_lep)[i]);
        if((Charge_lep)[i] >= 1){
           Nposl += 1;
        }
        else if((Charge_lep)[i] <= -1){
           Nnegl += 1;
        }
        else{
         //  cout << "Funny charge ?? " << i << " " << Charge_lep[i] << endl;
        }
    }
/////////////////////




	double maxsipmu=2.;
        double maxsipel=2.;
        double maxisomu=4.;//this is miniIso
        double maxisoel=4.;
        double maxrelisomu=4.;//this quantity is actually abspfiso now
        double maxrelisoel=4.;
	//cleaning cuts added in
	//define clean1 as ptcm<75 and dphiCMI < pi/4  and clean2 as ptcm<100 and dphiCMI > 3pi/4
	//define set 1 as N SJets = 0
	enum set1{ s1evtfltr=0, s1mtrg=1,s1metv=2, s1clean=3, s1lep=4, s12L=5, s1os=6, s1sf=7, s1j0=8, s1b=9, s1met=10, s1ptisr=11, s1risrlo=12, s1mll=13, s1id1=14, s1sip1=15, s1iso1=16, s1id2=17, s1sip2=18, s1iso2=19, s1reliso1=20, s1reliso2=21, s1numcuts=22};
	//define set 2 as N SJets >= 1
	enum set2{ s2evtfltr=0, s2mtrg=1,s2metv=2, s2clean=3, s2lep=4, s22L=5, s2os=6, s2sf=7, s2j1p=8, s2b=9, s2met=10, s2ptisr=11, s2risrlo=12, s2mll=13, s2id1=14, s2sip1=15, s2iso1=16, s2id2=17, s2sip2=18, s2iso2=19,s2reliso1=20, s2reliso2=21, s2numcuts=22};


	bitset s1bit(s1numcuts);
	bitset s2bit(s2numcuts);

	if(EventFilter){
		s1bit.set(s1evtfltr);
		s2bit.set(s2evtfltr);
	}
	if(METtrigger || !METtrigger){
		s1bit.set(s1mtrg);
		s2bit.set(s2mtrg);
	}
	if( abs(dphiMET_V) < PI/2. ){
		s1bit.set(s1metv);
		s2bit.set(s2metv);
	}
	if( (dphiCMI < (3.*PI)/4.) && (dphiCMI > PI/4.)  ){
		s1bit.set(s1clean);
		s2bit.set(s2clean);
	}
	else if((dphiCMI < PI/4.) && (PTCM<75.) ){
		s1bit.set(s1clean);
		s2bit.set(s2clean);
	}
	else if((dphiCMI > (3.*PI)/4.) && (PTCM<100.)){
		s1bit.set(s1clean);
		s2bit.set(s2clean);
	}	
	if(Nlep >= 2 ){
                s1bit.set(s1lep);
                s2bit.set(s2lep);
	}
	if(Nlep == 2){
                s1bit.set(s12L);
                s2bit.set(s22L);
	}	
	if(Nposl ==1 || Nnegl==1){
                s1bit.set(s1os);
                s2bit.set(s2os);	
	}
	if(Nmu==2 || Nele==2){
                s1bit.set(s1sf);
                s2bit.set(s2sf);
	}
	if( Njet_S == 0 ){
                s1bit.set(s1j0);
        }
	if( Njet_S == 1){
                s2bit.set(s2j1p);
        }
	if( Nbjet == 0){
                s1bit.set(s1b);
                s2bit.set(s2b);
	}
	if( MET > 175 ){
                s1bit.set(s1met);
                s2bit.set(s2met);
	}
	if( PTISR > 200 ){
                s1bit.set(s1ptisr);
                s2bit.set(s2ptisr);
	}
	 if( RISR > 0.6){
                s1bit.set(s1risrlo);
                s2bit.set(s2risrlo);
	}
	
	double mll;
        if( Nlep == 2){
                TLorentzVector l1;
                TLorentzVector l2;
                l1.SetPtEtaPhiM((PT_lep)[0], (Eta_lep)[0], (Phi_lep)[0], (M_lep)[0]);
                l2.SetPtEtaPhiM((PT_lep)[1], (Eta_lep)[1], (Phi_lep)[1], (M_lep)[1]);
                mll = (l1+l2).M();
        }

        if( mll <= 70 ){
                s1bit.set(s1mll);
                s2bit.set(s2mll);
	}

	//the next set of cuts we require 2 leptons 
	if( Nlep == 2){
		double iso1,iso2;
                iso1=(MiniIso_lep)[0]*(PT_lep)[0];
                iso2=(MiniIso_lep)[1]*(PT_lep)[1];
		double reliso1, reliso2;
                reliso1=(RelIso_lep)[0]*(PT_lep)[0];
                reliso2=(RelIso_lep)[1]*(PT_lep)[1];
		double sip1,sip2;
                sip1=(SIP3D_lep)[0];
                sip2=(SIP3D_lep)[1];
		//lepton 0 id cut
		if( ((ID_lep)[0] >= 3 && abs((PDGID_lep)[0])==13) || ( (ID_lep)[0] >= 4 && abs((PDGID_lep)[0])==11) ) {
                                s1bit.set(s1id1);
                                s2bit.set(s2id1);
		}
		//lepton 0 miniIso cut
		if( (iso1 < maxisomu && abs((PDGID_lep)[0])==13) || ( iso1 < maxisoel && abs((PDGID_lep)[0])==11) ) {
                                s1bit.set(s1iso1);
                                s2bit.set(s2iso1);
		}
		//lepton 0 pf iso cut
		if( (reliso1 < maxrelisomu && abs((PDGID_lep)[0])==13) || ( reliso1 < maxrelisoel && abs((PDGID_lep)[0])==11) ) { 
                                s1bit.set(s1reliso1);
                                s2bit.set(s2reliso1);
		}
		//lepton 0 sip cut
		if( (sip1 < maxsipmu && abs((PDGID_lep)[0])==13) || ( sip1 < maxsipel && abs((PDGID_lep)[0])==11) ) {
                                s1bit.set(s1sip1);
                                s2bit.set(s2sip1);	
		}
		//lepton 1 id cut
		if( ((ID_lep)[1*2] >= 3 && abs((PDGID_lep)[1])==13) || ( (ID_lep)[1] >= 4 && abs((PDGID_lep)[1*2])==11) ) {
		//if(true){
		                s1bit.set(s1id2);

                                s2bit.set(s2id2);
		}
		//lepton 1 miniIso cut
		if( (iso2 < maxisomu && abs((PDGID_lep)[1])==13) || ( iso2 < maxisoel && abs((PDGID_lep)[1])==11) ) {
                                s1bit.set(s1iso2);
                                s2bit.set(s2iso2);
		}
		//lepton 1 pf iso cut	
		if( (reliso2 < maxrelisomu && abs((PDGID_lep)[1])==13) || ( reliso2 < maxrelisoel && abs((PDGID_lep)[1])==11) ) {
                                s1bit.set(s1reliso2);
                                s2bit.set(s2reliso2);
		}
		//lepton 1 sip cut
		if( (sip2 < maxsipmu && abs((PDGID_lep)[1])==13) || ( sip2 < maxsipel && abs((PDGID_lep)[1])==11) ) {
                                s1bit.set(s1sip2);
                                s2bit.set(s2sip2);
		}

	}

	//generate cutflow
	FillSequence(s1bit, w, id_hset1);
	FillSequence(s2bit, w, id_hset2);

	//fill hists with events that pass all cuts
	if(s1bit.all()){
		FillTH2(id_RISRMperp1, RISR, Mperp, w);
		FillBinSeqA( RISR,  Mperp, w, id_RISRMperp1a);
		FillBinSeqB( RISR,  Mperp, w, id_RISRMperp1b);
		FillBinSeqC( RISR,  Mperp, w, id_RISRMperp1c);
	}
	if(s2bit.all()){
		FillTH2(id_RISRMperp2, RISR, Mperp, w);
		FillBinSeqA( RISR,  Mperp, w, id_RISRMperp2a);
                FillBinSeqB( RISR,  Mperp, w, id_RISRMperp2b);
		FillBinSeqC( RISR,  Mperp, w, id_RISRMperp2c);
	}

}  // End of sub-program
#endif
