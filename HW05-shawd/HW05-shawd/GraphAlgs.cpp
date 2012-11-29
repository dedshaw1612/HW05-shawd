#include "GraphAlgs.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
 
using namespace std;

EdgeWeight pathDist(Graph* G,int* arr, int n) {
	EdgeWeight path = 0.0;
	for(int i=0;i<n-1;i++) {
		path += G->weight(arr[i],arr[i+1]);
	}
	path += G->weight(arr[n-1],arr[0]);
	return path;
}

void GraphAlgs::tour(Graph* G,int* arr, int n, int startingPoint) {
	//pathDist is the distance of the best path, here we intialize it to whatever we're handed
	EdgeWeight pathDist;
	int* path = new int[n];
	path = arr;
	if(n - startingPoint == 1) {
		//check if arr is better than best tour
		pathDist = this->pathDist(G,arr,n);
		//answer_.second = this->pathDist(G,arr,n);
		if(answer_.second > pathDist) {
			answer_.second = pathDist;
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

std::pair<std::vector<NodeID>, EdgeWeight> GraphAlgs::TSP(Graph* G) {
	int n = G->size();
	int* arr = new int[n];
	EList::const_iterator it;
	for(it = G->getAdj(0).begin(); it != G->getAdj(0).end();it++) {
		int i = 0;
		arr[i] = it->first;
		i++;
	}
	answer_.second = this->pathDist(G,arr,n);
	tour(G,arr,n,0);
	//vector<pair<vector<NodeID>,EdgeWeight> > permuations;
	pair<vector<NodeID>,EdgeWeight> ans;
	
	return answer_;

}