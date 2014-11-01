

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>

void start(char ssid[128],char passw[128]);

int _tmain(int argc, _TCHAR* argv[])
{
	int f=1;
	char ssid[80],passw[20];
	while(1)
	{
		printf("=====注意事項:=====\n i.請用系統管理員身分執行\nii.這個功能只支援最近3~5年內推出的無線網卡\n\n\n1:啟動WiFi分享(自訂名稱、密碼)\n2:顯示目前分享狀態\n3:停止分享\n4:重設SSID\n5:重設密碼\n9:結束\n選擇功能:");
		scanf("%d",&f); 
		getchar();
		if(f==1)
		{
			printf("SSID:");
			scanf("%s",ssid);
			printf("密碼(8位以上):");
			scanf("%s",passw);
			while(1)
			{
				if (strlen(passw)<8)
				{
					printf("未達8位，請重新輸入:");
					scanf("%s",passw);
				}
				else
					break;
			}
			start(ssid,passw);
			system("Ncpa.cpl");
			printf("自動開啟介面卡設定頁面");
			printf("\n====注意，若是第一次使用請依照下列步驟設定====");
			printf("\n開啟'控制台'\n選擇'網路和網際網路'\n點選'網路和共用中心'\n左邊選單'變更介面卡設定'\n點選'區域網路'or'乙太網路'\n點選'內容'(你正常上網的網卡)\n點選上面'共用'分頁\n把第一個框框打勾\n選單選擇'區域連線*xx'(xx是隨機數字)\n");
			system("pause");
		}
		else if(f==2)
		{
			system("netsh wlan show hostednetwork setting=security");
		}
		else if(f==3)
		{
			system("netsh wlan stop hostednetwork");
		}
		else if(f==4)
		{
			char bub[300];
			printf("輸入新ssid:");
			scanf("%s",ssid);
			sprintf(bub,"netsh wlan set hostednetwork ssid=%s",ssid);
			system(bub);
		}
		else if(f==5)
		{
			char bub[300];
			printf("輸入新密碼:");
			scanf("%s",passw);
			sprintf(bub,"netsh wlan set hostednetwork key=%s",ssid);
			system(bub);
			system("netsh wlan refresh hostednetwork key");
		}
		else if(f==9)
			break;
		else
		{
			printf("輸入錯誤\n\n");
		}
			printf("\n\n\n\n");
	}
	return 0;
}
void start(char ssid[80],char passw[20])
{
	char buffer[300];
	sprintf(buffer,"netsh wlan set hostednetwork mode=allow ssid=%s key=%s",ssid,passw);
    system(buffer);
    system("netsh wlan start hostednetwork");
}
