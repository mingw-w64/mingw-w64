/* This file is generated with wmc version 1.4-rc5. Do not edit! */
/* Source : bugcodes.mc */
/* Cmdline: wmc bugcodes.mc */
/* Date   : Mon Feb 27 10:01:33 2012 */

#ifndef __WMCGENERATED_4f4b46e6_H
#define __WMCGENERATED_4f4b46e6_H

/* Severity codes */
#define STATUS_SEVERITY_ERROR	0x3
#define STATUS_SEVERITY_INFORMATIONAL	0x1
#define STATUS_SEVERITY_SUCCESS	0x0
#define STATUS_SEVERITY_WARNING	0x2

/* Facility codes */
#define FACILITY_IO_ERROR_CODE	0x4
#define FACILITY_RUNTIME	0x2
#define FACILITY_STUBS	0x3
#define FACILITY_SYSTEM	0x0

/* Message definitions */

/*  Created by : Marc Piulachs. */
/*  This source code is offered for use in the public domain. */


/*  ntoskrnl.exe bug codes  */


/*  message definitions */


/* MessageId  : 0x4000007e */
/* Approximate msg: ReactOS (R) Kernel Version %hs (Build %u%hs) */
#define WINDOWS_NT_BANNER	((ULONG)0x4000007eL)

/* MessageId  : 0x40000087 */
/* Approximate msg: Service Pack */
#define WINDOWS_NT_CSD_STRING	((ULONG)0x40000087L)

/* MessageId  : 0x40000088 */
/* Approximate msg: %u System Processor [%u MB Memory] %Z */
#define WINDOWS_NT_INFO_STRING	((ULONG)0x40000088L)

/* MessageId  : 0x40000089 */
/* Approximate msg: MultiProcessor Kernel */
#define WINDOWS_NT_MP_STRING	((ULONG)0x40000089L)

/* MessageId  : 0x4000008a */
/* Approximate msg: A kernel thread terminated while holding a mutex */
#define THREAD_TERMINATE_HELD_MUTEX	((ULONG)0x4000008aL)

/* MessageId  : 0x4000009d */
/* Approximate msg: %u System Processors [%u MB Memory] %Z */
#define WINDOWS_NT_INFO_STRING_PLURAL	((ULONG)0x4000009dL)

/* MessageId  : 0x8000007f */
/* Approximate msg: A problem has been detected and ReactOS has been shut down to prevent damage */
#define BUGCHECK_MESSAGE_INTRO	((ULONG)0x8000007fL)

/* MessageId  : 0x80000080 */
/* Approximate msg: The problem seems to be caused by the following file: */
#define BUGCODE_ID_DRIVER	((ULONG)0x80000080L)

/* MessageId  : 0x80000081 */
/* Approximate msg: If this is the first time you've seen this Stop error screen, */
#define PSS_MESSAGE_INTRO	((ULONG)0x80000081L)

/* MessageId  : 0x80000082 */
/* Approximate msg: Check to make sure any new hardware or software is properly installed. */
#define BUGCODE_PSS_MESSAGE	((ULONG)0x80000082L)

/* MessageId  : 0x80000083 */
/* Approximate msg: Technical information: */
#define BUGCHECK_TECH_INFO	((ULONG)0x80000083L)

/* MessageId  : 0x00000000 */
/* Approximate msg: The bug code is undefined. Please use an existing code instead. */
#define UNDEFINED_BUG_CODE	((ULONG)0x00000000L)

/* MessageId  : 0x00000001 */
/* Approximate msg: APC_INDEX_MISMATCH */
#define APC_INDEX_MISMATCH	((ULONG)0x00000001L)

/* MessageId  : 0x00000002 */
/* Approximate msg: DEVICE_QUEUE_NOT_BUSY */
#define DEVICE_QUEUE_NOT_BUSY	((ULONG)0x00000002L)

/* MessageId  : 0x00000003 */
/* Approximate msg: INVALID_AFFINITY_SET */
#define INVALID_AFFINITY_SET	((ULONG)0x00000003L)

/* MessageId  : 0x00000004 */
/* Approximate msg: INVALID_DATA_ACCESS_TRAP */
#define INVALID_DATA_ACCESS_TRAP	((ULONG)0x00000004L)

/* MessageId  : 0x00000005 */
/* Approximate msg: INVALID_PROCESS_ATTACH_ATTEMPT */
#define INVALID_PROCESS_ATTACH_ATTEMPT	((ULONG)0x00000005L)

/* MessageId  : 0x00000006 */
/* Approximate msg: INVALID_PROCESS_DETACH_ATTEMPT */
#define INVALID_PROCESS_DETACH_ATTEMPT	((ULONG)0x00000006L)

