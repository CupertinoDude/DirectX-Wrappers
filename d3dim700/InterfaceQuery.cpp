#include "d3dim700.h"

void genericQueryInterface(REFIID riid, LPVOID * ppvObj)
{
#define QUERYINTERFACE(x) \
	if (riid == IID_ ## x) \
		{ \
			*ppvObj = ProxyAddressLookupTable.FindAddress<m_ ## x>(*ppvObj); \
		}

	//QUERYINTERFACE(IDirect3D);
	//QUERYINTERFACE(IDirect3D2);
	//QUERYINTERFACE(IDirect3D3);
	QUERYINTERFACE(IDirect3D7);
	//QUERYINTERFACE(IDirect3DDevice);
	//QUERYINTERFACE(IDirect3DDevice2);
	//QUERYINTERFACE(IDirect3DDevice3);
	QUERYINTERFACE(IDirect3DDevice7);
	//QUERYINTERFACE(IDirect3DExecuteBuffer);
	//QUERYINTERFACE(IDirect3DLight);
	//QUERYINTERFACE(IDirect3DMaterial);
	//QUERYINTERFACE(IDirect3DMaterial2);
	//QUERYINTERFACE(IDirect3DMaterial3);
	//QUERYINTERFACE(IDirect3DTexture);
	//QUERYINTERFACE(IDirect3DTexture2);
	//QUERYINTERFACE(IDirect3DVertexBuffer);
	QUERYINTERFACE(IDirect3DVertexBuffer7);
	//QUERYINTERFACE(IDirect3DViewport);
	//QUERYINTERFACE(IDirect3DViewport2);
	//QUERYINTERFACE(IDirect3DViewport3);
	QUERYINTERFACE(IDirectDraw);
	//QUERYINTERFACE(IDirectDraw2);
	//QUERYINTERFACE(IDirectDraw4);
	QUERYINTERFACE(IDirectDraw7);
	QUERYINTERFACE(IDirectDrawClipper);
	//QUERYINTERFACE(IDirectDrawColorControl);
	//QUERYINTERFACE(IDirectDrawFactory);
	//QUERYINTERFACE(IDirectDrawGammaControl);
	QUERYINTERFACE(IDirectDrawPalette);
	QUERYINTERFACE(IDirectDrawSurface);
	//QUERYINTERFACE(IDirectDrawSurface2);
	//QUERYINTERFACE(IDirectDrawSurface3);
	//QUERYINTERFACE(IDirectDrawSurface4);
	QUERYINTERFACE(IDirectDrawSurface7);
}
