#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ios>

struct method {
	int id;
	int starttime;
	int endtime;
};

int main(int argc, char *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cerr << "program start" << std::endl;
	std::vector<method> methods;
	std::string line;

	// ignore the first line
	std::getline(std::cin, line);

	for (; std::getline(std::cin, line);) {
		std::stringstream ss(line);
		int eventID;
		ss >> eventID;
		if (eventID == 2 || eventID == 3) {
			int temp, chareID, time;
			ss >> temp;
			ss >> chareID;
			ss >> time;
			if (eventID == 2) {
				method m;
				m.id = chareID;
				m.starttime = time;
				methods.push_back(m);
			} else {
				methods[methods.size() - 1].endtime = time;
			}

		}
	}

	// remove last method which doesn't end executing
	if (!methods.empty())
		methods.pop_back();

	for (method m: methods) {
		std::cout << m.id << ' ' << m.starttime << ' ' << m.endtime << std::endl;
	}
	std::cerr << "program end" << std::endl;
	return 0;
}
