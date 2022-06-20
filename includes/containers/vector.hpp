#ifndef VECTOR_HPP
# define VECTOR_HPP

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
			/* TESTER CAPACITY ALLOCATORS */
			explicit	vector(const allocator_type& alloc = allocator_type()) : _vec(0), _allocator(alloc), _capacity_allocator(0), _size(0)
			{
				_vec = _allocator.allocate(0);
			}
			explicit	vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) :
				_allocator(alloc), _capacity_allocator(count), _size(count)
			{
				_vec = _allocator.allocate(count);
				for (size_type i = 0; i < count; i++)
					_allocator.construct(_vec + i, value);
			}
			template<class InputIt>
			vector(InputIt first, InputIt last,
				const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0) :
				_allocator(alloc)
			{
				size_type count = static_cast<size_type>(std::distance(first, last));
				_capacity_allocator = count;
				_vec = _allocator.allocate(_capacity_allocator);
				for (size_type i = 0; i < count; i++)
				{
						_allocator.construct(_vec + i, *first);
						++first;
				}
				_size = count;
			}
			vector(const vector& other)
			{
				_allocator = other.get_allocator();
				_vec = _allocator.allocate(other.size());
				_capacity_allocator = other.size();
				_size = other.size();
				for (size_type i = 0; i < other.size(); i++)
					_allocator.construct(_vec + i, other.at(i));
			}
			virtual	~vector()
			{
				if (_vec)
				{
					for (size_type i = 0; i < _size; i++)
						_allocator.destroy(&_vec[i]);
					_allocator.deallocate(_vec, _capacity_allocator);
				}
			}
			vector&	operator=(const vector& other)
			{
				if (this != &other)
				{
						for (size_type i = 0; i < _size; i++)
							_allocator.destroy(_vec + i);
						_size = 0;
					if (other.empty())
						return (*this);
					if (this->capacity() < other.capacity())
					{
						_allocator.deallocate(_vec, _capacity_allocator);
						_vec = _allocator.allocate(other.size());
						_capacity_allocator = other.size();
					}
					_size = other.size();
					for (size_type i = 0; i < other.size(); i++)
						_allocator.construct(_vec + i, other[i]);
				}
				return (*this);
			}
			/* Oublie pas de mettre les fonctions dans le bon ordre */
			void	assign(size_type count, const T& value)
			{
				size_type i = 0;

				for (; i < _size; i++)
					_allocator.destroy(_vec + i);
				if (_capacity_allocator < count)
				{
					_allocator.deallocate(_vec, _capacity_allocator);
					_capacity_allocator = count;
					_vec = _allocator.allocate(_capacity_allocator);
				}
				for (i = 0; i < count; i++)
					_allocator.construct(&_vec[i], value);
				_size = count;
			}
			/* ::type* = 0 () */
			template<class InputIt>
			void	assign(InputIt first, InputIt last,
				typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				difference_type	count = std::distance(first, last);
				size_type	i = 0;
				for (; i < _size; i++)
					_allocator.destroy(_vec + i);
				if (_capacity_allocator < static_cast<unsigned>(count))
				{
					_allocator.deallocate(_vec, _capacity_allocator);
					_capacity_allocator = count;
					_vec = _allocator.allocate(_capacity_allocator);
				}
				i = 0;
				while (first != last)
				{
					_allocator.construct(&_vec[i], *first);
					++first;
					++i;
				}
				_size = static_cast<size_type>(count);
			}
			allocator_type	get_allocator() const
			{
				return (_allocator);
			}
			/* ELEMENTS ACCESS */
			reference	at(size_type pos)
			{
				if (!(pos < this->size()))
				{
					std::stringstream	oss;
					std::string err_msg;
					std::string	concat_msg;

					err_msg = "vector::_M_check_range: __n (which is ";
					oss << pos;
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
				return (_vec[pos]);
			}
			const_reference	at(size_type pos) const
			{
				if (!(pos < this->size()))
				{
					std::stringstream	oss;
					std::string err_msg;
					std::string	concat_msg;

					err_msg = "vector::_M_check_range: __n (which is ";
					oss << pos;
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
				return (_vec[pos]);
			}
			reference	operator[](size_type pos)
			{
				return (_vec[pos]);
			}
			const_reference	operator[](size_type pos) const
			{
				return (_vec[pos]);
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
			void	reserve(size_type new_cap)
			{
				if (new_cap > this->max_size())
					throw std::length_error("vector::reserve");
				pointer	ptr = NULL;
				if (new_cap > _capacity_allocator)
				{
					ptr = _allocator.allocate(new_cap);
					for (size_type i = 0; i < _size; i++)
					{
						_allocator.construct(&ptr[i], _vec[i]);
						_allocator.destroy(&_vec[i]);
					}
					_allocator.deallocate(_vec, _capacity_allocator);
					_vec = ptr;
					_capacity_allocator = new_cap;
				}
			}
			size_type	capacity() const
			{
				return (_capacity_allocator);
			}
			/* MODIFIERS */
			void	clear()
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_vec + i);
				_size = 0;
			}
			iterator	insert(iterator pos, const T& value)
			{
				size_type	offset = pos - this->begin();
				size_type	offset_cpy = offset;
				size_type	new_size = _size + 1;

				if (new_size > _capacity_allocator)
				{
					pointer	ptr = pointer();

					size_type multiple_two = _size << 1;
					if (_capacity_allocator == 0)
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					else if (multiple_two > new_size)
					{
						ptr = _allocator.allocate(multiple_two);
						_capacity_allocator = multiple_two;
					}
					else
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					for (size_type i = 0; i < offset; i++)
					{
						_allocator.construct(ptr + i, _vec[i]);
						_allocator.destroy(_vec + i);
					}
					size_type	nb_count = offset + 1;
					_allocator.construct(ptr + offset, value);
					while (offset < _size)
					{
						new (ptr + nb_count) value_type(_vec[offset]);
						_vec[offset].~value_type();
						++nb_count;
						++offset;
					}
					_allocator.deallocate(_vec, _capacity_allocator);
					_vec = ptr;
					++_size;
					return (&_vec[offset_cpy]);
				}
				size_type	slot = _size;
				size_type       size = _size;
				size_type       max = _size - offset;
				for (size_type i = 0; i < max; i++)
				{
						--slot;
						new (_vec + size) value_type(_vec[slot]);
						_vec[slot].~value_type();
						--size;
				}
				_allocator.construct(&_vec[slot], value);
				++_size;
				return (&_vec[slot]);
			}
			/*
				Inserting element at a position other than end() cause element to relocate
				from pos to end
				THIS IS FROM LIBSTDC++
				Calling directly content is much faster than calling the functions.
				construct(pointer __p, const _Tp& __val)
				{ ::new((void *)__p) _Tp(__val); }
				void
				destroy(pointer __p) { __p->~_Tp(); }
			*/
			void	insert(iterator pos, size_type count, const T& value)
			{
				if (count == 0)
					return ;
				size_type	offset = pos - this->begin();
				size_type	new_size = _size + count;

				if (new_size > _capacity_allocator)
				{
					pointer	ptr = pointer();

					size_type multiple_two = _size << 1;
					if (_capacity_allocator == 0)
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					else if (multiple_two > new_size)
					{
						ptr = _allocator.allocate(multiple_two);
						_capacity_allocator = multiple_two;
					}
					else
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					for (size_type i = 0; i < offset; i++)
					{
						_allocator.construct(ptr + i, _vec[i]);
						_allocator.destroy(_vec + i);
					}
					size_type	nb_count = offset;
					size_type	max = offset + count;
					for (; nb_count < max; nb_count++)
						_allocator.construct(ptr + nb_count, value);
					while (offset < _size)
					{
						new (ptr + nb_count) value_type(_vec[offset]);
						_vec[offset].~value_type();
						++nb_count;
						++offset;
					}
					_allocator.deallocate(_vec, _capacity_allocator);
					_vec = ptr;
					_size += count;
					return ;
				}
				size_type       size = _size + count - 1;
				size_type       slot = _size;
				size_type       max = _size - offset;
				for (size_type i = 0; i < max; i++)
				{
						--slot;
						new (_vec + size) value_type(_vec[slot]);
						_vec[slot].~value_type();
						--size;
				}
				max = offset + count;
				for (size_type nb_count = offset; nb_count < max; nb_count++)
					_allocator.construct(_vec + nb_count, value);
				_size += count;
			}

			template<class InputIt>
			void	insert(iterator pos, InputIt first, InputIt last,
				typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				if (first == last)
					return ;
				size_type	offset = pos - begin();
				size_type	count = static_cast<size_type>(std::distance(first, last));
				size_type	new_size = _size + count;
				if (new_size > _capacity_allocator)
				{
					pointer	ptr = pointer();

					size_type multiple_two = _size << 1;
					if (_capacity_allocator == 0)
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					else if (multiple_two > new_size)
					{
						ptr = _allocator.allocate(multiple_two);
						_capacity_allocator = multiple_two;
					}
					else
					{
						ptr = _allocator.allocate(new_size);
						_capacity_allocator = new_size;
					}
					for (size_type i = 0; i < offset; i++)
					{
						new (ptr + i) value_type(_vec[i]);
						_vec[i].~value_type();
					}
					size_type	nb_count = offset;
					size_type	max = offset + count;
					for (; nb_count < max; nb_count++)
					{
						_allocator.construct(ptr + nb_count, *first);
						++first;
					}
					while (offset < _size)
					{
						new (ptr + nb_count) value_type(_vec[offset]);
						_vec[offset].~value_type();
						++nb_count;
						++offset;
					}
					_allocator.deallocate(_vec, _capacity_allocator);
					_vec = ptr;
					_size += count;
					return ;
				}
				size_type       size = _size + count - 1;
				size_type       slot = _size;
				size_type       max = _size - offset;
				for (size_type i = 0; i < max; i++)
				{
						--slot;
						new (_vec + size) value_type(_vec[slot]);
						_vec[slot].~value_type();
						--size;
				}
				max = offset + count;
				for (size_type nb_count = offset; nb_count < max; nb_count++)
				{
					new (_vec + nb_count) value_type(*first);
					++first;
				}
				_size += count;
			}
			/* pointer ptr for last element because STL return an iterator with the deleted value */
			iterator	erase(iterator pos)
			{
				if (pos != end())
				{
					size_type	offset = pos - this->begin();
					size_type	offset2 = offset + 1;
					size_type	max = (_size - offset) - 1;
					size_type	i = 0;
					while (i < max)
					{
						_vec[offset].~value_type();
						++i;
						new (_vec + offset) value_type(_vec[offset2]);
						++offset2;
						++offset;
					}
					_allocator.destroy(&_vec[offset]);
					_size--;
				}
				return (pos);
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
					while (offset_first != offset_last)
					{
						_vec[offset_first].~value_type();
						++offset_first;
						--_size;
					}
					while (offset_first != max)
					{
						new (_vec + copy_offset) value_type(_vec[offset_first]);
						_vec[offset_first].~value_type();
						++copy_offset;
						++offset_first;
					}
				}
				if (last == this->end())
					return (copy_offset2 + this->begin());
				return (first);
			}
			void	push_back(const T& value)
			{
				if (_capacity_allocator <= _size)
				{
					if (_capacity_allocator == 0)
						this->reserve(1);
					else
						this->reserve(_size << 1);
				}
				new (_vec + _size) value_type(value);
				_size++;
			}
			void	pop_back()
			{
				if (_size > 0)
				{
					_vec[_size - 1].~value_type();
					_size--;
				}
			}
			void	resize(size_type count, T value = T())
			{
				if (_capacity_allocator <= count)
				{
					size_type	multiple_two = _size << 1;
					if (_capacity_allocator == 0)
						this->reserve(count);
					else if (count < multiple_two)
						this->reserve(multiple_two);
					else
						this->reserve(count);
				}
				while (_size < count)
				{
					_allocator.construct(_vec + _size, value);
					++_size;
				}
				if (count < _size)
				{
					while (count < _size)
						this->pop_back();
				}
			}
			void	swap(vector& other)
			{
				if (*this != other)
				{
					pointer	tmp_vec = other._vec;
					allocator_type	tmp_alc = other._allocator;
					size_type	tmp_cap = other._capacity_allocator;
					size_type	tmp_size = other._size;

					other._vec = _vec;
					other._allocator = _allocator;
					other._capacity_allocator = _capacity_allocator;
					other._size = _size;
					_vec = tmp_vec;
					_allocator = tmp_alc;
					_capacity_allocator = tmp_cap;
					_size = tmp_size;
				}
			}
		private:
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
