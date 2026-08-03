/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:36:44 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/03 20:15:11 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        this->_database = other._database;
    return *this;
}

void BitcoinExchange::loadDataBase(const std::string &filename)
{
    // abrir o data.csv
    // ignorar a primeira linha: date,exchange_rate
    // ler linha por linha
    // separar a data da cotação pela vírgula
    // guardar no map
}

void BitcoinExchange::processInput(const std::string& filename)
{
    // abrir o arquivo
    // ignorar a primeira linha
    // ler linha por linha
    // validar cada linha
    // calcular o resultado se estiver certo
    // mostrar erro se estiver errado
}
