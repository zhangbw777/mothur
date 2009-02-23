/*
 *  tree.cpp
 *  Mothur
 *
 *  Created by Sarah Westcott on 1/22/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "tree.h"


/*****************************************************************/
Tree::Tree() {
	try {
	
		globaldata = GlobalData::getInstance();
		numLeaves = globaldata->gTreemap->getNumSeqs();
		numNodes = 2*numLeaves - 1;
		
		tree.resize(numNodes);

		//initialize tree with correct number of nodes, name and group info.
		for (int i = 0; i < numNodes; i++) {
			//initialize leaf nodes
			if (i <= (numLeaves-1)) {
				tree[i].setName(globaldata->gTreemap->namesOfSeqs[i]);
				tree[i].setGroup(globaldata->gTreemap->getGroup(globaldata->gTreemap->namesOfSeqs[i]));
				//the node knows its index
				tree[i].setIndex(i);
				//set pcount and pGroup for groupname to 1.
				tree[i].pcount[globaldata->gTreemap->getGroup(globaldata->gTreemap->namesOfSeqs[i])] = 1;
				tree[i].pGroups[globaldata->gTreemap->getGroup(globaldata->gTreemap->namesOfSeqs[i])] = 1;
				//Treemap knows name, group and index to speed up search
				globaldata->gTreemap->setIndex(globaldata->gTreemap->namesOfSeqs[i], i);
	
			//intialize non leaf nodes
			}else if (i > (numLeaves-1)) {
				tree[i].setName("");
				tree[i].setGroup("");
				//the node knows its index
				tree[i].setIndex(i);
			}
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function Tree. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function Tree. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}

/*****************************************************************/

int Tree::getIndex(string searchName) {
	try {
		//Treemap knows name, group and index to speed up search
		// getIndex function will return the vector index or -1 if seq is not found.
		int index = globaldata->gTreemap->getIndex(searchName);
		return index;
		
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function getIndex. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function getIndex. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}
/*****************************************************************/

void Tree::setIndex(string searchName, int index) {
	try {
		//set index in treemap
		globaldata->gTreemap->setIndex(searchName, index);
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function setIndex. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function setIndex. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}
/*****************************************************************/
void Tree::assembleTree() {
	try {
		//build the pGroups in non leaf nodes to be used in the parsimony calcs.
		for (int i = numLeaves; i < numNodes; i++) {
			tree[i].pGroups = (mergeGroups(i));
			tree[i].pcount = (mergeGcounts(i));
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function assembleTree. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function assembleTree. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}
/*****************************************************************/
void Tree::getCopy(Tree* copy) {
	try {
	
		//for each node in the tree copy its info
		for (int i = 0; i < numNodes; i++) {
			//copy name
			tree[i].setName(copy->tree[i].getName());
		
			//copy group
			tree[i].setGroup(copy->tree[i].getGroup());
			
			//copy branch length
			tree[i].setBranchLength(copy->tree[i].getBranchLength());
		
			//copy parent
			tree[i].setParent(copy->tree[i].getParent());
		
			//copy children
			tree[i].setChildren(copy->tree[i].getLChild(), copy->tree[i].getRChild());
		
			//copy index in node and tmap
			tree[i].setIndex(copy->tree[i].getIndex());
			setIndex(copy->tree[i].getName(), getIndex(copy->tree[i].getName()));
			
			//copy pGroups
			tree[i].pGroups = copy->tree[i].pGroups;
		
			//copy pcount
			tree[i].pcount = copy->tree[i].pcount;
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function getCopy. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function getCopy. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}
/*****************************************************************/
//returns a map with a groupname and the number of times that group was seen in the children
//for instance if your children are white and black then it would return a map with 2 entries
// p[white] = 1 and p[black] = 1.  Now go up a level and merge that with a node who has p[white] = 1
//and you get p[white] = 2, p[black] = 1, but you erase the p[black] because you have a p value higher than 1.

map<string, int> Tree::mergeGroups(int i) {
	try {
	
		int lc = tree[i].getLChild();
		int rc = tree[i].getRChild();
		
		//set parsimony groups to left child
		map<string,int> parsimony = tree[lc].pGroups;
		
		int maxPars = 1;

		//look at right child groups and update maxPars if right child has something higher for that group.
		for(it=tree[rc].pGroups.begin();it!=tree[rc].pGroups.end();it++){
			parsimony[it->first]++;
			
			if(parsimony[it->first] > maxPars){
				maxPars = parsimony[it->first];
			}
		}
	
		// this is true if right child had a greater parsimony for a certain group
		if(maxPars > 1){
			//erase all the groups that are only 1 because you found something with 2.
			for(it=parsimony.begin();it!=parsimony.end();it++){
				if(it->second == 1){
					parsimony.erase(it->first);
					it--;
				}
			}
			//set one remaining groups to 1
			//so with our above example p[white] = 2 would be left and it would become p[white] = 1
			for(it=parsimony.begin();it!=parsimony.end();it++){
				parsimony[it->first] = 1;
			}
		
		}
	
		return parsimony;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function mergeGroups. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function mergeGroups. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}

/**************************************************************************************************/

map<string,int> Tree::mergeGcounts(int position) {
	try{
		map<string,int>::iterator pos;
	
		int lc = tree[position].getLChild();
		int rc = tree[position].getRChild();
	
		map<string,int> sum = tree[lc].pcount;
    
		for(it=tree[rc].pcount.begin();it!=tree[rc].pcount.end();it++){
			sum[it->first] += it->second;
		}
		return sum;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function mergeGcounts. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function mergeGcounts. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}
/**************************************************************************************************/

void Tree::randomLabels() {
	try {
		
		//set up the groups the user wants to include
		setGroups();
		
		for(int i=numLeaves-1;i>=0;i--){
			if(tree[i].pGroups.size() == 0){
				continue;
			}
			
			int escape = 1;
			int z;
		
			while(escape == 1){
				//get random index to switch with
				z = int((float)(i+1) * (float)(rand()) / ((float)RAND_MAX+1.0));	
			
				if(tree[z].pGroups.size() != 0){
					escape = 0;
				}
			}
			
			//you only want to randomize the nodes that are from a group the user wants analyzed, so
			//if either of the leaf nodes you are about to switch are not in the users groups then you don't want to switch them.
			bool treez, treei;
			
			//leaves have only one group so you can just set it to begin()
			it = tree[z].pGroups.begin();
			treez = inUsersGroups(it->first, globaldata->Groups);
			
			it = tree[i].pGroups.begin();
			treei = inUsersGroups(it->first, globaldata->Groups);
			
			if ((treez == true) && (treei == true)) {
				//switches node i and node z's info.
				map<string,int> lib_hold = tree[z].pGroups;
				tree[z].pGroups = (tree[i].pGroups);
				tree[i].pGroups = (lib_hold);
		
				tree[z].setGroup(tree[z].pGroups.begin()->first);
				tree[i].setGroup(tree[i].pGroups.begin()->first);
		
				map<string,int> gcount_hold = tree[z].pcount;
				tree[z].pcount = (tree[i].pcount);
				tree[i].pcount = (gcount_hold);
			}
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function randomLabels. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function randomLabels. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}
/**************************************************************************************************/

void Tree::randomBlengths()  {
	try {
		for(int i=numNodes-1;i>=0;i--){
			int z = int((float)(i+1) * (float)(rand()) / ((float)RAND_MAX+1.0));	
		
			float bl_hold = tree[z].getBranchLength();
			tree[z].setBranchLength(tree[i].getBranchLength());
			tree[i].setBranchLength(bl_hold);
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function randomBlengths. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function randomBlengths. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}
/*************************************************************************************************/
void Tree::assembleRandomUnifracTree() {
	randomLabels();
	assembleTree();
}

/*************************************************************************************************/
//for now it's just random topology but may become random labels as well later that why this is such a simple function now...
void Tree::assembleRandomTree() {
	randomTopology();
	assembleTree();
}
/**************************************************************************************************/

void Tree::randomTopology() {
	try {
		for(int i=0;i<numNodes;i++){
			tree[i].setParent(-1);
		}
		for(int i=numLeaves;i<numNodes;i++){
			tree[i].setChildren(-1, -1); 
		}
    
		for(int i=numLeaves;i<numNodes;i++){
			int escape =0;
			int rnd_index1, rnd_index2;
			while(escape == 0){
				rnd_index1 = (int)(((double)rand() / (double) RAND_MAX)*i);
				if(tree[rnd_index1].getParent() == -1){escape = 1;}
			}
		
			escape = 0;
			while(escape == 0){
				rnd_index2 = (int)(((double)rand() / (double) RAND_MAX)*i);
				if(rnd_index2 != rnd_index1 && tree[rnd_index2].getParent() == -1){
					escape = 1;
				}		
			}
		
			tree[i].setChildren(rnd_index1,rnd_index2);
			tree[i].setParent(-1);
			tree[rnd_index1].setParent(i);
			tree[rnd_index2].setParent(i);
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function randomTopology. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function randomTopology. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}

/*****************************************************************/
// This prints out the tree in Newick form.
void Tree::createNewickFile() {
	try {
		int root = findRoot();
		filename = getRootName(globaldata->getTreeFile()) + "newick";
		openOutputFile(filename, out);
		
		printBranch(root);
		
		// you are at the end of the tree
		out << ";" << endl;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function createNewickFile. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function createNewickFile. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}

/*****************************************************************/
//This function finds the index of the root node.

int Tree::findRoot() {
	try {
		for (int i = 0; i < numNodes; i++) {
			//you found the root
			if (tree[i].getParent() == -1) { return i; }
		}
		return -1;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function findRoot. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function findRoot. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}

/*****************************************************************/
void Tree::printBranch(int node) {
	try {
		
		// you are not a leaf
		if (tree[node].getLChild() != -1) {
			out << "(";
			printBranch(tree[node].getLChild());
			out << ",";
			printBranch(tree[node].getRChild());
			out << ")";
		}else { //you are a leaf
			tree[node].printNode(out);  //prints out name and branch length
		}
		
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function printBranch. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function printBranch. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		
}

/*****************************************************************/
void Tree::setGroups() {
	try {
		//if the user has not entered specific groups to analyze then do them all
		if (globaldata->Groups.size() != 0) {
			//check that groups are valid
			for (int i = 0; i < globaldata->Groups.size(); i++) {
				if (globaldata->gTreemap->isValidGroup(globaldata->Groups[i]) != true) {
					cout << globaldata->Groups[i] << " is not a valid group, and will be disregarded." << endl;
					// erase the invalid group from globaldata->Groups
					globaldata->Groups.erase (globaldata->Groups.begin()+i);
				}
			}
			
			//if the user only entered invalid groups
			if (globaldata->Groups.size() == 0) { 
				cout << "When using the groups parameter you must have at least 1 valid group. I will run the command using all the groups in your groupfile." << endl; 
				for (int i = 0; i < globaldata->gTreemap->namesOfGroups.size(); i++) {
					globaldata->Groups.push_back(globaldata->gTreemap->namesOfGroups[i]);
				}
			}
					
		}else {
			for (int i = 0; i < globaldata->gTreemap->namesOfGroups.size(); i++) {
				globaldata->Groups.push_back(globaldata->gTreemap->namesOfGroups[i]);
			}
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Tree class Function setGroups. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Tree class function setGroups. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}		

}
