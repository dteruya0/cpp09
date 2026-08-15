/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:01:55 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 12:11:44 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN
{
	private:
		std::stack<int> _stack;
	
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);

		void calculate(const std::string &expression);
};

#endif