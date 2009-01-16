/*
 *  calculator.cpp
 *  Dotur
 *
 *  Created by Sarah Westcott on 11/18/08.
 *  Copyright 2008 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "calculator.h"

/***********************************************************************/
void VecCalc::printElements(vector<double> vec){
	try {
		for(int i = 0; i < vec.size(); i++)
			cout << vec.at(i) << " ";
		cout << "\n\n";
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function printElements. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function printElements. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}

/***********************************************************************/

void VecCalc::printElements(vector<string> vec){
	try {
		for(int i = 0; i < vec.size(); i++)
			cout << vec.at(i) << " ";
		cout << "\n\n";
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function printElements. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function printElements. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
int VecCalc::findString(vector<string> vec, string str){
	try {
		for(int i = 0; i < vec.size(); i++)
			if(str.compare(vec.at(i)) == 0)
				return i;
		return -1;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function findString. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function findString. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double VecCalc::mean(vector<double> vec){
	return sumElements(vec)/vec.size();
}
/***********************************************************************/
double VecCalc::stError(vector<double> vec){
	try {
		double sum = 0;
		double m = mean(vec);
		for(int i = 0; i < vec.size(); i++)
			sum += pow(vec.at(i)-m,2);
		return pow(sum/(vec.size()*(vec.size()-1)), .5);
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function stError. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function stError. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double VecCalc::sumElements(vector<double> vec){
	try {
		double sum = 0;
		for(int i = 0; i < vec.size(); i++)
			sum += vec.at(i);
		return sum;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function sumElements. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function sumElements. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double VecCalc::sumElements(vector<double> vec, int index){
	try {
		double sum = 0;
		for(int i = index; i < vec.size(); i++)
			sum += vec.at(i);
		return sum;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function sumElements. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function sumElements. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double VecCalc::findMax(vector<double> vec){
	try {
		double max = -1000000.0;
		for(int i = 0; i < vec.size(); i++)
			if(vec.at(i) > max)
				max = vec.at(i);
		return max;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function findMax. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function findMax. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double VecCalc::numNZ(vector<double> vec){
	try {
		double numNZ = 0;
		for(int i = 0; i < vec.size(); i++)
			if(vec.at(i) != 0)
				numNZ++;
		return numNZ;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function numNZ. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function numNZ. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double VecCalc::numPos(vector<double> vec){
	try {
		double numPos = 0;
		for(int i = 0 ; i < vec.size(); i++)
			if(vec.at(i) > 0)
				numPos++;
		return numPos;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function numPos. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function numPos. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double VecCalc::findMaxDiff(vector<double> vec1, vector<double> vec2){
	try {
		double maxDiff = -10000000000.0;
		for(int i = 0; i < vec1.size(); i++)
			if(fabs(vec1.at(i)-vec2.at(i)) > maxDiff)
				maxDiff = fabs(vec1.at(i)-vec2.at(i));
		return maxDiff;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function findMaxDiff. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function findMaxDiff. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double VecCalc::findDStat(vector<double> vec1, vector<double> vec2, double num){
	try {
		double mDiff = findMaxDiff(vec1, vec2);
		return (mDiff+.5)/num;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function findDStat. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function findDStat. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<int> VecCalc::findQuartiles(vector<double> vec){
	try {
		vector<int> quartiles;
		double max = vec.at(vec.size()-1);
		double r1 = max/4;
		double r2 = max*3/4;
		bool r1found = false;
		bool r2found = false;
		for(int i = 0; i < vec.size(); i++)
		{
			if(vec.at(i) > r1 && !r1found)
			{
				quartiles.push_back(i);
				r1found = true;
			}
			if(vec.at(i) > r2 && !r2found)
			{
				quartiles.push_back(i);
				i = vec.size();
			}
		}
		return quartiles;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function findQuartiles. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function findQuartiles. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::add(vector<double> vec, double x){
	try {
		vector<double> newVec;
		for(int i = 0; i < vec.size(); i++)
			newVec.push_back(vec.at(i)+x);
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function add. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function add. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::multiply(vector<double> vec, double x){
	try {
		vector<double> newVec;
		for(int i = 0; i < vec.size(); i++)
			newVec.push_back(vec.at(i)*x);
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function multiply. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function multiply. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::power(vector<double> vec, double p){
	try {
		vector<double> newVec;
		for(int i = 0; i < vec.size(); i++)
			newVec.push_back(pow(vec.at(i), p));
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function power. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function power. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::addVecs(vector<double> vec1, vector<double> vec2) //Vectors must be the same size.
{	try {
		vector<double> newVec;
		for(int i = 0; i < vec1.size(); i++)
			newVec.push_back(vec1.at(i)+vec2.at(i));
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function addVecs. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function addVecs. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::multVecs(vector<double> vec1, vector<double> vec2) //Vectors must be the same size.
{	try {
		vector<double> newVec;
		for(int i = 0; i < vec1.size(); i++)
			newVec.push_back(vec1.at(i)*vec2.at(i));
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function multVecs. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function multVecs. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::remDup(vector<double> vec){
	try {
		vector<double> newVec;
		newVec.push_back(vec.at(0));
		for(int i = 1; i < vec.size(); i++)
			if(vec.at(i) != vec.at(i-1))
				newVec.push_back(vec.at(i));
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function remDup. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function remDup. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}	
/***********************************************************************/	
vector<double> VecCalc::genCVec(vector<double> vec1){
	try {
		vector<double> vec2;
		double sum = 0;
		for(int i = 0; i < vec1.size(); i++)
		{
			sum += vec1.at(i);
			vec2.push_back(sum);
		}
		return vec2;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function genCVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function genCVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::genRelVec(vector<double> vec){	
	try {
		vector<double> newVec;
		double sum = sumElements(vec);
		for(int i = 0; i < vec.size(); i++)
			newVec.push_back(vec.at(i)/sum);
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function genRelVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function genRelVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::genDiffVec(vector<double> vec1, vector<double> vec2){
	try {
		vector<double> newVec;
		for(int i = 0; i < vec1.size(); i++)
			newVec.push_back(vec1.at(i)-vec2.at(i));
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function genDiffVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function genDiffVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::genCSVec(vector<double> vec){
	try {
		vector<double> newVec;
		double curInd = vec.at(vec.size()-1);
		double sumSpec = 0;
		double cSumSpec = 0;
		for(int i = vec.size()-1; i >= 0; i--)
		{
			if(vec.at(i) == curInd)
				sumSpec++;
			else
			{
				cSumSpec += sumSpec;
				newVec.push_back(cSumSpec);
				sumSpec = 1;
				curInd = vec.at(i);
			}
			if(i == 0)
				newVec.push_back(cSumSpec + sumSpec);
		}
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function genCSVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function genCSVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/	
vector<double> VecCalc::genTotVec(vector<vector<double> > vec){
	try {
		vector<double> newVec = vec.at(0);
		for(int i = 1; i < vec.size(); i++)
			newVec = addVecs(newVec, vec.at(i));
		return newVec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function genTotVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function genTotVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<double> VecCalc::quicksort(vector<double> vec){
	try {
		sort(vec.rbegin(), vec.rend());
		return vec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function quicksort. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function quicksort. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<vector<double> > VecCalc::gen2DVec(vector<double> vec, int div, int type){
	try {
		vector<vector<double> > vec2D;
		int gap = vec.size()/div;
		for(int i = 0; i < div; i++)
		{
			vector<double> inVec;
			for(int j = 0; j < gap; j++)
				if(type == 0)
					inVec.push_back(vec.at(j + i*gap)); //Rows
				else
					inVec.push_back(vec.at(i + j*div)); //Columns
			vec2D.push_back(inVec);
		}
		return vec2D;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function gen2DVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function gen2DVec. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
vector<string> VecCalc::getSData(char name[]){
	try {
		vector<string> vec;
		string data;
		ifstream file(name);
		if(file.is_open())
		{
			while(file >> data)		
				vec.push_back(data);
			file.close();
		}
		return vec;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the VecCalc class Function getSData. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the VecCalc class function getSData. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/	
double BDiversity::getWhitt(vector<double> vec1, vector<double> vec2){
	try {
		VecCalc vecCalc;
		double numSpec = vecCalc.numNZ(vecCalc.addVecs(vec1,vec2));
		return 2*numSpec/(vecCalc.numNZ(vec1)+vecCalc.numNZ(vec2))-1;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the BDiversity class Function getWhitt. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the BDiversity class function getWhitt. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double BDiversity::getMS(vector<double> vec1, vector<double> vec2){
	try {
		VecCalc vecCalc;
		double a = vecCalc.numNZ(vecCalc.multVecs(vec1, vec2));
		double b = vecCalc.numPos(vecCalc.addVecs(vecCalc.addVecs(vec1, vecCalc.multiply(vec2, -1)), vecCalc.multiply(vecCalc.multVecs(vec1, vec2), -1)));
		double c = vecCalc.numPos(vecCalc.addVecs(vecCalc.addVecs(vec2, vecCalc.multiply(vec1, -1)), vecCalc.multiply(vecCalc.multVecs(vec2, vec1), -1)));
		return a/(a+b+c);
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the BDiversity class Function getMS. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the BDiversity class function getMS. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double BDiversity::getSor(vector<double> vec1, vector<double> vec2){
	try {
		double sum = 0;
		double asum = 0;
		double bsum = 0;
		for(int i = 0; i < vec1.size(); i++)
		{
			asum += vec1.at(i);
			bsum += vec2.at(i);
			if(vec1.at(i) >= vec2.at(i))
				sum += vec2.at(i);
			else
				sum += vec1.at(i);
		}
		return 2*sum/(asum+bsum);
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the BDiversity class Function getSor. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the BDiversity class function getSor. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double BDiversity::getMor(vector<double> vec1, vector<double> vec2){
	try {
		double sum = 0;
		double asum = 0;
		double bsum = 0;
		double sum1 = 0;
		double sum2 = 0;
		for(int i = 0; i < vec1.size(); i++)
		{
			sum += vec1.at(i)*vec2.at(i);
			asum += pow(vec1.at(i),2);
			bsum += pow(vec2.at(i),2);
			sum1 += vec1.at(i);
			sum2 += vec2.at(i);
		}
		return 2*sum/((asum/pow(sum1,2)+bsum/pow(sum2,2))*(sum1*sum2));
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the BDiversity class Function getMor. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the BDiversity class function getMor. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
void BDiversity::printD(vector<vector<double> > columns, int type){
	try {
		cout << "         ";
		for(int i = 0; i < columns.size(); i++)
			cout << "Column:" << i << "    ";
		cout << "\n";
		for(int i = 0; i < columns.size(); i++)
		{
			cout << "Column " << i << ":";
			for(int j = 0; j < columns.size(); j++)
			{
				if(j > i)
				{
					double B;
					if(type == 1)
						B = getWhitt(columns.at(i), columns.at(j));
					else if(type == 2)
						B = 1-getMS(columns.at(i), columns.at(j));
					else if(type == 3)
						B = 1-getSor(columns.at(i), columns.at(j));
					else if(type == 4)
						B = 1-getMor(columns.at(i), columns.at(j));

					cout << B << "    ";
				}
				else
					cout << "            ";
			}	
			cout << "\n";
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the BDiversity class Function printD. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the BDiversity class function printD. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
void BDiversity::doBD(vector<double> vec, double cols)//vec = The data vector if the data table was read left-to-right, top-to-bottom. cols = the number of columns in the data table.
{	try {
		VecCalc vecCalc;
		vector<vector<double> > columns = vecCalc.gen2DVec(vec,cols,1);
	
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(6);//This formats the data so the tables look pretty.
	
		//Whittaker's measure Bw (presence/absence data)
		cout << "Whittaker's measure Bw (presence/absence data):\n";
		printD(columns, 1);
		double sum = 0;
		for(int i = 0; i < cols; i++)
			sum += vecCalc.numNZ(columns.at(i));
		double meanRichness = sum/cols;
		vector<double> totVec = vecCalc.genTotVec(columns);
		double totRichness = vecCalc.numNZ(totVec);
		cout << "\nOverall B Diversity = " << totRichness/meanRichness << "\n\n\n";//The overall B Diversity
	
		//Marczewski-Steinhaus(MS) distance(Jaccard index) (presence/abscence data)
		cout << "Marczewski-Steinhaus(MS) distance(Jaccard index) (presence/abscence data):\n";
		printD(columns, 2);
		sum = 0;
		for(int i = 0; i < cols; i++)
			for(int j = 0; j < cols; j++)
				if(j > i)
					sum += vecCalc.numNZ(columns.at(i))+vecCalc.numNZ(columns.at(j)) - 2*vecCalc.numNZ(vecCalc.multVecs(columns.at(i), columns.at(j)));
		cout << "\nOverall B Diversity = " << sum/cols << "\n\n\n";//The overall B Diversity
	
		//Sorensen quantitative index (abundance data)
		cout << "Sorensen quantitative index (abundance data):\n";
		printD(columns, 3);
		cout << "\n\n";
	
		//Sorensen quantitative index (abundance data)
		cout << "Morisita-Horn index (abundance data):\n";
		printD(columns,4);
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the BDiversity class Function doBD. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the BDiversity class function doBD. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}

/***********************************************************************/
void BrokenStick::doBStick(vector<double> vec)//vec = The data vector.
{	try {
		VecCalc vecCalc;
		vec = vecCalc.quicksort(vec);
		double numInd = vecCalc.sumElements(vec);
		double numSpec = vecCalc.numNZ(vec);
		vector<double> cObsVec = vecCalc.genCVec(vec);
		vector<double> cExpVec;
		vec = vecCalc.power(vec, -1);
		double sumExp = 0;
		for(int i = 0; i < numSpec; i++)
		{
			double n = 0;
			for(int j = i; j < numSpec; j++)
				n += 1/(double)(j+1);
	
			sumExp += numInd/numSpec*n;
			cExpVec.push_back(sumExp);
		}
	
		//Statistical analysis
		double maxDiff = vecCalc.findMaxDiff(cObsVec, cExpVec);
		double DStatistic = maxDiff/numInd;
	
		cout << "D-Statistic = " << DStatistic << "\n";
		if(vec.size() > 30)
			cout << "Critical value for 95% confidence interval = " << .886/sqrt(vec.size()) << "\n";
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the BrokenStick class Function doBStick. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the BrokenStick class function doBStick. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}

/***********************************************************************/
double kEq(double k, double spec)
{
	return k/(1-k)*pow(1-k, spec)/(1-pow(1-k, spec));
}
/***********************************************************************/
void GeometricSeries::doGeomTest(vector<double> vec)//vec = the data vector
{	try {
		VecCalc vecCalc;
		vec = vecCalc.quicksort(vec);//Sorts vec
		double numInd = vecCalc.sumElements(vec);//numInd = The total number of individuals in the data set.
		double numSpec = vecCalc.numNZ(vec);//numSpec = the number of nonzero elements in the data set.
		double min = -1.0*vecCalc.findMax(vecCalc.multiply(vec, -1));
		double k = .5;
		double step = .49999;
		while(fabs(min - numInd*kEq(k, numSpec)) > .0001)//This uses a binary search to find the value of k.
		{
			if(numInd*kEq(k, numSpec) > min)
				k += step;
			else
				k -= step;
			step /= 2;
		}
		cout << "k = " << k << "\n";
		double cK = 1/(1-pow(1-k, numSpec));
	
		vector<double> cObsVec = vecCalc.genCVec(vec);
		vector<double> cExpVec;
		double sumExp = 0;
		for(int i = 0; i < vec.size(); i++)
		{
			sumExp += numInd*cK*k*pow(1-k, i);
			cExpVec.push_back(sumExp);
		}
		double maxDiff = vecCalc.findMaxDiff(cObsVec, cExpVec);
		double DStatistic = maxDiff/numInd;
	
		//Statistical Analysis
		cout << "D-Statistic = " << DStatistic << "\n";
		if(vec.size() > 30)
			cout << "Critical value for 95% confidence interval = " << .886/sqrt(vec.size()) << "\n";
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the GeometricSeries class Function doGeomTest. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the GeometricSeries class function doGeomTest. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}

/***********************************************************************/
void Jackknifing::doJK(vector<double> vec, double cols)//vec = the data vector if the data table was read left-to-right, top-to-bottom. cols = The number of columns in the data table.
{	try {
		VecCalc vecCalc;
		SSBPDiversityIndices ssbp;
		double rows = vec.size()/cols;
		vector<vector<double> > species = vecCalc.gen2DVec(vec, rows, 0);//converts vec into a 2 dimensional vector
		vector<double> sumRows;
		vector<double> pVals;

		for(int i = 0; i < rows; i++)
			sumRows.push_back(vecCalc.sumElements(species.at(i)));
		double st = 1/ssbp.getSimp(sumRows);//The observed estimate using the Simpson Index. Can be changed to use other indexes of diversity.
		for(int i = 0; i < cols; i++)
		{
			vector<double> newVec;
			for(int j = 0; j < rows; j++)
				newVec.push_back(vecCalc.sumElements(species.at(j))-species.at(j).at(i));
			pVals.push_back(cols*st-((cols-1)/ssbp.getSimp(newVec)));
		}

		double mean = vecCalc.mean(pVals);
		double stErr = vecCalc.stError(pVals);//stErr = standard error
		TDTable table;
		double confidence = .95;
		double confLimit;
		cout << "Confidence Level (.8, .9, .95, .98, .99, .998, .999): ";
		cin >> confidence;
		double confLevels[] = {.80,.90,.95,.98,.99,.998,.999};
		for(int i = 0; i < 7; i++)
			if(confidence == confLevels[i])
			{
				confLimit = table.getConfLimit(cols-2,i);
				i = 7;
			}

		//Statistical Analysis
		cout << "Lower limit = " << mean - confLimit*stErr << "\n";
		cout <<	"Upper limit = " << mean + confLimit*stErr << "\n";
		cout << "Observed estimate = " << st << "\n\n";
		cout << "Jackknifed estimate = " << mean << "\n";
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the Jackknifing class Function doJK. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the Jackknifing class function doJK. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
void KS2SampleTest::doKSTest(vector<double> abun1, vector<double> abun2)//abun1 = 1st vector of abundances, abun2 = 2nd vector of abundances
{	try {
		VecCalc vecCalc;
		double numNZ1 = vecCalc.numNZ(abun1);//Number of nonzero elements in abun1
		double numNZ2 = vecCalc.numNZ(abun2);//Number of nonzero elements in abun2
		abun1 = vecCalc.quicksort(abun1);//Sorts abun1
		abun2 = vecCalc.quicksort(abun2);//Sorts abun2
		abun1 = vecCalc.genRelVec(abun1);//Generates the relative vector for abun1
		abun2 = vecCalc.genRelVec(abun2);//Generates the relative vector for abun2
	
		abun1 = vecCalc.genCVec(abun1);//Generates the cumulative vector for abun1
		abun2 = vecCalc.genCVec(abun2);//Generates the cumulative vector for abun2
	
		double maxDiff = vecCalc.findMaxDiff(abun1, abun2);
		double DStatistic = maxDiff*numNZ1*numNZ2;
	
		cout << "Null Hypothesis = There is no difference.\n";
		cout << "D-Statistic = " << DStatistic << "\n";
	
		double a = pow((numNZ1 + numNZ2)/(numNZ1*numNZ2),.5);
		double pVal = exp(-2*pow(maxDiff/a,2));
	
		if(numNZ1 > 25 && numNZ2 > 25) //If the sample sizes are both bigger than 25.
			cout << "P-Value = " << pVal << "\n\n";
		else
		{	
			cout << "D-Statistic must be higher than the critical value to reject the null hypothesis.\n" ;
			cout << "90% Confidence Critical Value = " << 1.22*a*numNZ1*numNZ2 << "\n";
			cout << "95% Confidence Critical Value = " << 1.36*a*numNZ1*numNZ2 << "\n";
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the KS2SampleTest class Function doKSTest. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the KS2SampleTest class function doKSTest. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}

/***********************************************************************/
double logS(double num)
{
	return -(1-num)*log(1-num)/num;
}

/***********************************************************************/
void LogSD::doLogSD(vector<double> indVec, vector<double> specVec) //indVec = individuals vector, specVec = species vector
{	try {
		VecCalc vecCalc;
		double numSpec = vecCalc.sumElements(specVec);//numSpec = The total number of species
		cout << "number of species = " << numSpec << "\n";
		double numInd = vecCalc.sumElements(vecCalc.multVecs(indVec, specVec));
		double snRatio = numSpec/numInd;
		double x = .5;
		double step = .4999999999;
		while(fabs(snRatio - logS(x)) > .00001) //This uses a binary search to find the value of x.
		{
			if(logS(x) > snRatio)
				x += step;
			else
				x -= step;
			step /= 2;
		}
		double alpha = numInd*(1-x)/x;
	
		int ind;
		cout << "Number of individuals:"; //Ask the user for the number of individuals.
		cin >> ind;
		double spec = alpha*pow(x, ind)/ind;
		cout << "Number of species expected = " << spec << "\n" << "X value = " << x << "\n" << "Alpha value= " << alpha << "\n";//Outputs the number of species expected with the given number of individuals.
	
		vector<double> obsSpec;
		vector<double> cObsSpec;
		vector<double> expSpec;
		vector<double> cExpSpec;
		vector<double> cDiff;
	
		// Generates the cumulative observed species vector.
		int oct = 1;
		double octSumObs = 0;
		for(int y = 0; y < specVec.size(); y++)
		{
			if(indVec.at(y) - .5 < pow(2.0, oct))
				octSumObs += specVec.at(y);
			else
			{
				obsSpec.push_back(octSumObs);
				octSumObs = specVec.at(y);
				oct++;
			}
			if(y == specVec.size()-1)
				obsSpec.push_back(octSumObs);
		}
		cObsSpec = vecCalc.genCVec(obsSpec);
		cObsSpec = vecCalc.add(cObsSpec,-.5);
	
		// Generates the cumulative expected species vector.
		oct = 1;
		double octSumExp = 0;
		for(int g = 1; g <= indVec.at(indVec.size()-1); g++)
		{
			if(g - .5 < pow(2.0, oct))
				octSumExp += alpha*pow(x,g)/(g);
			else
			{
				expSpec.push_back(octSumExp);
				octSumExp = alpha*pow(x,g)/(g);
				oct++;
			}
			if(g == indVec.at(indVec.size()-1))
				expSpec.push_back(octSumExp);
		}
		cExpSpec = vecCalc.genCVec(expSpec);
	
		// Statistical Analysis
		double dTStat = vecCalc.findDStat(cObsSpec, cExpSpec, numSpec);
		cout << "D Test Statistic = " << dTStat << "\n";
		cout << ".05 confidence value = " << .89196/sqrt(numSpec) << "\n";
		cout << ".01 confidence value = " << 1.0471/sqrt(numSpec) << "\n\n";
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the LogSD class Function doLogSD. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the LogSD class function doLogSD. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
void QStatistic::doQStat(vector<double> vec)//vec = The data vector.
{	try {
		VecCalc vecCalc;
		vector<double> cVec = vecCalc.genCSVec(vec);
		vector<int> q = vecCalc.findQuartiles(cVec);//q.at(0) is the index of the first quartile; q.at(1) is the index of the second quartile.
		vector<double> nDupVec = vecCalc.remDup(vec);//nDupVec only contains one of every unique element in cVec.
		double Q;
		if(q.at(0) != 0)//The case if neither quartile is 0 or 1
			Q = (.5*(cVec.at(q.at(0))-cVec.at(q.at(0)-1)) + (cVec.at(q.at(1)-1)-cVec.at(q.at(0))) + .5*(cVec.at(q.at(1))-cVec.at(q.at(1)-1)))/log(nDupVec.at(nDupVec.size()-1-q.at(1))/nDupVec.at(nDupVec.size()-1-q.at(0)));
		else if(q.at(0) == 0 && (q.at(1) == 0 || q.at(1) == 1))//The case if the quartiles are both at index 0 or one is at 0 and the other at 1.
			Q = (.5*cVec.at(0) + .5*(cVec.at(1)-cVec.at(0)))/log(nDupVec.at(nDupVec.size()-2)/nDupVec.at(nDupVec.size()-1));
		else if(q.at(0) == 0 && q.at(1) > 1) //The case if the lower quartile is at index 0 and upper quartile index is above index 1.
			Q = (.5*cVec.at(0) + (cVec.at(q.at(1)-1)-cVec.at(q.at(0))) + .5*(cVec.at(q.at(1))-cVec.at(q.at(1)-1)))/log(nDupVec.at(nDupVec.size()-1-q.at(1))/nDupVec.at(nDupVec.size()-1));
	
		cout << "Q = " << Q << "\n";
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the QStatistic class Function doQStat. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the QStatistic class function doQStat. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double SSBPDiversityIndices::getShan(vector<double> vec)//vec = The data vector.
{	try {
		VecCalc vecCalc;
		double nz = vecCalc.numNZ(vec);
		double nSum = vecCalc.sumElements(vec);
		double H = 0;
		for(int i = 0; i < nz; i++)
			H += vec.at(i)/nSum*log(vec.at(i)/nSum);
		H *= -1;
		return H;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the SSBPDiversityIndices class Function getShan. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the SSBPDiversityIndices class function getShan. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double SSBPDiversityIndices::getSimp(vector<double> vec)//vec = The data vector.
{	try {
		VecCalc vecCalc;
		double nSum = vecCalc.sumElements(vec);
		double D = 0;
		for(int j = 0; j < vec.size(); j++)
			D += vec.at(j)*(vec.at(j)-1)/(nSum*(nSum-1));
		return D;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the SSBPDiversityIndices class Function getSimp. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the SSBPDiversityIndices class function getSimp. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double SSBPDiversityIndices::getBP(vector<double> vec)//vec = The data vector.
{	try {
		VecCalc vecCalc;
		double nSum = vecCalc.sumElements(vec);
		return vecCalc.findMax(vec)/nSum;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the SSBPDiversityIndices class Function getBP. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the SSBPDiversityIndices class function getBP. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
void SSBPDiversityIndices::doSSBP(vector<double> vec)//vec = The data vector.
{	try {
		VecCalc vecCalc;
		double nz = vecCalc.numNZ(vec);
	
		//Shannon index
		double H = getShan(vec);
		cout << "H = " << H << "\n";
		cout << "Eveness = " << H/log(nz) << "\n\n";
	
		//Simpson index
		double D = getSimp(vec);
		cout << "D diversity = " << 1/D << "\n";
		cout << "Eveness = " << 1/D/nz << "\n\n";
	
		//Berger-Parker index
		double BP = getBP(vec);
		cout << "BP index = " << BP << "\n\n";
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the SSBPDiversityIndices class Function doSSBP. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the SSBPDiversityIndices class function doSSBP. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************/
double TDTable::getConfLimit(int row, int col) //Rows are the degrees of freedom
{    try {                       
		//Confidence Level        .80    .90     .95     .98     .99     .998     .999
		double values[33][7] = {{3.078, 6.314,	12.706,	31.821,	63.656,	318.289, 636.578},
						    {1.886,	2.920,	4.303,	6.965,	9.925,	22.328,	31.600},
							{1.638,	2.353,	3.182,	4.541,	5.841,	10.214,	12.924},
							{1.533,	2.132,	2.776,	3.747,	4.604,	7.173,	8.610},
							{1.476,	2.015,	2.571,	3.365,	4.032,	5.894,	6.869},
							{1.440,	1.943,	2.447,	3.143,	3.707,	5.208,	5.959},
							{1.415,	1.895,	2.365,	2.998,	3.499,	4.785,	5.408},
							{1.397,	1.860,	2.306,	2.896,	3.355,	4.501,	5.041},
							{1.383,	1.833,	2.262,	2.821,	3.250,	4.297,	4.781},
							{1.372,	1.812,	2.228,	2.764,	3.169,	4.144,	4.587},
							{1.363,	1.796,	2.201,	2.718,	3.106,	4.025,	4.437},
							{1.356,	1.782,	2.179,	2.681,	3.055,	3.930,	4.318},
							{1.350,	1.771,	2.160,	2.650,	3.012,	3.852,	4.221},
							{1.345,	1.761,	2.145,	2.624,	2.977,	3.787,	4.140},
							{1.341,	1.753,	2.131,	2.602,	2.947,	3.733,	4.073},
							{1.337,	1.746,	2.120,	2.583,	2.921,	3.686,	4.015},
							{1.333,	1.740,	2.110,	2.567,	2.898,	3.646,	3.965},
							{1.330,	1.734,	2.101,	2.552,	2.878,	3.610,	3.922},
							{1.328,	1.729,	2.093,	2.539,	2.861,	3.579,	3.883},
							{1.325,	1.725,	2.086,	2.528,	2.845,	3.552,	3.850},
							{1.323,	1.721,	2.080,	2.518,	2.831,	3.527,	3.819},
							{1.321,	1.717,	2.074,	2.508,	2.819,	3.505,	3.792},
							{1.319,	1.714,	2.069,	2.500,	2.807,	3.485,	3.768},
							{1.318,	1.711,	2.064,	2.492,	2.797,	3.467,	3.745},
							{1.316,	1.708,	2.060,	2.485,	2.787,	3.450,	3.725},
							{1.315,	1.706,	2.056,	2.479,	2.779,	3.435,	3.707},
							{1.314,	1.703,	2.052,	2.473,	2.771,	3.421,	3.689},
							{1.313,	1.701,	2.048,	2.467,	2.763,	3.408,	3.674},
							{1.311,	1.699,	2.045,	2.462,	2.756,	3.396,	3.660},
							{1.310,	1.697,	2.042,	2.457,	2.750,	3.385,	3.646},
							{1.296,	1.671,	2.000,	2.390,	2.660,	3.232,	3.460},
							{1.289,	1.658,	1.980,	2.358,	2.617,	3.160,	3.373},
							{1.282,	1.645,	1.960,	2.326,	2.576,	3.091,	3.291}};
		return values[row][col];
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the TDTable class Function getConfLimit. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the TDTable class function getConfLimit. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}
/***********************************************************************
void TrunLN::doTrunLN(vector<double> indVec, vector<double> specVec) //indVec = individuals vector, specVec = species vector
{	
	VecCalc vecCalc;
	double numSpec = vecCalc.sumElements(specVec); //numSpec = The total number of species
	double numInd = vecCalc.sumElements(vecCalc.multVecs(indVec,specVec)); //numInd = The total number of individuals
	
	double obsMean = 0;
	for(int i = 0; i < indVec.size(); i++)
		obsMean += log10(indVec.at(i));
	obsMean /= numSpec; //obsMean = observed mean of the individuals vector
	cout << "obsMean = " << obsMean << "\n";
	double variance = 0;
	for(int t = 0; t < indVec.size(); t++)
		variance += pow(log10(indVec.at(t))-obsMean,2)/numSpec;
	 
	 double rO = 0;
	 for(int k = 0; k < indVec.size(); k++)
		rO += log10(indVec.at(k));
	 rO /= indVec.size();
	 double veilLine = .5;//The desired veil line.
	 double auxFunc = -(obsMean-rO)/(obsMean-log10(veilLine));
	 double uX = obsMean-auxFunc*(obsMean-log10(veilLine));
	 double vX = variance + auxFunc*pow(obsMean-log10(veilLine),2);
	 double z = (log10(veilLine)-uX)/pow(vX, .5);
	 double p = .5*(erf(z)+1);
	 double specRichness = numSpec/(1-p);
	 
	 double numUnseen = .5*(erf((log10(.5)-uX)/pow(vX,.5))+1)*specRichness;
	 
	 
	 vector<double> cExp;
	 for(int i = 1; i < 8; i++)
	 {
		double a = pow(10, i-1)+.5;
		double b = log10(a);
		double c = (b - uX)/pow(vX,.5);
		double d = .5*(erf(c)+1);
		double numS = d*specRichness;
		double toPush = numS - numUnseen;
		cExp.push_back(toPush);
	}	
	vector<double> cObs;
	double sumOct = 0;
	for(int i = 0; i < 8; i++)
	{
		sumOct = 0;
		for(int r = 0; r < indVec.size(); r++)
		{
			if(indVec.at(r) < pow(10, i-1)+.5)
				sumOct += specVec.at(r);
			else
			{
				cObs.push_back(sumOct);
				sumOct = specVec.at(r);
				r = indVec.size();
			}
			if(r == indVec.size()-1)
				cObs.push_back(sumOct);
		}
	}

	//Statistical Analysis
	double d = vecCalc.findDStat(cExp, cObs, numSpec);
	cout << "DStat = " << d << "\n";
	cout << ".05 confidence value = " << .89196/sqrt(numSpec) << "\n";
	cout << ".01 confidence value = " << 1.0471/sqrt(numSpec) << "\n\n";
}
/***********************************************************************/
