#include "bfs.hpp"

void graph::loaddata(const std::string &filename) {
	std::ifstream file(filename);
	std::string line;

	while (getline(file, line)) {
		std::istringstream iss(line);
		std::string movie, actor;
		iss >> movie;

		std::vector<std::string> actors;
		while (iss >> actor) {
			actors.push_back(actor);
		}

		for (const auto &a1: actors) {
			for (const auto &a2 : actors) {
				if (a1 != a2) {
					adjlist[a1].push_back({a2,movie});
				}
			}
		}
	}
}

std::vector<std::string> graph::findshortestpath(const std::string &actor1, const std::string &actor2) {
	if (adjlist.find(actor1) == adjlist.end() || adjlist.find(actor2) == adjlist.end()) {
		return {"Not present"};
	}

	std::unordered_map<std::string, std::pair<std::string, std::string>> parent;
	std::queue<std::string> q;

	parent[actor1] = {"",""};
	q.push(actor1);

	while(!q.empty()) {
		std::string curr = q.front();
		q.pop();
		
		if (curr == actor2) {
			break;
		}

		for (auto &[neighbor, movie]:adjlist[curr]) {
			if(parent.find(neighbor) == parent.end()) {
				parent[neighbor] = {curr, movie};
				q.push(neighbor);
			}
		}
	}

	if (parent.find(actor2) == parent.end()) {
		return {"Not present"};
	}

	std::vector<std::string> path;
	for (std::string at = actor2; !parent[at].first.empty(); at = parent[at].first) {
		path.insert(path.begin(), "-(" + parent[at].second + ")- " + at);
	}

	path.insert(path.begin(),actor1);
	//path.push_back(actor1);
	//std::reverse(path.begin(), path.end());
	return path;
}
