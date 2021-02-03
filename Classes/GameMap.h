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
	// 世界坐标系转地图索引
	CCPoint convertToMapIdx(const CCPoint& pos);
	// 地图索引转世界坐标系
	CCPoint convertToUIPos(const CCPoint& mapIdx);
public:
	// 创建地图（地图文件）
	static GameMap* create(const char *tmxFile);
	// 获取对象字典。NULL表示没有获取到
	CCArray* getObjectsForGroupName(const char *groupName);
	CCDictionary* getObjectForName(const char *groupName, const char *objectName);
	// 获取指定对象坐标。理论是0，0表示没得到
	CCPoint getObjectPositionForDictionary(CCDictionary *pDict);
	CCPoint getObjectPositionForName(const char *groupName, const char *objectName);
	// 获取其它属性的字符串。转int：intValue()  转float：floatValue()  转bool：boolValue()
	CCString* getCustomStr(const char *groupName, const char *objectName, const char *property);
	// 检查并获取当前点指定方向的终点
	CCPoint getTargetPos(const char *layerName, const CCPoint& curPos, const CHECKEDDIR& dir);
	CCTMXObjectGroup* getObjectGroupForName(const char *groupName);
	CCPoint getTargetPosForCurPos(const char *layerName, const CCPoint curPos,const CCPoint dirPos);
};
#endif