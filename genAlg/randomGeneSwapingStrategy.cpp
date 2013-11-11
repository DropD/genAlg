#include "individual.h"
#include "combinationStrategy.h"

class randomGeneSwapingStrategy : public combinationStrategy{
public:
	
	float thress;
	randomGeneSwapingStrategy(float thress){
		this->thress = thress;
	}
	
	individual combine(individual i1, individual i2){
		//Here lies the implementation of the combination strategy:
		std::vector<float> i3FV(i2.getFeatureVector());
		
		std::uniform_real_distribution<> dint(0,1);
		
		float O1 = i1.getObjectiveFunction();
		float O2 = i2.getObjectiveFunction();
		
		float fitnessBias = O1>O2 ? 0.75 : 0.25;
		
		std::default_random_engine r{};
		r = i1.getRngEngine();
		
		for(unsigned int i=0;i<i1.getNdim();i++){
			i3FV.at(i) = dint(r)<fitnessBias ? (i1.getFeatureVector()).at(i) : (i2.getFeatureVector()).at(i) ;
		}
		
		
		return individual(i3FV);

	}
};