#include "GameData.h"

// ��̬�����ĳ�ʼ��
int GameData::s_iCurLvevel = 1;
int GameData::s_iCurBigLevel = 1;
void GameData::returnDefault(){

	//std::string ss=CCUserDefault::getXMLFilePath();
	//CCUserDefault::purgeSharedUserDefault();  
	//remove(CCUserDefault::getXMLFilePath().c_str());  
}
void GameData::saveStarNum(int bigIdx, int smallIdx, int starNum)
{
	//"starNum_1_2" = starNum
	char str[32] = { 0 };
	sprintf(str, "starNum_%d_%d", bigIdx, smallIdx);
	// �浵
	CCUserDefault::sharedUserDefault()->setIntegerForKey(str, starNum);
	// map ��ֵ��  ������--����ֵ
}

// ����.��������أ�С��
int GameData::getStarNum(int bigIdx, int smallIdx)
{
	char str[32] = { 0 };
	sprintf(str, "starNum_%d_%d", bigIdx, smallIdx);
	return CCUserDefault::sharedUserDefault()->getIntegerForKey(str, 0);
}
// �Ƿ����
int GameData::getPassCount(int bigIdx)
{
	char str[32] = { 0 };
	sprintf(str, "isPass_%d", bigIdx);
	// map  key-value
	// isPass_1_1
	return CCUserDefault::sharedUserDefault()->getIntegerForKey(str, 1);
}
// �����Ƿ����
void GameData::setPassCount(int bigIdx, int passCount)
{
	char str[32] = { 0 };
	sprintf(str, "isPass_%d", bigIdx);
	CCUserDefault::sharedUserDefault()->setIntegerForKey(str, passCount);
}