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

class B{
	Abs* a ;
	public:
		void doSthInB(){
			a->dosth();
		}
/*		void setObj(int i){
			if(i == 1){
				a = new Conc;
			}
			else{
				a = new Conc2;
			}
		}*/
		
		void setObj(Abs& aa){
				a = &aa;
		}
};

int main(){
	std::cout<<"compiles"<<std::endl;
	Abs* a = new Conc();
	a = new Conc2();
	a->dosth();
	
	B* b = new B;
	b->setObj(1);
	b->setObj(&a);
	b->doSthInB();

}

