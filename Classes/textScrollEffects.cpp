#include "textScrollEffects.h"




void textScrollEffects::create(CCLayer* layer,CCPoint pos,const char path[]){
		textScrollEffects*effects=new textScrollEffects();
		effects->init(layer,pos,path);

}
 textScrollEffects::textScrollEffects(){
	 sum=-1;

}

void textScrollEffects::init(CCLayer* layer,CCPoint pos,const char path[]){
	/*��������.txt*/
	
		 delay=0.55;  

		FILE *fp;
		char line[100000];

		fp=fopen(path,"r");
		if(fp==NULL)
		{
			printf("can not load file!");
			
		}
		  // ���������飬ֻ�ðѵ��״��˶��ٸ�������һ��ȫ�ֵı���������
		while(!feof(fp))
		{	
			
			sum++; //��¼һ���ı�������
			fgets(line,100000,fp);
			  
			/*wchar_t*wchar=CUser::CharToWchar(line);
			string str=UTF8ToGBK::UTF8TOGBK(wchar);  */   // ���ⲿ�ļ����룬����Ҫ����ת��

			 this->plabelArray[sum]=CCLabelTTF::create(line,"AppleGothic", 40.0);
			
			this-> plabelArray[sum]->setOpacity(0);
			
		//����һ��CCArray�����½�CCSquence
			CCArray *array=CCArray::createWithCapacity(3);
	
			static float temp=0;
			array->addObject(CCDelayTime::create(temp+=delay));  
			
		
		
			CCSequence *sChild=CCSequence::create(CCFadeTo::create(1.2f,255),CCDelayTime::create(1.0f),CCFadeTo::create(4.0f,0),NULL);
			CCSpawn* spawn=CCSpawn::create(sChild,CCMoveBy::create(15.0f,ccp(0,2000)),NULL);
			
			array->addObject(spawn);
			/*array->addObject(NULL);*/
			
			
			layer->addChild(plabelArray[sum]);

			plabelArray[sum]->setPosition(pos);
			
			plabelArray[sum]->runAction(CCSequence::create(array));

			plabelArray[sum]->setTag(2);

}
		
}