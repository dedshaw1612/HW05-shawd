#include "MatrixGraph.h"
using namespace std;

//NOTE: LOGIC MAYBE INCORRECT REGARDING THE SIZE OF M! M.SIZE() AND M[0].SIZE() MAY NOT BE
//THE CORRECT WAY TO FIND THE # OF ROWS/COLS, BE SURE TO CHECK THIS LATER!!!

MatrixGraph::MatrixGraph(unsigned num_nodes) {
	
	num_edges = (num_nodes*(num_nodes-1))/2;//V(V-1)/2
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
	
}

unsigned MatrixGraph::numEdges() const {
	unsigned eCnt = 0;
	for(int i = 0;i < M.size();i++) {
		for(int j = 0;j < M[0].size();j++) {
			if(M[i][j] > 0.0)
				eCnt++;
		}
	}
	return eCnt;
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
	return (pow((double)M.size(),2));//*this->M[0].size());//?? assuming M.size() & M[0].size() works
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {
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



