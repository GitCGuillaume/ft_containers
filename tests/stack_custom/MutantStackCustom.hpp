#ifndef MUTANTSTACKCUSTOM_HPP
# define MUTANTSTACKCUSTOM_HPP

#include "../../includes/containers/stack.hpp"
#include "../../includes/containers/map.hpp"
#include "../../includes/containers/vector.hpp"
#include <iostream>
#include <algorithm>
#include "constructor.hpp"

/*
 ** Source : https://www.cplusplus.com/reference/stack/stack/
 ** for iterator example : template <class T, class Container = deque<T> > class stack;
 ** Container :
 ** 	Type of the internal underlying container object where the elements are stored.
 ** 	Its value_type shall be T.
 ** 	Aliased as member type stack::container_type.
*/

template <class T>
class MutantStackCustom : public ft::stack<T>
{
	public:
		MutantStackCustom(){};
		~MutantStackCustom(){};
		MutantStackCustom(const MutantStackCustom<T> & src) : ft::stack<T>(src)
		{
			return ;
		}
		MutantStackCustom operator=(const MutantStackCustom<T> & src)
		{
			if (this != &src)
				*this = src;
			return (*this);
		}
		//Members types iterator
		typedef typename ft::stack<T>::container_type::iterator	iterator;
		typedef typename ft::stack<T>::container_type::const_iterator	const_iterator;
		typedef typename ft::stack<T>::container_type::reverse_iterator	reverse_iterator;
		typedef typename ft::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
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
