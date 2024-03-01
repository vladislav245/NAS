#include <iostream>

using namespace std;

namespace A {


    class error {


    public:
        string func;
        error(string func) {
            this->func = func;
        }

        string name() {
            cout << func << endl;
            return "Error - txt";
        }

        int position(int pos) {
            cout << func << endl;
            return pos;
        }
    };


    class error1 : public error {

    public:

        error1(string func) : error(func) {

        }

        string name() {
            cout << func << endl;
            return "Error - file";
        }

    };



    class error2 : public error {

    public:

        error2(string NameFunc) : error(NameFunc) {

        }

        int position1(int pos) {
            cout << func << endl;
            return pos;
        }
        int position2(int pos) {
            cout << func << endl;
            return pos;
        }
    };
}