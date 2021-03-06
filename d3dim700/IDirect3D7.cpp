/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "d3dim700.h"

HRESULT m_IDirect3D7::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	HRESULT hr = ProxyInterface->QueryInterface(riid, ppvObj);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppvObj);
	}

	return hr;
}

ULONG m_IDirect3D7::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirect3D7::Release()
{
	ULONG x = ProxyInterface->Release();

	if (x == 0)
	{
		ProxyAddressLookupTable.DeleteAddress(this);

		delete this;
	}

	return x;
}

HRESULT m_IDirect3D7::EnumDevices(LPD3DENUMDEVICESCALLBACK7 a, LPVOID b)
{
	return ProxyInterface->EnumDevices(a, b);
}

HRESULT m_IDirect3D7::CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE7 b, LPDIRECT3DDEVICE7 * c)
{
	if (b)
	{
		b = static_cast<m_IDirectDrawSurface7 *>(b)->GetProxyInterface();
	}

	HRESULT hr = ProxyInterface->CreateDevice(a, b, c);

	if (SUCCEEDED(hr))
	{
		*c = ProxyAddressLookupTable.FindAddress<m_IDirect3DDevice7>(*c);
	}

	return hr;
}

HRESULT m_IDirect3D7::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC a, LPDIRECT3DVERTEXBUFFER7 * b, DWORD c)
{
	HRESULT hr = ProxyInterface->CreateVertexBuffer(a, b, c);

	if (SUCCEEDED(hr))
	{
		*b = ProxyAddressLookupTable.FindAddress<m_IDirect3DVertexBuffer7>(*b);
	}

	return hr;
}

HRESULT m_IDirect3D7::EnumZBufferFormats(REFCLSID a, LPD3DENUMPIXELFORMATSCALLBACK b, LPVOID c)
{
	return ProxyInterface->EnumZBufferFormats(a, b, c);
}

HRESULT m_IDirect3D7::EvictManagedTextures()
{
	return ProxyInterface->EvictManagedTextures();
}
