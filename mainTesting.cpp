	#include <iostream>
	#include <sstream>
	#include <random>
	#include <assert.h>
	#include <vector>
	class individual;
	class objectiveFunctionStrategy;
	
	/*
	 * This is my abstract class implementation for a strategy.
	 */
	class objectiveFunctionStrategy
	{
	public:
		virtual float evaluate(individual)=0;
	};
	
	/*
	 * Now this one is a concrete strategy object class:
	 */
	class ObjectiveFunctionhyperBowl: public objectiveFunctionStrategy
	{
	public:
		float evaluate(individual ind){
			float Fc =0 ;
			std::vector<float> v = ind.getFeatureVector();
			for(unsigned int i=0;i<v.size();i++){
				Fc += v[i]*v[i];
			}
			return Fc;
		}
	};
	
	/*
	 * The class individual should contain strategy objects
	 */
	class individual{
		private:
			std::vector<float> 				featureVector;
			objectiveFunctionStrategy *		ofstrategy;
			unsigned int ndim;
			
		public:
			/*Constructors*/
			individual(std::vector<float>);
			float getObjectiveFunction();
			void setObjectiveFunction(int k);
			
			std::vector<float> getFeatureVector();
	};
	
	individual::individual(std::vector<float> fv){
		for(unsigned int i=0;i<fv.size() ; i++){
			featureVector.push_back(fv[i]);
		}
		this -> ndim = featureVector.size();
	}
	
	std::vector<float> individual::getFeatureVector(){
		return this->featureVector;
	}
	
	float individual::getObjectiveFunction(){
		/*
		 *Here I'm planning of passing a concrete strategy object to 
		 *make the objective functions interchangeable.
		 * 
		 *So the calculation would be ofstrategy.evaluate()
		 */
		float Fc=0;
		if(false == false){
			std::vector<float> vv = this->featureVector;
			Fc = ofstrategy->evaluate(vv);
		}
		return Fc;
	}
	
	void individual::setObjectiveFunction(int i){
		/*
		 * here the strategy is defined inside the class by an integer
		 */
		this->ofstrategy = new ObjectiveFunctionhyperBowl;
	}
	
	
	int main(){
		
		std::vector<float> v;
		/*ObjectiveFunctionhyperBowl hb;
		objectiveFunctionStrategy* ofs;
		ofs = dynamic_cast<objectiveFunctionStrategy*> (&hb);
		*/
		individual indiv(v);
		/*
		 * Now the above does not compile...
		 * error message:
		 * main.cpp: In member function ‘void individual::setObjectiveFunction(int)’:
			main.cpp:68:25: σφάλμα: expected type-specifier before ‘ObjectiveFunctionhyperBowl’
			main.cpp:68:25: σφάλμα: cannot convert ‘int*’ to ‘objectiveFunctionStrategy*’ in assignment
			main.cpp:68:25: σφάλμα: expected ‘;’ before ‘ObjectiveFunctionhyperBowl’
			main.cpp: At global scope:
			main.cpp:81:29: σφάλμα: expected ‘;’ at end of member declaration
			main.cpp: In function ‘int main()’:
			main.cpp:108:14: σφάλμα: ‘indiv’ was not declared in this scope
		 * 
		 * 
		 */
		v.push_back(2.1);
		v.push_back(22.1);/*
		hb.evaluate(indiv);*/
	}
