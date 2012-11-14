// MatrixGraph.h

#include <vector>
#include "Graph.h"

#pragma once

typedef std::list<NWPair> EList;
//A list of NWPairs or pairs which contain <NodeID,EdgeWeight>
//which are defined as <unsigned int,double>

class MatrixGraph : public Graph {
 public:
  MatrixGraph(unsigned num_nodes);
  ~MatrixGraph();

  // Modifiers
  virtual void addEdge(NodeID u, NodeID v, EdgeWeight weight);
  
  // Inspectors
  //EdgeWeight is a double
  virtual EdgeWeight weight(NodeID u, NodeID v) const;
  virtual std::list<NWPair> getAdj(NodeID u) const;
  //getAdj returns a pair<unsigned int, double> 
  //which is a NWPair:   <NodeID, EdgeWeight>


  virtual unsigned degree(NodeID u) const;
  virtual unsigned size() const;
  virtual unsigned numEdges() const;

 private:
  MatrixGraph() {;}

  //an X by Y matrix of edgeweights
  std::vector<std::vector<EdgeWeight> > M;
  int num_edges;
};
