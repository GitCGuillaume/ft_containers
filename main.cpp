#include "includes/iterators/iterator_traits.hpp"
#include "includes/iterators/RandomAccessIterator.hpp"
#include "includes/containers/vector.hpp"
#include <iostream>
#include "includes/iterators/reverse_iterator.hpp"
#include <vector>
#include "tests/vector_custom/iterator_forward.hpp"
#include "tests/vector_custom/iterator_backward.hpp"
#include "tests/vector/iterator_forward.hpp"
#include "tests/vector/iterator_backward.hpp"
#include "tests/vector/at.hpp"
#include "includes/library_headers/is_integral.hpp"

#include <iostream>
#include <type_traits>
#include <stdint.h>
int	main(void)
{
	test_std_assign1_forward();
	test_ft_assign1_forward();
	test_std_assign_it_forward();
	test_ft_assign_it_forward();
	test_std_assign1_backward();
	test_ft_assign1_backward();
	test_std_assign_it_backward();
	test_ft_assign_it_backward();
	//at_ok();
	//at_out_of_range();
	std::cout << ft::is_integral<unsigned long long int>::value;
	return (0);
}
