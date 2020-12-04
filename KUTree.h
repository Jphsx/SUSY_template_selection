//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov 11 10:26:05 2020 by ROOT version 6.14/09
// from TTree KUAnalysis/KUAnalysis
// found on file: ../WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_102X.root
//////////////////////////////////////////////////////////

#ifndef KUTree_h
#define KUTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class KUTree : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Bool_t> event_skipped = {fReader, "event_skipped"};
   TTreeReaderValue<Double_t> weight = {fReader, "weight"};
   TTreeReaderValue<Double_t> PUweight = {fReader, "PUweight"};
   TTreeReaderValue<Double_t> PUweight_up = {fReader, "PUweight_up"};
   TTreeReaderValue<Double_t> PUweight_down = {fReader, "PUweight_down"};
   TTreeReaderValue<Double_t> BtagSFweight = {fReader, "BtagSFweight"};
   TTreeReaderValue<Double_t> BtagSFweight_up = {fReader, "BtagSFweight_up"};
   TTreeReaderValue<Double_t> BtagSFweight_down = {fReader, "BtagSFweight_down"};
   TTreeReaderValue<Int_t> runnum = {fReader, "runnum"};
   TTreeReaderValue<Int_t> luminum = {fReader, "luminum"};
   TTreeReaderValue<Long64_t> eventnum = {fReader, "eventnum"};
   TTreeReaderValue<Int_t> NPV = {fReader, "NPV"};
   TTreeReaderValue<Bool_t> EventFilter = {fReader, "EventFilter"};
   TTreeReaderValue<Bool_t> METtrigger = {fReader, "METtrigger"};
   TTreeReaderValue<Bool_t> METHTtrigger = {fReader, "METHTtrigger"};
   TTreeReaderValue<Bool_t> METORtrigger = {fReader, "METORtrigger"};
   TTreeReaderValue<Double_t> MET = {fReader, "MET"};
   TTreeReaderValue<Double_t> MET_phi = {fReader, "MET_phi"};
   TTreeReaderValue<Double_t> HT = {fReader, "HT"};
   TTreeReaderValue<Int_t> Nele = {fReader, "Nele"};
   TTreeReaderValue<Int_t> Nmu = {fReader, "Nmu"};
   TTreeReaderValue<Int_t> Nlep = {fReader, "Nlep"};
   TTreeReaderArray<double> PT_lep = {fReader, "PT_lep"};
   TTreeReaderArray<double> Eta_lep = {fReader, "Eta_lep"};
   TTreeReaderArray<double> Phi_lep = {fReader, "Phi_lep"};
   TTreeReaderArray<double> M_lep = {fReader, "M_lep"};
   TTreeReaderArray<int> Charge_lep = {fReader, "Charge_lep"};
   TTreeReaderArray<int> PDGID_lep = {fReader, "PDGID_lep"};
   TTreeReaderArray<double> RelIso_lep = {fReader, "RelIso_lep"};
   TTreeReaderArray<double> MiniIso_lep = {fReader, "MiniIso_lep"};
   TTreeReaderArray<double> Dxy_lep = {fReader, "Dxy_lep"};
   TTreeReaderArray<double> DxyErr_lep = {fReader, "DxyErr_lep"};
   TTreeReaderArray<double> Dz_lep = {fReader, "Dz_lep"};
   TTreeReaderArray<double> DzErr_lep = {fReader, "DzErr_lep"};
   TTreeReaderArray<double> IP3D_lep = {fReader, "IP3D_lep"};
   TTreeReaderArray<double> SIP3D_lep = {fReader, "SIP3D_lep"};
   TTreeReaderArray<int> ID_lep = {fReader, "ID_lep"};
   TTreeReaderArray<int> Index_lep = {fReader, "Index_lep"};
   TTreeReaderValue<Int_t> Njet = {fReader, "Njet"};
   TTreeReaderValue<Int_t> Nbjet = {fReader, "Nbjet"};
   TTreeReaderArray<double> PT_jet = {fReader, "PT_jet"};
   TTreeReaderArray<double> Eta_jet = {fReader, "Eta_jet"};
   TTreeReaderArray<double> Phi_jet = {fReader, "Phi_jet"};
   TTreeReaderArray<double> M_jet = {fReader, "M_jet"};
   TTreeReaderArray<double> Btag_jet = {fReader, "Btag_jet"};
   TTreeReaderArray<int> BtagID_jet = {fReader, "BtagID_jet"};
   TTreeReaderArray<double> Flavor_jet = {fReader, "Flavor_jet"};
   TTreeReaderArray<int> index_jet_a = {fReader, "index_jet_a"};
   TTreeReaderArray<int> index_jet_b = {fReader, "index_jet_b"};
   TTreeReaderArray<int> index_jet_ISR = {fReader, "index_jet_ISR"};
   TTreeReaderArray<int> index_jet_S = {fReader, "index_jet_S"};
   TTreeReaderValue<Int_t> NSV = {fReader, "NSV"};
   TTreeReaderArray<double> PT_SV = {fReader, "PT_SV"};
   TTreeReaderArray<double> Eta_SV = {fReader, "Eta_SV"};
   TTreeReaderArray<double> Phi_SV = {fReader, "Phi_SV"};
   TTreeReaderArray<double> M_SV = {fReader, "M_SV"};
   TTreeReaderArray<double> ProbB_SV = {fReader, "ProbB_SV"};
   TTreeReaderArray<double> ProbC_SV = {fReader, "ProbC_SV"};
   TTreeReaderValue<Int_t> Njet_ISR = {fReader, "Njet_ISR"};
   TTreeReaderValue<Int_t> Njet_S = {fReader, "Njet_S"};
   TTreeReaderValue<Int_t> Nbjet_ISR = {fReader, "Nbjet_ISR"};
   TTreeReaderValue<Int_t> Nbjet_S = {fReader, "Nbjet_S"};
   TTreeReaderValue<Int_t> Nlep_ISR = {fReader, "Nlep_ISR"};
   TTreeReaderValue<Int_t> Nlep_S = {fReader, "Nlep_S"};
   TTreeReaderValue<Int_t> NSV_ISR = {fReader, "NSV_ISR"};
   TTreeReaderValue<Int_t> NSV_S = {fReader, "NSV_S"};
   TTreeReaderArray<int> index_SV_ISR = {fReader, "index_SV_ISR"};
   TTreeReaderArray<int> index_SV_S = {fReader, "index_SV_S"};
   TTreeReaderArray<int> index_lep_ISR = {fReader, "index_lep_ISR"};
   TTreeReaderArray<int> index_lep_S = {fReader, "index_lep_S"};
   TTreeReaderArray<double> dphi_lep_S = {fReader, "dphi_lep_S"};
   TTreeReaderArray<double> cos_lep_S = {fReader, "cos_lep_S"};
   TTreeReaderArray<double> dphi_jet_S = {fReader, "dphi_jet_S"};
   TTreeReaderArray<double> cos_jet_S = {fReader, "cos_jet_S"};
   TTreeReaderArray<double> dphi_SV_S = {fReader, "dphi_SV_S"};
   TTreeReaderArray<double> cos_SV_S = {fReader, "cos_SV_S"};
   TTreeReaderArray<double> dphiMET_lep_S = {fReader, "dphiMET_lep_S"};
   TTreeReaderArray<double> dphiMET_jet_S = {fReader, "dphiMET_jet_S"};
   TTreeReaderArray<double> dphiMET_SV_S = {fReader, "dphiMET_SV_S"};
   TTreeReaderValue<Int_t> Njet_a = {fReader, "Njet_a"};
   TTreeReaderValue<Int_t> Njet_b = {fReader, "Njet_b"};
   TTreeReaderValue<Int_t> Nbjet_a = {fReader, "Nbjet_a"};
   TTreeReaderValue<Int_t> Nbjet_b = {fReader, "Nbjet_b"};
   TTreeReaderValue<Int_t> Nlep_a = {fReader, "Nlep_a"};
   TTreeReaderValue<Int_t> Nlep_b = {fReader, "Nlep_b"};
   TTreeReaderValue<Int_t> NSV_a = {fReader, "NSV_a"};
   TTreeReaderValue<Int_t> NSV_b = {fReader, "NSV_b"};
   TTreeReaderArray<int> index_lep_a = {fReader, "index_lep_a"};
   TTreeReaderArray<int> index_lep_b = {fReader, "index_lep_b"};
   TTreeReaderArray<int> index_SV_a = {fReader, "index_SV_a"};
   TTreeReaderArray<int> index_SV_b = {fReader, "index_SV_b"};
   TTreeReaderValue<Double_t> PTCM = {fReader, "PTCM"};
   TTreeReaderValue<Double_t> PzCM = {fReader, "PzCM"};
   TTreeReaderValue<Double_t> cosCM = {fReader, "cosCM"};
   TTreeReaderValue<Double_t> dphiCM = {fReader, "dphiCM"};
   TTreeReaderValue<Double_t> dphiCMI = {fReader, "dphiCMI"};
   TTreeReaderValue<Double_t> MS = {fReader, "MS"};
   TTreeReaderValue<Double_t> PS = {fReader, "PS"};
   TTreeReaderValue<Double_t> cosS = {fReader, "cosS"};
   TTreeReaderValue<Double_t> dphiS = {fReader, "dphiS"};
   TTreeReaderValue<Double_t> dphiSI = {fReader, "dphiSI"};
   TTreeReaderValue<Double_t> PTS = {fReader, "PTS"};
   TTreeReaderValue<Double_t> PzS = {fReader, "PzS"};
   TTreeReaderValue<Double_t> MX3a = {fReader, "MX3a"};
   TTreeReaderValue<Double_t> MX3b = {fReader, "MX3b"};
   TTreeReaderValue<Double_t> EVa = {fReader, "EVa"};
   TTreeReaderValue<Double_t> EVb = {fReader, "EVb"};
   TTreeReaderValue<Double_t> PVa = {fReader, "PVa"};
   TTreeReaderValue<Double_t> PVb = {fReader, "PVb"};
   TTreeReaderValue<Double_t> EJa = {fReader, "EJa"};
   TTreeReaderValue<Double_t> EJb = {fReader, "EJb"};
   TTreeReaderValue<Double_t> PJa = {fReader, "PJa"};
   TTreeReaderValue<Double_t> PJb = {fReader, "PJb"};
   TTreeReaderValue<Double_t> MX2a = {fReader, "MX2a"};
   TTreeReaderValue<Double_t> MX2b = {fReader, "MX2b"};
   TTreeReaderValue<Double_t> ELa = {fReader, "ELa"};
   TTreeReaderValue<Double_t> ELb = {fReader, "ELb"};
   TTreeReaderValue<Double_t> PLa = {fReader, "PLa"};
   TTreeReaderValue<Double_t> PLb = {fReader, "PLb"};
   TTreeReaderValue<Double_t> MV = {fReader, "MV"};
   TTreeReaderValue<Double_t> PV = {fReader, "PV"};
   TTreeReaderValue<Double_t> MVa = {fReader, "MVa"};
   TTreeReaderValue<Double_t> MVb = {fReader, "MVb"};
   TTreeReaderValue<Double_t> PV_lab = {fReader, "PV_lab"};
   TTreeReaderValue<Double_t> dphiMET_V = {fReader, "dphiMET_V"};
   TTreeReaderValue<Double_t> MJa = {fReader, "MJa"};
   TTreeReaderValue<Double_t> MJb = {fReader, "MJb"};
   TTreeReaderValue<Double_t> MLa = {fReader, "MLa"};
   TTreeReaderValue<Double_t> MLb = {fReader, "MLb"};
   TTreeReaderValue<Double_t> cosJa = {fReader, "cosJa"};
   TTreeReaderValue<Double_t> cosJb = {fReader, "cosJb"};
   TTreeReaderValue<Double_t> cosLa = {fReader, "cosLa"};
   TTreeReaderValue<Double_t> cosLb = {fReader, "cosLb"};
   TTreeReaderValue<Double_t> MJ = {fReader, "MJ"};
   TTreeReaderValue<Double_t> ML = {fReader, "ML"};
   TTreeReaderValue<Double_t> EJ = {fReader, "EJ"};
   TTreeReaderValue<Double_t> EL = {fReader, "EL"};
   TTreeReaderValue<Double_t> PJ = {fReader, "PJ"};
   TTreeReaderValue<Double_t> PL = {fReader, "PL"};
   TTreeReaderValue<Double_t> PX3 = {fReader, "PX3"};
   TTreeReaderValue<Double_t> PX3_BoostT = {fReader, "PX3_BoostT"};
   TTreeReaderValue<Double_t> MX3a_BoostT = {fReader, "MX3a_BoostT"};
   TTreeReaderValue<Double_t> MX3b_BoostT = {fReader, "MX3b_BoostT"};
   TTreeReaderValue<Double_t> Mperp = {fReader, "Mperp"};
   TTreeReaderValue<Double_t> PV_BoostT = {fReader, "PV_BoostT"};
   TTreeReaderValue<Double_t> EVa_BoostT = {fReader, "EVa_BoostT"};
   TTreeReaderValue<Double_t> EVb_BoostT = {fReader, "EVb_BoostT"};
   TTreeReaderValue<Double_t> PVa_BoostT = {fReader, "PVa_BoostT"};
   TTreeReaderValue<Double_t> PVb_BoostT = {fReader, "PVb_BoostT"};
   TTreeReaderValue<Double_t> EJ_BoostT = {fReader, "EJ_BoostT"};
   TTreeReaderValue<Double_t> EL_BoostT = {fReader, "EL_BoostT"};
   TTreeReaderValue<Double_t> PJ_BoostT = {fReader, "PJ_BoostT"};
   TTreeReaderValue<Double_t> PL_BoostT = {fReader, "PL_BoostT"};
   TTreeReaderValue<Double_t> H11S = {fReader, "H11S"};
   TTreeReaderValue<Double_t> H21S = {fReader, "H21S"};
   TTreeReaderValue<Double_t> HT21S = {fReader, "HT21S"};
   TTreeReaderValue<Double_t> H22S = {fReader, "H22S"};
   TTreeReaderValue<Double_t> HT22S = {fReader, "HT22S"};
   TTreeReaderValue<Double_t> H42S = {fReader, "H42S"};
   TTreeReaderValue<Double_t> HT42S = {fReader, "HT42S"};
   TTreeReaderValue<Double_t> H11X3a = {fReader, "H11X3a"};
   TTreeReaderValue<Double_t> H11X3b = {fReader, "H11X3b"};
   TTreeReaderValue<Double_t> H21X3a = {fReader, "H21X3a"};
   TTreeReaderValue<Double_t> H21X3b = {fReader, "H21X3b"};
   TTreeReaderValue<Double_t> PISR = {fReader, "PISR"};
   TTreeReaderValue<Double_t> PTISR = {fReader, "PTISR"};
   TTreeReaderValue<Double_t> RISR = {fReader, "RISR"};
   TTreeReaderValue<Double_t> RISRT = {fReader, "RISRT"};
   TTreeReaderValue<Double_t> MISR = {fReader, "MISR"};
   TTreeReaderValue<Int_t> NPU = {fReader, "NPU"};
   TTreeReaderValue<Double_t> genMET = {fReader, "genMET"};
   TTreeReaderValue<Double_t> genMET_phi = {fReader, "genMET_phi"};
   TTreeReaderValue<Int_t> genNele = {fReader, "genNele"};
   TTreeReaderValue<Int_t> genNmu = {fReader, "genNmu"};
   TTreeReaderValue<Int_t> genNlep = {fReader, "genNlep"};
   TTreeReaderArray<double> genPT_lep = {fReader, "genPT_lep"};
   TTreeReaderArray<double> genEta_lep = {fReader, "genEta_lep"};
   TTreeReaderArray<double> genPhi_lep = {fReader, "genPhi_lep"};
   TTreeReaderArray<double> genM_lep = {fReader, "genM_lep"};
   TTreeReaderArray<int> genCharge_lep = {fReader, "genCharge_lep"};
   TTreeReaderArray<int> genPDGID_lep = {fReader, "genPDGID_lep"};
   TTreeReaderArray<int> genMomPDGID_lep = {fReader, "genMomPDGID_lep"};
   TTreeReaderArray<int> genIndex_lep = {fReader, "genIndex_lep"};
   TTreeReaderValue<Int_t> genNnu = {fReader, "genNnu"};
   TTreeReaderArray<double> genPT_nu = {fReader, "genPT_nu"};
   TTreeReaderArray<double> genEta_nu = {fReader, "genEta_nu"};
   TTreeReaderArray<double> genPhi_nu = {fReader, "genPhi_nu"};
   TTreeReaderArray<int> genPDGID_nu = {fReader, "genPDGID_nu"};
   TTreeReaderArray<int> genMomPDGID_nu = {fReader, "genMomPDGID_nu"};
   TTreeReaderValue<Int_t> genNboson = {fReader, "genNboson"};
   TTreeReaderArray<double> genPT_boson = {fReader, "genPT_boson"};
   TTreeReaderArray<double> genEta_boson = {fReader, "genEta_boson"};
   TTreeReaderArray<double> genPhi_boson = {fReader, "genPhi_boson"};
   TTreeReaderArray<double> genM_boson = {fReader, "genM_boson"};
   TTreeReaderArray<int> genPDGID_boson = {fReader, "genPDGID_boson"};
   TTreeReaderArray<int> genMomPDGID_boson = {fReader, "genMomPDGID_boson"};
   TTreeReaderValue<Int_t> genNsusy = {fReader, "genNsusy"};
   TTreeReaderArray<double> genPT_susy = {fReader, "genPT_susy"};
   TTreeReaderArray<double> genEta_susy = {fReader, "genEta_susy"};
   TTreeReaderArray<double> genPhi_susy = {fReader, "genPhi_susy"};
   TTreeReaderArray<double> genM_susy = {fReader, "genM_susy"};
   TTreeReaderArray<int> genPDGID_susy = {fReader, "genPDGID_susy"};
   TTreeReaderArray<int> genMomPDGID_susy = {fReader, "genMomPDGID_susy"};


   KUTree(TTree * /*tree*/ =0) { }
   virtual ~KUTree() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   //ClassDef(KUTree,0);

};

#endif

#ifdef KUTree_cxx
void KUTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t KUTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef KUTree_cxx
