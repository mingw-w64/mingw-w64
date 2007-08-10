#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <io.h>
#include <direct.h>
#include <dirent.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <tchar.h>
#define SUFFIX _T("*")
#define SLASH _T("\\")

_TDIR *
_topendir (const _TCHAR *szPath)
{
  _TDIR *nd;
  unsigned int rc;
  _TCHAR szFullPath[MAX_PATH];

  errno = 0;

  if (!szPath)
    {
      errno = EFAULT;
      return (_TDIR *) 0;
    }

  if (szPath[0] == _T('\0'))
    {
      errno = ENOTDIR;
      return (_TDIR *) 0;
    }

  rc = GetFileAttributes (szPath);
  if (rc == (unsigned int)-1)
    {

      errno = ENOENT;
      return (_TDIR *) 0;
    }
  if (!(rc & FILE_ATTRIBUTE_DIRECTORY))
    {

      errno = ENOTDIR;
      return (_TDIR *) 0;
    }

  _tfullpath (szFullPath,szPath,MAX_PATH);

  nd = (_TDIR *) malloc (sizeof (_TDIR) + (_tcslen (szFullPath)
					   + _tcslen (SLASH)
					   + _tcslen (SUFFIX) + 1)
					  * sizeof (_TCHAR));

  if (!nd)
    {

      errno = ENOMEM;
      return (_TDIR *) 0;
    }

  _tcscpy (nd->dd_name,szFullPath);

  if (nd->dd_name[0] != _T('\0')
      && _tcsrchr (nd->dd_name,_T('/')) != nd->dd_name
					    + _tcslen (nd->dd_name) - 1
      && _tcsrchr (nd->dd_name,_T('\\')) != nd->dd_name
      					     + _tcslen (nd->dd_name) - 1)
    {
      _tcscat (nd->dd_name,SLASH);
    }

  _tcscat (nd->dd_name,SUFFIX);

  nd->dd_handle = -1;

  nd->dd_stat = 0;

  nd->dd_dir.d_ino = 0;
  nd->dd_dir.d_reclen = 0;
  nd->dd_dir.d_namlen = 0;
  memset (nd->dd_dir.d_name,0,FILENAME_MAX);

  return nd;
}

struct _tdirent *
_treaddir (_TDIR * dirp)
{
  errno = 0;

  if (!dirp)
    {
      errno = EFAULT;
      return (struct _tdirent *) 0;
    }

  if (dirp->dd_stat < 0)
    {

      return (struct _tdirent *) 0;
    }
  else if (dirp->dd_stat == 0)
    {

      dirp->dd_handle = _tfindfirst (dirp->dd_name,&(dirp->dd_dta));

      if (dirp->dd_handle == -1)
	{

	  dirp->dd_stat = -1;
	}
      else
	{
	  dirp->dd_stat = 1;
	}
    }
  else
    {

      if (_tfindnext (dirp->dd_handle,&(dirp->dd_dta)))
	{

	  DWORD winerr = GetLastError ();
	  if (winerr == ERROR_NO_MORE_FILES)
	    errno = 0;
	  _findclose (dirp->dd_handle);
	  dirp->dd_handle = -1;
	  dirp->dd_stat = -1;
	}
      else
	{

	  dirp->dd_stat++;
	}
    }

  if (dirp->dd_stat > 0)
    {

      dirp->dd_dir.d_namlen = _tcslen (dirp->dd_dta.name);
      _tcscpy (dirp->dd_dir.d_name,dirp->dd_dta.name);
      return &dirp->dd_dir;
    }

  return (struct _tdirent *) 0;
}

int
_tclosedir (_TDIR * dirp)
{
  int rc;

  errno = 0;
  rc = 0;

  if (!dirp)
    {
      errno = EFAULT;
      return -1;
    }

  if (dirp->dd_handle != -1)
    {
      rc = _findclose (dirp->dd_handle);
    }

  free (dirp);

  return rc;
}

void
_trewinddir (_TDIR * dirp)
{
  errno = 0;

  if (!dirp)
    {
      errno = EFAULT;
      return;
    }

  if (dirp->dd_handle != -1)
    {
      _findclose (dirp->dd_handle);
    }

  dirp->dd_handle = -1;
  dirp->dd_stat = 0;
}

long
_ttelldir (_TDIR * dirp)
{
  errno = 0;

  if (!dirp)
    {
      errno = EFAULT;
      return -1;
    }
  return dirp->dd_stat;
}

void
_tseekdir (_TDIR * dirp,long lPos)
{
  errno = 0;

  if (!dirp)
    {
      errno = EFAULT;
      return;
    }

  if (lPos < -1)
    {

      errno = EINVAL;
      return;
    }
  else if (lPos == -1)
    {

      if (dirp->dd_handle != -1)
	{
	  _findclose (dirp->dd_handle);
	}
      dirp->dd_handle = -1;
      dirp->dd_stat = -1;
    }
  else
    {

      _trewinddir (dirp);

      while ((dirp->dd_stat < lPos) && _treaddir (dirp));
    }
}
