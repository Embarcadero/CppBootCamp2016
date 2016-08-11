//---------------------------------------------------------------------------
#pragma hdrstop

#include <iostream>
#include "Foo.h"

Foo::Foo() {
	std::wcout << L"Foo created" << std::endl;
}

Foo::~Foo() {
	std::wcout << L"Foo destroyed" << std::endl;
}

void Foo::DoSomething() const {
	std::wcout << L"Hello from Foo" << std::endl;
}

