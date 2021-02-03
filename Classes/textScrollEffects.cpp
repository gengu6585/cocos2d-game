#include "textScrollEffects.h"




void textScrollEffects::create(CCLayer* layer,CCPoint pos,const char path[]){
		textScrollEffects*effects=new textScrollEffects();
		effects->init(layer,pos,path);

}
 textScrollEffects::textScrollEffects(){
	 sum=-1;

}

void textScrollEffects::init(CCLayer* layer,CCPoint pos,const char path[]){
	/*背景故事.txt*/
	
		 delay=0.55;  

		FILE *fp;
		char line[100000];

		fp=fopen(path,"r");
		if(fp==NULL)
		{
			printf("can not load file!");
			
		}
		  // 由于是数组，只好把到底存了多少个对象用一个全局的变量存起来
		while(!feof(fp))
		{	
			
			sum++; //记录一下文本的行数
			fgets(line,100000,fp);
			  
			/*wchar_t*wchar=CUser::CharToWchar(line);
			string str=UTF8ToGBK::UTF8TOGBK(wchar);  */   // 从外部文件导入，不需要进行转码

			 this->plabelArray[sum]=CCLabelTTF::create(line,"AppleGothic", 40.0);
			
			this-> plabelArray[sum]->setOpacity(0);
			
		//创建一个CCArray用于新建CCSquence
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