/* MessageId  : 0x00000007 */
/* Approximate msg: INVALID_SOFTWARE_INTERRUPT */
#define INVALID_SOFTWARE_INTERRUPT	((ULONG)0x00000007L)

/* MessageId  : 0x00000008 */
/* Approximate msg: IRQL_NOT_DISPATCH_LEVEL */
#define IRQL_NOT_DISPATCH_LEVEL	((ULONG)0x00000008L)

/* MessageId  : 0x00000009 */
/* Approximate msg: IRQL_NOT_GREATER_OR_EQUAL */
#define IRQL_NOT_GREATER_OR_EQUAL	((ULONG)0x00000009L)

/* MessageId  : 0x0000000a */
/* Approximate msg: IRQL_NOT_LESS_OR_EQUAL */
#define IRQL_NOT_LESS_OR_EQUAL	((ULONG)0x0000000aL)

/* MessageId  : 0x0000000b */
/* Approximate msg: NO_EXCEPTION_HANDLING_SUPPORT */
#define NO_EXCEPTION_HANDLING_SUPPORT	((ULONG)0x0000000bL)

/* MessageId  : 0x0000000c */
/* Approximate msg: MAXIMUM_WAIT_OBJECTS_EXCEEDED */
#define MAXIMUM_WAIT_OBJECTS_EXCEEDED	((ULONG)0x0000000cL)

/* MessageId  : 0x0000000d */
/* Approximate msg: MUTEX_LEVEL_NUMBER_VIOLATION */
#define MUTEX_LEVEL_NUMBER_VIOLATION	((ULONG)0x0000000dL)

/* MessageId  : 0x0000000e */
/* Approximate msg: NO_USER_MODE_CONTEXT */
#define NO_USER_MODE_CONTEXT	((ULONG)0x0000000eL)

/* MessageId  : 0x0000000f */
/* Approximate msg: SPIN_LOCK_ALREADY_OWNED */
#define SPIN_LOCK_ALREADY_OWNED	((ULONG)0x0000000fL)

/* MessageId  : 0x00000010 */
/* Approximate msg: SPIN_LOCK_NOT_OWNED */
#define SPIN_LOCK_NOT_OWNED	((ULONG)0x00000010L)

/* MessageId  : 0x00000011 */
/* Approximate msg: THREAD_NOT_MUTEX_OWNER */
#define THREAD_NOT_MUTEX_OWNER	((ULONG)0x00000011L)

/* MessageId  : 0x00000012 */
/* Approximate msg: TRAP_CAUSE_UNKNOWN */
#define TRAP_CAUSE_UNKNOWN	((ULONG)0x00000012L)

/* MessageId  : 0x00000013 */
/* Approximate msg: EMPTY_THREAD_REAPER_LIST */
#define EMPTY_THREAD_REAPER_LIST	((ULONG)0x00000013L)

/* MessageId  : 0x00000014 */
/* Approximate msg: The thread reaper was handed a thread to reap, but the thread's process' */
#define CREATE_DELETE_LOCK_NOT_LOCKED	((ULONG)0x00000014L)

/* MessageId  : 0x00000015 */
/* Approximate msg: LAST_CHANCE_CALLED_FROM_KMODE */
#define LAST_CHANCE_CALLED_FROM_KMODE	((ULONG)0x00000015L)

/* MessageId  : 0x00000016 */
/* Approximate msg: CID_HANDLE_CREATION */
#define CID_HANDLE_CREATION	((ULONG)0x00000016L)

/* MessageId  : 0x00000017 */
/* Approximate msg: CID_HANDLE_DELETION */
#define CID_HANDLE_DELETION	((ULONG)0x00000017L)

/* MessageId  : 0x00000018 */
/* Approximate msg: REFERENCE_BY_POINTER */
#define REFERENCE_BY_POINTER	((ULONG)0x00000018L)

/* MessageId  : 0x00000019 */
/* Approximate msg: BAD_POOL_HEADER */
#define BAD_POOL_HEADER	((ULONG)0x00000019L)

/* MessageId  : 0x0000001a */
/* Approximate msg: MEMORY_MANAGEMENT */
#define MEMORY_MANAGEMENT	((ULONG)0x0000001aL)

/* MessageId  : 0x0000001b */
/* Approximate msg: PFN_SHARE_COUNT */
#define PFN_SHARE_COUNT	((ULONG)0x0000001bL)

/* MessageId  : 0x0000001c */
/* Approximate msg: PFN_REFERENCE_COUNT */
#define PFN_REFERENCE_COUNT	((ULONG)0x0000001cL)

/* MessageId  : 0x0000001d */
/* Approximate msg: NO_SPINLOCK_AVAILABLE */
#define NO_SPINLOCK_AVAILABLE	((ULONG)0x0000001dL)

