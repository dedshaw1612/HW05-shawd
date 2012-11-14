// listGraph.h

#include <vector>
#include "Graph.h"

#pragma once

//doubly linked list of NWPairs
typedef std::list<NWPair> EList;

class ListGraph : public Graph {
 public:
  ListGraph(int numNodes);
  ~ListGraph();

  // Modifiers
  virtual void addEdge(NodeID u, NodeID v, EdgeWeight weight);
  
  // Inspectors
  virtual EdgeWeight weight(NodeID u, NodeID v) const;
  virtual std::list<NWPair> getAdj(NodeID u) const;
  virtual unsigned degree(NodeID u) const;
  virtual unsigned size() const;
  virtual unsigned numEdges() const;

 private:
  ListGraph() {;}

  //an array of doubly linked lists which contain NWPairs
  /*
  Figure 17.10 from reading
  0[]->[6]->[5]->[1]->[2]
  1[]->[0]
  2[]->[0]
  3[]->[5]->[4]
  4[]->[6]->[5]->[3]
  5[]->[3]->[0]->[4]
  .
  .
  ect

  */
  std::vector<EList> edgeList;
  int num_edges;
};
