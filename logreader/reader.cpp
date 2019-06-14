#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ios>
#include <cstdio>

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
	char *line = new char[1000];
	size_t bufsize = 1000;

	// ignore the first line

	method m;
	while (getline(&line, &bufsize, stdin) != -1) {
		/*std::stringstream ss(line);

		int eventID;
		ss >> eventID;*/
		int eventID, temp, chareID, time;
		sscanf(line, "%d %d %d %d", &eventID, &temp, &chareID, &time);
		if (eventID == 2 || eventID == 3) {
			/*int temp, chareID, time;
			ss >> temp;
			ss >> chareID;
			ss >> time;*/
			if (eventID == 2) {
				m.id = chareID;
				m.starttime = time;
			} else {
				m.endtime = time;
				std::cout << m.id << ' ' << m.starttime << ' ' << m.endtime << std::endl;
			}

		}
	}

	std::cerr << "program end" << std::endl;
	return 0;
}
