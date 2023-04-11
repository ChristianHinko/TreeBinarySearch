# TreeBinarySearch

This project implements a generic binary search tree and demonstrates some recursive algorithms on it.

The demonstrated tree is populated with integers and then algorithms for counting number of total leaves and nodes are run as well as an algorithm for getting the tree height.

## Design

The goal for this binary search tree implementation was to make it generic and have its functionality broken up into many helpful functions.

Tree implementations can easily fall into having duplicate code dispersed throughout their code for accessing children nodes. CTHTreeBinarySearch<> provides GetDeepestNode() along with GetAppropriateChildNodePointerRef() for avoiding this pitfall. The Add() function uses these to assign the child-most reference to the new node. The Remove() function uses this for removing the child-most node.

A problem faced was having nodes cache references to their parent nodes. These extra pointers are redundant but are important for quick access to parent nodes. To have these extra pointers automatically nulled when their pointee is destroyed, we utilize smart pointers. We make the important pointers shared pointers while the extra, cached pointers are weak pointers. When all shared references are gone, the node is automatically destroyed and all weak references are nulled.
