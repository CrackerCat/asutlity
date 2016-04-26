
// unittestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "unittest.h"
#include "unittestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CunittestDlg �Ի���




CunittestDlg::CunittestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CunittestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CunittestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CunittestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_JSON, &CunittestDlg::OnBnClickedBtnJson)
	ON_BN_CLICKED(IDC_BTN_XML, &CunittestDlg::OnBnClickedBtnXml)
	ON_BN_CLICKED(IDC_BTN_CURL, &CunittestDlg::OnBnClickedBtnCurl)
	ON_BN_CLICKED(IDC_BTN_CHART, &CunittestDlg::OnBnClickedBtnChart)
END_MESSAGE_MAP()


// CunittestDlg ��Ϣ�������

BOOL CunittestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CunittestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CunittestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CunittestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ����
void CunittestDlg::OnBnClickedBtnJson()
{
	// ���ļ�
	string str_file = "d:\\jsontest.jscon";
	std::locale loc = std::locale::global(std::locale(""));
	std::ifstream file_stream;
	file_stream.open(str_file.c_str(), std::ios::binary);

	// ����json����
	Json::Reader reader;
	Json::Value  root;
	if (reader.parse(file_stream, root, false))
	{
		// uudama
		if (!root["uudama"].isNull())
		{
			int nCnt = root["uudama"].size();
			for (int i=0; i<nCnt; i++)
			{
				string str_id = root["uudama"][i]["id"].asString();
				string str_codetype = root["uudama"][i]["code_type"].asString();
				string str_minlen = root["uudama"][i]["min_length"].asString();
				string str_maxlen = root["uudama"][i]["max_length"].asString();
				string str_description = root["uudama"][i]["description"].asString();
			}
		}
	}

	file_stream.close();
	std::locale::global(std::locale(loc));
}

void CunittestDlg::OnBnClickedBtnXml()
{
	// ��Xml
	string strUrl = "d:\\xmltest.xml"; 
	TiXmlDocument xmlDoc(strUrl.c_str());
	xmlDoc.LoadFile();

	TiXmlElement* pRootElement = xmlDoc.RootElement();
	if(!pRootElement)
		return;

	TiXmlElement* pNode = NULL;
	pNode = pRootElement->FirstChildElement("PersonID");
	if(pNode != NULL)
	{
		string strPersonID = pNode->GetText();
	}

	TiXmlNode* pSubNode = NULL;
	pSubNode = pRootElement->FirstChild("PersonXml");

	TiXmlElement* pTempElement = NULL;
	pTempElement = pSubNode->FirstChildElement("Path");
	while (pTempElement)
	{
		std::string strPersonXml = pTempElement->GetText();
		pTempElement = pTempElement->NextSiblingElement();
	}

	/*/ дXml
	CString strUrl = szFilePath; 

	strUrl += "xml\\personSetting.xml";
	OutputDebugString("savepath:");
	OutputDebugString(strUrl);

	TiXmlDocument xmlDoc;
	TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "gb2312", "yes");
	xmlDoc.LinkEndChild(decl);
	TiXmlNode* rootElement = xmlDoc.InsertEndChild(TiXmlElement("ConfigSetting"));

	TiXmlNode* pTempNode = rootElement->InsertEndChild(TiXmlElement("PersonID"));
	pTempNode->InsertEndChild(TiXmlText(m_strPersonID.c_str()));

	std::string strSubName = "PersonXml";
	TiXmlNode* subElement = rootElement->InsertEndChild(TiXmlElement(strSubName.c_str()));

	list<std::string>::iterator iter = m_listPersonInfo.begin();
	for (; iter != m_listPersonInfo.end(); iter++)
	{
		pTempNode = subElement->InsertEndChild(TiXmlElement("Path"));
		pTempNode->InsertEndChild(TiXmlText((*iter).c_str()));
	}

	xmlDoc.SaveFile(strUrl);
	*/
}

