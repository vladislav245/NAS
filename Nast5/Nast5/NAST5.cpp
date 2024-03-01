#include <list>
#include <fstream>
#include "Error.cpp"

using namespace std;

namespace B {

	ifstream* f1(string path) {

		ifstream* FILE = new ifstream(path);

		string result;
		int i = 0;
		while (true) {

			if (path[i] == '.') {
				break;
			}

			result += path[i];
			i++;
		}

		if (result == "file") {
			A::error1 er1("f1");
			throw(er1.name());
		}

		if (path.substr(i + 1) == "txt") {
			A::error er("f1");
			throw(er.name());
		}

		return FILE;
	}



	void f2(ifstream* file, string& buffer, int count) {

		char symbol;
		int pos = 0;

		if (count == 1) {
			while (file->get(symbol)) {
				buffer += symbol;

				pos = file->tellg();

				if (pos == 10) {
					A::error2 er2("f2");
					throw(er2.position1(10));
				}
				if (pos == 50) {
					A::error2 er2("f2");
					throw(er2.position2(50));
				}
			}
		}
		else {
			char* f = new char[count + 1];
			while (file->read(f, count)) {
				f[count] = '\0';
				buffer += f;

				pos = file->tellg();


				if (pos == 10) {
					A::error2 er2("f2");
					throw(er2.position1(10));
				}
				if (pos == 50) {
					A::error2 er2("f2");
					throw(er2.position2(50));
				}
			}
		}

		file->clear();
		file->seekg(pos);
	}


	void f3(ifstream* file) {

		int pos = file->tellg();

		if (pos > 300) {
			A::error er("f3");
			throw(er.position(pos));
		}
		file->close();
	}
}

void FuncHandle(int count, string name) {


	try {
		ifstream* f = B::f1(name);
		string str;
		B::f2(f, str, count);
		B::f3(f);

		cout << name << " - no error" << endl;
	}
	catch (string error) {
		cout << error << endl;
	}
	catch (int error) {
		cout << "pos " << error << endl;
	}

	cout << endl;
}





int main() {
	setlocale(LC_ALL, "Russian");


	FuncHandle(1, "f.txt");  // type = txt
	FuncHandle(1, "file.docx"); // name = file
	FuncHandle(1, "file2.docx"); // pos == 10 || pos == 50
	FuncHandle(3, "file2.docx"); // pos > 300


	return 0;
}