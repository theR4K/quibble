/* Copyright (c) Mark Harmstone 2020
 *
 * This file is part of Quibble.
 *
 * Quibble is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public Licence as published by
 * the Free Software Foundation, either version 3 of the Licence, or
 * (at your option) any later version.
 *
 * Quibble is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public Licence for more details.
 *
 * You should have received a copy of the GNU Lesser General Public Licence
 * along with Quibble.  If not, see <http://www.gnu.org/licenses/>. */

#pragma once

#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#ifdef _X86_

#define KGDT_NULL           0x00
#define KGDT_R0_CODE        0x08
#define KGDT_R0_DATA        0x10
#define KGDT_R3_CODE        0x18
#define KGDT_R3_DATA        0x20
#define KGDT_TSS            0x28
#define KGDT_R0_PCR         0x30
#define KGDT_R3_TEB         0x38
#define KGDT_VDM_TILE       0x40
#define KGDT_LDT            0x48
#define KGDT_DF_TSS         0x50
#define KGDT_NMI_TSS        0x58
#define KGDT_MC_TSS         0xa0

#elif defined(__x86_64__)

#define KGDT_NULL         0x00
#define KGDT_R0_CODE      0x10
#define KGDT_R0_DATA      0x18
#define KGDT_R3_CMCODE    0x20
#define KGDT_R3_DATA      0x28
#define KGDT_R3_CODE      0x30
#define KGDT_TSS          0x40
#define KGDT_R3_CMTEB     0x50
#define KGDT_R0_LDT       0x60

#endif

#define NUM_GDT     128
#define NUM_IDT     0x100

#define MM_KSEG0_BASE           0x80000000

#ifdef _X86_
#define SELFMAP                 0xc0000000
#define SELFMAP2                0xc0600000
#define APIC_BASE               0xfffe0000
#define KI_USER_SHARED_DATA     0xffdf0000
#define KIP0PCRADDRESS          0xffdff000
#define PCR_PAGES               7 // 0x6020 bytes as of 2004
#elif defined(__x86_64__)
#define SELFMAP                 0xfffff68000000000
#define SELFMAP_PD              0xfffff6fb40000000
#define SELFMAP_PDP             0xfffff6fb7da00000
#define SELFMAP_PML4            0xfffff6fb7dbed000
#define APIC_BASE               0xfffffffffffe0000
#define KI_USER_SHARED_DATA     0xfffff78000000000
#define PCR_PAGES               0xc // 0xb080 bytes as of 2004
#endif

#define _WIN32_WINNT_NT4                    0x0400
#define _WIN32_WINNT_WIN2K                  0x0500
#define _WIN32_WINNT_WINXP                  0x0501
#define _WIN32_WINNT_WS03                   0x0502
#define _WIN32_WINNT_VISTA                  0x0600
#define _WIN32_WINNT_WIN7                   0x0601
#define _WIN32_WINNT_WIN8                   0x0602
#define _WIN32_WINNT_WINBLUE                0x0603
#define _WIN32_WINNT_WIN10                  0x0A00

#define WIN10_BUILD_1507            10240
#define WIN10_BUILD_1511            10586
#define WIN10_BUILD_1607            14393
#define WIN10_BUILD_1703            15063
#define WIN10_BUILD_1709            16299
#define WIN10_BUILD_1803            17134
#define WIN10_BUILD_1809            17763
#define WIN10_BUILD_1903            18362
#define WIN10_BUILD_1909            18363
#define WIN10_BUILD_2004            19041

#define NTDDI_WIN7                          0x06010000
#define NTDDI_WIN8                          0x06020000
#define NTDDI_WINBLUE                       0x06030000
#define NTDDI_WIN10                         0x0a000000
#define NTDDI_WIN10_TH2                     0x0a000001 // 1511
#define NTDDI_WIN10_RS1                     0x0a000002 // 1607
#define NTDDI_WIN10_RS2                     0x0a000003 // 1703
#define NTDDI_WIN10_RS3                     0x0a000004 // 1709
#define NTDDI_WIN10_RS4                     0x0a000005 // 1803
#define NTDDI_WIN10_RS5                     0x0a000006 // 1809
#define NTDDI_WIN10_19H1                    0x0a000007 // 1903
#define NTDDI_WIN10_20H1                    0x0a000008 // 2004

#define STATUS_NOT_IMPLEMENTED 0xC0000002

#define NX_OPTIN        0
#define NX_OPTOUT       1
#define NX_ALWAYSOFF    2
#define NX_ALWAYSON     3

#define PAE_DEFAULT         0
#define PAE_FORCEENABLE     1
#define PAE_FORCEDISABLE    2

typedef enum {
    SystemClass,
    ProcessorClass,
    CacheClass,
    AdapterClass,
    ControllerClass,
    PeripheralClass,
    MemoryClass,
    MaximumClass
} CONFIGURATION_CLASS;

typedef enum {
    ArcSystem,
    CentralProcessor,
    FloatingPointProcessor,
    PrimaryIcache,
    PrimaryDcache,
    SecondaryIcache,
    SecondaryDcache,
    SecondaryCache,
    EisaAdapter,
    TcAdapter,
    ScsiAdapter,
    DtiAdapter,
    MultiFunctionAdapter,
    DiskController,
    TapeController,
    CdromController,
    WormController,
    SerialController,
    NetworkController,
    DisplayController,
    ParallelController,
    PointerController,
    KeyboardController,
    AudioController,
    OtherController,
    DiskPeripheral,
    FloppyDiskPeripheral,
    TapePeripheral,
    ModemPeripheral,
    MonitorPeripheral,
    PrinterPeripheral,
    PointerPeripheral,
    KeyboardPeripheral,
    TerminalPeripheral,
    OtherPeripheral,
    LinePeripheral,
    NetworkPeripheral,
    SystemMemory,
    DockingInformation,
    RealModeIrqRoutingTable,
    RealModePCIEnumeration,
    MaximumType
} CONFIGURATION_TYPE;

typedef enum {
    Failed = 0x01,
    ReadOnly = 0x02,
    Removable = 0x04,
    ConsoleIn = 0x08,
    ConsoleOut = 0x10,
    IdentifierFlag_Input = 0x20, // renamed
    IdentifierFlag_Output = 0x40 // renamed
} IDENTIFIER_FLAG;

typedef struct _CONFIGURATION_COMPONENT {
    CONFIGURATION_CLASS Class;
    CONFIGURATION_TYPE Type;
    IDENTIFIER_FLAG Flags;
    uint16_t Version;
    uint16_t Revision;
    uint32_t Key;
    uint32_t AffinityMask;
    uint32_t ConfigurationDataLength;
    uint32_t IdentifierLength;
    char* Identifier;
} CONFIGURATION_COMPONENT;

typedef struct _CONFIGURATION_COMPONENT_DATA {
    struct _CONFIGURATION_COMPONENT_DATA* Parent;
    struct _CONFIGURATION_COMPONENT_DATA* Child;
    struct _CONFIGURATION_COMPONENT_DATA* Sibling;
    CONFIGURATION_COMPONENT ComponentEntry;
    void* ConfigurationData;
} CONFIGURATION_COMPONENT_DATA;

typedef struct {
    void* AnsiCodePageData;
    void* OemCodePageData;
    void* UnicodeCodePageData;
} NLS_DATA_BLOCK;

typedef struct {
    LIST_ENTRY ListEntry;
    uint32_t Signature;
    char* ArcName;
    uint32_t CheckSum;
    BOOLEAN ValidPartitionTable;
    BOOLEAN xInt13;
    BOOLEAN IsGpt;
    BOOLEAN Reserved;
    char GptSignature[16];
} ARC_DISK_SIGNATURE;

#pragma pack(push,1)

typedef struct {
    LIST_ENTRY ListEntry;
    uint32_t Signature;
#ifdef __x86_64__
    uint32_t padding;
#endif
    char* ArcName;
    uint32_t CheckSum;
    uint8_t ValidPartitionTable;
    uint8_t xInt13;
    uint8_t IsGpt;
    uint8_t Reserved;
    char GptSignature[16];
    void* unknown;
} ARC_DISK_SIGNATURE_WIN7;

#pragma pack(pop)

typedef struct {
    LIST_ENTRY DiskSignatureListHead;
} ARC_DISK_INFORMATION;

#pragma pack(push,1)

typedef struct {
    uint16_t Status;
    uint16_t Reserved;
    uint16_t DockingState;
    uint16_t Capabilities;
    uint32_t DockID;
    uint32_t SerialNumber;
} PROFILE_PARAMETER_BLOCK;

#pragma pack(pop)

typedef uint8_t GUID[16];

typedef struct {
    uint8_t UsedBiosSettings;
    uint8_t DataBits;
    uint8_t StopBits;
    uint8_t Parity;
    uint32_t BaudRate;
    uint32_t PortNumber;
    uint8_t* PortAddress;
    uint16_t PciDeviceId;
    uint16_t PciVendorId;
    uint8_t PciBusNumber;
    uint8_t PciSlotNumber;
    uint8_t PciFunctionNumber;
    uint32_t PciFlags;
    GUID SystemGUID;
    uint8_t IsMMIODevice;
    uint8_t TerminalType;
} HEADLESS_LOADER_BLOCK;

typedef struct {
    char Signature[4];
    uint8_t Checksum;
    uint8_t Length;
    uint8_t MajorVersion;
    uint8_t MinorVersion;
    uint16_t MaximumStructureSize;
    uint8_t EntryPointRevision;
    uint8_t Reserved[5];
    char Signature2[5];
    uint8_t IntermediateChecksum;
    uint16_t StructureTableLength;
    uint32_t StructureTableAddress;
    uint16_t NumberStructures;
    uint8_t Revision;
} SMBIOS_TABLE_HEADER;

typedef struct {
    char* DHCPServerACK;
    uint32_t DHCPServerACKLength;
    char* BootServerReplyPacket;
    uint32_t BootServerReplyPacketLength;
} NETWORK_LOADER_BLOCK;

#pragma pack(push,1)

typedef struct {
    void* EmInfFileImage;
    uintptr_t EmInfFileSize;
    void* TriageDumpBlock;
} LOADER_EXTENSION_BLOCK1A;

typedef struct {
    HEADLESS_LOADER_BLOCK* HeadlessLoaderBlock;
    SMBIOS_TABLE_HEADER* SMBiosEPSHeader;
    void* DrvDBImage;
    uintptr_t DrvDBSize;
} LOADER_EXTENSION_BLOCK1B;

typedef struct {
    NETWORK_LOADER_BLOCK* NetworkLoaderBlock;
#ifndef __x86_64__
    uint8_t* HalpIRQLToTPR;
    uint8_t* HalpVectorToIRQL;
#endif
    LIST_ENTRY FirmwareDescriptorListHead;
    void* AcpiTable;
    uint32_t AcpiTableSize;
} LOADER_EXTENSION_BLOCK1C;

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
    uint32_t MajorVersion;
    uint32_t MinorVersion;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    uintptr_t LoaderPagesSpanned;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
#ifdef __x86_64__
    uint32_t padding2;
#endif
} LOADER_PARAMETER_EXTENSION_WS03;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WS03) == 0x58, "LOADER_PARAMETER_EXTENSION_WS03 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WS03 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WS03 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, MajorVersion) == 0x14, "LOADER_PARAMETER_EXTENSION_WS03 MajorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, MinorVersion) == 0x18, "LOADER_PARAMETER_EXTENSION_WS03 MinorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1a.EmInfFileImage) == 0x1c, "LOADER_PARAMETER_EXTENSION_WS03 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WS03 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1a.TriageDumpBlock) == 0x24, "LOADER_PARAMETER_EXTENSION_WS03 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, LoaderPagesSpanned) == 0x28, "LOADER_PARAMETER_EXTENSION_WS03 LoaderPagesSpanned");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1b.HeadlessLoaderBlock) == 0x2c, "LOADER_PARAMETER_EXTENSION_WS03 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1b.SMBiosEPSHeader) == 0x30, "LOADER_PARAMETER_EXTENSION_WS03 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1b.DrvDBImage) == 0x34, "LOADER_PARAMETER_EXTENSION_WS03 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1b.DrvDBSize) == 0x38, "LOADER_PARAMETER_EXTENSION_WS03 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1c.NetworkLoaderBlock) == 0x3c, "LOADER_PARAMETER_EXTENSION_WS03 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1c.FirmwareDescriptorListHead) == 0x48, "LOADER_PARAMETER_EXTENSION_WS03 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1c.AcpiTable) == 0x50, "LOADER_PARAMETER_EXTENSION_WS03 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1c.AcpiTableSize) == 0x54, "LOADER_PARAMETER_EXTENSION_WS03 AcpiTableSize");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WS03) == 0x88, "LOADER_PARAMETER_EXTENSION_WS03 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WS03 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WS03 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, MajorVersion) == 0x14, "LOADER_PARAMETER_EXTENSION_WS03 MajorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, MinorVersion) == 0x18, "LOADER_PARAMETER_EXTENSION_WS03 MinorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1a.EmInfFileImage) == 0x20, "LOADER_PARAMETER_EXTENSION_WS03 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1a.EmInfFileSize) == 0x28, "LOADER_PARAMETER_EXTENSION_WS03 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1a.TriageDumpBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WS03 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, LoaderPagesSpanned) == 0x38, "LOADER_PARAMETER_EXTENSION_WS03 LoaderPagesSpanned");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1b.HeadlessLoaderBlock) == 0x40, "LOADER_PARAMETER_EXTENSION_WS03 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1b.SMBiosEPSHeader) == 0x48, "LOADER_PARAMETER_EXTENSION_WS03 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1b.DrvDBImage) == 0x50, "LOADER_PARAMETER_EXTENSION_WS03 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1b.DrvDBSize) == 0x58, "LOADER_PARAMETER_EXTENSION_WS03 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1c.NetworkLoaderBlock) == 0x60, "LOADER_PARAMETER_EXTENSION_WS03 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1c.FirmwareDescriptorListHead) == 0x68, "LOADER_PARAMETER_EXTENSION_WS03 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1c.AcpiTable) == 0x78, "LOADER_PARAMETER_EXTENSION_WS03 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WS03, Block1c.AcpiTableSize) == 0x80, "LOADER_PARAMETER_EXTENSION_WS03 AcpiTableSize");
#endif

typedef struct {
    uint64_t StartTime;
    uint64_t EndTime;
} LOADER_PERFORMANCE_DATA;

#pragma pack(push,1)

typedef struct {
    uint32_t BootViaWinload:1;
    uint32_t BootViaEFI:1;
    uint32_t Reserved:30;
} LOADER_EXTENSION_BLOCK2A;

typedef struct {
    LIST_ENTRY BootApplicationPersistentData;
    void* WmdTestResult;
    GUID BootIdentifier;
} LOADER_EXTENSION_BLOCK2B;

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
    uint32_t MajorVersion;
    uint32_t MinorVersion;
#if defined(__x86_64__)
    uint32_t padding;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    uintptr_t LoaderPagesSpanned;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA* LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
} LOADER_PARAMETER_EXTENSION_VISTA;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_VISTA) == 0x7c, "LOADER_PARAMETER_EXTENSION_VISTA has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_VISTA Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_VISTA Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, MajorVersion) == 0x14, "LOADER_PARAMETER_EXTENSION_VISTA MajorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, MinorVersion) == 0x18, "LOADER_PARAMETER_EXTENSION_VISTA MinorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1a.EmInfFileImage) == 0x1c, "LOADER_PARAMETER_EXTENSION_VISTA EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_VISTA EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1a.TriageDumpBlock) == 0x24, "LOADER_PARAMETER_EXTENSION_VISTA TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, LoaderPagesSpanned) == 0x28, "LOADER_PARAMETER_EXTENSION_VISTA LoaderPagesSpanned");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1b.HeadlessLoaderBlock) == 0x2c, "LOADER_PARAMETER_EXTENSION_VISTA HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1b.SMBiosEPSHeader) == 0x30, "LOADER_PARAMETER_EXTENSION_VISTA SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1b.DrvDBImage) == 0x34, "LOADER_PARAMETER_EXTENSION_VISTA DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1b.DrvDBSize) == 0x38, "LOADER_PARAMETER_EXTENSION_VISTA DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1c.NetworkLoaderBlock) == 0x3c, "LOADER_PARAMETER_EXTENSION_VISTA NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1c.FirmwareDescriptorListHead) == 0x48, "LOADER_PARAMETER_EXTENSION_VISTA FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1c.AcpiTable) == 0x50, "LOADER_PARAMETER_EXTENSION_VISTA AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1c.AcpiTableSize) == 0x54, "LOADER_PARAMETER_EXTENSION_VISTA AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, LoaderPerformanceData) == 0x5c, "LOADER_PARAMETER_EXTENSION_VISTA LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block2b.BootApplicationPersistentData) == 0x60, "LOADER_PARAMETER_EXTENSION_VISTA BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block2b.WmdTestResult) == 0x68, "LOADER_PARAMETER_EXTENSION_VISTA WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block2b.BootIdentifier) == 0x6c, "LOADER_PARAMETER_EXTENSION_VISTA BootIdentifier");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_VISTA) == 0xb8, "LOADER_PARAMETER_EXTENSION_VISTA has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_VISTA Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_VISTA Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, MajorVersion) == 0x14, "LOADER_PARAMETER_EXTENSION_VISTA MajorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, MinorVersion) == 0x18, "LOADER_PARAMETER_EXTENSION_VISTA MinorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1a.EmInfFileImage) == 0x20, "LOADER_PARAMETER_EXTENSION_VISTA EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1a.EmInfFileSize) == 0x28, "LOADER_PARAMETER_EXTENSION_VISTA EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1a.TriageDumpBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_VISTA TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, LoaderPagesSpanned) == 0x38, "LOADER_PARAMETER_EXTENSION_VISTA LoaderPagesSpanned");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1b.HeadlessLoaderBlock) == 0x40, "LOADER_PARAMETER_EXTENSION_VISTA HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1b.SMBiosEPSHeader) == 0x48, "LOADER_PARAMETER_EXTENSION_VISTA SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1b.DrvDBImage) == 0x50, "LOADER_PARAMETER_EXTENSION_VISTA DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1b.DrvDBSize) == 0x58, "LOADER_PARAMETER_EXTENSION_VISTA DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1c.NetworkLoaderBlock) == 0x60, "LOADER_PARAMETER_EXTENSION_VISTA NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1c.FirmwareDescriptorListHead) == 0x68, "LOADER_PARAMETER_EXTENSION_VISTA FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1c.AcpiTable) == 0x78, "LOADER_PARAMETER_EXTENSION_VISTA AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block1c.AcpiTableSize) == 0x80, "LOADER_PARAMETER_EXTENSION_VISTA AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, LoaderPerformanceData) == 0x88, "LOADER_PARAMETER_EXTENSION_VISTA LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block2b.BootApplicationPersistentData) == 0x90, "LOADER_PARAMETER_EXTENSION_VISTA BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block2b.WmdTestResult) == 0xa0, "LOADER_PARAMETER_EXTENSION_VISTA WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA, Block2b.BootIdentifier) == 0xa8, "LOADER_PARAMETER_EXTENSION_VISTA BootIdentifier");
#endif

#pragma pack(push,1)

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
    uint32_t MajorVersion;
    uint32_t MinorVersion;
#if defined(__x86_64__)
    uint32_t padding;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    uintptr_t LoaderPagesSpanned;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA* LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
} LOADER_PARAMETER_EXTENSION_VISTA_SP2;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_VISTA_SP2) == 0x84, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, MajorVersion) == 0x14, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 MajorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, MinorVersion) == 0x18, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 MinorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1a.EmInfFileImage) == 0x1c, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1a.TriageDumpBlock) == 0x24, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, LoaderPagesSpanned) == 0x28, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 LoaderPagesSpanned");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1b.HeadlessLoaderBlock) == 0x2c, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1b.SMBiosEPSHeader) == 0x30, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1b.DrvDBImage) == 0x34, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1b.DrvDBSize) == 0x38, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1c.NetworkLoaderBlock) == 0x3c, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1c.FirmwareDescriptorListHead) == 0x48, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1c.AcpiTable) == 0x50, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1c.AcpiTableSize) == 0x54, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, LoaderPerformanceData) == 0x5c, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block2b.BootApplicationPersistentData) == 0x60, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block2b.WmdTestResult) == 0x68, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block2b.BootIdentifier) == 0x6c, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, ResumePages) == 0x7c, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, DumpHeader) == 0x80, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 DumpHeader");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_VISTA_SP2) == 0xc8, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, MajorVersion) == 0x14, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 MajorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, MinorVersion) == 0x18, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 MinorVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1a.EmInfFileImage) == 0x20, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1a.EmInfFileSize) == 0x28, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1a.TriageDumpBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, LoaderPagesSpanned) == 0x38, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 LoaderPagesSpanned");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1b.HeadlessLoaderBlock) == 0x40, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1b.SMBiosEPSHeader) == 0x48, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1b.DrvDBImage) == 0x50, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1b.DrvDBSize) == 0x58, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1c.NetworkLoaderBlock) == 0x60, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1c.FirmwareDescriptorListHead) == 0x68, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1c.AcpiTable) == 0x78, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block1c.AcpiTableSize) == 0x80, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, LoaderPerformanceData) == 0x88, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block2b.BootApplicationPersistentData) == 0x90, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block2b.WmdTestResult) == 0xa0, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, Block2b.BootIdentifier) == 0xa8, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, ResumePages) == 0xb8, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_VISTA_SP2, DumpHeader) == 0xc0, "LOADER_PARAMETER_EXTENSION_VISTA_SP2 DumpHeader");
#endif

typedef enum {
    TpmBootEntropyStructureUninitialized,
    TpmBootEntropyDisabledByPolicy,
    TpmBootEntropyNoTpmFound,
    TpmBootEntropyTpmError,
    TpmBootEntropySuccess
} TPM_BOOT_ENTROPY_RESULT_CODE;

#pragma pack(push,1)

typedef struct {
    uint64_t Policy;
    TPM_BOOT_ENTROPY_RESULT_CODE ResultCode;
    int32_t ResultStatus;
    uint64_t Time;
    uint32_t EntropyLength;
    uint8_t EntropyData[40];
} TPM_BOOT_ENTROPY_LDR_RESULT;

typedef struct {
    void* BgContext;
    void* NumaLocalityInfo;
    void* NumaGroupAssignment;
    LIST_ENTRY AttachedHives;
    uintptr_t MemoryCachingRequirementsCount;
    void* MemoryCachingRequirements;
} LOADER_EXTENSION_BLOCK3;

#pragma pack(pop)

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    uintptr_t LoaderPagesSpanned;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA* LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
    LOADER_EXTENSION_BLOCK3 Block3;
    TPM_BOOT_ENTROPY_LDR_RESULT TpmBootEntropyResult;
    uint32_t padding;
    uint64_t ProcessorCounterFrequency;
} LOADER_PARAMETER_EXTENSION_WIN7;

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN7) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN7 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN7 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN7 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1a.EmInfFileImage) == 0x14, "LOADER_PARAMETER_EXTENSION_WIN7 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1a.EmInfFileSize) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN7 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1a.TriageDumpBlock) == 0x1c, "LOADER_PARAMETER_EXTENSION_WIN7 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, LoaderPagesSpanned) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN7 LoaderPagesSpanned");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1b.HeadlessLoaderBlock) == 0x24, "LOADER_PARAMETER_EXTENSION_WIN7 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1b.SMBiosEPSHeader) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN7 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1b.DrvDBImage) == 0x2c, "LOADER_PARAMETER_EXTENSION_WIN7 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1b.DrvDBSize) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN7 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1c.NetworkLoaderBlock) == 0x34, "LOADER_PARAMETER_EXTENSION_WIN7 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1c.FirmwareDescriptorListHead) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN7 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1c.AcpiTable) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN7 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1c.AcpiTableSize) == 0x4c, "LOADER_PARAMETER_EXTENSION_WIN7 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, LoaderPerformanceData) == 0x54, "LOADER_PARAMETER_EXTENSION_WIN7 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block2b.BootApplicationPersistentData) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN7 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block2b.WmdTestResult) == 0x60, "LOADER_PARAMETER_EXTENSION_WIN7 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block2b.BootIdentifier) == 0x64, "LOADER_PARAMETER_EXTENSION_WIN7 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, ResumePages) == 0x74, "LOADER_PARAMETER_EXTENSION_WIN7 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, DumpHeader) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN7 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.BgContext) == 0x7c, "LOADER_PARAMETER_EXTENSION_WIN7 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.NumaLocalityInfo) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN7 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.NumaGroupAssignment) == 0x84, "LOADER_PARAMETER_EXTENSION_WIN7 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.AttachedHives) == 0x88, "LOADER_PARAMETER_EXTENSION_WIN7 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.MemoryCachingRequirementsCount) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN7 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.MemoryCachingRequirements) == 0x94, "LOADER_PARAMETER_EXTENSION_WIN7 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, TpmBootEntropyResult) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN7 TpmBootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, ProcessorCounterFrequency) == 0xe0, "LOADER_PARAMETER_EXTENSION_WIN7 ProcessorCounterFrequency");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN7) == 0x148, "LOADER_PARAMETER_EXTENSION_WIN7 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN7 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN7 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1a.EmInfFileImage) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN7 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN7 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1a.TriageDumpBlock) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN7 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, LoaderPagesSpanned) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN7 LoaderPagesSpanned");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1b.HeadlessLoaderBlock) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN7 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1b.SMBiosEPSHeader) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN7 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1b.DrvDBImage) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN7 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1b.DrvDBSize) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN7 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1c.NetworkLoaderBlock) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN7 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1c.FirmwareDescriptorListHead) == 0x60, "LOADER_PARAMETER_EXTENSION_WIN7 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1c.AcpiTable) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN7 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block1c.AcpiTableSize) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN7 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, LoaderPerformanceData) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN7 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block2b.BootApplicationPersistentData) == 0x88, "LOADER_PARAMETER_EXTENSION_WIN7 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block2b.WmdTestResult) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN7 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block2b.BootIdentifier) == 0xa0, "LOADER_PARAMETER_EXTENSION_WIN7 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, ResumePages) == 0xb0, "LOADER_PARAMETER_EXTENSION_WIN7 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, DumpHeader) == 0xb8, "LOADER_PARAMETER_EXTENSION_WIN7 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.BgContext) == 0xc0, "LOADER_PARAMETER_EXTENSION_WIN7 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.NumaLocalityInfo) == 0xc8, "LOADER_PARAMETER_EXTENSION_WIN7 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.NumaGroupAssignment) == 0xd0, "LOADER_PARAMETER_EXTENSION_WIN7 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.AttachedHives) == 0xd8, "LOADER_PARAMETER_EXTENSION_WIN7 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.MemoryCachingRequirementsCount) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN7 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, Block3.MemoryCachingRequirements) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN7 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, TpmBootEntropyResult) == 0xf8, "LOADER_PARAMETER_EXTENSION_WIN7 TpmBootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN7, ProcessorCounterFrequency) == 0x140, "LOADER_PARAMETER_EXTENSION_WIN7 ProcessorCounterFrequency");
#endif

