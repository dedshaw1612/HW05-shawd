#include "MatrixGraph.h"
using namespace std;

//NOTE: LOGIC MAYBE INCORRECT REGARDING THE SIZE OF M! M.SIZE() AND M[0].SIZE() MAY NOT BE
//THE CORRECT WAY TO FIND THE # OF ROWS/COLS, BE SURE TO CHECK THIS LATER!!!

MatrixGraph::MatrixGraph(unsigned num_nodes) {
	
	num_edges = 0;//(num_nodes*(num_nodes-1))/2;//V(V-1)/2
	M.resize(num_nodes);
	for(int i = 0;i < num_nodes;i++) 
		{        
			M[i].assign(num_nodes,0.0f);
		}//end i for loop
}

	MatrixGraph::~MatrixGraph() {

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	M[u][v] = weight;
	M[v][u] = weight;//needed b/c this is an undirected graph and they are symmetrical
	num_edges++;
	
}

unsigned MatrixGraph::numEdges() const {
	return num_edges;
	/*
	unsigned eCnt = 0;
	unsigned size1 = M.size();
	unsigned size2 = M[0].size();
	for(int i = 0;i < M.size();i++) {
		for(int j = 0;j < M[0].size();j++) {
			if(M[i][j] > 0.0)
				eCnt++;
		}
	}
	return eCnt;
	*/
}

unsigned MatrixGraph::degree(NodeID u) const {
	unsigned degree = 0;
	for(int i = 0;i < M.size();i++) {
		if(M[u][i] > 0.0)
			degree++;
	}
	return degree;
}

unsigned MatrixGraph::size() const {
	return M.size();
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	return M[u][v];
}

EList MatrixGraph::getAdj(NodeID u) const {
	std::list<NWPair> adj = new std::list<NWPair>();
	NWPair adjNode = NWPair();
	for(int i = 0;i < M.size();i++) {
		if(M[u][i] > 0.0) {
			adjNode.first = i;
			adjNode.second = M[u][i];
			adj.push_front(adjNode);
		}
	}
	return adj;
}



