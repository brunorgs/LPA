#include <iostream>
#include <sstream>

using namespace std;

int mod(string line, int a) {

        int result = 0;

        for(int i = 0; i < line.length(); i++) {

                result = (result * 10 + (line[i] - '0')) % a;

        }

        return result;
}


bool isLeapYear(string year) {

	bool a = mod(year,4) == 0 && mod(year,100) != 0;
	bool b = mod(year,400) == 0;

	return a || b;
}

bool isHuluculuYear(string year) {
	return mod(year,3) == 0 && mod(year,5) ==0;
}

bool isBulukuluYear(string year) {
	return mod(year,5) == 0 && mod(year,11) == 0 && isLeapYear(year);
}

bool isOrdinaryYear(string year) {
	return !(isLeapYear(year) || isHuluculuYear(year) || isBulukuluYear(year));
}

int main() {
	
	std::string line;
	bool first = true;

	while(std::getline(cin, line)) {

		if(first == false) {
			cout << "\n";
		}


		if(isLeapYear(line)) {
			cout << "This is leap year.\n";
		}

		if(isHuluculuYear(line)) {
			cout << "This is huluculu festival year.\n";
		}

		if(isBulukuluYear(line)) {
			cout << "This is bulukulu festival year.\n";
		}

		if(isOrdinaryYear(line)) {
			cout << "This is an ordinary year.\n";
		}

		first = false;	

	}


	return 0;
}
