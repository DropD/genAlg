#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include <vector>
#include <iostream>
#include <random>
#include "sexEnum.h"
#include "combinationStrategy.cpp"


class individual{
	private:
		unsigned int ndim;
		std::vector<float> featureVector;
		sexEnum sex;
		std::default_random_engine rngEngine;
		combinationStrategy *cstrategy;
	public:
		individual(std::vector<float> , sexEnum);
		individual(std::vector<float>);
		individual makeOffspringAsexual(individual);
		individual makeOffspringSexual(individual);
		std::vector<float> getFeatureVector();
		individual combine1(individual); //first approach - no trategy pattern
		individual combineIndividuals(individual);
		float getObjectiveFunction();
		std::string getIndividualString(int); // the integer defines the verbosity of the output string. This is supposed to have some data about the individual.
		unsigned int getNdim();
		void setRNG(std::default_random_engine rngEngine);
		std::string featureLine();
		std::vector<float> getChromosome();//relevant for the sex aware gen alg
		void setCombinationStrategy(combinationStrategy&);
		std::default_random_engine getRngEngine();
		
};

#endif /*INDIVIDUAL_H_*/
