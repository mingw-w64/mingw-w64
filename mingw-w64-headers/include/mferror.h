/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _MFERROR_H
#define _MFERROR_H

#define STATUS_SEVERITY(hr) (((hr) >> 30) & 0x3)
#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)

#define FACILITY_MF_WIN32  0x7
#define FACILITY_MF        0xd

#define STATUS_SEVERITY_SUCCESS        0x0
#define STATUS_SEVERITY_INFORMATIONAL  0x1
#define STATUS_SEVERITY_WARNING        0x2
#define STATUS_SEVERITY_ERROR          0x3

#define MF_E_PLATFORM_NOT_INITIALIZED  _HRESULT_TYPEDEF_(0xc00d36b0)
#define MF_E_BUFFERTOOSMALL            _HRESULT_TYPEDEF_(0xc00d36b1)
#define MF_E_INVALIDREQUEST            _HRESULT_TYPEDEF_(0xc00d36b2)
#define MF_E_INVALIDSTREAMNUMBER       _HRESULT_TYPEDEF_(0xc00d36b3)
#define MF_E_INVALIDMEDIATYPE          _HRESULT_TYPEDEF_(0xc00d36b4)
#define MF_E_NOTACCEPTING              _HRESULT_TYPEDEF_(0xc00d36b5)
#define MF_E_NOT_INITIALIZED           _HRESULT_TYPEDEF_(0xc00d36b6)

#endif /* _MFERROR_H */
