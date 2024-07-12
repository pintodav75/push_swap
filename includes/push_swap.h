/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 01:42:57 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/13 00:58:26 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdio.h>
# include <string.h>

# define STRAT_A 1 // les 2 vers le haut
# define STRAT_B 2 // les 2 vers le bas
# define STRAT_C 3 // A vers le bas et b vers le haut
# define STRAT_D 4 // B vers le bas et A vers le haut

typedef struct s_lst
{
	int				n;
	struct s_lst	*next;
}					t_lst;

typedef struct s_score
{
	int				n;
	int				target;
	int				strat;
	int				cost;
}					t_score;

int					parse(char **av);
void				ft_swap(int *a, int *b);
int					compute(t_lst **head_a, t_lst **head_b);
int					get_position(t_lst *head, int n);
void				get_cheapest_cost_n(t_lst **head_a, t_lst **head_b,
						t_score *score);
long long int		ft_abs(long long int a);
char				**dup_map(char **map);
char				**free_strs(char **strs);
size_t				get_tab_len(char **tab);

/* big sort */
void				ft_big_sort(t_lst **head_a, t_lst **head_b);
void				make_empty_b(t_lst **head_a, t_lst **head_b);
int					get_cost(t_lst **head_a, t_lst **head_b, int n, int *strat);
void				final_rotate_a(t_lst **head_a);

/* helpers big sort */
int					get_min_score(const int *tab, int *strat);
int					get_position(t_lst *head, int n);
int					get_target(t_lst **head_a, int n);
int					max(int a, int b);
int					min(int a, int b);
void				ft_init_second_stack(t_lst **head_a, t_lst **head_b);

/* lst utils*/
t_lst				*ft_lst_create_node(int n);
void				ft_lst_push_front(t_lst **head, t_lst *node);
void				ft_lst_push_back(t_lst **head, t_lst *node);

/* helpers*/
int					ft_lst_is_sort(t_lst *head);
int					ft_lst_size(t_lst *head);
int					ft_lst_get_min(t_lst *head, int *index);
t_lst				*ft_lst_get_max(t_lst *head, int *index);

/* instructions */
void				ft_sa(t_lst **head, int d);
void				ft_sb(t_lst **head, int d);
void				ft_ss(t_lst **head_a, t_lst **head_b);

void				ft_pa(t_lst **head_a, t_lst **head_b);
void				ft_pb(t_lst **head_b, t_lst **head_a);

void				ft_ra(t_lst **head, int d);
void				ft_rb(t_lst **head, int d);
void				ft_rr(t_lst **head_a, t_lst **head_b);

void				ft_rra(t_lst **head, int d);
void				ft_rrb(t_lst **head, int d);
void				ft_rrr(t_lst **head_a, t_lst **head_b);

void				ft_p(t_lst **head_from, t_lst **head_to);
/* Quick sort */
void				ft_sort_by_3(t_lst **head);
void				ft_sort_by_4(t_lst **head_a, t_lst **head_b);
void				ft_sort_by_5(t_lst **head_a, t_lst **head_b);

/* strat */

void				apply_strat(t_lst **head_a, t_lst **head_b, t_score score);
void				apply_a(t_lst **head_a, t_lst **head_b, t_score score);
void				apply_b(t_lst **head_a, t_lst **head_b, t_score score);
void				apply_c(t_lst **head_a, t_lst **head_b, t_score score);
void				apply_d(t_lst **head_a, t_lst **head_b, t_score score);

/* Free */
void				free_lst(t_lst *head);

#endif
