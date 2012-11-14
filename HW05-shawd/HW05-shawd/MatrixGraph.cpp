#include "MatrixGraph.h"

//NOTE: LOGIC MAYBE INCORRECT REGARDING THE SIZE OF M! M.SIZE() AND M[0].SIZE() MAY NOT BE
//THE CORRECT WAY TO FIND THE # OF ROWS/COLS, BE SURE TO CHECK THIS LATER!!!

MatrixGraph::MatrixGraph(unsigned num_nodes) {
	this->num_edges = 0;//?this->numEdges(); took out function call, cant construct using non-existant info!
		//(num_nodes*(num_nodes-1))/2;//mentioned in reading. V(V-1)/2, but may not be correct
	//doubley nested for loop to go through and initialize all the spaces?
	for(int i = 0;i < num_nodes;i++) {
		for(int j = 0;j < num_nodes;j++) {
			M[i][j] = 0.0;//EdgeWeight();//no idea if this is right.

		}//end i for loop
	}//end j for loop
}

MatrixGraph::~MatrixGraph() {

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

unsigned MatrixGraph::size() const {
	return (this->M.size()*this->M[0].size());//?? assuming M.size() & M[0].size()
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {
	std::list<NWPair> adj = std::list<NWPair>();
	NWPair adjNode = NWPair();
	for(int i = 0;i < this->M.size();i++) {
		if(M[u][i] > 0.0) {
			adjNode.first = i;
			adjNode.second = M[u][i];
			adj.push_front(adjNode);
		}
	}
	return adj;
}



