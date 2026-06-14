/* MSPDebug - debugging tool for MSP430 MCUs
 * Copyright (C) 2009-2015 Daniel Beer
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef TILIB_API_H_
#define TILIB_API_H_

#include "tilib_defs.h"

struct tilib_api_table {
	/* MSP430.h */
	STATUS_T (*MSP430_Initialize)(char *port, int32_t *version);
	STATUS_T (*MSP430_VCC)(int32_t voltage);
	STATUS_T (*MSP430_Configure)(int32_t mode, int32_t value);
	STATUS_T (*MSP430_OpenDevice)(char *Device, char *Password,
	                              int32_t PwLength, int32_t DeviceCode,
	                              int32_t setId);
	STATUS_T (*MSP430_GetFoundDevice)(char *FoundDevice, int32_t count);
	STATUS_T (*MSP430_Close)(int32_t vccOff);
	STATUS_T (*MSP430_Memory)(int32_t address, char *buffer,
	                          int32_t count, int32_t rw);
	STATUS_T (*MSP430_Reset)(int32_t method, int32_t execute,
	                         int32_t releaseJTAG);
	STATUS_T (*MSP430_Erase)(int32_t type, int32_t address, int32_t length);
	STATUS_T (*MSP430_Secure)(void);
	STATUS_T (*MSP430_Error_Number)(void);
	const char *(*MSP430_Error_String)(int32_t errNumber);
	
	STATUS_T (*MSP430_GetNumberOfUsbIfs)(int32_t* number);
	STATUS_T (*MSP430_GetNameOfUsbIf)(int32_t idx, char **name,
	                                  int32_t *status);
	
	/* MSP430_Debug.h */
	STATUS_T (*MSP430_Registers)(int32_t *registers, int32_t mask,
	                             int32_t rw);
	STATUS_T (*MSP430_Run)(int32_t mode, int32_t releaseJTAG);
	STATUS_T (*MSP430_State)(int32_t *state, int32_t stop,
	                         int32_t *pCPUCycles);
	
	/* MSP430_EEM.h */
	STATUS_T (*MSP430_EEM_Init)(DLL430_EVENTNOTIFY_FUNC callback,
	                            int32_t clientHandle,
	                            MessageID_t *pMsgIdBuffer);
	STATUS_T (*MSP430_EEM_SetBreakpoint)(uint16_t *pwBpHandle,
	                                     BpParameter_t *pBpBuffer);
	
	/* MSP430_FET.h */
	STATUS_T (*MSP430_FET_FwUpdate)(char* lpszFileName,
	                                DLL430_FET_NOTIFY_FUNC callback,
	                                int32_t clientHandle);
};

extern const struct tilib_api_table *tilib_api;

int tilib_api_init(void);
void tilib_api_exit(void);

#endif
