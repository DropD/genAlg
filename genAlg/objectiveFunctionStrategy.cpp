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
	virtual float evaluate(std::vector<float>);
};
#endif /*OBJECTIVEFUNCTIONSTRATEGY_H_*/
