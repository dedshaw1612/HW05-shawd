#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes) {
	this->num_edges = (num_nodes*(num_nodes-1))/2;//mentioned in reading. V(V-1)/2

}