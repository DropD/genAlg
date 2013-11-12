#ifndef OOBJECTIVEFUNCTIONHYPERBOWL_CPP_
#define OOBJECTIVEFUNCTIONHYPERBOWL_CPP_

#include "objectiveFunctionStrategy.h"
#include "individual.h"
//class individual;
class ObjectiveFunctionhyperBowl: objectiveFunctionStrategy
{
public:
	ObjectiveFunctionhyperBowl();
	~ObjectiveFunctionhyperBowl();
	float evaluate(individual ind){
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
};
#endif