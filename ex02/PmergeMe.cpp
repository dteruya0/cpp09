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

std::vector<size_t> PmergeMe::getJacobsthal(size_t size)
{
	std::vector<size_t> sequence;

	size_t j0 = 1;
	size_t j1 = 3;

	while (j0 < size)
	{
		sequence.push_back(j0);

		size_t next = j1;
		j1 = j1 + 2 * j0;
		j0 = next;
	}

	return sequence;
}

void PmergeMe::sortVector()
{
	fordJohnson<std::vector<int>, std::vector<std::vector<int> > >(_vector);
}

void PmergeMe::sortDeque()
{
	fordJohnson<std::deque<int>, std::deque<std::deque<int> > >(_deque);
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