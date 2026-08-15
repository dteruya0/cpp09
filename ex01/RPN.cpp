/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:38:38 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 15:04:25 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
		this -> _stack = other._stack;
	return *this;
}

void RPN::calculate(const std::string &expression)
{
	for (size_t i = 0; i < expression.length(); i++)
	{
		if (isdigit(expression[i]))
		{
			int value = expression[i] - '0';
			_stack.push(value);
		}
		else if (expression[i] == ' ')
			continue;
		else if (expression[i] == '+')
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			int value1 = _stack.top();
			_stack.pop();
			int value2 = _stack.top();
			_stack.pop();
			_stack.push(value1 + value2);
		}
		else if (expression[i] == '-')
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			int value1 = _stack.top();
			_stack.pop();
			int value2 = _stack.top();
			_stack.pop();
			_stack.push(value2 - value1);
		}
		else if (expression[i] == '*')
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			int value1 = _stack.top();
			_stack.pop();
			int value2 = _stack.top();
			_stack.pop();
			_stack.push(value1 * value2);
		}
		else if (expression[i] == '/')
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			int value1 = _stack.top();
			if (value1 == 0)
			{
				std::cerr << "Error: 0 value in division operation." << std::endl;
				return;
			}
			_stack.pop();
			int value2 = _stack.top();
			_stack.pop();
			_stack.push(value2 / value1);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}
	if (_stack.size() != 1)
	{
		std::cerr << "Error: more than 1 value in result." << std::endl;
		return;
	}
	std::cout <<_stack.top() << std::endl;
}