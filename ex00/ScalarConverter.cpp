#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <cstddef>

ScalarConverter::ScalarConverter(){

}
ScalarConverter::ScalarConverter(const ScalarConverter& rhs){
	(void)rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs){
	if(this != &rhs){
		(void)rhs;
		return *this;
	}
	return *this;
}

bool ScalarConverter::isChar(const std::string& input){
	if(input.length() != 3)
		return false;
	if(input[0] != '\''|| input[2] != '\'')
		return false;
	if(!std::isprint(input[1]))
		return false;
	else
		return true;

}

bool ScalarConverter::isInt(const std::string& input){
	if(input.empty())
		return false;
	size_t i = 0;
	if(input[0] == '-' || input[0] == '+')
		i = 1;
	if(i >= input.length())
		return false;
	while(i < input.length()){
		if(!std::isdigit(input[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& input){
	if(input.empty())
		return false;
	size_t i = 0;
	if(input[0] == '-' || input[0] == '+')
		i = 1;
	if(i >= input.length() || input[input.length() - 1] != 'f')
		return false;
	while(input[i] != '.'){
		if(!input[i]){
			return false;
		}
		if(!std::isdigit(input[i]))
			return false;
		i++;
	}
	std::cout << input[i] << ": ce caractere est un point ?" << std::endl;
	if(input[i] == '.')
		i++;
	if(i >= input.length() - 1)
		return false;
	
	while(i < input.length() - 1){
		if(!std::isdigit(input[i]))
			return false; 
		i++;
	}
	return true;

}
bool ScalarConverter::isDouble(const std::string& input){
	(void)input;
	return false; // TODO: à implémenter
}

void ScalarConverter::test(const std::string& input){
	std::cout << "=== Test pour: \"" << input << "\" ===" << std::endl;
	std::cout << "isChar:   " << (isChar(input) ? "true" : "false") << std::endl;
	std::cout << "isInt:    " << (isInt(input) ? "true" : "false") << std::endl;
	std::cout << "isFloat:  " << (isFloat(input) ? "true" : "false") << std::endl;
	std::cout << "isDouble: " << (isDouble(input) ? "true" : "false") << std::endl;
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& input){
	(void)input;
}


ScalarConverter::~ScalarConverter(){}