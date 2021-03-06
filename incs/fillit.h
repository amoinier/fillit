/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:31:43 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/03 12:12:12 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct	s_tetr
{
	int			x;
	int			y;
	int			sx;
	int			sy;
	char		**tab;
	int			pos;
}				t_tetr;

char			*ft_create_str(char **av);
int				ft_test_str(char *str);
char			**ft_create_dtab(char *str, int nbp);
int				ft_test_tetri(char **tab);
t_tetr			*tetrnew(char **tab);
void			ft_modif_tetri(char **tab);
char			**ft_clean_tetri2(char **tab);
char			**ft_clean_tetri3(char **tab);

char			**ft_init_tab(int nbp);
int				ft_ft(char **tc, t_tetr **tab, int nb, int nbp[2]);
void			ft_freetab(char **tab);
int				ft_test_tetrimo(t_tetr *tab);

void			ft_erase_piece(char **tc, t_tetr *tetri, int nb);
void			ft_place(char **tc, t_tetr *tetri, int ij[2], int nb);

int				ft_puterror(char *s);
int				ft_line(char *s);

t_tetr			**init_tetr_tab(int nb);
#endif
