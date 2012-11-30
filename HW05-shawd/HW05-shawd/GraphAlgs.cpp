#include "GraphAlgs.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
 
using namespace std;

Tour answer_;


EdgeWeight pathDist(Graph* G,int* arr, unsigned n) {
	EdgeWeight path = 0.0;
	for(unsigned i=0;i<n-1;i++) {
		path += G->weight(arr[i],arr[i+1]);
	}
	path += G->weight(arr[n-1],arr[0]);
	return path;
}

void tour(Graph* G,int* arr, int n, int startingPoint) {
	//pathDist is the distance of the best path, here we intialize it to whatever we're handed
	EdgeWeight pathDistance;
	int* path;
	path = new int[n];
	path = arr;
	for(int i = 0;i<n;i++) {
		answer_.first[i] = arr[i];
	}
	if(n - startingPoint == 1) {
		//check if arr is better than best tour
		pathDistance = pathDist(G,arr,n);
		//answer_.second = this->pathDist(G,arr,n);
		if(answer_.second > pathDistance) {
			answer_.second = pathDistance;
			for(int i = 0;i<n;i++) {
				answer_.first[i] = arr[i];
			}
		}
	}
	else {
		
		for(int i = startingPoint; i < n; i++) {
			swap(arr[startingPoint],arr[i]);
			tour(G,arr,n,startingPoint+1);
			swap(arr[startingPoint],arr[i]);//cleanup, put everything back where it was
		}
	}
	

}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G) {
	EList nodes = G->getAdj(0);
	NWPair fst(0,0.0);
	nodes.push_back(fst);
	
	
	EList::const_iterator it;
	//unsigned n = nodes.size();
	int n = G->size();
	int* arr;
	arr = new int[n];

	answer_.first.resize(n);
	
	int i = 0;
	
	for(it = nodes.begin(); it != nodes.end();it++) {
		arr[i] = it->first;
		i++;
	}

	answer_.second = pathDist(G,arr,n);
	tour(G,arr,n,0);
	//vector<pair<vector<NodeID>,EdgeWeight> > permuations;
	//pair<vector<NodeID>,EdgeWeight> ans;
	
	return answer_;

}