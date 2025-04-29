/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:51:00 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/29 14:47:54 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define reset	"\033[0m"
#define red		"\033[31m"
#define green	"\033[32m"
#define yellow	"\033[33m"

class ClapTrap
{
private:
	std::string name;
	int	hitPoints;
	int	energyPoints;
	int	attackDamage;
public:
	ClapTrap(void);
	ClapTrap(const ClapTrap& cpy);
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &other);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string getName(void);
	void		setName(std::string name);
};
