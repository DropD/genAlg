//#include "individual.cpp"
//#include "population.cpp"
#include "genalg.h"
class objectiveFunctionStrategy;
class ObjectiveFunctionhyperBowl;

//#include "individual.cpp"
int main(){
	std::cout<<"It compiled and runned"<<std::endl;
	
	std::pair<float,float> b1(-5,1);
	std::pair<float,float> b2(-10,10);
	std::pair<float,float> b3(-10,10);

	std::vector<std::pair<float,float> > bounds;
	bounds.push_back(b1);bounds.push_back(b2);bounds.push_back(b3);
	
	population pop(10,bounds);
	/*Creating random engine and passing it to who needs it*/
	std::default_random_engine r{};
	std::cout<<"Trying to print population..."<<std::endl;
	//objectiveFunctionStrategy OdFS();
	ObjectiveFunctionhyperBowl ofb();
	objectiveFunctionStrategy * ofs_ptr = new ObjectiveFunctionhyperBowl();
	//ofs_ptr = dynamic_cast<objectiveFunctionStrategy*>(&ofb);
	//ObjectiveFunctionhyperBowl & odfsConc();
	//OdFS = (objectiveFunctionStrategy &)odfsConc;
	//pop.setObjFuncStrat(OdFS);
	//pop.printPop();
	std::cout<<"Printed population..."<<std::endl;
	std::cout<<"The program ended without crashing"<<std::endl;
}