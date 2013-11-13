#include <iostream>

class Abs{
public:
	virtual void dosth()=0;
};

class Conc:public Abs{
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

class Context{
public:
	Abs* a ;
	void setObj(int i){
		if(i==0)
			a = new Conc;

		if(i==2)
			a = new Conc2;
			
	}
	void doctx(){
		a->dosth();
	}
};


class B{
	Context cont;
	public:
		void doSthInB(){
			cont.doctx();
		}
		void setContext(Context ctx){
			this->cont = ctx;
		}
};

int main(){
	std::cout<<"compiles"<<std::endl;
	Abs* a = new Conc();
	a = new Conc2();
	a->dosth();
	
	Context ctx;
	ctx.setObj(1);
	
	B* b = new B;
	b->setContext(ctx);
	b->doSthInB();
}

