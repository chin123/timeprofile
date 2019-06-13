#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

struct method {
	int id;
	int starttime;
	int endtime;
};

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error! Usage: ./cg <binsize>" << std::endl;
		return 0;
	}
	int binsize = std::stoi(argv[1]);
	int globalstarttime = -1;
	int globalendtime = -1;
	method m;
	std::vector<method> methods;
	while (std::cin >> m.id) {
		std::cin >> m.starttime >> m.endtime;
		if (globalstarttime == -1 || m.starttime < globalstarttime) {
			globalstarttime = m.starttime;
		}
		if (m.endtime > globalendtime) {
			globalendtime = m.endtime;
		}
		methods.push_back(m);
	}
	std::unordered_map<int, std::vector<int> > methodTimes;
	for (method m: methods) {
		methodTimes[m.id].resize((globalendtime - globalstarttime)/binsize, 0);
	}
	for (int i = 0; i < methods.size(); i++) {
		method m = methods[i];
		for (int j = globalstarttime; j <= globalendtime; j += binsize) {
			int timeinbucket;
			if (j > m.endtime || j + binsize < m.starttime) {
				timeinbucket = 0;
			} else {
				timeinbucket = m.endtime - m.starttime;
				if (m.endtime > j + binsize) {
					timeinbucket -= m.endtime - (j + binsize);
				}
				if (m.starttime < j) {
					timeinbucket -= j - m.starttime;
				}
			}
			methodTimes[m.id][(j - globalstarttime)/binsize] += timeinbucket;
			if (timeinbucket != 0) {
				std::cerr << "adding time " << timeinbucket << std::endl;
			}
		}
	}
	int noBins = (globalendtime - globalstarttime)/binsize; 
	for (int i = 0; i < noBins; i++) {
		std::cout << (float) (globalstarttime + i*binsize)/(1000*1000) << ' '; //output in seconds
		for (auto kv: methodTimes) {
			std::cout << kv.second[i] << ' ';
		}
		std::cout << std::endl;
	}
	/*
	for (auto kv: methodTimes) {
		int mid = kv.first;
		std::cout << mid << ", ";
		for (int j = 0; j < methodTimes[mid].size(); j++) {
			std::cout << methodTimes[mid][j];
			if (j != methodTimes[mid].size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
	*/
	
	return 0;
}
