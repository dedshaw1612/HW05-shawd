#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes) {
	this->num_edges = (num_nodes*(num_nodes-1))/2;//mentioned in reading. V(V-1)/2, but may not be correct
	//doubley nested for loop to go through and initialize all the spaces?
	for(int i = 0;i < this->M.size();i++) {
		for(int j = 0;j < this->M[0].size();j++) {
			M[i][j] = EdgeWeight();

		}//end i for loop
	}//end j for loop

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	this->M[u][v] = weight;
	this->M[v][u] = weight;//needed if this is an undirected graph b/c they 
	//are symmetrical 
}

unsigned MatrixGraph::numEdges() const {
	unsigned eCnt = 0;
	for(int i = 0;i < this->M.size();i++) {
		for(int j = 0;j < this->M[0].size();j++) {
			if(this->M[i][j] > 0.0)
				eCnt++;

		}
	}
	return eCnt;

}

unsigned MatrixGraph::degree(NodeID u) const {
	unsigned degree = 0;
	for(int i = 0;i < this->M.size();i++) {
		if(M[u][i] > 0.0)
			degree++;
	}

	return degree;
}