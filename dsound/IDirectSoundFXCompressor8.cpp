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
*
* Code taken from code found here: https://github.com/elishacloud/DirectSoundControl
*/

#include "dsound.h"

HRESULT m_IDirectSoundFXCompressor8::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	HRESULT hr = ProxyInterface->QueryInterface(riid, ppvObj);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppvObj);
	}

	return hr;
}

ULONG m_IDirectSoundFXCompressor8::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectSoundFXCompressor8::Release()
{
	ULONG x = ProxyInterface->Release();

	if (x == 0)
	{
		ProxyAddressLookupTable.DeleteAddress(this);

		delete this;
	}

	return x;
}

// IDirectSoundFXCompressor methods
HRESULT m_IDirectSoundFXCompressor8::SetAllParameters(LPCDSFXCompressor pcDsFxCompressor)
{
	return ProxyInterface->SetAllParameters(pcDsFxCompressor);
}

HRESULT m_IDirectSoundFXCompressor8::GetAllParameters(LPDSFXCompressor pDsFxCompressor)
{
	return ProxyInterface->GetAllParameters(pDsFxCompressor);
}
