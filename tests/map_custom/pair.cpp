#include "pair.hpp"

void    pair_default_custom()
{
    std::cout << "Default pair CUSTOM" << std::endl;
    ft::pair<double, double>   pair;
    std::cout << "first : " << pair.first << std::endl;
    std::cout << "second : " << pair.second << std::endl;
}

void    pair_equal_custom()
{
    std::cout << "pair equal CUSTOM" << std::endl;
    ft::pair<double, double>   pair(0.005000, 0.005000);
    ft::pair<double, double>   pair2(0.005000, 0.005000);
    ft::pair<double, double>   pair3(0.005000, 0.000001);
    std::cout <<" pair is equal CUSTOM == " << (pair == pair) << std::endl;
    std::cout <<" pair is equal CUSTOM == " << (pair == pair2) << std::endl;
    std::cout <<" pair is equal CUSTOM == " << (pair == pair3) << std::endl;
}

void    pair_not_equal_custom()
{
    std::cout << "pair not equal CUSTOM" << std::endl;
    ft::pair<double, double>   pair(0.005000, 0.005000);
    ft::pair<double, double>   pair2(0.005000, 0.005000);
    ft::pair<double, double>   pair3(0.005000, 0.000001);
    std::cout <<" pair is equal CUSTOM != " << (pair != pair) << std::endl;
    std::cout <<" pair is equal CUSTOM != " << (pair != pair2) << std::endl;
    std::cout <<" pair is equal CUSTOM != " << (pair != pair3) << std::endl;
}

void    pair_left_custom()
{
    std::cout << "pair left CUSTOM" << std::endl;
    ft::pair<double, double>   pair(0.006000, 0.005000);
    ft::pair<double, double>   pair2(0.005000, 0.006000);
    ft::pair<double, double>   pair3(0.005000, 0.000001);
    ft::pair<double, double>   pair4(0.000001, 0.005000);
    std::cout <<" pair is < CUSTOM " << (pair < pair) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair < pair2) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair < pair3) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair3 < pair4) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair4 < pair3) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair3 < pair4) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair4 < pair) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair < pair4) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair < pair3) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair4 < pair2) << std::endl;
    std::cout <<" pair is < CUSTOM " << (pair3 < pair2) << std::endl;
}

void    pair_left_equal_custom()
{
    std::cout << "pair left EQUAL CUSTOM" << std::endl;
    ft::pair<double, double>   pair(0.006000, 0.005000);
    ft::pair<double, double>   pair2(0.005000, 0.006000);
    ft::pair<double, double>   pair3(0.005000, 0.000001);
    ft::pair<double, double>   pair4(0.000001, 0.005000);
    std::cout <<" pair is <= CUSTOM " << (pair <= pair) << std::endl;
    std::cout <<" pair is <= CUSTOM " << (pair <= pair2) << std::endl;
    std::cout <<" pair is <= CUSTOM " << (pair <= pair3) << std::endl;
    std::cout <<" pair is <= CUSTOM " << (pair3 <= pair4) << std::endl;
    std::cout <<" pair is <= CUSTOM " << (pair4 <= pair3) << std::endl;
    std::cout <<" pair is <= CUSTOM " << (pair4 <= pair) << std::endl;
    std::cout <<" pair is <= CUSTOM " << (pair <= pair4) << std::endl;
}

void    pair_right_custom()
{
    std::cout << "pair right CUSTOM" << std::endl;
    ft::pair<double, double>   pair(0.006000, 0.005000);
    ft::pair<double, double>   pair2(0.005000, 0.006000);
    ft::pair<double, double>   pair3(0.005000, 0.000001);
    ft::pair<double, double>   pair4(0.000001, 0.005000);
    std::cout <<" pair is > CUSTOM " << (pair > pair) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair > pair2) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair > pair3) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair3 > pair4) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair4 > pair3) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair3 > pair4) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair4 > pair) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair > pair4) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair > pair3) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair4 > pair2) << std::endl;
    std::cout <<" pair is > CUSTOM " << (pair3 > pair2) << std::endl;
}

void    pair_right_equal_custom()
{
    std::cout << "pair right EQUAL CUSTOM" << std::endl;
    ft::pair<double, double>   pair(0.006000, 0.005000);
    ft::pair<double, double>   pair2(0.005000, 0.006000);
    ft::pair<double, double>   pair3(0.005000, 0.000001);
    ft::pair<double, double>   pair4(0.000001, 0.005000);
    std::cout <<" pair is >= CUSTOM " << (pair >= pair) << std::endl;
    std::cout <<" pair is >= CUSTOM " << (pair >= pair2) << std::endl;
    std::cout <<" pair is >= CUSTOM " << (pair >= pair3) << std::endl;
    std::cout <<" pair is >= CUSTOM " << (pair3 >= pair4) << std::endl;
    std::cout <<" pair is >= CUSTOM " << (pair4 >= pair3) << std::endl;
    std::cout <<" pair is >= CUSTOM " << (pair4 >= pair) << std::endl;
    std::cout <<" pair is >= CUSTOM " << (pair >= pair4) << std::endl;
}