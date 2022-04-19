#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T>> class	vector
	{
		public:
			typedef T		value_type;
			typedef Allocator	allocator_type;
			typedef typename Allocator::reference	reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer	pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef ft::RandomAccessIterator<value_type>	iterator;
			typedef ft::RandomAccessIterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t	size_type;
	};
}

#endif
