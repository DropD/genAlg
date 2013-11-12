#ifndef COMBINATIONSTRATEGY_
#define COMBINATIONSTRATEGY_

//#include "individual.h"

class individual;

class combinationStrategy{
public:
	combinationStrategy(){};
	virtual individual combine(individual,individual);
};


#endif /*COMBINATIONSTRATEGY_*/
