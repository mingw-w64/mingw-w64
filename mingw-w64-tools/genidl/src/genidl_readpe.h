/*
    genidl - Generate interface defintion language listing from a
    Portable Executable.
    Copyright (C) 2009-2016  mingw-w64 project

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _GENIDL_READPE_H
#define _GENIDL_READPE_H

#pragma pack(push,1)

/**
 * PE header layout structure
 * @see http://www.jbox.dk/sanos/source/include/os/pe.h.html
 */
typedef struct sDosHeader {
  uint16_t magic;       /**< PE signature, usually MZ or ZM */
  uint16_t cblp;        /**< (PE image size) % (512) */
  uint16_t cp;          /**< Size of PE image in 512 byte blocks */
  uint16_t crlc;        /**< Number of relocation table entries*/
  uint16_t cparhdr;     /**< Size of PE header */
  uint16_t minalloc;    /**< Minimum required memory */
  uint16_t maxalloc;    /**< Maximum required memory */
  uint16_t ss;          /**< Stack seg offset in load module */
  uint16_t sp;          /**< initial value of Stack Pointer */
  uint16_t csum;        /**< Image checksum */
  uint16_t ip;          /**< initial value of Instruction Pointer */
  uint16_t cs;          /**< Initial value of the CS register, relative to the segment the program was loaded at. */
  uint16_t lfarlc;      /**< Offset of the first relocation item in the file. */
  uint16_t ovno;        /**< Overlay number. */
  uint16_t res[4];      /**< Reserved slack space */
  uint16_t oemid;       /**< OEM ID */
  uint16_t oeminfo;     /**< OEM info */
  uint16_t res2[10];    /**< Reserved slack space */
  int32_t lfanew;       /**< Offset to new PE header */
} sDosHeader;

/**
 * Data directory table structure layout
 */
typedef struct sImgDataDir {
  uint32_t virtualAddress;      /**< Relative Virtual Address */
  uint32_t size;                /**< Size of the table in bytes */
} sImgDataDir;

#define IMG_NOOF_DIR_ENTRIES 16

/**
 * PE32 Optional header layout structure
 * @see http://www.microsoft.com/whdc/system/platform/firmware/PECOFF.mspx
 */
typedef struct sImgOptionalHeaders32 {
  uint16_t Magic;                           /**< Identifies the type of image */
  unsigned char MajorLinkerVersion;         /**< Linker major version */
  unsigned char MinorLinkerVersion;         /**< Linker minor version */
  uint32_t SizeOfCode;                      /**< Size of excutable .text and related sections */
  uint32_t SizeOfInitializedData;           /**< Size of initialized .data and related sections */
  uint32_t SizeOfUninitializedData;         /**< Size of unitialized .bss and related sections */
  uint32_t AddressOfEntryPoint;             /**< Address of image entry point relative to image base */
  uint32_t BaseOfCode;                      /**< Address to start of .text section relative to image base */
  uint32_t BaseOfData;                      /**< Address to start of .data section relative to image base */
  uint32_t ImageBase;                       /**< Prefered load address of image */
  uint32_t SectionAlignment;                /**< Section allignment when loaded in memory */
  uint32_t FileAlignment;                   /**< Section allignment of image on disk */
  uint16_t MajorOperatingSystemVersion;     /**< Minimum required OS version (Major version) */
  uint16_t MinorOperatingSystemVersion;     /**< Minimum required OS version (Minor version) */
  uint16_t MajorImageVersion;               /**< PE Image major version */
  uint16_t MinorImageVersion;               /**< PE Image minor version */
  uint16_t MajorSubsystemVersion;           /**< Subsystem major version */
  uint16_t MinorSubsystemVersion;           /**< Subsystem minor version */
  uint32_t Win32VersionValue;               /**< Reserved, set to 0 */
  uint32_t SizeOfImage;                     /**< Total size of image in multiples of SectionAlignment */
  uint32_t SizeOfHeaders;                   /**< Size of DOS stub header, PE header, and section headers in multiples of SectionAlignment */
  uint32_t CheckSum;                        /**< Image checksum */
  uint16_t Subsystem;                       /**< Image subsystem */
  uint16_t DllCharacteristics;              /**< DLL characteristics */
  uint32_t SizeOfStackReserve;              /**< Amount of stack to reserve */
  uint32_t SizeOfStackCommit;               /**< Amount of stack to commit on start */
  uint32_t SizeOfHeapReserve;               /**< Amount of heap to reserve */
  uint32_t SizeOfHeapCommit;                /**< Amount of heap to commit on start */
  uint32_t LoaderFlags;                     /**< Reserved, set to 0 */
  uint32_t NumberOfRvaAndSizes;             /**< Number of DataDirectory entries at the end of the header */
  sImgDataDir DataDirectory[IMG_NOOF_DIR_ENTRIES]; /**< Data directories */
} sImgOptionalHeaders32;

