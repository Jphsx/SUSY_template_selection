//    #include "mylocaltree.h"     //All the variable incantations needed
   	
	//always make a local copy, if its a value dereference. 
    //if you dont do this scope/dereferencing will get really weird, clunky, and unmanageable
	//have to auto& or myreader will try to register copy of the readerarray pointer

// Here we retain the old variable names as far as possible to minimize required changes


	auto& PT_lep = s.PT_lep;
	auto weight = *(s.weight);
	auto Nlep = *(s.Nlep);
	auto RISR = *(s.RISR);
	auto Mperp = *(s.Mperp);
	auto Nmu = *(s.Nmu);
	auto Nele = *(s.Nele);
	auto Nbjet = *(s.Nbjet);
	auto MET = *(s.MET);
	auto PTISR = *(s.PTISR);
	auto Njet_S = *(s.Njet_S);
	auto EventFilter = *(s.EventFilter);
	auto METtrigger = *(s.METtrigger);
	auto PTCM = *(s.PTCM);
	auto dphiCMI = *(s.dphiCMI);
	auto dphiMET_V = *(s.dphiMET_V);

	auto& ID_lep = s.ID_lep;
	auto& MiniIso_lep = s.MiniIso_lep;
	auto& SIP3D_lep = s.SIP3D_lep;
	auto& Charge_lep = s.Charge_lep;
	auto& PDGID_lep = s.PDGID_lep;	
	auto& RelIso_lep = s.RelIso_lep;
	auto& Eta_lep = s.Eta_lep;
	auto& Phi_lep = s.Phi_lep;
	auto& M_lep = s.M_lep;
		
	
