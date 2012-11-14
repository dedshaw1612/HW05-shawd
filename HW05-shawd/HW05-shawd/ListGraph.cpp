#include "ListGraph.h"

//		typedef std::list<NWPair> EList; doubly linked lest of NWPairs
//		std::vector<EList> edgeList;

ListGraph::ListGraph(int numNodes) {
	for(int i = 0;i<numNodes;i++) {
		//this->edgeList
	}
}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	NWPair nw = NWPair();
	nw.first = v;
	nw.second = weight;
	this->edgeList[u].push_back(nw);
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	EList::pointer i;
	this->edgeList[u].begin();
	


	for(i = this->edgeList[u].begin();i != this->edgeList[u].end();++i) {
	}


	return this->edgeList[u]._Nextnode(v);
}

