#ifndef ITERATOR_TRAITS_HPP
 # define ITERATOR_TRAITS_HPP

#include	<cstddef>

namespace ft
{
	template <class Iter>
	class	iterator_traits
	{
		typename Iter::difference_type	difference_type;
		typename Iter::value_type	value_type;
		typename Iter::pointer		pointer;
		typename Iter::reference		reference;
		typename Iter::iterator_category	iterator_category;
	};

	template <typename T>
	class	iterator_traits<T*>
	{
		typename std::ptrdiff_t	difference_type;
		typedef T		value_type;
		typedef T*		pointer;
		typedef T&		reference;
		//doit coder équivalent en ft:: std::random_access_iterator_tag	iterator_category;
	};

	template <typename T>
	class	iterator_traits<const T*>
	{
		typename std::ptrdiff_t	difference_type;
		typedef T		value_type;
		typename const T*	pointer;
		typename const T&	reference;
		//doit coder équivalent en ft:: typename T::iterator_category	iterator_category;
	};
}

#endif
