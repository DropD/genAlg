#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include <vector>
#include <iostream>
#include <random>
#include "sexEnum.h"
#include "combinationStrategy.cpp"
#include "objectiveFunctionStrategy.cpp"
#include <assert.h>

//class objectiveFunctionStrategy;
//class combinationStrategy;

class individual{
	private:
		unsigned int 					ndim;
		std::vector<float> 				featureVector;
		sexEnum 						sex;
		std::default_random_engine 		rngEngine;
		
		/* The strategy objects 
		 * that are interchangeable 
		 * and give the individual the
		 * combination and the objective 
		 * function functionality
		 */
		combinationStrategy*			cstrategy;
		objectiveFunctionStrategy*		ofstrategy;
		
		//flags for error checking:
		bool							OFCalc=false;
		bool							OFAvailable=false;
		bool							CombStratAvail=false;
		bool							RNGEngineSet=false;
		
		float							Objective;
	public:
		/*Constructors*/
		individual(std::vector<float> , sexEnum);
		individual(std::vector<float>);
		
		individual 						makeOffspringAsexual(individual);
		individual 						makeOffspringSexual(individual);
		
		individual 						combine1(individual); //first approach - no trategy pattern
		individual 						combineIndividuals(individual); //The strategy pattern approach
		
		
		// The integer defines the verbosity of the output string. 
		// This is supposed to have some data about the individual.
		std::string	 					getIndividualString(int); 
		unsigned int 					getNdim();
		float 							getObjectiveFunction();
		std::vector<float> 				getChromosome();//relevant for the sex aware gen alg
		std::default_random_engine 		getRngEngine();
		std::vector<float> 				getFeatureVector();
		
		std::string 					featureLine();
		void 							setCombinationStrategy(combinationStrategy&);
		void 							setRNG(std::default_random_engine rngEngine);
		void 							setObjectiveFunction(objectiveFunctionStrategy&);
		individual						copy();
};

#endif /*INDIVIDUAL_H_*/
