#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{
	template<class T, class Allocator = std::allocator<T>> class	vector
	{
		public:
			T		value_type;
			Allocator	allocator_type;
			allocator_type::reference	reference;
			allocator_type::const_reference	const_reference;
			Allocator::pointer	pointer;
			Alocator::const_pointer	const_pointer;
			std::ptrdiff_t	diffrence_type;
			std::size_t	size_type;
	};
}

#endif
