//============================================================================
//
//% Student Name 1: Oluwalayomi Dele-Dare
//% Student 1 #: 301136462
//% Student 1 userid (email): ldeledar (ldeledar@sfu.ca)
//
//% Student Name 2: Takudzwa Mhonde
//% Student 2 #: 301270018
//% Student 2 userid (email): tmhonde (tmhonde@sfu.ca)
//
//% Below, edit to list any people who helped you with the code in this file,
//%      or put �none� if nobody helped (the two of) you.
//
// Helpers: _everybody helped us/me with the assignment (list names or put �none�)__
//
// Also, list any resources beyond the course textbook and the course pages on Piazza
// that you used in making your submission.
//
// Resources:  ___________
//
//%% Instructions:
//% * Put your name(s), student number(s), userid(s) in the above section.
//% * Enter the above information in any other files you are also submitting.
//% * Edit the "Helpers" line and "Resources" line.
//% * Your group name should be "P3_<userid1>_<userid2>" (eg. P3_stu1_stu2)
//% * Form groups as described at:  https://courses.cs.sfu.ca/docs/students
//% * Submit files to courses.cs.sfu.ca
//
// Name        : Directory.hpp
// Description : Course Project Part 3 (Directory Tree)
//============================================================================


#ifndef SRC_DIRECTORY_HPP_
#define SRC_DIRECTORY_HPP_

#include "TreeNode.hpp"
#include <iomanip>
#include <string>
#include <vector>

class Directory : public ensc251::TreeNode
{
	typedef std::vector<std::string> stringVect;

	private:
		std::string dir_name;
		stringVect file_names;

	public:
		Directory(std::string m_dir_name): dir_name(m_dir_name) {}
		Directory(std::string m_dir_name, stringVect m_file_names): dir_name(m_dir_name), file_names(m_file_names) {}
		Directory(const Directory& nodeToCopy) : TreeNode(nodeToCopy), dir_name(nodeToCopy.dir_name), file_names(nodeToCopy.file_names)
		{

		}
		virtual Directory* clone() const { return new Directory(*this);};
		void set_dir_name(const std::string& m_dir_name){  dir_name = m_dir_name;}
		const std::string & get_dir_name() { return dir_name; }
		void add_file(const std::string& m_fileName) { file_names.push_back(m_fileName); }
		void add_multiple_files(const stringVect& m_files) { file_names.insert(file_names.end(), m_files.begin(), m_files.end()); }
		const stringVect & get_files() const { return file_names; }

		TreeNode* print_action()
		{
			// Do not modify insertion on OUT in this member function!
			OUT << std::setw(20) << dir_name+"\t|" << " ";
			OUT << this->childPVector.size() << "  ";
			for (auto file : file_names)
			{
				OUT << "  -" << file;
			}
			OUT << std::endl;
		    return nullptr;
		}

		void print_traverse(const TreeNode*)
		{
			// ***** this needs work *****
			if (childPVector.size() == 2)
			{
				traverse_children_in_order(
						static_cast<ensc251::traverse_func>(print_traverse),
						static_cast<ensc251::action_func>(print_action));
			}
			else if (childPVector.size() < 2)
			{
				traverse_children_post_order(
						static_cast<ensc251::traverse_func>(print_traverse),
						static_cast<ensc251::action_func>(print_action));
			}
			else
			{
				traverse_children_pre_order(
						static_cast<ensc251::traverse_func>(print_traverse),
						static_cast<ensc251::action_func>(print_action));
			}
		}
};

#endif /* SRC_DIRECTORY_HPP_ */
