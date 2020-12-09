// Now in "histset2init.h"

void histset::init(){
//init TH1D
    TH1Manager.at(id_ptLep) = new MyTH1D("ptLepHist", "Lepton p_{T} Distribution;p_{T} (GeV)", 100, 0.0, 100);
    TH1Manager.at(id_nLep) = new MyTH1D("nLepHist","N Leptons",10,-0.5,9.5);

// init TH2D
    TH2Manager.at(id_RISRMperp) = new MyTH2D("RISRMperp", "RISR vs Mperp;RISR;Mperp",10,0.5,1.,10,0.,100.);
////////////// non example stuff
//
    TH1Manager.at(id_hset1) = new MyTH1D("hset1","sequence1",22,-0.5,21.5);
    TH1Manager.at(id_hset2) = new MyTH1D("hset2","sequence2",22,-0.5,21.5);

    TH2Manager.at(id_RISRMperp1) = new MyTH2D("RISRMperp1", "Seq.1 RISR vs Mperp;RISR;Mperp",10,0.5,1.,10,0.,100.);
    TH2Manager.at(id_RISRMperp2) = new MyTH2D("RISRMperp2", "Seq.2 RISR vs Mperp;RISR;Mperp",10,0.5,1.,10,0.,100.);

    TH2Manager.at(id_RISRMperp1a) = new MyTH2D("RISRMperp1a","Seq.1 Bin A RISR vs Mperp;RISR;Mperp",3,-0.5,2.5,3,-0.5,2.5);
    TH2Manager.at(id_RISRMperp2a) = new MyTH2D("RISRMperp2a","Seq.2 Bin A RISR vs Mperp;RISR;Mperp",3,-0.5,2.5,3,-0.5,2.5);

    TH2Manager.at(id_RISRMperp1b) = new MyTH2D("RISRMperp1b","Seq.1 Bin B RISR vs Mperp;RISR;Mperp",3,-0.5,2.5,3,-0.5,2.5);
    TH2Manager.at(id_RISRMperp2b) = new MyTH2D("RISRMperp2b","Seq.2 Bin B RISR vs Mperp;RISR;Mperp",3,-0.5,2.5,3,-0.5,2.5);

    TH2Manager.at(id_RISRMperp1c) = new MyTH2D("RISRMperp1c","Seq.1 Bin C RISR vs Mperp;RISR;Mperp",4,-0.5,3.5,4,-0.5,3.5);
    TH2Manager.at(id_RISRMperp2c) = new MyTH2D("RISRMperp2c","Seq.2 Bin C RISR vs Mperp;RISR;Mperp",4,-0.5,3.5,4,-0.5,3.5);

}//end histogram init

