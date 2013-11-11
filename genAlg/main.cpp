//#include "individual.cpp"
//#include "population.cpp"
#include "genalg.h"

//#include "individual.cpp"
int main(){
	std::cout<<"It compiled and runned"<<std::endl;
	std::vector<float> v1;
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(-4);
	individual ind1(v1);
	
	std::pair<float,float> b1(-10,10);
	std::pair<float,float> b2(-10,10);
	std::vector<std::pair<float,float> > bounds;
	bounds.push_back(b1);bounds.push_back(b2);
	
	population pop(10,bounds);
	std::cout<<"The population created has "<<pop.getNpop()<<" individuals"<<std::endl;
	std::cout<<"The dimension of the individuals is"<<pop.getNdim()<<std::endl;
	std::default_random_engine r{};
	ind1.setRNG(r);
	std::cout<<ind1.getObjectiveFunction()<<std::endl;
	pop.printPop();
	std::cout<<pop.getIndividual(9).getFeatureVector().at(0)<<std::endl;
	std::cout<<pop.getIndividual(9).getFeatureVector().at(1)<<std::endl;
	std::cout<<"Dimensions of indiv:"<<((pop.getIndividual(2))).getNdim()<<std::endl;
	
	std::cout<<"The program ended without crashing"<<std::endl;

}