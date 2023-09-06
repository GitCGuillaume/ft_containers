#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../iterators/iterator_traits.hpp"
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include "../library_headers/equal.hpp"
#include "../library_headers/lexicographical_compare.hpp"
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <memory>

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
			typedef ft::random_access_iterator<value_type, vector>		iterator;
			typedef ft::random_access_iterator<const value_type, vector>	const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t	size_type;
			/* MEMBERS FUNCTIONS */
			explicit	vector(const allocator_type& alloc = allocator_type()) : _vec(0), _allocator(alloc), _capacity_allocator(0), _size(0)
			{
				_vec = NULL;
			}
			explicit	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				_allocator(alloc), _capacity_allocator(n), _size(n)
			{
				if (n == 0)
				{
					_vec = NULL;
					return ;
				}
				else if (max_size() < n)
				{
					_vec = NULL;
					throw std::length_error("Length exception");
				}
				_vec = _allocator.allocate(n);
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(&_vec[i], val);
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()
					, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) :
				_allocator(alloc)
			{
				_size = 0;
				_vec = NULL;
				_capacity_allocator = 0;
				typedef typename ft::iterator_traits<InputIterator>::iterator_category	it_cat;
				_assign_constructor(first, last, it_cat());
			}
			vector(const vector& x)
			{
				_allocator = x.get_allocator();
				_vec = _allocator.allocate(x.size());
				_capacity_allocator = x.size();
				_size = x.size();
				for (size_type i = 0; i < x._size; ++i)
					_allocator.construct(&_vec[i], x[i]);
			}
			virtual	~vector()
			{
				if (_vec)
				{
					for (size_type i = 0; i < _size; ++i)
						_allocator.destroy(&_vec[i]);
					_allocator.deallocate(_vec, _capacity_allocator);
				}
			}
			vector&	operator=(const vector& x)
			{
				if (this != &x)
				{
					for (size_type i = 0; i < _size; ++i)
						_allocator.destroy(_vec + i);
					_size = 0;
					if (x.empty())
						return (*this);
					if (this->capacity() < x.capacity())
					{
						if (_vec)
							_allocator.deallocate(_vec, _capacity_allocator);
						_vec = _allocator.allocate(x.size());
						_capacity_allocator = x.size();
					}
					_size = x.size();
					for (size_type i = 0; i < _size; ++i)
						_allocator.construct(&_vec[i], x[i]);
				}
				return (*this);
			}
			void	assign(size_type n, const T& val)
			{
				for (size_type i = 0; i < _size; ++i)
					_allocator.destroy(_vec + i);
				if (_capacity_allocator < n)
				{
					if (_vec)
						_allocator.deallocate(_vec, _capacity_allocator);
					_capacity_allocator = n;
					_vec = _allocator.allocate(_capacity_allocator);
				}
				for (_size = 0; _size < n; ++_size)
					_allocator.construct(&_vec[_size], val);
			}
			/* ::type* = 0 () */
			/* https://en.cppreference.com/w/cpp/iterator/iterator_tags */
			template<class InputIt>
			void	assign(InputIt first, InputIt last
					, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				typedef typename ft::iterator_traits<InputIt>::iterator_category	it_cat;
				_assign(first, last, it_cat());
			}
			allocator_type	get_allocator() const
			{
				return (_allocator);
			}
			/* ELEMENTS ACCESS */
			reference	at(size_type n)
			{
				if (!(n < this->size()))
				{
					std::stringstream	oss;
					std::string err_msg;
					std::string	concat_msg;

					err_msg = "vector::_M_check_range: __n (which is ";
					oss << n;
					std::getline(oss, concat_msg);
					err_msg += concat_msg + ") >= this->size() (which is ";
					concat_msg.clear();
					oss.clear();
					oss << this->size();
					std::getline(oss, concat_msg);
					err_msg += concat_msg + ")";
					oss.clear();
					throw std::out_of_range(err_msg);
				}
				return (_vec[n]);
			}
			const_reference	at(size_type n) const
			{
				if (!(n < this->size()))
				{
					std::stringstream	oss;
					std::string err_msg;
					std::string	concat_msg;

					err_msg = "vector::_M_check_range: __n (which is ";
					oss << n;
					std::getline(oss, concat_msg);
					err_msg += concat_msg + ") >= this->size() (which is ";
					concat_msg.clear();
					oss.clear();
					oss << this->size();
					std::getline(oss, concat_msg);
					err_msg += concat_msg + ")";
					oss.clear();
					throw std::out_of_range(err_msg);
				}
				return (_vec[n]);
			}
			reference	operator[](size_type n)
			{
				return (_vec[n]);
			}
			const_reference	operator[](size_type n) const
			{
				return (_vec[n]);
			}
			reference	front()
			{
				return (_vec[0]);
			}
			const_reference	front() const
			{
				return (_vec[0]);
			}
			reference	back()
			{
				return (_vec[_size - 1]);
			}
			const_reference	back() const
			{
				return (_vec[_size - 1]);
			}
			T*	data()
			{
				return (this->_vec);
			}
			const T*	data() const
			{
				return (this->_vec);
			}
			/* ITERATORS */
			iterator	begin()
			{
				return (iterator(this->_vec));
			}
			const_iterator	begin() const
			{
				return (const_iterator(this->_vec));
			}
			reverse_iterator	rbegin()
			{
				return (reverse_iterator(this->end()));
			}
			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			}
			iterator	end()
			{
				if (_size == 0)
					return (iterator(this->_vec));
				return (iterator(this->_vec + _size));
			}
			const_iterator	end() const
			{
				if (_size == 0)
					return (const_iterator(this->_vec));
				return (const_iterator(this->_vec + _size));
			}
			reverse_iterator	rend()
			{
				return (reverse_iterator(this->begin()));
			}
			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(this->begin()));
			}
			/* CAPACITY */
			bool	empty() const
			{
				if (this->begin() == this->end())
					return (true);
				return (false);
			}
			size_type	size() const
			{
				return (_size);
			}
			/* Maximum number of items in a vector, it can still fail,
			because computer can run out of memory before 2^bits-1 2^(64-1 or 32-1)
			Could use std::numeric_limits<size_type>::max() / sizeof(value_type)
			but the references say it's used "in most"  */
			size_type	max_size() const
			{
				return (this->get_allocator().max_size());
			}
			/* Reserve does provock iterator invalidity */
			void	reserve(size_type n)
			{
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				pointer	ptr = NULL;
				if (n > _capacity_allocator)
				{
					ptr = _allocator.allocate(n);
					for (size_type i = 0; i < _size; ++i)
					{
						_allocator.construct(&ptr[i], _vec[i]);
						_allocator.destroy(&_vec[i]);
					}
					if (_vec)
						_allocator.deallocate(_vec, _capacity_allocator);
					_vec = ptr;
					_capacity_allocator = n;
				}
			}
			size_type	capacity() const
			{
				return (_capacity_allocator);
			}
			/* MODIFIERS */
			void	clear()
			{
				for (size_type i = 0; i < _size; ++i)
					_allocator.destroy(&_vec[i]);
				_size = 0;
			}
			iterator	insert(iterator position, const T& val)
			{
				size_type	offset = position - this->begin();
				size_type	offset_cpy = offset;
				size_type	new_size = _size + 1;

				if (new_size > this->max_size())
					throw std::length_error("vector::reserve");
				if (new_size > _capacity_allocator)
				{
					size_type	old_capacity = _capacity_allocator;
					pointer	ptr = pointer();

					size_type multiple_two = _size << 1;
					if (_capacity_allocator == 0)
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					else if (multiple_two > new_size)
					{
						if (multiple_two > this->max_size())
							throw std::length_error("vector::reserve");
						ptr = _allocator.allocate(multiple_two);
						_capacity_allocator = multiple_two;
					}
					else
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					for (size_type i = 0; i < offset; ++i)
					{
						_allocator.construct(&ptr[i], _vec[i]);
						_allocator.destroy(&_vec[i]);
					}
					size_type	nb_count = offset + 1;
					_allocator.construct(ptr + offset, val);
					while (offset < _size)
					{
						_allocator.construct(&ptr[nb_count], _vec[offset]);
						_allocator.destroy(&_vec[offset]);
						++nb_count;
						++offset;
					}
					if (_vec)
						_allocator.deallocate(_vec, old_capacity);
					_vec = ptr;
					++_size;
					return (&_vec[offset_cpy]);
				}
				size_type	slot = _size;
				size_type       size = _size;
				size_type       max = _size - offset;
				for (size_type i = 0; i < max; ++i)
				{
						--slot;
						_allocator.construct(&_vec[size], _vec[slot]);
						_allocator.destroy(&_vec[slot]);
						--size;
				}
				_allocator.construct(&_vec[slot], val);
				++_size;
				return (&_vec[slot]);
			}
			/*
				Inserting element at a position other than end() cause element to relocate
				from pos to end
				THIS IS FROM LIBSTDC++
			*/
			void	insert(iterator position, size_type n, const T& value)
			{
				if (n == 0)
					return ;
				size_type	offset = position - this->begin();
				size_type	new_size = _size + n;

				if (new_size > this->max_size())
						throw std::length_error("vector::reserve");
				if (new_size > _capacity_allocator)
				{
					size_type	old_capacity = _capacity_allocator;
					pointer	ptr = pointer();

					size_type multiple_two = _size << 1;
					if (_capacity_allocator == 0)
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					else if (multiple_two > new_size)
					{
						if (multiple_two > this->max_size())
							throw std::length_error("vector::reserve");
						ptr = _allocator.allocate(multiple_two);
						_capacity_allocator = multiple_two;
					}
					else
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					for (size_type i = 0; i < offset; ++i)
					{
						_allocator.construct(&ptr[i], _vec[i]);
						_allocator.destroy(&_vec[i]);
					}
					size_type	nb_count = offset;
					size_type	max = offset + n;
					for (; nb_count < max; ++nb_count)
						_allocator.construct(ptr + nb_count, value);
					while (offset < _size)
					{
						_allocator.construct(&ptr[nb_count], _vec[offset]);
						_allocator.destroy(&_vec[offset]);
						++nb_count;
						++offset;
					}
					if (_vec)
						_allocator.deallocate(_vec, old_capacity);
					_vec = ptr;
					_size += n;
					return ;
				}
				size_type       size = _size + n - 1;
				size_type       slot = _size;
				size_type       max = _size - offset;
				for (size_type i = 0; i < max; ++i)
				{
						--slot;
						_allocator.construct(&_vec[size], _vec[slot]);
						_allocator.destroy(&_vec[slot]);
						--size;
				}
				max = offset + n;
				while (offset < max)
				{
					_allocator.construct(&_vec[offset], value);
					++offset;
				}
				_size += n;
			}
			template<class InputIt>
			void	insert(iterator position, InputIt first, InputIt last,
				typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				if (first == last)
					return ;
				typedef typename ft::iterator_traits<InputIt>::iterator_category	it_cat;
				_insert(position, first, last, it_cat());
			}
			/* pointer ptr for last element because STL return an iterator with the deleted value */
			iterator	erase(iterator position)
			{
				if (position != end())
				{
					size_type	offset = position - this->begin();
					std::copy(&_vec[offset + 1], &_vec[_size], &_vec[offset]);
					_size--;
					_allocator.destroy(&_vec[_size]);
				}
				return (position);
			}
			iterator	erase(iterator first, iterator last)
			{
				size_type	offset_first = first - this->begin();
				size_type	copy_offset = offset_first;
				size_type	copy_offset2 = copy_offset;
				size_type	offset_last = last - this->begin();
				size_type	max = this->end() - this->begin();

				if (first != last)
				{
					if (offset_first != max)
					{
						std::copy(&_vec[offset_last], &_vec[_size], &_vec[offset_first]);
						size_type start = _size - (offset_last - offset_first);
						size_type end = _size;
						
						while (start != end)
						{
							_allocator.destroy(&_vec[start]);
							++start;
							--_size;
						}
					}
				}
				if (last == this->end())
					return (copy_offset2 + this->begin());
				return (first);
			}
			void	push_back(const T& val)
			{
				if (_capacity_allocator <= _size)
				{
					if (_capacity_allocator == 0)
						this->reserve(1);
					else
						this->reserve(_size << 1);
				}
				_allocator.construct(&_vec[_size], val);
				_size++;
			}
			void	pop_back()
			{
				if (_size > 0)
				{
					_allocator.destroy(&_vec[_size - 1]);
					_size--;
				}
			}
			void	resize(size_type n, value_type val = value_type())
			{
				if (_capacity_allocator <= n)
				{
					size_type	multiple_two = _size << 1;
					if (_capacity_allocator == 0)
						this->reserve(n);
					else if (n < multiple_two)
						this->reserve(multiple_two);
					else
						this->reserve(n);
				}
				while (_size < n)
				{
					_allocator.construct(_vec + _size, val);
					++_size;
				}
				if (n < _size)
				{
					while (n < _size)
						this->pop_back();
				}
			}
			void	swap(vector& x)
			{
				if (this != &x)
				{
					pointer	tmp_vec = x._vec;
					allocator_type	tmp_alc = x._allocator;
					size_type	tmp_cap = x._capacity_allocator;
					size_type	tmp_size = x._size;

					x._vec = _vec;
					x._allocator = _allocator;
					x._capacity_allocator = _capacity_allocator;
					x._size = _size;
					_vec = tmp_vec;
					_allocator = tmp_alc;
					_capacity_allocator = tmp_cap;
					_size = tmp_size;
				}
			}
		private:
			template<typename InputIt>
			void	_assign_constructor(InputIt first, InputIt last, std::input_iterator_tag)
			{
				for(; first != last; ++first)
					this->push_back(*first);
			}
			template<typename ForwardIt>
			void	_assign_constructor(ForwardIt first, ForwardIt last, std::forward_iterator_tag)
			{
				size_type count = static_cast<size_type>(std::distance(first, last));
				if (count == 0)
					return ;
				_capacity_allocator = count;
				_vec = _allocator.allocate(_capacity_allocator);
				for (size_type i = 0; first != last;)
				{
					_allocator.construct(&_vec[i], *first);
					++i;
					++first;
				}
				_size = count;
			}
			template<typename InputIt>
			void	_assign(InputIt first, InputIt last, std::input_iterator_tag)
			{
				this->clear();
				for(; first != last; ++first)
					this->push_back(*first);
			}
			template<typename ForwardIt>
			void	_assign(ForwardIt first, ForwardIt last, std::forward_iterator_tag)
			{
				difference_type	count = std::distance(first, last);
				size_type	i = 0;
				size_type	count_cpy = static_cast<unsigned int>(count);
				for (; i < _size; ++i)
					_allocator.destroy(_vec + i);
				if (_capacity_allocator < count_cpy)
				{
					if (_vec)
						_allocator.deallocate(_vec, _capacity_allocator);
					_capacity_allocator = count;
					_vec = _allocator.allocate(_capacity_allocator);
				}
				_size = 0;
				for(ForwardIt it = first; it != last; ++it, ++_size)
					_allocator.construct(&_vec[_size], *it);
			}
			template<typename InputIt>
			void	_insert(iterator position, InputIt first, InputIt last, std::input_iterator_tag)
			{
				if (first == last)
					return ;
				size_type	offset = position - begin();
				vector	vec_range(first, last);
				size_type	count = vec_range.size();
				size_type	new_size = _size + count;

				if (new_size > this->max_size())
					throw std::length_error("vector::reserve");
				if (new_size > _capacity_allocator)
				{
					size_type	old_capacity = _capacity_allocator;
					pointer	ptr = pointer();
					size_type multiple_two = _size << 1;
					if (_capacity_allocator == 0)
					{
						ptr = _allocator.allocate(vec_range.capacity());
						_capacity_allocator = vec_range.capacity();
					}
					else if (multiple_two > new_size)
					{
						if (multiple_two > this->max_size())
							throw std::length_error("vector::reserve");
						ptr = _allocator.allocate(multiple_two);
						_capacity_allocator = multiple_two;
					}
					else
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					for (size_type i = 0; i < offset; ++i)
					{
						_allocator.construct(&ptr[i], _vec[i]);
						_allocator.destroy(&_vec[i]);
					}
					size_type       nb_count = offset;
					for (size_type i = 0; i < count; ++i)
					{
							_allocator.construct(ptr + nb_count, vec_range[i]);
							++nb_count;
					}
					while (offset < _size)
					{
						_allocator.construct(&ptr[nb_count], _vec[offset]);
						_allocator.destroy(&_vec[offset]);
						++nb_count;
						++offset;
					}
					if (_vec)
						_allocator.deallocate(_vec, old_capacity);
					_vec = ptr;
					_size += count;
					return ;
				}
				size_type       size = _size + count - 1;
				size_type       slot = _size;
				size_type       max = _size - offset;
				for (size_type i = 0; i < max; ++i)
				{
					--slot;
					_allocator.construct(&_vec[size], _vec[slot]);
					_allocator.destroy(&_vec[slot]);
					--size;
				}
				for (size_type i = 0; i < count; ++i)
				{
					_allocator.construct(&_vec[offset], vec_range[i]);
					++offset;
				}
				_size += count;
			}
			template<typename ForwardIt>
			void	_insert(iterator position, ForwardIt first, ForwardIt last, std::forward_iterator_tag)
			{
				size_type	offset = position - begin();
				size_type	count = static_cast<size_type>(std::distance(first, last));
				size_type	new_size = _size + count;
				if (new_size > this->max_size())
						throw std::length_error("vector::reserve");
				if (new_size > _capacity_allocator)
				{
					size_type	old_capacity = _capacity_allocator;
					pointer	ptr = pointer();
					size_type multiple_two = _size << 1;
					if (_capacity_allocator == 0)
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					else if (multiple_two > new_size)
					{
						if (multiple_two > this->max_size())
							throw std::length_error("vector::reserve");
						ptr = _allocator.allocate(multiple_two);
						_capacity_allocator = multiple_two;
					}
					else
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					for (size_type i = 0; i < offset; ++i)
					{
						_allocator.construct(&ptr[i], _vec[i]);
						_allocator.destroy(&_vec[i]);
					}
					size_type       nb_count = offset;
					while (first != last)
					{
							_allocator.construct(ptr + nb_count, *first);
							++nb_count;
							++first;
					}
					while (offset < _size)
					{
						_allocator.construct(&ptr[nb_count], _vec[offset]);
						_allocator.destroy(&_vec[offset]);
						++nb_count;
						++offset;
					}
					if (_vec)
						_allocator.deallocate(_vec, old_capacity);
					_vec = ptr;
					_size += count;
					return ;
				}
				size_type       size = _size + count - 1;
				size_type       slot = _size;
				size_type       max = _size - offset;
				for (size_type i = 0; i < max; ++i)
				{
					--slot;
					_allocator.construct(&_vec[size], _vec[slot]);
					_allocator.destroy(&_vec[slot]);
					--size;
				}
				for (; first != last; ++offset)
				{
					_allocator.construct(&_vec[offset], *first);
					++first;
				}
				_size += count;
			}
			pointer			_vec;
			allocator_type	_allocator;
			size_type		_capacity_allocator;
			size_type		_size;
	};
	/*
	*	if (lhs.size() != rhs.size())
	*	Can't be equal if size is not
	*	Also quicker
	*/
	template<class T, class Alloc>
	bool	operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		bool	is_equal = ft::equal(lhs.begin(), lhs.end(), rhs.begin());

		return (is_equal);
	}
	template<class T, class Alloc>
	bool	operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size()) // Quicker
			return (true);
		bool	is_equal = ft::equal(lhs.begin(), lhs.end(), rhs.begin());

		return (!is_equal);
	}
	template<class T, class Alloc>
    	bool	operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
    	{
        	bool	is_left = ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	
		return (is_left);
    	}
	template<class T, class Alloc>
   	bool	operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}
	template<class T, class Alloc>
    	bool	operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
        	return (rhs < lhs);
	}
	template<class T, class Alloc>
    	bool	operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	template<class T, class Alloc>
	void	swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