/* MessageId  : 0x0000001e */
/* Approximate msg: Check to be sure you have adequate disk space. If a driver is */
#define KMODE_EXCEPTION_NOT_HANDLED	((ULONG)0x0000001eL)

/* MessageId  : 0x0000001f */
/* Approximate msg: SHARED_RESOURCE_CONV_ERROR */
#define SHARED_RESOURCE_CONV_ERROR	((ULONG)0x0000001fL)

/* MessageId  : 0x00000020 */
/* Approximate msg: KERNEL_APC_PENDING_DURING_EXIT */
#define KERNEL_APC_PENDING_DURING_EXIT	((ULONG)0x00000020L)

/* MessageId  : 0x00000021 */
/* Approximate msg: QUOTA_UNDERFLOW */
#define QUOTA_UNDERFLOW	((ULONG)0x00000021L)

/* MessageId  : 0x00000022 */
/* Approximate msg: FILE_SYSTEM */
#define FILE_SYSTEM	((ULONG)0x00000022L)

/* MessageId  : 0x00000023 */
/* Approximate msg: Disable or uninstall any anti-virus, disk defragmentation */
#define FAT_FILE_SYSTEM	((ULONG)0x00000023L)

/* MessageId  : 0x00000024 */
/* Approximate msg: NTFS_FILE_SYSTEM */
#define NTFS_FILE_SYSTEM	((ULONG)0x00000024L)

/* MessageId  : 0x00000025 */
/* Approximate msg: NPFS_FILE_SYSTEM */
#define NPFS_FILE_SYSTEM	((ULONG)0x00000025L)

/* MessageId  : 0x00000026 */
/* Approximate msg: CDFS_FILE_SYSTEM */
#define CDFS_FILE_SYSTEM	((ULONG)0x00000026L)

/* MessageId  : 0x00000027 */
/* Approximate msg: RDR_FILE_SYSTEM */
#define RDR_FILE_SYSTEM	((ULONG)0x00000027L)

/* MessageId  : 0x00000028 */
/* Approximate msg: CORRUPT_ACCESS_TOKEN */
#define CORRUPT_ACCESS_TOKEN	((ULONG)0x00000028L)

/* MessageId  : 0x00000029 */
/* Approximate msg: SECURITY_SYSTEM */
#define SECURITY_SYSTEM	((ULONG)0x00000029L)

/* MessageId  : 0x0000002a */
/* Approximate msg: INCONSISTENT_IRP */
#define INCONSISTENT_IRP	((ULONG)0x0000002aL)

/* MessageId  : 0x0000002b */
/* Approximate msg: PANIC_STACK_SWITCH */
#define PANIC_STACK_SWITCH	((ULONG)0x0000002bL)

/* MessageId  : 0x0000002c */
/* Approximate msg: PORT_DRIVER_INTERNAL */
#define PORT_DRIVER_INTERNAL	((ULONG)0x0000002cL)

/* MessageId  : 0x0000002d */
/* Approximate msg: SCSI_DISK_DRIVER_INTERNAL */
#define SCSI_DISK_DRIVER_INTERNAL	((ULONG)0x0000002dL)

/* MessageId  : 0x0000002e */
/* Approximate msg: Run system diagnostics supplied by your hardware manufacturer. */
#define DATA_BUS_ERROR	((ULONG)0x0000002eL)

/* MessageId  : 0x0000002f */
/* Approximate msg: INSTRUCTION_BUS_ERROR */
#define INSTRUCTION_BUS_ERROR	((ULONG)0x0000002fL)

/* MessageId  : 0x00000030 */
/* Approximate msg: SET_OF_INVALID_CONTEXT */
#define SET_OF_INVALID_CONTEXT	((ULONG)0x00000030L)

/* MessageId  : 0x00000031 */
/* Approximate msg: PHASE0_INITIALIZATION_FAILED */
#define PHASE0_INITIALIZATION_FAILED	((ULONG)0x00000031L)

/* MessageId  : 0x00000032 */
/* Approximate msg: PHASE1_INITIALIZATION_FAILED */
#define PHASE1_INITIALIZATION_FAILED	((ULONG)0x00000032L)

/* MessageId  : 0x00000033 */
/* Approximate msg: UNEXPECTED_INITIALIZATION_CALL */
#define UNEXPECTED_INITIALIZATION_CALL	((ULONG)0x00000033L)

/* MessageId  : 0x00000034 */
/* Approximate msg: CACHE_MANAGER */
#define CACHE_MANAGER	((ULONG)0x00000034L)

/* MessageId  : 0x00000035 */
/* Approximate msg: NO_MORE_IRP_STACK_LOCATIONS */
#define NO_MORE_IRP_STACK_LOCATIONS	((ULONG)0x00000035L)

