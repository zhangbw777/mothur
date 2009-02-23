#ifndef TREENODE_H
#define TREENODE_H

/*
 *  treenode.h
 *  Mothur
 *
 *  Created by Sarah Westcott on 1/23/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

using namespace std;

#include "mothur.h"

/* This class represents a node on a tree. */


class Node  {
	public:
		Node();  //pass it the sequence name
		~Node() {};
		
		void setName(string);
		void setGroup(string);  
		void setBranchLength(float);
		void setParent(int);
		void setChildren(int, int);		//leftchild, rightchild
		void setIndex(int);
		
		string getName();
		string getGroup();  
		float getBranchLength();
		int getParent();
		int getLChild();
		int getRChild();
		int getIndex();
		void printNode(ostream&);   //prints out the name and the branch length
		
		
		//pGroup is the parsimony group info.  i.e. for a leaf node it would contain 1 enter pGroup["groupname"] = 1;
		//but for a branch node it may contain several entries so if the nodes children are from different groups it
		//would have at least two entries pgroup["groupnameOfLeftChild"] = 1, pgroup["groupnameOfRightChild"] = 1.
		//pCount is the nodes descendant group infomation.  i.e. pCount["black"] = 20 would mean that 20 of the nodes 
		//descendant are from group black.

		map<string, int> pGroups; //leaf nodes will only have 1 group, but branch nodes may have multiple groups.
		map<string, int> pcount;	
			
	private:
		string			name;
		string			group;
		float			branchLength;
		int				parent;
		int				lchild;
		int				rchild;
		int				vectorIndex;
};		

#endif