#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cstdio>

#include "creategraph.h"

std::unordered_map<int, std::vector<int>> getTimes(int binsize) {
	int globalstarttime = -1;
	int globalendtime = -1;
	method m;
	std::vector<method> methods;
	while (scanf("%d", &m.id) != EOF) {
		scanf("%d %d", &m.starttime, &m.endtime);
		if (globalstarttime == -1 || m.starttime < globalstarttime) {
			globalstarttime = m.starttime;
		}
		if (m.endtime > globalendtime) {
			globalendtime = m.endtime;
		}
		methods.push_back(m);
	}
	std::cout << "finished first loop" << std::endl;
	std::unordered_map<int, std::vector<int> > methodTimes;
	for (method m: methods) {
		methodTimes[m.id].resize((globalendtime - globalstarttime)/binsize, 0);
	}
	std::cout << "finished second loop" << std::endl;
	for (int i = 0; i < methods.size(); i++) {
		method m = methods[i];
		for (int j = m.starttime; j <= m.endtime; j += binsize) {
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
		}
	}
	std::cout << "finished third loop" << std::endl;
	int noBins = (globalendtime - globalstarttime)/binsize; 
	/*for (auto kv: methodTimes) {
		int mid = kv.first;
		for (int j = 0; j < methodTimes[mid].size(); j++) {
			std::cout << methodTimes[mid][j];
		}
		std::cout << std::endl;
	}*/
	return methodTimes;
}
