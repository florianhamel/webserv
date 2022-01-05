/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:09:23 by pnielly           #+#    #+#             */
/*   Updated: 2022/01/05 21:13:23 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "Location.hpp"

/**************************************/
//           COPLIAN CLASS            //
/**************************************/

Location::Location():
	_root("/")
{}

Location::~Location() {}

Location::Location(const Location &x) { *this = x; }

Location&	Location::operator=(const Location &x) {
	if (this != &x) {
		_root = x.getRoot();
	}
	return *this;
}

/**************************************/
//				GETTERS				  //
/**************************************/

std::string	Location::getRoot() const { return _root; }

/**************************************/
//				GETTERS				  //
/**************************************/

void	Location::setRoot(std::string root) { _root = root; }

/**************************************/
//			PRINT_LOC				  //
/**************************************/

void	Location::print_loc() {
	std::cout << "Root: " << _root << std::endl;
	std::cout << std::endl;
}