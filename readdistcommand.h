#ifndef READDISTCOMMAND_H
#define READDISTCOMMAND_H
/*
 *  readdistcommand.h
 *  Mothur
 *
 *  Created by Sarah Westcott on 1/20/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "command.hpp"
#include "readmatrix.hpp"

/* The read.dist command is used to read a distance matrix file.  
The read.dist command parameter options are phylipfile, columnfile, namefile, cutoff and precision. 
The read.dist command should be in the following format: read.dist(phylipfile=yourDistFile, 
namefile=yourNameFile, cutoff=yourCutoff, precision=yourPrecision). The phylipfile or columnfile are required and if you use a columnfile the namefile is required.  
If you do not provide a cutoff value 10.00 is assumed. If you do not provide a precision value then 100 is assumed.  */

class NameAssignment;
class GlobalData;


class ReadDistCommand : public Command {
public:
	ReadDistCommand();
	~ReadDistCommand();
	int execute();
	
private:
	GlobalData* globaldata;
	double cutoff;
	int precision;
	ReadMatrix* read;
	string filename, format, method;
	NameAssignment* nameMap;
};

#endif