typedef enum {
    BootEntropySourceNone,
    BootEntropySourceSeedfile,
    BootEntropySourceExternal,
    BootEntropySourceTpm,
    BootEntropySourceRdrand,
    BootEntropySourceTime,
    BootEntropySourceAcpiOem0,
    BootEntropySourceUefi,
    BootEntropySourceCng,
    BootEntropySourceTcbTpm,
    BootEntropySourceTcbRdrand,
    BootMaxEntropySources = BootEntropySourceTcbRdrand
} BOOT_ENTROPY_SOURCE_ID;

typedef enum {
    BootEntropySourceStructureUninitialized,
    BootEntropySourceDisabledByPolicy,
    BootEntropySourceNotPresent,
    BootEntropySourceError,
    BootEntropySourceSuccess
} BOOT_ENTROPY_SOURCE_RESULT_CODE;

typedef struct {
    BOOT_ENTROPY_SOURCE_ID SourceId;
    uint64_t Policy;
    BOOT_ENTROPY_SOURCE_RESULT_CODE ResultCode;
    int32_t ResultStatus;
    uint64_t Time;
    uint32_t EntropyLength;
    uint8_t EntropyData[64];
} BOOT_ENTROPY_SOURCE_LDR_RESULT;

typedef struct {
    uint32_t maxEntropySources;
    BOOT_ENTROPY_SOURCE_LDR_RESULT EntropySourceResult[7];
    uint8_t SeedBytesForCng[48];
    uint8_t RngBytesForNtoskrnl[1024];
} BOOT_ENTROPY_LDR_RESULT_WIN8;

typedef struct {
    uint32_t HypervisorCrashdumpAreaPageCount;
    uint64_t HypervisorCrashdumpAreaSpa;
    uint64_t HypervisorLaunchStatus;
    uint64_t HypervisorLaunchStatusArg1;
    uint64_t HypervisorLaunchStatusArg2;
    uint64_t HypervisorLaunchStatusArg3;
    uint64_t HypervisorLaunchStatusArg4;
} LOADER_PARAMETER_HYPERVISOR_EXTENSION;

typedef struct {
    uint16_t Length;
    uint16_t MaximumLength;
    WCHAR* Buffer;
} UNICODE_STRING;

typedef struct {
    GUID HardwareConfigurationId;
    LIST_ENTRY HalExtensionModuleList;
    int64_t SystemTime;
    uint64_t TimeStampAtSystemTimeRead;
    uint64_t BootFlags;

    union {
        uint64_t InternalBootFlags;
        struct {
            uint64_t DbgUtcBootTime : 1;
            uint64_t DbgRtcBootTime : 1;
            uint64_t DbgNoLegacyServices : 1;
        };
    };

    void* WfsFPData;
    uint32_t WfsFPDataSize;
} LOADER_EXTENSION_BLOCK4;

typedef struct {
    UNICODE_STRING AcpiBiosVersion;
    UNICODE_STRING SmbiosVersion;
    UNICODE_STRING EfiVersion;
} LOADER_EXTENSION_BLOCK5B;

#pragma pack(push,1)

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA* LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
    LOADER_EXTENSION_BLOCK3 Block3;
#ifndef __x86_64__
    uint32_t padding2;
#endif
    BOOT_ENTROPY_LDR_RESULT_WIN8 BootEntropyResult;
    uint64_t ProcessorCounterFrequency;
    LOADER_PARAMETER_HYPERVISOR_EXTENSION HypervisorExtension;
    LOADER_EXTENSION_BLOCK4 Block4;
#ifdef __x86_64__
    uint8_t unknown[0x60];
#else
    uint8_t unknown[0x30];
#endif
    LOADER_EXTENSION_BLOCK5B Block5b;
} LOADER_PARAMETER_EXTENSION_WIN8;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN8) == 0x870, "LOADER_PARAMETER_EXTENSION_WIN8 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN8 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN8 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1a.EmInfFileImage) == 0x14, "LOADER_PARAMETER_EXTENSION_WIN8 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1a.EmInfFileSize) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN8 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1a.TriageDumpBlock) == 0x1c, "LOADER_PARAMETER_EXTENSION_WIN8 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1b.HeadlessLoaderBlock) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN8 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1b.SMBiosEPSHeader) == 0x24, "LOADER_PARAMETER_EXTENSION_WIN8 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1b.DrvDBImage) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN8 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1b.DrvDBSize) == 0x2c, "LOADER_PARAMETER_EXTENSION_WIN8 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1c.NetworkLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN8 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1c.FirmwareDescriptorListHead) == 0x3c, "LOADER_PARAMETER_EXTENSION_WIN8 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1c.AcpiTable) == 0x44, "LOADER_PARAMETER_EXTENSION_WIN8 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1c.AcpiTableSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN8 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, LoaderPerformanceData) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN8 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block2b.BootApplicationPersistentData) == 0x54, "LOADER_PARAMETER_EXTENSION_WIN8 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block2b.WmdTestResult) == 0x5c, "LOADER_PARAMETER_EXTENSION_WIN8 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block2b.BootIdentifier) == 0x60, "LOADER_PARAMETER_EXTENSION_WIN8 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, ResumePages) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN8 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, DumpHeader) == 0x74, "LOADER_PARAMETER_EXTENSION_WIN8 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.BgContext) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN8 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.NumaLocalityInfo) == 0x7c, "LOADER_PARAMETER_EXTENSION_WIN8 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.NumaGroupAssignment) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN8 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.AttachedHives) == 0x84, "LOADER_PARAMETER_EXTENSION_WIN8 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.MemoryCachingRequirementsCount) == 0x8c, "LOADER_PARAMETER_EXTENSION_WIN8 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.MemoryCachingRequirements) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN8 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, BootEntropyResult) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN8 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, ProcessorCounterFrequency) == 0x7a8, "LOADER_PARAMETER_EXTENSION_WIN8 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, HypervisorExtension) == 0x7b0, "LOADER_PARAMETER_EXTENSION_WIN8 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.HardwareConfigurationId) == 0x7e8, "LOADER_PARAMETER_EXTENSION_WIN8 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.HalExtensionModuleList) == 0x7f8, "LOADER_PARAMETER_EXTENSION_WIN8 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.SystemTime) == 0x800, "LOADER_PARAMETER_EXTENSION_WIN8 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.TimeStampAtSystemTimeRead) == 0x808, "LOADER_PARAMETER_EXTENSION_WIN8 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.BootFlags) == 0x810, "LOADER_PARAMETER_EXTENSION_WIN8 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.InternalBootFlags) == 0x818, "LOADER_PARAMETER_EXTENSION_WIN8 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.WfsFPData) == 0x820, "LOADER_PARAMETER_EXTENSION_WIN8 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.WfsFPDataSize) == 0x824, "LOADER_PARAMETER_EXTENSION_WIN8 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block5b.AcpiBiosVersion) == 0x858, "LOADER_PARAMETER_EXTENSION_WIN8 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block5b.SmbiosVersion) == 0x860, "LOADER_PARAMETER_EXTENSION_WIN8 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block5b.EfiVersion) == 0x868, "LOADER_PARAMETER_EXTENSION_WIN8 EfiVersion");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN8) == 0x920, "LOADER_PARAMETER_EXTENSION_WIN8 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN8 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN8 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1a.EmInfFileImage) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN8 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN8 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1a.TriageDumpBlock) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN8 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1b.HeadlessLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN8 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1b.SMBiosEPSHeader) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN8 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1b.DrvDBImage) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN8 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1b.DrvDBSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN8 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1c.NetworkLoaderBlock) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN8 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1c.FirmwareDescriptorListHead) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN8 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1c.AcpiTable) == 0x68, "LOADER_PARAMETER_EXTENSION_WIN8 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block1c.AcpiTableSize) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN8 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, LoaderPerformanceData) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN8 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block2b.BootApplicationPersistentData) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN8 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block2b.WmdTestResult) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN8 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block2b.BootIdentifier) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN8 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, ResumePages) == 0xa8, "LOADER_PARAMETER_EXTENSION_WIN8 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, DumpHeader) == 0xb0, "LOADER_PARAMETER_EXTENSION_WIN8 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.BgContext) == 0xb8, "LOADER_PARAMETER_EXTENSION_WIN8 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.NumaLocalityInfo) == 0xc0, "LOADER_PARAMETER_EXTENSION_WIN8 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.NumaGroupAssignment) == 0xc8, "LOADER_PARAMETER_EXTENSION_WIN8 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.AttachedHives) == 0xd0, "LOADER_PARAMETER_EXTENSION_WIN8 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.MemoryCachingRequirementsCount) == 0xe0, "LOADER_PARAMETER_EXTENSION_WIN8 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block3.MemoryCachingRequirements) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN8 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, BootEntropyResult) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN8 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, ProcessorCounterFrequency) == 0x800, "LOADER_PARAMETER_EXTENSION_WIN8 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, HypervisorExtension) == 0x808, "LOADER_PARAMETER_EXTENSION_WIN8 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.HardwareConfigurationId) == 0x840, "LOADER_PARAMETER_EXTENSION_WIN8 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.HalExtensionModuleList) == 0x850, "LOADER_PARAMETER_EXTENSION_WIN8 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.SystemTime) == 0x860, "LOADER_PARAMETER_EXTENSION_WIN8 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.TimeStampAtSystemTimeRead) == 0x868, "LOADER_PARAMETER_EXTENSION_WIN8 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.BootFlags) == 0x870, "LOADER_PARAMETER_EXTENSION_WIN8 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.InternalBootFlags) == 0x878, "LOADER_PARAMETER_EXTENSION_WIN8 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.WfsFPData) == 0x880, "LOADER_PARAMETER_EXTENSION_WIN8 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block4.WfsFPDataSize) == 0x888, "LOADER_PARAMETER_EXTENSION_WIN8 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block5b.AcpiBiosVersion) == 0x8f0, "LOADER_PARAMETER_EXTENSION_WIN8 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block5b.SmbiosVersion) == 0x900, "LOADER_PARAMETER_EXTENSION_WIN8 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN8, Block5b.EfiVersion) == 0x910, "LOADER_PARAMETER_EXTENSION_WIN8 EfiVersion");
#endif

typedef struct {
    uint32_t maxEntropySources;
    BOOT_ENTROPY_SOURCE_LDR_RESULT EntropySourceResult[8];
    uint8_t SeedBytesForCng[48];
    uint8_t RngBytesForNtoskrnl[1024];
} BOOT_ENTROPY_LDR_RESULT_WIN81;

typedef struct {
    uint8_t Type;
    uint8_t Valid;
    union {
        uint8_t Reserved[2];
        struct {
            uint8_t BitWidth;
            uint8_t AccessSize;
        };
    };
    uint8_t* TranslatedAddress;
    uint32_t Length;
} DEBUG_DEVICE_ADDRESS;

typedef struct {
    uint64_t Start;
    uint64_t MaxEnd;
    void* VirtualAddress;
    uint32_t Length;
    uint8_t Cached;
    uint8_t Aligned;
} DEBUG_MEMORY_REQUIREMENTS;

typedef enum {
    KdNameSpacePCI,
    KdNameSpaceACPI,
    KdNameSpaceAny,
    KdNameSpaceNone,
    KdNameSpaceMax
} KD_NAMESPACE_ENUM;

typedef struct {
    uint32_t HwContextSize;
    uint8_t UseSerialFraming;
    uint8_t ValidUSBCoreId;
    uint8_t USBCoreId;
} DEBUG_TRANSPORT_DATA;

#define MAXIMUM_DEBUG_BARS 6

#define DBG_DEVICE_FLAG_HAL_SCRATCH_ALLOCATED   1
#define DBG_DEVICE_FLAG_BARS_MAPPED             2
#define DBG_DEVICE_FLAG_SCRATCH_ALLOCATED       4
#define DBG_DEVICE_FLAG_UNCACHED_MEMORY         8
#define DBG_DEVICE_FLAG_SYNTHETIC               16

typedef struct {
    uint32_t Bus;
    uint32_t Slot;
    uint16_t Segment;
    uint16_t VendorID;
    uint16_t DeviceID;
    uint8_t BaseClass;
    uint8_t SubClass;
    uint8_t ProgIf;
    uint8_t Flags;
    bool Initialized;
    bool Configured;
    DEBUG_DEVICE_ADDRESS BaseAddress[MAXIMUM_DEBUG_BARS];
    DEBUG_MEMORY_REQUIREMENTS Memory;
    uint16_t PortType;
    uint16_t PortSubtype;
    void* OemData;
    uint32_t OemDataLength;
    KD_NAMESPACE_ENUM NameSpace;
    WCHAR* NameSpacePath;
    uint32_t NameSpacePathLength;
    uint32_t TransportType;
    DEBUG_TRANSPORT_DATA TransportData;
} DEBUG_DEVICE_DESCRIPTOR;

// FIXME - also check sizes on x86
#ifdef __x86_64__
static_assert(sizeof(DEBUG_DEVICE_ADDRESS) == 0x18, "DEBUG_DEVICE_ADDRESS has incorrect size.");
static_assert(sizeof(DEBUG_MEMORY_REQUIREMENTS) == 0x20, "DEBUG_MEMORY_REQUIREMENTS has incorrect size.");
static_assert(sizeof(DEBUG_TRANSPORT_DATA) == 0x8, "DEBUG_TRANSPORT_DATA has incorrect size.");
static_assert(sizeof(DEBUG_DEVICE_DESCRIPTOR) == 0xf8, "DEBUG_DEVICE_DESCRIPTOR has incorrect size.");
#endif

typedef struct {
    uintptr_t BugcheckCode;
    uintptr_t BugcheckParameter1;
    uintptr_t BugcheckParameter2;
    uintptr_t BugcheckParameter3;
    uintptr_t BugcheckParameter4;
} LOADER_BUGCHECK_PARAMETERS;

#pragma pack(push,1)

typedef struct {
    uint32_t Version;
    uint32_t AbnormalResetOccurred;
    uint32_t OfflineMemoryDumpCapable;
} OFFLINE_CRASHDUMP_CONFIGURATION_TABLE_WIN81;

#pragma pack(pop)

typedef struct {
    LOADER_BUGCHECK_PARAMETERS BugcheckParameters;
    void* ApiSetSchema;
    uint32_t ApiSetSchemaSize;
    LIST_ENTRY ApiSetSchemaExtensions;
} LOADER_EXTENSION_BLOCK5A;

#pragma pack(push,1)

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA* LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
    LOADER_EXTENSION_BLOCK3 Block3;
#ifndef __x86_64__
    uint32_t padding2;
#endif
    BOOT_ENTROPY_LDR_RESULT_WIN81 BootEntropyResult;
    uint64_t ProcessorCounterFrequency;
    LOADER_PARAMETER_HYPERVISOR_EXTENSION HypervisorExtension;
    LOADER_EXTENSION_BLOCK4 Block4;
    LOADER_EXTENSION_BLOCK5A Block5a;
    LOADER_EXTENSION_BLOCK5B Block5b;
    DEBUG_DEVICE_DESCRIPTOR* KdDebugDevice;
    OFFLINE_CRASHDUMP_CONFIGURATION_TABLE_WIN81 OfflineCrashdumpConfigurationTable;
    uint32_t padding3;
    uint32_t padding4[4];
} LOADER_PARAMETER_EXTENSION_WIN81;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN81) == 0x8f0, "LOADER_PARAMETER_EXTENSION_WIN81 has incorrect size."); // FIXME - definitely 16 bytes on the end for x86 6.3.9600.18438?
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN81 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN81 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1a.EmInfFileImage) == 0x14, "LOADER_PARAMETER_EXTENSION_WIN81 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1a.EmInfFileSize) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN81 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1a.TriageDumpBlock) == 0x1c, "LOADER_PARAMETER_EXTENSION_WIN81 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1b.HeadlessLoaderBlock) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN81 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1b.SMBiosEPSHeader) == 0x24, "LOADER_PARAMETER_EXTENSION_WIN81 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1b.DrvDBImage) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN81 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1b.DrvDBSize) == 0x2c, "LOADER_PARAMETER_EXTENSION_WIN81 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1c.NetworkLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN81 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1c.FirmwareDescriptorListHead) == 0x3c, "LOADER_PARAMETER_EXTENSION_WIN81 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1c.AcpiTable) == 0x44, "LOADER_PARAMETER_EXTENSION_WIN81 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1c.AcpiTableSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN81 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, LoaderPerformanceData) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN81 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block2b.BootApplicationPersistentData) == 0x54, "LOADER_PARAMETER_EXTENSION_WIN81 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block2b.WmdTestResult) == 0x5c, "LOADER_PARAMETER_EXTENSION_WIN81 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block2b.BootIdentifier) == 0x60, "LOADER_PARAMETER_EXTENSION_WIN81 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, ResumePages) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN81 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, DumpHeader) == 0x74, "LOADER_PARAMETER_EXTENSION_WIN81 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.BgContext) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN81 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.NumaLocalityInfo) == 0x7c, "LOADER_PARAMETER_EXTENSION_WIN81 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.NumaGroupAssignment) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN81 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.AttachedHives) == 0x84, "LOADER_PARAMETER_EXTENSION_WIN81 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.MemoryCachingRequirementsCount) == 0x8c, "LOADER_PARAMETER_EXTENSION_WIN81 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.MemoryCachingRequirements) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN81 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, BootEntropyResult) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN81 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, ProcessorCounterFrequency) == 0x810, "LOADER_PARAMETER_EXTENSION_WIN81 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, HypervisorExtension) == 0x818, "LOADER_PARAMETER_EXTENSION_WIN81 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.HardwareConfigurationId) == 0x850, "LOADER_PARAMETER_EXTENSION_WIN81 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.HalExtensionModuleList) == 0x860, "LOADER_PARAMETER_EXTENSION_WIN81 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.SystemTime) == 0x868, "LOADER_PARAMETER_EXTENSION_WIN81 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.TimeStampAtSystemTimeRead) == 0x870, "LOADER_PARAMETER_EXTENSION_WIN81 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.BootFlags) == 0x878, "LOADER_PARAMETER_EXTENSION_WIN81 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.InternalBootFlags) == 0x880, "LOADER_PARAMETER_EXTENSION_WIN81 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.WfsFPData) == 0x888, "LOADER_PARAMETER_EXTENSION_WIN81 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.WfsFPDataSize) == 0x88c, "LOADER_PARAMETER_EXTENSION_WIN81 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5a.BugcheckParameters) == 0x890, "LOADER_PARAMETER_EXTENSION_WIN81 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5a.ApiSetSchema) == 0x8a4, "LOADER_PARAMETER_EXTENSION_WIN81 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5a.ApiSetSchemaSize) == 0x8a8, "LOADER_PARAMETER_EXTENSION_WIN81 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5a.ApiSetSchemaExtensions) == 0x8ac, "LOADER_PARAMETER_EXTENSION_WIN81 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5b.AcpiBiosVersion) == 0x8b4, "LOADER_PARAMETER_EXTENSION_WIN81 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5b.SmbiosVersion) == 0x8bc, "LOADER_PARAMETER_EXTENSION_WIN81 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5b.EfiVersion) == 0x8c4, "LOADER_PARAMETER_EXTENSION_WIN81 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, KdDebugDevice) == 0x8cc, "LOADER_PARAMETER_EXTENSION_WIN81 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, OfflineCrashdumpConfigurationTable) == 0x8d0, "LOADER_PARAMETER_EXTENSION_WIN81 OfflineCrashdumpConfigurationTable");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN81) == 0x998, "LOADER_PARAMETER_EXTENSION_WIN81 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN81 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN81 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1a.EmInfFileImage) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN81 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN81 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1a.TriageDumpBlock) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN81 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1b.HeadlessLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN81 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1b.SMBiosEPSHeader) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN81 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1b.DrvDBImage) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN81 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1b.DrvDBSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN81 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1c.NetworkLoaderBlock) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN81 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1c.FirmwareDescriptorListHead) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN81 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1c.AcpiTable) == 0x68, "LOADER_PARAMETER_EXTENSION_WIN81 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block1c.AcpiTableSize) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN81 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, LoaderPerformanceData) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN81 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block2b.BootApplicationPersistentData) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN81 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block2b.WmdTestResult) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN81 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block2b.BootIdentifier) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN81 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, ResumePages) == 0xa8, "LOADER_PARAMETER_EXTENSION_WIN81 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, DumpHeader) == 0xb0, "LOADER_PARAMETER_EXTENSION_WIN81 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.BgContext) == 0xb8, "LOADER_PARAMETER_EXTENSION_WIN81 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.NumaLocalityInfo) == 0xc0, "LOADER_PARAMETER_EXTENSION_WIN81 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.NumaGroupAssignment) == 0xc8, "LOADER_PARAMETER_EXTENSION_WIN81 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.AttachedHives) == 0xd0, "LOADER_PARAMETER_EXTENSION_WIN81 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.MemoryCachingRequirementsCount) == 0xe0, "LOADER_PARAMETER_EXTENSION_WIN81 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block3.MemoryCachingRequirements) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN81 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, BootEntropyResult) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN81 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, ProcessorCounterFrequency) == 0x868, "LOADER_PARAMETER_EXTENSION_WIN81 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, HypervisorExtension) == 0x870, "LOADER_PARAMETER_EXTENSION_WIN81 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.HardwareConfigurationId) == 0x8a8, "LOADER_PARAMETER_EXTENSION_WIN81 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.HalExtensionModuleList) == 0x8b8, "LOADER_PARAMETER_EXTENSION_WIN81 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.SystemTime) == 0x8c8, "LOADER_PARAMETER_EXTENSION_WIN81 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.TimeStampAtSystemTimeRead) == 0x8d0, "LOADER_PARAMETER_EXTENSION_WIN81 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.BootFlags) == 0x8d8, "LOADER_PARAMETER_EXTENSION_WIN81 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.InternalBootFlags) == 0x8e0, "LOADER_PARAMETER_EXTENSION_WIN81 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.WfsFPData) == 0x8e8, "LOADER_PARAMETER_EXTENSION_WIN81 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block4.WfsFPDataSize) == 0x8f0, "LOADER_PARAMETER_EXTENSION_WIN81 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5a.BugcheckParameters) == 0x8f8, "LOADER_PARAMETER_EXTENSION_WIN81 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5a.ApiSetSchema) == 0x920, "LOADER_PARAMETER_EXTENSION_WIN81 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5a.ApiSetSchemaSize) == 0x928, "LOADER_PARAMETER_EXTENSION_WIN81 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5a.ApiSetSchemaExtensions) == 0x930, "LOADER_PARAMETER_EXTENSION_WIN81 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5b.AcpiBiosVersion) == 0x940, "LOADER_PARAMETER_EXTENSION_WIN81 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5b.SmbiosVersion) == 0x950, "LOADER_PARAMETER_EXTENSION_WIN81 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, Block5b.EfiVersion) == 0x960, "LOADER_PARAMETER_EXTENSION_WIN81 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, KdDebugDevice) == 0x970, "LOADER_PARAMETER_EXTENSION_WIN81 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN81, OfflineCrashdumpConfigurationTable) == 0x978, "LOADER_PARAMETER_EXTENSION_WIN81 OfflineCrashdumpConfigurationTable");
#endif

typedef struct _LOADER_PARAMETER_CI_EXTENSION LOADER_PARAMETER_CI_EXTENSION;

#pragma pack(push,1)

typedef struct {
    uint32_t Version;
    uint32_t AbnormalResetOccurred;
    uint32_t OfflineMemoryDumpCapable;
    uint32_t padding;
    uint64_t ResetDataAddress;
    uint32_t ResetDataSize;
} OFFLINE_CRASHDUMP_CONFIGURATION_TABLE_WIN10;

typedef struct {
    uint32_t unknown[5];
} LOADER_HIVE_RECOVERY_INFO;

typedef struct {
    DEBUG_DEVICE_DESCRIPTOR* KdDebugDevice;
    OFFLINE_CRASHDUMP_CONFIGURATION_TABLE_WIN10 OfflineCrashdumpConfigurationTable;
    uint32_t padding3;
    UNICODE_STRING ManufacturingProfile;
    void* BbtBuffer;
#ifndef __x86_64__
    uint32_t padding4;
#endif
    uint64_t XsaveAllowedFeatures;
    uint32_t XsaveFlags;
#ifdef __x86_64__
    uint32_t padding5;
#endif
    void* BootOptions;
} LOADER_EXTENSION_BLOCK6;

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA* LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
    LOADER_EXTENSION_BLOCK3 Block3;
#ifndef __x86_64__
    uint32_t padding2;
#endif
    BOOT_ENTROPY_LDR_RESULT_WIN81 BootEntropyResult;
    uint64_t ProcessorCounterFrequency;
    LOADER_PARAMETER_HYPERVISOR_EXTENSION HypervisorExtension;
    LOADER_EXTENSION_BLOCK4 Block4;
    LOADER_EXTENSION_BLOCK5A Block5a;
    LOADER_EXTENSION_BLOCK5B Block5b;
    LOADER_EXTENSION_BLOCK6 Block6;
    uint32_t BootId;
#ifdef __x86_64__
    uint32_t padding6;
