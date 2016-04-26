/*!
* Copyright (c) 2016,airsurfish team.
* WebSite:http://www.eyusoft.com
* Official Author QQ:1473849376
* OpenSource:Apache License 2.0
*
* \file GuidHelper.h
* \brief ������
*
* \date 2016��04��26��
* \version 1.0
*/
#pragma once

// GUID ����
class ASUTLITY_EXT_CLASS GuidHelper
{
public:
	GuidHelper(void);
	~GuidHelper(void);

public:
	static wstring CreateGuidWstring(void);

	static string  CreateGuidString(void);

	static GUID    CreateGuid(void);
};
