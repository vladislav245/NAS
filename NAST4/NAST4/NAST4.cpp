#include <list>
#include "Comp.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	int number = 0;

	cout << "������� ������� ��������" << endl;
	cin >> number;

	while (number > 0) {

		int index = 0;
		cout << "������ ���� �������� ����� ���������" << endl;
		cin >> index;

		cout << "�����" << endl;
		string author;
		cin >> author;
		
		Comp::Add(Comp(author), index);
		--number;
	}


	cout << "������� ������� ��������" << endl;

	cin >> number;

	while (number > 0) {

		int index = 0;
		cout << "������ ����� ��������� �������" << endl;
		cin >> index;

		Comp::Del(index);
		
		--number;
	}

	Comp::GetInfo();


	return 0;
}