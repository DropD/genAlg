#ifndef POPULATION_H_
#define POPULATION_H_
#include "individual.h"
class population{
	private:
		unsigned short int ndim; //the dimensionallity of the individuals
		unsigned int npop; //The total number of individuals in the population
		unsigned int ngen; //The total number of generations so far
		unsigned int fCalculations; // the total number of calculation of the objective function.
		std::vector<individual> indivs;
		std::default_random_engine rng;
	public:
		population(std::vector<individual>);
		population(unsigned int,std::vector<std::pair<float,float> >);
		void runGeneration();
		std::vector<float> getObjectiveFunctions(); //get the objective function of the N individual
		std::vector<individual> getBest(int); //This returns the N best individuals of the population

		
		//The following are for the sex-aware implementation:
		std::vector<float> getMales();//returns the males of the population (the ones that the objective is ESTIMATED!)
		std::vector<float> getFemes();//returns the Females of the population (the ones that the objective is calculated.)
		void setRNG(std::default_random_engine rngEngine);
		
		std::string getGenerationString(); // That string returned should have some data about the current population.
		void printPop();
		unsigned int getNpop();
		unsigned int getNdim();
		individual getIndividual(int);
};
#endif /*POPULATION_H_*/
