/*
 * Copyright (C) 2021-2026 ASHINi Corp. 
 * 
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public 
 * License as published by the Free Software Foundation; either 
 * version 3 of the License, or any later version. 
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public 
 * License along with this program. If not, see <https://www.gnu.org/licenses/>.   
 *  
 * 
 */

//---------------------------------------------------------------------------

#ifndef HostToAddrUtilH
#define HostToAddrUtilH
//---------------------------------------------------------------------------

class CHostToAddrUtil
{

public:
	BOOL					IsIdlePort(UINT32 nPort, DWORD& dwWsaError);
	LPCTSTR					ConvertHostToAddr(LPCTSTR lpHost, LPTSTR lpAddr, INT32 nAddrLen);

public:
	CHostToAddrUtil();
    ~CHostToAddrUtil();

private:
	BOOL					m_bInitWinSock;

	// Do not call out of class
	void					InitWinSock();
	void					UnInitWinSock();
	// End of 
};

extern CHostToAddrUtil*		t_HostToAddrUtil;

#endif