#endif
    LOADER_PARAMETER_CI_EXTENSION* CodeIntegrityData;
    uint32_t CodeIntegrityDataSize;
    LOADER_HIVE_RECOVERY_INFO SystemHiveRecoveryInfo;
} LOADER_PARAMETER_EXTENSION_WIN10;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10) == 0x930, "LOADER_PARAMETER_EXTENSION_WIN10 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1a.EmInfFileImage) == 0x14, "LOADER_PARAMETER_EXTENSION_WIN10 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1a.EmInfFileSize) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1a.TriageDumpBlock) == 0x1c, "LOADER_PARAMETER_EXTENSION_WIN10 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1b.HeadlessLoaderBlock) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1b.SMBiosEPSHeader) == 0x24, "LOADER_PARAMETER_EXTENSION_WIN10 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1b.DrvDBImage) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1b.DrvDBSize) == 0x2c, "LOADER_PARAMETER_EXTENSION_WIN10 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1c.NetworkLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1c.FirmwareDescriptorListHead) == 0x3c, "LOADER_PARAMETER_EXTENSION_WIN10 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1c.AcpiTable) == 0x44, "LOADER_PARAMETER_EXTENSION_WIN10 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1c.AcpiTableSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, LoaderPerformanceData) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block2b.BootApplicationPersistentData) == 0x54, "LOADER_PARAMETER_EXTENSION_WIN10 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block2b.WmdTestResult) == 0x5c, "LOADER_PARAMETER_EXTENSION_WIN10 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block2b.BootIdentifier) == 0x60, "LOADER_PARAMETER_EXTENSION_WIN10 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, ResumePages) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN10 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, DumpHeader) == 0x74, "LOADER_PARAMETER_EXTENSION_WIN10 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.BgContext) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN10 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.NumaLocalityInfo) == 0x7c, "LOADER_PARAMETER_EXTENSION_WIN10 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.NumaGroupAssignment) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN10 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.AttachedHives) == 0x84, "LOADER_PARAMETER_EXTENSION_WIN10 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.MemoryCachingRequirementsCount) == 0x8c, "LOADER_PARAMETER_EXTENSION_WIN10 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.MemoryCachingRequirements) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN10 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, BootEntropyResult) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN10 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, ProcessorCounterFrequency) == 0x810, "LOADER_PARAMETER_EXTENSION_WIN10 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, HypervisorExtension) == 0x818, "LOADER_PARAMETER_EXTENSION_WIN10 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.HardwareConfigurationId) == 0x850, "LOADER_PARAMETER_EXTENSION_WIN10 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.HalExtensionModuleList) == 0x860, "LOADER_PARAMETER_EXTENSION_WIN10 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.SystemTime) == 0x868, "LOADER_PARAMETER_EXTENSION_WIN10 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.TimeStampAtSystemTimeRead) == 0x870, "LOADER_PARAMETER_EXTENSION_WIN10 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.BootFlags) == 0x878, "LOADER_PARAMETER_EXTENSION_WIN10 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.InternalBootFlags) == 0x880, "LOADER_PARAMETER_EXTENSION_WIN10 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.WfsFPData) == 0x888, "LOADER_PARAMETER_EXTENSION_WIN10 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.WfsFPDataSize) == 0x88c, "LOADER_PARAMETER_EXTENSION_WIN10 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5a.BugcheckParameters) == 0x890, "LOADER_PARAMETER_EXTENSION_WIN10 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5a.ApiSetSchema) == 0x8a4, "LOADER_PARAMETER_EXTENSION_WIN10 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5a.ApiSetSchemaSize) == 0x8a8, "LOADER_PARAMETER_EXTENSION_WIN10 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5a.ApiSetSchemaExtensions) == 0x8ac, "LOADER_PARAMETER_EXTENSION_WIN10 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5b.AcpiBiosVersion) == 0x8b4, "LOADER_PARAMETER_EXTENSION_WIN10 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5b.SmbiosVersion) == 0x8bc, "LOADER_PARAMETER_EXTENSION_WIN10 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5b.EfiVersion) == 0x8c4, "LOADER_PARAMETER_EXTENSION_WIN10 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.KdDebugDevice) == 0x8cc, "LOADER_PARAMETER_EXTENSION_WIN10 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.OfflineCrashdumpConfigurationTable) == 0x8d0, "LOADER_PARAMETER_EXTENSION_WIN10 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.ManufacturingProfile) == 0x8f0, "LOADER_PARAMETER_EXTENSION_WIN10 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.BbtBuffer) == 0x8f8, "LOADER_PARAMETER_EXTENSION_WIN10 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.XsaveAllowedFeatures) == 0x900, "LOADER_PARAMETER_EXTENSION_WIN10 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.XsaveFlags) == 0x908, "LOADER_PARAMETER_EXTENSION_WIN10 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.BootOptions) == 0x90c, "LOADER_PARAMETER_EXTENSION_WIN10 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, BootId) == 0x910, "LOADER_PARAMETER_EXTENSION_WIN10 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, CodeIntegrityData) == 0x914, "LOADER_PARAMETER_EXTENSION_WIN10 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, CodeIntegrityDataSize) == 0x918, "LOADER_PARAMETER_EXTENSION_WIN10 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, SystemHiveRecoveryInfo) == 0x91c, "LOADER_PARAMETER_EXTENSION_WIN10 SystemHiveRecoveryInfo");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10) == 0x9f0, "LOADER_PARAMETER_EXTENSION_WIN10 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1a.EmInfFileImage) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1a.TriageDumpBlock) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1b.HeadlessLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1b.SMBiosEPSHeader) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN10 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1b.DrvDBImage) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN10 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1b.DrvDBSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1c.NetworkLoaderBlock) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1c.FirmwareDescriptorListHead) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN10 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1c.AcpiTable) == 0x68, "LOADER_PARAMETER_EXTENSION_WIN10 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block1c.AcpiTableSize) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN10 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, LoaderPerformanceData) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN10 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block2b.BootApplicationPersistentData) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN10 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block2b.WmdTestResult) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN10 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block2b.BootIdentifier) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN10 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, ResumePages) == 0xa8, "LOADER_PARAMETER_EXTENSION_WIN10 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, DumpHeader) == 0xb0, "LOADER_PARAMETER_EXTENSION_WIN10 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.BgContext) == 0xb8, "LOADER_PARAMETER_EXTENSION_WIN10 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.NumaLocalityInfo) == 0xc0, "LOADER_PARAMETER_EXTENSION_WIN10 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.NumaGroupAssignment) == 0xc8, "LOADER_PARAMETER_EXTENSION_WIN10 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.AttachedHives) == 0xd0, "LOADER_PARAMETER_EXTENSION_WIN10 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.MemoryCachingRequirementsCount) == 0xe0, "LOADER_PARAMETER_EXTENSION_WIN10 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block3.MemoryCachingRequirements) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN10 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, BootEntropyResult) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN10 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, ProcessorCounterFrequency) == 0x868, "LOADER_PARAMETER_EXTENSION_WIN10 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, HypervisorExtension) == 0x870, "LOADER_PARAMETER_EXTENSION_WIN10 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.HardwareConfigurationId) == 0x8a8, "LOADER_PARAMETER_EXTENSION_WIN10 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.HalExtensionModuleList) == 0x8b8, "LOADER_PARAMETER_EXTENSION_WIN10 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.SystemTime) == 0x8c8, "LOADER_PARAMETER_EXTENSION_WIN10 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.TimeStampAtSystemTimeRead) == 0x8d0, "LOADER_PARAMETER_EXTENSION_WIN10 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.BootFlags) == 0x8d8, "LOADER_PARAMETER_EXTENSION_WIN10 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.InternalBootFlags) == 0x8e0, "LOADER_PARAMETER_EXTENSION_WIN10 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.WfsFPData) == 0x8e8, "LOADER_PARAMETER_EXTENSION_WIN10 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block4.WfsFPDataSize) == 0x8f0, "LOADER_PARAMETER_EXTENSION_WIN10 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5a.BugcheckParameters) == 0x8f8, "LOADER_PARAMETER_EXTENSION_WIN10 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5a.ApiSetSchema) == 0x920, "LOADER_PARAMETER_EXTENSION_WIN10 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5a.ApiSetSchemaSize) == 0x928, "LOADER_PARAMETER_EXTENSION_WIN10 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5a.ApiSetSchemaExtensions) == 0x930, "LOADER_PARAMETER_EXTENSION_WIN10 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5b.AcpiBiosVersion) == 0x940, "LOADER_PARAMETER_EXTENSION_WIN10 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5b.SmbiosVersion) == 0x950, "LOADER_PARAMETER_EXTENSION_WIN10 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block5b.EfiVersion) == 0x960, "LOADER_PARAMETER_EXTENSION_WIN10 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.KdDebugDevice) == 0x970, "LOADER_PARAMETER_EXTENSION_WIN10 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.OfflineCrashdumpConfigurationTable) == 0x978, "LOADER_PARAMETER_EXTENSION_WIN10 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.ManufacturingProfile) == 0x998, "LOADER_PARAMETER_EXTENSION_WIN10 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.BbtBuffer) == 0x9a8, "LOADER_PARAMETER_EXTENSION_WIN10 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.XsaveAllowedFeatures) == 0x9b0, "LOADER_PARAMETER_EXTENSION_WIN10 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.XsaveFlags) == 0x9b8, "LOADER_PARAMETER_EXTENSION_WIN10 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, Block6.BootOptions) == 0x9c0, "LOADER_PARAMETER_EXTENSION_WIN10 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, BootId) == 0x9c8, "LOADER_PARAMETER_EXTENSION_WIN10 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, CodeIntegrityData) == 0x9d0, "LOADER_PARAMETER_EXTENSION_WIN10 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, CodeIntegrityDataSize) == 0x9d8, "LOADER_PARAMETER_EXTENSION_WIN10 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10, SystemHiveRecoveryInfo) == 0x9dc, "LOADER_PARAMETER_EXTENSION_WIN10 SystemHiveRecoveryInfo");
#endif

#pragma pack(push,1)

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA* LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
    LOADER_EXTENSION_BLOCK3 Block3;
#ifndef __x86_64__
    uint32_t padding2;
#endif
    BOOT_ENTROPY_LDR_RESULT_WIN81 BootEntropyResult;
    uint64_t ProcessorCounterFrequency;
    LOADER_PARAMETER_HYPERVISOR_EXTENSION HypervisorExtension;
    LOADER_EXTENSION_BLOCK4 Block4;
    LOADER_EXTENSION_BLOCK5A Block5a;
    LOADER_EXTENSION_BLOCK5B Block5b;
    LOADER_EXTENSION_BLOCK6 Block6;
    uint32_t IumEnablement;
    uint32_t IumPolicy;
    uint32_t IumStatus;
    uint32_t BootId;
    LOADER_PARAMETER_CI_EXTENSION* CodeIntegrityData;
    uint32_t CodeIntegrityDataSize;
    LOADER_HIVE_RECOVERY_INFO SystemHiveRecoveryInfo;
    uint32_t SoftRestartCount;
#ifdef __x86_64__
    uint32_t padding3;
#endif
    int64_t SoftRestartTime;
#ifdef __x86_64__
    void* HypercallCodeVa;
    void* HalVirtualAddress;
    uint64_t HalNumberOfBytes;
#endif
    uint32_t MajorRelease;
    uint32_t Reserved1;
} LOADER_PARAMETER_EXTENSION_WIN10_1607;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_1607) == 0x950, "LOADER_PARAMETER_EXTENSION_WIN10_1607 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_1607 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1a.EmInfFileImage) == 0x14, "LOADER_PARAMETER_EXTENSION_WIN10_1607 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1a.EmInfFileSize) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_1607 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1a.TriageDumpBlock) == 0x1c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1b.HeadlessLoaderBlock) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1b.SMBiosEPSHeader) == 0x24, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1b.DrvDBImage) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_1607 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1b.DrvDBSize) == 0x2c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1c.NetworkLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_1607 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1c.FirmwareDescriptorListHead) == 0x3c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1c.AcpiTable) == 0x44, "LOADER_PARAMETER_EXTENSION_WIN10_1607 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1c.AcpiTableSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10_1607 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, LoaderPerformanceData) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_1607 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block2b.BootApplicationPersistentData) == 0x54, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block2b.WmdTestResult) == 0x5c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block2b.BootIdentifier) == 0x60, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, ResumePages) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, DumpHeader) == 0x74, "LOADER_PARAMETER_EXTENSION_WIN10_1607 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.BgContext) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.NumaLocalityInfo) == 0x7c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.NumaGroupAssignment) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN10_1607 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.AttachedHives) == 0x84, "LOADER_PARAMETER_EXTENSION_WIN10_1607 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.MemoryCachingRequirementsCount) == 0x8c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.MemoryCachingRequirements) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN10_1607 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, BootEntropyResult) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, ProcessorCounterFrequency) == 0x810, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, HypervisorExtension) == 0x818, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.HardwareConfigurationId) == 0x850, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.HalExtensionModuleList) == 0x860, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.SystemTime) == 0x868, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.TimeStampAtSystemTimeRead) == 0x870, "LOADER_PARAMETER_EXTENSION_WIN10_1607 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.BootFlags) == 0x878, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.InternalBootFlags) == 0x880, "LOADER_PARAMETER_EXTENSION_WIN10_1607 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.WfsFPData) == 0x888, "LOADER_PARAMETER_EXTENSION_WIN10_1607 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.WfsFPDataSize) == 0x88c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5a.BugcheckParameters) == 0x890, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5a.ApiSetSchema) == 0x8a4, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5a.ApiSetSchemaSize) == 0x8a8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5a.ApiSetSchemaExtensions) == 0x8ac, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5b.AcpiBiosVersion) == 0x8b4, "LOADER_PARAMETER_EXTENSION_WIN10_1607 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5b.SmbiosVersion) == 0x8bc, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5b.EfiVersion) == 0x8c4, "LOADER_PARAMETER_EXTENSION_WIN10_1607 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.KdDebugDevice) == 0x8cc, "LOADER_PARAMETER_EXTENSION_WIN10_1607 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.OfflineCrashdumpConfigurationTable) == 0x8d0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.ManufacturingProfile) == 0x8f0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.BbtBuffer) == 0x8f8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.XsaveAllowedFeatures) == 0x900, "LOADER_PARAMETER_EXTENSION_WIN10_1607 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.XsaveFlags) == 0x908, "LOADER_PARAMETER_EXTENSION_WIN10_1607 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.BootOptions) == 0x90c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, IumEnablement) == 0x910, "LOADER_PARAMETER_EXTENSION_WIN10_1607 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, IumPolicy) == 0x914, "LOADER_PARAMETER_EXTENSION_WIN10_1607 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, IumStatus) == 0x918, "LOADER_PARAMETER_EXTENSION_WIN10_1607 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, BootId) == 0x91c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, CodeIntegrityData) == 0x920, "LOADER_PARAMETER_EXTENSION_WIN10_1607 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, CodeIntegrityDataSize) == 0x924, "LOADER_PARAMETER_EXTENSION_WIN10_1607 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, SystemHiveRecoveryInfo) == 0x928, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, SoftRestartCount) == 0x93c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, SoftRestartTime) == 0x940, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, MajorRelease) == 0x948, "LOADER_PARAMETER_EXTENSION_WIN10_1607 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Reserved1) == 0x94c, "LOADER_PARAMETER_EXTENSION_WIN10_1607 Reserved1");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_1607) == 0xa28, "LOADER_PARAMETER_EXTENSION_WIN10_1607 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_1607 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1a.EmInfFileImage) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_1607 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_1607 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1a.TriageDumpBlock) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_1607 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1b.HeadlessLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1b.SMBiosEPSHeader) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1b.DrvDBImage) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN10_1607 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1b.DrvDBSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10_1607 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1c.NetworkLoaderBlock) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_1607 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1c.FirmwareDescriptorListHead) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN10_1607 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1c.AcpiTable) == 0x68, "LOADER_PARAMETER_EXTENSION_WIN10_1607 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block1c.AcpiTableSize) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN10_1607 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, LoaderPerformanceData) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN10_1607 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block2b.BootApplicationPersistentData) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block2b.WmdTestResult) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN10_1607 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block2b.BootIdentifier) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, ResumePages) == 0xa8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, DumpHeader) == 0xb0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.BgContext) == 0xb8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.NumaLocalityInfo) == 0xc0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.NumaGroupAssignment) == 0xc8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.AttachedHives) == 0xd0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.MemoryCachingRequirementsCount) == 0xe0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block3.MemoryCachingRequirements) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, BootEntropyResult) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, ProcessorCounterFrequency) == 0x868, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, HypervisorExtension) == 0x870, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.HardwareConfigurationId) == 0x8a8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.HalExtensionModuleList) == 0x8b8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.SystemTime) == 0x8c8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.TimeStampAtSystemTimeRead) == 0x8d0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.BootFlags) == 0x8d8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.InternalBootFlags) == 0x8e0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.WfsFPData) == 0x8e8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block4.WfsFPDataSize) == 0x8f0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5a.BugcheckParameters) == 0x8f8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5a.ApiSetSchema) == 0x920, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5a.ApiSetSchemaSize) == 0x928, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5a.ApiSetSchemaExtensions) == 0x930, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5b.AcpiBiosVersion) == 0x940, "LOADER_PARAMETER_EXTENSION_WIN10_1607 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5b.SmbiosVersion) == 0x950, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block5b.EfiVersion) == 0x960, "LOADER_PARAMETER_EXTENSION_WIN10_1607 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.KdDebugDevice) == 0x970, "LOADER_PARAMETER_EXTENSION_WIN10_1607 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.OfflineCrashdumpConfigurationTable) == 0x978, "LOADER_PARAMETER_EXTENSION_WIN10_1607 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.ManufacturingProfile) == 0x998, "LOADER_PARAMETER_EXTENSION_WIN10_1607 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.BbtBuffer) == 0x9a8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.XsaveAllowedFeatures) == 0x9b0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.XsaveFlags) == 0x9b8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Block6.BootOptions) == 0x9c0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, IumEnablement) == 0x9c8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, IumPolicy) == 0x9cc, "LOADER_PARAMETER_EXTENSION_WIN10_1607 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, IumStatus) == 0x9d0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, BootId) == 0x9d4, "LOADER_PARAMETER_EXTENSION_WIN10_1607 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, CodeIntegrityData) == 0x9d8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, CodeIntegrityDataSize) == 0x9e0, "LOADER_PARAMETER_EXTENSION_WIN10_1607 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, SystemHiveRecoveryInfo) == 0x9e4, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, SoftRestartCount) == 0x9f8, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, SoftRestartTime) == 0xa00, "LOADER_PARAMETER_EXTENSION_WIN10_1607 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, HypercallCodeVa) == 0xa08, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HypercallCodeVa");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, HalVirtualAddress) == 0xa10, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HalVirtualAddress");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, HalNumberOfBytes) == 0xa18, "LOADER_PARAMETER_EXTENSION_WIN10_1607 HalNumberOfBytes");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, MajorRelease) == 0xa20, "LOADER_PARAMETER_EXTENSION_WIN10_1607 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1607, Reserved1) == 0xa24, "LOADER_PARAMETER_EXTENSION_WIN10_1607 Reserved1");
#endif

typedef struct {
    uint32_t maxEntropySources;
    BOOT_ENTROPY_SOURCE_LDR_RESULT EntropySourceResult[8];
    uint8_t SeedBytesForCng[48];
    uint8_t RngBytesForNtoskrnl[1024];
    uint8_t KdEntropy[32];
} BOOT_ENTROPY_LDR_RESULT_WIN1703;

#pragma pack(push,1)

typedef struct {
    uint8_t Supplied;
    uint8_t padding[7];
    uint8_t Pch;
    uint8_t EmbeddedController;
    uint8_t Reserved[6];
    uint32_t AdditionalInfo[8];
} LOADER_RESET_REASON;

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA* LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
    LOADER_EXTENSION_BLOCK3 Block3;
#ifndef __x86_64__
    uint32_t padding2;
#endif
    BOOT_ENTROPY_LDR_RESULT_WIN1703 BootEntropyResult;
    uint64_t ProcessorCounterFrequency;
    LOADER_PARAMETER_HYPERVISOR_EXTENSION HypervisorExtension;
    LOADER_EXTENSION_BLOCK4 Block4;
    LOADER_EXTENSION_BLOCK5A Block5a;
    LOADER_EXTENSION_BLOCK5B Block5b;
    LOADER_EXTENSION_BLOCK6 Block6;
    uint32_t IumEnablement;
    uint32_t IumPolicy;
    uint32_t IumStatus;
    uint32_t BootId;
    LOADER_PARAMETER_CI_EXTENSION* CodeIntegrityData;
    uint32_t CodeIntegrityDataSize;
    LOADER_HIVE_RECOVERY_INFO SystemHiveRecoveryInfo;
    uint32_t SoftRestartCount;
#ifdef __x86_64__
    uint32_t padding3;
#endif
    int64_t SoftRestartTime;
#ifdef __x86_64__
    void* HypercallCodeVa;
    void* HalVirtualAddress;
    uint64_t HalNumberOfBytes;
#endif
    uint32_t MajorRelease;
    uint32_t Reserved1;
    char NtBuildLab[0xe0];
    char NtBuildLabEx[0xe0];
    LOADER_RESET_REASON ResetReason;
    uint32_t MaxPciBusNumber;
    uint32_t padding4;
} LOADER_PARAMETER_EXTENSION_WIN10_1703;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_1703) == 0xb68, "LOADER_PARAMETER_EXTENSION_WIN10_1703 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_1703 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1a.EmInfFileImage) == 0x14, "LOADER_PARAMETER_EXTENSION_WIN10_1703 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1a.EmInfFileSize) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_1703 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1a.TriageDumpBlock) == 0x1c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1b.HeadlessLoaderBlock) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1b.SMBiosEPSHeader) == 0x24, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1b.DrvDBImage) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_1703 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1b.DrvDBSize) == 0x2c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1c.NetworkLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1c.FirmwareDescriptorListHead) == 0x3c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1c.AcpiTable) == 0x44, "LOADER_PARAMETER_EXTENSION_WIN10_1703 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1c.AcpiTableSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10_1703 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, LoaderPerformanceData) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_1703 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block2b.BootApplicationPersistentData) == 0x54, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block2b.WmdTestResult) == 0x5c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block2b.BootIdentifier) == 0x60, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, ResumePages) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, DumpHeader) == 0x74, "LOADER_PARAMETER_EXTENSION_WIN10_1703 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.BgContext) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.NumaLocalityInfo) == 0x7c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.NumaGroupAssignment) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.AttachedHives) == 0x84, "LOADER_PARAMETER_EXTENSION_WIN10_1703 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.MemoryCachingRequirementsCount) == 0x8c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.MemoryCachingRequirements) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN10_1703 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, BootEntropyResult) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, ProcessorCounterFrequency) == 0x830, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, HypervisorExtension) == 0x838, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.HardwareConfigurationId) == 0x870, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.HalExtensionModuleList) == 0x880, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.SystemTime) == 0x888, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.TimeStampAtSystemTimeRead) == 0x890, "LOADER_PARAMETER_EXTENSION_WIN10_1703 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.BootFlags) == 0x898, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.InternalBootFlags) == 0x8a0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.WfsFPData) == 0x8a8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.WfsFPDataSize) == 0x8ac, "LOADER_PARAMETER_EXTENSION_WIN10_1703 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5a.BugcheckParameters) == 0x8b0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5a.ApiSetSchema) == 0x8c4, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5a.ApiSetSchemaSize) == 0x8c8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5a.ApiSetSchemaExtensions) == 0x8cc, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5b.AcpiBiosVersion) == 0x8d4, "LOADER_PARAMETER_EXTENSION_WIN10_1703 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5b.SmbiosVersion) == 0x8dc, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5b.EfiVersion) == 0x8e4, "LOADER_PARAMETER_EXTENSION_WIN10_1703 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.KdDebugDevice) == 0x8ec, "LOADER_PARAMETER_EXTENSION_WIN10_1703 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.OfflineCrashdumpConfigurationTable) == 0x8f0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.ManufacturingProfile) == 0x910, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.BbtBuffer) == 0x918, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.XsaveAllowedFeatures) == 0x920, "LOADER_PARAMETER_EXTENSION_WIN10_1703 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.XsaveFlags) == 0x928, "LOADER_PARAMETER_EXTENSION_WIN10_1703 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.BootOptions) == 0x92c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, IumEnablement) == 0x930, "LOADER_PARAMETER_EXTENSION_WIN10_1703 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, IumPolicy) == 0x934, "LOADER_PARAMETER_EXTENSION_WIN10_1703 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, IumStatus) == 0x938, "LOADER_PARAMETER_EXTENSION_WIN10_1703 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, BootId) == 0x93c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, CodeIntegrityData) == 0x940, "LOADER_PARAMETER_EXTENSION_WIN10_1703 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, CodeIntegrityDataSize) == 0x944, "LOADER_PARAMETER_EXTENSION_WIN10_1703 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, SystemHiveRecoveryInfo) == 0x948, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, SoftRestartCount) == 0x95c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, SoftRestartTime) == 0x960, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, MajorRelease) == 0x968, "LOADER_PARAMETER_EXTENSION_WIN10_1703 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Reserved1) == 0x96c, "LOADER_PARAMETER_EXTENSION_WIN10_1703 Reserved1");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, NtBuildLab) == 0x970, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NtBuildLab");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, NtBuildLabEx) == 0xa50, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NtBuildLabEx");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, ResetReason) == 0xb30, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ResetReason");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, MaxPciBusNumber) == 0xb60, "LOADER_PARAMETER_EXTENSION_WIN10_1703 MaxPciBusNumber");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_1703) == 0xc40, "LOADER_PARAMETER_EXTENSION_WIN10_1703 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_1703 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1a.EmInfFileImage) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_1703 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_1703 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1a.TriageDumpBlock) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_1703 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1b.HeadlessLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1b.SMBiosEPSHeader) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1b.DrvDBImage) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN10_1703 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1b.DrvDBSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10_1703 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1c.NetworkLoaderBlock) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1c.FirmwareDescriptorListHead) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN10_1703 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1c.AcpiTable) == 0x68, "LOADER_PARAMETER_EXTENSION_WIN10_1703 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block1c.AcpiTableSize) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN10_1703 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, LoaderPerformanceData) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN10_1703 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block2b.BootApplicationPersistentData) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block2b.WmdTestResult) == 0x90, "LOADER_PARAMETER_EXTENSION_WIN10_1703 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block2b.BootIdentifier) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, ResumePages) == 0xa8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, DumpHeader) == 0xb0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.BgContext) == 0xb8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.NumaLocalityInfo) == 0xc0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.NumaGroupAssignment) == 0xc8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.AttachedHives) == 0xd0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.MemoryCachingRequirementsCount) == 0xe0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block3.MemoryCachingRequirements) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, BootEntropyResult) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, ProcessorCounterFrequency) == 0x888, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, HypervisorExtension) == 0x890, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.HardwareConfigurationId) == 0x8c8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.HalExtensionModuleList) == 0x8d8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.SystemTime) == 0x8e8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.TimeStampAtSystemTimeRead) == 0x8f0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.BootFlags) == 0x8f8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.InternalBootFlags) == 0x900, "LOADER_PARAMETER_EXTENSION_WIN10_1703 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.WfsFPData) == 0x908, "LOADER_PARAMETER_EXTENSION_WIN10_1703 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block4.WfsFPDataSize) == 0x910, "LOADER_PARAMETER_EXTENSION_WIN10_1703 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5a.BugcheckParameters) == 0x918, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5a.ApiSetSchema) == 0x940, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5a.ApiSetSchemaSize) == 0x948, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5a.ApiSetSchemaExtensions) == 0x950, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5b.AcpiBiosVersion) == 0x960, "LOADER_PARAMETER_EXTENSION_WIN10_1703 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5b.SmbiosVersion) == 0x970, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block5b.EfiVersion) == 0x980, "LOADER_PARAMETER_EXTENSION_WIN10_1703 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.KdDebugDevice) == 0x990, "LOADER_PARAMETER_EXTENSION_WIN10_1703 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.OfflineCrashdumpConfigurationTable) == 0x998, "LOADER_PARAMETER_EXTENSION_WIN10_1703 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.ManufacturingProfile) == 0x9b8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.BbtBuffer) == 0x9c8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.XsaveAllowedFeatures) == 0x9d0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.XsaveFlags) == 0x9d8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Block6.BootOptions) == 0x9e0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, IumEnablement) == 0x9e8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, IumPolicy) == 0x9ec, "LOADER_PARAMETER_EXTENSION_WIN10_1703 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, IumStatus) == 0x9f0, "LOADER_PARAMETER_EXTENSION_WIN10_1703 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, BootId) == 0x9f4, "LOADER_PARAMETER_EXTENSION_WIN10_1703 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, CodeIntegrityData) == 0x9f8, "LOADER_PARAMETER_EXTENSION_WIN10_1703 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, CodeIntegrityDataSize) == 0xa00, "LOADER_PARAMETER_EXTENSION_WIN10_1703 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, SystemHiveRecoveryInfo) == 0xa04, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, SoftRestartCount) == 0xa18, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, SoftRestartTime) == 0xa20, "LOADER_PARAMETER_EXTENSION_WIN10_1703 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, HypercallCodeVa) == 0xa28, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HypercallCodeVa");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, HalVirtualAddress) == 0xa30, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HalVirtualAddress");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, HalNumberOfBytes) == 0xa38, "LOADER_PARAMETER_EXTENSION_WIN10_1703 HalNumberOfBytes");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, MajorRelease) == 0xa40, "LOADER_PARAMETER_EXTENSION_WIN10_1703 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, Reserved1) == 0xa44, "LOADER_PARAMETER_EXTENSION_WIN10_1703 Reserved1");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, NtBuildLab) == 0xa48, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NtBuildLab");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, NtBuildLabEx) == 0xb28, "LOADER_PARAMETER_EXTENSION_WIN10_1703 NtBuildLabEx");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, ResetReason) == 0xc08, "LOADER_PARAMETER_EXTENSION_WIN10_1703 ResetReason");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1703, MaxPciBusNumber) == 0xc38, "LOADER_PARAMETER_EXTENSION_WIN10_1703 MaxPciBusNumber");
#endif

