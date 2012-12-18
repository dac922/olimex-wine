/*
 * SiUSBXp.dll
 *
 * Generated from SiUSBXp.dll by winedump.
 *
 * DO NOT SEND GENERATED DLLS FOR INCLUSION INTO WINE !
 *
 */
#ifndef __WINE_SIUSBXP_DLL_H
#define __WINE_SIUSBXP_DLL_H

#ifndef _WINDOWS
#include <pthread.h>
#define WINAPI
#endif

#ifdef SI_USB_XP_EXPORTS 
#define SI_USB_XP_API __declspec(dllexport) 
#else 
#define SI_USB_XP_API __declspec(dllimport) 
#endif 

#ifndef _WINDOWS
#include "WinTypes.h"

#ifdef SI_USB_XP_API
#undef SI_USB_XP_API
#define SI_USB_XP_API
#endif
#endif

/* return codes */
enum {
	SI_DEVICE_NOT_FOUND = 0xFF,
	SI_SUCCESS = 0x00,
	SI_INVALID_HANDLE,
	SI_READ_ERROR,
	SI_RX_QUEUE_NOT_READY,
	SI_WRITE_ERROR,
	SI_RESET_ERROR,
	SI_INVALID_PARAMETER,
	SI_INVALID_REQUEST_LENGTH,
	SI_DEVICE_IO_FAILED,
	SI_INVALID_BAUDRATE,
	SI_FUNCTION_NOT_SUPPORTED,
	SI_GLOBAL_DATA_ERROR,
	SI_SYSTEM_ERROR_CODE,
	SI_READ_TIMED_OUT,
	SI_WRITE_TIMED_OUT,
	SI_IO_PENDING
};

/* GetProductString  */
enum {
	SI_RETURN_SERIAL_NUMBER = 0x00,
	SI_RETURN_DESCRIPTION,
	SI_RETURN_LINK_NAME,
	SI_RETURN_VID,
	SI_RETURN_PID
};

/* RX Queue status */
enum {
	SI_RX_NO_OVERRUN = 0x00,
	SI_RX_EMPTY = 0x00,
	SI_RX_OVERRUN,
	SI_RX_READY
};


/* typedefs */
#define		SI_MAX_DEVICE_STRLEN		256 
#define		SI_MAX_READ_SIZE		4096*16 
#define		SI_MAX_WRITE_SIZE		4096 

typedef		int		SI_STATUS; 
typedef		char	SI_DEVICE_STRING[SI_MAX_DEVICE_STRLEN]; 


/* prototypes */
#ifdef __cplusplus
extern "C" {
#endif

SI_USB_XP_API SI_STATUS WINAPI SI_GetNumDevices(LPDWORD lpdwNumDevices);
SI_USB_XP_API SI_STATUS WINAPI SI_GetProductString(DWORD dwDeviceNum, LPVOID lpvDeviceString, DWORD dwFlags);
SI_USB_XP_API SI_STATUS WINAPI SI_Open(DWORD dwDevice, HANDLE * cyHandle);
SI_USB_XP_API SI_STATUS WINAPI SI_Close(HANDLE cyHandle);
//SI_USB_XP_API int WINAPI global_SI_ResetDevice_5(void * arg0);
SI_USB_XP_API SI_STATUS WINAPI SI_Read(HANDLE cyHandle, LPVOID lpBuffer, DWORD dwBytesToRead, LPDWORD lpdwBytesReturned, OVERLAPPED * o);
SI_USB_XP_API SI_STATUS WINAPI SI_Write(HANDLE cyHandle, LPVOID lpBuffer, DWORD dwBytesToWrite, LPDWORD lpdwBytesWritten, OVERLAPPED * o);
SI_USB_XP_API SI_STATUS WINAPI SI_DeviceIOControl(HANDLE cyHandle, DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD dwBytesToRead, LPVOID lpOutBuffer, DWORD dwBytesToWrite, LPDWORD lpdwBytesSucceeded);
SI_USB_XP_API SI_STATUS WINAPI SI_FlushBuffers(HANDLE cyHandle, BYTE FlushTransmit, BYTE FlushReceive);
SI_USB_XP_API SI_STATUS WINAPI SI_SetTimeouts(DWORD dwReadTimeout, DWORD dwWriteTimeout);
SI_USB_XP_API SI_STATUS WINAPI SI_GetTimeouts(LPDWORD lpdwReadTimeout, LPDWORD lpdwWriteTimeout);
SI_USB_XP_API SI_STATUS WINAPI SI_CheckRXQueue(HANDLE cyHandle, LPDWORD lpdwNumBytesInQueue, LPDWORD lpdwQueueStatus);
SI_USB_XP_API SI_STATUS WINAPI SI_SetBaudRate(HANDLE cyHandle, DWORD dwBaudRate);
SI_USB_XP_API SI_STATUS WINAPI SI_SetBaudDivisor(HANDLE cyHandle, WORD wBaudDivisor);
SI_USB_XP_API SI_STATUS WINAPI SI_SetLineControl(HANDLE cyHandle, WORD wLineControl);
SI_USB_XP_API SI_STATUS WINAPI SI_SetFlowControl(HANDLE cyHandle, BYTE bCTS_MaskCode, BYTE bRTS_MaskCode, BYTE bDTR_MaskCode, BYTE bDSR_MaskCode, BYTE bDCD_MaskCode, BOOL bFlowXonXoff);
SI_USB_XP_API SI_STATUS WINAPI SI_GetModemStatus(HANDLE cyHandle, PBYTE ModemStatus);
SI_USB_XP_API SI_STATUS WINAPI SI_SetBreak(HANDLE cyHandle, WORD wBreakState);
SI_USB_XP_API SI_STATUS WINAPI SI_ReadLatch(HANDLE cyHandle, LPBYTE lpbLatch);
SI_USB_XP_API SI_STATUS WINAPI SI_WriteLatch(HANDLE cyHandle, BYTE bMask, BYTE bLatch);
SI_USB_XP_API SI_STATUS WINAPI SI_GetPartNumber(HANDLE cyHandle, LPBYTE lpbPartNum);
SI_USB_XP_API SI_STATUS WINAPI SI_GetDLLVersion(DWORD * HighVersion, DWORD * LowVersion);
SI_USB_XP_API SI_STATUS WINAPI SI_GetDriverVersion(DWORD * HighVersion, DWORD * LowVersion);

#ifdef __cplusplus
}
#endif

#endif	/* __WINE_SIUSBXP_DLL_H */
