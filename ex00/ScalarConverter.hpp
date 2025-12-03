#pragma once

#include <string>
#include <cctype>

class ScalarConverter {
	private:
		static bool isChar(const std::string& input);
		static bool isInt(const std::string& input);
		static bool isFloat(const std::string& input);
		static bool isDouble(const std::string& input);
		static bool isOther(const std::string& input);
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();

	public:
		//static void test(const std::string& input);
		static void convert(const std::string& input);
};