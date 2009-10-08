// Tag_Wma.h: CTag_Wma �N���X�̃C���^�[�t�F�C�X
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Tag_Wma_H__E33771A1_E2B4_4AE7_8315_1B62735A6280__INCLUDED_)
#define AFX_Tag_Wma_H__E33771A1_E2B4_4AE7_8315_1B62735A6280__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4786)
#include <map>
using namespace std;

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
	CTag_WmaComment(const CTag_WmaComment &obj)	//�R�s�[�R���X�g���N�^
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
	DWORD Load(const char *szFileName);
	DWORD Save(const char *szFileName,LPTCPPROGRESS cbProgress = NULL);
	CString GetNAM();
	void	SetNAM(const char *str);

	CString GetTRACK();
	void	SetTRACK(const char *str);
	
	CString GetART();
	void	SetART(const char *str);
	
	CString GetPRD();
	void	SetPRD(const char *str);
	
	CString GetCMT();
	void	SetCMT(const char *str);
	
	CString GetCRD();
	void	SetCRD(const char *str);
	
	CString GetGNR();
	void	SetGNR(const char *str);
	
	CString GetCOPY();
	void	SetCOPY(const char *str);
	
	CString GetUrl1();
	void	SetUrl1(const char *str);
	
	CString GetUrl2();
	void	SetUrl2(const char *str);
	
	CString GetRating();
	void	SetRating(const char *str);
	
	BOOL	GetSeekable(){return m_bIsSeekable;};
	BOOL	GetBroadcast(){return m_bIsBroadcast;};
	int		GetDrmVer(){
		if(m_bUseDRMv7) return 7;
		if(m_bUseDRMv1) return 1;
		return 0;
	}
	
	CString GetAudioFormatString(){return m_strAudioCodec.GetLength()?(m_strAudioCodec):("N/A");};
	CString GetVideoFormatString(){return m_strVideoCodec.GetLength()?(m_strVideoCodec):("N/A");};
	CString GetTimeString()
	{
		CString strTime;
		ULONGLONG sec = m_llPlayTime/10000000;	// 100ns�P�ʂ���1sec�P�ʂ�
		if(m_llPlayTime)
		{
			sec += ((m_llPlayTime%10000000)?0:1);
		}
		strTime.Format("%02I64u:%02I64u:%02I64u (%I64usec)",
						sec/60/60,
						sec/60%60,
						sec%60,
						sec);
		return strTime;
	}

protected:
//	DWORD Save_(const char *szFileName,HANDLE *hEvent);
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
	__int64 GetFileSize64(HANDLE hFile);
	__int64 SetFilePointer64(HANDLE hFile,__int64 llDistanceToMove,DWORD dwMoveMethod);
	DWORD	ReadGUID_Size(HANDLE hFile,GUID_SIZE *guidSize);
	DWORD	Walk(HANDLE hFile,__int64 llSize);
	DWORD	HeaderWalk(HANDLE hFile,__int64 llSize);
	CString ReadWchar(HANDLE hFile,WORD len);
	DWORD	WriteWchar(HANDLE hFile,CString str);
	DWORD	ReadDescString(HANDLE hFile);
	DWORD	WriteDescString(HANDLE hFile,ULONGLONG &ullNewLength);
	BOOL	AddComment(const char *name,WORD type,char *buf,WORD len);
	BOOL	DellComment(const char *name);
	BOOL	AddCommentString(const char *name,CString str);
	BOOL	AddCommentDword(const char *name,DWORD val);
	BOOL	GetComment(const char *name,WORD *type,WORD *len,char **buf);
	BOOL	GetCommentString(const char *name,CString &str);
	BOOL	GetCommentDword(const char *name,DWORD &val);
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
	map<CString,CTag_WmaComment> m_comments;
};

#endif // !defined(AFX_Tag_Wma_H__E33771A1_E2B4_4AE7_8315_1B62735A6280__INCLUDED_)