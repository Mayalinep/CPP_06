#pragma once

#include <cstdlib>

class Base {
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify(Base* p); // pour identifier via un pointeur 
void identify(Base& p); // pour identifier via une ref