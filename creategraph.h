// include: vector, unordered_map

struct method {
	int id;
	int starttime;
	int endtime;
};

std::unordered_map<int, std::vector<int>> getTimes(int binsize);