/**
 * PE32+ Optional header layout structure
 * @see http://www.microsoft.com/whdc/system/platform/firmware/PECOFF.mspx
 */
typedef struct sImgOptionalHeaders64 {
  uint16_t Magic;                           /**< Identifies the type of image */
  unsigned char MajorLinkerVersion;         /**< Linker major version */
  unsigned char MinorLinkerVersion;         /**< Linker minor version */
  uint32_t SizeOfCode;                      /**< Size of excutable .text and related sections */
  uint32_t SizeOfInitializedData;           /**< Size of initialized .data and related sections */
  uint32_t SizeOfUninitializedData;         /**< Size of unitialized .bss and related sections */
  uint32_t AddressOfEntryPoint;             /**< Address of image entry point relative to image base */
  uint32_t BaseOfCode;                      /**< Address to start of .text section relative to image base */
  uint64_t ImageBase;                       /**< Prefered load address of image */
  uint32_t SectionAlignment;                /**< Section allignment when loaded in memory */
  uint32_t FileAlignment;                   /**< Section allignment of image on disk */
  uint16_t MajorOperatingSystemVersion;     /**< Minimum required OS version (Major version) */
  uint16_t MinorOperatingSystemVersion;     /**< Minimum required OS version (Minor version) */
  uint16_t MajorImageVersion;               /**< PE Image major version */
  uint16_t MinorImageVersion;               /**< PE Image minor version */
  uint16_t MajorSubsystemVersion;           /**< Subsystem major version */
  uint16_t MinorSubsystemVersion;           /**< Subsystem minor version */
  uint32_t Win32VersionValue;               /**< Reserved, set to 0 */
  uint32_t SizeOfImage;                     /**< Total size of image in multiples of SectionAlignment */
  uint32_t SizeOfHeaders;                   /**< Size of DOS stub header, PE header, and section headers in multiples of SectionAlignment */
  uint32_t CheckSum;                        /**< Image checksum */
  uint16_t Subsystem;                       /**< Image subsystem */
  uint16_t DllCharacteristics;              /**< DLL characteristics */
  uint64_t SizeOfStackReserve;              /**< Amount of stack to reserve */
  uint64_t SizeOfStackCommit;               /**< Amount of stack to commit on start */
  uint64_t SizeOfHeapReserve;               /**< Amount of heap to reserve */
  uint64_t SizeOfHeapCommit;                /**< Amount of heap to commit on start */
  uint32_t LoaderFlags;                     /**< Reserved, set to 0 */
  uint32_t NumberOfRvaAndSizes;             /**< Number of DataDirectory entries at the end of the header */
  sImgDataDir DataDirectory[IMG_NOOF_DIR_ENTRIES]; /**< Data directories */
} sImgOptionalHeaders64;

/**
 * COFF header structure layout
 */
typedef struct sImgFileHeader {
  uint16_t Machine;                         /**< Machine ID to run image */
  uint16_t NumberOfSections;                /**< Number of sections, maximum of 96 */
  uint32_t TimeDateStamp;                   /**< 32bit time_t seconds since epoch */
  uint32_t PointerToSymbolTable;            /**< File offset to COFF symbol table */
  uint32_t NumberOfSymbols;                 /**< Number of symbol entries in COFF symbol table*/
  uint16_t SizeOfOptionalHeader;            /**< Size of optional header */
  uint16_t Characteristics;                 /**< Object/Image attribute flags */
} sImgFileHeader;

#define IMG_SIZEOF_NT_OPTIONAL32_HEADER 224
#define IMG_SIZEOF_NT_OPTIONAL64_HEADER 240

/**
 * PE32+ Headers structure layout on disk
 */
typedef struct sImgNtHeaders64 {
  uint32_t Signature;                       /**< PE\0\0 signature */
  sImgFileHeader FileHeader;                /**< Common PE32/PE32+ header */
  sImgOptionalHeaders64 OptionalHeader;     /**< Optional fields for 64bit PE32+ executables */
} sImgNtHeaders64;

