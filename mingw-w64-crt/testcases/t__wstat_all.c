#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <wchar.h>

int wmain(int argc, wchar_t *wargv[]) {
	int ret;
	struct _stat st = {};
	struct _stat32 st32 = {};
	struct _stat32i64 st32i64 = {};
	struct _stat64 st64 = {};
	struct _stat64i32 st64i32 = {};
	errno = 0;
	ret = _wstat(argc >= 2 ? wargv[1] : wargv[0], &st);
	printf("_wstat:\n");
	printf("ret=%d\n", ret);
	printf("errno=%d (%s)\n", errno, strerror(errno));
	printf("dev=%u\n", (unsigned)st.st_dev);
	printf("ino=%u\n", (unsigned)st.st_ino);
	printf("mode=%u\n", (unsigned)st.st_mode);
	printf("nlink=%u\n", (unsigned)st.st_nlink);
	printf("uid=%u\n", (unsigned)st.st_uid);
	printf("gid=%u\n", (unsigned)st.st_gid);
	printf("rdev=%u\n", (unsigned)st.st_rdev);
	/* struct _stat always uses 32-bit unsigned size stored in signed _off_t type */
	printf("size=%u\n", (unsigned)st.st_size);
	/* struct _stat uses either 32-bit or 64-bit signed timestamps based on _USE_32BIT_TIME_T */
	printf("atime=%I64d\n", (long long)st.st_atime);
	printf("mtime=%I64d\n", (long long)st.st_mtime);
	printf("ctime=%I64d\n", (long long)st.st_ctime);
	printf("\n");
	errno = 0;
	ret = _wstat32(argc >= 2 ? wargv[1] : wargv[0], &st32);
	printf("_wstat32:\n");
	printf("ret=%d\n", ret);
	printf("errno=%d (%s)\n", errno, strerror(errno));
	printf("dev=%u\n", (unsigned)st32.st_dev);
	printf("ino=%u\n", (unsigned)st32.st_ino);
	printf("mode=%u\n", (unsigned)st32.st_mode);
	printf("nlink=%u\n", (unsigned)st32.st_nlink);
	printf("uid=%u\n", (unsigned)st32.st_uid);
	printf("gid=%u\n", (unsigned)st32.st_gid);
	printf("rdev=%u\n", (unsigned)st32.st_rdev);
	printf("size=%u\n", (unsigned)st32.st_size);
	printf("atime=%d\n", (int)st32.st_atime);
	printf("mtime=%d\n", (int)st32.st_mtime);
	printf("ctime=%d\n", (int)st32.st_ctime);
	printf("\n");
	errno = 0;
	ret = _wstat32i64(argc >= 2 ? wargv[1] : wargv[0], &st32i64);
	printf("_wstat32i64:\n");
	printf("ret=%d\n", ret);
	printf("errno=%d (%s)\n", errno, strerror(errno));
	printf("dev=%u\n", (unsigned)st32i64.st_dev);
	printf("ino=%u\n", (unsigned)st32i64.st_ino);
	printf("mode=%u\n", (unsigned)st32i64.st_mode);
	printf("nlink=%u\n", (unsigned)st32i64.st_nlink);
	printf("uid=%u\n", (unsigned)st32i64.st_uid);
	printf("gid=%u\n", (unsigned)st32i64.st_gid);
	printf("rdev=%u\n", (unsigned)st32i64.st_rdev);
	printf("size=%I64u\n", (unsigned long long)st32i64.st_size);
	printf("atime=%d\n", (int)st32i64.st_atime);
	printf("mtime=%d\n", (int)st32i64.st_mtime);
	printf("ctime=%d\n", (int)st32i64.st_ctime);
	printf("\n");
	errno = 0;
	ret = _wstat64(argc >= 2 ? wargv[1] : wargv[0], &st64);
	printf("_wstat64:\n");
	printf("ret=%d\n", ret);
	printf("errno=%d (%s)\n", errno, strerror(errno));
	printf("dev=%u\n", (unsigned)st64.st_dev);
	printf("ino=%u\n", (unsigned)st64.st_ino);
	printf("mode=%u\n", (unsigned)st64.st_mode);
	printf("nlink=%u\n", (unsigned)st64.st_nlink);
	printf("uid=%u\n", (unsigned)st64.st_uid);
	printf("gid=%u\n", (unsigned)st64.st_gid);
	printf("rdev=%u\n", (unsigned)st64.st_rdev);
	printf("size=%I64u\n", (unsigned long long)st64.st_size);
	printf("atime=%I64d\n", (long long)st64.st_atime);
	printf("mtime=%I64d\n", (long long)st64.st_mtime);
	printf("ctime=%I64d\n", (long long)st64.st_ctime);
	printf("\n");
	errno = 0;
	ret = _wstat64i32(argc >= 2 ? wargv[1] : wargv[0], &st64i32);
	printf("_wstat64i32:\n");
	printf("ret=%d\n", ret);
	printf("errno=%d (%s)\n", errno, strerror(errno));
	printf("dev=%u\n", (unsigned)st64i32.st_dev);
	printf("ino=%u\n", (unsigned)st64i32.st_ino);
	printf("mode=%u\n", (unsigned)st64i32.st_mode);
	printf("nlink=%u\n", (unsigned)st64i32.st_nlink);
	printf("uid=%u\n", (unsigned)st64i32.st_uid);
	printf("gid=%u\n", (unsigned)st64i32.st_gid);
	printf("rdev=%u\n", (unsigned)st64i32.st_rdev);
	printf("size=%u\n", (unsigned)st64i32.st_size);
	printf("atime=%I64d\n", (long long)st64i32.st_atime);
	printf("mtime=%I64d\n", (long long)st64i32.st_mtime);
	printf("ctime=%I64d\n", (long long)st64i32.st_ctime);
	return 0;
}
