#include <vector>
#include <iostream>
#include "individual.h"
#include <sstream>
//class individual{
	//private:
		//std::vector<float> featureVector;
		//sexEnum sex;
	//public:
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
		//std::cout<<fv[i]<<std::endl;
	}
	this -> ndim = featureVector.size();
}
/**
 * The make offspring method returns a new individual.
 * The new individual is created by combining in a speciffic 
 * (yet to be defined) way the features of the two parents.
 */
individual individual::makeOffspring(individual indiv){
	std::vector<float> newFV((this->featureVector).size());
	individual child(newFV);
	child = this->combine1(indiv);
	return child;
}

/**
 * This method gives access to the private features of the individual
 */
std::vector<float> individual::getFeatureVector(){
	return this->featureVector;
}

/**
 * the combine method just takes the average of the individual's feature vector 
 * and another individual.
 * 
 * The combination strategy is used in the make offspring method to create a child.
 */
individual individual::combine1(individual indiv){
	//individual child(indiv.getFeatureVector());
	std::vector<float> fv;
	std::vector<float> indivFV(indiv.getFeatureVector());
	
	for(unsigned int i=0;i < (this->featureVector).size();i++){
		fv.push_back( (indivFV[i] + featureVector[i]) / 2) ; 
	}
	return individual(fv);
}

float individual::getObjectiveFunction(){
	//Here the objective function is calculated somehow...
	//Let's say a simple hyperbowl...
	float F =0 ;
	for(unsigned int i=0;i<(this->featureVector).size();i++){
		F += featureVector[i]*featureVector[i];
	}
	return F;
}
void individual::setRNG(std::default_random_engine rngEngine){
	this->rngEngine = rngEngine;
}

std::string individual::featureLine(){
	std::string s;
	//std::cout<<"The current individuals dim is  "<< this->ndim<<" "<<std::endl;
	for(unsigned int i=0;i<(this->ndim);i++){
		//sprintf(c,"%f",(this->featureVector).at(i));
		std::ostringstream ss;
		ss << (this->featureVector).at(i);
		s.append(ss.str());
		if(i!=(ndim-1))  s.append(", ");
		//std::cout<<(this->featureVector).at(i)<<std::endl;
	}
	return s;
}

unsigned int individual::getNdim(){
	return (this->ndim);
}
	

