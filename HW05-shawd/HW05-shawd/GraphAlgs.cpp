/*
David Shaw
CSE 274 Final Homework
Attempted all goals except for drawing with cinder
*/

#include "GraphAlgs.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
 
using namespace std;

Tour answer_;

//Iterates through the array summing up pathes of nodes,
//and then calculates the distance between the end and the beggining
//to figure out the tour distance.
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
	EdgeWeight badBranch = 0.0;

	if(n - startingPoint == 1) {
		
		pathDistance = pathDist(G,arr,n);
		//check if arr is better than best tour, if so
		//update the best tour distance and the path
		if(answer_.second > pathDistance) {
			answer_.second = pathDistance;
			for(int i = 0;i<n;i++) {
				answer_.first[i] = arr[i];
			}
		}
	}

	else {

		/*The idea is whenever tour is called it looks at the path so far for all nodes
		and if at any point it ends up longer than the the shortest tour we exit out of the tour in that branch.
		This iterates through the entire path staring off with the first two nodes, then first 3 nodes, etc.
		and keeps adding up until it finds a bigger number or keeps touring.
		*/
		for(int i = 0;i < n-1;i++) {
			//optimized for speed. Used to be badBranch = pathDist() but the function
			//would be called every iteration and do most of the same calculations so
			//this seemed to me almost twice as fast as the function call.
			badBranch += G->weight(arr[i],arr[i+1]);
		
			if (badBranch > answer_.second)
				return;
		}
		
		//Otherwise, keep touring.
		for(int i = startingPoint; i < n; i++) {
			swap(arr[startingPoint],arr[i]);
			tour(G,arr,n,startingPoint+1);
			swap(arr[startingPoint],arr[i]);//cleanup, put everything back where it was
		}
	}
	

}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G) {
	//Create the list of nodes that we are looking at.
	EList nodes = G->getAdj(0);
	NWPair fst(0,0.0);
	nodes.push_back(fst);
	
	EList::const_iterator it;
	int n = G->size();
	int* arr;
	arr = new int[n];

	//initialize the answer path to the first array we find and the path from that array.
	answer_.first.resize(n);
	
	int i = 0;
	
	for(it = nodes.begin(); it != nodes.end();it++) {
		arr[i] = it->first;
		i++;
	}

	for(int i = 0;i<n;i++) {
		answer_.first[i] = arr[i];
	}

	answer_.second = pathDist(G,arr,n);
	

	//Start touring
	tour(G,arr,n,0);
	
	return answer_;

}