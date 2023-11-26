/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 12:48:11 by dnakano           #+#    #+#             */
/*   Updated: 2023/11/26 18:52:55 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *srclst, void *(*dup)(void *), void (*del)(void *))
{
	t_list		*dstlst;
	t_list		*newelem;
	void		*dstcontent;

	dstlst = NULL;
	while (srclst)
	{
		dstcontent = (*dup)(srclst->content);
		if (!dstcontent)
		{
			ft_lstclear(&dstlst, del);
			return (NULL);
		}
		newelem = ft_lstnew(dstcontent);
		if (!newelem)
		{
			(*del)(dstcontent);
			ft_lstclear(&dstlst, del);
			return (NULL);
		}
		ft_lstadd_back(&dstlst, newelem);
		srclst = srclst->next;
	}
	return (dstlst);
}
