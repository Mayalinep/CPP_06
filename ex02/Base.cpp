#include "Base.hpp"
#include <iostream>
#include <exception>

Base::~Base(){

}

Base* generate(void){
	switch(rand() % 3){
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;

}

void identify(Base* p){
	A* a = dynamic_cast<A*>(p);
	if(a != NULL){
		std::cout << "A" << std::endl;
		return;
	}
	B* b = dynamic_cast<B*>(p);
	if(b != NULL){
		std::cout << "B" << std::endl;
		return;
	}
	std::cout << "C" << std::endl;
}

void identify(Base& p){
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch(std::exception& e){
	}
	try{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch(std::exception& e){
	}
	std::cout << "C" << std::endl;
}