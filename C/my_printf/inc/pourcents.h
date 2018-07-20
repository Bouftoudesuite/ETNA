/*
** pourcents.h for my_ls in /Users/habi_a/Documents
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Thu Jul 19 09:49:43 2018 HABI Açal
** Last update Thu Jul 19 09:50:02 2018 HABI Açal
*/

#ifndef				_POURCENTS_H_
# define			_POURCENTS_H_

typedef struct			s_node_pourcents
{
    unsigned int		_position;
    char			_letter;
    struct s_node_pourcents	*_next;
}				t_node_pourcents;


typedef struct			s_list_pourcents
{
    unsigned int		_size;
    t_node_pourcents		*_first;
    t_node_pourcents		*_last;
}				t_list_pourcents;

void				init_list_pourcents(t_list_pourcents *list);
void				push_back_pourcent(t_list_pourcents *list, unsigned int position, char letter);
void				fill_pourcents(t_list_pourcents *list, const char *str);
t_node_pourcents		*get_pourcents(unsigned int key, t_list_pourcents *list);
void				free_list_pourcents(t_list_pourcents *list);

#endif				/* _POURCENTS_H */