/* MessageId  : 0x00000036 */
/* Approximate msg: DEVICE_REFERENCE_COUNT_NOT_ZERO */
#define DEVICE_REFERENCE_COUNT_NOT_ZERO	((ULONG)0x00000036L)

/* MessageId  : 0x00000037 */
/* Approximate msg: FLOPPY_INTERNAL_ERROR */
#define FLOPPY_INTERNAL_ERROR	((ULONG)0x00000037L)

/* MessageId  : 0x00000038 */
/* Approximate msg: SERIAL_DRIVER_INTERNAL */
#define SERIAL_DRIVER_INTERNAL	((ULONG)0x00000038L)

/* MessageId  : 0x00000039 */
/* Approximate msg: SYSTEM_EXIT_OWNED_MUTEX */
#define SYSTEM_EXIT_OWNED_MUTEX	((ULONG)0x00000039L)

/* MessageId  : 0x0000003e */
/* Approximate msg: MULTIPROCESSOR_CONFIGURATION_NOT_SUPPORTED */
#define MULTIPROCESSOR_CONFIGURATION_NOT_SUPPORTED	((ULONG)0x0000003eL)

/* MessageId  : 0x0000003f */
/* Approximate msg: Remove any recently installed software including backup */
#define NO_MORE_SYSTEM_PTES	((ULONG)0x0000003fL)

/* MessageId  : 0x00000040 */
/* Approximate msg: TARGET_MDL_TOO_SMALL */
#define TARGET_MDL_TOO_SMALL	((ULONG)0x00000040L)

/* MessageId  : 0x00000041 */
/* Approximate msg: MUST_SUCCEED_POOL_EMPTY */
#define MUST_SUCCEED_POOL_EMPTY	((ULONG)0x00000041L)

/* MessageId  : 0x00000042 */
/* Approximate msg: ATDISK_DRIVER_INTERNAL */
#define ATDISK_DRIVER_INTERNAL	((ULONG)0x00000042L)

/* MessageId  : 0x00000044 */
/* Approximate msg: MULTIPLE_IRP_COMPLETE_REQUESTS */
#define MULTIPLE_IRP_COMPLETE_REQUESTS	((ULONG)0x00000044L)

/* MessageId  : 0x00000045 */
/* Approximate msg: INSUFFICIENT_SYSTEM_MAP_REGS */
#define INSUFFICIENT_SYSTEM_MAP_REGS	((ULONG)0x00000045L)

/* MessageId  : 0x00000048 */
/* Approximate msg: CANCEL_STATE_IN_COMPLETED_IRP */
#define CANCEL_STATE_IN_COMPLETED_IRP	((ULONG)0x00000048L)

/* MessageId  : 0x00000049 */
/* Approximate msg: PAGE_FAULT_WITH_INTERRUPTS_OFF */
#define PAGE_FAULT_WITH_INTERRUPTS_OFF	((ULONG)0x00000049L)

/* MessageId  : 0x0000004a */
/* Approximate msg: IRQL_GT_ZERO_AT_SYSTEM_SERVICE */
#define IRQL_GT_ZERO_AT_SYSTEM_SERVICE	((ULONG)0x0000004aL)

/* MessageId  : 0x0000004b */
/* Approximate msg: STREAMS_INTERNAL_ERROR */
#define STREAMS_INTERNAL_ERROR	((ULONG)0x0000004bL)

/* MessageId  : 0x0000004c */
/* Approximate msg: FATAL_UNHANDLED_HARD_ERROR */
#define FATAL_UNHANDLED_HARD_ERROR	((ULONG)0x0000004cL)

/* MessageId  : 0x0000004d */
/* Approximate msg: NO_PAGES_AVAILABLE */
#define NO_PAGES_AVAILABLE	((ULONG)0x0000004dL)

/* MessageId  : 0x0000004e */
/* Approximate msg: PFN_LIST_CORRUPT */
#define PFN_LIST_CORRUPT	((ULONG)0x0000004eL)

/* MessageId  : 0x0000004f */
/* Approximate msg: NDIS_INTERNAL_ERROR */
#define NDIS_INTERNAL_ERROR	((ULONG)0x0000004fL)

/* MessageId  : 0x00000050 */
/* Approximate msg: PAGE_FAULT_IN_NONPAGED_AREA */
#define PAGE_FAULT_IN_NONPAGED_AREA	((ULONG)0x00000050L)

/* MessageId  : 0x00000051 */
/* Approximate msg: REGISTRY_ERROR */
#define REGISTRY_ERROR	((ULONG)0x00000051L)

/* MessageId  : 0x00000052 */
/* Approximate msg: MAILSLOT_FILE_SYSTEM */
#define MAILSLOT_FILE_SYSTEM	((ULONG)0x00000052L)

