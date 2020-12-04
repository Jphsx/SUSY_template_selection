//    #include "mylocaltree.h"     //All the variable incantations needed
   	
	//always make a local copy, if its a value dereference. 
    //if you dont do this scope/dereferencing will get really weird, clunky, and unmanageable
	//have to auto& or myreader will try to register copy of the readerarray pointer

// Here we retain the old variable names as far as possible to minimize required changes


	auto& PT_lep = s.PT_lep;

	auto Nlep = *(s.Nlep);
	auto RISR = *(s.RISR);
	auto Mperp = *(s.Mperp);

