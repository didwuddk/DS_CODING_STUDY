#include <vector>
#include <limits> // INF표현하기 위해서
#include <algorithm>
#define MAX 5

using std::vector;

int n;
double dist[MAX][MAX];
const double INF = std::numeric_limits<double>::infinity();

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	if (path.size() == n) return currentLength + dist[path[0]][path.back()];
	double ret = INF;
	for (int next = 0; next < n; ++next) {
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;

		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = std::min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}