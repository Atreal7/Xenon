// Return codes
typedef unsigned long long EFI_STATUS; // 64-bit on x64
typedef void* EFI_HANDLE;              // opaque image handle
#define EFIAPI __attribute__((ms_abi))


typedef struct {
  unsigned long long     Signature;
  unsigned          Revision;
  unsigned          HeaderSize;
  unsigned          CRC32;
  unsigned          Reserved;
 } EFI_TABLE_HEADER;

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef EFI_STATUS (*EFI_TEXT_STRING)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, const __CHAR16_TYPE__ *String);


typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
        void   *Reset;
        EFI_TEXT_STRING   OutputString;
        void   *TestString;
        void   *QueryMode;
        void   *SetMode;
        void   *SetAttribute;
        void   *ClearScreen;
        void   *SetCursorPosition;
        void   *EnableCursor;
        void   *Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;



typedef struct {
  EFI_TABLE_HEADER      Hdr;
  __CHAR16_TYPE__       *FirmwareVendor;
  unsigned              FirmwareRevision;
  EFI_HANDLE            ConsoleInHandle;
  void                  *ConIn;
  EFI_HANDLE   ConsoleOutHandle;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL   *ConOut;
  EFI_HANDLE            StandardErrorHandle;
  void                  *StdErr;
  void                  *RuntimeServices;
  void                  *BootServices;
  unsigned long long          NumberOfTableEntries;
  void                  *ConfigurationTable;
} EFI_SYSTEM_TABLE;


__attribute__((section(".text")))
EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
  if (SystemTable && SystemTable->ConOut && SystemTable->ConOut->OutputString) {
    EFI_TEXT_STRING f = (EFI_TEXT_STRING)SystemTable->ConOut->OutputString;
    f(SystemTable->ConOut,(__CHAR16_TYPE__ *)L"Hello world\r\n");
  }
    //for(volatile int i = 0; i<2000; i++);
    return 0;
}
__attribute__((used))
void *dummy_reloc = (void*)&efi_main;
