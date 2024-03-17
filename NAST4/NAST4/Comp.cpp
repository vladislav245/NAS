#include "comp.h"


std::list<Comp*> Comp::StorageComp;

Comp::Comp() {
	brand = "";
	memorySize = 0;
}

void Comp::Input() {
	std::cout << "----------------------------" << std::endl;
	std::cout << "Введите марку компьютера:" << std::endl;
	std::cin >> brand;
	std::cout << "Введите размер памяти:" << std::endl;
	std::cin >> memorySize;
}

void Comp::Output() const {
	std::cout << "Марка компьютера: " << brand << std::endl;
	std::cout << "Размер памяти: " << memorySize << std::endl;
}

void Comp::Add(const Comp obj, int index) {

	Comp* tmp = new Comp(obj);

	auto it = StorageComp.begin();

	while (it != StorageComp.end() && index != 0) {
		++it;
		index--;
	}


	StorageComp.insert(it, tmp);
}


void Comp::Del(int index) {

	auto it = StorageComp.begin();

	while (it != StorageComp.end() && index != 0) {
		++it;
		index--;
	}

	StorageComp.erase(it);
}

void Comp::GetInfo() {

	for (auto it = StorageComp.begin(); it != StorageComp.end(); it++) {
		(*it)->Output();
	}
}


std::ostream& operator << (std::ostream& os, const Comp* obj)
{
	return os << obj->brand;
}



