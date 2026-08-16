/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:54:15 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 23:54:47 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP
#include "PmergeMe.hpp"

template <typename T>
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

template <typename T>
typename T::iterator PmergeMe::binarySearch(
	T& container,
	int value,
	typename T::iterator end)
{
	typename T::iterator first = container.begin();
	typename T::iterator last = end;

	while (first != last)
	{
		typename T::iterator middle = first;
		size_t distance = 0;

		typename T::iterator temp = first;
		while (temp != last)
		{
			++distance;
			++temp;
		}

		for (size_t i = 0; i < distance / 2; ++i)
			++middle;

		if (*middle < value)
			first = ++middle;
		else
			last = middle;
	}

	return first;
}

template <typename T>
void PmergeMe::insertSorted(
	T& container,
	int value,
	typename T::iterator end)
{
	typename T::iterator position =
		binarySearch(container, value, end);

	container.insert(position, value);
}

template <typename T>
void PmergeMe::fordJohnson(T& container)
{
	if (container.size() <= 1)
		return;

	T mainChain;
	T pend;

	/*
	** 1. Form pairs.
	**
	** Smaller element -> pend
	** Larger element  -> mainChain
	*/
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		int first = container[i];
		int second = container[i + 1];

		if (first > second)
			std::swap(first, second);

		pend.push_back(first);
		mainChain.push_back(second);
	}

	/*
	** 2. If we have an odd number of elements,
	** save the last one.
	*/
	bool hasOdd = (container.size() % 2 != 0);
	int odd = 0;

	if (hasOdd)
		odd = container.back();

	/*
	** 3. Recursively sort the larger elements.
	*/
	fordJohnson(mainChain);

	/*
	** 4. Insert the first pending element.
	*/
	if (!pend.empty())
	{
		typename T::iterator end = mainChain.end();

		insertSorted(mainChain, pend[0], end);
	}

	/*
	** 5. Generate Jacobsthal insertion order.
	*/
	std::vector<size_t> jacobsthal =
		getJacobsthal<T>(pend.size());

	size_t previous = 1;

	for (size_t j = 0; j < jacobsthal.size(); ++j)
	{
		size_t current = jacobsthal[j];

		if (current > pend.size())
			current = pend.size();

		size_t i = current;

		while (i > previous)
		{
			--i;

			typename T::iterator end = mainChain.end();

			insertSorted(mainChain, pend[i], end);
		}

		previous = current;

		if (current == pend.size())
			break;
	}

	/*
	** 6. Insert anything that wasn't inserted yet.
	*/
	for (size_t i = previous; i < pend.size(); ++i)
	{
		typename T::iterator end = mainChain.end();

		insertSorted(mainChain, pend[i], end);
	}

	/*
	** 7. Insert the odd element.
	*/
	if (hasOdd)
	{
		typename T::iterator end = mainChain.end();

		insertSorted(mainChain, odd, end);
	}

	container = mainChain;
}

#endif