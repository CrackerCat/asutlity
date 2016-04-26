/*!
* Copyright (c) 2016,airsurfish team.
* WebSite:http://www.eyusoft.com
* Official Author QQ:1473849376
* OpenSource:Apache License 2.0
*
* \file EncodingHelper.h
* \brief ������
*
* \date 2016��04��26��
* \version 1.0
*/
#pragma once

// ���ܽ�����
class ASUTLITY_EXT_CLASS EncodingHelper
{
public:
	EncodingHelper(void);
	~EncodingHelper(void);

public:
	// ʮ����/ʮ������ת��
	static char	  DecHex(int n);
	static int	  HexDec(char c);

	// Hex����/����
	static string HexEncode(const string& strSrc);
	static string HexDecode(const string& strSrc);

	// Url����/����
	static string UrlEncode(const string& strSrc);
	static string UrlDecode(const string& strSrc);

	// ICONV�ַ�����ת��
	static char*  IconvConvert(const char* szSrc, string strFromCode, string strToCode);

	// MB/UTF-8ת��
	static string MbUtf8(const string& strMb);
	static string Utf8Mb(const string& strUtf8);

	// Unicode/����ת��
	static string UnicodeChinese(const string& strUnicode);
	static string ChineseUnicode(const string& strChinese);

	// Base64����/����
	static string Base64Encode(const string& strSrc);
	static string Base64Decode(const string& strSrc);
	static string Base64EncodeJPG(const string& strFileName);
};