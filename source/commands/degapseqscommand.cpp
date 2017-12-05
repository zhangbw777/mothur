/*
 *  degapseqscommand.cpp
 *  Mothur
 *
 *  Created by westcott on 6/21/10.
 *  Copyright 2010 Schloss Lab. All rights reserved.
 *
 */

#include "degapseqscommand.h"


//**********************************************************************************************************************
vector<string> DegapSeqsCommand::setParameters(){	
	try {
		CommandParameter pfasta("fasta", "InputTypes", "", "", "none", "none", "none","fasta",false,true,true); parameters.push_back(pfasta);
		CommandParameter pseed("seed", "Number", "", "0", "", "", "","",false,false); parameters.push_back(pseed);
        CommandParameter pprocessors("processors", "Number", "", "1", "", "", "","",false,false,true); parameters.push_back(pprocessors);
        CommandParameter pinputdir("inputdir", "String", "", "", "", "", "","",false,false); parameters.push_back(pinputdir);
		CommandParameter poutputdir("outputdir", "String", "", "", "", "", "","",false,false); parameters.push_back(poutputdir);
		
		vector<string> myArray;
		for (int i = 0; i < parameters.size(); i++) {	myArray.push_back(parameters[i].name);		}
		return myArray;
	}
	catch(exception& e) {
		m->errorOut(e, "DegapSeqsCommand", "setParameters");
		exit(1);
	}
}
//**********************************************************************************************************************
string DegapSeqsCommand::getHelpString(){	
	try {
		string helpString = "";
		helpString += "The degap.seqs command reads a fastafile and removes all gap characters.\n";
		helpString += "The degap.seqs command parameter are fasta and processors.\n";
		helpString += "The fasta parameter allows you to enter the fasta file containing your sequences, and is required unless you have a valid current fasta file. \n";
		helpString += "You may enter multiple fasta files by separating their names with dashes. ie. fasta=abrecovery.fasta-amzon.fasta \n";
        helpString += "The processors parameter allows you to enter the number of processors you would like to use. \n";
		helpString += "The degap.seqs command should be in the following format: \n";
		helpString += "degap.seqs(fasta=yourFastaFile) \n";	
		helpString += "Example: degap.seqs(fasta=abrecovery.align) \n";
		helpString += "Note: No spaces between parameter labels (i.e. fasta), '=' and parameters (i.e.yourFastaFile).\n";	
		return helpString;
	}
	catch(exception& e) {
		m->errorOut(e, "DegapSeqsCommand", "getHelpString");
		exit(1);
	}
}
//**********************************************************************************************************************
string DegapSeqsCommand::getOutputPattern(string type) {
    try {
        string pattern = "";
        if (type == "fasta") {  pattern = "[filename],ng.fasta"; } 
        else { m->mothurOut("[ERROR]: No definition for type " + type + " output pattern.\n"); m->setControl_pressed(true);  }
        
        return pattern;
    }
    catch(exception& e) {
        m->errorOut(e, "DegapSeqsCommand", "getOutputPattern");
        exit(1);
    }
}
//**********************************************************************************************************************
DegapSeqsCommand::DegapSeqsCommand(){	
	try {
		abort = true; calledHelp = true; 
		setParameters();
		vector<string> tempOutNames;
		outputTypes["fasta"] = tempOutNames;
	}
	catch(exception& e) {
		m->errorOut(e, "DegapSeqsCommand", "DegapSeqsCommand");
		exit(1);
	}
}
//***************************************************************************************************************
DegapSeqsCommand::DegapSeqsCommand(string option)  {
	try {
		abort = false; calledHelp = false;   
		
		//allow user to run help
		if(option == "help") { help(); abort = true; calledHelp = true; }
		else if(option == "citation") { citation(); abort = true; calledHelp = true;}
		
		else {
			vector<string> myArray = setParameters();
			
			OptionParser parser(option);
			map<string,string> parameters = parser.getParameters();
			
			ValidParameters validParameter;
			map<string,string>::iterator it;
			
			//check to make sure all parameters are valid for command
			for (it = parameters.begin(); it != parameters.end(); it++) { 
				if (validParameter.isValidParameter(it->first, myArray, it->second) != true) {  abort = true;  }
			}
			
			
			//initialize outputTypes
			vector<string> tempOutNames;
			outputTypes["fasta"] = tempOutNames;
		
			//if the user changes the input directory command factory will send this info to us in the output parameter 
			string inputDir = validParameter.valid(parameters, "inputdir");		
			if (inputDir == "not found"){	inputDir = "";		}
			
			//check for required parameters
			fastafile = validParameter.valid(parameters, "fasta");
			if (fastafile == "not found") { 				
				fastafile = current->getFastaFile(); 
				if (fastafile != "") { fastaFileNames.push_back(fastafile); m->mothurOut("Using " + fastafile + " as input file for the fasta parameter."); m->mothurOutEndLine(); }
				else { 	m->mothurOut("You have no current fastafile and the fasta parameter is required."); m->mothurOutEndLine(); abort = true; }
			}
			else { 
				util.splitAtDash(fastafile, fastaFileNames);
				
				//go through files and make sure they are good, if not, then disregard them
				for (int i = 0; i < fastaFileNames.size(); i++) {
					
					bool ignore = false;
					if (fastaFileNames[i] == "current") { 
						fastaFileNames[i] = current->getFastaFile(); 
						if (fastaFileNames[i] != "") {  m->mothurOut("Using " + fastaFileNames[i] + " as input file for the fasta parameter where you had given current."); m->mothurOutEndLine(); }
						else { 	
							m->mothurOut("You have no current fastafile, ignoring current."); m->mothurOutEndLine(); ignore=true; 
							//erase from file list
							fastaFileNames.erase(fastaFileNames.begin()+i);
							i--;
						}
					}
					
                    if (!ignore) {
                        if (util.checkLocations(fastaFileNames[i], current->getLocations())) { current->setFastaFile(fastaFileNames[i]); }
                        else { fastaFileNames.erase(fastaFileNames.begin()+i); i--; } //erase from file list
                    }
                }
				
				//make sure there is at least one valid file left
				if (fastaFileNames.size() == 0) { m->mothurOut("no valid files."); m->mothurOutEndLine(); abort = true; }
			}
            
            string temp = validParameter.valid(parameters, "processors");	if (temp == "not found"){	temp = current->getProcessors();	}
            processors = current->setProcessors(temp);
			
			//if the user changes the output directory command factory will send this info to us in the output parameter 
			outputDir = validParameter.valid(parameters, "outputdir");		if (outputDir == "not found"){	
				outputDir = "";	
				outputDir += util.hasPath(fastafile); //if user entered a file with a path then preserve it	
			}

		}
	}
	catch(exception& e) {
		m->errorOut(e, "DegapSeqsCommand", "DegapSeqsCommand");
		exit(1);
	}
}
//***************************************************************************************************************
int DegapSeqsCommand::execute(){
	try{
		
		if (abort) { if (calledHelp) { return 0; }  return 2;	}
		
		for (int s = 0; s < fastaFileNames.size(); s++) {
				
			m->mothurOut("Degapping sequences from " + fastaFileNames[s] + " ..." ); m->mothurOutEndLine();
			
			string tempOutputDir = outputDir;
			if (outputDir == "") { tempOutputDir = util.hasPath(fastaFileNames[s]); }
            map<string, string> variables; 
            variables["[filename]"] = tempOutputDir + util.getRootName(util.getSimpleName(fastaFileNames[s]));
			string degapFile = getOutputFileName("fasta", variables);
            outputNames.push_back(degapFile); outputTypes["fasta"].push_back(degapFile);
            
            long start = time(NULL);
			
            int numSeqs = createProcesses(fastaFileNames[s], degapFile);
			
			m->mothurOut("It took " + toString(time(NULL) - start) + " secs to degap " + toString(numSeqs) + " sequences.\n\n");
            
			if (m->getControl_pressed()) {  for (int j = 0; j < outputNames.size(); j++) {	util.mothurRemove(outputNames[j]);	} return 0; }
		}
		
		//set fasta file as new current fastafile
		string currentName = "";
		itTypes = outputTypes.find("fasta");
		if (itTypes != outputTypes.end()) {
			if ((itTypes->second).size() != 0) { currentName = (itTypes->second)[0]; current->setFastaFile(currentName); }
		}
		
		m->mothurOutEndLine();
		m->mothurOut("Output File Names: "); m->mothurOutEndLine();
		for (int i = 0; i < outputNames.size(); i++) {	m->mothurOut(outputNames[i]); m->mothurOutEndLine();	}	
		m->mothurOutEndLine();

		
		return 0;
		
	}
	catch(exception& e) {
		m->errorOut(e, "DegapSeqsCommand", "execute");
		exit(1);
	}
}
/**************************************************************************************************/
//custom data structure for threads to use.
// This is passed by void pointer so it can be any data type
// that can be passed using a single void pointer (LPVOID).
struct degapData {
    string filename;
    string outputFileName;
    unsigned long long start;
    unsigned long long end;
    int count;
    MothurOut* m;
    Utils util;
    