void CunittestDlg::OnBnClickedBtnCurl()
{
	string strResponse = ""; // �������󷵻�����
	CURL* curl = curl_easy_init();
	if (curl)
	{
		// ����ͷ
		struct curl_slist* headers = NULL;
		headers = curl_slist_append(headers,"User-Agent:Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko");
		headers = curl_slist_append(headers,"Referer:http://www.asapp.com");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

		// ���ò���
		char szTemp[1024] = {0};
		sprintf(szTemp, "http://www.eyusoft.com");
		curl_easy_setopt(curl, CURLOPT_URL, szTemp);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30);
		curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip");

		// ���ûص�����
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strResponse);

		// ִ��http����
		CURLcode res = curl_easy_perform(curl);

		// �ͷ���Դ
		curl_easy_cleanup(curl);
		curl_slist_free_all(headers);
		headers = NULL;
	}
}

void CunittestDlg::OnBnClickedBtnChart()
{
	string strFile = "d:\\surface2.jpg";
	// The x and y coordinates of the grid
	double dataX[] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
	double dataY[] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};

	// The values at the grid points. In this example, we will compute the values
	// using the formula z = sin((x - 0.5) * 2 * pi) * sin((y - 0.5) * 2 * pi)
	double dataZ[(int)(sizeof(dataX) / sizeof(dataX[0])) * (int)(sizeof(dataY) /
		sizeof(dataY[0]))];
	int yIndex;
	for(yIndex = 0; yIndex < (int)(sizeof(dataY) / sizeof(dataY[0])); ++yIndex) {
		double y = (dataY[yIndex] - 0.5) * 2 * 3.1416;
		int xIndex;
		for(xIndex = 0; xIndex < (int)(sizeof(dataX) / sizeof(dataX[0])); ++xIndex) {
			double x = (dataX[xIndex] - 0.5) * 2 * 3.1416;
			dataZ[yIndex * (int)(sizeof(dataX) / sizeof(dataX[0])) + xIndex] = sin(x)
				* sin(y);
		}
	}

	// Create a SurfaceChart object of size 720 x 540 pixels
	SurfaceChart *c = new SurfaceChart(720, 540);

	// Add a title to the chart using 20 points Times New Roman Italic font
	c->addTitle("Quantum Wave Function", "timesi.ttf", 20);

	// Set the center of the plot region at (360, 245), and set width x depth x
	// height to 360 x 360 x 270 pixels
	c->setPlotRegion(360, 245, 360, 360, 270);

	// Set the elevation and rotation angles to 20 and 30 degrees
	c->setViewAngle(20, 30);

	// Set the data to use to plot the chart
	c->setData(DoubleArray(dataX, (int)(sizeof(dataX) / sizeof(dataX[0]))),
		DoubleArray(dataY, (int)(sizeof(dataY) / sizeof(dataY[0]))), DoubleArray(
		dataZ, (int)(sizeof(dataZ) / sizeof(dataZ[0]))));

	// Spline interpolate data to a 80 x 80 grid for a smooth surface
	c->setInterpolation(80, 80);

	// Set surface grid lines to semi-transparent black (dd000000)
	c->setSurfaceAxisGrid(0xdd000000);

	// Set contour lines to semi-transparent white (80ffffff)
	c->setContourColor(0x80ffffff);

	// Add a color axis (the legend) in which the left center is anchored at (645,
	// 270). Set the length to 200 pixels and the labels on the right side. Use
	// smooth gradient coloring.
	c->setColorAxis(645, 270, Chart::Left, 200, Chart::Right)->setColorGradient();

	// Set the x, y and z axis titles using 10 points Arial Bold font
	c->xAxis()->setTitle("x/L(x)", "arialbd.ttf", 10);
	c->yAxis()->setTitle("y/L(y)", "arialbd.ttf", 10);
	c->zAxis()->setTitle("Wave Function Amplitude", "arialbd.ttf", 10);

	// Output the chart
	c->makeChart(strFile.c_str());

	//free up resources
	delete c;

	::ShellExecute(this->GetSafeHwnd(), _T("open"), _T("d:\\surface2.jpg"),NULL,NULL,SW_SHOWMAXIMIZED);
}