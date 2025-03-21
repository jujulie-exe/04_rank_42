/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:00:02 by jfranco           #+#    #+#             */
/*   Updated: 2025/02/11 14:26:07 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);

#endif
