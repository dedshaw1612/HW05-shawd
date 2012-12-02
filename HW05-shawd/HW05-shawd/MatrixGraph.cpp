#include "MatrixGraph.h"
using namespace std;

MatrixGraph::MatrixGraph(unsigned num_nodes) {
	
	num_edges = 0;
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
	std::list<NWPair> adj = std::list<NWPair>();
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