    degapData(){}
    degapData(string f, string of, MothurOut* mout, unsigned long long st, unsigned long long en) {
        filename = f;
        outputFileName = of;
        m = mout;
        start = st;
        end = en;
        count = 0;
    }
};

//***************************************************************************************************************
void driverDegap(degapData* params){
    try{
        ifstream inFASTA;
        params->util.openInputFile(params->filename, inFASTA);
        
        inFASTA.seekg(params->start);
        
        if (params->start == 0) {  params->util.zapGremlins(inFASTA); params->util.gobble(inFASTA); }
        
        ofstream outFASTA;
        params->util.openOutputFile(params->outputFileName, outFASTA);
        
        while(!inFASTA.eof()){
            if (params->m->getControl_pressed()) {  break; }
            
            Sequence currSeq(inFASTA);  params->util.gobble(inFASTA);
            if (currSeq.getName() != "") {
                outFASTA << ">" << currSeq.getName() << endl;
                outFASTA << currSeq.getUnaligned() << endl;
                params->count++;
                params->m->mothurOutJustToScreen(toString(params->count) + "\n"); 
            }
            
#if defined NON_WINDOWS
            unsigned long long pos = inFASTA.tellg();
            if ((pos == -1) || (pos >= params->end)) { break; }
#else
            if (params->count == params->end) { break; }
#endif
            
            //report progress
            if((params->count) % 1000 == 0){	params->m->mothurOutJustToScreen(toString(params->count) + "\n"); 		}
            
        }
        //report progress
        if((params->count) % 1000 != 0){	params->m->mothurOutJustToScreen(toString(params->count) + "\n"); 		}
        
        inFASTA.close();
        outFASTA.close();
    }
    catch(exception& e) {
        params->m->errorOut(e, "DegapSeqsCommand", "driver");
        exit(1);
    }
}
//***************************************************************************************************************
int DegapSeqsCommand::createProcesses(string filename, string outputFileName){
    try{
        //create array of worker threads
        vector<thread*> workerThreads;
        vector<degapData*> data;
        vector<linePair> lines;
        
        long long num = 0;
        time_t start, end;
        time(&start);
        
        vector<unsigned long long> positions;
#if defined (__APPLE__) || (__MACH__) || (linux) || (__linux) || (__linux__) || (__unix__) || (__unix)
        positions = util.divideFile(filename, processors);
        for (int i = 0; i < (positions.size()-1); i++) {	lines.push_back(linePair(positions[i], positions[(i+1)]));	}
#else
        if (processors == 1) {
            lines.push_back(new linePair(0, -1)); //forces it to read whole file
        }else {
            positions = m->setFilePosFasta(filename, num);
            if (num < processors) { processors = num; }
            
            //figure out how many sequences you have to process
            int numSeqsPerProcessor = num / processors;
            for (int i = 0; i < processors; i++) {
                int startIndex =  i * numSeqsPerProcessor;
                if(i == (processors - 1)){	numSeqsPerProcessor = num - i * numSeqsPerProcessor; 	}
                lines.push_back(linePair(positions[startIndex], numSeqsPerProcessor));
            }
        }
#endif
        
        //Lauch worker threads
        for (int i = 0; i < processors-1; i++) {
            degapData* dataBundle = new degapData(filename, (outputFileName + toString(i+1) + ".temp"), m, lines[i+1].start, lines[i+1].end);
            data.push_back(dataBundle);
            
            workerThreads.push_back(new thread(driverDegap, dataBundle));
        }
        
        degapData* dataBundle = new degapData(filename, outputFileName, m, lines[0].start, lines[0].end);
        driverDegap(dataBundle);
        num = dataBundle->count;
        delete dataBundle;
        
        for (int i = 0; i < processors-1; i++) {
            workerThreads[i]->join();
            num += data[i]->count;
            
            util.appendFiles(data[i]->outputFileName, outputFileName);
            util.mothurRemove(data[i]->outputFileName);

            delete data[i];
            delete workerThreads[i];
        }
        
        time(&end);
        m->mothurOut("It took " + toString(difftime(end, start)) + " secs to classify " + toString(num) + " sequences.\n\n");
    
        return num;
    }
    catch(exception& e) {
        m->errorOut(e, "DegapSeqsCommand", "createProcesses");
        exit(1);
    }
}
//***************************************************************************************************************

