#include "ROOT/TThreadedObject.hxx"
//#include "histset.C"
#ifndef TOOLS
#define TOOLS

class bitset{
	public:
	bitset(int size);
	std::vector<bool> _b;
	bool test(int bit);
	void set(int bit);
	bool all();	
};
bitset::bitset(int size){
	std::vector<bool> bits(size,false);
	_b= bits;
}
bool bitset::test(int bit){
	return _b.at(bit);	
}
void bitset::set(int bit){
	_b.at(bit) = true;
}
bool bitset::all(){
	return std::all_of(_b.begin(), _b.end(), [](bool v) { return v; });
}

/*

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
		FillTH2(index,1,2,w);
	}


}
*/
#endif
