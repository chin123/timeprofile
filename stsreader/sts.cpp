#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

#include "sts.h"

std::unordered_map<int, std::string> idMap(std::string filename) {
	std::string s;
	std::ifstream ifile(filename);
	std::unordered_map<int, std::string> toret;

	while (ifile >> s) {
		if (s == "CHARE") {
			std::string t = "", f = "";
			int id;
			ifile >> id;
			while (t[t.size() - 1] != '\"') {
				ifile >> t;
				f += t + " ";
			}
			toret[id] = f;
		}
	}
	return toret;
}
