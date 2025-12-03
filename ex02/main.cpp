#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(){
	std::srand(std::time(NULL));

	std::cout << "test pour generer et identifier via un pointeur" << std::endl;
	for(int i = 0; i < 5; i++){
		Base* random = generate();
		std::cout << " object " << i + 1 << " generated is type " ;
		identify(random);
		delete random;
	}

	std::cout << "Test pour generer et identifier via une reference" << std::endl;
	Base* object1 = generate();
	Base* object2 = generate();
	Base* object3 = generate();

	std::cout << "Object 1 is type: ";
	identify(*object1);
	std::cout << "Object 2 is type: ";
	identify(*object2);
	std::cout << "Object 3 is type: ";
	identify(*object3);
	
	
	delete object1;
	delete object2;
	delete object3;
	
	return 0;

}