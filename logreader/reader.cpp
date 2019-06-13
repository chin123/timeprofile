#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct method {
	int id;
	int starttime;
	int endtime;
};

int main(int argc, char *argv[]) {
	std::vector< std::vector<method> > graph;
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
	methods.pop_back();

	for (method m: methods) {
		std::cout << m.id << ' ' << m.starttime << ' ' << m.endtime << std::endl;
	}

	/*
	int start = methods[0].starttime;
	int end = methods.back().endtime;
	int totaltime = end - start;
	graph.resize(totaltime/binsize + 1);
	for (method m: methods) {
		for (int i = m.starttime; i <= m.endtime; i += binsize) {
			graph[(i-start)/binsize].push_back(m);
		}
	}
	std::cout << start << std::endl;
	for (auto v: graph) {
		std::cout << v.size() << ' ';
		for (auto m: v) {
			std::cout << m.id << ' ';
		}
		std::cout << std::endl;
	}
	*/
	return 0;
}
