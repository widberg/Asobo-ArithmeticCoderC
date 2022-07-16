#include "ModelI.h"

#include <iostream>

void ModelI::Process( fstream *source, fstream *target, ModeE mode )
{
	mSource = source;
	mTarget = target;

	if( mode == MODE_ENCODE )
	{
		mSource->seekg(0, std::ios::end);
		mDecompressedSize = (unsigned int)mSource->tellg();
		mSource->seekg(0, std::ios::beg);
		mTarget->seekp(4, std::ios::beg);
		mTarget->write(reinterpret_cast<char*>(&mDecompressedSize), sizeof(mDecompressedSize));

		mAC.SetFile( mTarget );

		// encode
		Encode();

		mAC.EncodeFinish();

		char zero = 0;
		mTarget->write(&zero, sizeof(zero));
		mTarget->seekp(0, std::ios::end);
		mCompressedSize = (unsigned int)mTarget->tellp();
		mTarget->seekp(0, std::ios::beg);
		mTarget->write(reinterpret_cast<char*>(&mCompressedSize), sizeof(mCompressedSize));
	}
	else // MODE_DECODE
	{
		mSource->read(reinterpret_cast<char*>(&mCompressedSize), sizeof(mCompressedSize));
		mSource->read(reinterpret_cast<char*>(&mDecompressedSize), sizeof(mDecompressedSize));
		mCompressedSize = mCompressedSize - 8;

		mAC.SetFile( mSource );

		mAC.DecodeStart();

		// decode
		Decode();
	}
};
