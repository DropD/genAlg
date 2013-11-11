//#include "individual.cpp"
//#include "genalg.h"
//class individual;
#include <vector>
#include <iostream>
#include "population.h"

//#include "individual.h"
//class individual;

population::population(std::vector<individual> indivss){
	this->npop = indivss.size();
	this->ndim = indivss[1].getFeatureVector().size();
	for(unsigned int i=0;i<this -> npop;i++)
		(this -> indivs).push_back(indivss[i]);
	
}

population::population(unsigned int npop,std::vector<std::pair<float,float> > vb){
	//In the vector of pairs there are the upper and lower bounds of the features of the
	//individuals to be initialized.
	//npop is the population number of the random population.
	std::vector<float> featureVector(vb.size());
	std::uniform_real_distribution<float> rdist(0,1);
	
	this->npop = npop;
	this->ndim = vb.size();
	
	for(unsigned int i=0;i<npop;i++){
		for(unsigned int b=0; b<vb.size();b++){
			featureVector.at(b)  = rdist(this->rng)*(vb.at(b).second - vb.at(b).first) + vb.at(b).first;
		}
		
		individual ind(featureVector);
		(this->indivs).push_back(ind);
		std::cout<<"created an indiv. "<<i<<std::endl;
	}
	
}

std::vector<float> population::getObjectiveFunctions(){
	std::vector<float> vec;
	std::vector<float> currIndivVec(this->ndim);
	individual currIndiv(currIndivVec);
	for(unsigned int i=0;i< this -> npop;i++){
		currIndiv = indivs[i];
		vec.push_back(currIndiv.getObjectiveFunction());
	}
	return vec;
}
void population::printPop(){
	for(unsigned int i=0;     i < (this->npop) ; i++){
		for(unsigned int j=0; j < (this->ndim) ; j++){
			std::cout<<indivs.at(i).featureLine();
		}
		std::cout<<std::endl;
	}
}

unsigned int population::getNpop(){
	return (this->npop);
}
unsigned int population::getNdim(){
	return (this->ndim);
}