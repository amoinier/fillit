/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 14:12:38 by amoinier          #+#    #+#             */
/*   Updated: 2015/12/20 17:29:22 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>

t_tetr	**init_tetr_tab(int nb)
{
	int		i;
	t_tetr	**tab;

	i = 0;
	tab = (t_tetr **)malloc(sizeof(t_tetr *) * (nb + 1));
	while (i != nb)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

void	ft_launch_algo(t_tetr **tab, int nbp[2])
{
	char	**tc;

	nbp[1] = nbp[0];
	tc = ft_init_tab(nbp[0]);
	ft_ft(tc, tab, 0, nbp);
	ft_print_tab(tc);
}

int		main(int ac, char **av)
{
	char	*tmp;
	t_tetr	**tab;
	int		nbp[2];
	int		i;

	i = 0;
	if (ac != 2)
		return (ft_puterror("error\n"));
	else
	{
		tmp = ft_create_str(av);
		if (!tmp || tmp[0] == '\0')
			return (ft_puterror("error\n"));
		if (((nbp[0] = ft_test_str(tmp)) > 0) &&
			ft_line(tmp) != 0 && (nbp[0] < 27))
		{
			tab = init_tetr_tab(nbp[0]);
			while (i < nbp[0])
			{
				if (ft_create_dtab(tmp, i) != NULL &&
					ft_test_tetri(ft_create_dtab(tmp, i)) > 0)
					tab[i] = tetrnew(ft_clean_tetri3(ft_clean_tetri2(ft_create_dtab(tmp, i))));
				else
					return (ft_puterror("error\n"));
				if (!ft_test_tetrimo(tab[i]))
					return (ft_puterror("error\n"));
				i++;
			}
			ft_launch_algo(tab, nbp);
		}
		else
			return (ft_puterror("error\n"));
	}
	return (0);
}
