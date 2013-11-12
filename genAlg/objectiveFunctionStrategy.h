#ifndef OBJECTIVEFUNCTIONSTRATEGY_H
#define OBJECTIVEFUNCTIONSTRATEGY_H

//#include "individual.h"
class individual;
class objectiveFunctionStrategy
{
public:
	objectiveFunctionStrategy();
	virtual ~objectiveFunctionStrategy();
	virtual float evaluate(individual);
	//float evaluate(std::vector<float>);
};
#endif