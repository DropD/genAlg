#include <vector>
#include <iostream>
#include "individual.h"
#include <sstream>

individual::individual(std::vector<float> fv, sexEnum Sex){
	for(unsigned int i=0;i<fv.size() ; i++){
		featureVector.push_back(fv[i]);
	}
	this->sex = Sex;
	this -> ndim = featureVector.size();
}

individual::individual(std::vector<float> fv){
	//asexual constructor
	for(unsigned int i=0;i<fv.size() ; i++){
		featureVector.push_back(fv[i]);
	}
	this -> ndim = featureVector.size();
}

individual individual::copy(){
	std::vector<float> cop = getFeatureVector();
	individual ind(cop);
	return ind;
}
/**
 * The make offspring method returns a new individual.
 * The new individual is created by combining in a speciffic 
 * (yet to be defined) way the features of the two parents.
 */
individual individual::makeOffspringAsexual(individual indiv){
	std::vector<float> newFV((this->featureVector).size());
	individual child(newFV);
	child = this->combine1(indiv);
	return child;
}


/**
 * This method gives access to the private features of the individual
 */
std::vector<float> individual::getFeatureVector(){
	/*I supposedly coded it in such a way that there never
	 *exists an individual without a feature vector - assertion not neccessary
	 */
	return this->featureVector;
}

/**
 * Asexual reproduction:
 * 
 * I just randomly chose features of one or the other parent by a probabillity proportional
 * to the parents fitness function
 * 
 * The combination strategy is used in the make offspring method to create a child.
 */
individual individual::combine1(individual indiv){
	//individual child(indiv.getFeatureVector());
	std::vector<float> fv;
	std::vector<float> indivFV(indiv.getFeatureVector());
	
	std::uniform_real_distribution<> dint(0,1);
	
	float O1 = this->getObjectiveFunction();
	float O2 = indiv.getObjectiveFunction();
	
	float fittnessBias = O1>O2 ? 0.75 : 0.25;
	
	for(unsigned int i=0;i<ndim;i++){
		indivFV.at(i) = dint(this->rngEngine)<fittnessBias ? (this->featureVector).at(i) : (indiv.getFeatureVector()).at(i);
	}
	
	
	return individual(fv);
}
std::default_random_engine individual::getRngEngine(){
	if(RNGEngineSet==false) assert(0);
	return this->rngEngine;
}

float individual::getObjectiveFunction(){
	if(CombStratAvail == false) {assert(0);}
	//Here the objective function is calculated somehow...
	//Let's say a simple hyperbowl...
	float Fc=0;
	if(OFCalc == false){
		std::cout<<"Now I'm trying to calculate the OF on this..."<<std::endl;
		
		//individual tempIndiv = this->copy();
		std::cout<<"eval "<<std::endl;
		//std::cout<<ofstrategy<<std::endl;
		std::vector<float> vv = this->featureVector;
		Fc = ofstrategy->evaluate(vv);
	}
	if(OFCalc == true){
		Fc = Objective;
	}
	return Fc;
}

void individual::setRNG(std::default_random_engine rngEngine){
	this->rngEngine = rngEngine;
}

std::string individual::featureLine(){
	std::string s;
	std::ostringstream ss;
	for(unsigned int i=0;i<(this->ndim);i++){
		ss << (this->featureVector).at(i);
		if(i!=(ndim-1))  s.append(", ");
	}
	//std::cout<<"I'm out of the feature line loop"<<std::endl;

	ss<<(this->getObjectiveFunction());

	std::cout<<"I have not created the ss"<<std::endl;
	s.append(ss.str());
	std::cout<<"I have created the ss"<<std::endl;
	return s;
}

unsigned int individual::getNdim(){
	return (this->ndim);
}

individual individual::combineIndividuals(individual ind ){
	return cstrategy->combine(*this,ind);
}

void individual::setObjectiveFunction(objectiveFunctionStrategy& of){
	OFAvailable=true;
	ofstrategy = &of;
}

void individual::setCombinationStrategy(combinationStrategy& cstr){
	CombStratAvail=true;
	cstrategy = &cstr;
}
