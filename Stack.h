#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <type_traits>
namespace G{
template<typename T>
class Stack
{
public:
	std::vector<T> elems;

	T pop()const;
	void print()const;
	void push(T const& t);
	T top()const;
	void print(std::ostream& strm)const{
		for (T const& elem : elems)
		{
			strm << elem << " ";
		}
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os,Stack<T> t){
	for ( T const& elem : t.elems)
	{
		os << elem << " ";
	}
	os << std::endl;
	return os;
}

template<typename T>
void Stack<T>::push(T const& t){
	elems.push_back(t);
}

template<typename T>
T Stack<T>::top()const{
	assert(!elems.empty());
	return elems.back();
}
// 
template<typename T>
T Stack<T>::pop ()const{
	auto t = elems.end() - 1;

	return t;
}
// 判断T是什么类型
template<typename T>
void Stack<T>::print()const{
	if (std::is_integral<T>::value)
		std::cout << "it is float" << std::endl;
	else
		std::cout << "it is not float" << std::endl;
}

}