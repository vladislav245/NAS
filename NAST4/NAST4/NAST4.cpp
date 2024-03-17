#include <list>
#include "Comp.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	int number = 0;

	cout << "Сколько создать объектов" << endl;
	cin >> number;

	while (number > 0) {

		int index = 0;
		cout << "Индекс куда добавить новый экземпляр" << endl;
		cin >> index;

		cout << "Марка" << endl;
		string author;
		cin >> author;
		
		Comp::Add(Comp(author), index);
		--number;
	}


	cout << "Сколько удалить объектов" << endl;

	cin >> number;

	while (number > 0) {

		int index = 0;
		cout << "Индекс какой экземпляр удалить" << endl;
		cin >> index;

		Comp::Del(index);
		
		--number;
	}

	Comp::GetInfo();


	return 0;
}