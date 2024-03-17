#pragma once

#include<iostream>
#include<string>
#include<locale>
#include<list>

class Comp {
public:
	Comp();
	Comp(std::string brand) { this->brand = brand; };
	void Input();
	void Output() const;
	void Get_brand() const { std::cout << brand << std::endl; };

	static void Add(const Comp obj, int index);
	static void Del(int index);
	static void GetInfo();

	~Comp() { };

	static std::list<Comp*> StorageComp;

	std::string brand;
private:
	int memorySize;


	friend std::ostream& operator << (std::ostream& os, const Comp* obj);
};