/*
 *  taxonomyequalizer.cpp
 *  Mothur
 *
 *  Created by westcott on 11/20/09.
 *  Copyright 2009 Schloss Lab. All rights reserved.
 *
 */

#include "taxonomyequalizer.h"

/**************************************************************************************************/
TaxEqualizer::TaxEqualizer(string tfile, int c, string o) : cutoff(c), outputDir(o) {
	try {
		m = MothurOut::getInstance();
		containsConfidence = false;
		
		ifstream inTax;
		util.openInputFile(tfile, inTax);
	
		highestLevel = getHighestLevel(inTax);
		
		if (!m->getControl_pressed()) { 
			
			//if the user has specified a cutoff and it's smaller than the highest level
			if ((cutoff != -1) && (cutoff < highestLevel)) { 
				highestLevel = cutoff;
			}else if (cutoff > highestLevel) {
				m->mothurOut("The highest level taxonomy you have is " + toString(highestLevel) + " and your cutoff is " + toString(cutoff) + ". I will set the cutoff to " + toString(highestLevel));
				m->mothurOutEndLine();
			}
			
			inTax.close(); 
			ifstream in; 
			util.openInputFile(tfile, in);
			
			ofstream out;
			equalizedFile = outputDir + util.getRootName(util.getSimpleName(tfile)) + "equalized.taxonomy";
			util.openOutputFile(equalizedFile, out);
			
	
			string name, tax;
			while (in) {
			
				if (m->getControl_pressed()) {  break; }
				
                in >> name;   util.gobble(in);
                tax = util.getline(in); util.gobble(in);
				
				if (containsConfidence) {  util.removeConfidences(tax);	}
				
				//is this a taxonomy that needs to be extended?
				if (seqLevels[name] < highestLevel) {
					extendTaxonomy(name, tax, highestLevel);
				}else if (seqLevels[name] > highestLevel) { //this can happen if the user enters a cutoff
					truncateTaxonomy(name, tax, highestLevel);
				}
				
				out << name << '\t' << tax << endl;
			}
			
			in.close();
			out.close();
			
			if (m->getControl_pressed()) { util.mothurRemove(equalizedFile);  }
		}else { inTax.close(); }
		
	}
	catch(exception& e) {
		m->errorOut(e, "TaxEqualizer", "TaxEqualizer");
		exit(1);
	}
}
/**************************************************************************************************/
int TaxEqualizer::getHighestLevel(ifstream& in) {
	try {
		
		int level = 0;
		string name, tax;
		
		while (in) {
            in >> name;   util.gobble(in);
            tax = util.getline(in); util.gobble(in);
		
			//count levels in this taxonomy
			int thisLevel = 0;
			for (int i = 0; i < tax.length(); i++) {
				if (tax[i] == ';') {  thisLevel++;	}
			}
		
			//save sequences level
			seqLevels[name] = thisLevel;
	
			//is this the longest taxonomy?
			if (thisLevel > level) {  
				level = thisLevel;  
				testTax = tax; //testTax is used to figure out if this file has confidences we need to strip out
			} 
		}
		
        int openParen = testTax.find_last_of('(');
        int closeParen = testTax.find_last_of(')');
        
        if ((openParen != string::npos) && (closeParen != string::npos)) {
            string confidenceScore = testTax.substr(openParen+1, (closeParen-(openParen+1)));
            if (util.isNumeric1(confidenceScore)) {  //its a confidence
                containsConfidence = true;
            }else { //its part of the taxon
                containsConfidence = false;
            }
        }
	
		return level;
					
	}
	catch(exception& e) {
		m->errorOut(e, "TaxEqualizer", "getHighestLevel");
		exit(1);
	}
}
/**************************************************************************************************/
void TaxEqualizer::extendTaxonomy(string name, string& tax, int desiredLevel) {
	try {
			
		//get last taxon
		//tax = tax.substr(0, tax.length()-1);  //take off final ";"
		//int pos = tax.find_last_of(';');
		//string lastTaxon = tax.substr(pos+1);
		//lastTaxon += ";"; //add back on delimiting char
		//tax += ";";
		
		//int currentLevel = seqLevels[name];
        
        tax = util.addUnclassifieds(tax, desiredLevel, containsConfidence);
		
		//added last taxon until you get desired level
		//for (int i = currentLevel; i < desiredLevel; i++) {
			//tax += lastTaxon;
		//}
	}
	catch(exception& e) {
		m->errorOut(e, "TaxEqualizer", "extendTaxonomy");
		exit(1);
	}
}
/**************************************************************************************************/
void TaxEqualizer::truncateTaxonomy(string name, string& tax, int desiredLevel) {
	try {
			
		int currentLevel = seqLevels[name];
		tax = tax.substr(0, tax.length()-1);  //take off final ";"
		
		//remove a taxon until you get to desired level
		for (int i = currentLevel; i > desiredLevel; i--) {
			tax = tax.substr(0,  tax.find_last_of(';'));
		}
		
		tax += ";";
	}
	catch(exception& e) {
		m->errorOut(e, "TaxEqualizer", "truncateTaxonomy");
		exit(1);
	}
}
/**************************************************************************************************/

