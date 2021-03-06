// Tag_Wma.h: CTag_Wma クラスのインターフェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Tag_Wma_H__E33771A1_E2B4_4AE7_8315_1B62735A6280__INCLUDED_)
#define AFX_Tag_Wma_H__E33771A1_E2B4_4AE7_8315_1B62735A6280__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4786)
#include <map>

typedef void (*LPTCPPROGRESS)(__int64 writeSize,__int64 totalSize);

class CTag_WmaComment  
{
public:
	CTag_WmaComment(WORD wDataType,char *buf,WORD len)
	{
		m_wDataType = wDataType;
		m_buf = (char *)malloc(len);
		m_wLen = len;
		memcpy(m_buf,buf,len);
	}
	~CTag_WmaComment()
	{
		free(m_buf);
	}
	CTag_WmaComment(const CTag_WmaComment &obj)	//コピーコンストラクタ
	{
		m_wDataType = obj.m_wDataType;
		m_buf = (char *)malloc(obj.m_wLen);
		m_wLen = obj.m_wLen;
		memcpy(m_buf,obj.m_buf,obj.m_wLen);
	};
	WORD m_wDataType;
	char *m_buf;
	WORD m_wLen;
};

class CTag_Wma  
{
public:
	CTag_Wma();
	virtual ~CTag_Wma();
	void Release();
	BOOL IsEnable(){return m_bEnable;};
	DWORD Load(LPCTSTR szFileName);
	DWORD Save(LPCTSTR szFileName,LPTCPPROGRESS cbProgress = NULL);

	CString GetNAM() { return m_strTitle; };
	void	SetNAM(LPCTSTR str) { m_strTitle = str; m_bEnable = TRUE; };

	CString GetTRACK();
	void	SetTRACK(LPCTSTR str);
	
	CString GetART() { return m_strAuthor; };
	void	SetART(LPCTSTR str) { m_strAuthor = str; m_bEnable = TRUE; };
	
	CString GetPRD();
	void	SetPRD(LPCTSTR str);
	
	CString GetCMT() { return m_strDescription; };
	void	SetCMT(LPCTSTR str) { m_strDescription = str; m_bEnable = TRUE; };
	
	CString GetCRD();
	void	SetCRD(LPCTSTR str);
	
	CString GetGNR();
	void	SetGNR(LPCTSTR str);
	
	CString GetCOPY() { return m_strCopyright; };
	void	SetCOPY(LPCTSTR str) { m_strCopyright = str; m_bEnable = TRUE; };
	
	CString GetUrl1();
	void	SetUrl1(LPCTSTR str);
	
	CString GetUrl2();
	void	SetUrl2(LPCTSTR str);
	
	CString GetRating() { return m_strRating; };
	void	SetRating(LPCTSTR str) { m_strRating = str; m_bEnable = TRUE; };
	
	BOOL	GetSeekable(){return m_bIsSeekable;};
	BOOL	GetBroadcast(){return m_bIsBroadcast;};
	int		GetDrmVer(){
		if(m_bUseDRMv7) return 7;
		if(m_bUseDRMv1) return 1;
		return 0;
	}
	
	CString GetAudioFormatString(){return m_strAudioCodec.GetLength()?(m_strAudioCodec):(_T("N/A"));};
	CString GetVideoFormatString(){return m_strVideoCodec.GetLength()?(m_strVideoCodec):(_T("N/A"));};
	CString GetTimeString()
	{
		CString strTime;
		ULONGLONG sec = m_llPlayTime/10000000;	// 100ns単位から1sec単位へ
		if(m_llPlayTime)
		{
			sec += ((m_llPlayTime%10000000)?0:1);
		}
		strTime.Format(_T("%02I64u:%02I64u:%02I64u (%I64usec)"),
						sec/60/60,
						sec/60%60,
						sec%60,
						sec);
		return strTime;
	}

protected:
//	DWORD Save_(LPCTSTR szFileName,HANDLE *hEvent);
#pragma pack(1)
	typedef struct _GUID_SIZE{
		GUID guid;
		ULONGLONG size;
	}GUID_SIZE;
	typedef struct _Extended_Stream_Properties_Object{
		GUID_SIZE guid3;
		ULONGLONG ullStartTime;
		ULONGLONG ullEndTime;
		DWORD dwDataBitrate;
		DWORD dwBufferSize;
		DWORD dwInitialBufferFullness;
		DWORD dwAlternateDataBitrate;
		DWORD dwAlternateBufferSize;
		DWORD dwAlternateInitialBufferFullness;
		DWORD dwMaximumObjectSize;
		DWORD dwFlags;
		WORD wStreamNumber;
		WORD wStreamLanguageIdIndex;
		ULONGLONG ullAverageTimePerFrame;
		WORD wStreamNameCount;
	}Extended_Stream_Properties_Object;
#pragma pack()
	DWORD	ReadGUID_Size(HANDLE hFile,GUID_SIZE *guidSize);
	DWORD	Walk(HANDLE hFile,__int64 llSize);
	DWORD	HeaderWalk(HANDLE hFile,__int64 llSize);
	CString ReadWchar(HANDLE hFile,WORD len);
	DWORD	WriteWchar(HANDLE hFile,CString str);
	DWORD	ReadDescString(HANDLE hFile);
	DWORD	WriteDescString(HANDLE hFile,ULONGLONG &ullNewLength);
	BOOL	AddComment(LPCTSTR name,WORD type,char *buf,WORD len);
	BOOL	DellComment(LPCTSTR name);
	BOOL	AddCommentString(LPCTSTR name,CString str);
	BOOL	AddCommentDword(LPCTSTR name,DWORD val);
	BOOL	GetComment(LPCTSTR name,WORD *type,WORD *len,char **buf);
	BOOL	GetCommentString(LPCTSTR name,CString &str);
	BOOL	GetCommentDword(LPCTSTR name,DWORD &val);
	BOOL	m_bEnable;
	DWORD CTag_Wma::Save_Header_Object(HANDLE hFile,HANDLE hTempFile,ULONGLONG size,ULONGLONG &writeSize);

private:
	BOOL		m_bIsSeekable;
	BOOL		m_bIsBroadcast;
	BOOL		m_bUseDRMv1;
	BOOL		m_bUseDRMv7;
	ULONGLONG	m_llPlayTime;
	CString		m_strAudioCodec;
	CString		m_strVideoCodec;
	DWORD		m_dwVideoWidth;
	DWORD		m_dwVideoHeight;
	DWORD		m_dwBitCount;
	
	CString		m_strTitle;
	CString		m_strAuthor;
	CString		m_strCopyright;
	CString		m_strDescription;
	CString		m_strRating;
	
	__int64		m_lldwPtr_File_Properties_Object;
	typedef std::map<CString,CTag_WmaComment> CommentMap;
	CommentMap m_comments;
};

#endif // !defined(AFX_Tag_Wma_H__E33771A1_E2B4_4AE7_8315_1B62735A6280__INCLUDED_)
