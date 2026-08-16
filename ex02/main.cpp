/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:55:14 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 23:55:15 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe pmerge;

	for (int i = 1; i < argc; ++i)
	{
		std::string number = argv[i];

		if (number.empty())
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}

		for (size_t j = 0; j < number.length(); ++j)
		{
			if (!isdigit(number[j]))
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}

		long value = std::atol(argv[i]);

		if (value > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}

		pmerge.addNumber(static_cast<int>(value));
	}

	std::cout << "Before: ";
	pmerge.printVector();

	clock_t startVector = clock();

	pmerge.sortVector();

	clock_t endVector = clock();

	clock_t startDeque = clock();

	pmerge.sortDeque();

	clock_t endDeque = clock();

	std::cout << "After: ";
	pmerge.printVector();

	double vectorTime =
		static_cast<double>(endVector - startVector)
		/ CLOCKS_PER_SEC * 1000000.0;

	double dequeTime =
		static_cast<double>(endDeque - startDeque)
		/ CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of "
			  << argc - 1
			  << " elements with std::vector : "
			  << vectorTime
			  << " us"
			  << std::endl;

	std::cout << "Time to process a range of "
			  << argc - 1
			  << " elements with std::deque : "
			  << dequeTime
			  << " us"
			  << std::endl;

	return 0;
}