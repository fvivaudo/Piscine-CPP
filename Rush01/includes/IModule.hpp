/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IModule.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 10:34:04 by thoraffr          #+#    #+#             */
/*   Updated: 2015/01/18 19:48:43 by thoraffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMODULE_HPP
# define IMODULE_HPP

# include <iostream>
# include <sys/utsname.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <unistd.h>
# include <string>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/sysctl.h>
# include <sys/wait.h>
# include <mach/vm_statistics.h>
# include <mach/vm_map.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include <mach/mach_error.h>
# include <sys/socket.h>
# include <sys/sysctl.h>
# include <netinet/in.h>
# include <net/if.h>
# include <net/route.h>
# include <curses.h>
# include <ncurses.h>
# include <string>

class IModule
{
	public:
		virtual void		update() = 0;
};

#endif
