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
size_t PmergeMe::binarySearch(T& container, int value, size_t end)
{
	size_t low = 0;
	size_t high = end;

	while (low < high)
	{
		size_t middle = (low + high) / 2;

		if (container[middle] < value)
			low = middle + 1;
		else
			high = middle;
	}

	return low;
}

template <typename T>
void PmergeMe::insertSorted(T& container, int value, size_t end)
{
	size_t position = binarySearch(container, value, end);

	container.insert(container.begin() + position, value);
}

template <typename T>
void PmergeMe::fordJohnson(T& container)
{
	if (container.size() <= 1)
		return;

	T mainChain;
	T pend;

	// 1. Forma os pares
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		int first = container[i];
		int second = container[i + 1];

		if (first > second)
			std::swap(first, second);

		pend.push_back(first);
		mainChain.push_back(second);
	}

	// 2. O ímpar é só mais um pendente
	if (container.size() % 2 != 0)
		pend.push_back(container.back());

	// 3. Ordena os maiores
	fordJohnson(mainChain);

	// 4. Insere todos os pendentes, na ordem certa
	std::vector<size_t> order = getInsertionOrder(pend.size());

	for (size_t i = 0; i < order.size(); ++i)
		insertSorted(mainChain, pend[order[i]], mainChain.size());

	container = mainChain;
}

#endif