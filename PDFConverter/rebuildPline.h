#pragma once
#include <vector>
using namespace std;

//�����еĵ��ţ���γ��ֵĵ�ֻ��һ���ţ������ñ��������㣬�򻯹���
struct PointNum
{
	AcGePoint3d pt; //��
	int nNum;  //���
};

//�����ĵ㣬�ñ����������ʾ
struct NumMap
{
	int nNum1;  //���
	int nNum2;  //���
	double dBulge; //͹��
};

//���Ƶ�
struct DrawPoint
{
	int nNum;  //���
	double dBulge; //����һ���͹��
};

class UserHelp
{
public:
	UserHelp(void);
public:
	~UserHelp(void);
private:
	//-----------------------------------------------------------------------------
	//Summary:�ҳ�����һ����������һ�㣬�Լ���֮������͹��
	//Par:
	// nm   ������Ϣ����
	// nThisNum ����
	// dThisBulge ͹��
	// nNextNum ����(���Ҳ��ɹ�ʱ��Ϊ-1)
	//Return:
	// ���ҳɹ�Ϊtrue�����Ҳ��ɹ�Ϊfalse
	//-----------------------------------------------------------------------------
	static bool FindNextPointNum(vector<NumMap>& nm, int nThisNum, double& dThisBulge, int& nNextNum);

	//-----------------------------------------------------------------------------
	//Summary:ͨ����Ų�����Ӧ�ĵ�
	//Par:
	// vecPt2Num �������� 
	// dThisBulge ͹��
	// ptThis  ��Ӧ�ĵ�
	//Return:
	// ���ҳɹ�Ϊtrue�����Ҳ��ɹ�Ϊfalse
	//-----------------------------------------------------------------------------
	static bool NumToPoint(vector<PointNum>& vecPt2Num, int nThisNum, AcGePoint3d& ptThis);

	//-----------------------------------------------------------------------------
	//Summary:��ʵ����ӵ����ݿ���
	//Par:
	// pEnt ʵ��ָ��  
	//Return:
	// �������ʵ��ID��
	//-----------------------------------------------------------------------------
	static AcDbObjectId Append(AcDbEntity* pEnt);

	//-----------------------------------------------------------------------------
	//Summary:����Բ����͹��
	//Par:
	// pArc Բ��ָ��  
	//Return:
	// ���ؼ���Ľ��
	//-----------------------------------------------------------------------------
	static double GetBulge(AcDbArc*& pArc);

	//-----------------------------------------------------------------------------
	//Summary:�õ�ĳ�����Ļ�����Ϣ���������ţ�������Ϣ
	//Par:
	// vecPt2Num �������� 
	// vecNumMap ������Ϣ����
	// nCodeNum ��Ҫ��ŵĵڼ�����
	// ptStart  ���
	// ptEnd  �յ�
	// dBulge  ptStart��ptEnd��͹��
	//Return:
	// �ޡ�
	//-----------------------------------------------------------------------------
	static void GetDrawInfo(vector<PointNum>& vecPt2Num, vector<NumMap>& vecNumMap, int& nCodeNum,
		const AcGePoint3d& ptStart, const AcGePoint3d ptEnd, double dBulge);

	static double m_cPI2;
	//-----------------------------------------------------------------------------
	//Summary:��ֱ�ߣ�Բ���������ת��Ϊ(�ϲ�)�����
	//Par:
	// idObjArr ֱ�ߣ�Բ��������ߵ�id 
	// idPolyline ת�������ߵ�ID
	//Return:
	// ת���ɹ�Ϊtrue�����ɹ�Ϊfalse��
	//-----------------------------------------------------------------------------

private:
	static bool ChangeToPolyLine(std::vector<AcDbPolyline*>& arrPtr, AcDbDatabase* pDb);

public:
	static void AppendPlines(std::vector<AcDbPolyline*>& arrPtr, AcDbDatabase* pDb);

};