typedef struct {
    uint64_t StartTime;
    uint64_t EndTime;
    uint64_t PreloadEndTime;
    uint64_t TcbLoaderStartTime;
    uint64_t LoadHypervisorTime;
    uint64_t LaunchHypervisorTime;
    uint64_t LoadVsmTime;
    uint64_t LaunchVsmTime;
    uint64_t LoadDriversTime;
} LOADER_PERFORMANCE_DATA_1809;

typedef struct {
    uint32_t maxEntropySources;
    BOOT_ENTROPY_SOURCE_LDR_RESULT EntropySourceResult[10];
    uint8_t SeedBytesForCng[48];
    uint8_t RngBytesForNtoskrnl[1024];
    uint8_t KdEntropy[32];
} BOOT_ENTROPY_LDR_RESULT_WIN1809;

typedef struct {
    uint32_t InitialHypervisorCrashdumpAreaPageCount;
    uint32_t HypervisorCrashdumpAreaPageCount;
    uint64_t InitialHypervisorCrashdumpAreaSpa;
    uint64_t HypervisorCrashdumpAreaSpa;
    uint64_t HypervisorLaunchStatus;
    uint64_t HypervisorLaunchStatusArg1;
    uint64_t HypervisorLaunchStatusArg2;
    uint64_t HypervisorLaunchStatusArg3;
    uint64_t HypervisorLaunchStatusArg4;
} LOADER_PARAMETER_HYPERVISOR_EXTENSION_1809;

typedef struct {
    uint32_t Enabled;
    uint32_t Count;
    uint64_t Data[1];
} LEAP_SECOND_DATA;

#pragma pack(push,1)

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA_1809 LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
    LOADER_EXTENSION_BLOCK3 Block3;
    BOOT_ENTROPY_LDR_RESULT_WIN1809 BootEntropyResult;
    uint64_t ProcessorCounterFrequency;
    LOADER_PARAMETER_HYPERVISOR_EXTENSION_1809 HypervisorExtension;
    LOADER_EXTENSION_BLOCK4 Block4;
    LOADER_EXTENSION_BLOCK5A Block5a;
    LOADER_EXTENSION_BLOCK5B Block5b;
    LOADER_EXTENSION_BLOCK6 Block6;
    uint32_t IumEnablement;
    uint32_t IumPolicy;
    uint32_t IumStatus;
    uint32_t BootId;
    LOADER_PARAMETER_CI_EXTENSION* CodeIntegrityData;
    uint32_t CodeIntegrityDataSize;
    LOADER_HIVE_RECOVERY_INFO SystemHiveRecoveryInfo;
    uint32_t SoftRestartCount;
#ifdef __x86_64__
    uint32_t padding3;
#endif
    int64_t SoftRestartTime;
#ifdef __x86_64__
    void* HypercallCodeVa;
    void* HalVirtualAddress;
    uint64_t HalNumberOfBytes;
#endif
    LEAP_SECOND_DATA* LeapSecondData;
    uint32_t MajorRelease;
    uint32_t Reserved1;
    char NtBuildLab[0xe0];
    char NtBuildLabEx[0xe0];
#ifndef __x86_64__
    uint32_t padding4;
#endif
    LOADER_RESET_REASON ResetReason;
    uint32_t MaxPciBusNumber;
    uint32_t FeatureSettings;
} LOADER_PARAMETER_EXTENSION_WIN10_1809;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_1809) == 0xc88, "LOADER_PARAMETER_EXTENSION_WIN10_1809 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_1809 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1a.EmInfFileImage) == 0x14, "LOADER_PARAMETER_EXTENSION_WIN10_1809 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1a.EmInfFileSize) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_1809 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1a.TriageDumpBlock) == 0x1c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1b.HeadlessLoaderBlock) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1b.SMBiosEPSHeader) == 0x24, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1b.DrvDBImage) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_1809 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1b.DrvDBSize) == 0x2c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.NetworkLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.HalpIRQLToTPR) == 0x34, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HalpIRQLtoTPR");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.HalpVectorToIRQL) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HalpVectorToIRQL");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.FirmwareDescriptorListHead) == 0x3c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.AcpiTable) == 0x44, "LOADER_PARAMETER_EXTENSION_WIN10_1809 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.AcpiTableSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10_1809 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, LoaderPerformanceData) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_1809 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block2b.BootApplicationPersistentData) == 0x98, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block2b.WmdTestResult) == 0xa0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block2b.BootIdentifier) == 0xa4, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, ResumePages) == 0xb4, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, DumpHeader) == 0xb8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.BgContext) == 0xbc, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.NumaLocalityInfo) == 0xc0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.NumaGroupAssignment) == 0xc4, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.AttachedHives) == 0xc8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.MemoryCachingRequirementsCount) == 0xd0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.MemoryCachingRequirements) == 0xd4, "LOADER_PARAMETER_EXTENSION_WIN10_1809 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, BootEntropyResult) == 0xd8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, ProcessorCounterFrequency) == 0x940, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, HypervisorExtension) == 0x948, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.HardwareConfigurationId) == 0x988, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.HalExtensionModuleList) == 0x998, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.SystemTime) == 0x9a0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.TimeStampAtSystemTimeRead) == 0x9a8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.BootFlags) == 0x9b0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.InternalBootFlags) == 0x9b8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.WfsFPData) == 0x9c0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.WfsFPDataSize) == 0x9c4, "LOADER_PARAMETER_EXTENSION_WIN10_1809 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5a.BugcheckParameters) == 0x9c8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5a.ApiSetSchema) == 0x9dc, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5a.ApiSetSchemaSize) == 0x9e0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5a.ApiSetSchemaExtensions) == 0x9e4, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5b.AcpiBiosVersion) == 0x9ec, "LOADER_PARAMETER_EXTENSION_WIN10_1809 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5b.SmbiosVersion) == 0x9f4, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5b.EfiVersion) == 0x9fc, "LOADER_PARAMETER_EXTENSION_WIN10_1809 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.KdDebugDevice) == 0xa04, "LOADER_PARAMETER_EXTENSION_WIN10_1809 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.OfflineCrashdumpConfigurationTable) == 0xa08, "LOADER_PARAMETER_EXTENSION_WIN10_1809 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.ManufacturingProfile) == 0xa28, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.BbtBuffer) == 0xa30, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.XsaveAllowedFeatures) == 0xa38, "LOADER_PARAMETER_EXTENSION_WIN10_1809 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.XsaveFlags) == 0xa40, "LOADER_PARAMETER_EXTENSION_WIN10_1809 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.BootOptions) == 0xa44, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, IumEnablement) == 0xa48, "LOADER_PARAMETER_EXTENSION_WIN10_1809 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, IumPolicy) == 0xa4c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, IumStatus) == 0xa50, "LOADER_PARAMETER_EXTENSION_WIN10_1809 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, BootId) == 0xa54, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, CodeIntegrityData) == 0xa58, "LOADER_PARAMETER_EXTENSION_WIN10_1809 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, CodeIntegrityDataSize) == 0xa5c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, SystemHiveRecoveryInfo) == 0xa60, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, SoftRestartCount) == 0xa74, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, SoftRestartTime) == 0xa78, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, LeapSecondData) == 0xa80, "LOADER_PARAMETER_EXTENSION_WIN10_1809 LeapSecondData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, MajorRelease) == 0xa84, "LOADER_PARAMETER_EXTENSION_WIN10_1809 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Reserved1) == 0xa88, "LOADER_PARAMETER_EXTENSION_WIN10_1809 Reserved1");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, NtBuildLab) == 0xa8c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NtBuildLab");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, NtBuildLabEx) == 0xb6c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NtBuildLabEx");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, ResetReason) == 0xc50, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ResetReason");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, MaxPciBusNumber) == 0xc80, "LOADER_PARAMETER_EXTENSION_WIN10_1809 MaxPciBusNumber");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, FeatureSettings) == 0xc84, "LOADER_PARAMETER_EXTENSION_WIN10_1809 FeatureSettings");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_1809) == 0xd60, "LOADER_PARAMETER_EXTENSION_WIN10_1809 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_1809 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1a.EmInfFileImage) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_1809 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_1809 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1a.TriageDumpBlock) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_1809 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1b.HeadlessLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1b.SMBiosEPSHeader) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1b.DrvDBImage) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN10_1809 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1b.DrvDBSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10_1809 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.NetworkLoaderBlock) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.FirmwareDescriptorListHead) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN10_1809 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.AcpiTable) == 0x68, "LOADER_PARAMETER_EXTENSION_WIN10_1809 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block1c.AcpiTableSize) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN10_1809 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, LoaderPerformanceData) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN10_1809 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block2b.BootApplicationPersistentData) == 0xc0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block2b.WmdTestResult) == 0xd0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block2b.BootIdentifier) == 0xd8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, ResumePages) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, DumpHeader) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.BgContext) == 0xf8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.NumaLocalityInfo) == 0x100, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.NumaGroupAssignment) == 0x108, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.AttachedHives) == 0x110, "LOADER_PARAMETER_EXTENSION_WIN10_1809 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.MemoryCachingRequirementsCount) == 0x120, "LOADER_PARAMETER_EXTENSION_WIN10_1809 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block3.MemoryCachingRequirements) == 0x128, "LOADER_PARAMETER_EXTENSION_WIN10_1809 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, BootEntropyResult) == 0x130, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, ProcessorCounterFrequency) == 0x998, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, HypervisorExtension) == 0x9a0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.HardwareConfigurationId) == 0x9e0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.HalExtensionModuleList) == 0x9f0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.SystemTime) == 0xa00, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.TimeStampAtSystemTimeRead) == 0xa08, "LOADER_PARAMETER_EXTENSION_WIN10_1809 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.BootFlags) == 0xa10, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.InternalBootFlags) == 0xa18, "LOADER_PARAMETER_EXTENSION_WIN10_1809 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.WfsFPData) == 0xa20, "LOADER_PARAMETER_EXTENSION_WIN10_1809 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block4.WfsFPDataSize) == 0xa28, "LOADER_PARAMETER_EXTENSION_WIN10_1809 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5a.BugcheckParameters) == 0xa30, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5a.ApiSetSchema) == 0xa58, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5a.ApiSetSchemaSize) == 0xa60, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5a.ApiSetSchemaExtensions) == 0xa68, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5b.AcpiBiosVersion) == 0xa78, "LOADER_PARAMETER_EXTENSION_WIN10_1809 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5b.SmbiosVersion) == 0xa88, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block5b.EfiVersion) == 0xa98, "LOADER_PARAMETER_EXTENSION_WIN10_1809 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.KdDebugDevice) == 0xaa8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.OfflineCrashdumpConfigurationTable) == 0xab0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.ManufacturingProfile) == 0xad0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.BbtBuffer) == 0xae0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.XsaveAllowedFeatures) == 0xae8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.XsaveFlags) == 0xaf0, "LOADER_PARAMETER_EXTENSION_WIN10_1809 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Block6.BootOptions) == 0xaf8, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, IumEnablement) == 0xb00, "LOADER_PARAMETER_EXTENSION_WIN10_1809 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, IumPolicy) == 0xb04, "LOADER_PARAMETER_EXTENSION_WIN10_1809 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, IumStatus) == 0xb08, "LOADER_PARAMETER_EXTENSION_WIN10_1809 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, BootId) == 0xb0c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, CodeIntegrityData) == 0xb10, "LOADER_PARAMETER_EXTENSION_WIN10_1809 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, CodeIntegrityDataSize) == 0xb18, "LOADER_PARAMETER_EXTENSION_WIN10_1809 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, SystemHiveRecoveryInfo) == 0xb1c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, SoftRestartCount) == 0xb30, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, SoftRestartTime) == 0xb38, "LOADER_PARAMETER_EXTENSION_WIN10_1809 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, HypercallCodeVa) == 0xb40, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HypercallCodeVa");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, HalVirtualAddress) == 0xb48, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HalVirtualAddress");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, HalNumberOfBytes) == 0xb50, "LOADER_PARAMETER_EXTENSION_WIN10_1809 HalNumberOfBytes");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, LeapSecondData) == 0xb58, "LOADER_PARAMETER_EXTENSION_WIN10_1809 LeapSecondData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, MajorRelease) == 0xb60, "LOADER_PARAMETER_EXTENSION_WIN10_1809 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, Reserved1) == 0xb64, "LOADER_PARAMETER_EXTENSION_WIN10_1809 Reserved1");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, NtBuildLab) == 0xb68, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NtBuildLab");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, NtBuildLabEx) == 0xc48, "LOADER_PARAMETER_EXTENSION_WIN10_1809 NtBuildLabEx");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, ResetReason) == 0xd28, "LOADER_PARAMETER_EXTENSION_WIN10_1809 ResetReason");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, MaxPciBusNumber) == 0xd58, "LOADER_PARAMETER_EXTENSION_WIN10_1809 MaxPciBusNumber");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1809, FeatureSettings) == 0xd5c, "LOADER_PARAMETER_EXTENSION_WIN10_1809 FeatureSettings");
#endif

typedef struct {
    uint64_t StartTime;
    uint64_t EndTime;
    uint64_t PreloadEndTime;
    uint64_t TcbLoaderStartTime;
    uint64_t LoadHypervisorTime;
    uint64_t LaunchHypervisorTime;
    uint64_t LoadVsmTime;
    uint64_t LaunchVsmTime;
    uint64_t ExecuteTransitionStartTime;
    uint64_t ExecuteTransitionEndTime;
    uint64_t LoadDriversTime;
    uint64_t CleanupVsmTime;
} LOADER_PERFORMANCE_DATA_1903;

typedef struct {
    uint64_t LaunchVsmMark[8];
} VSM_PERFORMANCE_DATA;

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    LOADER_EXTENSION_BLOCK1B Block1b;
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA_1903 LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
    LOADER_EXTENSION_BLOCK3 Block3;
    BOOT_ENTROPY_LDR_RESULT_WIN1809 BootEntropyResult;
    uint64_t ProcessorCounterFrequency;
    LOADER_PARAMETER_HYPERVISOR_EXTENSION_1809 HypervisorExtension;
    LOADER_EXTENSION_BLOCK4 Block4;
    LOADER_EXTENSION_BLOCK5A Block5a;
    LOADER_EXTENSION_BLOCK5B Block5b;
    LOADER_EXTENSION_BLOCK6 Block6;
    uint32_t IumEnablement;
    uint32_t IumPolicy;
    uint32_t IumStatus;
    uint32_t BootId;
    LOADER_PARAMETER_CI_EXTENSION* CodeIntegrityData;
    uint32_t CodeIntegrityDataSize;
    LOADER_HIVE_RECOVERY_INFO SystemHiveRecoveryInfo;
    uint32_t SoftRestartCount;
#ifdef __x86_64__
    uint32_t padding3;
#endif
    int64_t SoftRestartTime;
#ifdef __x86_64__
    void* HypercallCodeVa;
    void* HalVirtualAddress;
    uint64_t HalNumberOfBytes;
#endif
    LEAP_SECOND_DATA* LeapSecondData;
    uint32_t MajorRelease;
    uint32_t Reserved1;
    char NtBuildLab[0xe0];
    char NtBuildLabEx[0xe0];
#ifndef __x86_64__
    uint32_t padding4;
#endif
    LOADER_RESET_REASON ResetReason;
    uint32_t MaxPciBusNumber;
    uint32_t FeatureSettings;
    uint32_t HotPatchReserveSize;
    uint32_t RetpolineReserveSize;
#ifdef __x86_64__
    struct {
        void* CodeBase;
        uint32_t CodeSize;
    } MiniExecutive;
#endif
    VSM_PERFORMANCE_DATA VsmPerformanceData;
} LOADER_PARAMETER_EXTENSION_WIN10_1903;

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_1903) == 0xce8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_1903 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1a.EmInfFileImage) == 0x14, "LOADER_PARAMETER_EXTENSION_WIN10_1903 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1a.EmInfFileSize) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_1903 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1a.TriageDumpBlock) == 0x1c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1b.HeadlessLoaderBlock) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1b.SMBiosEPSHeader) == 0x24, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1b.DrvDBImage) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_1903 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1b.DrvDBSize) == 0x2c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.NetworkLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.HalpIRQLToTPR) == 0x34, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HalpIRQLtoTPR");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.HalpVectorToIRQL) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HalpVectorToIRQL");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.FirmwareDescriptorListHead) == 0x3c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.AcpiTable) == 0x44, "LOADER_PARAMETER_EXTENSION_WIN10_1903 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.AcpiTableSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10_1903 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, LoaderPerformanceData) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_1903 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block2b.BootApplicationPersistentData) == 0xb0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block2b.WmdTestResult) == 0xb8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block2b.BootIdentifier) == 0xbc, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, ResumePages) == 0xcc, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, DumpHeader) == 0xd0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.BgContext) == 0xd4, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.NumaLocalityInfo) == 0xd8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.NumaGroupAssignment) == 0xdc, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.AttachedHives) == 0xe0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.MemoryCachingRequirementsCount) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.MemoryCachingRequirements) == 0xec, "LOADER_PARAMETER_EXTENSION_WIN10_1903 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, BootEntropyResult) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, ProcessorCounterFrequency) == 0x958, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, HypervisorExtension) == 0x960, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.HardwareConfigurationId) == 0x9a0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.HalExtensionModuleList) == 0x9b0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.SystemTime) == 0x9b8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.TimeStampAtSystemTimeRead) == 0x9c0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.BootFlags) == 0x9c8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.InternalBootFlags) == 0x9d0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.WfsFPData) == 0x9d8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.WfsFPDataSize) == 0x9dc, "LOADER_PARAMETER_EXTENSION_WIN10_1903 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5a.BugcheckParameters) == 0x9e0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5a.ApiSetSchema) == 0x9f4, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5a.ApiSetSchemaSize) == 0x9f8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5a.ApiSetSchemaExtensions) == 0x9fc, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5b.AcpiBiosVersion) == 0xa04, "LOADER_PARAMETER_EXTENSION_WIN10_1903 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5b.SmbiosVersion) == 0xa0c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5b.EfiVersion) == 0xa14, "LOADER_PARAMETER_EXTENSION_WIN10_1903 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.KdDebugDevice) == 0xa1c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.OfflineCrashdumpConfigurationTable) == 0xa20, "LOADER_PARAMETER_EXTENSION_WIN10_1903 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.ManufacturingProfile) == 0xa40, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.BbtBuffer) == 0xa48, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.XsaveAllowedFeatures) == 0xa50, "LOADER_PARAMETER_EXTENSION_WIN10_1903 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.XsaveFlags) == 0xa58, "LOADER_PARAMETER_EXTENSION_WIN10_1903 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.BootOptions) == 0xa5c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, IumEnablement) == 0xa60, "LOADER_PARAMETER_EXTENSION_WIN10_1903 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, IumPolicy) == 0xa64, "LOADER_PARAMETER_EXTENSION_WIN10_1903 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, IumStatus) == 0xa68, "LOADER_PARAMETER_EXTENSION_WIN10_1903 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, BootId) == 0xa6c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, CodeIntegrityData) == 0xa70, "LOADER_PARAMETER_EXTENSION_WIN10_1903 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, CodeIntegrityDataSize) == 0xa74, "LOADER_PARAMETER_EXTENSION_WIN10_1903 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, SystemHiveRecoveryInfo) == 0xa78, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, SoftRestartCount) == 0xa8c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, SoftRestartTime) == 0xa90, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, LeapSecondData) == 0xa98, "LOADER_PARAMETER_EXTENSION_WIN10_1903 LeapSecondData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, MajorRelease) == 0xa9c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Reserved1) == 0xaa0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 Reserved1");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, NtBuildLab) == 0xaa4, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NtBuildLab");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, NtBuildLabEx) == 0xb84, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NtBuildLabEx");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, ResetReason) == 0xc68, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ResetReason");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, MaxPciBusNumber) == 0xc98, "LOADER_PARAMETER_EXTENSION_WIN10_1903 MaxPciBusNumber");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, FeatureSettings) == 0xc9c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 FeatureSettings");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, HotPatchReserveSize) == 0xca0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HotPatchReserveSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, RetpolineReserveSize) == 0xca4, "LOADER_PARAMETER_EXTENSION_WIN10_1903 RetpolineReserveSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, VsmPerformanceData) == 0xca8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 VsmPerformanceData");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_1903) == 0xdd0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_1903 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1a.EmInfFileImage) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_1903 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_1903 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1a.TriageDumpBlock) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_1903 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1b.HeadlessLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1b.SMBiosEPSHeader) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1b.DrvDBImage) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN10_1903 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1b.DrvDBSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10_1903 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.NetworkLoaderBlock) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.FirmwareDescriptorListHead) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN10_1903 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.AcpiTable) == 0x68, "LOADER_PARAMETER_EXTENSION_WIN10_1903 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block1c.AcpiTableSize) == 0x70, "LOADER_PARAMETER_EXTENSION_WIN10_1903 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, LoaderPerformanceData) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN10_1903 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block2b.BootApplicationPersistentData) == 0xd8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block2b.WmdTestResult) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block2b.BootIdentifier) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, ResumePages) == 0x100, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, DumpHeader) == 0x108, "LOADER_PARAMETER_EXTENSION_WIN10_1903 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.BgContext) == 0x110, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.NumaLocalityInfo) == 0x118, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.NumaGroupAssignment) == 0x120, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.AttachedHives) == 0x128, "LOADER_PARAMETER_EXTENSION_WIN10_1903 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.MemoryCachingRequirementsCount) == 0x138, "LOADER_PARAMETER_EXTENSION_WIN10_1903 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block3.MemoryCachingRequirements) == 0x140, "LOADER_PARAMETER_EXTENSION_WIN10_1903 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, BootEntropyResult) == 0x148, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, ProcessorCounterFrequency) == 0x9b0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, HypervisorExtension) == 0x9b8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.HardwareConfigurationId) == 0x9f8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.HalExtensionModuleList) == 0xa08, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.SystemTime) == 0xa18, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.TimeStampAtSystemTimeRead) == 0xa20, "LOADER_PARAMETER_EXTENSION_WIN10_1903 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.BootFlags) == 0xa28, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.InternalBootFlags) == 0xa30, "LOADER_PARAMETER_EXTENSION_WIN10_1903 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.WfsFPData) == 0xa38, "LOADER_PARAMETER_EXTENSION_WIN10_1903 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block4.WfsFPDataSize) == 0xa40, "LOADER_PARAMETER_EXTENSION_WIN10_1903 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5a.BugcheckParameters) == 0xa48, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5a.ApiSetSchema) == 0xa70, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5a.ApiSetSchemaSize) == 0xa78, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5a.ApiSetSchemaExtensions) == 0xa80, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5b.AcpiBiosVersion) == 0xa90, "LOADER_PARAMETER_EXTENSION_WIN10_1903 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5b.SmbiosVersion) == 0xaa0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block5b.EfiVersion) == 0xab0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.KdDebugDevice) == 0xac0, "LOADER_PARAMETER_EXTENSION_WIN10_1903 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.OfflineCrashdumpConfigurationTable) == 0xac8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.ManufacturingProfile) == 0xae8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.BbtBuffer) == 0xaf8, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.XsaveAllowedFeatures) == 0xb00, "LOADER_PARAMETER_EXTENSION_WIN10_1903 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.XsaveFlags) == 0xb08, "LOADER_PARAMETER_EXTENSION_WIN10_1903 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Block6.BootOptions) == 0xb10, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, IumEnablement) == 0xb18, "LOADER_PARAMETER_EXTENSION_WIN10_1903 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, IumPolicy) == 0xb1c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, IumStatus) == 0xb20, "LOADER_PARAMETER_EXTENSION_WIN10_1903 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, BootId) == 0xb24, "LOADER_PARAMETER_EXTENSION_WIN10_1903 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, CodeIntegrityData) == 0xb28, "LOADER_PARAMETER_EXTENSION_WIN10_1903 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, CodeIntegrityDataSize) == 0xb30, "LOADER_PARAMETER_EXTENSION_WIN10_1903 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, SystemHiveRecoveryInfo) == 0xb34, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, SoftRestartCount) == 0xb48, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, SoftRestartTime) == 0xb50, "LOADER_PARAMETER_EXTENSION_WIN10_1903 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, HypercallCodeVa) == 0xb58, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HypercallCodeVa");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, HalVirtualAddress) == 0xb60, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HalVirtualAddress");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, HalNumberOfBytes) == 0xb68, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HalNumberOfBytes");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, LeapSecondData) == 0xb70, "LOADER_PARAMETER_EXTENSION_WIN10_1903 LeapSecondData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, MajorRelease) == 0xb78, "LOADER_PARAMETER_EXTENSION_WIN10_1903 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, Reserved1) == 0xb7c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 Reserved1");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, NtBuildLab) == 0xb80, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NtBuildLab");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, NtBuildLabEx) == 0xc60, "LOADER_PARAMETER_EXTENSION_WIN10_1903 NtBuildLabEx");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, ResetReason) == 0xd40, "LOADER_PARAMETER_EXTENSION_WIN10_1903 ResetReason");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, MaxPciBusNumber) == 0xd70, "LOADER_PARAMETER_EXTENSION_WIN10_1903 MaxPciBusNumber");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, FeatureSettings) == 0xd74, "LOADER_PARAMETER_EXTENSION_WIN10_1903 FeatureSettings");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, HotPatchReserveSize) == 0xd78, "LOADER_PARAMETER_EXTENSION_WIN10_1903 HotPatchReserveSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, RetpolineReserveSize) == 0xd7c, "LOADER_PARAMETER_EXTENSION_WIN10_1903 RetpolineReserveSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, MiniExecutive) == 0xd80, "LOADER_PARAMETER_EXTENSION_WIN10_1903 MiniExecutive");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_1903, VsmPerformanceData) == 0xd90, "LOADER_PARAMETER_EXTENSION_WIN10_1903 VsmPerformanceData");
#endif

