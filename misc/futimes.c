/* futimes -- change access and modification times of open file.  Stub version.
   Copyright (C) 2002 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <sys/time.h>
#include <errno.h>
#include <io.h>
#include <windows.h>

extern int
__hutimes (const HANDLE h, const char *file, const struct timeval tvp[2]);

/* Change the access time of FILE to TVP[0] and
   the modification time of FILE to TVP[1], but do not follow symlinks.  */
int
__futimes (int fd, const struct timeval tvp[2])
{
	HANDLE h = (HANDLE) _get_osfhandle (fd);
	return __hutimes(h, NULL, tvp);
}
weak_alias (__futimes, futimes)
