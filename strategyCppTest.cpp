#include <iostream>

class Abs{
public:
	virtual void dosth()=0;
};

class Conc1:public Abs{
public:
	void dosth(){
		std::cout<<"I'm doing sth"<<std::endl;
	}
};
class Conc2:public Abs{
public:
	void dosth(){
		std::cout<<"I'm doing sth else"<<std::endl;
	}
};

class B{
	Abs* nakedStrategy;
	public:
		void doSthInB(){
			nakedStrategy->dosth();
		}
		void setContext(Context* ctx){
			this->cont = ctx;
		}
		void setNakedStrategy(Abs * abs){
			this->nakedStrategy = abs;
		}
};

int main(){
	Abs* a = new Conc2;	
	Context* ctx = new Context;ctx->setObj(0);
	
	B* b = new B;
	b->setNakedStrategy(a);
	
	std::cout<<"This gives a segfault..."<<std::endl;
	b->doSthInB();	
}