/**
 * PE32 Headers structure layout on disk
 */
typedef struct sImgNtHeaders32 {
  uint32_t Signature;                       /**< PE\0\0 signature */
  sImgFileHeader FileHeader;                /**< Common PE32/PE32+ header */
  sImgOptionalHeaders32 OptionalHeader;     /**< Optional fields for 32bit PE32 executables */
} sImgNtHeaders32;

/**
 * Generic object type to hold both PE32 and PE32+ headers
 */
typedef union uImgHeader {
  sImgNtHeaders32 hdr32;                    /**< PE32 header */
  sImgNtHeaders64 hdr64;                    /**< PE32+ header */
} uImgHeader;

#define IMG_FIRST_SECTION(ntheader) ((sImgSectionHdr *) ((ULONG_PTR)ntheader + FIELD_OFFSET(IMAGE_NT_HEADERS,OptionalHeader) + ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.SizeOfOptionalHeader))

/**
 *  Section header structure layout
 */
typedef struct sImgSectionHdr {
  unsigned char Name[8];            /**< Section Name */
  union {
    uint32_t PhysicalAddress;       /**< */
    uint32_t VirtualSize;           /**< Total section size when loaded in memory */
  } Misc;
  uint32_t VirtualAddress;          /**< Section offset from image base */
  uint32_t SizeOfRawData;           /**< Size of section on disk */
  uint32_t PointerToRawData;        /**< Pointer to first page of section */
  uint32_t PointerToRelocations;    /**< Pointer to section relocation entries */
  uint32_t PointerToLinenumbers;    /**< Pointer to COFF debug line-number entries */
  uint16_t NumberOfRelocations;     /**< Number of relocation entries in section */
  uint16_t NumberOfLinenumbers;     /**< Number of line-number entries in section */
  uint32_t Characteristics;         /**< Section characteristics flag */
} sImgSectionHdr;

/**
 * Finds PE signature in file associated with fp
 * @param[in] fp Pointer to a file
 * @param[out] be64 indicates if PE is 64bit if 1, 32bit otherwise
 *@return Offset at which a PE signature is found
 */
int32_t genidl_ispe (FILE *fp, int32_t *be64);

/**
 * Reads the typelib from a file
 * @param[in] fp Pointer to file
 * @param[in] nores typelib to read in directory
 * @param[out] pDta raw typelib info
 * @param[out] szDta size of raw typelib information
 * @return 1 for success
 */
int32_t genidl_pe_typelib_resource_read (FILE *fp, int32_t noRes, unsigned char **pDta, size_t *szDta);

/**
 * Counts the number of typelib resources
 * @param[in] fp File to check
 * @return number of found typelib resource
 */
int32_t genidl_pe_typelib_resource_count (FILE *fp);

typedef struct sImgResourceDataEntry {
  uint32_t OffsetToData;
  uint32_t Size;
  uint32_t CodePage;
  uint32_t Reserved;
} sImgResourceDataEntry;

#ifdef __GNUC__
  __extension__
#endif
typedef struct sImgResourceDirectoryEntry {
#ifdef __GNUC__
  __extension__
#endif
  union {
#ifdef __GNUC__
    __extension__
#endif
    struct {
      uint32_t NameOffset:31;
      uint32_t NameIsString:1;
    };
    uint32_t Name;
    uint16_t Id;
  };
#ifdef __GNUC__
  __extension__
#endif
  union {
    uint32_t OffsetToData;
#ifdef __GNUC__
    __extension__
#endif
    struct {
      uint32_t OffsetToDirectory:31;
      uint32_t DataIsDirectory:1;
    };
  };
} sImgResourceDirectoryEntry;

typedef struct sImgResourceDirStringWC {
  uint16_t Length;
  uint16_t NameString[1];
} sImgResourceDirStringWC;

typedef struct sImgResourceDirectory {
  uint32_t Characteristics;
  uint32_t TimeDateStamp;
  uint16_t MajorVersion;
  uint16_t MinorVersion;
  uint16_t NumberOfNamedEntries;
  uint16_t NumberOfIdEntries;
} sImgResourceDirectory;

#define GENIDL_IMG_RESDATA_IS_DIR 0x80000000
#define GENIDL_IMG_RESNAME_IS_STR 0x80000000

#pragma pack(pop)

#endif
