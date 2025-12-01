#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <cstddef>
#include <cstdlib>

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
	while(i < input.length() && input[i] != '.'){
		if(!std::isdigit(input[i]))
			return false;
		i++;
	}
	if(i >= input.length() || input[i] != '.')
		return false;
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
	if(input.empty())
		return false;
	size_t i = 0;
	if(input[0] == '-' || input[0] == '+')
		i = 1;
	if(i >= input.length())
		return false;
	while(i < input.length() && input[i] != '.'){
		if(!std::isdigit(input[i]))
			return false;
		i++;
	}
	if(i >= input.length() || input[i] != '.')
		return false;
	i++;
	if(i >= input.length())
		return false;
	while(i < input.length()){
		if(!std::isdigit(input[i]))
			return false;
		i++;
	}
	return true;
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
	if(isChar(input)){
		char c = input[1];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
	}
	else if(isInt(input)){
		int i = atoi(input.c_str());
		std::cout << "char: " << static_cast<char>(i) << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
	}
	else if(isFloat(input)){
		float f = static_cast<float>(atof(input.c_str()));
		std::cout << "char: " << static_cast<char>(f) << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	else if(isDouble(input)){
		double d = atof(input.c_str());
		std::cout << "char: " << static_cast<char>(d) << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d) << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else{
		std::cout << "error: no conversion possible" << std::endl;
	}
}


ScalarConverter::~ScalarConverter(){}