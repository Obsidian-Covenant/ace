/*
 * ACE - Automated Corporate Enumerator
 * Copyright (C) 2008 Sipera VIPER Lab
 * Author:  Jason Ostrom
 * Chief Developer:  Arjun Sambamoorthy
 *
 * This file is part of ACE.
 *
 * ACE is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * ACE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Header files to be included */

#ifndef OS_WINDOWS
#undef OS_WINDOWS
#endif

#include <ctype.h>
#include <fcntl.h>
#include <getopt.h>
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>

#ifndef OS_WINDOWS

#if defined(__has_include)
/* Prefer libtirpc-style path if available */
#if __has_include(<tirpc/rpc/types.h>)
#include <tirpc/rpc/types.h>
#define HAVE_TIRPC_RPC_TYPES_H 1
/* Fallback to traditional glibc path */
#elif __has_include(<rpc/types.h>)
#include <rpc/types.h>
#define HAVE_RPC_TYPES_H 1
#else
#error "Neither <tirpc/rpc/types.h> nor <rpc/types.h> found"
#endif
#else
/* Old compilers without __has_include:
   pick the most common case for the world, or keep this simple
*/
#include <rpc/types.h>
#define HAVE_RPC_TYPES_H 1
#endif
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <linux/if_vlan.h>
#include <linux/sockios.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <pcap.h>
#include <pthread.h>
#include <strings.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>

#endif
