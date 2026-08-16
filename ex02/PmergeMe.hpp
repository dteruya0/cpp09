/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:08:36 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 23:34:20 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <climits>
#include <cstdlib>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::vector<int> _deque;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);

		void addNumber(int value);
		void sortVector();
		void sortDeque();
		void sortMainChain(std::vector<int>& mainChain);
};




#endif