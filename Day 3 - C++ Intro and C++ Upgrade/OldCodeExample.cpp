//---------------------------------------------------------------------------
#pragma hdrstop

#include "OldCodeExample.h"

#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>

//---------------------------------------------------------------------------
Foo::Foo() {
	std::wcout << L"Foo created" << std::endl;
}

Foo::~Foo() {
	std::wcout << L"Foo destroyed" << std::endl;
}

void Foo::DoSomething() const {
	std::wcout << L"Hello from Foo" << std::endl;
}

//---------------------------------------------------------------------------
struct VectorMapFunctor {
private:
	std::map<int, std::wstring>& m_Map;
public:
	VectorMapFunctor(std::map<int, std::wstring>& map) : m_Map(map) {}
	void operator()(int n) { std::wcout << L"Entry " << n << L"=" << m_Map[n] << std::endl; }
};

//---------------------------------------------------------------------------
void Test(const Foo* foo) {
	foo->DoSomething();
}

//---------------------------------------------------------------------------
void DoStuff() {
	std::vector<int> items;
	items.push_back(1);
	items.push_back(2);
	items.push_back(5);

	std::map<int, std::wstring> map;
	map[1] = L"One";
	map[2] = L"Two";
	map[3] = L"Three";

	std::wcout << L"Test some map (key - value) access:" << std::endl;
	std::wcout << L"Item 2 is " << map[2] << std::endl;
	std::wcout << L"Item 5 is " << map[5] << std::endl;
	std::wcout << std::endl;

	// Demonstrate an algorithm
    std::wcout << L"Look up map items from a vector:" << std::endl;
	for_each(items.begin(), items.end(), VectorMapFunctor(map));

	std::wcout<< std::endl;
	// Print all vector items
	std::wcout << L"All vector items:" << std::endl;
	for (std::vector<int>::const_iterator it = items.begin(); it != items.end(); it++) {
		std::wcout << *it << std::endl;
	}
	std::wcout<< std::endl;

	// Create and do something with a Foo, then destroy it
	Foo* foo = new Foo();
	Test(foo);
	delete foo;
}