/* MessageId  : 0x00000053 */
/* Approximate msg: NO_BOOT_DEVICE */
#define NO_BOOT_DEVICE	((ULONG)0x00000053L)

/* MessageId  : 0x00000054 */
/* Approximate msg: LM_SERVER_INTERNAL_ERROR */
#define LM_SERVER_INTERNAL_ERROR	((ULONG)0x00000054L)

/* MessageId  : 0x00000055 */
/* Approximate msg: DATA_COHERENCY_EXCEPTION */
#define DATA_COHERENCY_EXCEPTION	((ULONG)0x00000055L)

/* MessageId  : 0x00000056 */
/* Approximate msg: INSTRUCTION_COHERENCY_EXCEPTION */
#define INSTRUCTION_COHERENCY_EXCEPTION	((ULONG)0x00000056L)

/* MessageId  : 0x00000057 */
/* Approximate msg: XNS_INTERNAL_ERROR */
#define XNS_INTERNAL_ERROR	((ULONG)0x00000057L)

/* MessageId  : 0x00000058 */
/* Approximate msg: FTDISK_INTERNAL_ERROR */
#define FTDISK_INTERNAL_ERROR	((ULONG)0x00000058L)

/* MessageId  : 0x00000059 */
/* Approximate msg: PINBALL_FILE_SYSTEM */
#define PINBALL_FILE_SYSTEM	((ULONG)0x00000059L)

/* MessageId  : 0x0000005c */
/* Approximate msg: HAL_INITIALIZATION_FAILED */
#define HAL_INITIALIZATION_FAILED	((ULONG)0x0000005cL)

/* MessageId  : 0x0000005d */
/* Approximate msg: UNSUPPORTED_PROCESSOR */
#define UNSUPPORTED_PROCESSOR	((ULONG)0x0000005dL)

/* MessageId  : 0x0000005e */
/* Approximate msg: OBJECT_INITIALIZATION_FAILED */
#define OBJECT_INITIALIZATION_FAILED	((ULONG)0x0000005eL)

/* MessageId  : 0x0000005f */
/* Approximate msg: SECURITY_INITIALIZATION_FAILED */
#define SECURITY_INITIALIZATION_FAILED	((ULONG)0x0000005fL)

/* MessageId  : 0x00000060 */
/* Approximate msg: PROCESS_INITIALIZATION_FAILED */
#define PROCESS_INITIALIZATION_FAILED	((ULONG)0x00000060L)

/* MessageId  : 0x00000061 */
/* Approximate msg: HAL1_INITIALIZATION_FAILED */
#define HAL1_INITIALIZATION_FAILED	((ULONG)0x00000061L)

/* MessageId  : 0x00000062 */
/* Approximate msg: OBJECT1_INITIALIZATION_FAILED */
#define OBJECT1_INITIALIZATION_FAILED	((ULONG)0x00000062L)

/* MessageId  : 0x00000063 */
/* Approximate msg: SECURITY1_INITIALIZATION_FAILED */
#define SECURITY1_INITIALIZATION_FAILED	((ULONG)0x00000063L)

/* MessageId  : 0x00000064 */
/* Approximate msg: SYMBOLIC_INITIALIZATION_FAILED */
#define SYMBOLIC_INITIALIZATION_FAILED	((ULONG)0x00000064L)

/* MessageId  : 0x00000065 */
/* Approximate msg: MEMORY1_INITIALIZATION_FAILED */
#define MEMORY1_INITIALIZATION_FAILED	((ULONG)0x00000065L)

/* MessageId  : 0x00000066 */
/* Approximate msg: CACHE_INITIALIZATION_FAILED */
#define CACHE_INITIALIZATION_FAILED	((ULONG)0x00000066L)

/* MessageId  : 0x00000067 */
/* Approximate msg: CONFIG_INITIALIZATION_FAILED */
#define CONFIG_INITIALIZATION_FAILED	((ULONG)0x00000067L)

/* MessageId  : 0x00000068 */
/* Approximate msg: FILE_INITIALIZATION_FAILED */
#define FILE_INITIALIZATION_FAILED	((ULONG)0x00000068L)

/* MessageId  : 0x00000069 */
/* Approximate msg: IO1_INITIALIZATION_FAILED */
#define IO1_INITIALIZATION_FAILED	((ULONG)0x00000069L)

/* MessageId  : 0x0000006a */
/* Approximate msg: LPC_INITIALIZATION_FAILED */
#define LPC_INITIALIZATION_FAILED	((ULONG)0x0000006aL)

/* MessageId  : 0x0000006b */
/* Approximate msg: PROCESS1_INITIALIZATION_FAILED */
#define PROCESS1_INITIALIZATION_FAILED	((ULONG)0x0000006bL)

/* MessageId  : 0x0000006c */
/* Approximate msg: REFMON_INITIALIZATION_FAILED */
#define REFMON_INITIALIZATION_FAILED	((ULONG)0x0000006cL)

