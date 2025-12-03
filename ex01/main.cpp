#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(){
	Data original;
	original.value = 42;
	original.name = "Mpelage";

	std::cout << "Original value: " << &original << std::endl;
	std::cout << std::endl;
	uintptr_t serializer = Serializer::serialize(&original);
	std::cout << "Serializer value: " << serializer << std::endl;
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(serializer);
	std::cout << "Deserialized value: " << deserialized << std::endl;

	if(deserialized == &original){
		std::cout << "Deserialized value is equal to the original value" << std::endl;
	}
	else{
		std::cout << "Deserialized value is not equal to the original value" << std::endl;
	}

	return 0;
}