# Generated from ftd2xx.dll by winedump

1 stdcall FT_Open( long ptr ) FTD2XX_FT_Open
2 stdcall FT_Close( long ) FTD2XX_FT_Close
3 stdcall FT_Read( long ptr long ptr ) FTD2XX_FT_Read
4 stdcall FT_Write( long ptr long ptr ) FTD2XX_FT_Write
5 stdcall FT_IoCtl( long long ptr long ptr long ptr ptr ) FTD2XX_FT_IoCtl
6 stdcall FT_ResetDevice( long ) FTD2XX_FT_ResetDevice
7 stdcall FT_SetBaudRate( long long ) FTD2XX_FT_SetBaudRate
8 stdcall FT_SetDataCharacteristics( long long long long ) FTD2XX_FT_SetDataCharacteristics
9 stdcall FT_SetFlowControl( long long long long ) FTD2XX_FT_SetFlowControl
10 stdcall FT_SetDtr( long ) FTD2XX_FT_SetDtr
11 stdcall FT_ClrDtr( long ) FTD2XX_FT_ClrDtr
12 stdcall FT_SetRts( long ) FTD2XX_FT_SetRts
13 stdcall FT_ClrRts( long ) FTD2XX_FT_ClrRts
14 stdcall FT_GetModemStatus( long ptr ) FTD2XX_FT_GetModemStatus
15 stdcall FT_SetChars( long long long long long ) FTD2XX_FT_SetChars
16 stdcall FT_Purge( long long ) FTD2XX_FT_Purge
17 stdcall FT_SetTimeouts( long long long ) FTD2XX_FT_SetTimeouts
18 stdcall FT_GetQueueStatus( long ptr ) FTD2XX_FT_GetQueueStatus
19 stdcall FT_SetEventNotification( long long ptr ) FTD2XX_FT_SetEventNotification
20 stdcall FT_GetEventStatus( long ptr ) FTD2XX_FT_GetEventStatus
21 stdcall FT_GetStatus( long ptr ptr ptr ) FTD2XX_FT_GetStatus
22 stdcall FT_SetBreakOn( long ) FTD2XX_FT_SetBreakOn
23 stdcall FT_SetBreakOff( long ) FTD2XX_FT_SetBreakOff
24 stdcall FT_SetWaitMask( long long ) FTD2XX_FT_SetWaitMask
25 stdcall FT_WaitOnMask( long ptr ) FTD2XX_FT_WaitOnMask
26 stdcall FT_SetDivisor( long long ) FTD2XX_FT_SetDivisor
27 stdcall FT_OpenEx( ptr long ptr ) FTD2XX_FT_OpenEx
28 stdcall FT_ListDevices( ptr ptr long ) FTD2XX_FT_ListDevices
29 stdcall FT_SetLatencyTimer( long long ) FTD2XX_FT_SetLatencyTimer
30 stdcall FT_GetLatencyTimer( long str ) FTD2XX_FT_GetLatencyTimer
31 stdcall FT_SetBitMode( long long long ) FTD2XX_FT_SetBitMode
32 stdcall FT_GetBitMode( long str ) FTD2XX_FT_GetBitMode
33 stdcall FT_SetUSBParameters( long long long ) FTD2XX_FT_SetUSBParameters
34 stdcall FT_EraseEE( long ) FTD2XX_FT_EraseEE
35 stdcall FT_ReadEE( long long ptr ) FTD2XX_FT_ReadEE
36 stdcall FT_WriteEE( long long long ) FTD2XX_FT_WriteEE
37 stdcall FT_EE_Program( long ptr ) FTD2XX_FT_EE_Program
38 stdcall FT_EE_Read( long ptr ) FTD2XX_FT_EE_Read
39 stdcall FT_EE_UARead( long str long ptr ) FTD2XX_FT_EE_UARead
40 stdcall FT_EE_UASize( long ptr ) FTD2XX_FT_EE_UASize
41 stdcall FT_EE_UAWrite( long str long ) FTD2XX_FT_EE_UAWrite
42 stdcall FT_W32_CreateFile( str long long ptr long long ptr ) FTD2XX_FT_W32_CreateFile
43 stdcall FT_W32_CloseHandle( long ) FTD2XX_FT_W32_CloseHandle
44 stdcall FT_W32_ReadFile( long ptr long ptr ptr ) FTD2XX_FT_W32_ReadFile
45 stdcall FT_W32_WriteFile( long ptr long ptr ptr ) FTD2XX_FT_W32_WriteFile
46 stdcall FT_W32_GetOverlappedResult( long ptr ptr long ) FTD2XX_FT_W32_GetOverlappedResult
47 stdcall FT_W32_ClearCommBreak( long ) FTD2XX_FT_W32_ClearCommBreak
48 stdcall FT_W32_ClearCommError( long ptr ptr ) FTD2XX_FT_W32_ClearCommError
49 stdcall FT_W32_EscapeCommFunction( long long ) FTD2XX_FT_W32_EscapeCommFunction
50 stdcall FT_W32_GetCommModemStatus( long ptr ) FTD2XX_FT_W32_GetCommModemStatus
51 stdcall FT_W32_GetCommState( long ptr ) FTD2XX_FT_W32_GetCommState
52 stdcall FT_W32_GetCommTimeouts( long ptr ) FTD2XX_FT_W32_GetCommTimeouts
53 stdcall FT_W32_GetLastError( long ) FTD2XX_FT_W32_GetLastError
54 stdcall FT_W32_PurgeComm( long long ) FTD2XX_FT_W32_PurgeComm
55 stdcall FT_W32_SetCommBreak( long ) FTD2XX_FT_W32_SetCommBreak
56 stdcall FT_W32_SetCommMask( long long ) FTD2XX_FT_W32_SetCommMask
57 stdcall FT_W32_SetCommState( long ptr ) FTD2XX_FT_W32_SetCommState
58 stdcall FT_W32_SetCommTimeouts( long ptr ) FTD2XX_FT_W32_SetCommTimeouts
59 stdcall FT_W32_SetupComm( long long long ) FTD2XX_FT_W32_SetupComm
60 stdcall FT_W32_WaitCommEvent( long ptr ptr ) FTD2XX_FT_W32_WaitCommEvent
61 stdcall FT_GetDeviceInfo( long ptr ptr str str ptr ) FTD2XX_FT_GetDeviceInfo
62 stdcall FT_W32_CancelIo( long ) FTD2XX_FT_W32_CancelIo
63 stdcall FT_StopInTask( long ) FTD2XX_FT_StopInTask
64 stdcall FT_RestartInTask( long ) FTD2XX_FT_RestartInTask
65 stdcall FT_SetResetPipeRetryCount( long long ) FTD2XX_FT_SetResetPipeRetryCount
66 stdcall FT_ResetPort( long ) FTD2XX_FT_ResetPort
67 stdcall FT_EE_ProgramEx( long ptr str str str str ) FTD2XX_FT_EE_ProgramEx
68 stdcall FT_EE_ReadEx( long ptr str str str str ) FTD2XX_FT_EE_ReadEx
69 stdcall FT_CyclePort( long ) FTD2XX_FT_CyclePort
70 stdcall FT_CreateDeviceInfoList( ptr ) FTD2XX_FT_CreateDeviceInfoList
71 stdcall FT_GetDeviceInfoList( ptr ptr ) FTD2XX_FT_GetDeviceInfoList
72 stdcall FT_GetDeviceInfoDetail( long ptr ptr ptr ptr ptr ptr ptr ) FTD2XX_FT_GetDeviceInfoDetail
73 stdcall FT_SetDeadmanTimeout( long long ) FTD2XX_FT_SetDeadmanTimeout
