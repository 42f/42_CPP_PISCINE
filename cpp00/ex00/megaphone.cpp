/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:26:08 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/29 09:22:26 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdbool.h>
#include <ctype.h>

void	output_av(const char *av)
{
	for ( int i = 0; av[i] != '\0'; i++ )
		std::cout << (const char)std::toupper( av[i] );
}

int		main( const int ac, const char **av ) {

	if ( ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if ( ac > 1 )
	{
		for ( int i = 1; av[i] != NULL; i++ )
			output_av( av[i] );
		std::cout << std::endl;
	}
	return ( 0 );
}
