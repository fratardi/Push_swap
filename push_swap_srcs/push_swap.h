/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:25:02 by fratardi          #+#    #+#             */
/*   Updated: 2019/11/04 15:00:41 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"

/*
**	defines of positions for more readability
*/

# define START_M		0
# define START_A		0
# define M_LEN			stack->memlen
# define A_LEN			stack->a_len
# define B_LEN			stack->b_len
# define MOVES			stack->moves
# define A_START_POS 	0
# define B_START_POS 	M_LEN - B_LEN
# define A_START		stack->mem[START_A]
# define A_START_NEXT 	stack->mem[START_A + 1]
# define B_START		stack->mem[B_START_POS]
# define B_START_NEXT	stack->mem[B_START_POS + 1]
# define A_END			stack->mem[A_LEN - 1]
# define B_END			stack->mem[M_LEN - 1]
# define PIVOT			stack->mem[pivot_pos]

/*
**	defines of return for more readability
*/

# define ERR_A			0x80
# define ERR_B			0x08
# define ERR_AB 		0x88
# define SA				0x10
# define SB				0x01
# define SS				0x11
# define PA				0x20
# define PB				0x02
# define RA				0x30
# define RB				0x03
# define RR				0x33
# define RRA			0x40
# define RRB			0x04
# define RRR			0x44

/*
** Structure of the area memory
*/

typedef struct			s_stack
{
	int					*mem;
	unsigned char		debug;
	unsigned int		memlen;
	unsigned int		a_len;
	unsigned int		b_len;
	unsigned int		pivot_pos;
	unsigned int		moves;
	struct s_pivot		*pivots;
}						t_stack;

/*
**	structure pivot list
*/
typedef	struct			s_pivot
{
	int					nb;
	int					size;
	struct s_pivot		*next;
}						t_pivot;

/*
**	median handling structure
*/
typedef struct			s_median
{
	unsigned int		i;
	unsigned int		pos;
	int					low;
	int					high;
	int					tmp;
	int					ret;
}						t_med;

/*
**	fold structrure
*/

typedef struct			s_fold
{
	int					new_piv;
	unsigned int		stack_l;
	unsigned int		pushed_size;

}						t_fold;

/*
**	parsing structure
*/

typedef struct			s_zone
{
	unsigned int		i;
	unsigned int		y;
	unsigned int		z;
	unsigned int		tmp;
	unsigned int		size;
	int					*zone;
}						t_zone;

/*
**Free
*/

int						free_stack(t_stack *stack);

/*
**	generic funcs
*/

void					ft_swap_int(int *stack, unsigned int pos_a,
	unsigned int pos_b);
void					rotate_zone_up(int *zone_start, size_t n);
void					rotate_zone_down(int *zone_start, size_t n);
unsigned int			ft_area_sorted(int *mem, unsigned int n);

/*
**	push_swap funcs
*/

void					print_stack_content(t_stack *stack);
void					rot_down(int *mem, unsigned int n);
void					rot_up(int *mem, unsigned int n);

/*
** Sorting funcs
*/

void					ft_stackifyfrom(t_stack *stack);
void					unfold_start(t_stack *stack);
void					ft_sort_three_a(t_stack *stack);
void					ft_a_fold(t_stack *stack, unsigned int pushed);
void					ft_recu(t_stack *stack);
void					ft_sort_a(t_stack *stack);

/*
** is_sorted
*/

int						ft_area_sorted_b(t_stack *stack);
int						ft_area_sorted_a(t_stack *stack);

/*
** fold_utils
*/

void					ft_select_from_fold(t_stack *stack);
unsigned int			pso_on_b(t_stack *stack);
int						is_stack_d_null(t_stack *stack, int new_piv,
	unsigned int pushed);

/*
**Pivot_fct
*/

int						ft_is_start_piv(t_stack *stack);
int						get_upper_pivot(t_stack *stack);
int						ft_edit_last_pivot(t_stack *stack);
int						howmany_piv_b(t_stack *stack);
int						is_pivot(t_stack *stack, int pivot);
int						ft_add_pivot(t_stack *stack, unsigned int pivot_pos);
/*
**No Val below stack
*/

char					ft_no_val_below_stack_a(t_stack *stack);
char					ft_no_val_below_stack_b(t_stack *stack);

/*
**	checker funcs
*/

void					size_pivot(t_stack *stack);
void					ft_stackify_to_b(t_stack *stack);
t_stack					ft_init_stacks(int *mem, unsigned int tablen);

void					ft_unstackifier(t_stack *stack);
void					ft_check_debug(char *str, unsigned int *debug);

/*
** Median
*/

unsigned int			pos_precise_med_a(t_stack *stack);
unsigned int			pos_precise_med_b(t_stack *stack);
unsigned int			pos_precise_sector(t_stack *stack,
	unsigned int start_pos, unsigned int end_pos);

/*
** moves
*/

unsigned char			ft_sa(t_stack *stack);
unsigned char			ft_sb(t_stack *stack);
unsigned char			ft_ss(t_stack *stack);
unsigned char			ft_pa(t_stack *stack);
unsigned char			ft_pb(t_stack *stack);
unsigned char			ft_ra(t_stack *stack);
unsigned char			ft_rb(t_stack *stack);
unsigned char			ft_rr(t_stack *stack);
unsigned char			ft_rra(t_stack *stack);
unsigned char			ft_rrb(t_stack *stack);
unsigned char			ft_rrr(t_stack *stack);

/*
**Parsing
*/

t_stack					*ft_init_memory(size_t n);
void					ft_assign_stack(int argc, char **argv);
int						fill_zone(char **av, t_stack *stack);
unsigned char			ft_doobloons(t_stack *stack);
unsigned long			ft_overflowcheck(char *str);
int						ft_tablen(char **str);

#endif