/* MessageId  : 0x0000006d */
/* Approximate msg: SESSION1_INITIALIZATION_FAILED */
#define SESSION1_INITIALIZATION_FAILED	((ULONG)0x0000006dL)

/* MessageId  : 0x0000006e */
/* Approximate msg: SESSION2_INITIALIZATION_FAILED */
#define SESSION2_INITIALIZATION_FAILED	((ULONG)0x0000006eL)

/* MessageId  : 0x0000006f */
/* Approximate msg: SESSION3_INITIALIZATION_FAILED */
#define SESSION3_INITIALIZATION_FAILED	((ULONG)0x0000006fL)

/* MessageId  : 0x00000070 */
/* Approximate msg: SESSION4_INITIALIZATION_FAILED */
#define SESSION4_INITIALIZATION_FAILED	((ULONG)0x00000070L)

/* MessageId  : 0x00000071 */
/* Approximate msg: SESSION5_INITIALIZATION_FAILED */
#define SESSION5_INITIALIZATION_FAILED	((ULONG)0x00000071L)

/* MessageId  : 0x00000072 */
/* Approximate msg: ASSIGN_DRIVE_LETTERS_FAILED */
#define ASSIGN_DRIVE_LETTERS_FAILED	((ULONG)0x00000072L)

/* MessageId  : 0x00000073 */
/* Approximate msg: CONFIG_LIST_FAILED */
#define CONFIG_LIST_FAILED	((ULONG)0x00000073L)

/* MessageId  : 0x00000074 */
/* Approximate msg: BAD_SYSTEM_CONFIG_INFO */
#define BAD_SYSTEM_CONFIG_INFO	((ULONG)0x00000074L)

/* MessageId  : 0x00000075 */
/* Approximate msg: CANNOT_WRITE_CONFIGURATION */
#define CANNOT_WRITE_CONFIGURATION	((ULONG)0x00000075L)

/* MessageId  : 0x00000076 */
/* Approximate msg: PROCESS_HAS_LOCKED_PAGES */
#define PROCESS_HAS_LOCKED_PAGES	((ULONG)0x00000076L)

/* MessageId  : 0x00000077 */
/* Approximate msg: KERNEL_STACK_INPAGE_ERROR */
#define KERNEL_STACK_INPAGE_ERROR	((ULONG)0x00000077L)

/* MessageId  : 0x00000078 */
/* Approximate msg: PHASE0_EXCEPTION */
#define PHASE0_EXCEPTION	((ULONG)0x00000078L)

/* MessageId  : 0x00000079 */
/* Approximate msg: Mismatched Kernel and HAL image */
#define MISMATCHED_HAL	((ULONG)0x00000079L)

/* MessageId  : 0x0000007a */
/* Approximate msg: KERNEL_DATA_INPAGE_ERROR */
#define KERNEL_DATA_INPAGE_ERROR	((ULONG)0x0000007aL)

/* MessageId  : 0x0000007b */
/* Approximate msg: Check for viruses on your computer. Remove any newly installed */
#define INACCESSIBLE_BOOT_DEVICE	((ULONG)0x0000007bL)

/* MessageId  : 0x0000007d */
/* Approximate msg: INSTALL_MORE_MEMORY */
#define INSTALL_MORE_MEMORY	((ULONG)0x0000007dL)

/* MessageId  : 0x0000007e */
/* Approximate msg: SYSTEM_THREAD_EXCEPTION_NOT_HANDLED */
#define SYSTEM_THREAD_EXCEPTION_NOT_HANDLED	((ULONG)0x0000007eL)

/* MessageId  : 0x0000007f */
/* Approximate msg: Run a system diagnostic utility supplied by your hardware manufacturer. */
#define UNEXPECTED_KERNEL_MODE_TRAP	((ULONG)0x0000007fL)

/* MessageId  : 0x00000080 */
/* Approximate msg: Hardware malfunction */
#define NMI_HARDWARE_FAILURE	((ULONG)0x00000080L)

/* MessageId  : 0x00000081 */
/* Approximate msg: SPIN_LOCK_INIT_FAILURE */
#define SPIN_LOCK_INIT_FAILURE	((ULONG)0x00000081L)

/* MessageId  : 0x0000008e */
/* Approximate msg: KERNEL_MODE_EXCEPTION_NOT_HANDLED */
#define KERNEL_MODE_EXCEPTION_NOT_HANDLED	((ULONG)0x0000008eL)

/* MessageId  : 0x0000008f */
/* Approximate msg: PP0_INITIALIZATION_FAILED */
#define PP0_INITIALIZATION_FAILED	((ULONG)0x0000008fL)

