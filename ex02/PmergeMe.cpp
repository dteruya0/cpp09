/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:08:34 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 23:36:30 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
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

void PmergeMe::sortMainChain(std::vector<int>& mainChain)
{
	for (size_t i = 0; i < mainChain.size(); i++)
	{
		for (size_t j = i + 1; j < mainChain.size(); j++)
		{
			if (mainChain[i] > mainChain[j])
			{
				int temp = mainChain[i];
				mainChain[i] = mainChain[j];
				mainChain[j] = temp;
			}
		}
	}
}

void PmergeMe::sortVector()
{
	std::vector<int> mainChain;
	std::vector<int> pend;
	for (size_t i = 0; i + 1 < _vector.size(); i += 2)
	{
		if (_vector[i] > _vector[i + 1])
		{
			int temp = _vector[i];
			_vector[i] = _vector[i + 1];
			_vector[i + 1] = temp;
		}
		pend.push_back(_vector[i]);
		mainChain.push_back(_vector[i + 1]);
	}
	sortMainChain(mainChain);
}

void PmergeMe::sortDeque()
{}