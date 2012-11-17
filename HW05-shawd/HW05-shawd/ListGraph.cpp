#include "ListGraph.h"

//		typedef std::list<NWPair> EList; doubly linked lest of NWPairs
//		std::vector<EList> edgeList;

ListGraph::ListGraph(int numNodes) {
	edgeList.resize(numNodes);
	num_edges = 0;
	
}

ListGraph::~ListGraph() {

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	NWPair nw1 = NWPair();
	NWPair nw2 = NWPair();//NWPair* nw = new NWPair();
	nw1.first = v;
	nw1.second = weight;
	nw2.first = u;
	nw2.second = weight;
	edgeList[u].push_front(nw1);
	edgeList[v].push_front(nw2);

	num_edges++;
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
	return num_edges;
	/*
	EList::const_iterator j;
	unsigned numE = 0;
	//loop through the vector, and count the number of pairs in the list.
	for(int i = 0;i < edgeList.size();i++) {
		numE += edgeList[i].size();
	}
	return numE;
	*/
}

unsigned ListGraph::size() const {
	return edgeList.size();//(pow((double)edgeList.size(),2));
}


