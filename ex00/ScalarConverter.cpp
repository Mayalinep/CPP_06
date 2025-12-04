#include "ScalarConverter.hpp"
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <climits>

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

bool ScalarConverter::isOther(const std::string& input){
	if(input == "nan" || input == "+nan" || input == "-nan")
		return true;
	if(input == "inf" || input == "+inf" || input == "-inf")
		return true;
	if(input == "nanf" || input == "+nanf" || input == "-nanf")
		return true;
	if(input == "inff" || input == "+inff" || input == "-inff")
		return true;
	return false;
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

void ScalarConverter::printFloat(float f) {
    std::cout << "float: ";
    if (f == static_cast<int>(f) && f >= -1000000 && f <= 1000000) {
        std::cout << static_cast<int>(f) << ".0f";
    } else {
        std::cout << f << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: ";
    if (d == static_cast<int>(d) && d >= -1000000 && d <= 1000000) {
        std::cout << static_cast<int>(d) << ".0";
    } else {
        std::cout << d;
    }
    std::cout << std::endl;
}

//void ScalarConverter::test(const std::string& input){
//	std::cout << "=== Test pour: \"" << input << "\" ===" << std::endl;
//	std::cout << "isChar:   " << (isChar(input) ? "true" : "false") << std::endl;
//	std::cout << "isInt:    " << (isInt(input) ? "true" : "false") << std::endl;
//	std::cout << "isFloat:  " << (isFloat(input) ? "true" : "false") << std::endl;
//	std::cout << "isDouble: " << (isDouble(input) ? "true" : "false") << std::endl;
//	std::cout << std::endl;
//}

void ScalarConverter::convert(const std::string& input){
	if(isChar(input)){
		char c = input[1];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
	}
	else if(isInt(input)){
		long tmp = atol(input.c_str());
		if(tmp < INT_MIN || tmp > INT_MAX){
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}

		int i = static_cast<int>(tmp);
		if(i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(i))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        
        std::cout << "int: " << i << std::endl;
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
    }
	else if(isFloat(input)){
		float f = static_cast<float>(atof(input.c_str()));
        
        if (f < 0 || f > 127 || f != f)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<int>(f)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        
        if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX) || f != f)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        
        printFloat(f);
		printDouble(static_cast<double>(f));
	}

	else if(isDouble(input)){
		double d = atof(input.c_str());
		if (d < 0 || d > 127 || d != d)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<int>(d)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

		if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX) || d != d)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        
        printFloat(static_cast<float>(d));
		printDouble(d);
	}
	else if(isOther(input)){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		bool isFloatType = (input == "nanf" || input == "+nanf" || input == "-nanf" ||
		                    input == "inff" || input == "+inff" || input == "-inff");
		std::string base = isFloatType ? input.substr(0, input.length() - 1) : input;
		std::cout << "float: " << base << "f" << std::endl;
		std::cout << "double: " << base << std::endl;
	}
	else{
		std::cout << "error: no conversion possible" << std::endl;
	}
}


ScalarConverter::~ScalarConverter(){}