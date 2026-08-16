/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:53:49 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 23:53:50 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		template <typename T>
		void fordJohnson(T& container);

		template <typename T>
		void insertSorted(T& container, int value, typename T::iterator end);

		template <typename T>
		typename T::iterator binarySearch(T& container, int value,
			typename T::iterator end);

		template <typename T>
		std::vector<size_t> getJacobsthal(size_t size);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void addNumber(int value);

		void sortVector();
		void sortDeque();

		void printVector() const;
};

#include "PmergeMe.tpp"

#endif