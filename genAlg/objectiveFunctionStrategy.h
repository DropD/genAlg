#ifndef OBJECTIVEFUNCTIONSTRATEGY_H
#define OBJECTIVEFUNCTIONSTRATEGY_H

//#include "individual.h"
class individual;
class objectiveFunctionStrategy
{
public:
	objectiveFunctionStrategy();
	virtual ~objectiveFunctionStrategy();
	virtual float evaluate(individual)=0;
	//float evaluate(std::vector<float>);
};
#endif