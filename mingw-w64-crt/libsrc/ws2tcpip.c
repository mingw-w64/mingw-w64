#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <winsock2.h>
#include <ws2tcpip.h>

int IN6_ADDR_EQUAL(const struct in6_addr *a,const struct in6_addr *b) { return (memcmp(a,b,sizeof(struct in6_addr))==0); }
int IN6_IS_ADDR_UNSPECIFIED(const struct in6_addr *a) { return ((a->s6_words[0]==0) && (a->s6_words[1]==0) && (a->s6_words[2]==0) && (a->s6_words[3]==0) && (a->s6_words[4]==0) && (a->s6_words[5]==0) && (a->s6_words[6]==0) && (a->s6_words[7]==0)); }
int IN6_IS_ADDR_LOOPBACK(const struct in6_addr *a) { return ((a->s6_words[0]==0) && (a->s6_words[1]==0) && (a->s6_words[2]==0) && (a->s6_words[3]==0) && (a->s6_words[4]==0) && (a->s6_words[5]==0) && (a->s6_words[6]==0) && (a->s6_words[7]==0x0100)); }
int IN6_IS_ADDR_MULTICAST(const struct in6_addr *a) { return (a->s6_bytes[0]==0xff); }
int IN6_IS_ADDR_LINKLOCAL(const struct in6_addr *a) { return ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
int IN6_IS_ADDR_SITELOCAL(const struct in6_addr *a) { return ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
int IN6_IS_ADDR_V4MAPPED(const struct in6_addr *a) { return ((a->s6_words[0]==0) && (a->s6_words[1]==0) && (a->s6_words[2]==0) && (a->s6_words[3]==0) && (a->s6_words[4]==0) && (a->s6_words[5]==0xffff)); }
int IN6_IS_ADDR_V4COMPAT(const struct in6_addr *a) { return ((a->s6_words[0]==0) && (a->s6_words[1]==0) && (a->s6_words[2]==0) && (a->s6_words[3]==0) && (a->s6_words[4]==0) && (a->s6_words[5]==0) && !((a->s6_words[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
int IN6_IS_ADDR_MC_NODELOCAL(const struct in6_addr *a) { return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
int IN6_IS_ADDR_MC_LINKLOCAL(const struct in6_addr *a) { return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
int IN6_IS_ADDR_MC_SITELOCAL(const struct in6_addr *a) { return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
int IN6_IS_ADDR_MC_ORGLOCAL(const struct in6_addr *a) { return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
int IN6_IS_ADDR_MC_GLOBAL(const struct in6_addr *a) { return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
int IN6ADDR_ISANY(const struct sockaddr_in6 *a) { return ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
int IN6ADDR_ISLOOPBACK(const struct sockaddr_in6 *a) { return ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
void IN6_SET_ADDR_UNSPECIFIED(struct in6_addr *a) { memset(a->s6_bytes,0,sizeof(struct in6_addr)); }
void IN6_SET_ADDR_LOOPBACK(struct in6_addr *a) {
  memset(a->s6_bytes,0,sizeof(struct in6_addr));
  a->s6_bytes[15] = 1;
}
void IN6ADDR_SETANY(struct sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
void IN6ADDR_SETLOOPBACK(struct sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
char *gai_strerrorA(int ecode) {
    DWORD dwMsgLen;
    static char buff[GAI_STRERROR_BUFFER_SIZE + 1];
    dwMsgLen = FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS|FORMAT_MESSAGE_MAX_WIDTH_MASK,NULL,ecode,MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),(LPSTR)buff,GAI_STRERROR_BUFFER_SIZE,NULL);
    return buff;
}
WCHAR *gai_strerrorW(int ecode) {
    DWORD dwMsgLen;
    static WCHAR buff[GAI_STRERROR_BUFFER_SIZE + 1];
    dwMsgLen = FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS|FORMAT_MESSAGE_MAX_WIDTH_MASK,NULL,ecode,MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),(LPWSTR)buff,GAI_STRERROR_BUFFER_SIZE,NULL);
    return buff;
}
