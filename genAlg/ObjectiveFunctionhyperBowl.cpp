#ifndef OBJECTIVEFUNCTIONHYPERBOWL_H_
#define OBJECTIVEFUNCTIONHYPERBOWL_H_

#include "objectiveFunctionStrategy.cpp"
#include "individual.h"


class ObjectiveFunctionhyperBowl: public objectiveFunctionStrategy
{
public:
	ObjectiveFunctionhyperBowl();
	virtual ~ObjectiveFunctionhyperBowl();
	float evaluate(individual);
};

float ObjectiveFunctionhyperBowl::evaluate(individual ind){
	std::cout<<"i'm in float ObjectiveFunctionhyperBowl::evaluate"<<std::endl;
	//Here the objective function is calculated somehow...
	//Let's say a simple hyperbowl...
	float Fc =0 ;
	std::vector<float> v = ind.getFeatureVector();
	std::cout<<"I'm inside the obj function calculation"<<std::endl;
	for(unsigned int i=0;i<v.size();i++){
		std::cout<<"I'm calculating the of"<<std::endl;
		Fc += v[i]*v[i];
	}
	return Fc;
}

#endif /*OBJECTIVEFUNCTIONHYPERBOWL_H_*/
