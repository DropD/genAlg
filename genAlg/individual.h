#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include <vector>
#include <iostream>
#include <random>
#include "sexEnum.h"
class individual{
	private:
		unsigned int ndim;
		std::vector<float> featureVector;
		sexEnum sex;
		std::default_random_engine rngEngine;
	public:
		individual(std::vector<float> , sexEnum);
		individual(std::vector<float>);
		individual makeOffspring(individual);
		std::vector<float> getFeatureVector();
		individual combine1(individual);
		float getObjectiveFunction();
		std::string getIndividualString(int); // the integer defines the verbosity of the output string. This is supposed to have some data about the individual.
		unsigned int getNdim();
		void setRNG(std::default_random_engine rngEngine);
		std::string featureLine();

};

#endif /*INDIVIDUAL_H_*/
