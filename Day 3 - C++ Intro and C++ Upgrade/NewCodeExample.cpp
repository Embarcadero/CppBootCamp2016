//---------------------------------------------------------------------------
#pragma hdrstop

#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include "NewCodeExample.h"
#include "Foo.h"

//---------------------------------------------------------------------------
void Test(const Foo& foo) {
	foo.DoSomething();
}

void DoStuff() {
	std::vector<int> items {1, 2, 5};

	std::map<int, std::wstring> map {
		{1, L"One"},
		{2, L"Two"},
		{3, L"Three"}
	};

	std::wcout << L"Test some map (key - value) access:" << std::endl;
	std::wcout << L"Item 2 is " << map[2] << std::endl;
	std::wcout << L"Item 5 is " << map[5] << std::endl;
	std::wcout << std::endl;

	// Demonstrate an algorithm - now use a lambda
	// Less code (get rid of an entire struct!) and see logic in place
    std::wcout << L"Look up map items from a vector:" << std::endl;
	for_each(items.begin(), items.end(),
		[&map](int n) { std::wcout << L"Entry " << n << L"=" << map[n] << std::endl; });

	std::wcout<< std::endl;

	// Print all vector items
	std::wcout << L"All vector items:" << std::endl;
	for (auto i : items) {
		std::wcout << i << std::endl;
	}
	std::wcout << std::endl;

	// Create and do something with a Foo, then destroy it
	{ // This new block is just for demonstration...
		std::unique_ptr<Foo> foo(new Foo());
		Test(*foo);
	} // ... because the Foo object will be destroyed here.
	// Try making two shared_ptr<>s, both referring to the same Foo object,
	// but making the shared_ptr<>s themselves destroy at different times.
	// Watch when the Foo object is actually deleted.
}