typedef struct {
    uint32_t ProximityId;
#ifdef __x86_64__
    uint32_t padding;
#endif
    uint64_t BasePage;
    uint64_t EndPage;
} NUMA_MEMORY_RANGE;

typedef struct {
    uint32_t Size;
    PROFILE_PARAMETER_BLOCK Profile;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    LOADER_EXTENSION_BLOCK1A Block1a;
    LOADER_EXTENSION_BLOCK1B Block1b;
    void* DrvDBPatchImage;
    uint32_t DrvDBPatchSize;
#ifdef __x86_64__
    uint32_t padding2;
#endif
    LOADER_EXTENSION_BLOCK1C Block1c;
    LOADER_EXTENSION_BLOCK2A Block2a;
    LOADER_PERFORMANCE_DATA_1903 LoaderPerformanceData;
    LOADER_EXTENSION_BLOCK2B Block2b;
    uintptr_t ResumePages;
    void* DumpHeader;
    LOADER_EXTENSION_BLOCK3 Block3;
    BOOT_ENTROPY_LDR_RESULT_WIN1809 BootEntropyResult;
    uint64_t ProcessorCounterFrequency;
    LOADER_PARAMETER_HYPERVISOR_EXTENSION_1809 HypervisorExtension;
    LOADER_EXTENSION_BLOCK4 Block4;
    LOADER_EXTENSION_BLOCK5A Block5a;
    LOADER_EXTENSION_BLOCK5B Block5b;
    LOADER_EXTENSION_BLOCK6 Block6;
    uint32_t IumEnablement;
    uint32_t IumPolicy;
    uint32_t IumStatus;
    uint32_t BootId;
    LOADER_PARAMETER_CI_EXTENSION* CodeIntegrityData;
    uint32_t CodeIntegrityDataSize;
    LOADER_HIVE_RECOVERY_INFO SystemHiveRecoveryInfo;
    uint32_t SoftRestartCount;
#ifdef __x86_64__
    uint32_t padding3;
#endif
    int64_t SoftRestartTime;
#ifdef __x86_64__
    void* HypercallCodeVa;
    void* HalVirtualAddress;
    uint64_t HalNumberOfBytes;
#endif
    LEAP_SECOND_DATA* LeapSecondData;
    uint32_t MajorRelease;
    uint32_t Reserved1;
    char NtBuildLab[0xe0];
    char NtBuildLabEx[0xe0];
#ifndef __x86_64__
    uint32_t padding4;
#endif
    LOADER_RESET_REASON ResetReason;
    uint32_t MaxPciBusNumber;
    uint32_t FeatureSettings;
    uint32_t HotPatchReserveSize;
    uint32_t RetpolineReserveSize;
#ifdef __x86_64__
    struct {
        void* CodeBase;
        uint32_t CodeSize;
    } MiniExecutive;
#endif
    VSM_PERFORMANCE_DATA VsmPerformanceData;
    NUMA_MEMORY_RANGE* NumaMemoryRanges;
    uint32_t NumaMemoryRangeCount;
    uint32_t IommuFaultPolicy;
} LOADER_PARAMETER_EXTENSION_WIN10_2004;

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_2004) == 0xd00, "LOADER_PARAMETER_EXTENSION_WIN10_2004 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1a.EmInfFileImage) == 0x14, "LOADER_PARAMETER_EXTENSION_WIN10_2004 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1a.EmInfFileSize) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_2004 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1a.TriageDumpBlock) == 0x1c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1b.HeadlessLoaderBlock) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1b.SMBiosEPSHeader) == 0x24, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1b.DrvDBImage) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1b.DrvDBSize) == 0x2c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, DrvDBPatchImage) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DrvDBPatchImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, DrvDBPatchSize) == 0x34, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DrvDBPatchSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.NetworkLoaderBlock) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.HalpIRQLToTPR) == 0x3c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HalpIRQLtoTPR");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.HalpVectorToIRQL) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HalpVectorToIRQL");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.FirmwareDescriptorListHead) == 0x44, "LOADER_PARAMETER_EXTENSION_WIN10_2004 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.AcpiTable) == 0x4c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.AcpiTableSize) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_2004 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, LoaderPerformanceData) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN10_2004 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block2b.BootApplicationPersistentData) == 0xb8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block2b.WmdTestResult) == 0xc0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block2b.BootIdentifier) == 0xc4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, ResumePages) == 0xd4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, DumpHeader) == 0xd8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.BgContext) == 0xdc, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.NumaLocalityInfo) == 0xe0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.NumaGroupAssignment) == 0xe4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.AttachedHives) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.MemoryCachingRequirementsCount) == 0xf0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.MemoryCachingRequirements) == 0xf4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, BootEntropyResult) == 0xf8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, ProcessorCounterFrequency) == 0x960, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, HypervisorExtension) == 0x968, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.HardwareConfigurationId) == 0x9a8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.HalExtensionModuleList) == 0x9b8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.SystemTime) == 0x9c0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.TimeStampAtSystemTimeRead) == 0x9c8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.BootFlags) == 0x9d0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.InternalBootFlags) == 0x9d8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.WfsFPData) == 0x9e0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.WfsFPDataSize) == 0x9e4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5a.BugcheckParameters) == 0x9e8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5a.ApiSetSchema) == 0x9fc, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5a.ApiSetSchemaSize) == 0xa00, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5a.ApiSetSchemaExtensions) == 0xa04, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5b.AcpiBiosVersion) == 0xa0c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5b.SmbiosVersion) == 0xa14, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5b.EfiVersion) == 0xa1c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.KdDebugDevice) == 0xa24, "LOADER_PARAMETER_EXTENSION_WIN10_2004 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.OfflineCrashdumpConfigurationTable) == 0xa28, "LOADER_PARAMETER_EXTENSION_WIN10_2004 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.ManufacturingProfile) == 0xa48, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.BbtBuffer) == 0xa50, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.XsaveAllowedFeatures) == 0xa58, "LOADER_PARAMETER_EXTENSION_WIN10_2004 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.XsaveFlags) == 0xa60, "LOADER_PARAMETER_EXTENSION_WIN10_2004 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.BootOptions) == 0xa64, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, IumEnablement) == 0xa68, "LOADER_PARAMETER_EXTENSION_WIN10_2004 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, IumPolicy) == 0xa6c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, IumStatus) == 0xa70, "LOADER_PARAMETER_EXTENSION_WIN10_2004 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, BootId) == 0xa74, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, CodeIntegrityData) == 0xa78, "LOADER_PARAMETER_EXTENSION_WIN10_2004 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, CodeIntegrityDataSize) == 0xa7c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, SystemHiveRecoveryInfo) == 0xa80, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, SoftRestartCount) == 0xa94, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, SoftRestartTime) == 0xa98, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, LeapSecondData) == 0xaa0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 LeapSecondData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, MajorRelease) == 0xaa4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Reserved1) == 0xaa8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 Reserved1");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, NtBuildLab) == 0xaac, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NtBuildLab");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, NtBuildLabEx) == 0xb8c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NtBuildLabEx");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, ResetReason) == 0xc70, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ResetReason");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, MaxPciBusNumber) == 0xca0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 MaxPciBusNumber");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, FeatureSettings) == 0xca4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 FeatureSettings");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, HotPatchReserveSize) == 0xca8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HotPatchReserveSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, RetpolineReserveSize) == 0xcac, "LOADER_PARAMETER_EXTENSION_WIN10_2004 RetpolineReserveSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, VsmPerformanceData) == 0xcb0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 VsmPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, NumaMemoryRanges) == 0xcf0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NumaMemoryRanges");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, NumaMemoryRangeCount) == 0xcf4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NumaMemoryRangeCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, IommuFaultPolicy) == 0xcf8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 IommuFaultPolicy");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_EXTENSION_WIN10_2004) == 0xdf0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Size) == 0x0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 Size");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Profile) == 0x4, "LOADER_PARAMETER_EXTENSION_WIN10_2004 Profile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1a.EmInfFileImage) == 0x18, "LOADER_PARAMETER_EXTENSION_WIN10_2004 EmInfFileImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1a.EmInfFileSize) == 0x20, "LOADER_PARAMETER_EXTENSION_WIN10_2004 EmInfFileSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1a.TriageDumpBlock) == 0x28, "LOADER_PARAMETER_EXTENSION_WIN10_2004 TriageDumpBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1b.HeadlessLoaderBlock) == 0x30, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HeadlessLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1b.SMBiosEPSHeader) == 0x38, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SMBiosEPSHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1b.DrvDBImage) == 0x40, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DrvDBImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1b.DrvDBSize) == 0x48, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DrvDBSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, DrvDBPatchImage) == 0x50, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DrvDBPatchImage");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, DrvDBPatchSize) == 0x58, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DrvDBPatchSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.NetworkLoaderBlock) == 0x60, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NetworkLoaderBlock");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.FirmwareDescriptorListHead) == 0x68, "LOADER_PARAMETER_EXTENSION_WIN10_2004 FirmwareDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.AcpiTable) == 0x78, "LOADER_PARAMETER_EXTENSION_WIN10_2004 AcpiTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block1c.AcpiTableSize) == 0x80, "LOADER_PARAMETER_EXTENSION_WIN10_2004 AcpiTableSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, LoaderPerformanceData) == 0x88, "LOADER_PARAMETER_EXTENSION_WIN10_2004 LoaderPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block2b.BootApplicationPersistentData) == 0xe8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootApplicationPersistentData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block2b.WmdTestResult) == 0xf8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 WmdTestResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block2b.BootIdentifier) == 0x100, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootIdentifier");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, ResumePages) == 0x110, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ResumePages");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, DumpHeader) == 0x118, "LOADER_PARAMETER_EXTENSION_WIN10_2004 DumpHeader");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.BgContext) == 0x120, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BgContext");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.NumaLocalityInfo) == 0x128, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NumaLocalityInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.NumaGroupAssignment) == 0x130, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NumaGroupAssignment");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.AttachedHives) == 0x138, "LOADER_PARAMETER_EXTENSION_WIN10_2004 AttachedHives");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.MemoryCachingRequirementsCount) == 0x148, "LOADER_PARAMETER_EXTENSION_WIN10_2004 MemoryCachingRequirementsCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block3.MemoryCachingRequirements) == 0x150, "LOADER_PARAMETER_EXTENSION_WIN10_2004 MemoryCachingRequirements");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, BootEntropyResult) == 0x158, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootEntropyResult");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, ProcessorCounterFrequency) == 0x9c0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ProcessorCounterFrequency");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, HypervisorExtension) == 0x9c8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HypervisorExtension");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.HardwareConfigurationId) == 0xa08, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HardwareConfigurationId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.HalExtensionModuleList) == 0xa18, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HalExtensionModuleList");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.SystemTime) == 0xa28, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SystemTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.TimeStampAtSystemTimeRead) == 0xa30, "LOADER_PARAMETER_EXTENSION_WIN10_2004 TimeStampAtSystemTimeRead");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.BootFlags) == 0xa38, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.InternalBootFlags) == 0xa40, "LOADER_PARAMETER_EXTENSION_WIN10_2004 InternalBootFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.WfsFPData) == 0xa48, "LOADER_PARAMETER_EXTENSION_WIN10_2004 WfsFPData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block4.WfsFPDataSize) == 0xa50, "LOADER_PARAMETER_EXTENSION_WIN10_2004 WfsFPDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5a.BugcheckParameters) == 0xa58, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BugcheckParameters");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5a.ApiSetSchema) == 0xa80, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ApiSetSchema");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5a.ApiSetSchemaSize) == 0xa88, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ApiSetSchemaSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5a.ApiSetSchemaExtensions) == 0xa90, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ApiSetSchemaExtensions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5b.AcpiBiosVersion) == 0xaa0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 AcpiBiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5b.SmbiosVersion) == 0xab0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SmbiosVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block5b.EfiVersion) == 0xac0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 EfiVersion");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.KdDebugDevice) == 0xad0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 KdDebugDevice");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.OfflineCrashdumpConfigurationTable) == 0xad8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 OfflineCrashdumpConfigurationTable");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.ManufacturingProfile) == 0xaf8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ManufacturingProfile");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.BbtBuffer) == 0xb08, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BbtBuffer");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.XsaveAllowedFeatures) == 0xb10, "LOADER_PARAMETER_EXTENSION_WIN10_2004 XsaveAllowedFeatures");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.XsaveFlags) == 0xb18, "LOADER_PARAMETER_EXTENSION_WIN10_2004 XsaveFlags");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Block6.BootOptions) == 0xb20, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootOptions");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, IumEnablement) == 0xb28, "LOADER_PARAMETER_EXTENSION_WIN10_2004 IumEnablement");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, IumPolicy) == 0xb2c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 IumPolicy");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, IumStatus) == 0xb30, "LOADER_PARAMETER_EXTENSION_WIN10_2004 IumStatus");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, BootId) == 0xb34, "LOADER_PARAMETER_EXTENSION_WIN10_2004 BootId");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, CodeIntegrityData) == 0xb38, "LOADER_PARAMETER_EXTENSION_WIN10_2004 CodeIntegrityData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, CodeIntegrityDataSize) == 0xb40, "LOADER_PARAMETER_EXTENSION_WIN10_2004 CodeIntegrityDataSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, SystemHiveRecoveryInfo) == 0xb44, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SystemHiveRecoveryInfo");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, SoftRestartCount) == 0xb58, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SoftRestartCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, SoftRestartTime) == 0xb60, "LOADER_PARAMETER_EXTENSION_WIN10_2004 SoftRestartTime");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, HypercallCodeVa) == 0xb68, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HypercallCodeVa");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, HalVirtualAddress) == 0xb70, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HalVirtualAddress");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, HalNumberOfBytes) == 0xb78, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HalNumberOfBytes");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, LeapSecondData) == 0xb80, "LOADER_PARAMETER_EXTENSION_WIN10_2004 LeapSecondData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, MajorRelease) == 0xb88, "LOADER_PARAMETER_EXTENSION_WIN10_2004 MajorRelease");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, Reserved1) == 0xb8c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 Reserved1");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, NtBuildLab) == 0xb90, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NtBuildLab");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, NtBuildLabEx) == 0xc70, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NtBuildLabEx");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, ResetReason) == 0xd50, "LOADER_PARAMETER_EXTENSION_WIN10_2004 ResetReason");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, MaxPciBusNumber) == 0xd80, "LOADER_PARAMETER_EXTENSION_WIN10_2004 MaxPciBusNumber");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, FeatureSettings) == 0xd84, "LOADER_PARAMETER_EXTENSION_WIN10_2004 FeatureSettings");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, HotPatchReserveSize) == 0xd88, "LOADER_PARAMETER_EXTENSION_WIN10_2004 HotPatchReserveSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, RetpolineReserveSize) == 0xd8c, "LOADER_PARAMETER_EXTENSION_WIN10_2004 RetpolineReserveSize");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, MiniExecutive) == 0xd90, "LOADER_PARAMETER_EXTENSION_WIN10_2004 MiniExecutive");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, VsmPerformanceData) == 0xda0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 VsmPerformanceData");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, NumaMemoryRanges) == 0xde0, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NumaMemoryRanges");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, NumaMemoryRangeCount) == 0xde8, "LOADER_PARAMETER_EXTENSION_WIN10_2004 NumaMemoryRangeCount");
static_assert(offsetof(LOADER_PARAMETER_EXTENSION_WIN10_2004, IommuFaultPolicy) == 0xdec, "LOADER_PARAMETER_EXTENSION_WIN10_2004 IommuFaultPolicy");
#endif

typedef struct {
    void* CommonDataArea;
    uint32_t MachineType;
    uint32_t VirtualBias;
} I386_LOADER_BLOCK;

typedef struct _SETUP_LOADER_BLOCK SETUP_LOADER_BLOCK;

typedef struct {
    LIST_ENTRY LoadOrderListHead;
    LIST_ENTRY MemoryDescriptorListHead;
    LIST_ENTRY BootDriverListHead;
} LOADER_BLOCK1A;

typedef struct {
    void* KernelStack;
    void* Prcb;
    void* Process;
    void* Thread;
} LOADER_BLOCK1B;

typedef struct {
    CONFIGURATION_COMPONENT_DATA* ConfigurationRoot;
    char* ArcBootDeviceName;
    char* ArcHalDeviceName;
    char* NtBootPathName;
    char* NtHalPathName;
    char* LoadOptions;
    NLS_DATA_BLOCK* NlsData;
    ARC_DISK_INFORMATION* ArcDiskInformation;
} LOADER_BLOCK1C;

typedef struct {
    void* Extension;
    union {
        I386_LOADER_BLOCK I386;
    } u;
} LOADER_BLOCK2;

typedef struct {
    LOADER_BLOCK1A Block1a;
    LOADER_BLOCK1B Block1b;
    uint32_t RegistryLength;
    void* RegistryBase;
    LOADER_BLOCK1C Block1c;
    void* OemFontFile;
    SETUP_LOADER_BLOCK* SetupLdrBlock;
    LOADER_BLOCK2 Block2;
} LOADER_PARAMETER_BLOCK_WS03;

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WS03) == 0x68, "LOADER_PARAMETER_BLOCK_WS03 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1a.LoadOrderListHead) == 0x0, "LOADER_PARAMETER_BLOCK_WS03 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1a.MemoryDescriptorListHead) == 0x8, "LOADER_PARAMETER_BLOCK_WS03 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1a.BootDriverListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WS03 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1b.KernelStack) == 0x18, "LOADER_PARAMETER_BLOCK_WS03 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1b.Prcb) == 0x1c, "LOADER_PARAMETER_BLOCK_WS03 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1b.Process) == 0x20, "LOADER_PARAMETER_BLOCK_WS03 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1b.Thread) == 0x24, "LOADER_PARAMETER_BLOCK_WS03 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, RegistryLength) == 0x28, "LOADER_PARAMETER_BLOCK_WS03 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, RegistryBase) == 0x2c, "LOADER_PARAMETER_BLOCK_WS03 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.ConfigurationRoot) == 0x30, "LOADER_PARAMETER_BLOCK_WS03 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.ArcBootDeviceName) == 0x34, "LOADER_PARAMETER_BLOCK_WS03 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.ArcHalDeviceName) == 0x38, "LOADER_PARAMETER_BLOCK_WS03 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.NtBootPathName) == 0x3c, "LOADER_PARAMETER_BLOCK_WS03 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.NtHalPathName) == 0x40, "LOADER_PARAMETER_BLOCK_WS03 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.LoadOptions) == 0x44, "LOADER_PARAMETER_BLOCK_WS03 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.NlsData) == 0x48, "LOADER_PARAMETER_BLOCK_WS03 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.ArcDiskInformation) == 0x4c, "LOADER_PARAMETER_BLOCK_WS03 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, OemFontFile) == 0x50, "LOADER_PARAMETER_BLOCK_WS03 OemFontFile");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, SetupLdrBlock) == 0x54, "LOADER_PARAMETER_BLOCK_WS03 SetupLdrBlock");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block2.Extension) == 0x58, "LOADER_PARAMETER_BLOCK_WS03 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block2.u.I386) == 0x5c, "LOADER_PARAMETER_BLOCK_WS03 I386");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WS03) == 0xc8, "LOADER_PARAMETER_BLOCK_WS03 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1a.LoadOrderListHead) == 0x0, "LOADER_PARAMETER_BLOCK_WS03 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1a.MemoryDescriptorListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WS03 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1a.BootDriverListHead) == 0x20, "LOADER_PARAMETER_BLOCK_WS03 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1b.KernelStack) == 0x30, "LOADER_PARAMETER_BLOCK_WS03 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1b.Prcb) == 0x38, "LOADER_PARAMETER_BLOCK_WS03 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1b.Process) == 0x40, "LOADER_PARAMETER_BLOCK_WS03 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1b.Thread) == 0x48, "LOADER_PARAMETER_BLOCK_WS03 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, RegistryLength) == 0x50, "LOADER_PARAMETER_BLOCK_WS03 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, RegistryBase) == 0x58, "LOADER_PARAMETER_BLOCK_WS03 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.ConfigurationRoot) == 0x60, "LOADER_PARAMETER_BLOCK_WS03 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.ArcBootDeviceName) == 0x68, "LOADER_PARAMETER_BLOCK_WS03 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.ArcHalDeviceName) == 0x70, "LOADER_PARAMETER_BLOCK_WS03 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.NtBootPathName) == 0x78, "LOADER_PARAMETER_BLOCK_WS03 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.NtHalPathName) == 0x80, "LOADER_PARAMETER_BLOCK_WS03 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.LoadOptions) == 0x88, "LOADER_PARAMETER_BLOCK_WS03 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.NlsData) == 0x90, "LOADER_PARAMETER_BLOCK_WS03 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block1c.ArcDiskInformation) == 0x98, "LOADER_PARAMETER_BLOCK_WS03 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, OemFontFile) == 0xa0, "LOADER_PARAMETER_BLOCK_WS03 OemFontFile");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, SetupLdrBlock) == 0xa8, "LOADER_PARAMETER_BLOCK_WS03 SetupLdrBlock");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block2.Extension) == 0xb0, "LOADER_PARAMETER_BLOCK_WS03 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WS03, Block2.u.I386) == 0xb8, "LOADER_PARAMETER_BLOCK_WS03 I386");
#endif

typedef struct {
    uint32_t FirmwareVersion;
    void* VirtualEfiRuntimeServices;
    uint32_t SetVirtualAddressMapStatus;
    uint32_t MissedMappingsCount;
} EFI_FIRMWARE_INFORMATION_WIN7;

typedef struct {
    uint32_t FirmwareVersion;
    void* VirtualEfiRuntimeServices;
    uint32_t SetVirtualAddressMapStatus;
    uint32_t MissedMappingsCount;
    LIST_ENTRY FirmwareResourceList;
} EFI_FIRMWARE_INFORMATION_WIN8;

typedef struct {
    uint32_t PlaceHolder;
} PCAT_FIRMWARE_INFORMATION;

typedef struct {
    uint32_t FirmwareTypeEfi:1;
    uint32_t Reserved:31;
    union {
        EFI_FIRMWARE_INFORMATION_WIN7 EfiInformation;
        PCAT_FIRMWARE_INFORMATION PcatInformation;
    };
} FIRMWARE_INFORMATION_LOADER_BLOCK_WIN7;

typedef struct {
    uint32_t FirmwareTypeEfi:1;
    uint32_t Reserved:31;
    union {
        EFI_FIRMWARE_INFORMATION_WIN8 EfiInformation;
        PCAT_FIRMWARE_INFORMATION PcatInformation;
    };
} FIRMWARE_INFORMATION_LOADER_BLOCK_WIN8;

