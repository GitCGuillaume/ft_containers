#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include <iterator>
#include <exception>
#include <sstream>
#include <limits>

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
			//typedef typename ft::iterator<std::random_access_iterator_tag, ft::RandomAccessIterator<value_type> >	iterator;
			typedef ft::RandomAccessIterator<value_type>		iterator;
			typedef ft::RandomAccessIterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t	size_type;
			/* MEMBERS FUNCTIONS */
			vector() : _capacity_allocator(0), _size(0)
			{
				_vec = _allocator.allocate(0);
			}
			/* TESTER CAPACITY ALLOCATORS */
			explicit	vector(const Allocator& alloc) : _vec(NULL), _allocator(alloc), _capacity_allocator(0), _size(0){}
			explicit	vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) :
				_allocator(alloc), _capacity_allocator(count), _size(count)
			{
				_vec = _allocator.allocate(_capacity_allocator);
				for (size_type i = 0; i < this->size(); i++)
					_allocator.construct(_vec + i, value);
			}
			template<class InputIt>
			vector(InputIt first, InputIt last,
				const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0) :
				_allocator(alloc)
			{
				size_type	count = 0;

				count = std::distance(last, first);
				_capacity_allocator = count;
				_vec = _allocator.allocate(_capacity_allocator);
				for (size_type i = 0; i < count; i++)
				{
					if (first != last)
					{
						_allocator.construct(_vec + i, *first);
						first++;
					}
				}
				_size = count;
			}
			vector(const vector& other)
			{
				_allocator = other.get_allocator();
				_vec = _allocator.allocate(other.capacity());
				_capacity_allocator = other.capacity();
				_size = other.size();
				for (size_type i = 0; i < other.size(); i++)
					_allocator.construct(_vec + i, other.at(i));
			}
			virtual	~vector()
			{
				if (_vec)
				{
					for (size_type i = 0; i < _size; i++)
						_allocator.destroy(_vec + i);
					_allocator.deallocate(_vec, _capacity_allocator);
				}
			}
			vector&	operator=(const vector& other)
			{
				if (this != &other)
				{
					if (_vec)
					{
						for (size_type i = 0; i < _size; i++)
							_allocator.destroy(_vec + i);
						_allocator.deallocate(_vec, _capacity_allocator);
						_allocator = other.get_allocator();
						_vec = _allocator.allocate(other.capacity());
					}
					_capacity_allocator = other.capacity();
					_size = other.size();
					for (size_type i = 0; i < other.size(); i++)
						_allocator.construct(_vec + i, other.at(i));
				}
				return (*this);
			}
			/* Oublie pas de mettre les fonctions dans le bon ordre */
			void	assign(size_type count, const T& value)
			{
				//TRY CATCH ?
				size_type i = 0;

				for (; i < _size; i++)
					_allocator.destroy(_vec + i);
				if (this->capacity() <= count)
				{
					if (_vec)
						_allocator.deallocate(_vec, _capacity_allocator);
					_capacity_allocator = count;
					_vec = _allocator.allocate(_capacity_allocator);
				}
				for (i = 0; i < count; i++)
					_allocator.construct(_vec + i, value);
				_size = count;
			}
			/* ::type* = 0 () */
			template<class InputIt>
			void	assign(InputIt first, InputIt last,
				typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				size_type	i = 0;
				difference_type	count = 0;

				count = std::distance(last, first);
				for (; i < _size; i++)
					_allocator.destroy(_vec + i);
				if (this->capacity() <= static_cast<unsigned>(count))
				{
					if (_vec)
						_allocator.deallocate(_vec, _capacity_allocator);
					_capacity_allocator = count;
					_vec = _allocator.allocate(_capacity_allocator);
				}
				i = 0;
				while (first != last)
				{
					_allocator.construct(_vec + i++, *first);
					first++;
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
			/* ELEMENTS ACCESS */
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
				return (this->_vec);
			}
			const_iterator	begin() const
			{
				return (this->_vec);
			}
			iterator	end()
			{
				if (_size == 0)
					return (this->_vec);
				return (this->_vec + _size);
			}
			const_iterator	end() const
			{
				if (_size == 0)
					return (this->_vec);
				return (this->_vec + _size);
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
			because computer can run out of memory before 2^bits-1 2^(64-1 or 32-1) */
			size_type	max_size() const
			{
				return (std::numeric_limits<difference_type>::max()/2);
			}
			/* Reserve does provock iterator invalidity */
			void	reserve(size_type new_cap)
			{
				if (new_cap > this->max_size())
					throw std::length_error("vector::reserve");
				pointer	ptr = NULL;
				if (new_cap > this->capacity())
				{
					ptr = _allocator.allocate(new_cap);
					_capacity_allocator = new_cap;
					for (size_type i = 0; i < this->size(); i++)
					{
						_allocator.construct(ptr + i, *(_vec + i));
						_allocator.destroy(_vec + i);
					}
					_allocator.deallocate(_vec, this->size());
					_vec = ptr;
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
			/*
				Memory capacity is _capacity_allocator * 2 if new_size is greater than old capacity
				Put value at the iterator address
				Reserve does provock iterator invalidity
				To resolve this, can do std::distance or iterator - .begin();
			*/
			iterator	insert(iterator pos, const T& value)
			{
				iterator	new_it;
				iterator	it_end;
				size_type	offset = pos - this->begin();
				size_type	cpy_size = _size;

				if (_size + 1 > _capacity_allocator)
					this->reserve(1 << _capacity_allocator);
				if (this->size() == 0)
					_allocator.construct(_vec, value);
				else
				{
					new_it = this->begin() - offset;
					it_end = this->end();
					while (it_end != new_it)
					{
						_allocator.construct(_vec + cpy_size, *(_vec + (cpy_size - 1)));
						_allocator.destroy(_vec + (cpy_size - 1));
						cpy_size--;
						it_end--;
					}
					_allocator.construct(_vec + cpy_size, value);
				}
				_size++;
				//FAUT TESTER CA ENCORE
				return (&_vec[cpy_size]);
			}
		private:
			pointer			_vec;
			allocator_type	_allocator;
			size_type		_capacity_allocator;
			size_type		_size;
	};
	template<class T, class Alloc>
	bool	operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs/*->_size*/ != rhs/*->_size*/)
			return (true);
		return (false);
	}
}

#endif
