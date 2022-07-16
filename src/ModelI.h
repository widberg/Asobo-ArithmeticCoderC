#ifndef __MODELI_H__
#define __MODELI_H__

#include "ArithmeticCoderC.h"

enum ModeE
{
	MODE_ENCODE = 0,
	MODE_DECODE
};

class ModelI  
{
public:
	void Process( fstream *source, fstream *target, ModeE mode );

protected:
	virtual void Encode() = 0;
	virtual void Decode() = 0;

	ArithmeticCoderC mAC;
	fstream *mSource;
	fstream *mTarget;

	unsigned int mCompressedSize = 0;
	unsigned int mDecompressedSize = 0;
};

#endif
