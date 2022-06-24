#include "tests/vector/constructor_summary_vector.hpp"
#include "tests/map/constructor_summary_map.hpp"
#include "tests/stack/constructor_summary_stack.hpp"
#include <iostream>
#include <stdint.h>
#include <ctime>
#include "sys/time.h"
#include <ios>
#include <iomanip>

/*
 *	true == green == std
 *	false == cyan == ft
*/
void	execute_function(void (*ft)(void))
{
	struct timeval	start, end;
	double		sum_time;
	long int	mem_seconds;
	long int	mem_micro_s;

	gettimeofday(&start, NULL);
	ft();
	gettimeofday(&end, NULL);
	mem_seconds = end.tv_sec - start.tv_sec;
	mem_micro_s = end.tv_usec - start.tv_usec;
	sum_time = mem_seconds + mem_micro_s * 1e-6;
	std::cout << std::setprecision(17) << std::fixed << sum_time << std::endl;
	std::cout << std::setprecision(0);
}

int	main(void)
{
	execute_function(&iterator_assign_forward);
	execute_function(iterator_assign_first_last_forward);
	execute_function(iterator_assign_backward);
	execute_function(iterator_assign_first_last_backward);
	execute_function(at_ok);
	execute_function(at_const_ok);
	execute_function(at_out_of_range);
	execute_function(front);
	execute_function(back);
	execute_function(default_constructor);
	execute_function(allocator_constructor);
	execute_function(allocator_count_constructor);
	execute_function(allocator_iterator);
	execute_function(copy_constructor);
	execute_function(fill_constructor);
	execute_function(operator_assignation_constructor);
	execute_function(test_data);
	execute_function(test_const_data);
	execute_function(empty);
	execute_function(max_size);
	execute_function(reserve_error);
	execute_function(reserve_test);
	execute_function(clear);
	execute_function(insert);
	execute_function(insert_100k);
	execute_function(insert_reserve_100k);
	execute_function(insert_return);
	execute_function(count_insert_100);
	execute_function(iterator_insert);
	execute_function(erase);
	execute_function(erase_30k);
	execute_function(erase_iterator);
	execute_function(push_back_vector);
	execute_function(pop_back_vector);
	execute_function(resize);
	execute_function(swap_vector);
	execute_function(swap_vector_non_member);
	execute_function(equal_vector);
	execute_function(reverse_iterator);
	execute_function(reverse_iterator_empty);
	execute_function(iterator_test);
	execute_function(iterator_empty);*/
	//MAP PART
	/*execute_function(default_constructor_map);
	execute_function(constructor_range_map);
	execute_function(copy_constructor_map);
	execute_function(operator_assignation_map);
	execute_function(constructor_range_speed);
	execute_function(constructor_copy_speed);
	execute_function(assignation_speed);
	execute_function(pair_default);
	execute_function(pair_equal);
	execute_function(pair_not_equal);
	execute_function(pair_left);
	execute_function(pair_left_equal);
	execute_function(pair_right);
	execute_function(pair_right_equal);
	execute_function(pair_copy);
	execute_function(iterator_map_default);
	execute_function(empty_bracket);
	execute_function(bracket_map);
	execute_function(at_map);
	execute_function(iterator_assignation_map);
	execute_function(iterator_forward_map);
	execute_function(iterator_backward_map);
	execute_function(reverse_iterator_map);
	execute_function(reverse_iterator_empty_map);
	execute_function(equal_map);
	execute_function(simple_clear);
	execute_function(simple_erase);
	execute_function(range_erase);
	execute_function(erase_key);
	execute_function(insert_value_type);
	execute_function(insert_hint);
	execute_function(insert_range);
	execute_function(lookup_find);
	execute_function(map_count);
	execute_function(map_swap);
	execute_function(map_swap_non_member);
	execute_function(map_equal_range);
	execute_function(map_equal_range_const);
	execute_function(lower_bound_map);
	execute_function(upper_bound_map);
	execute_function(test_keycomp);
	execute_function(test_value_comp);
	execute_function(non_member_operator_map);
	//STACK
	execute_function(default_constructor_stack);
	execute_function(constructor_stack_copy);
	execute_function(stack_empty);
	execute_function(stack_size);
	execute_function(stack_equal);
	execute_function(stack_mutant_stack);
	return (0);
}
