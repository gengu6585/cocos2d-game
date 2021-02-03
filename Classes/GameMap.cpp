#include "GameMap.h"

GameMap* GameMap::create(const char *tmxFile)
{
	GameMap *pRet = new GameMap();
	if (pRet->initWithTMXFile(tmxFile))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
CCDictionary* GameMap::getObjectForName(const char *groupName, const char *objectName)
{
	CCAssert(groupName != NULL && strlen(groupName) > 0, "Invalid group name!");

	std::string sGroupName = groupName;
	if (m_pObjectGroups && m_pObjectGroups->count()>0)
	{
		CCTMXObjectGroup* objectGroup = NULL;
		CCObject* pObj = NULL;
		CCARRAY_FOREACH(m_pObjectGroups, pObj)
		{
			objectGroup = (CCTMXObjectGroup*)(pObj);
			if (objectGroup && objectGroup->getGroupName() == sGroupName)
			{
				return getDictionary(objectGroup, objectName);
			}
		}
	}
	// objectGroup not found
	return NULL;
}
CCTMXObjectGroup* GameMap::getObjectGroupForName(const char *groupName)
{
	CCAssert(groupName != NULL && strlen(groupName) > 0, "Invalid group name!");

	std::string sGroupName = groupName;
	if (m_pObjectGroups && m_pObjectGroups->count()>0)
	{
		CCTMXObjectGroup* objectGroup = NULL;
		CCObject* pObj = NULL;
		CCARRAY_FOREACH(m_pObjectGroups, pObj)
		{
			objectGroup = (CCTMXObjectGroup*)(pObj);
			if (objectGroup)
			{
				return objectGroup;
			}
		}
	}
	// objectGroup not found
	return NULL;
}


CCArray* GameMap::getObjectsForGroupName(const char *groupName)
{
	CCAssert(groupName != NULL && strlen(groupName) > 0, "Invalid group name!");

	std::string sGroupName = groupName;
	if (m_pObjectGroups && m_pObjectGroups->count()>0)
	{
		CCTMXObjectGroup* objectGroup = NULL;
		CCObject* pObj = NULL;
		CCARRAY_FOREACH(m_pObjectGroups, pObj)
		{
			objectGroup = (CCTMXObjectGroup*)(pObj);
			if (objectGroup && objectGroup->getGroupName() == sGroupName)
			{
				return objectGroup->getObjects();
			}
		}
	}
	// objectGroup not found
	return NULL;
}



CCDictionary* GameMap::getDictionary(CCTMXObjectGroup* group, const char *objectName)
{
	std::string sObjectName = objectName;
	// 获取层上的对象集合
	CCArray *objects = group->getObjects();
	CCDictionary *pDict = NULL;
	CCObject *pObj = NULL;
	// 遍历对象集合中的对象
	CCARRAY_FOREACH(objects, pObj)
	{
		pDict = (CCDictionary*)pObj;
		if (!pDict)
		{
			break;
		}
		CCString *str = (CCString*)pDict->objectForKey("name");
		if (str->m_sString == sObjectName)
		{
			return pDict;
		}
	}
	return NULL;
}


CCPoint GameMap::getObjectPositionForDictionary(CCDictionary *pDict)
{
	
	 
	if (pDict)
	{
		float x = ((CCString*)pDict->objectForKey("x"))->floatValue();
		float y = ((CCString*)pDict->objectForKey("y"))->floatValue();
		return ccp(x + m_tTileSize.width / 2 + this->getPositionX(), y + m_tTileSize.height/2 + this->getPositionY());
	}
	return CCPointZero;
}
// 获取指定对象坐标
CCPoint GameMap::getObjectPositionForName(const char *groupName, const char *objectName)
{
	CCAssert(groupName != NULL && strlen(groupName) > 0, "Invalid group name!");
	CCDictionary *pDict = getObjectForName(groupName, objectName);
	if (pDict)
	{
		float x = ((CCString*)pDict->objectForKey("x"))->floatValue();
		float y = ((CCString*)pDict->objectForKey("y"))->floatValue();
		return ccp(x + m_tTileSize.width / 2 + this->getPositionX(), y + m_tTileSize.height/2 + this->getPositionY());
	}
	return CCPointZero;
}

// 获取其它属性的字符串。转int：intValue()  转float：floatValue()  转bool：boolValue()
CCString* GameMap::getCustomStr(const char *groupName, const char *objectName, const char *property)
{
	CCAssert(groupName != NULL && strlen(groupName) > 0, "Invalid group name!");
	CCDictionary *pDict = getObjectForName(groupName, objectName);
	if (pDict)
	{
		return ((CCString*)pDict->objectForKey(property));
	}
	return NULL;
}

// 世界坐标系转地图索引
CCPoint GameMap::convertToMapIdx(const CCPoint& pos)
{
	return CCPoint((int)((pos.x - m_tTileSize.width / 2 - this->getPositionX()) / m_tTileSize.width), m_tMapSize.height - 1 - (int)((pos.y - m_tTileSize.height / 2 - this->getPositionY()) / m_tTileSize.height));
}
// 地图索引转世界坐标系
CCPoint GameMap::convertToUIPos(const CCPoint& mapIdx)
{
	return CCPoint(mapIdx.x * m_tTileSize.width + m_tTileSize.width / 2 + this->getPositionX(), 
		(m_tMapSize.height - 1 - mapIdx.y) * m_tTileSize.height + m_tTileSize.height / 2 + this->getPositionY());
}
// 检查并获取当前点指定方向的终点
CCPoint GameMap::getTargetPos(const char *layerName, const CCPoint& curPos, const CHECKEDDIR& dir)
{
	CCTMXLayer* layer = this->layerNamed(layerName);
	if (layer)
	{
		CCPoint curIdx = this->convertToMapIdx(curPos);
		CCPoint dirVec;
		switch (dir)
		{
		case CHECKEDDIR_UP:
			dirVec = ccp(0,-1);
			break;
		case CHECKEDDIR_DOWN:
			dirVec = ccp(0, 1);
			break;
		case CHECKEDDIR_LEFT:
			dirVec = ccp(-1, 0);
			break;
		case CHECKEDDIR_RIGHT:
			dirVec = ccp(1, 0);
			break;
		default:
			dirVec = ccp(0, 0);
			break;
		}
		while (true)
		{
			curIdx = curIdx + dirVec;
			if (curIdx.x < 0 || curIdx.x >= m_tMapSize.width || curIdx.y < 0 || curIdx.y >= m_tMapSize.height)
			{
				return convertToUIPos(curIdx - dirVec);
			}
			else if (0 != layer->tileGIDAt(curIdx))
			{
				return convertToUIPos(curIdx - dirVec);
			}
		}
	}
	return curPos;
}

CCPoint GameMap::getTargetPosForCurPos(const char *layerName, const CCPoint curPos,const CCPoint dirPos)
{
	CCTMXLayer* layer = this->layerNamed(layerName);
	if (layer)
	{
		CCPoint curIdx = this->convertToMapIdx(curPos);
		CCPoint dirVec=dirPos;
		
		while (true)
		{
			curIdx = curIdx + dirVec;
			if (curIdx.x < 0 || curIdx.x >= m_tMapSize.width || curIdx.y < 0 || curIdx.y >= m_tMapSize.height)
			{
				return convertToUIPos(curIdx - dirVec);
			}
			else if (0 != layer->tileGIDAt(curIdx))
			{
				return convertToUIPos(curIdx - dirVec);
			}
		}
	}
	return curPos;
}