// Now in "histset2init.h"

void histset::init(){
//init TH1D
    TH1Manager.at(id_ptLep) = new MyTH1D("ptLepHist", "Lepton p_{T} Distribution;p_{T} (GeV)", 100, 0.0, 100);
    TH1Manager.at(id_nLep) = new MyTH1D("nLepHist","N Leptons",10,-0.5,9.5);

// init TH2D
    TH2Manager.at(id_RISRMperp) = new MyTH2D("RISRMperp", "RISR vs Mperp;RISR;Mperp",10,0.5,1.,10,0.,100.);
}//end histogram init

