/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:54:28 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 23:54:29 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}

	return *this;
}

void PmergeMe::addNumber(int value)
{
	_vector.push_back(value);
	_deque.push_back(value);
}

void PmergeMe::sortVector()
{
	fordJohnson(_vector);
}

void PmergeMe::sortDeque()
{
	fordJohnson(_deque);
}

void PmergeMe::printVector() const
{
	for (size_t i = 0; i < _vector.size(); ++i)
	{
		std::cout << _vector[i];

		if (i + 1 < _vector.size())
			std::cout << " ";
	}

	std::cout << std::endl;
}