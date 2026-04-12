#include <queue>

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howmany(n-1,0);
	priority_queue<pair<long double, int>> pq;
	for(int i=0;i<arr.size()-1;i++){
		pq.push({arr[i+1]-arr[i], i});
	}

	for(int i=1;i<=k;i++){
		auto tp = pq.top();pq.pop();
		int secIdx = tp.second;
		howmany[secIdx]++;
		long double inisum = arr[secIdx+1]-arr[secIdx];
		long double secsum = inisum/(long double)(howmany[secIdx]+1);
		pq.push({secsum, secIdx});
	}

	return pq.top().first;
}
