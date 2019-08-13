//============================================================================
//
//% Student Name : Takudzwa Mhonde
//% Student 1 #: 3012700198
//% Student 1 userid (email): tmhonde@sfu.ca
//
//% Student Name 2: Layomi Dele-Dare
//% Student 2 #: 301136462
//% Student 2 userid (email): stu2 : ldeledar@sfu
//
//// Name        : tokenClasses.hpp
// Description : Course Project Part 5 (Interpreting/Evaluation)
// Original portions Copyright (c) 2016 School of Engineering Science, Simon Fraser University
// Resources :  www.cplusplus.com
//============================================================================


#include <vector>
#include <sstream>
#include <algorithm>
#include "tokenClasses.hpp"
#include "Part1Tokenizer.hpp"

using namespace std;
using namespace ensc251;

// Construct token objects categorized into appropriate types
// Input: a stream
// Output: a vector containing the list of Token objects properly categorized

int token_identify(const std::string &s);
void check(std::vector<int> &v,const std::vector<std::string> &tokens);
template<typename T>
T convertTo(const std::string &s){
	T num = 0;
	stringstream convert(s);
	convert>>num;
	return num;
}

std::vector<ensc251::Token*> tokenClassifier(istream& code)
{
        std::vector<ensc251::Token*> tokenObjectPs;

        //tokenize the string first:
        std::vector<std::string> tokens = tokenizeCodeStrip(code);
        //classify the tokens soon after....

        //create a vector of int that has identities of each type of token
        //the integers are used to define certain types of tokens e.g. 1-punctuator

        std::vector<int> types_vec;
        auto size_tokens = tokens.size();

        //identify each token and push back the identity number into the int vector (type_vec)
        for(auto i = 0;i<size_tokens;i++){

            types_vec.push_back(token_identify(tokens[i]));
        }

        //make sure everything is fine in the vector
        //check changes the * punctuator to unary op (iff it meets the conditions)
        check(types_vec,tokens);

        //now assign the appropriate things to the vector
        auto size_types = types_vec.size();
        for(auto i = 0;i<size_types;i++){
        	if(types_vec[i] == 1){
        	//cout << "punctuator"<< endl;
        	//punctuator* t_p = new punctuator(tokens[i]);
        	tokenObjectPs.push_back(new punctuator(tokens[i]));
        	}
        	else if(types_vec[i] == 2){
        	//cout << "id" << endl;
        	//id* t_id = new id(tokens[i]);
        	tokenObjectPs.push_back(new id(tokens[i]));
        	}
        	else if(types_vec[i] == 3){
        	//cout << "type_spec" << endl;
        	//type_spec* t_spc = new type_spec(tokens[i]);
        	tokenObjectPs.push_back(new type_spec(tokens[i]));
        	}
        	else if(types_vec[i] == 4){
        	//cout << "Assignment operator" << endl;
        	//assignment_operator *t_as = new assignment_operator(tokens[i]);
        	tokenObjectPs.push_back(new assignment_operator(tokens[i]));
        	}
        	else if(types_vec[i]==5){
        	//cout << "Conditional operator" << endl;
        	//conditional_operator* t_co = new conditional_operator(tokens[i]);
        	tokenObjectPs.push_back(new conditional_operator(tokens[i]));
        	}
        	else if(types_vec[i]==6){
        	//cout << "Shift operator" << endl;
        	//shift_operator *t_so = new shift_operator(tokens[i]);
        	tokenObjectPs.push_back(new shift_operator(tokens[i]));
        	}
        	else if(types_vec[i]==7){
        	//cout << "Additive operator" << endl;
        	//additive_operator* t_ao = new additive_operator(tokens[i]);
        	tokenObjectPs.push_back(new additive_operator(tokens[i]));
        	}
        	else if(types_vec[i]==8){
        	//cout << "Div operator" << endl;
        	//div_operator* t_do = new div_operator(tokens[i]);
        	tokenObjectPs.push_back(new div_operator(tokens[i]));
        	}
        	else if(types_vec[i]==9){
        	//cout << "Unary operator" << endl;
        	//unary_operator *t_uo = new unary_operator(tokens[i]);
        	tokenObjectPs.push_back(new unary_operator(tokens[i]));
        	}
        	else if(types_vec[i]==10){
        	//cout << "Postfix Operator" << endl;
        	//postfix_operator *t_po = new postfix_operator(tokens[i]);
        	tokenObjectPs.push_back(new postfix_operator(tokens[i]));
        	}
        	else if(types_vec[i]==11){
        	//cout << "numeric_const<int>" << endl;
        	int n = convertTo<int>(tokens[i]);
        	//numeric_const<int> *t_nci = new numeric_const<int>(n);
        	tokenObjectPs.push_back(new numeric_const<int>(n));
        	}
        	else if(types_vec[i]==12){
        	//cout << "numeric_const<float>" << endl;
        	float n = convertTo<float>(tokens[i]);
        	//numeric_const<float> *t_ncf = new numeric_const<float>(n);
        	tokenObjectPs.push_back(new numeric_const<float>(n));
        	}
        	else if(types_vec[i]==13){
        	//cout << "numeric_const<char>" << endl;
        	char n = convertTo<char>(tokens[i]);
        	//numeric_const<char> *t_ncc = new numeric_const<char>(n);
        	tokenObjectPs.push_back(new numeric_const<char>(n));
        	}
        	else if(types_vec[i]==14){
        	//cout << "ensc251::string" << endl;
        	//ensc251::string *t_str = new ensc251::string(tokens[i]);
        	tokenObjectPs.push_back(new ensc251::string(tokens[i]));
        	}
        	else if(types_vec[i]==15){
        	//cout << "ensc251::string" << endl;
        	//ensc251::string *t_str = new ensc251::string(tokens[i]);
        	tokenObjectPs.push_back(new ensc251::incorrect(tokens[i]));
        	}
        }


        return tokenObjectPs;
}


