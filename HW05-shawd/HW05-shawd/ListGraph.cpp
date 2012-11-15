#include "ListGraph.h"

//		typedef std::list<NWPair> EList; doubly linked lest of NWPairs
//		std::vector<EList> edgeList;

ListGraph::ListGraph(int numNodes) {
	for(int i = 0;i<numNodes;i++) {
		//this->edgeList
	}
}

ListGraph::~ListGraph() {

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	NWPair nw = NWPair();//NWPair* nw = new NWPair();
	nw.first = v;
	nw.second = weight;
	this->edgeList[u].push_back(nw);
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	EList::const_iterator i;

	for( i = edgeList[u].begin();i != edgeList[u].end();i++) {
		if(i->first == v)
			return i->second;
	}
	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const {
	EList::const_iterator i;
	std::list<NWPair> adj = std::list<NWPair>();
	NWPair adjNode = NWPair();
	for(i = edgeList[u].begin();i != edgeList[u].end();i++) {
		if(i->second > 0.0) {
			adjNode.first = i->first;
			adjNode.second = i->second;
			adj.push_front(adjNode);
		}
	}
	return adj;
}

unsigned ListGraph::degree(NodeID u) const {
	unsigned degree = 0;
	EList::const_iterator i;
	for(i = edgeList[u].begin();i != edgeList[u].end();i++) {
		if(i->second > 0.0) 
			degree++;
	}
	return degree;
}

unsigned ListGraph::numEdges() const {
	EList::const_iterator j;
	unsigned numE = 0;
	//loop through the vector, and count the number of pairs in the list.
	for(int i = 0;i < edgeList.size();i++) {
		numE += edgeList[i].size();
	}
	return numE;
}

unsigned ListGraph::size() const {
	return (pow((double)edgeList.size(),2));
}


