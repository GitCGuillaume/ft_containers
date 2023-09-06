#ifndef UTILS_GC_HPP
# define UTILS_GC_HPP
namespace ft
{
	template <class T>
	T*	addressof(T& arg)
	{
		return (&arg);
	}
}

#endif
