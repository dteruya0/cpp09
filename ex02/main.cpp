/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:08:31 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 23:03:40 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: too few arguments." << std::endl;
		return 1;
	}
	PmergeMe pmerge;
	
	for (int i = 1; i < argc; i++)
	{
		std::string number = argv[i];
		for (size_t j = 0; j < number.length(); j++)
		{
			if (!isdigit(number[j]))
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
		long value = atol(argv[i]);
		if (value > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		pmerge.addNumber(static_cast<int>(value));
	}
	pmerge.sortDeque();
	pmerge.sortVector();
	return 0;
}