typedef struct {
    LOADER_BLOCK1A Block1a;
    LOADER_BLOCK1B Block1b;
    uint32_t RegistryLength;
    void* RegistryBase;
    LOADER_BLOCK1C Block1c;
    void* OemFontFile;
    SETUP_LOADER_BLOCK* SetupLdrBlock;
    LOADER_BLOCK2 Block2;
    FIRMWARE_INFORMATION_LOADER_BLOCK_WIN7 FirmwareInformation;
} LOADER_PARAMETER_BLOCK_VISTA;

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_BLOCK_VISTA) == 0x7c, "LOADER_PARAMETER_BLOCK_VISTA has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1a.LoadOrderListHead) == 0x0, "LOADER_PARAMETER_BLOCK_VISTA LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1a.MemoryDescriptorListHead) == 0x8, "LOADER_PARAMETER_BLOCK_VISTA MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1a.BootDriverListHead) == 0x10, "LOADER_PARAMETER_BLOCK_VISTA BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1b.KernelStack) == 0x18, "LOADER_PARAMETER_BLOCK_VISTA KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1b.Prcb) == 0x1c, "LOADER_PARAMETER_BLOCK_VISTA Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1b.Process) == 0x20, "LOADER_PARAMETER_BLOCK_VISTA Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1b.Thread) == 0x24, "LOADER_PARAMETER_BLOCK_VISTA Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, RegistryLength) == 0x28, "LOADER_PARAMETER_BLOCK_VISTA RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, RegistryBase) == 0x2c, "LOADER_PARAMETER_BLOCK_VISTA RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.ConfigurationRoot) == 0x30, "LOADER_PARAMETER_BLOCK_VISTA ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.ArcBootDeviceName) == 0x34, "LOADER_PARAMETER_BLOCK_VISTA ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.ArcHalDeviceName) == 0x38, "LOADER_PARAMETER_BLOCK_VISTA ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.NtBootPathName) == 0x3c, "LOADER_PARAMETER_BLOCK_VISTA NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.NtHalPathName) == 0x40, "LOADER_PARAMETER_BLOCK_VISTA NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.LoadOptions) == 0x44, "LOADER_PARAMETER_BLOCK_VISTA LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.NlsData) == 0x48, "LOADER_PARAMETER_BLOCK_VISTA NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.ArcDiskInformation) == 0x4c, "LOADER_PARAMETER_BLOCK_VISTA ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, OemFontFile) == 0x50, "LOADER_PARAMETER_BLOCK_VISTA OemFontFile");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, SetupLdrBlock) == 0x54, "LOADER_PARAMETER_BLOCK_VISTA SetupLdrBlock");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block2.Extension) == 0x58, "LOADER_PARAMETER_BLOCK_VISTA Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block2.u.I386) == 0x5c, "LOADER_PARAMETER_BLOCK_VISTA I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, FirmwareInformation) == 0x68, "LOADER_PARAMETER_BLOCK_VISTA FirmwareInformation");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_BLOCK_VISTA) == 0xe8, "LOADER_PARAMETER_BLOCK_VISTA has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1a.LoadOrderListHead) == 0x0, "LOADER_PARAMETER_BLOCK_VISTA LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1a.MemoryDescriptorListHead) == 0x10, "LOADER_PARAMETER_BLOCK_VISTA MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1a.BootDriverListHead) == 0x20, "LOADER_PARAMETER_BLOCK_VISTA BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1b.KernelStack) == 0x30, "LOADER_PARAMETER_BLOCK_VISTA KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1b.Prcb) == 0x38, "LOADER_PARAMETER_BLOCK_VISTA Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1b.Process) == 0x40, "LOADER_PARAMETER_BLOCK_VISTA Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1b.Thread) == 0x48, "LOADER_PARAMETER_BLOCK_VISTA Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, RegistryLength) == 0x50, "LOADER_PARAMETER_BLOCK_VISTA RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, RegistryBase) == 0x58, "LOADER_PARAMETER_BLOCK_VISTA RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.ConfigurationRoot) == 0x60, "LOADER_PARAMETER_BLOCK_VISTA ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.ArcBootDeviceName) == 0x68, "LOADER_PARAMETER_BLOCK_VISTA ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.ArcHalDeviceName) == 0x70, "LOADER_PARAMETER_BLOCK_VISTA ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.NtBootPathName) == 0x78, "LOADER_PARAMETER_BLOCK_VISTA NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.NtHalPathName) == 0x80, "LOADER_PARAMETER_BLOCK_VISTA NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.LoadOptions) == 0x88, "LOADER_PARAMETER_BLOCK_VISTA LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.NlsData) == 0x90, "LOADER_PARAMETER_BLOCK_VISTA NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block1c.ArcDiskInformation) == 0x98, "LOADER_PARAMETER_BLOCK_VISTA ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, OemFontFile) == 0xa0, "LOADER_PARAMETER_BLOCK_VISTA OemFontFile");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, SetupLdrBlock) == 0xa8, "LOADER_PARAMETER_BLOCK_VISTA SetupLdrBlock");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block2.Extension) == 0xb0, "LOADER_PARAMETER_BLOCK_VISTA Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, Block2.u.I386) == 0xb8, "LOADER_PARAMETER_BLOCK_VISTA I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_VISTA, FirmwareInformation) == 0xc8, "LOADER_PARAMETER_BLOCK_VISTA FirmwareInformation");
#endif

typedef struct {
    uint32_t OsMajorVersion;
    uint32_t OsMinorVersion;
    uint32_t Size;
    uint32_t Reserved;
    LOADER_BLOCK1A Block1a;
    LOADER_BLOCK1B Block1b;
    uint32_t RegistryLength;
    void* RegistryBase;
    LOADER_BLOCK1C Block1c;
    void* OemFontFile;
    LOADER_BLOCK2 Block2;
    FIRMWARE_INFORMATION_LOADER_BLOCK_WIN7 FirmwareInformation;
} LOADER_PARAMETER_BLOCK_WIN7;

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WIN7) == 0x88, "LOADER_PARAMETER_BLOCK_WIN7 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, OsMajorVersion) == 0x0, "LOADER_PARAMETER_BLOCK_WIN7 OsMajorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, OsMinorVersion) == 0x4, "LOADER_PARAMETER_BLOCK_WIN7 OsMinorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Size) == 0x8, "LOADER_PARAMETER_BLOCK_WIN7 Size");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Reserved) == 0xc, "LOADER_PARAMETER_BLOCK_WIN7 Reserved");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1a.LoadOrderListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WIN7 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1a.MemoryDescriptorListHead) == 0x18, "LOADER_PARAMETER_BLOCK_WIN7 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1a.BootDriverListHead) == 0x20, "LOADER_PARAMETER_BLOCK_WIN7 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1b.KernelStack) == 0x28, "LOADER_PARAMETER_BLOCK_WIN7 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1b.Prcb) == 0x2c, "LOADER_PARAMETER_BLOCK_WIN7 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1b.Process) == 0x30, "LOADER_PARAMETER_BLOCK_WIN7 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1b.Thread) == 0x34, "LOADER_PARAMETER_BLOCK_WIN7 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, RegistryLength) == 0x38, "LOADER_PARAMETER_BLOCK_WIN7 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, RegistryBase) == 0x3c, "LOADER_PARAMETER_BLOCK_WIN7 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.ConfigurationRoot) == 0x40, "LOADER_PARAMETER_BLOCK_WIN7 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.ArcBootDeviceName) == 0x44, "LOADER_PARAMETER_BLOCK_WIN7 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.ArcHalDeviceName) == 0x48, "LOADER_PARAMETER_BLOCK_WIN7 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.NtBootPathName) == 0x4c, "LOADER_PARAMETER_BLOCK_WIN7 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.NtHalPathName) == 0x50, "LOADER_PARAMETER_BLOCK_WIN7 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.LoadOptions) == 0x54, "LOADER_PARAMETER_BLOCK_WIN7 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.NlsData) == 0x58, "LOADER_PARAMETER_BLOCK_WIN7 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.ArcDiskInformation) == 0x5c, "LOADER_PARAMETER_BLOCK_WIN7 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, OemFontFile) == 0x60, "LOADER_PARAMETER_BLOCK_WIN7 OemFontFile");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block2.Extension) == 0x64, "LOADER_PARAMETER_BLOCK_WIN7 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block2.u.I386) == 0x68, "LOADER_PARAMETER_BLOCK_WIN7 I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, FirmwareInformation) == 0x74, "LOADER_PARAMETER_BLOCK_WIN7 FirmwareInformation");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WIN7) == 0xf0, "LOADER_PARAMETER_BLOCK_WIN7 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, OsMajorVersion) == 0x0, "LOADER_PARAMETER_BLOCK_WIN7 OsMajorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, OsMinorVersion) == 0x4, "LOADER_PARAMETER_BLOCK_WIN7 OsMinorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Size) == 0x8, "LOADER_PARAMETER_BLOCK_WIN7 Size");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Reserved) == 0xc, "LOADER_PARAMETER_BLOCK_WIN7 Reserved");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1a.LoadOrderListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WIN7 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1a.MemoryDescriptorListHead) == 0x20, "LOADER_PARAMETER_BLOCK_WIN7 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1a.BootDriverListHead) == 0x30, "LOADER_PARAMETER_BLOCK_WIN7 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1b.KernelStack) == 0x40, "LOADER_PARAMETER_BLOCK_WIN7 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1b.Prcb) == 0x48, "LOADER_PARAMETER_BLOCK_WIN7 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1b.Process) == 0x50, "LOADER_PARAMETER_BLOCK_WIN7 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1b.Thread) == 0x58, "LOADER_PARAMETER_BLOCK_WIN7 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, RegistryLength) == 0x60, "LOADER_PARAMETER_BLOCK_WIN7 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, RegistryBase) == 0x68, "LOADER_PARAMETER_BLOCK_WIN7 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.ConfigurationRoot) == 0x70, "LOADER_PARAMETER_BLOCK_WIN7 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.ArcBootDeviceName) == 0x78, "LOADER_PARAMETER_BLOCK_WIN7 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.ArcHalDeviceName) == 0x80, "LOADER_PARAMETER_BLOCK_WIN7 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.NtBootPathName) == 0x88, "LOADER_PARAMETER_BLOCK_WIN7 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.NtHalPathName) == 0x90, "LOADER_PARAMETER_BLOCK_WIN7 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.LoadOptions) == 0x98, "LOADER_PARAMETER_BLOCK_WIN7 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.NlsData) == 0xa0, "LOADER_PARAMETER_BLOCK_WIN7 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block1c.ArcDiskInformation) == 0xa8, "LOADER_PARAMETER_BLOCK_WIN7 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, OemFontFile) == 0xb0, "LOADER_PARAMETER_BLOCK_WIN7 OemFontFile");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block2.Extension) == 0xb8, "LOADER_PARAMETER_BLOCK_WIN7 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, Block2.u.I386) == 0xc0, "LOADER_PARAMETER_BLOCK_WIN7 I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN7, FirmwareInformation) == 0xd0, "LOADER_PARAMETER_BLOCK_WIN7 FirmwareInformation");
#endif

#pragma pack(push,4)

typedef struct {
    uint32_t OsMajorVersion;
    uint32_t OsMinorVersion;
    uint32_t Size;
    uint32_t Reserved;
    LOADER_BLOCK1A Block1a;
    LIST_ENTRY EarlyLaunchListHead;
    LIST_ENTRY CoreDriverListHead;
    LOADER_BLOCK1B Block1b;
    uint32_t KernelStackSize;
    uint32_t RegistryLength;
    void* RegistryBase;
    LOADER_BLOCK1C Block1c;
    LOADER_BLOCK2 Block2;
    FIRMWARE_INFORMATION_LOADER_BLOCK_WIN8 FirmwareInformation;
} LOADER_PARAMETER_BLOCK_WIN8;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WIN8) == 0xa0, "LOADER_PARAMETER_BLOCK_WIN8 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, OsMajorVersion) == 0x0, "LOADER_PARAMETER_BLOCK_WIN8 OsMajorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, OsMinorVersion) == 0x4, "LOADER_PARAMETER_BLOCK_WIN8 OsMinorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Size) == 0x8, "LOADER_PARAMETER_BLOCK_WIN8 Size");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Reserved) == 0xc, "LOADER_PARAMETER_BLOCK_WIN8 Reserved");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1a.LoadOrderListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WIN8 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1a.MemoryDescriptorListHead) == 0x18, "LOADER_PARAMETER_BLOCK_WIN8 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1a.BootDriverListHead) == 0x20, "LOADER_PARAMETER_BLOCK_WIN8 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, EarlyLaunchListHead) == 0x28, "LOADER_PARAMETER_BLOCK_WIN8 EarlyLaunchListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, CoreDriverListHead) == 0x30, "LOADER_PARAMETER_BLOCK_WIN8 CoreDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1b.KernelStack) == 0x38, "LOADER_PARAMETER_BLOCK_WIN8 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1b.Prcb) == 0x3c, "LOADER_PARAMETER_BLOCK_WIN8 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1b.Process) == 0x40, "LOADER_PARAMETER_BLOCK_WIN8 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1b.Thread) == 0x44, "LOADER_PARAMETER_BLOCK_WIN8 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, KernelStackSize) == 0x48, "LOADER_PARAMETER_BLOCK_WIN8 KernelStackSize");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, RegistryLength) == 0x4c, "LOADER_PARAMETER_BLOCK_WIN8 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, RegistryBase) == 0x50, "LOADER_PARAMETER_BLOCK_WIN8 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.ConfigurationRoot) == 0x54, "LOADER_PARAMETER_BLOCK_WIN8 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.ArcBootDeviceName) == 0x58, "LOADER_PARAMETER_BLOCK_WIN8 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.ArcHalDeviceName) == 0x5c, "LOADER_PARAMETER_BLOCK_WIN8 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.NtBootPathName) == 0x60, "LOADER_PARAMETER_BLOCK_WIN8 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.NtHalPathName) == 0x64, "LOADER_PARAMETER_BLOCK_WIN8 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.LoadOptions) == 0x68, "LOADER_PARAMETER_BLOCK_WIN8 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.NlsData) == 0x6c, "LOADER_PARAMETER_BLOCK_WIN8 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.ArcDiskInformation) == 0x70, "LOADER_PARAMETER_BLOCK_WIN8 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block2.Extension) == 0x74, "LOADER_PARAMETER_BLOCK_WIN8 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block2.u.I386) == 0x78, "LOADER_PARAMETER_BLOCK_WIN8 I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, FirmwareInformation) == 0x84, "LOADER_PARAMETER_BLOCK_WIN8 FirmwareInformation");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WIN8) == 0x118, "LOADER_PARAMETER_BLOCK_WIN8 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, OsMajorVersion) == 0x0, "LOADER_PARAMETER_BLOCK_WIN8 OsMajorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, OsMinorVersion) == 0x4, "LOADER_PARAMETER_BLOCK_WIN8 OsMinorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Size) == 0x8, "LOADER_PARAMETER_BLOCK_WIN8 Size");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Reserved) == 0xc, "LOADER_PARAMETER_BLOCK_WIN8 Reserved");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1a.LoadOrderListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WIN8 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1a.MemoryDescriptorListHead) == 0x20, "LOADER_PARAMETER_BLOCK_WIN8 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1a.BootDriverListHead) == 0x30, "LOADER_PARAMETER_BLOCK_WIN8 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, EarlyLaunchListHead) == 0x40, "LOADER_PARAMETER_BLOCK_WIN8 EarlyLaunchListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, CoreDriverListHead) == 0x50, "LOADER_PARAMETER_BLOCK_WIN8 CoreDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1b.KernelStack) == 0x60, "LOADER_PARAMETER_BLOCK_WIN8 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1b.Prcb) == 0x68, "LOADER_PARAMETER_BLOCK_WIN8 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1b.Process) == 0x70, "LOADER_PARAMETER_BLOCK_WIN8 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1b.Thread) == 0x78, "LOADER_PARAMETER_BLOCK_WIN8 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, KernelStackSize) == 0x80, "LOADER_PARAMETER_BLOCK_WIN8 KernelStackSize");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, RegistryLength) == 0x84, "LOADER_PARAMETER_BLOCK_WIN8 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, RegistryBase) == 0x88, "LOADER_PARAMETER_BLOCK_WIN8 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.ConfigurationRoot) == 0x90, "LOADER_PARAMETER_BLOCK_WIN8 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.ArcBootDeviceName) == 0x98, "LOADER_PARAMETER_BLOCK_WIN8 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.ArcHalDeviceName) == 0xa0, "LOADER_PARAMETER_BLOCK_WIN8 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.NtBootPathName) == 0xa8, "LOADER_PARAMETER_BLOCK_WIN8 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.NtHalPathName) == 0xb0, "LOADER_PARAMETER_BLOCK_WIN8 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.LoadOptions) == 0xb8, "LOADER_PARAMETER_BLOCK_WIN8 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.NlsData) == 0xc0, "LOADER_PARAMETER_BLOCK_WIN8 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block1c.ArcDiskInformation) == 0xc8, "LOADER_PARAMETER_BLOCK_WIN8 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block2.Extension) == 0xd0, "LOADER_PARAMETER_BLOCK_WIN8 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, Block2.u.I386) == 0xd8, "LOADER_PARAMETER_BLOCK_WIN8 I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN8, FirmwareInformation) == 0xe8, "LOADER_PARAMETER_BLOCK_WIN8 FirmwareInformation");
#endif

typedef struct {
    uint32_t FirmwareVersion;
    void* VirtualEfiRuntimeServices;
    uint32_t SetVirtualAddressMapStatus;
    uint32_t MissedMappingsCount;
    LIST_ENTRY FirmwareResourceList;
    void* EfiMemoryMap;
    uint32_t EfiMemoryMapSize;
    uint32_t EfiMemoryMapDescriptorSize;
} EFI_FIRMWARE_INFORMATION_WIN81;

typedef struct {
    uint32_t FirmwareTypeEfi:1;
    uint32_t Reserved:31;
    union {
        EFI_FIRMWARE_INFORMATION_WIN81 EfiInformation;
        PCAT_FIRMWARE_INFORMATION PcatInformation;
    };
} FIRMWARE_INFORMATION_LOADER_BLOCK_WIN81;

#pragma pack(push,1)

typedef struct {
    uint32_t OsMajorVersion;
    uint32_t OsMinorVersion;
    uint32_t Size;
    uint32_t Reserved;
    LOADER_BLOCK1A Block1a;
    LIST_ENTRY EarlyLaunchListHead;
    LIST_ENTRY CoreDriverListHead;
    LOADER_BLOCK1B Block1b;
    uint32_t KernelStackSize;
    uint32_t RegistryLength;
    void* RegistryBase;
    LOADER_BLOCK1C Block1c;
    LOADER_BLOCK2 Block2;
    FIRMWARE_INFORMATION_LOADER_BLOCK_WIN81 FirmwareInformation;
} LOADER_PARAMETER_BLOCK_WIN81;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WIN81) == 0xac, "LOADER_PARAMETER_BLOCK_WIN81 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, OsMajorVersion) == 0x0, "LOADER_PARAMETER_BLOCK_WIN81 OsMajorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, OsMinorVersion) == 0x4, "LOADER_PARAMETER_BLOCK_WIN81 OsMinorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Size) == 0x8, "LOADER_PARAMETER_BLOCK_WIN81 Size");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Reserved) == 0xc, "LOADER_PARAMETER_BLOCK_WIN81 Reserved");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1a.LoadOrderListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WIN81 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1a.MemoryDescriptorListHead) == 0x18, "LOADER_PARAMETER_BLOCK_WIN81 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1a.BootDriverListHead) == 0x20, "LOADER_PARAMETER_BLOCK_WIN81 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, EarlyLaunchListHead) == 0x28, "LOADER_PARAMETER_BLOCK_WIN81 EarlyLaunchListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, CoreDriverListHead) == 0x30, "LOADER_PARAMETER_BLOCK_WIN81 CoreDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1b.KernelStack) == 0x38, "LOADER_PARAMETER_BLOCK_WIN81 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1b.Prcb) == 0x3c, "LOADER_PARAMETER_BLOCK_WIN81 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1b.Process) == 0x40, "LOADER_PARAMETER_BLOCK_WIN81 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1b.Thread) == 0x44, "LOADER_PARAMETER_BLOCK_WIN81 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, KernelStackSize) == 0x48, "LOADER_PARAMETER_BLOCK_WIN81 KernelStackSize");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, RegistryLength) == 0x4c, "LOADER_PARAMETER_BLOCK_WIN81 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, RegistryBase) == 0x50, "LOADER_PARAMETER_BLOCK_WIN81 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.ConfigurationRoot) == 0x54, "LOADER_PARAMETER_BLOCK_WIN81 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.ArcBootDeviceName) == 0x58, "LOADER_PARAMETER_BLOCK_WIN81 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.ArcHalDeviceName) == 0x5c, "LOADER_PARAMETER_BLOCK_WIN81 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.NtBootPathName) == 0x60, "LOADER_PARAMETER_BLOCK_WIN81 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.NtHalPathName) == 0x64, "LOADER_PARAMETER_BLOCK_WIN81 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.LoadOptions) == 0x68, "LOADER_PARAMETER_BLOCK_WIN81 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.NlsData) == 0x6c, "LOADER_PARAMETER_BLOCK_WIN81 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.ArcDiskInformation) == 0x70, "LOADER_PARAMETER_BLOCK_WIN81 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block2.Extension) == 0x74, "LOADER_PARAMETER_BLOCK_WIN81 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block2.u.I386) == 0x78, "LOADER_PARAMETER_BLOCK_WIN81 I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, FirmwareInformation) == 0x84, "LOADER_PARAMETER_BLOCK_WIN81 FirmwareInformation");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WIN81) == 0x128, "LOADER_PARAMETER_BLOCK_WIN81 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, OsMajorVersion) == 0x0, "LOADER_PARAMETER_BLOCK_WIN81 OsMajorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, OsMinorVersion) == 0x4, "LOADER_PARAMETER_BLOCK_WIN81 OsMinorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Size) == 0x8, "LOADER_PARAMETER_BLOCK_WIN81 Size");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Reserved) == 0xc, "LOADER_PARAMETER_BLOCK_WIN81 Reserved");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1a.LoadOrderListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WIN81 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1a.MemoryDescriptorListHead) == 0x20, "LOADER_PARAMETER_BLOCK_WIN81 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1a.BootDriverListHead) == 0x30, "LOADER_PARAMETER_BLOCK_WIN81 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, EarlyLaunchListHead) == 0x40, "LOADER_PARAMETER_BLOCK_WIN81 EarlyLaunchListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, CoreDriverListHead) == 0x50, "LOADER_PARAMETER_BLOCK_WIN81 CoreDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1b.KernelStack) == 0x60, "LOADER_PARAMETER_BLOCK_WIN81 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1b.Prcb) == 0x68, "LOADER_PARAMETER_BLOCK_WIN81 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1b.Process) == 0x70, "LOADER_PARAMETER_BLOCK_WIN81 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1b.Thread) == 0x78, "LOADER_PARAMETER_BLOCK_WIN81 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, KernelStackSize) == 0x80, "LOADER_PARAMETER_BLOCK_WIN81 KernelStackSize");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, RegistryLength) == 0x84, "LOADER_PARAMETER_BLOCK_WIN81 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, RegistryBase) == 0x88, "LOADER_PARAMETER_BLOCK_WIN81 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.ConfigurationRoot) == 0x90, "LOADER_PARAMETER_BLOCK_WIN81 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.ArcBootDeviceName) == 0x98, "LOADER_PARAMETER_BLOCK_WIN81 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.ArcHalDeviceName) == 0xa0, "LOADER_PARAMETER_BLOCK_WIN81 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.NtBootPathName) == 0xa8, "LOADER_PARAMETER_BLOCK_WIN81 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.NtHalPathName) == 0xb0, "LOADER_PARAMETER_BLOCK_WIN81 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.LoadOptions) == 0xb8, "LOADER_PARAMETER_BLOCK_WIN81 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.NlsData) == 0xc0, "LOADER_PARAMETER_BLOCK_WIN81 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block1c.ArcDiskInformation) == 0xc8, "LOADER_PARAMETER_BLOCK_WIN81 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block2.Extension) == 0xd0, "LOADER_PARAMETER_BLOCK_WIN81 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, Block2.u.I386) == 0xd8, "LOADER_PARAMETER_BLOCK_WIN81 I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN81, FirmwareInformation) == 0xe8, "LOADER_PARAMETER_BLOCK_WIN81 FirmwareInformation");
#endif

#pragma pack(push,1)

typedef struct {
    uint32_t OsMajorVersion;
    uint32_t OsMinorVersion;
    uint32_t Size;
    uint32_t OsLoaderSecurityVersion;
    LOADER_BLOCK1A Block1a;
    LIST_ENTRY EarlyLaunchListHead;
    LIST_ENTRY CoreDriverListHead;
    LIST_ENTRY CoreExtensionsDriverListHead;
    LIST_ENTRY TpmCoreDriverListHead;
    LOADER_BLOCK1B Block1b;
    uint32_t KernelStackSize;
    uint32_t RegistryLength;
    void* RegistryBase;
    LOADER_BLOCK1C Block1c;
    LOADER_BLOCK2 Block2;
    FIRMWARE_INFORMATION_LOADER_BLOCK_WIN81 FirmwareInformation;
    char* OsBootstatPathName;
    char* ArcOSDataDeviceName;
    char* ArcWindowsSysPartName;
} LOADER_PARAMETER_BLOCK_WIN10;

#pragma pack(pop)

