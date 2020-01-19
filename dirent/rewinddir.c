/* Copyright (C) 1991, 1995, 1996, 1997 Free Software Foundation, Inc.
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

#include <errno.h>
#include <stddef.h>
#include <dirent.h>
#include <windows.h>

/* Rewind DIRP to the beginning of the directory.  */
void
__rewinddir (dirp)
     DIR *dirp;
{
  if (dirp == NULL) {
     __set_errno (EINVAL);
     return ;
  }
  __libc_lock_lock (dirp->lock);
	
  /* If we have a find-handle open, close it.  */
   if (dirp->fd != INVALID_DIRFD) {
      if (!FindClose ((HANDLE) dirp->fd)) {
	  	set_werrno;
	  }	
      dirp->fd = INVALID_DIRFD;
    }  
   dirp->filepos = 1;
  /* No way to indicate failure.	*/
  __libc_lock_unlock (dirp->lock);
}

weak_alias (__rewinddir, rewinddir)
