#ifndef OBJECTIVEFUNCTIONSTRATEGY_H_
#define OBJECTIVEFUNCTIONSTRATEGY_H_
#include <vector>
class individual;
class objectiveFunctionStrategy
{
public:
	objectiveFunctionStrategy();
	virtual ~objectiveFunctionStrategy();
	virtual float evaluate(individual);
};
#endif /*OBJECTIVEFUNCTIONSTRATEGY_H_*/