#ifdef _X86_
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WIN10) == 0xc8, "LOADER_PARAMETER_BLOCK_WIN10 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, OsMajorVersion) == 0x0, "LOADER_PARAMETER_BLOCK_WIN10 OsMajorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, OsMinorVersion) == 0x4, "LOADER_PARAMETER_BLOCK_WIN10 OsMinorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Size) == 0x8, "LOADER_PARAMETER_BLOCK_WIN10 Size");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, OsLoaderSecurityVersion) == 0xc, "LOADER_PARAMETER_BLOCK_WIN10 Reserved");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1a.LoadOrderListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WIN10 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1a.MemoryDescriptorListHead) == 0x18, "LOADER_PARAMETER_BLOCK_WIN10 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1a.BootDriverListHead) == 0x20, "LOADER_PARAMETER_BLOCK_WIN10 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, EarlyLaunchListHead) == 0x28, "LOADER_PARAMETER_BLOCK_WIN10 EarlyLaunchListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, CoreDriverListHead) == 0x30, "LOADER_PARAMETER_BLOCK_WIN10 CoreDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, CoreExtensionsDriverListHead) == 0x38, "LOADER_PARAMETER_BLOCK_WIN10 CoreExtensionsDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, TpmCoreDriverListHead) == 0x40, "LOADER_PARAMETER_BLOCK_WIN10 TpmCoreDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1b.KernelStack) == 0x48, "LOADER_PARAMETER_BLOCK_WIN10 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1b.Prcb) == 0x4c, "LOADER_PARAMETER_BLOCK_WIN10 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1b.Process) == 0x50, "LOADER_PARAMETER_BLOCK_WIN10 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1b.Thread) == 0x54, "LOADER_PARAMETER_BLOCK_WIN10 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, KernelStackSize) == 0x58, "LOADER_PARAMETER_BLOCK_WIN10 KernelStackSize");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, RegistryLength) == 0x5c, "LOADER_PARAMETER_BLOCK_WIN10 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, RegistryBase) == 0x60, "LOADER_PARAMETER_BLOCK_WIN10 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.ConfigurationRoot) == 0x64, "LOADER_PARAMETER_BLOCK_WIN10 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.ArcBootDeviceName) == 0x68, "LOADER_PARAMETER_BLOCK_WIN10 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.ArcHalDeviceName) == 0x6c, "LOADER_PARAMETER_BLOCK_WIN10 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.NtBootPathName) == 0x70, "LOADER_PARAMETER_BLOCK_WIN10 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.NtHalPathName) == 0x74, "LOADER_PARAMETER_BLOCK_WIN10 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.LoadOptions) == 0x78, "LOADER_PARAMETER_BLOCK_WIN10 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.NlsData) == 0x7c, "LOADER_PARAMETER_BLOCK_WIN10 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.ArcDiskInformation) == 0x80, "LOADER_PARAMETER_BLOCK_WIN10 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block2.Extension) == 0x84, "LOADER_PARAMETER_BLOCK_WIN10 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block2.u.I386) == 0x88, "LOADER_PARAMETER_BLOCK_WIN10 I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, FirmwareInformation) == 0x94, "LOADER_PARAMETER_BLOCK_WIN10 FirmwareInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, OsBootstatPathName) == 0xbc, "LOADER_PARAMETER_BLOCK_WIN10 OsBootstatPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, ArcOSDataDeviceName) == 0xc0, "LOADER_PARAMETER_BLOCK_WIN10 ArcOSDataDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, ArcWindowsSysPartName) == 0xc4, "LOADER_PARAMETER_BLOCK_WIN10 ArcWindowsSysPartName");
#elif defined(__x86_64__)
static_assert(sizeof(LOADER_PARAMETER_BLOCK_WIN10) == 0x160, "LOADER_PARAMETER_BLOCK_WIN10 has incorrect size.");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, OsMajorVersion) == 0x0, "LOADER_PARAMETER_BLOCK_WIN10 OsMajorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, OsMinorVersion) == 0x4, "LOADER_PARAMETER_BLOCK_WIN10 OsMinorVersion");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Size) == 0x8, "LOADER_PARAMETER_BLOCK_WIN10 Size");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, OsLoaderSecurityVersion) == 0xc, "LOADER_PARAMETER_BLOCK_WIN10 Reserved");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1a.LoadOrderListHead) == 0x10, "LOADER_PARAMETER_BLOCK_WIN10 LoadOrderListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1a.MemoryDescriptorListHead) == 0x20, "LOADER_PARAMETER_BLOCK_WIN10 MemoryDescriptorListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1a.BootDriverListHead) == 0x30, "LOADER_PARAMETER_BLOCK_WIN10 BootDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, EarlyLaunchListHead) == 0x40, "LOADER_PARAMETER_BLOCK_WIN10 EarlyLaunchListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, CoreDriverListHead) == 0x50, "LOADER_PARAMETER_BLOCK_WIN10 CoreDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, CoreExtensionsDriverListHead) == 0x60, "LOADER_PARAMETER_BLOCK_WIN10 CoreExtensionsDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, TpmCoreDriverListHead) == 0x70, "LOADER_PARAMETER_BLOCK_WIN10 TpmCoreDriverListHead");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1b.KernelStack) == 0x80, "LOADER_PARAMETER_BLOCK_WIN10 KernelStack");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1b.Prcb) == 0x88, "LOADER_PARAMETER_BLOCK_WIN10 Prcb");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1b.Process) == 0x90, "LOADER_PARAMETER_BLOCK_WIN10 Process");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1b.Thread) == 0x98, "LOADER_PARAMETER_BLOCK_WIN10 Thread");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, KernelStackSize) == 0xa0, "LOADER_PARAMETER_BLOCK_WIN10 KernelStackSize");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, RegistryLength) == 0xa4, "LOADER_PARAMETER_BLOCK_WIN10 RegistryLength");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, RegistryBase) == 0xa8, "LOADER_PARAMETER_BLOCK_WIN10 RegistryBase");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.ConfigurationRoot) == 0xb0, "LOADER_PARAMETER_BLOCK_WIN10 ConfigurationRoot");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.ArcBootDeviceName) == 0xb8, "LOADER_PARAMETER_BLOCK_WIN10 ArcBootDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.ArcHalDeviceName) == 0xc0, "LOADER_PARAMETER_BLOCK_WIN10 ArcHalDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.NtBootPathName) == 0xc8, "LOADER_PARAMETER_BLOCK_WIN10 NtBootPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.NtHalPathName) == 0xd0, "LOADER_PARAMETER_BLOCK_WIN10 NtHalPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.LoadOptions) == 0xd8, "LOADER_PARAMETER_BLOCK_WIN10 LoadOptions");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.NlsData) == 0xe0, "LOADER_PARAMETER_BLOCK_WIN10 NlsData");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block1c.ArcDiskInformation) == 0xe8, "LOADER_PARAMETER_BLOCK_WIN10 ArcDiskInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block2.Extension) == 0xf0, "LOADER_PARAMETER_BLOCK_WIN10 Extension");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, Block2.u.I386) == 0xf8, "LOADER_PARAMETER_BLOCK_WIN10 I386");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, FirmwareInformation) == 0x108, "LOADER_PARAMETER_BLOCK_WIN10 FirmwareInformation");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, OsBootstatPathName) == 0x148, "LOADER_PARAMETER_BLOCK_WIN10 OsBootstatPathName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, ArcOSDataDeviceName) == 0x150, "LOADER_PARAMETER_BLOCK_WIN10 ArcOSDataDeviceName");
static_assert(offsetof(LOADER_PARAMETER_BLOCK_WIN10, ArcWindowsSysPartName) == 0x158, "LOADER_PARAMETER_BLOCK_WIN10 ArcWindowsSysPartName");
#endif

typedef void (__stdcall* KERNEL_ENTRY_POINT)(void* LoaderBlock);

typedef struct {
    uint64_t BaseAddress;
    uint64_t Length;
    uint32_t Type;

    union {
        uint32_t ExtendedAttributesAsULONG;

        struct {
            uint32_t Enabled_Reserved : 1;
            uint32_t NonVolatile_Deprecated : 1;
            uint32_t SlowAccess_Deprecated : 1;
            uint32_t ErrorLog : 1;
            uint32_t Reserved : 28;
        } ExtendedAttributes;
    };
} BIOS_MEMORY_MAP;

typedef struct {
    uint64_t RSDTAddress;
    uint64_t Count;
    BIOS_MEMORY_MAP MemoryMap[1];
} ACPI_BIOS_DATA;

#define CmResourceTypeNull                      0
#define CmResourceTypePort                      1
#define CmResourceTypeInterrupt                 2
#define CmResourceTypeMemory                    3
#define CmResourceTypeDma                       4
#define CmResourceTypeDeviceSpecific            5
#define CmResourceTypeBusNumber                 6
#define CmResourceTypeMemoryLarge               7
#define CmResourceTypeNonArbitrated             128
#define CmResourceTypeConfigData                128
#define CmResourceTypeDevicePrivate             129
#define CmResourceTypePcCardConfig              130
#define CmResourceTypeMfCardConfig              131

typedef enum {
    CmResourceShareUndetermined,
    CmResourceShareDeviceExclusive,
    CmResourceShareDriverExclusive,
    CmResourceShareShared
} CM_SHARE_DISPOSITION;

#pragma pack(push,1)

typedef struct {
    uint8_t Type;
    uint8_t ShareDisposition;
    uint16_t Flags;
    union {
        struct {
            uint64_t Start;
            uint32_t Length;
        } Generic;
        struct {
            uint64_t Start;
            uint32_t Length;
        } Port;
        struct {
            uint32_t Level;
            uint32_t Vector;
            uintptr_t Affinity;
        } Interrupt;
        struct {
            uint64_t Start;
            uint32_t Length;
        } Memory;
        struct {
            uint32_t Channel;
            uint32_t Port;
            uint32_t Reserved1;
        } Dma;
        struct {
            uint32_t Data[3];
        } DevicePrivate;
        struct {
            uint32_t Start;
            uint32_t Length;
            uint32_t Reserved;
        } BusNumber;
        struct {
            uint32_t DataSize;
            uint32_t Reserved1;
            uint32_t Reserved2;
        } DeviceSpecificData;
    } u;
} CM_PARTIAL_RESOURCE_DESCRIPTOR;

#pragma pack(pop)

typedef struct {
    uint16_t Version;
    uint16_t Revision;
    uint32_t Count;
    CM_PARTIAL_RESOURCE_DESCRIPTOR PartialDescriptors[1];
} CM_PARTIAL_RESOURCE_LIST;

typedef enum {
    LoaderExceptionBlock,
    LoaderSystemBlock,
    LoaderFree,
    LoaderBad,
    LoaderLoadedProgram,
    LoaderFirmwareTemporary,
    LoaderFirmwarePermanent,
    LoaderOsloaderHeap,
    LoaderOsloaderStack,
    LoaderSystemCode,
    LoaderHalCode,
    LoaderBootDriver,
    LoaderConsoleInDriver,
    LoaderConsoleOutDriver,
    LoaderStartupDpcStack,
    LoaderStartupKernelStack,
    LoaderStartupPanicStack,
    LoaderStartupPcrPage,
    LoaderStartupPdrPage,
    LoaderRegistryData,
    LoaderMemoryData,
    LoaderNlsData,
    LoaderSpecialMemory,
    LoaderBBTMemory,
    LoaderReserve,
    LoaderXIPRom,
    LoaderHALCachedMemory,
    LoaderLargePageFiller,
    LoaderErrorLogMemory,
    LoaderMaximum
} TYPE_OF_MEMORY;

typedef struct {
    LIST_ENTRY ListEntry;
    TYPE_OF_MEMORY MemoryType;
    uintptr_t BasePage;
    uintptr_t PageCount;
} MEMORY_ALLOCATION_DESCRIPTOR;

#define LDRP_IMAGE_INTEGRITY_FORCED     0x00000020
#define LDRP_ENTRY_PROCESSED            0x00004000
#define LDRP_DRIVER_DEPENDENT_DLL       0x04000000

typedef struct _NON_PAGED_DEBUG_INFO NON_PAGED_DEBUG_INFO;

// This shouldn't be confused with the similarly named LDR_DATA_TABLE_ENTRY, with which
// it's partially binary-compatible.
typedef struct {
    LIST_ENTRY InLoadOrderLinks;
    void* ExceptionTable;
    uint32_t ExceptionTableSize;
    void* GpValue;
    NON_PAGED_DEBUG_INFO* NonPagedDebugInfo;
    void* DllBase;
    void* EntryPoint;
    uint32_t SizeOfImage;
    UNICODE_STRING FullDllName;
    UNICODE_STRING BaseDllName;
    union {
        uint32_t Flags;

        struct {
            uint32_t PackagedBinary : 1;
            uint32_t MarkedForRemoval : 1;
            uint32_t ImageDll : 1;
            uint32_t LoadNotificationsSent : 1;
            uint32_t TelemetryEntryProcessed : 1;
            uint32_t ProcessStaticImport : 1;
            uint32_t InLegacyLists : 1;
            uint32_t InIndexes : 1;
            uint32_t ShimDll : 1;
            uint32_t InExceptionTable : 1;
            uint32_t ReservedFlags1 : 2;
            uint32_t LoadInProgress : 1;
            uint32_t LoadConfigProcessed : 1;
            uint32_t EntryProcessed : 1;
            uint32_t ProtectDelayLoad : 1;
            uint32_t ReservedFlags3 : 2;
            uint32_t DontCallForThreads : 1;
            uint32_t ProcessAttachCalled : 1;
            uint32_t ProcessAttachFailed : 1;
            uint32_t CorDeferredValidate : 1;
            uint32_t CorImage : 1;
            uint32_t DontRelocate : 1;
            uint32_t CorILOnly : 1;
            uint32_t ChpeImage : 1;
            uint32_t ReservedFlags5 : 2;
            uint32_t Redirected : 1;
            uint32_t ReservedFlags6 : 2;
            uint32_t CompatDatabaseProcessed : 1;
        };
    };
    uint16_t LoadCount;
    uint16_t Reserved1;
    void* SectionPointer;
    uint32_t CheckSum;
    void* LoadedImports;
    void* PatchInformation;
    uint32_t unk1;
    uint32_t unk2;
    uint32_t unk3;
    uint32_t unk4;
    UNICODE_STRING unk5;
    UNICODE_STRING unk6;
    void* unk7;
    void* unk8;
    uint32_t unk9;
    uint32_t unk10;
    uint32_t unk11;
    uint32_t unk12;
    uint32_t unk13;
    uint32_t unk14; // bool ShouldCallDllInitialize?
} KLDR_DATA_TABLE_ENTRY;

typedef struct {
    LIST_ENTRY Link;
    UNICODE_STRING FilePath;
    UNICODE_STRING RegistryPath;
    KLDR_DATA_TABLE_ENTRY* LdrEntry;
    uint32_t Status;
    uint32_t unk1;
} BOOT_DRIVER_LIST_ENTRY;

#define SERVICE_KERNEL_DRIVER       0x00000001
#define SERVICE_FILE_SYSTEM_DRIVER  0x00000002
#define SERVICE_ADAPTER             0x00000004
#define SERVICE_RECOGNIZER_DRIVER   0x00000008
#define SERVICE_WIN32_OWN_PROCESS   0x00000010
#define SERVICE_WIN32_SHARE_PROCESS 0x00000020
#define SERVICE_USER_OWN_PROCESS    0x00000050
#define SERVICE_USER_SHARE_PROCESS  0x00000060

#define SERVICE_BOOT_START      0x00000000
#define SERVICE_SYSTEM_START    0x00000001
#define SERVICE_AUTO_START      0x00000002
#define SERVICE_DEMAND_START    0x00000003
#define SERVICE_DISABLED        0x00000004

#pragma pack(push,1)

typedef struct {
    uint8_t MajorRevision;
    uint8_t MinorRevision;
    uint8_t NoBuses;
    uint8_t HardwareMechanism;
} PCI_REGISTRY_INFO;

typedef struct {
    uint16_t DriveSelect;
    uint32_t MaxCylinders;
    uint16_t SectorsPerTrack;
    uint16_t MaxHeads;
    uint16_t NumberDrives;
} CM_INT13_DRIVE_PARAMETER;

typedef struct {
    uint32_t BytesPerSector;
    uint32_t NumberOfCylinders;
    uint32_t SectorsPerTrack;
    uint32_t NumberOfHeads;
} CM_DISK_GEOMETRY_DEVICE_DATA;

#pragma pack(pop)

typedef struct {
    uint32_t NameOffset;
    uint32_t NameLength;
    uint32_t DataOffset;
} API_SET_NAMESPACE_ENTRY_80;

typedef struct {
    uint32_t Version;
    uint32_t Count;
    API_SET_NAMESPACE_ENTRY_80 Array[1];
} API_SET_NAMESPACE_ARRAY_80;

typedef struct {
    uint32_t NameOffset;
    uint32_t NameLength;
    uint32_t ValueOffset;
    uint32_t ValueLength;
} API_SET_VALUE_ENTRY_80;

typedef struct {
    uint32_t Count;
    API_SET_VALUE_ENTRY_80 Array[1];
} API_SET_VALUE_ARRAY_80;

typedef struct {
    uint32_t Flags;
    uint32_t NameOffset;
    uint32_t NameLength;
    uint32_t AliasOffset;
    uint32_t AliasLength;
    uint32_t DataOffset;
} API_SET_NAMESPACE_ENTRY_81;

typedef struct {
    uint32_t Version;
    uint32_t Size;
    uint32_t Flags;
    uint32_t Count;
    API_SET_NAMESPACE_ENTRY_81 Array[1];
} API_SET_NAMESPACE_ARRAY_81;

typedef struct {
    uint32_t Flags;
    uint32_t NameOffset;
    uint32_t NameLength;
    uint32_t ValueOffset;
    uint32_t ValueLength;
} API_SET_VALUE_ENTRY_81;

typedef struct {
    uint32_t Flags;
    uint32_t Count;
    API_SET_VALUE_ENTRY_81 Array[1];
} API_SET_VALUE_ARRAY_81;

typedef struct {
    uint32_t Flags;
    uint32_t NameOffset;
    uint32_t NameLength;
    uint32_t AliasOffset;
    uint32_t HostsOffset;
    uint32_t NumberOfHosts;
} API_SET_NAMESPACE_ENTRY_10;

typedef struct {
    uint32_t Version;
    uint32_t Size;
    uint32_t Flags;
    uint32_t Count;
    uint32_t ArrayOffset;
    uint32_t HashOffset;
    uint32_t HashMultiplier;
} API_SET_NAMESPACE_HEADER_10;

#ifdef _X86_
typedef struct _KPCR {
    uint8_t NtTib[0x1c];
    struct _KPCR* SelfPcr;
    void* Prcb;
    uint32_t Irql;
    uint32_t IRR;
    uint32_t IrrActive;
    uint32_t IDR;
    void* KdVersionBlock;
    void* IDT;
    void* GDT;
    void* TSS;
    uint16_t MajorVersion;
    uint16_t MinorVersion;
    uint32_t SetMember;
    uint32_t StallScaleFactor;
    uint8_t SpareUnused;
    uint8_t Number;
    uint8_t Spare0;
    uint8_t SecondLevelCacheAssociativity;
    uint32_t VdmAlert;
    uint32_t KernelReserved[14];
    uint32_t SecondLevelCacheSize;
    uint32_t HalReserved[16];
    uint32_t InterruptMode;
    uint32_t Spare1;
    uint32_t KernelReserved2[17];
    uint8_t PrcbData;
} KPCR;

static_assert(offsetof(KPCR, PrcbData) == 0x120, "KPCR PrcbData has incorrect offset.");

#elif defined(__x86_64__)

typedef struct _KPCR {
    uint8_t NtTib[0x38];
    void* IdtBase;
    uint64_t Unused[2];
    uint8_t Irql;
    uint8_t SecondLevelCacheAssociativity;
    uint8_t ObsoleteNumber;
    uint8_t Fill0;
    uint32_t Unused0[3];
    uint16_t MajorVersion;
    uint16_t MinorVersion;
    uint32_t StallScaleFactor;
    void* Unused1[3];
    uint32_t KernelReserved[15];
    uint32_t SecondLevelCacheSize;
    uint32_t HalReserved[16];
    uint32_t Unused2;
    void* KdVersionBlock;
    void* Unused3;
    uint32_t PcrAlign1[24];
    uint64_t padding;
    uint8_t PrcbData;
} KPCR;

static_assert(offsetof(KPCR, PrcbData) == 0x180, "KPCR PrcbData has incorrect offset.");
#endif

/* See BOOT_GRAPHICS_CONTEXT below. The kernel stores a copy of this as nt!BgInternal,
 * hence the name. */

typedef struct {
    uint8_t unk1; // 01
    uint8_t unk2; // 01
    uint8_t unk3; // 00
    uint8_t unk4; // f4
    uint32_t height;
    uint32_t width;
    uint32_t pixels_per_scan_line; // ?
    uint32_t format; // ?
#ifdef __x86_64__
    uint32_t bits_per_pixel; // ?
#endif
    void* unk5;
    void* framebuffer;
} bg_internal;

#ifdef _X86_
static_assert(sizeof(bg_internal) == 0x1c, "bg_internal has incorrect size.");
#elif defined(__x86_64__)
static_assert(sizeof(bg_internal) == 0x28, "bg_internal has incorrect size.");
#endif

/* As far as I can tell, the BOOT_GRAPHICS_CONTEXT structures are *completely* undocumented -
 * nothing on Microsoft's website, nor in the PDB files of any version ntoskrnl or winload. */

typedef struct {
    void* unk1;
    void* unk2;
    void* unk3;
    void* unk4;
    bg_internal internal;
    void* system_font;
    uint32_t system_font_size;
    uint32_t unk5;
    void* console_font;
    uint32_t console_font_size;
    uint8_t boot_identifier[16];
    uint32_t version;
    uint32_t unk6;
    uint32_t unk7;
    void* mui;
    uint32_t mui_size;
#ifdef __x86_64__
    uint32_t padding1;
#endif
    void* logo_bitmap;
    void* unk8;
    uint32_t logo_bitmap_size;
    uint32_t unk9;
    uint32_t unk10;
    uint32_t logo_bitmap_width;
    uint32_t logo_bitmap_height;
    uint32_t unk11;
} bgblock1;

typedef struct {
    void* unk19;
    void* reserve_pool;
    uint32_t reserve_pool_size;
#ifdef __x86_64__
    uint32_t padding2;
#endif
    void* string_resources;
    void* progress_resources;
} bgblock2;

typedef struct {
    bgblock1 block1;
#ifdef _X86_
    uint32_t unk1;
    uint32_t unk2;
#endif
    bgblock2 block2;
} BOOT_GRAPHICS_CONTEXT_V1;

#ifdef _X86_
static_assert(sizeof(BOOT_GRAPHICS_CONTEXT_V1) == 0xa0, "BOOT_GRAPHICS_CONTEXT_V1 has incorrect size.");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk1) == 0x0, "BOOT_GRAPHICS_CONTEXT_V1 unk1");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk2) == 0x4, "BOOT_GRAPHICS_CONTEXT_V1 unk2");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk3) == 0x8, "BOOT_GRAPHICS_CONTEXT_V1 unk3");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk4) == 0xc, "BOOT_GRAPHICS_CONTEXT_V1 unk4");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.internal) == 0x10, "BOOT_GRAPHICS_CONTEXT_V1 internal");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.system_font) == 0x2c, "BOOT_GRAPHICS_CONTEXT_V1 system_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.system_font_size) == 0x30, "BOOT_GRAPHICS_CONTEXT_V1 system_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk5) == 0x34, "BOOT_GRAPHICS_CONTEXT_V1 unk5");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.console_font) == 0x38, "BOOT_GRAPHICS_CONTEXT_V1 console_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.console_font_size) == 0x3c, "BOOT_GRAPHICS_CONTEXT_V1 console_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.boot_identifier) == 0x40, "BOOT_GRAPHICS_CONTEXT_V1 boot_identifier");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.version) == 0x50, "BOOT_GRAPHICS_CONTEXT_V1 version");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk6) == 0x54, "BOOT_GRAPHICS_CONTEXT_V1 unk6");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk7) == 0x58, "BOOT_GRAPHICS_CONTEXT_V1 unk7");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.mui) == 0x5c, "BOOT_GRAPHICS_CONTEXT_V1 mui");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.mui_size) == 0x60, "BOOT_GRAPHICS_CONTEXT_V1 mui_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.logo_bitmap) == 0x64, "BOOT_GRAPHICS_CONTEXT_V1 logo_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk8) == 0x68, "BOOT_GRAPHICS_CONTEXT_V1 unk8");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.logo_bitmap_size) == 0x6c, "BOOT_GRAPHICS_CONTEXT_V1 logo_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk9) == 0x70, "BOOT_GRAPHICS_CONTEXT_V1 unk9");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk10) == 0x74, "BOOT_GRAPHICS_CONTEXT_V1 unk10");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.logo_bitmap_width) == 0x78, "BOOT_GRAPHICS_CONTEXT_V1 logo_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.logo_bitmap_height) == 0x7c, "BOOT_GRAPHICS_CONTEXT_V1 logo_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk11) == 0x80, "BOOT_GRAPHICS_CONTEXT_V1 unk11");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.unk19) == 0x8c, "BOOT_GRAPHICS_CONTEXT_V1 unk19");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.reserve_pool) == 0x90, "BOOT_GRAPHICS_CONTEXT_V1 reserve_pool");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.reserve_pool_size) == 0x94, "BOOT_GRAPHICS_CONTEXT_V1 reserve_pool_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.string_resources) == 0x98, "BOOT_GRAPHICS_CONTEXT_V1 string_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.progress_resources) == 0x9c, "BOOT_GRAPHICS_CONTEXT_V1 progress_resources");
#elif defined(__x86_64__)
static_assert(sizeof(BOOT_GRAPHICS_CONTEXT_V1) == 0xe0, "BOOT_GRAPHICS_CONTEXT_V1 has incorrect size.");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk1) == 0x0, "BOOT_GRAPHICS_CONTEXT_V1 unk1");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk2) == 0x8, "BOOT_GRAPHICS_CONTEXT_V1 unk2");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk3) == 0x10, "BOOT_GRAPHICS_CONTEXT_V1 unk3");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk4) == 0x18, "BOOT_GRAPHICS_CONTEXT_V1 unk4");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.internal) == 0x20, "BOOT_GRAPHICS_CONTEXT_V1 internal");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.system_font) == 0x48, "BOOT_GRAPHICS_CONTEXT_V1 system_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.system_font_size) == 0x50, "BOOT_GRAPHICS_CONTEXT_V1 system_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk5) == 0x54, "BOOT_GRAPHICS_CONTEXT_V1 unk5");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.console_font) == 0x58, "BOOT_GRAPHICS_CONTEXT_V1 console_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.console_font_size) == 0x60, "BOOT_GRAPHICS_CONTEXT_V1 console_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.boot_identifier) == 0x64, "BOOT_GRAPHICS_CONTEXT_V1 boot_identifier");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.version) == 0x74, "BOOT_GRAPHICS_CONTEXT_V1 version");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk6) == 0x78, "BOOT_GRAPHICS_CONTEXT_V1 unk6");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk7) == 0x7c, "BOOT_GRAPHICS_CONTEXT_V1 unk7");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.mui) == 0x80, "BOOT_GRAPHICS_CONTEXT_V1 mui");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.mui_size) == 0x88, "BOOT_GRAPHICS_CONTEXT_V1 mui_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.logo_bitmap) == 0x90, "BOOT_GRAPHICS_CONTEXT_V1 logo_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk8) == 0x98, "BOOT_GRAPHICS_CONTEXT_V1 unk8");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.logo_bitmap_size) == 0xa0, "BOOT_GRAPHICS_CONTEXT_V1 logo_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk9) == 0xa4, "BOOT_GRAPHICS_CONTEXT_V1 unk9");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk10) == 0xa8, "BOOT_GRAPHICS_CONTEXT_V1 unk10");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.logo_bitmap_width) == 0xac, "BOOT_GRAPHICS_CONTEXT_V1 logo_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.logo_bitmap_height) == 0xb0, "BOOT_GRAPHICS_CONTEXT_V1 logo_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block1.unk11) == 0xb4, "BOOT_GRAPHICS_CONTEXT_V1 unk11");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.unk19) == 0xb8, "BOOT_GRAPHICS_CONTEXT_V1 unk19");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.reserve_pool) == 0xc0, "BOOT_GRAPHICS_CONTEXT_V1 reserve_pool");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.reserve_pool_size) == 0xc8, "BOOT_GRAPHICS_CONTEXT_V1 reserve_pool_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.string_resources) == 0xd0, "BOOT_GRAPHICS_CONTEXT_V1 string_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V1, block2.progress_resources) == 0xd8, "BOOT_GRAPHICS_CONTEXT_V1 progress_resources");
#endif