/* MessageId  : 0x00000090 */
/* Approximate msg: PP1_INITIALIZATION_FAILED */
#define PP1_INITIALIZATION_FAILED	((ULONG)0x00000090L)

/* MessageId  : 0x00000093 */
/* Approximate msg: INVALID_KERNEL_HANDLE */
#define INVALID_KERNEL_HANDLE	((ULONG)0x00000093L)

/* MessageId  : 0x00000094 */
/* Approximate msg: KERNEL_STACK_LOCKED_AT_EXIT */
#define KERNEL_STACK_LOCKED_AT_EXIT	((ULONG)0x00000094L)

/* MessageId  : 0x00000096 */
/* Approximate msg: INVALID_WORK_QUEUE_ITEM */
#define INVALID_WORK_QUEUE_ITEM	((ULONG)0x00000096L)

/* MessageId  : 0x000000a0 */
/* Approximate msg: INTERNAL_POWER_ERROR */
#define INTERNAL_POWER_ERROR	((ULONG)0x000000a0L)

/* MessageId  : 0x000000a1 */
/* Approximate msg: Inconsistency detected in the PCI Bus driver's internal structures. */
#define PCI_BUS_DRIVER_INTERNAL	((ULONG)0x000000a1L)

/* MessageId  : 0x000000a5 */
/* Approximate msg: The BIOS in this system is not fully ACPI compliant.  Please contact your */
#define ACPI_BIOS_ERROR	((ULONG)0x000000a5L)

/* MessageId  : 0x400000a8 */
/* Approximate msg: The system is booting in safemode - Minimal Services */
#define BOOTING_IN_SAFEMODE_MINIMAL	((ULONG)0x400000a8L)

/* MessageId  : 0x400000a9 */
/* Approximate msg: The system is booting in safemode - Minimal Services with Network */
#define BOOTING_IN_SAFEMODE_NETWORK	((ULONG)0x400000a9L)

/* MessageId  : 0x400000aa */
/* Approximate msg: The system is booting in safemode - Directory Services Repair */
#define BOOTING_IN_SAFEMODE_DSREPAIR	((ULONG)0x400000aaL)

/* MessageId  : 0x000000ac */
/* Approximate msg: Allocate from NonPaged Pool failed for a HAL critical allocation. */
#define HAL_MEMORY_ALLOCATION	((ULONG)0x000000acL)

/* MessageId  : 0x000000b4 */
/* Approximate msg: The video driver failed to initialize */
#define VIDEO_DRIVER_INIT_FAILURE	((ULONG)0x000000b4L)

/* MessageId  : 0x400000b7 */
/* Approximate msg: Boot Logging Enabled */
#define BOOTLOG_ENABLED	((ULONG)0x400000b7L)

/* MessageId  : 0x000000b8 */
/* Approximate msg: A wait operation, attach process, or yield was attempted from a DPC routine. */
#define ATTEMPTED_SWITCH_FROM_DPC	((ULONG)0x000000b8L)

/* MessageId  : 0x000000be */
/* Approximate msg: An attempt was made to write to read-only memory. */
#define ATTEMPTED_WRITE_TO_READONLY_MEMORY	((ULONG)0x000000beL)

/* MessageId  : 0x000000c1 */
/* Approximate msg: SPECIAL_POOL_DETECTED_MEMORY_CORRUPTION */
#define SPECIAL_POOL_DETECTED_MEMORY_CORRUPTION	((ULONG)0x000000c1L)

/* MessageId  : 0x000000c2 */
/* Approximate msg: BAD_POOL_CALLER */
#define BAD_POOL_CALLER	((ULONG)0x000000c2L)

/* MessageId  : 0x000000c3 */
/* Approximate msg: A system file that is owned by ReactOS was replaced by an application */
#define BUGCODE_PSS_MESSAGE_SIGNATURE	((ULONG)0x000000c3L)

/* MessageId  : 0x000000c5 */
/* Approximate msg: A device driver has pool. */
#define DRIVER_CORRUPTED_EXPOOL	((ULONG)0x000000c5L)

/* MessageId  : 0x000000c6 */
/* Approximate msg: A device driver attempting to corrupt the system has been caught. */
#define DRIVER_CAUGHT_MODIFYING_FREED_POOL	((ULONG)0x000000c6L)

/* MessageId  : 0x000000c8 */
/* Approximate msg: The processor's IRQL is not valid for the currently executing context. */
#define IRQL_UNEXPECTED_VALUE	((ULONG)0x000000c8L)

/* MessageId  : 0x000000ca */
/* Approximate msg: Plug and Play detected an error most likely caused by a faulty driver. */
#define PNP_DETECTED_FATAL_ERROR	((ULONG)0x000000caL)

