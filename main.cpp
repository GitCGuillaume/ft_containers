#include "tests/vector/constructor_summary_vector.hpp"
#include "tests/map/constructor_summary_map.hpp"
#include "tests/stack/constructor_summary_stack.hpp"
#include <ctime>
#include <iomanip>

void	execute_function(void (*ft)(void), char timer)
{
	if (timer == '0')
	{
		ft();
	}
	else
	{
		//clock_t start, end;

		//start = clock();
		ft();
		//end = clock();
		//double timing = end - start;
		//double seconds = (timing * 1000) / CLOCKS_PER_SEC;
		//std::cout << std::setprecision(4) << (seconds) << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	execute_function(iterator_assign_forward, argv[1][0]);
	execute_function(iterator_assign_first_last_forward, argv[1][0]);
	execute_function(iterator_assign_backward, argv[1][0]);
	execute_function(iterator_assign_first_last_backward, argv[1][0]);
	execute_function(iterator_input_assign, argv[1][0]);
	execute_function(at_ok, argv[1][0]);
	execute_function(at_const_ok, argv[1][0]);
	execute_function(at_out_of_range, argv[1][0]);
	execute_function(front, argv[1][0]);
	execute_function(back, argv[1][0]);
	execute_function(default_constructor, argv[1][0]);
	execute_function(allocator_constructor, argv[1][0]);
	execute_function(allocator_count_constructor, argv[1][0]);
	execute_function(allocator_iterator, argv[1][0]);
	execute_function(copy_constructor, argv[1][0]);
	execute_function(fill_constructor, argv[1][0]);
	execute_function(length_error_constructor, argv[1][0]);
	execute_function(constructor_range_input_it, argv[1][0]);
	execute_function(operator_assignation_constructor, argv[1][0]);
	execute_function(test_data, argv[1][0]);
	execute_function(test_const_data, argv[1][0]);
	execute_function(empty, argv[1][0]);
	execute_function(max_size, argv[1][0]);
	execute_function(reserve_error, argv[1][0]);
	execute_function(reserve_test, argv[1][0]);
	execute_function(clear, argv[1][0]);
	execute_function(insert, argv[1][0]);
	execute_function(insert_100k, argv[1][0]);
	execute_function(insert_reserve_100k, argv[1][0]);
	execute_function(insert_return, argv[1][0]);
	execute_function(count_insert_100, argv[1][0]);
	execute_function(iterator_insert, argv[1][0]);
	execute_function(iterator_input_insert_range, argv[1][0]);
	execute_function(erase, argv[1][0]);
	execute_function(erase_30k, argv[1][0]);
	execute_function(erase_iterator, argv[1][0]);
	execute_function(push_back_vector, argv[1][0]);
	execute_function(pop_back_vector, argv[1][0]);
	execute_function(resize, argv[1][0]);
	execute_function(swap_vector, argv[1][0]);
	execute_function(swap_vector_non_member, argv[1][0]);
	execute_function(equal_vector, argv[1][0]);
	execute_function(non_member_operator_vector, argv[1][0]);
	execute_function(reverse_iterator, argv[1][0]);
	execute_function(reverse_iterator_empty, argv[1][0]);
	execute_function(iterator_test, argv[1][0]);
	execute_function(iterator_empty, argv[1][0]);
	//MAP PART
	execute_function(default_constructor_map, argv[1][0]);
	execute_function(constructor_range_map, argv[1][0]);
	execute_function(copy_constructor_map, argv[1][0]);
	execute_function(operator_assignation_map, argv[1][0]);
	execute_function(constructor_range_speed, argv[1][0]);
	execute_function(constructor_copy_speed, argv[1][0]);
	execute_function(assignation_speed, argv[1][0]);
	execute_function(pair_default, argv[1][0]);
	execute_function(pair_equal, argv[1][0]);
	execute_function(pair_not_equal, argv[1][0]);
	execute_function(pair_left, argv[1][0]);
	execute_function(pair_left_equal, argv[1][0]);
	execute_function(pair_right, argv[1][0]);
	execute_function(pair_right_equal, argv[1][0]);
	execute_function(pair_copy, argv[1][0]);
	execute_function(iterator_map_default, argv[1][0]);
	execute_function(empty_bracket, argv[1][0]);
	execute_function(bracket_map, argv[1][0]);
	execute_function(at_map, argv[1][0]);
	execute_function(iterator_assignation_map, argv[1][0]);
	execute_function(iterator_forward_map, argv[1][0]);
	execute_function(iterator_backward_map, argv[1][0]);
	execute_function(reverse_iterator_map, argv[1][0]);
	execute_function(reverse_iterator_empty_map, argv[1][0]);
	execute_function(equal_map, argv[1][0]);
	execute_function(simple_clear, argv[1][0]);
	execute_function(simple_erase, argv[1][0]);
	execute_function(range_erase, argv[1][0]);
	execute_function(erase_key, argv[1][0]);
	execute_function(insert_value_type, argv[1][0]);
	execute_function(insert_hint, argv[1][0]);
	execute_function(insert_range, argv[1][0]);
	execute_function(lookup_find, argv[1][0]);
	execute_function(map_count, argv[1][0]);
	execute_function(map_swap, argv[1][0]);
	execute_function(map_swap_non_member, argv[1][0]);
	execute_function(map_equal_range, argv[1][0]);
	execute_function(map_equal_range_const, argv[1][0]);
	execute_function(lower_bound_map, argv[1][0]);
	execute_function(upper_bound_map, argv[1][0]);
	execute_function(test_keycomp, argv[1][0]);
	execute_function(test_value_comp, argv[1][0]);
	execute_function(non_member_operator_map, argv[1][0]);

	//STACK
	execute_function(default_constructor_stack, argv[1][0]);
	execute_function(constructor_stack_copy, argv[1][0]);
	execute_function(stack_empty, argv[1][0]);
	execute_function(stack_size, argv[1][0]);
	execute_function(stack_equal, argv[1][0]);
	execute_function(stack_mutant_stack, argv[1][0]);
	execute_function(stl_vector, argv[1][0]);
	execute_function(stl_deque, argv[1][0]);
	execute_function(stl_list, argv[1][0]);
	return (0);
}