typedef struct {
    bgblock1 block1;
#ifdef _X86_
    uint32_t unk1;
    uint32_t unk2;
#endif
    bgblock2 block2;
    uint8_t edid[128];
} BOOT_GRAPHICS_CONTEXT_V2;

#ifdef _X86_
static_assert(sizeof(BOOT_GRAPHICS_CONTEXT_V2) == 0x120, "BOOT_GRAPHICS_CONTEXT_V2 has incorrect size.");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk1) == 0x0, "BOOT_GRAPHICS_CONTEXT_V2 unk1");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk2) == 0x4, "BOOT_GRAPHICS_CONTEXT_V2 unk2");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk3) == 0x8, "BOOT_GRAPHICS_CONTEXT_V2 unk3");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk4) == 0xc, "BOOT_GRAPHICS_CONTEXT_V2 unk4");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.internal) == 0x10, "BOOT_GRAPHICS_CONTEXT_V2 internal");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.system_font) == 0x2c, "BOOT_GRAPHICS_CONTEXT_V2 system_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.system_font_size) == 0x30, "BOOT_GRAPHICS_CONTEXT_V2 system_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk5) == 0x34, "BOOT_GRAPHICS_CONTEXT_V2 unk5");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.console_font) == 0x38, "BOOT_GRAPHICS_CONTEXT_V2 console_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.console_font_size) == 0x3c, "BOOT_GRAPHICS_CONTEXT_V2 console_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.boot_identifier) == 0x40, "BOOT_GRAPHICS_CONTEXT_V2 boot_identifier");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.version) == 0x50, "BOOT_GRAPHICS_CONTEXT_V2 version");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk6) == 0x54, "BOOT_GRAPHICS_CONTEXT_V2 unk6");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk7) == 0x58, "BOOT_GRAPHICS_CONTEXT_V2 unk7");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.mui) == 0x5c, "BOOT_GRAPHICS_CONTEXT_V2 mui");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.mui_size) == 0x60, "BOOT_GRAPHICS_CONTEXT_V2 mui_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.logo_bitmap) == 0x64, "BOOT_GRAPHICS_CONTEXT_V2 logo_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk8) == 0x68, "BOOT_GRAPHICS_CONTEXT_V2 unk8");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.logo_bitmap_size) == 0x6c, "BOOT_GRAPHICS_CONTEXT_V2 logo_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk9) == 0x70, "BOOT_GRAPHICS_CONTEXT_V2 unk9");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk10) == 0x74, "BOOT_GRAPHICS_CONTEXT_V2 unk10");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.logo_bitmap_width) == 0x78, "BOOT_GRAPHICS_CONTEXT_V2 logo_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.logo_bitmap_height) == 0x7c, "BOOT_GRAPHICS_CONTEXT_V2 logo_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk11) == 0x80, "BOOT_GRAPHICS_CONTEXT_V2 unk11");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.unk19) == 0x8c, "BOOT_GRAPHICS_CONTEXT_V2 unk19");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.reserve_pool) == 0x90, "BOOT_GRAPHICS_CONTEXT_V2 reserve_pool");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.reserve_pool_size) == 0x94, "BOOT_GRAPHICS_CONTEXT_V2 reserve_pool_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.string_resources) == 0x98, "BOOT_GRAPHICS_CONTEXT_V2 string_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.progress_resources) == 0x9c, "BOOT_GRAPHICS_CONTEXT_V2 progress_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, edid) == 0xa0, "BOOT_GRAPHICS_CONTEXT_V2 edid");
#elif defined(__x86_64__)
static_assert(sizeof(BOOT_GRAPHICS_CONTEXT_V2) == 0x160, "BOOT_GRAPHICS_CONTEXT_V2 has incorrect size.");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk1) == 0x0, "BOOT_GRAPHICS_CONTEXT_V2 unk1");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk2) == 0x8, "BOOT_GRAPHICS_CONTEXT_V2 unk2");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk3) == 0x10, "BOOT_GRAPHICS_CONTEXT_V2 unk3");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk4) == 0x18, "BOOT_GRAPHICS_CONTEXT_V2 unk4");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.internal) == 0x20, "BOOT_GRAPHICS_CONTEXT_V2 internal");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.system_font) == 0x48, "BOOT_GRAPHICS_CONTEXT_V2 system_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.system_font_size) == 0x50, "BOOT_GRAPHICS_CONTEXT_V2 system_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk5) == 0x54, "BOOT_GRAPHICS_CONTEXT_V2 unk5");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.console_font) == 0x58, "BOOT_GRAPHICS_CONTEXT_V2 console_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.console_font_size) == 0x60, "BOOT_GRAPHICS_CONTEXT_V2 console_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.boot_identifier) == 0x64, "BOOT_GRAPHICS_CONTEXT_V2 boot_identifier");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.version) == 0x74, "BOOT_GRAPHICS_CONTEXT_V2 version");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk6) == 0x78, "BOOT_GRAPHICS_CONTEXT_V2 unk6");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk7) == 0x7c, "BOOT_GRAPHICS_CONTEXT_V2 unk7");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.mui) == 0x80, "BOOT_GRAPHICS_CONTEXT_V2 mui");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.mui_size) == 0x88, "BOOT_GRAPHICS_CONTEXT_V2 mui_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.logo_bitmap) == 0x90, "BOOT_GRAPHICS_CONTEXT_V2 logo_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk8) == 0x98, "BOOT_GRAPHICS_CONTEXT_V2 unk8");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.logo_bitmap_size) == 0xa0, "BOOT_GRAPHICS_CONTEXT_V2 logo_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk9) == 0xa4, "BOOT_GRAPHICS_CONTEXT_V2 unk9");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk10) == 0xa8, "BOOT_GRAPHICS_CONTEXT_V2 unk10");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.logo_bitmap_width) == 0xac, "BOOT_GRAPHICS_CONTEXT_V2 logo_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.logo_bitmap_height) == 0xb0, "BOOT_GRAPHICS_CONTEXT_V2 logo_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block1.unk11) == 0xb4, "BOOT_GRAPHICS_CONTEXT_V2 unk11");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.unk19) == 0xb8, "BOOT_GRAPHICS_CONTEXT_V2 unk19");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.reserve_pool) == 0xc0, "BOOT_GRAPHICS_CONTEXT_V2 reserve_pool");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.reserve_pool_size) == 0xc8, "BOOT_GRAPHICS_CONTEXT_V2 reserve_pool_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.string_resources) == 0xd0, "BOOT_GRAPHICS_CONTEXT_V2 string_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, block2.progress_resources) == 0xd8, "BOOT_GRAPHICS_CONTEXT_V2 progress_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V2, edid) == 0xe0, "BOOT_GRAPHICS_CONTEXT_V2 edid");
#endif

typedef struct {
    bgblock1 block1;
    void* qr_code_bitmap;
    uint32_t qr_code_bitmap_size;
    uint32_t qr_code_bitmap_width;
    uint32_t qr_code_bitmap_height;
    uint32_t unk13;
    uint32_t unk14;
    uint32_t unk15;
#ifdef _X86_
    uint32_t unk16;
#endif
    bgblock2 block2;
    uint8_t edid[128];
    uint32_t unk20;
    uint32_t unk21;
    uint32_t unk22;
    uint32_t unk23;
} BOOT_GRAPHICS_CONTEXT_V3;

#ifdef _X86_
static_assert(sizeof(BOOT_GRAPHICS_CONTEXT_V3) == 0x148, "BOOT_GRAPHICS_CONTEXT_V3 has incorrect size.");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk1) == 0x0, "BOOT_GRAPHICS_CONTEXT_V3 unk1");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk2) == 0x4, "BOOT_GRAPHICS_CONTEXT_V3 unk2");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk3) == 0x8, "BOOT_GRAPHICS_CONTEXT_V3 unk3");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk4) == 0xc, "BOOT_GRAPHICS_CONTEXT_V3 unk4");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.internal) == 0x10, "BOOT_GRAPHICS_CONTEXT_V3 internal");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.system_font) == 0x2c, "BOOT_GRAPHICS_CONTEXT_V3 system_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.system_font_size) == 0x30, "BOOT_GRAPHICS_CONTEXT_V3 system_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk5) == 0x34, "BOOT_GRAPHICS_CONTEXT_V3 unk5");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.console_font) == 0x38, "BOOT_GRAPHICS_CONTEXT_V3 console_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.console_font_size) == 0x3c, "BOOT_GRAPHICS_CONTEXT_V3 console_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.boot_identifier) == 0x40, "BOOT_GRAPHICS_CONTEXT_V3 boot_identifier");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.version) == 0x50, "BOOT_GRAPHICS_CONTEXT_V3 version");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk6) == 0x54, "BOOT_GRAPHICS_CONTEXT_V3 unk6");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk7) == 0x58, "BOOT_GRAPHICS_CONTEXT_V3 unk7");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.mui) == 0x5c, "BOOT_GRAPHICS_CONTEXT_V3 mui");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.mui_size) == 0x60, "BOOT_GRAPHICS_CONTEXT_V3 mui_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.logo_bitmap) == 0x64, "BOOT_GRAPHICS_CONTEXT_V3 logo_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk8) == 0x68, "BOOT_GRAPHICS_CONTEXT_V3 unk8");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.logo_bitmap_size) == 0x6c, "BOOT_GRAPHICS_CONTEXT_V3 logo_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk9) == 0x70, "BOOT_GRAPHICS_CONTEXT_V3 unk9");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk10) == 0x74, "BOOT_GRAPHICS_CONTEXT_V3 unk10");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.logo_bitmap_width) == 0x78, "BOOT_GRAPHICS_CONTEXT_V3 logo_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.logo_bitmap_height) == 0x7c, "BOOT_GRAPHICS_CONTEXT_V3 logo_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk11) == 0x80, "BOOT_GRAPHICS_CONTEXT_V3 unk11");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, qr_code_bitmap) == 0x84, "BOOT_GRAPHICS_CONTEXT_V3 qr_code_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, qr_code_bitmap_size) == 0x88, "BOOT_GRAPHICS_CONTEXT_V3 qr_code_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, qr_code_bitmap_width) == 0x8c, "BOOT_GRAPHICS_CONTEXT_V3 qr_code_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, qr_code_bitmap_height) == 0x90, "BOOT_GRAPHICS_CONTEXT_V3 qr_code_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk13) == 0x94, "BOOT_GRAPHICS_CONTEXT_V3 unk13");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk14) == 0x98, "BOOT_GRAPHICS_CONTEXT_V3 unk14");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk15) == 0x9c, "BOOT_GRAPHICS_CONTEXT_V3 unk15");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk16) == 0xa0, "BOOT_GRAPHICS_CONTEXT_V3 unk16");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.unk19) == 0xa4, "BOOT_GRAPHICS_CONTEXT_V3 unk19");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.reserve_pool) == 0xa8, "BOOT_GRAPHICS_CONTEXT_V3 reserve_pool");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.reserve_pool_size) == 0xac, "BOOT_GRAPHICS_CONTEXT_V3 reserve_pool_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.string_resources) == 0xb0, "BOOT_GRAPHICS_CONTEXT_V3 string_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.progress_resources) == 0xb4, "BOOT_GRAPHICS_CONTEXT_V3 progress_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, edid) == 0xb8, "BOOT_GRAPHICS_CONTEXT_V3 edid");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk20) == 0x138, "BOOT_GRAPHICS_CONTEXT_V3 unk20");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk21) == 0x13c, "BOOT_GRAPHICS_CONTEXT_V3 unk21");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk22) == 0x140, "BOOT_GRAPHICS_CONTEXT_V3 unk22");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk23) == 0x144, "BOOT_GRAPHICS_CONTEXT_V3 unk23");
#elif defined(__x86_64__)
static_assert(sizeof(BOOT_GRAPHICS_CONTEXT_V3) == 0x190, "BOOT_GRAPHICS_CONTEXT_V3 has incorrect size.");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk1) == 0x0, "BOOT_GRAPHICS_CONTEXT_V3 unk1");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk2) == 0x8, "BOOT_GRAPHICS_CONTEXT_V3 unk2");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk3) == 0x10, "BOOT_GRAPHICS_CONTEXT_V3 unk3");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk4) == 0x18, "BOOT_GRAPHICS_CONTEXT_V3 unk4");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.internal) == 0x20, "BOOT_GRAPHICS_CONTEXT_V3 internal");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.system_font) == 0x48, "BOOT_GRAPHICS_CONTEXT_V3 system_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.system_font_size) == 0x50, "BOOT_GRAPHICS_CONTEXT_V3 system_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk5) == 0x54, "BOOT_GRAPHICS_CONTEXT_V3 unk5");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.console_font) == 0x58, "BOOT_GRAPHICS_CONTEXT_V3 console_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.console_font_size) == 0x60, "BOOT_GRAPHICS_CONTEXT_V3 console_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.boot_identifier) == 0x64, "BOOT_GRAPHICS_CONTEXT_V3 boot_identifier");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.version) == 0x74, "BOOT_GRAPHICS_CONTEXT_V3 version");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk6) == 0x78, "BOOT_GRAPHICS_CONTEXT_V3 unk6");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk7) == 0x7c, "BOOT_GRAPHICS_CONTEXT_V3 unk7");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.mui) == 0x80, "BOOT_GRAPHICS_CONTEXT_V3 mui");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.mui_size) == 0x88, "BOOT_GRAPHICS_CONTEXT_V3 mui_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.logo_bitmap) == 0x90, "BOOT_GRAPHICS_CONTEXT_V3 logo_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk8) == 0x98, "BOOT_GRAPHICS_CONTEXT_V3 unk8");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.logo_bitmap_size) == 0xa0, "BOOT_GRAPHICS_CONTEXT_V3 logo_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk9) == 0xa4, "BOOT_GRAPHICS_CONTEXT_V3 unk9");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk10) == 0xa8, "BOOT_GRAPHICS_CONTEXT_V3 unk10");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.logo_bitmap_width) == 0xac, "BOOT_GRAPHICS_CONTEXT_V3 logo_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.logo_bitmap_height) == 0xb0, "BOOT_GRAPHICS_CONTEXT_V3 logo_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block1.unk11) == 0xb4, "BOOT_GRAPHICS_CONTEXT_V3 unk11");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, qr_code_bitmap) == 0xb8, "BOOT_GRAPHICS_CONTEXT_V3 qr_code_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, qr_code_bitmap_size) == 0xc0, "BOOT_GRAPHICS_CONTEXT_V3 qr_code_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, qr_code_bitmap_width) == 0xc4, "BOOT_GRAPHICS_CONTEXT_V3 qr_code_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, qr_code_bitmap_height) == 0xc8, "BOOT_GRAPHICS_CONTEXT_V3 qr_code_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk13) == 0xcc, "BOOT_GRAPHICS_CONTEXT_V3 unk13");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk14) == 0xd0, "BOOT_GRAPHICS_CONTEXT_V3 unk14");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk15) == 0xd4, "BOOT_GRAPHICS_CONTEXT_V3 unk15");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.unk19) == 0xd8, "BOOT_GRAPHICS_CONTEXT_V3 unk19");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.reserve_pool) == 0xe0, "BOOT_GRAPHICS_CONTEXT_V3 reserve_pool");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.reserve_pool_size) == 0xe8, "BOOT_GRAPHICS_CONTEXT_V3 reserve_pool_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.string_resources) == 0xf0, "BOOT_GRAPHICS_CONTEXT_V3 string_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, block2.progress_resources) == 0xf8, "BOOT_GRAPHICS_CONTEXT_V3 progress_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, edid) == 0x100, "BOOT_GRAPHICS_CONTEXT_V3 edid");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk20) == 0x180, "BOOT_GRAPHICS_CONTEXT_V3 unk20");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk21) == 0x184, "BOOT_GRAPHICS_CONTEXT_V3 unk21");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk22) == 0x188, "BOOT_GRAPHICS_CONTEXT_V3 unk22");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V3, unk23) == 0x18c, "BOOT_GRAPHICS_CONTEXT_V3 unk23");
#endif

typedef struct {
    bgblock1 block1;
    void* qr_code_bitmap;
    uint32_t qr_code_bitmap_size;
    uint32_t qr_code_bitmap_width;
    uint32_t qr_code_bitmap_height;
    uint32_t unk13;
    uint32_t unk14;
    uint32_t unk15;
    void* unk16;
    uint32_t unk17;
    uint32_t unk18;
    bgblock2 block2;
    uint8_t edid[128];
    uint32_t unk20;
    uint32_t unk21;
    uint32_t unk22;
    uint32_t unk23;
} BOOT_GRAPHICS_CONTEXT_V4;

#ifdef _X86_
static_assert(sizeof(BOOT_GRAPHICS_CONTEXT_V4) == 0x150, "BOOT_GRAPHICS_CONTEXT_V4 has incorrect size.");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk1) == 0x0, "BOOT_GRAPHICS_CONTEXT_V4 unk1");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk2) == 0x4, "BOOT_GRAPHICS_CONTEXT_V4 unk2");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk3) == 0x8, "BOOT_GRAPHICS_CONTEXT_V4 unk3");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk4) == 0xc, "BOOT_GRAPHICS_CONTEXT_V4 unk4");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.internal) == 0x10, "BOOT_GRAPHICS_CONTEXT_V4 internal");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.system_font) == 0x2c, "BOOT_GRAPHICS_CONTEXT_V4 system_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.system_font_size) == 0x30, "BOOT_GRAPHICS_CONTEXT_V4 system_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk5) == 0x34, "BOOT_GRAPHICS_CONTEXT_V4 unk5");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.console_font) == 0x38, "BOOT_GRAPHICS_CONTEXT_V4 console_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.console_font_size) == 0x3c, "BOOT_GRAPHICS_CONTEXT_V4 console_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.boot_identifier) == 0x40, "BOOT_GRAPHICS_CONTEXT_V4 boot_identifier");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.version) == 0x50, "BOOT_GRAPHICS_CONTEXT_V4 version");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk6) == 0x54, "BOOT_GRAPHICS_CONTEXT_V4 unk6");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk7) == 0x58, "BOOT_GRAPHICS_CONTEXT_V4 unk7");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.mui) == 0x5c, "BOOT_GRAPHICS_CONTEXT_V4 mui");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.mui_size) == 0x60, "BOOT_GRAPHICS_CONTEXT_V4 mui_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.logo_bitmap) == 0x64, "BOOT_GRAPHICS_CONTEXT_V4 logo_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk8) == 0x68, "BOOT_GRAPHICS_CONTEXT_V4 unk8");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.logo_bitmap_size) == 0x6c, "BOOT_GRAPHICS_CONTEXT_V4 logo_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk9) == 0x70, "BOOT_GRAPHICS_CONTEXT_V4 unk9");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk10) == 0x74, "BOOT_GRAPHICS_CONTEXT_V4 unk10");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.logo_bitmap_width) == 0x78, "BOOT_GRAPHICS_CONTEXT_V4 logo_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.logo_bitmap_height) == 0x7c, "BOOT_GRAPHICS_CONTEXT_V4 logo_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk11) == 0x80, "BOOT_GRAPHICS_CONTEXT_V4 unk11");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, qr_code_bitmap) == 0x84, "BOOT_GRAPHICS_CONTEXT_V4 qr_code_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, qr_code_bitmap_size) == 0x88, "BOOT_GRAPHICS_CONTEXT_V4 qr_code_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, qr_code_bitmap_width) == 0x8c, "BOOT_GRAPHICS_CONTEXT_V4 qr_code_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, qr_code_bitmap_height) == 0x90, "BOOT_GRAPHICS_CONTEXT_V4 qr_code_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk13) == 0x94, "BOOT_GRAPHICS_CONTEXT_V4 unk13");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk14) == 0x98, "BOOT_GRAPHICS_CONTEXT_V4 unk14");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk15) == 0x9c, "BOOT_GRAPHICS_CONTEXT_V4 unk15");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk16) == 0xa0, "BOOT_GRAPHICS_CONTEXT_V4 unk16");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk17) == 0xa4, "BOOT_GRAPHICS_CONTEXT_V4 unk17");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk18) == 0xa8, "BOOT_GRAPHICS_CONTEXT_V4 unk18");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.unk19) == 0xac, "BOOT_GRAPHICS_CONTEXT_V4 unk19");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.reserve_pool) == 0xb0, "BOOT_GRAPHICS_CONTEXT_V4 reserve_pool");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.reserve_pool_size) == 0xb4, "BOOT_GRAPHICS_CONTEXT_V4 reserve_pool_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.string_resources) == 0xb8, "BOOT_GRAPHICS_CONTEXT_V4 string_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.progress_resources) == 0xbc, "BOOT_GRAPHICS_CONTEXT_V4 progress_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, edid) == 0xc0, "BOOT_GRAPHICS_CONTEXT_V4 edid");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk20) == 0x140, "BOOT_GRAPHICS_CONTEXT_V4 unk20");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk21) == 0x144, "BOOT_GRAPHICS_CONTEXT_V4 unk21");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk22) == 0x148, "BOOT_GRAPHICS_CONTEXT_V4 unk22");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk23) == 0x14c, "BOOT_GRAPHICS_CONTEXT_V4 unk23");
#elif defined(__x86_64__)
static_assert(sizeof(BOOT_GRAPHICS_CONTEXT_V4) == 0x1a0, "BOOT_GRAPHICS_CONTEXT_V4 has incorrect size.");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk1) == 0x0, "BOOT_GRAPHICS_CONTEXT_V4 unk1");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk2) == 0x8, "BOOT_GRAPHICS_CONTEXT_V4 unk2");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk3) == 0x10, "BOOT_GRAPHICS_CONTEXT_V4 unk3");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk4) == 0x18, "BOOT_GRAPHICS_CONTEXT_V4 unk4");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.internal) == 0x20, "BOOT_GRAPHICS_CONTEXT_V4 internal");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.system_font) == 0x48, "BOOT_GRAPHICS_CONTEXT_V4 system_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.system_font_size) == 0x50, "BOOT_GRAPHICS_CONTEXT_V4 system_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk5) == 0x54, "BOOT_GRAPHICS_CONTEXT_V4 unk5");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.console_font) == 0x58, "BOOT_GRAPHICS_CONTEXT_V4 console_font");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.console_font_size) == 0x60, "BOOT_GRAPHICS_CONTEXT_V4 console_font_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.boot_identifier) == 0x64, "BOOT_GRAPHICS_CONTEXT_V4 boot_identifier");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.version) == 0x74, "BOOT_GRAPHICS_CONTEXT_V4 version");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk6) == 0x78, "BOOT_GRAPHICS_CONTEXT_V4 unk6");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk7) == 0x7c, "BOOT_GRAPHICS_CONTEXT_V4 unk7");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.mui) == 0x80, "BOOT_GRAPHICS_CONTEXT_V4 mui");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.mui_size) == 0x88, "BOOT_GRAPHICS_CONTEXT_V4 mui_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.logo_bitmap) == 0x90, "BOOT_GRAPHICS_CONTEXT_V4 logo_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk8) == 0x98, "BOOT_GRAPHICS_CONTEXT_V4 unk8");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.logo_bitmap_size) == 0xa0, "BOOT_GRAPHICS_CONTEXT_V4 logo_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk9) == 0xa4, "BOOT_GRAPHICS_CONTEXT_V4 unk9");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk10) == 0xa8, "BOOT_GRAPHICS_CONTEXT_V4 unk10");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.logo_bitmap_width) == 0xac, "BOOT_GRAPHICS_CONTEXT_V4 logo_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.logo_bitmap_height) == 0xb0, "BOOT_GRAPHICS_CONTEXT_V4 logo_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block1.unk11) == 0xb4, "BOOT_GRAPHICS_CONTEXT_V4 unk11");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, qr_code_bitmap) == 0xb8, "BOOT_GRAPHICS_CONTEXT_V4 qr_code_bitmap");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, qr_code_bitmap_size) == 0xc0, "BOOT_GRAPHICS_CONTEXT_V4 qr_code_bitmap_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, qr_code_bitmap_width) == 0xc4, "BOOT_GRAPHICS_CONTEXT_V4 qr_code_bitmap_width");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, qr_code_bitmap_height) == 0xc8, "BOOT_GRAPHICS_CONTEXT_V4 qr_code_bitmap_height");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk13) == 0xcc, "BOOT_GRAPHICS_CONTEXT_V4 unk13");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk14) == 0xd0, "BOOT_GRAPHICS_CONTEXT_V4 unk14");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk15) == 0xd4, "BOOT_GRAPHICS_CONTEXT_V4 unk15");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk16) == 0xd8, "BOOT_GRAPHICS_CONTEXT_V4 unk16");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk17) == 0xe0, "BOOT_GRAPHICS_CONTEXT_V4 unk17");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk18) == 0xe4, "BOOT_GRAPHICS_CONTEXT_V4 unk18");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.unk19) == 0xe8, "BOOT_GRAPHICS_CONTEXT_V4 unk19");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.reserve_pool) == 0xf0, "BOOT_GRAPHICS_CONTEXT_V4 reserve_pool");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.reserve_pool_size) == 0xf8, "BOOT_GRAPHICS_CONTEXT_V4 reserve_pool_size");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.string_resources) == 0x100, "BOOT_GRAPHICS_CONTEXT_V4 string_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, block2.progress_resources) == 0x108, "BOOT_GRAPHICS_CONTEXT_V4 progress_resources");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, edid) == 0x110, "BOOT_GRAPHICS_CONTEXT_V4 edid");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk20) == 0x190, "BOOT_GRAPHICS_CONTEXT_V4 unk20");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk21) == 0x194, "BOOT_GRAPHICS_CONTEXT_V4 unk21");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk22) == 0x198, "BOOT_GRAPHICS_CONTEXT_V4 unk22");
static_assert(offsetof(BOOT_GRAPHICS_CONTEXT_V4, unk23) == 0x19c, "BOOT_GRAPHICS_CONTEXT_V4 unk23");
#endif
