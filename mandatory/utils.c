/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 05:40:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/22 06:18:38 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int   ft_atoi(char *num)
{
  int number;
  int index;

  index = 0;
  number = 0;
  while (num[index])
  {
    number = number * 10 + (num[index] - '0');
    index++;
  }
  return (number);
}

double  ft_map(int in, double min, double max)
{
  double  maped;

  maped = in * ((max - min) / 600) + min;
  return (maped);
}

void  ft_instructions(void)
{
  write(1, "############## INSTRUCTION ##############\n", 43);
  write(1, "#                                       #\n", 43);
  write(1, "#                                       #\n", 43);
  write(1, "# mouse wheel   -   Zoom                #\n", 43);
  write(1, "# mouse buttons - Use them whith julia  #\n", 43);
  write(1, "#                                       #\n", 43);
  write(1, "#                                       #\n", 43);
  write(1, "# r - Reset                             #\n", 43);
  write(1, "# c - Change Color                      #\n", 43);
  write(1, "# p - Change fractal                    #\n", 43);
  write(1, "# z - Increase the max iteration        #\n", 43);
  write(1, "# n - Decrease the max iteration        #\n", 43);
  write(1, "# esc | q - Quit                        #\n", 43);
  write(1, "#                                       #\n", 43);
  write(1, "#                                       #\n", 43);
  write(1, "############## INSTRUCTION ##############\n", 43);
}
