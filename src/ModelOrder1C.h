#ifndef __MODELORDER0C_H__
#define __MODELORDER0C_H__

#include "ModelI.h"

class ModelOrder1C : public ModelI  
{
public:
	ModelOrder1C();
	~ModelOrder1C();

protected:
	void Encode();
	void Decode();
	void UpdateModel(unsigned int symbol);
	unsigned char CumulateFreqencies(unsigned char symbol, unsigned int& low_count, unsigned int& high_count, unsigned int& total);
	unsigned int determineSymbol(unsigned int value, unsigned int & low_count, unsigned int& high_count);

	struct CountBackingStore
	{
		unsigned int mCumCount[ 257 ] = {};
		unsigned int mTotal = 0;
		unsigned char mDefault = 0;
	};
	CountBackingStore *mCumCount = nullptr;
	CountBackingStore *mCumCountLookback[ 256 ] = {};
	CountBackingStore mCumCountCurrent = {};
	int mLastSymbol;
};

#endif 
