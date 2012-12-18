/*
 * ftd2xx.dll for WINE
 *
 * Based on file Generated from ftd2xx.dll by the command:
 * $ winedump spec ftd2xx.dll -Iftd2xx.h -c -t
 *
 * Crafted by gatopeich in 2008
 *
 * Version 1.0 - A direct mapping from ftd2xx.dll to libftd2xx.so
 */

#include <stdarg.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

#include <linux/serial.h>
#include <sys/ioctl.h>

#include <windef.h>
#include <winbase.h>
#include <wine/debug.h>

/* Some grease to get through ftd2xx.h under winegcc ... */
#include <pthread.h>
#define _WINDOWS
#define __WINDOWS_TYPES__
#undef __declspec
#define __declspec(x)
#include "ftd2xx.h"

WINE_DEFAULT_DEBUG_CHANNEL(ftd2xx);

char *pRxBuf=NULL,*pTxBuf=NULL;
int rxSize=0,txSize=0;

char *RxBuf[2048],*TxBuf[2048];

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	TRACE("(0x%p, %d, %p)\n", hinstDLL, fdwReason, lpvReserved);

	switch (fdwReason)
	{
		case DLL_WINE_PREATTACH:
			return TRUE;    /* prefer this version */
		case DLL_PROCESS_ATTACH:
			break;
		case DLL_PROCESS_DETACH:
			if (pRxBuf) free(pRxBuf);
			if (pTxBuf) free(pTxBuf);
			break;
		default:
			break;
	}

	return TRUE;
}


char* status[]={
	"OK",
	"INVALID_HANDLE",
	"DEVICE_NOT_FOUND",
	"DEVICE_NOT_OPENED",
	"IO_ERROR",
	"INSUFFICIENT_RESOURCES",
	"INVALID_PARAMETER",
	"INVALID_BAUD_RATE",	//7

	"DEVICE_NOT_OPENED_FOR_ERASE",
	"DEVICE_NOT_OPENED_FOR_WRITE",
	"FAILED_TO_WRITE_DEVICE",
	"EEPROM_READ_FAILED",
	"EEPROM_WRITE_FAILED",
	"EEPROM_ERASE_FAILED",
	"EEPROM_NOT_PRESENT",
	"EEPROM_NOT_PROGRAMMED",
	"INVALID_ARGS",
	"NOT_SUPPORTED",
	"OTHER_ERROR"
};

/*
 * FT_Open (FTD2XX.1)
 */
