#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <map>
#include "../../includes/containers/stack.hpp"
#include "../../includes/containers/vector.hpp"
#include "../../includes/containers/map.hpp"
#include <algorithm>
#include "constructor.hpp"

/*
 * iterators are used for random access or sequential access, 
 * std::stack don't understand it by default
*/

/*
 ** Source : https://www.cplusplus.com/reference/stack/stack/
 ** for iterator example : template <class T, class Container = deque<T> > class stack;
 ** Container :
 ** 	Type of the internal underlying container object where the elements are stored.
 ** 	Its value_type shall be T.
 ** 	Aliased as member type stack::container_type.
*/

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		~MutantStack(){};
		MutantStack(const MutantStack<T> & src) : std::stack<T>(src)
		{
			return ;
		}
		MutantStack operator=(const MutantStack<T> & src)
		{
			if (this != &src)
				*this = src;
			return (*this);
		}
		//Members types iterator
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		iterator	begin()
		{
			return (this->c.begin());
		};
		iterator	end()
		{
			return (this->c.end());
		};
		const_iterator	begin() const
		{
			return (this->c.begin());
		};
		const_iterator	end() const
		{
			return (this->c.end());
		};

		reverse_iterator	rbegin()
		{
			return (this->c.rbegin());
		};
		reverse_iterator	rend()
		{
			return (this->c.rend());
		};
		const_reverse_iterator	rbegin() const
		{
			return (this->c.rbegin());
		};
		const_reverse_iterator	rend() const
		{
			return (this->c.rend());
		};

};

#endif
