#include "StdAfx.h"
#include "mp3infp.h"

//IPersistFile Methods
STDMETHODIMP CShellExt::IsDirty()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	TRACE("[%s]CShellExt::IsDirty()\n",APP_NAME);

	return S_FALSE;
}

STDMETHODIMP CShellExt::Load(LPCOLESTR pszFileName, DWORD dwMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	TRACE("[%s]CShellExt::Load(%s)\n",APP_NAME,pszFileName);

	char szFileUserClickedOn[MAX_PATH];

	WideCharToMultiByte(CP_ACP,                // CodePage
                        0,		              // dwFlags
                        pszFileName,          // lpWideCharStr
                        -1,                    // cchWideChar
                        szFileUserClickedOn, // lpMultiByteStr
                        sizeof(szFileUserClickedOn),  // cchMultiByte,
                        NULL,                  // lpDefaultChar,
                        NULL);                 // lpUsedDefaultChar

	m_strSelectFile = szFileUserClickedOn;
	TRACE("    +--Load (%s)\n",m_strSelectFile);

	Load();	//������

	return S_OK;
}

STDMETHODIMP CShellExt::Save(LPCOLESTR pszFileName, BOOL fMember)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	TRACE("[%s]CShellExt::Save()\n",APP_NAME);

	return E_NOTIMPL;
}

STDMETHODIMP CShellExt::SaveCompleted(LPCOLESTR)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	TRACE("[%s]CShellExt::SaveCompleted()\n",APP_NAME);

	return E_NOTIMPL;
}

STDMETHODIMP CShellExt::GetCurFile(LPOLESTR *ppszFileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	TRACE("[%s]CShellExt::GetCurFile()\n",APP_NAME);

	return S_OK;  
}