FT_STATUS __stdcall FTD2XX_FT_Open(int deviceNumber, FT_HANDLE * pHandle)
{
	TRACE("((int)%d,(FT_HANDLE *)%p) --> ",(LONG)deviceNumber,pHandle);
	//FT_STATUS r = FT_Open(deviceNumber, pHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_Close (FTD2XX.2)
 */
FT_STATUS __stdcall FTD2XX_FT_Close(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
	//FT_STATUS r = FT_Close(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_Read (FTD2XX.3)
 */
FT_STATUS __stdcall FTD2XX_FT_Read(FT_HANDLE ftHandle, LPVOID lpBuffer, DWORD nBufferSize, LPDWORD lpBytesReturned)
{
	//FT_STATUS r = FT_Read(ftHandle, lpBuffer, nBufferSize, lpBytesReturned);
	FT_STATUS r = 17;
	if(FT_OK!=r) ERR("(FT_HANDLE: %p, buffer[%u]@%p, BytesReturned=%u, status: %s\n",ftHandle,nBufferSize,lpBuffer,*lpBytesReturned,status[r]);
	return r;
}
/*
 * FT_Write (FTD2XX.4)
 */
FT_STATUS __stdcall FTD2XX_FT_Write(FT_HANDLE ftHandle, LPVOID lpBuffer, DWORD nBufferSize, LPDWORD lpBytesWritten)
{
	//FT_STATUS r = FT_Write(ftHandle, lpBuffer, nBufferSize, lpBytesWritten);
	FT_STATUS r = 17;
	if(FT_OK!=r) ERR("(FT_HANDLE: %p, buffer[%u]@%p, BytesWritten=%u, status: %s\n",ftHandle,nBufferSize,lpBuffer,*lpBytesWritten,status[r]);
	return r;
}
/*
 * FT_IoCtl (FTD2XX.5)
 */
FT_STATUS __stdcall FTD2XX_FT_IoCtl(FT_HANDLE ftHandle, DWORD dwIoControlCode, LPVOID lpInBuf, DWORD nInBufSize, LPVOID lpOutBuf, DWORD nOutBufSize, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped)
{
	TRACE("(FT_HANDLE: %p,(DWORD)%d,(LPVOID)%p,(DWORD)%d,(LPVOID)%p,(DWORD)%d,(LPDWORD)%p,(LPOVERLAPPED)%p) --> ",ftHandle,(LONG)dwIoControlCode,lpInBuf,(LONG)nInBufSize,lpOutBuf,(LONG)nOutBufSize,lpBytesReturned,lpOverlapped);
	//FT_STATUS r = FT_IoCtl(ftHandle, dwIoControlCode, lpInBuf, nInBufSize, lpOutBuf, nOutBufSize, lpBytesReturned, lpOverlapped);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_ResetDevice (FTD2XX.6)
 */
FT_STATUS __stdcall FTD2XX_FT_ResetDevice(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
	//FT_STATUS r = FT_ResetDevice(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetBaudRate (FTD2XX.7)
 */
FT_STATUS __stdcall FTD2XX_FT_SetBaudRate(FT_HANDLE ftHandle, ULONG BaudRate)
{
	TRACE("(FT_HANDLE: %p,(ULONG)%d) --> ",ftHandle,(LONG)BaudRate);
	//FT_STATUS r = FT_SetBaudRate(ftHandle, BaudRate);
	FT_STATUS r = 0;	
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetDataCharacteristics (FTD2XX.8)
 */
FT_STATUS __stdcall FTD2XX_FT_SetDataCharacteristics(FT_HANDLE ftHandle, UCHAR WordLength, UCHAR StopBits, UCHAR Parity)
{
	TRACE("(FT_HANDLE: %p,(UCHAR)%u,(UCHAR)%u,(UCHAR)%u) --> ",ftHandle,(LONG)WordLength,(LONG)StopBits,(LONG)Parity);
//	FT_STATUS r = FT_SetDataCharacteristics(ftHandle, WordLength, StopBits, Parity);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetFlowControl (FTD2XX.9)
 */
FT_STATUS __stdcall FTD2XX_FT_SetFlowControl(FT_HANDLE ftHandle, USHORT FlowControl, UCHAR XonChar, UCHAR XoffChar)
{
	TRACE("(FT_HANDLE: %p,(USHORT)%u,(UCHAR)%u,(UCHAR)%u) --> ",ftHandle,(LONG)FlowControl,(LONG)XonChar,(LONG)XoffChar);
//	FT_STATUS r = FT_SetFlowControl(ftHandle, FlowControl, XonChar, XoffChar);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetDtr (FTD2XX.10)
 */
FT_STATUS __stdcall FTD2XX_FT_SetDtr(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_SetDtr(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_ClrDtr (FTD2XX.11)
 */
FT_STATUS __stdcall FTD2XX_FT_ClrDtr(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_ClrDtr(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetRts (FTD2XX.12)
 */
FT_STATUS __stdcall FTD2XX_FT_SetRts(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_SetRts(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_ClrRts (FTD2XX.13)
 */
FT_STATUS __stdcall FTD2XX_FT_ClrRts(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_ClrRts(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_GetModemStatus (FTD2XX.14)
 */
FT_STATUS __stdcall FTD2XX_FT_GetModemStatus(FT_HANDLE ftHandle, ULONG * pModemStatus)
{
	TRACE("(FT_HANDLE: %p,(ULONG *)%p) --> ",ftHandle,pModemStatus);
//	FT_STATUS r = FT_GetModemStatus(ftHandle, pModemStatus);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetChars (FTD2XX.15)
 */
FT_STATUS __stdcall FTD2XX_FT_SetChars(FT_HANDLE ftHandle, UCHAR EventChar, UCHAR EventCharEnabled, UCHAR ErrorChar, UCHAR ErrorCharEnabled)
{
	TRACE("(FT_HANDLE: %p,(UCHAR)%u,(UCHAR)%u,(UCHAR)%u,(UCHAR)%u) --> ",ftHandle,(LONG)EventChar,(LONG)EventCharEnabled,(LONG)ErrorChar,(LONG)ErrorCharEnabled);
//	FT_STATUS r = FT_SetChars(ftHandle, EventChar, EventCharEnabled, ErrorChar, ErrorCharEnabled);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_Purge (FTD2XX.16)
 */
FT_STATUS __stdcall FTD2XX_FT_Purge(FT_HANDLE ftHandle, ULONG Mask)
{
	TRACE("(FT_HANDLE: %p,(ULONG)%d) --> ",ftHandle,(LONG)Mask);
//	FT_STATUS r = FT_Purge(ftHandle, Mask);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetTimeouts (FTD2XX.17)
 */
FT_STATUS __stdcall FTD2XX_FT_SetTimeouts(FT_HANDLE ftHandle, ULONG ReadTimeout, ULONG WriteTimeout)
{
	TRACE("(FT_HANDLE: %p,(ULONG)%d,(ULONG)%d) --> ",ftHandle,(LONG)ReadTimeout,(LONG)WriteTimeout);
//	FT_STATUS r = FT_SetTimeouts(ftHandle, ReadTimeout, WriteTimeout);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_GetQueueStatus (FTD2XX.18)
 */
FT_STATUS __stdcall FTD2XX_FT_GetQueueStatus(FT_HANDLE ftHandle, DWORD * dwRxBytes)
{
//	FT_STATUS r = FT_GetQueueStatus(ftHandle, dwRxBytes);
	FT_STATUS r = 17;
	if(FT_OK!=r) ERR("(FT_HANDLE: %p, AmountInRxQueue=%u, status: %s\n",ftHandle,*dwRxBytes,status[r]);
	return r;
}
/*
 * FT_SetEventNotification (FTD2XX.19)
 */
FT_STATUS __stdcall FTD2XX_FT_SetEventNotification(FT_HANDLE ftHandle, DWORD Mask, PVOID Param)
{
	TRACE("(FT_HANDLE: %p,(DWORD)%d,(PVOID)%p) --> ",ftHandle,(LONG)Mask,Param);
//	FT_STATUS r = FT_SetEventNotification(ftHandle, Mask, Param);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_GetEventStatus (FTD2XX.20)
 */
FT_STATUS __stdcall FTD2XX_FT_GetEventStatus(FT_HANDLE ftHandle, DWORD * dwEventDWord)
{
	TRACE("(FT_HANDLE: %p,(DWORD *)%p) --> ",ftHandle,dwEventDWord);
//	FT_STATUS r = FT_GetEventStatus(ftHandle, dwEventDWord);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_GetStatus (FTD2XX.21)
 */
FT_STATUS __stdcall FTD2XX_FT_GetStatus(FT_HANDLE ftHandle, DWORD * dwRxBytes, DWORD * dwTxBytes, DWORD * dwEventDWord)
{
	TRACE("(FT_HANDLE: %p,(DWORD *)%p,(DWORD *)%p,(DWORD *)%p) --> ",ftHandle,dwRxBytes,dwTxBytes,dwEventDWord);
//	FT_STATUS r = FT_GetStatus(ftHandle, dwRxBytes, dwTxBytes, dwEventDWord);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetBreakOn (FTD2XX.22)
 */
FT_STATUS __stdcall FTD2XX_FT_SetBreakOn(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_SetBreakOn(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetBreakOff (FTD2XX.23)
 */
FT_STATUS __stdcall FTD2XX_FT_SetBreakOff(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_SetBreakOff(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetWaitMask (FTD2XX.24)
 */
FT_STATUS __stdcall FTD2XX_FT_SetWaitMask(FT_HANDLE ftHandle, DWORD Mask)
{
	TRACE("(FT_HANDLE: %p,(DWORD)%d) --> ",ftHandle,(LONG)Mask);
//	FT_STATUS r = FT_SetWaitMask(ftHandle, Mask);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_WaitOnMask (FTD2XX.25)
 */
FT_STATUS __stdcall FTD2XX_FT_WaitOnMask(FT_HANDLE ftHandle, DWORD * Mask)
{
	TRACE("(FT_HANDLE: %p,(DWORD *)%p) --> ",ftHandle,Mask);
//	FT_STATUS r = FT_WaitOnMask(ftHandle, Mask);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetDivisor (FTD2XX.26)
 */
FT_STATUS __stdcall FTD2XX_FT_SetDivisor(FT_HANDLE ftHandle, USHORT Divisor)
{
	TRACE("(FT_HANDLE: %p,(USHORT)%u) --> ",ftHandle,(LONG)Divisor);
//	FT_STATUS r = FT_SetDivisor(ftHandle, Divisor);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_OpenEx (FTD2XX.27)
 */
FT_STATUS __stdcall FTD2XX_FT_OpenEx(PVOID pArg1, DWORD Flags, FT_HANDLE * pHandle)
{
	TRACE("(%s: %s, FT_Handle=%p) ",Flags==FT_OPEN_BY_SERIAL_NUMBER?"Serial":Flags==FT_OPEN_BY_DESCRIPTION?"Description":"?",(char*)pArg1,*pHandle);
//	FT_STATUS r = FT_OpenEx(pArg1, Flags, pHandle);
	FT_STATUS r = 17;
	TRACE("new fthandle: %p, status: %s\n",*pHandle,status[r]);
	return r;
}
/*
 * FT_ListDevices (FTD2XX.28)
 */
FT_STATUS __stdcall FTD2XX_FT_ListDevices(PVOID pArg1, PVOID pArg2, DWORD Flags)
{
	TRACE("((PVOID)%p,(PVOID)%p,(DWORD)%d): ",pArg1,pArg2,(LONG)Flags);
//	FT_STATUS r = FT_ListDevices(pArg1, pArg2, Flags);
	FT_STATUS r = 17;
	if(pArg1) TRACE("Arg1=%x ",*(DWORD*)pArg1);
	if(pArg2) TRACE("Arg2=%x ",*(DWORD*)pArg2);
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetLatencyTimer (FTD2XX.29)
 */
FT_STATUS __stdcall FTD2XX_FT_SetLatencyTimer(FT_HANDLE ftHandle, UCHAR ucLatency)
{
	TRACE("(FT_HANDLE: %p,(UCHAR)%u) --> ",ftHandle,(LONG)ucLatency);
	//FT_STATUS r = FT_SetLatencyTimer(ftHandle, ucLatency);
	FT_STATUS r = 0;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_GetLatencyTimer (FTD2XX.30)
 */
FT_STATUS __stdcall FTD2XX_FT_GetLatencyTimer(FT_HANDLE ftHandle, PUCHAR pucLatency)
{
	TRACE("(FT_HANDLE: %p,(PUCHAR)%s) --> ",ftHandle,pucLatency);
//	FT_STATUS r = FT_GetLatencyTimer(ftHandle, pucLatency);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetBitMode (FTD2XX.31)
 */
FT_STATUS __stdcall FTD2XX_FT_SetBitMode(FT_HANDLE ftHandle, UCHAR ucMask, UCHAR ucEnable)
{
	TRACE("(FT_HANDLE: %p,(UCHAR)%u,(UCHAR)%u) --> ",ftHandle,(LONG)ucMask,(LONG)ucEnable);
//	FT_STATUS r = FT_SetBitMode(ftHandle, ucMask, ucEnable);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_GetBitMode (FTD2XX.32)
 */
FT_STATUS __stdcall FTD2XX_FT_GetBitMode(FT_HANDLE ftHandle, PUCHAR pucMode)
{
	TRACE("(FT_HANDLE: %p,(PUCHAR)%s) --> ",ftHandle,pucMode);
//	FT_STATUS r = FT_GetBitMode(ftHandle, pucMode);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetUSBParameters (FTD2XX.33)
 */
FT_STATUS __stdcall FTD2XX_FT_SetUSBParameters(FT_HANDLE ftHandle, ULONG ulInTransferSize, ULONG ulOutTransferSize)
{
	TRACE("(FT_HANDLE: %p,(ULONG)%d,(ULONG)%d) --> ",ftHandle,(LONG)ulInTransferSize,(LONG)ulOutTransferSize);
//	FT_STATUS r = FT_SetUSBParameters(ftHandle, ulInTransferSize, ulOutTransferSize);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_EraseEE (FTD2XX.34)
 */
FT_STATUS __stdcall FTD2XX_FT_EraseEE(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_EraseEE(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_ReadEE (FTD2XX.35)
 */
FT_STATUS __stdcall FTD2XX_FT_ReadEE(FT_HANDLE ftHandle, DWORD dwWordOffset, LPWORD lpwValue)
{
	TRACE("(FT_HANDLE: %p,(DWORD)%d,(LPWORD)%p) --> ",ftHandle,(LONG)dwWordOffset,lpwValue);
//	FT_STATUS r = FT_ReadEE(ftHandle, dwWordOffset, lpwValue);
	FT_STATUS r = 17;
	TRACE("Value=%04x, status: %s\n",*lpwValue,status[r]);
	return r;
}
/*
 * FT_WriteEE (FTD2XX.36)
 */
FT_STATUS __stdcall FTD2XX_FT_WriteEE(FT_HANDLE ftHandle, DWORD dwWordOffset, WORD wValue)
{
	TRACE("(FT_HANDLE: %p,(DWORD)%d,(WORD)%d) --> ",ftHandle,(LONG)dwWordOffset,(LONG)wValue);
//	FT_STATUS r = FT_WriteEE(ftHandle, dwWordOffset, wValue);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_EE_Program (FTD2XX.37)
 */
FT_STATUS __stdcall FTD2XX_FT_EE_Program(FT_HANDLE ftHandle, PFT_PROGRAM_DATA pData)
{
	TRACE("(FT_HANDLE: %p,(PFT_PROGRAM_DATA)%p) --> ",ftHandle,pData);
//	FT_STATUS r = FT_EE_Program(ftHandle, pData);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_EE_Read (FTD2XX.38)
 */
FT_STATUS __stdcall FTD2XX_FT_EE_Read(FT_HANDLE ftHandle, PFT_PROGRAM_DATA pData)
{
	TRACE("(FT_HANDLE: %p,(PFT_PROGRAM_DATA)%p) --> ",ftHandle,pData);
//	FT_STATUS r = FT_EE_Read(ftHandle, pData);
	FT_STATUS r = 17;
	TRACE("%s,%s,%s,%s ",
		pData->Manufacturer,		// "FTDI"
		pData->ManufacturerId,		// "FT"
		pData->Description,		// "USB HS Serial Converter"
		pData->SerialNumber);		// "FT000001" if fixed, or NULL

	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_EE_UARead (FTD2XX.39)
 */
FT_STATUS __stdcall FTD2XX_FT_EE_UARead(FT_HANDLE ftHandle, PUCHAR pucData, DWORD dwDataLen, LPDWORD lpdwBytesRead)
{
	TRACE("(FT_HANDLE: %p,(PUCHAR)%s,(DWORD)%d,(LPDWORD)%p) --> ",ftHandle,pucData,(LONG)dwDataLen,lpdwBytesRead);
//	FT_STATUS r = FT_EE_UARead(ftHandle, pucData, dwDataLen, lpdwBytesRead);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_EE_UASize (FTD2XX.40)
 */
FT_STATUS __stdcall FTD2XX_FT_EE_UASize(FT_HANDLE ftHandle, LPDWORD lpdwSize)
{
	TRACE("(FT_HANDLE: %p,(LPDWORD)%p) --> ",ftHandle,lpdwSize);
//	FT_STATUS r = FT_EE_UASize(ftHandle, lpdwSize);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_EE_UAWrite (FTD2XX.41)
 */
FT_STATUS __stdcall FTD2XX_FT_EE_UAWrite(FT_HANDLE ftHandle, PUCHAR pucData, DWORD dwDataLen)
{
	TRACE("(FT_HANDLE: %p,(PUCHAR)%s,(DWORD)%d) --> ",ftHandle,pucData,(LONG)dwDataLen);
//	FT_STATUS r = FT_EE_UAWrite(ftHandle, pucData, dwDataLen);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_W32_CreateFile (FTD2XX.42)
 */
FT_HANDLE __stdcall FTD2XX_FT_W32_CreateFile(LPCSTR lpszName, DWORD dwAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreate, DWORD dwAttrsAndFlags, HANDLE hTemplate)
{
	FT_HANDLE r;
	TRACE("((LPCSTR)%s,(DWORD)%d,(DWORD)%d,(LPSECURITY_ATTRIBUTES)%p,(DWORD)%d,(DWORD)%d,(HANDLE)%p)\n",lpszName,(LONG)dwAccess,(LONG)dwShareMode,lpSecurityAttributes,(LONG)dwCreate,(LONG)dwAttrsAndFlags,hTemplate);
	//return FT_W32_CreateFile(lpszName, dwAccess, dwShareMode, lpSecurityAttributes, dwCreate, dwAttrsAndFlags, hTemplate);

	//r = FT_W32_CreateFile("OLIMEX MSP430 JTAG ISO", dwAccess, dwShareMode, lpSecurityAttributes, dwCreate, dwAttrsAndFlags-4+FT_OPEN_BY_DESCRIPTION, hTemplate);

	//TRACE("FT_HANDLE:  %x\n", r);
	//TRACE("FT_OK: %d\n", FT_OpenEx("OLIMEX MSP430 JTAG ISO",FT_OPEN_BY_DESCRIPTION,&r));
	//TRACE("FT_OK: %d\n", FT_OpenEx("030003DC",FT_OPEN_BY_SERIAL_NUMBER,&r));	

	//TRACE("FT_HANDLE:  %x %x %d %i\n", *r,r,OPEN_EXISTING,(FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED | FT_OPEN_BY_DESCRIPTION) & 0x0000FFFF);

	r = open("/dev/ttyUSB0", O_RDWR|O_NDELAY|O_NOCTTY);

	struct termios termp;

	tcgetattr(r, &termp);

	/* Modify the speed. */
	cfsetispeed(&termp, B38400);
	cfsetospeed(&termp, B38400);

	/* Now set 8n1. */
	termp.c_iflag = IGNBRK;
	termp.c_lflag = 0;
	termp.c_oflag = 0;
	termp.c_cflag = (termp.c_cflag & ~CSIZE) | CS8;	/* 8 data bits. */
	termp.c_cflag |= CLOCAL | CREAD;
	termp.c_cflag &= ~(PARENB|CSTOPB);		/* Clear. */
	termp.c_cflag &= ~(IXON|IXOFF|IXANY);		/* Clear. */
	termp.c_cc[VMIN] = 1;
	termp.c_cc[VTIME] = 5;


	struct serial_struct serial_info;

	serial_info.flags = ASYNC_SPD_CUST;
	serial_info.custom_divisor = 120;

	if ( ioctl( r, TIOCSSERIAL, &serial_info ) < 0)
	{
		perror("config_serial_port: ioctl TIOCSSERIAL");
		return(-1);
	}

	/* Now set all of this. */
	tcsetattr(r, TCSANOW, &termp);

	int flags;

	flags = fcntl( r, F_GETFL );
	flags |= O_NONBLOCK;

	fcntl( r, F_SETFL, flags );

	TRACE("FT_HANDLE:  %x\n", r);

	return r;
}
/*
 * FT_W32_CloseHandle (FTD2XX.43)
 */
BOOL __stdcall FTD2XX_FT_W32_CloseHandle(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
	//BOOL r = FT_W32_CloseHandle(ftHandle);
	BOOL r;
	if (close(ftHandle) == 0) r=TRUE;
	if (pRxBuf) free(pRxBuf);
	if (pTxBuf) free(pTxBuf);	
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_ReadFile (FTD2XX.44)
 */
BOOL __stdcall FTD2XX_FT_W32_ReadFile(FT_HANDLE ftHandle, LPVOID lpBuffer, DWORD nBufferSize, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped)
{
	TRACE("(FT_HANDLE: %p,(LPVOID)%p,(DWORD)%d,(LPDWORD)%p,(LPOVERLAPPED)%p) --> ",ftHandle,lpBuffer,(LONG)nBufferSize,lpBytesReturned,lpOverlapped);
	//FT_STATUS r = FT_W32_ReadFile(ftHandle, lpBuffer, nBufferSize, lpBytesReturned, lpOverlapped);

	FT_STATUS r = TRUE;

	char*buffer=malloc(nBufferSize*3+1);
	buffer[0]=0;

	int i;
	for (i=0;i<nBufferSize && i<rxSize;i++) {
		*((char*)lpBuffer+i) = RxBuf[i];
	}
	*lpBytesReturned=i;

	rxSize -= i;

	for (i=0;i<*lpBytesReturned && i<20;i++) {
		sprintf(buffer,"%s%02X ",buffer,*(unsigned char *)(lpBuffer+i));
	}

	TRACE("read: %d %s\n",*lpBytesReturned,buffer);

	free(buffer);

	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_WriteFile (FTD2XX.45)
 */
BOOL __stdcall FTD2XX_FT_W32_WriteFile(FT_HANDLE ftHandle, LPVOID lpBuffer, DWORD nBufferSize, LPDWORD lpBytesWritten, LPOVERLAPPED lpOverlapped)
{
	TRACE("(FT_HANDLE: %p,(LPVOID)%p,(DWORD)%d,(LPDWORD)%p,(LPOVERLAPPED)%p) --> ",ftHandle,lpBuffer,(LONG)nBufferSize,lpBytesWritten,lpOverlapped);
	//BOOL r = FT_W32_WriteFile(ftHandle, lpBuffer, nBufferSize, lpBytesWritten, lpOverlapped);
	/*
	BOOL r;
	if (FT_Write(ftHandle, lpBuffer, nBufferSize, lpBytesWritten) == FT_OK)
		r = TRUE;
	else
		r = FALSE; */

	BOOL r=TRUE;
	*lpBytesWritten=write(ftHandle, lpBuffer, nBufferSize);
	TRACE("status: %s %d %d\n",r ? "OK" : "FAIL",nBufferSize,*lpBytesWritten);

	
	char*buffer=malloc(nBufferSize*3+1);
	buffer[0]=0;
	int i;
	for (i=0;i<nBufferSize  && i < 20;i++) {
		sprintf(buffer,"%s%02X ",buffer,*(unsigned char *)(lpBuffer+i));
	}

	TRACE("write: %s\n",buffer);

	free(buffer);
	

	return r;
}
/*
 * FT_W32_GetOverlappedResult (FTD2XX.46)
 */
BOOL __stdcall FTD2XX_FT_W32_GetOverlappedResult(FT_HANDLE ftHandle, LPOVERLAPPED lpOverlapped, LPDWORD lpdwBytesTransferred, BOOL bWait)
{
	TRACE("(FT_HANDLE: %p,(LPOVERLAPPED)%p,(LPDWORD)%p,(BOOL)%d) --> ",ftHandle,lpOverlapped,lpdwBytesTransferred,(LONG)bWait);
//	BOOL r = FT_W32_GetOverlappedResult(ftHandle, lpOverlapped, lpdwBytesTransferred, bWait);
	BOOL r = FALSE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_ClearCommBreak (FTD2XX.47)
 */
BOOL __stdcall FTD2XX_FT_W32_ClearCommBreak(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	BOOL r = FT_W32_ClearCommBreak(ftHandle);
	BOOL r = FALSE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_ClearCommError (FTD2XX.48)
 */
BOOL __stdcall FTD2XX_FT_W32_ClearCommError(FT_HANDLE ftHandle, LPDWORD lpdwErrors, LPFTCOMSTAT lpftComstat)
{
	TRACE("(FT_HANDLE: %p,(LPDWORD)%p,(LPFTCOMSTAT)%p) --> ",ftHandle,lpdwErrors,lpftComstat);
	//BOOL r = FT_W32_ClearCommError(ftHandle, lpdwErrors, lpftComstat);

	/*
	typedef struct _FTCOMSTAT {
	    DWORD fCtsHold : 1;
	    DWORD fDsrHold : 1;
	    DWORD fRlsdHold : 1;
	    DWORD fXoffHold : 1;
	    DWORD fXoffSent : 1;
	    DWORD fEof : 1;
	    DWORD fTxim : 1;
	    DWORD fReserved : 25;
	    DWORD cbInQue;
	    DWORD cbOutQue;
	} FTCOMSTAT, *LPFTCOMSTAT;
	*/

	BOOL r = TRUE;

	if (read(ftHandle,RxBuf+rxSize,1) == 1) rxSize += 1;

	lpftComstat->fCtsHold = 0;
	lpftComstat->fDsrHold = 0;
	lpftComstat->fRlsdHold = 0;
	lpftComstat->fXoffHold = 0;
	lpftComstat->fXoffSent = 0;
	lpftComstat->fEof = 0;
	lpftComstat->fTxim = 0;
	lpftComstat->cbInQue = rxSize;
	lpftComstat->cbOutQue = 0;

	*lpdwErrors = 0;

	TRACE("errors: %d\n",*lpdwErrors);
	TRACE("comstat: %d %d %d %d %d %d %d %d %d\n",
		lpftComstat->fCtsHold,
		lpftComstat->fDsrHold,
		lpftComstat->fRlsdHold,
		lpftComstat->fXoffHold,
		lpftComstat->fXoffSent,
		lpftComstat->fEof,
		lpftComstat->fTxim,
		lpftComstat->cbInQue,
		lpftComstat->cbOutQue);
	TRACE("status: %s\n",r ? "OK" : "FAIL");

	//lpftComstat->cbInQue = 100;

	return r;
}
/*
 * FT_W32_EscapeCommFunction (FTD2XX.49)
 */
BOOL __stdcall FTD2XX_FT_W32_EscapeCommFunction(FT_HANDLE ftHandle, DWORD dwFunc)
{
	TRACE("(FT_HANDLE: %p,(DWORD)%d) --> ",ftHandle,(LONG)dwFunc);
//	BOOL r = FT_W32_EscapeCommFunction(ftHandle, dwFunc);
	BOOL r = FALSE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_GetCommModemStatus (FTD2XX.50)
 */
BOOL __stdcall FTD2XX_FT_W32_GetCommModemStatus(FT_HANDLE ftHandle, LPDWORD lpdwModemStatus)
{
	TRACE("(FT_HANDLE: %p,(LPDWORD)%p) --> ",ftHandle,lpdwModemStatus);
//	BOOL r = FT_W32_GetCommModemStatus(ftHandle, lpdwModemStatus);
	BOOL r = FALSE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_GetCommState (FTD2XX.51)
 */
BOOL __stdcall FTD2XX_FT_W32_GetCommState(FT_HANDLE ftHandle, LPFTDCB lpftDcb)
{
	TRACE("(FT_HANDLE: %p,(LPFTDCB)%p) --> ",ftHandle,lpftDcb);
	//BOOL r = FT_W32_GetCommState(ftHandle, lpftDcb);
	BOOL r = TRUE;	
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_GetCommTimeouts (FTD2XX.52)
 */
BOOL __stdcall FTD2XX_FT_W32_GetCommTimeouts(FT_HANDLE ftHandle, FTTIMEOUTS * pTimeouts)
{
	TRACE("(FT_HANDLE: %p,(FTTIMEOUTS *)%p) --> ",ftHandle,pTimeouts);
//	BOOL r = FT_W32_GetCommTimeouts(ftHandle, pTimeouts);
	BOOL r = FALSE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_GetLastError (FTD2XX.53)
 */
DWORD __stdcall FTD2XX_FT_W32_GetLastError(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	DWORD r = FT_W32_GetLastError(ftHandle);
	DWORD r = 0;
	TRACE("LastError: %u\n",r);
	return r;
}
/*
 * FT_W32_PurgeComm (FTD2XX.54)
 */
BOOL __stdcall FTD2XX_FT_W32_PurgeComm(FT_HANDLE ftHandle, DWORD dwMask)
{
	TRACE("(FT_HANDLE: %p,(DWORD)%d) --> ",ftHandle,(LONG)dwMask);
	//BOOL r = FT_W32_PurgeComm(ftHandle, dwMask);
	BOOL r = TRUE;
	if (dwMask & PURGE_TXCLEAR) txSize=0;
	if (dwMask & PURGE_RXCLEAR) rxSize=0;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_SetCommBreak (FTD2XX.55)
 */
BOOL __stdcall FTD2XX_FT_W32_SetCommBreak(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
	//BOOL r = FT_W32_SetCommBreak(ftHandle);
	BOOL r = TRUE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_SetCommMask (FTD2XX.56)
 */
BOOL __stdcall FTD2XX_FT_W32_SetCommMask(FT_HANDLE ftHandle, ULONG ulEventMask)
{
	TRACE("(FT_HANDLE: %p,(ULONG)%d) --> ",ftHandle,(LONG)ulEventMask);
	//BOOL r = FT_W32_SetCommMask(ftHandle, ulEventMask);
	BOOL r = TRUE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_SetCommState (FTD2XX.57)
 */
BOOL __stdcall FTD2XX_FT_W32_SetCommState(FT_HANDLE ftHandle, LPFTDCB lpftDcb)
{
	TRACE("(FT_HANDLE: %p,(LPFTDCB)%p) --> ",ftHandle,lpftDcb);
	//BOOL r = FT_W32_SetCommState(ftHandle, lpftDcb);
	BOOL r = TRUE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_SetCommTimeouts (FTD2XX.58)
 */
BOOL __stdcall FTD2XX_FT_W32_SetCommTimeouts(FT_HANDLE ftHandle, FTTIMEOUTS * pTimeouts)
{
	TRACE("(FT_HANDLE: %p,(FTTIMEOUTS *)%p) --> ",ftHandle,pTimeouts);
	//BOOL r = FT_W32_SetCommTimeouts(ftHandle, pTimeouts);
	BOOL r = TRUE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_SetupComm (FTD2XX.59)
 */
BOOL __stdcall FTD2XX_FT_W32_SetupComm(FT_HANDLE ftHandle, DWORD dwReadBufferSize, DWORD dwWriteBufferSize)
{
	TRACE("(FT_HANDLE: %p,(DWORD)%d,(DWORD)%d) --> ",ftHandle,(LONG)dwReadBufferSize,(LONG)dwWriteBufferSize);
	//BOOL r = FT_W32_SetupComm(ftHandle, dwReadBufferSize, dwWriteBufferSize);
	//pRxBuf = malloc(dwReadBufferSize);
	//pTxBuf = malloc(dwWriteBufferSize);
	BOOL r = TRUE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_W32_WaitCommEvent (FTD2XX.60)
 */
BOOL __stdcall FTD2XX_FT_W32_WaitCommEvent(FT_HANDLE ftHandle, PULONG pulEvent, LPOVERLAPPED lpOverlapped)
{
	TRACE("(FT_HANDLE: %p,(PULONG)%p,(LPOVERLAPPED)%p) --> ",ftHandle,pulEvent,lpOverlapped);
//	BOOL r = FT_W32_WaitCommEvent(ftHandle, pulEvent, lpOverlapped);
	BOOL r = FALSE;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_GetDeviceInfo (FTD2XX.61)
 */
FT_STATUS __stdcall FTD2XX_FT_GetDeviceInfo(FT_HANDLE ftHandle, FT_DEVICE * lpftDevice, LPDWORD lpdwID, PCHAR SerialNumber, PCHAR Description, LPVOID Dummy)
{
	TRACE("(FT_HANDLE: %p,(FT_DEVICE *)%p,(LPDWORD)%p,(PCHAR)%s,(PCHAR)%s,(LPVOID)%p) --> ",ftHandle,lpftDevice,lpdwID,SerialNumber,Description,Dummy);
//	FT_STATUS r = FT_GetDeviceInfo(ftHandle, lpftDevice, lpdwID, SerialNumber, Description, Dummy);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_W32_CancelIo (FTD2XX.62)
 */
BOOL __stdcall FTD2XX_FT_W32_CancelIo(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	BOOL r = FT_W32_CancelIo(ftHandle);
	BOOL r = FALSE;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_StopInTask (FTD2XX.63)
 */
FT_STATUS __stdcall FTD2XX_FT_StopInTask(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_StopInTask(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",r ? "OK" : "FAIL");
	return r;
}
/*
 * FT_RestartInTask (FTD2XX.64)
 */
FT_STATUS __stdcall FTD2XX_FT_RestartInTask(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_RestartInTask(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_SetResetPipeRetryCount (FTD2XX.65)
 */
FT_STATUS __stdcall FTD2XX_FT_SetResetPipeRetryCount(FT_HANDLE ftHandle, DWORD dwCount)
{
	TRACE("(FT_HANDLE: %p,(DWORD)%d) --> ",ftHandle,(LONG)dwCount);
//	FT_STATUS r = FT_SetResetPipeRetryCount(ftHandle, dwCount);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_ResetPort (FTD2XX.66)
 */
FT_STATUS __stdcall FTD2XX_FT_ResetPort(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_ResetPort(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_EE_ProgramEx (FTD2XX.67)
 */
FT_STATUS __stdcall FTD2XX_FT_EE_ProgramEx(FT_HANDLE ftHandle, PFT_PROGRAM_DATA lpData, char * Manufacturer, char * ManufacturerId, char * Description, char * SerialNumber)
{
	TRACE("(FT_HANDLE: %p,(PFT_PROGRAM_DATA)%p,(char *)%s,(char *)%s,(char *)%s,(char *)%s) --> ",ftHandle,lpData,Manufacturer,ManufacturerId,Description,SerialNumber);
//	FT_STATUS r = FT_EE_ProgramEx(ftHandle, lpData, Manufacturer, ManufacturerId, Description, SerialNumber);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_EE_ReadEx (FTD2XX.68)
 */
FT_STATUS __stdcall FTD2XX_FT_EE_ReadEx(FT_HANDLE ftHandle, PFT_PROGRAM_DATA lpData, char * Manufacturer, char * ManufacturerId, char * Description, char * SerialNumber)
{
	TRACE("(FT_HANDLE: %p,(PFT_PROGRAM_DATA)%p,(char *)%s,(char *)%s,(char *)%s,(char *)%s) --> ",ftHandle,lpData,Manufacturer,ManufacturerId,Description,SerialNumber);
//	FT_STATUS r = FT_EE_ReadEx(ftHandle, lpData, Manufacturer, ManufacturerId, Description, SerialNumber);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_CyclePort (FTD2XX.69)
 */
FT_STATUS __stdcall FTD2XX_FT_CyclePort(FT_HANDLE ftHandle)
{
	TRACE("FT_HANDLE: %p --> ",ftHandle);
//	FT_STATUS r = FT_CyclePort(ftHandle);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
/*
 * FT_CreateDeviceInfoList (FTD2XX.70)
 */
FT_STATUS __stdcall FTD2XX_FT_CreateDeviceInfoList(LPDWORD lpdwNumDevs)
{
	//FT_STATUS r = FT_CreateDeviceInfoList(lpdwNumDevs);
	FT_STATUS r = 0;
#ifdef JTAGISO
	*lpdwNumDevs = 1;
#else
	*lpdwNumDevs = 0;
#endif
	TRACE("lpdwNumDevs = %u, status: %s\n", *lpdwNumDevs, status[r]);
	return r;
}
/*
 * FT_GetDeviceInfoList (FTD2XX.71)
 */
FT_STATUS __stdcall FTD2XX_FT_GetDeviceInfoList(FT_DEVICE_LIST_INFO_NODE * pDest, LPDWORD lpdwNumDevs)
{
	//FT_STATUS r = FT_GetDeviceInfoList(pDest, lpdwNumDevs);
#if 1
	FT_STATUS r = 0;
	*lpdwNumDevs = 1;
	pDest[0].Flags=0;
	pDest[0].Type=5;
	pDest[0].ID=364511240;
	pDest[0].LocId=0;
	memcpy(pDest[0].SerialNumber,"030003DC",9);
	memcpy(pDest[0].Description,"OLIMEX MSP430 JTAG ISO",23);
	pDest[0].ftHandle = 0;
	
	TRACE("(FT_DEVICE_LIST_INFO_NODE *)%p, lpdwNumDevs = %u, status: %s\n", pDest, *lpdwNumDevs, status[r]);
	TRACE("aa:  %ld %ld %ld %d\n", pDest[0].Flags, pDest[0].Type, pDest[0].ID, pDest[0].LocId);
	TRACE("SerialNumber: %s\n", pDest[0].SerialNumber);
	TRACE("Description:  %s\n", pDest[0].Description);
#else
	FT_STATUS r = 0;
	*lpdwNumDevs = 0;	/* no device found */

	TRACE("(FT_DEVICE_LIST_INFO_NODE *)%p, lpdwNumDevs = %u, status: %s\n", pDest, *lpdwNumDevs, status[r]);
#endif /* JTAGISO */
	return r;
}
/*
 * FT_GetDeviceInfoDetail (FTD2XX.72)
 */
FT_STATUS __stdcall FTD2XX_FT_GetDeviceInfoDetail(DWORD dwIndex, LPDWORD lpdwFlags, LPDWORD lpdwType, LPDWORD lpdwID, LPDWORD lpdwLocId, LPVOID lpSerialNumber, LPVOID lpDescription, FT_HANDLE * pftHandle)
{
//	FT_STATUS r = FT_GetDeviceInfoDetail(dwIndex, lpdwFlags, lpdwType, lpdwID, lpdwLocId, lpSerialNumber, lpDescription, pftHandle);
	FT_STATUS r = 17;

	TRACE("(dwIndex=%u) --> Flags=%x, Type=%u, ID=%08x, LocId=%x, SerialNumber=\"%s\", Description=\"%s\", ftHandle=%p, status: %s\n",dwIndex,*lpdwFlags,*lpdwType,*lpdwID,*lpdwLocId,(char*)lpSerialNumber,(char*)lpDescription,*pftHandle,status[r]);
	return r;
}
/*
 * FT_SetDeadmanTimeout (FTD2XX.73)
 */
FT_STATUS __stdcall FTD2XX_FT_SetDeadmanTimeout(FT_HANDLE ftHandle, ULONG ulDeadmanTimeout)
{
	TRACE("(FT_HANDLE: %p,(ULONG)%d) --> ",ftHandle,(LONG)ulDeadmanTimeout);
//	FT_STATUS r = FT_SetDeadmanTimeout(ftHandle, ulDeadmanTimeout);
	FT_STATUS r = 17;
	TRACE("status: %s\n",status[r]);
	return r;
}