/* MessageId  : 0x000000cb */
/* Approximate msg: DRIVER_LEFT_LOCKED_PAGES_IN_PROCESS */
#define DRIVER_LEFT_LOCKED_PAGES_IN_PROCESS	((ULONG)0x000000cbL)

/* MessageId  : 0x000000ce */
/* Approximate msg: DRIVER_UNLOADED_WITHOUT_CANCELLING_PENDING_OPERATIONS */
#define DRIVER_UNLOADED_WITHOUT_CANCELLING_PENDING_OPERATIONS	((ULONG)0x000000ceL)

/* MessageId  : 0x000000d0 */
/* Approximate msg: DRIVER_CORRUPTED_MMPOOL */
#define DRIVER_CORRUPTED_MMPOOL	((ULONG)0x000000d0L)

/* MessageId  : 0x000000d1 */
/* Approximate msg: DRIVER_IRQL_NOT_LESS_OR_EQUAL */
#define DRIVER_IRQL_NOT_LESS_OR_EQUAL	((ULONG)0x000000d1L)

/* MessageId  : 0x000000d3 */
/* Approximate msg: The driver mistakenly marked a part of it's image pageable instead of non-pageable. */
#define DRIVER_PORTION_MUST_BE_NONPAGED	((ULONG)0x000000d3L)

/* MessageId  : 0x000000d8 */
/* Approximate msg: The driver has used an excessive number of system PTEs. */
#define DRIVER_USED_EXCESSIVE_PTES	((ULONG)0x000000d8L)

/* MessageId  : 0x000000d4 */
/* Approximate msg: The driver unloaded without cancelling pending operations. */
#define SYSTEM_SCAN_AT_RAISED_IRQL_CAUGHT_IMPROPER_DRIVER_UNLOAD	((ULONG)0x000000d4L)

/* MessageId  : 0x000000e0 */
/* Approximate msg:  */
#define ACPI_BIOS_FATAL_ERROR	((ULONG)0x000000e0L)

/* MessageId  : 0x000000e1 */
/* Approximate msg: WORKER_THREAD_RETURNED_AT_BAD_IRQL */
#define WORKER_THREAD_RETURNED_AT_BAD_IRQL	((ULONG)0x000000e1L)

/* MessageId  : 0x000000e2 */
/* Approximate msg: MANUALLY_INITIATED_CRASH */
#define MANUALLY_INITIATED_CRASH	((ULONG)0x000000e2L)

/* MessageId  : 0x000000e3 */
/* Approximate msg: RESOURCE_NOT_OWNED */
#define RESOURCE_NOT_OWNED	((ULONG)0x000000e3L)

/* MessageId  : 0x000000e4 */
/* Approximate msg: If Parameter1 == 0, an executive worker item was found in memory which */
#define WORKER_INVALID	((ULONG)0x000000e4L)

/* MessageId  : 0x000000e5 */
/* Approximate msg: POWER_FAILURE_SIMULATE */
#define POWER_FAILURE_SIMULATE	((ULONG)0x000000e5L)

/* MessageId  : 0x000000e9 */
/* Approximate msg: An executive worker thread is being terminated without having gone through the worker thread rundown code. */
#define ACTIVE_EX_WORKER_THREAD_TERMINATION	((ULONG)0x000000e9L)

/* MessageId  : 0x000000ea */
/* Approximate msg:  */
#define THREAD_STUCK_IN_DEVICE_DRIVER	((ULONG)0x000000eaL)

/* MessageId  : 0x000000ef */
/* Approximate msg: The kernel attempted to ready a thread that was in an incorrect state such as terminated. */
#define CRITICAL_PROCESS_DIED	((ULONG)0x000000efL)

/* MessageId  : 0x000000f4 */
/* Approximate msg: A process or thread crucial to system operation has unexpectedly exited or been terminated. */
#define CRITICAL_OBJECT_TERMINATION	((ULONG)0x000000f4L)

/* MessageId  : 0x000000f6 */
/* Approximate msg: The PCI driver has detected an error in a PCI device or BIOS being verified. */
#define PCI_VERIFIER_DETECTED_VIOLATION	((ULONG)0x000000f6L)

/* MessageId  : 0x000000f8 */
/* Approximate msg: An initialization failure occurred while attempting to boot from the RAM disk. */
#define RAMDISK_BOOT_INITIALIZATION_FAILED	((ULONG)0x000000f8L)

/* MessageId  : 0x000000fa */
/* Approximate msg: A worker thread is impersonating another process. The work item forgot to */
#define IMPERSONATING_WORKER_THREAD	((ULONG)0x000000faL)

/* MessageId  : 0x000000fc */
/* Approximate msg: An attempt was made to execute to non-executable memory. */
#define ATTEMPTED_EXECUTE_OF_NOEXECUTE_MEMORY	((ULONG)0x000000fcL)

/*  EOF */

#endif
