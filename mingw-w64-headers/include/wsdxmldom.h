/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WSDXMLDOM
#define _INC_WSDXMLDOM

#ifndef _INC_WSDAPI
#error Please include wsdapi.h instead of this header. This header cannot be used directly.
#endif

#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _WSDXML_TYPE {
  WCHAR *Uri;
  BYTE  *Table;
} WSDXML_TYPE;

typedef const WSDXML_TYPE *PCWSDXML_TYPE;

typedef struct _WSDXML_NAMESPACE {
  const WCHAR *Uri;
  const WCHAR *PreferredPrefix;
  WSDXML_NAME *Names;
  WORD        NamesCount;
  WORD        Encoding;
} WSDXML_NAMESPACE;

typedef const WSDXML_NAMESPACE *PCWSDXML_NAMESPACE;

typedef struct _WSDXML_NAME {
  WSDXML_NAMESPACE *Space;
  WCHAR            *LocalName;
} WSDXML_NAME;

typedef struct _WSDXML_NODE {
  enum DUMMYUNIONNAME {
     ElementType,
     TextType
  }           Type;
  WSDXML_ELEMENT *Parent;
  WSDXML_NODE    *Next;
} WSDXML_NODE;

typedef struct _WSDXML_TEXT {
  WSDXML_NODE Node;
  WCHAR       *Text;
} WSDXML_TEXT;

typedef struct _WSDXML_ATTRIBUTE {
  WSDXML_ELEMENT   *Element;
  WSDXML_ATTRIBUTE *Next;
  WSDXML_NAME      *Name;
  WCHAR            *Value;
} WSDXML_ATTRIBUTE;

typedef struct _WSDXML_PREFIX_MAPPING {
  DWORD                 Refs;
  WSDXML_PREFIX_MAPPING *Next;
  WSDXML_NAMESPACE      *Space;
  WCHAR                 *Prefix;
} WSDXML_PREFIX_MAPPING;

typedef struct _WSDXML_ELEMENT {
  WSDXML_NODE           Node;
  WSDXML_NAME           *Name;
  WSDXML_ATTRIBUTE      *FirstAttribute;
  WSDXML_NODE           *FirstChild;
  WSDXML_PREFIX_MAPPING *PrefixMappings;
} WSDXML_ELEMENT;

typedef struct _WSDXML_ELEMENT_LIST {
  WSDXML_ELEMENT_LIST *Next;
  WSDXML_ELEMENT      *Element;
} WSDXML_ELEMENT_LIST;

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_WSDXMLDOM*/
