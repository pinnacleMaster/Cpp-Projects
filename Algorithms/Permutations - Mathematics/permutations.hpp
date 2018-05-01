/*
 * permutation.hpp
 *
 *  Created on: Apr 25, 2018
 *      Author: takudzwamhonde
 */

#ifndef PERMUTATION_HPP_
#define PERMUTATION_HPP_

template <typename T>
class Permutation {
public:
	Permutation(const std::vector<T> _C);
	void permute(); // a function that generates all the permutations of C.
	int numberOfPermutations(); // a function that returns the number of possible permutations
	std::vector<std::vector<T> > getPermutations() const;
private:
	void generate_distinct(const std::vector<T>& _C); // a function that generates a distinct "set of C".
	int factorial(const int& n) const;
	bool find(const T& e, const std::vector<T> E);
	void _permute(const std::vector<T>& s, const std::vector<T> S);
	std::vector<T> createSetWithoutElementAt(const int& cursor_pos, const std::vector<T>& S);
private:
	std::vector<T> C;
	std::vector<std::vector<T> > P; // collection of permutations.
};


template <typename T>
Permutation<T>::Permutation(const std::vector<T> _C){
	generate_distinct(_C);
}

template <typename T>
void Permutation<T>::permute(){
	std::vector<T> s;
	_permute(s, C);
}

template <typename T>
int Permutation<T>::numberOfPermutations(){
	int size = C.size();
	return factorial(size);
}

template <typename T>
std::vector<std::vector<T> > Permutation<T>::getPermutations() const{ return P; }

template <typename T>
void Permutation<T>::generate_distinct(const std::vector<T>& _C){
	for(auto c:_C){
		if(!find(c, C))
		{
			C.push_back(c);
		}
	}
}

template<typename T>
int Permutation<T>::factorial(const int& n) const{
	int x = 1;
	for(int i=n; i>0;i--){
		x*=i;
	}
	return x;
}

template<typename T>
bool Permutation<T>::find(const T& e, const std::vector<T> E){
	for (auto _e:E){
		if(e == _e){
			return true;
		}
	}
	return false;
}

template <typename T>
void Permutation<T>::_permute(const std::vector<T>& s, const std::vector<T> S){
	int cursor_pos = 0;
	std::vector<T> _C, _s;
	_s = s; // copy what is in s so far
	while(cursor_pos < S.size()){
		_s.push_back(S[cursor_pos]);
		_C = createSetWithoutElementAt(cursor_pos, S);
		_permute(_s,_C);
		cursor_pos++;
		_s.pop_back();
	}
	if(S.empty())
		P.push_back(_s);
	else
		return;
}
template <typename T>
std::vector<T> Permutation<T>::createSetWithoutElementAt(const int& cursor_pos, const std::vector<T>& S){
	std::vector<T> _C;
	for (int i=0; i<S.size();i++){
		if(i!=cursor_pos){
			_C.push_back(S[i]);
		}
	}
	return _C;
}

#endif /* PERMUTATION_HPP_ */



