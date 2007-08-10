int ftruncate(int __fd,int __length)
{
  return _chsize (__fd,__length);
}
