//============================================================================
//
//% Student Name 1: Layomi Dele-Dare
//% Student 1 #: 301136462
//% Student 1 userid (email): ldeledar (ldeledar@sfu.ca)
//
//% Student Name 2: Takudzwa Mhonde
//% Student 2 #: 301270018
//% Student 2 userid (email): tmhonde (tmhonde@sfu.ca)
// Name        : TreeNode.hpp
// Description : Course Project Part 3 (Directory Tree)
//============================================================================

#ifndef USE_OSS
#define OUT std::cout
#else
#include <sstream>
extern std::ostringstream oss;
#define OUT oss
#endif

#ifndef SRC_TREENODE_HPP_
#define SRC_TREENODE_HPP_

#include <iostream>
#include <vector>

//#define USE_OSS

#ifndef USE_OSS
#define OUT std::cout
#else
#include <sstream>
extern std::ostringstream oss;
#define OUT oss
#endif

namespace ensc251 {

	static unsigned count = 0;

	class TreeNode;

	typedef TreeNode* (TreeNode::*action_func)(void);
	typedef void (TreeNode::*traverse_func)(const TreeNode*);

	class TreeNode
	{
		typedef std::vector<TreeNode*> TreeNodePVect;

		protected:
			TreeNodePVect childPVector;

		public:
			TreeNode() {};
			TreeNode(const TreeNode& nodeToCopy) { 
				// ***** this needs work *****
				for ( auto childP : nodeToCopy.childPVector)
				{
					add_childP(childP->clone());
				}
			}

			virtual TreeNode* clone() const {
				return new TreeNode(*this);
			};

			virtual ~TreeNode() {
				// do not modify this insertion on OUT
				OUT << "Destroying TreeNode with " << childPVector.size() << " children."<< std::endl;
				// ***** Complete this member function *****
				for (auto childP : childPVector)
				{
					delete childP;
				}
				childPVector.clear();

			}

		    void swap(TreeNode & other) // the swap member function (should never fail!)
		    {
	    	// ***** fill this in if desired *****
//		    	TreeNode temp = other;
//		    	other.add_children(this->childPVector);
//		    	this->add_children(temp.childPVector);
		    	std::swap(this->childPVector, other.childPVector);
		    }

		    TreeNode & operator = (TreeNode other) // note: argument passed by value, copy made!
		    {
				// ***** Complete this code *****
//		    	std::swap(childPVector, other.childPVector);
		    	swap(other);
		    	       return *this; // by convention, always return *this
		    }

			void add_childP(TreeNode* child) {
				/* ***** Complete this member function ***** */
				childPVector.push_back(child);
			}
			void add_children(const TreeNodePVect& childPV) { childPVector.insert(childPVector.end(), childPV.begin(), childPV.end()); }
			const TreeNodePVect& get_children() const { return childPVector; }

			TreeNode* traverse_children_post_order(traverse_func tf, action_func af)
			{
			    for(auto childP : childPVector) {
			        (childP->*tf)(this); // traverse child's children using tf
			    }
			    return (this->*af)();
			}
			
			TreeNode* traverse_children_pre_order(traverse_func tf, action_func af)
			{
				// ***** Complete this member function *****
				(this->*af)();
				for(auto childP : childPVector) {
			        (childP->*tf)(this); // traverse child's children using tf
			    }

				return nullptr;
			}

			TreeNode* traverse_children_in_order(traverse_func tf, action_func af)
			{
				// ***** Complete this member function *****
				(childPVector[0]->*tf)(this);
				(this->*af)();
				(childPVector[1]->*tf)(this);
				return nullptr;
			}

			TreeNode* count_action()
			{
				count++;
				return nullptr;
			}

			void count_traverse(const TreeNode*)
			{
				traverse_children_post_order(count_traverse, count_action);
			}
			void reset_count() { count = 0; }
			unsigned get_count() const { return count; }

	};
}

#endif /* SRC_TREENODE_HPP_ */
