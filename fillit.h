/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:03:02 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/11 09:30:50 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

typedef struct		s_elem {
	char			arr[4][4];
	char			letter;
	int				ax;
	int				ay;
	int				bx;
	int				by;
	int				cx;
	int				cy;
	int				dx;
	int				dy;
	int				hei;
	int				wid;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

int					ft_error_msg(int no, t_elem **p_node);

void				ft_print_square(char *map, int dim);

int					ft_count_elems(t_elem **p_node);
int					ft_free_list(t_elem **p_node);

int					ft_add_end_node(t_elem **p_node, char tab[4][4]);
t_elem				*ft_get_elems(int fd, t_elem **p_node);

int					ft_count_dots_and_hashes(char tab[4][4]);
int					ft_count_contacts(char tab[4][4], int i, int j);
int					ft_check_shape(char tab[4][4], t_elem **p_node);
int					ft_count_tetriminos(t_elem **p_node);
int					ft_check_elems(t_elem **p_node);

int					ft_measure_gap_vert(t_elem **p_node);
int					ft_measure_gap_horz(t_elem **p_node);
void				ft_translate(t_elem **p_node, int vert, int horz);
void				ft_align_elems(t_elem **p_node);

int					ft_get_hei(t_elem *node);
int					ft_get_wid(t_elem *node);
void				ft_measure_elems(t_elem **p_node);

void				ft_init_coords(t_elem **p_node, int i, int j, int blckidx);
void				ft_get_coords(t_elem **p_node);

int					ft_check_bounds(t_elem *node, int coords, int dim);
int					ft_try_dim(t_elem **p_node, int dim);

void				ft_init_map(char *p, int dim);
int					ft_remove_piece(t_elem *node, char *map, int dim);
int					ft_is_present(t_elem *node, char *map, int dim);

#endif
