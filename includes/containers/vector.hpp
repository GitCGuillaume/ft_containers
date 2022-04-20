#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> > class	vector
	{
		public:
			/* MEMBERS TYPES */
			typedef T		value_type;
			typedef Allocator	allocator_type;
			typedef typename Allocator::reference	reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer	pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef ft::RandomAccessIterator<value_type>	iterator;
			typedef ft::RandomAccessIterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t	size_type;
			/* MEMBERS FUNCTIONS */
			vector(){}
			explicit	vector(const Allocator& alloc)
			{
				_allocator = alloc;
			}
			explicit	vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
			{
				//
				return ;
			}
			template<class InputIt>
			vector(InputIt first, InputIt last,
				const Allocator& alloc = Allocator())
			{
				//
				return ;
			}
			vector(const vector& other)
			{
				//
				return ;
			}
			virtual	~vector(){}
			vector&	operator=(const vector& other)
			{
				if (this != &other)
				{
					//*this = other;
				}
				return (*this);
			}
			void	assign(size_type count, const T& value)
			{
				_allocator.deallocate();
				for (size_t i = 0; i < count; i++)
				{
					
				}
			}
			template<class InputIt>
			void	assign(InputIt first, InputIt last)
			{

			}
		private:
			allocator_type	_allocator;
	};
}

#endif