int token_identify(const std::string &s){

    auto size = s.size();
    char c = '\0';

    if(size>0)//might mean there was an error somewhere if size < 1...
        c = s[0];
    else
    	return 15;

    //some tests...
    if (size == 1){
        //punctuator test
        if((c == '*' || c == ';' || c == ')' || c == '(' || c == ':'))
            return 1;

        //conditional operator test
        if(c == '?')
            return 5;

        //additive operator test
        if(c == '+' || c == '-')
            return  7;

        //div operator test
        if(c == '/' || c == '%')
            return  8;

        //unary operator test
        if(c == '&' || c == '~')
            return 9;
    }
    else if(size == 2)
    {
        //shift operator test
        if(s == "<<" || s == ">>")
            return  6;

        //post fix operator
        if(s == "++" || s == "--")
            return  10;

    }

    //do this regardless....

    //type_spec && id test
    if((c >64 && c < 91) || (c >96 && c <123) || c == '_'){
        if(s == "int"  || s == "float" ||  s== "char")
            return  3;
        else
            return  2;
        }

    //assignment operator test
    else if(s.find_first_of('=') < size)
        return  4;

    //numeric const<int /float>
    else if(c >47 && c <58)
    {
        //float test...
        if(s.find_first_of('E') < size || s.find_first_of('e') < size || s.find_first_of('.') < size)
            return 12;

        //int test...
        else
            return 11;
    }
    //constant char test
    else if(s.find_first_of('\'') < size)
        return 13;

    //constant string test
    else if(s.find_first_of('"') < size && size > 2)
        return 14;





    //return unknown goes to default
    return -1;
}
void check(vector<int> &v,const std::vector<std::string> &tokens){

    auto size = v.size();
    for(auto i=0;i<size;i++){
        //fill in here...
        //cout << "v_i "<< v[i] << "; tokens " << tokens[i] << endl;
        if(v[i] == 1 && tokens[i] == "*"){
          //check if previous one is an id
            if(v[i-1] == 3)
                //change v[i] from punctuator to unary operator
                v[i] = 9;
        }

    }
}
