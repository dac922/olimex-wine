/*
 * SiUSBXp.dll
 *
 * Generated from SiUSBXp.dll by winedump.
 *
 * DO NOT SUBMIT GENERATED DLLS FOR INCLUSION INTO WINE!
 *
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
#include "SiUSBXp_dll.h"

WINE_DEFAULT_DEBUG_CHANNEL(siusbxp);


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
            //DisableThreadLibraryCalls(hinstDLL);
            break;
        case DLL_PROCESS_DETACH:
			if (pRxBuf) free(pRxBuf);
			if (pTxBuf) free(pTxBuf);
            break;
    }

    return TRUE;
}
/******************************************************************
 *		SI_GetNumDevices (SIUSBXP.1)
 *
 *
 * PARAMS
 *
 *  lpdwNumDevices [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_GetNumDevices(LPDWORD lpdwNumDevices)
{
	TRACE("((LPDWORD)%p): stub\n",lpdwNumDevices);
#ifdef JTAGTINY
	*lpdwNumDevices = 1;
#else
	*lpdwNumDevices = 0;
#endif /* JTAGTINY */
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_GetProductString (SIUSBXP.2)
 *
 *
 * PARAMS
 *
 *  dwDeviceNum [In]
 *  lpvDeviceString [In/Out]
 *  dwFlags [In]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_GetProductString(DWORD dwDeviceNum, LPVOID lpvDeviceString, DWORD dwFlags)
{
	TRACE("((DWORD)%ld,(LPVOID)%p,(DWORD)%ld): stub\n",(LONG)dwDeviceNum,lpvDeviceString,(LONG)dwFlags);
	switch (dwFlags) {

	case SI_RETURN_SERIAL_NUMBER:
		memcpy(lpvDeviceString,"030006B4",9);
		break;

	case SI_RETURN_DESCRIPTION:
		memcpy(lpvDeviceString,"MSP430 JTAG Tiny ",18);
		break;	

	case SI_RETURN_LINK_NAME:
		memcpy(lpvDeviceString,"???",4);
		break;

	default:
	case SI_RETURN_VID:
	case SI_RETURN_PID:
		break;

	}

	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_Open (SIUSBXP.3)
 *
 *
 * PARAMS
 *
 *  dwDevice [In]
 *  cyHandle [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_Open(DWORD dwDevice, HANDLE * cyHandle)
{
	TRACE("((DWORD)%ld,(HANDLE *)%p): stub\n",(LONG)dwDevice,cyHandle);
	
	*cyHandle = open("/dev/ttyUSB0", O_RDWR|O_NDELAY|O_NOCTTY);

	struct termios termp;

	tcgetattr(*cyHandle, &termp);

	/* Modify the speed. */
	cfsetispeed(&termp, B500000);
	cfsetospeed(&termp, B500000);

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

	/* Now set all of this. */
	tcsetattr(*cyHandle, TCSANOW, &termp);

	int flags;

	flags = fcntl( *cyHandle, F_GETFL );
	flags |= O_NONBLOCK;

	fcntl( *cyHandle, F_SETFL, flags );

	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_Close (SIUSBXP.4)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_Close(HANDLE cyHandle)
{
	TRACE("((HANDLE)%p): stub\n",cyHandle);
	close(cyHandle);

	return (SI_STATUS) 0;
}
/******************************************************************
 *		?SI_ResetDevice@@YGHPAX@Z (SIUSBXP.5)
 *
 *
 * PARAMS
 *
 *  arg0 [In/Out]
 *
 * RETURNS
 *
 *  int
 *
 */
/*
int __stdcall SIUSBXP_global_SI_ResetDevice_5(void * arg0)
{
	TRACE("((void *)%p): stub\n",arg0);
	return (int) 0;
}
*/
/******************************************************************
 *		SI_Read (SIUSBXP.6)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  lpBuffer [In/Out]
 *  dwBytesToRead [In]
 *  lpdwBytesReturned [In/Out]
 *  o [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_Read(HANDLE cyHandle, LPVOID lpBuffer, DWORD dwBytesToRead, LPDWORD lpdwBytesReturned, OVERLAPPED * o)
{
	TRACE("((HANDLE)%p,(LPVOID)%p,(DWORD)%ld,(LPDWORD)%p,(OVERLAPPED *)%p): stub\n",cyHandle,lpBuffer,(LONG)dwBytesToRead,lpdwBytesReturned,o);

	char*buffer=malloc(dwBytesToRead*3+1);
	buffer[0]=0;

	int i;
	for (i=0;i<dwBytesToRead && i<rxSize;i++) {
		*((char*)lpBuffer+i) = RxBuf[i];
	}
	*lpdwBytesReturned=i;

	rxSize -= i;

	for (i=0;i<*lpdwBytesReturned && i<20;i++) {
		sprintf(buffer,"%s%02X ",buffer,*(unsigned char *)(lpBuffer+i));
	}

	TRACE("read: %d %s\n",*lpdwBytesReturned,buffer);

	free(buffer);


	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_Write (SIUSBXP.7)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  lpBuffer [In/Out]
 *  dwBytesToWrite [In]
 *  lpdwBytesWritten [In/Out]
 *  o [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_Write(HANDLE cyHandle, LPVOID lpBuffer, DWORD dwBytesToWrite, LPDWORD lpdwBytesWritten, OVERLAPPED * o)
{
	TRACE("((HANDLE)%p,(LPVOID)%p,(DWORD)%ld,(LPDWORD)%p,(OVERLAPPED *)%p): stub\n",cyHandle,lpBuffer,(LONG)dwBytesToWrite,lpdwBytesWritten,o);

	*lpdwBytesWritten=write(cyHandle, lpBuffer, dwBytesToWrite);
	
	char*buffer=malloc(dwBytesToWrite*3+1);
	buffer[0]=0;
	int i;
	for (i=0;i<dwBytesToWrite  && i < 20;i++) {
		sprintf(buffer,"%s%02X ",buffer,*(unsigned char *)(lpBuffer+i));
	}

	TRACE("write: %s\n",buffer);

	free(buffer);
	

	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_DeviceIOControl (SIUSBXP.8)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  dwIoControlCode [In]
 *  lpInBuffer [In/Out]
 *  dwBytesToRead [In]
 *  lpOutBuffer [In/Out]
 *  dwBytesToWrite [In]
 *  lpdwBytesSucceeded [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_DeviceIOControl(HANDLE cyHandle, DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD dwBytesToRead, LPVOID lpOutBuffer, DWORD dwBytesToWrite, LPDWORD lpdwBytesSucceeded)
{
	TRACE("((HANDLE)%p,(DWORD)%ld,(LPVOID)%p,(DWORD)%ld,(LPVOID)%p,(DWORD)%ld,(LPDWORD)%p): stub\n",cyHandle,(LONG)dwIoControlCode,lpInBuffer,(LONG)dwBytesToRead,lpOutBuffer,(LONG)dwBytesToWrite,lpdwBytesSucceeded);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_FlushBuffers (SIUSBXP.9)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  FlushTransmit [In]
 *  FlushReceive [In]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_FlushBuffers(HANDLE cyHandle, BYTE FlushTransmit, BYTE FlushReceive)
{
	TRACE("((HANDLE)%p,(BYTE)%ld,(BYTE)%ld): stub\n",cyHandle,(LONG)FlushTransmit,(LONG)FlushReceive);
	if (FlushTransmit) txSize=0;
	if (FlushReceive) rxSize=0;
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_SetTimeouts (SIUSBXP.10)
 *
 *
 * PARAMS
 *
 *  dwReadTimeout [In]
 *  dwWriteTimeout [In]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_SetTimeouts(DWORD dwReadTimeout, DWORD dwWriteTimeout)
{
	TRACE("((DWORD)%ld,(DWORD)%ld): stub\n",(LONG)dwReadTimeout,(LONG)dwWriteTimeout);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_GetTimeouts (SIUSBXP.11)
 *
 *
 * PARAMS
 *
 *  lpdwReadTimeout [In/Out]
 *  lpdwWriteTimeout [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_GetTimeouts(LPDWORD lpdwReadTimeout, LPDWORD lpdwWriteTimeout)
{
	TRACE("((LPDWORD)%p,(LPDWORD)%p): stub\n",lpdwReadTimeout,lpdwWriteTimeout);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_CheckRXQueue (SIUSBXP.12)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  lpdwNumBytesInQueue [In/Out]
 *  lpdwQueueStatus [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_CheckRXQueue(HANDLE cyHandle, LPDWORD lpdwNumBytesInQueue, LPDWORD lpdwQueueStatus)
{
	TRACE("((HANDLE)%p,(LPDWORD)%p,(LPDWORD)%p): stub\n",cyHandle,lpdwNumBytesInQueue,lpdwQueueStatus);

	if (read(cyHandle,RxBuf+rxSize,1) == 1) rxSize += 1;
	*lpdwNumBytesInQueue = rxSize;

	if (rxSize == 0) *lpdwQueueStatus = SI_RX_EMPTY;
	else if (rxSize > 2048) *lpdwQueueStatus = SI_RX_OVERRUN;
	else *lpdwQueueStatus = SI_RX_READY;

	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_SetBaudRate (SIUSBXP.13)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  dwBaudRate [In]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_SetBaudRate(HANDLE cyHandle, DWORD dwBaudRate)
{
	TRACE("((HANDLE)%p,(DWORD)%ld): stub\n",cyHandle,(LONG)dwBaudRate);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_SetBaudDivisor (SIUSBXP.14)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  wBaudDivisor [In]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_SetBaudDivisor(HANDLE cyHandle, WORD wBaudDivisor)
{
	TRACE("((HANDLE)%p,(WORD)%ld): stub\n",cyHandle,(LONG)wBaudDivisor);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_SetLineControl (SIUSBXP.15)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  wLineControl [In]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_SetLineControl(HANDLE cyHandle, WORD wLineControl)
{
	TRACE("((HANDLE)%p,(WORD)%ld): stub\n",cyHandle,(LONG)wLineControl);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_SetFlowControl (SIUSBXP.16)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  bCTS_MaskCode [In]
 *  bRTS_MaskCode [In]
 *  bDTR_MaskCode [In]
 *  bDSR_MaskCode [In]
 *  bDCD_MaskCode [In]
 *  bFlowXonXoff [In]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_SetFlowControl(HANDLE cyHandle, BYTE bCTS_MaskCode, BYTE bRTS_MaskCode, BYTE bDTR_MaskCode, BYTE bDSR_MaskCode, BYTE bDCD_MaskCode, BOOL bFlowXonXoff)
{
	TRACE("((HANDLE)%p,(BYTE)%ld,(BYTE)%ld,(BYTE)%ld,(BYTE)%ld,(BYTE)%ld,(BOOL)%ld): stub\n",cyHandle,(LONG)bCTS_MaskCode,(LONG)bRTS_MaskCode,(LONG)bDTR_MaskCode,(LONG)bDSR_MaskCode,(LONG)bDCD_MaskCode,(LONG)bFlowXonXoff);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_GetModemStatus (SIUSBXP.17)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  ModemStatus [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_GetModemStatus(HANDLE cyHandle, PBYTE ModemStatus)
{
	TRACE("((HANDLE)%p,(PBYTE)%p): stub\n",cyHandle,ModemStatus);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_SetBreak (SIUSBXP.18)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  wBreakState [In]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_SetBreak(HANDLE cyHandle, WORD wBreakState)
{
	TRACE("((HANDLE)%p,(WORD)%ld): stub\n",cyHandle,(LONG)wBreakState);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_ReadLatch (SIUSBXP.19)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  lpbLatch [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_ReadLatch(HANDLE cyHandle, LPBYTE lpbLatch)
{
	TRACE("((HANDLE)%p,(LPBYTE)%p): stub\n",cyHandle,lpbLatch);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_WriteLatch (SIUSBXP.20)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  bMask [In]
 *  bLatch [In]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_WriteLatch(HANDLE cyHandle, BYTE bMask, BYTE bLatch)
{
	TRACE("((HANDLE)%p,(BYTE)%ld,(BYTE)%ld): stub\n",cyHandle,(LONG)bMask,(LONG)bLatch);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_GetPartNumber (SIUSBXP.21)
 *
 *
 * PARAMS
 *
 *  cyHandle [In/Out]
 *  lpbPartNum [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_GetPartNumber(HANDLE cyHandle, LPBYTE lpbPartNum)
{
	TRACE("((HANDLE)%p,(LPBYTE)%p): stub\n",cyHandle,lpbPartNum);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_GetDLLVersion (SIUSBXP.22)
 *
 *
 * PARAMS
 *
 *  HighVersion [In/Out]
 *  LowVersion [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_GetDLLVersion(DWORD * HighVersion, DWORD * LowVersion)
{
	TRACE("((DWORD *)%p,(DWORD *)%p): stub\n",HighVersion,LowVersion);
	return (SI_STATUS) 0;
}
/******************************************************************
 *		SI_GetDriverVersion (SIUSBXP.23)
 *
 *
 * PARAMS
 *
 *  HighVersion [In/Out]
 *  LowVersion [In/Out]
 *
 * RETURNS
 *
 *  SI_STATUS
 *
 */
SI_STATUS __stdcall SIUSBXP_SI_GetDriverVersion(DWORD * HighVersion, DWORD * LowVersion)
{
	TRACE("((DWORD *)%p,(DWORD *)%p): stub\n",HighVersion,LowVersion);
	return (SI_STATUS) 0;
}
