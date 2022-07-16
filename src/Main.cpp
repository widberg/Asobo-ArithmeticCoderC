#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ModelOrder1C.h"

int main(int argc, char *argv[])
{
	cout << "Arithmetic Coding" << endl;

	if( argc != 4 )
	{
		cout << "Syntax: AC source target" << endl;
		return 1;
	}

	fstream source, target;
	ModelI* model;

	// choose model, here just order-0
	model = new ModelOrder1C;

	std::string mode(argv[1]);

	source.open( argv[2], ios::in | ios::binary );
	target.open( argv[3], ios::out | ios::binary );

	if( !source.is_open() )
	{
		cout << "Cannot open input stream";
		return 2;
	}
	if( !target.is_open() )
	{
		cout << "Cannot open output stream";
		return 3;
	}

	if(mode == "d")
	{
		cout << "Decoding " << argv[2] << " to " << argv[3] << endl;
		model->Process( &source, &target, MODE_DECODE );
	}
	else
	{
		cout << "Encoding " << argv[2] << " to " << argv[3] << endl;
		model->Process( &source, &target, MODE_ENCODE );
	}

	source.close();
	target.close();

	return 0;
}
