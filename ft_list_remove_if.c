#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{

