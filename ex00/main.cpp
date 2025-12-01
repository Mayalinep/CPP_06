#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv){
	if(argc < 2){
		std::cout << "Usage: ./convert <value>" << std::endl;
		return 1;
	}
	
	// Test de vos fonctions bool - pas besoin de créer d'instance !
	ScalarConverter::test(argv[1]);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "convert: " << std::endl;
	ScalarConverter::convert(argv[1]);
	return 0;
}
