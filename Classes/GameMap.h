#ifndef _GameMap_H_
#define _GameMap_H_
#include "cocos2d.h"
using namespace cocos2d;
enum CHECKEDDIR
{
	CHECKEDDIR_UP,
	CHECKEDDIR_DOWN,
	CHECKEDDIR_LEFT,
	CHECKEDDIR_RIGHT
};
class GameMap : public CCTMXTiledMap
{
private:
	CCDictionary* getDictionary(CCTMXObjectGroup* group, const char *objectName);
	// ��������ϵת��ͼ����
	CCPoint convertToMapIdx(const CCPoint& pos);
	// ��ͼ����ת��������ϵ
	CCPoint convertToUIPos(const CCPoint& mapIdx);
public:
	// ������ͼ����ͼ�ļ���
	static GameMap* create(const char *tmxFile);
	// ��ȡ�����ֵ䡣NULL��ʾû�л�ȡ��
	CCArray* getObjectsForGroupName(const char *groupName);
	CCDictionary* getObjectForName(const char *groupName, const char *objectName);
	// ��ȡָ���������ꡣ������0��0��ʾû�õ�
	CCPoint getObjectPositionForDictionary(CCDictionary *pDict);
	CCPoint getObjectPositionForName(const char *groupName, const char *objectName);
	// ��ȡ�������Ե��ַ�����תint��intValue()  תfloat��floatValue()  תbool��boolValue()
	CCString* getCustomStr(const char *groupName, const char *objectName, const char *property);
	// ��鲢��ȡ��ǰ��ָ��������յ�
	CCPoint getTargetPos(const char *layerName, const CCPoint& curPos, const CHECKEDDIR& dir);
	CCTMXObjectGroup* getObjectGroupForName(const char *groupName);
	CCPoint getTargetPosForCurPos(const char *layerName, const CCPoint curPos,const CCPoint dirPos);
};
#endif