

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
		printf("=====�`�N�ƶ�:=====\n i.�ХΨt�κ޲z����������\nii.�o�ӥ\��u�䴩�̪�3~5�~�����X���L�u���d\n\n\n1:�Ұ�WiFi����(�ۭq�W�١B�K�X)\n2:��ܥثe���ɪ��A\n3:�������\n4:���]SSID\n5:���]�K�X\n9:����\n��ܥ\��:");
		scanf("%d",&f); 
		getchar();
		if(f==1)
		{
			printf("SSID:");
			scanf("%s",ssid);
			printf("�K�X(8��H�W):");
			scanf("%s",passw);
			while(1)
			{
				if (strlen(passw)<8)
				{
					printf("���F8��A�Э��s��J:");
					scanf("%s",passw);
				}
				else
					break;
			}
			start(ssid,passw);
			system("Ncpa.cpl");
			printf("�۰ʶ}�Ҥ����d�]�w����");
			printf("\n====�`�N�A�Y�O�Ĥ@���ϥνШ̷ӤU�C�B�J�]�w====");
			printf("\n�}��'����x'\n���'�����M���ں���'\n�I��'�����M�@�Τ���'\n������'�ܧ󤶭��d�]�w'\n�I��'�ϰ����'or'�A�Ӻ���'\n�I��'���e'(�A���`�W�������d)\n�I��W��'�@��'����\n��Ĥ@�Ӯخإ���\n�����'�ϰ�s�u*xx'(xx�O�H���Ʀr)\n");
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
			printf("��J�sssid:");
			scanf("%s",ssid);
			sprintf(bub,"netsh wlan set hostednetwork ssid=%s",ssid);
			system(bub);
		}
		else if(f==5)
		{
			char bub[300];
			printf("��J�s�K�X:");
			scanf("%s",passw);
			sprintf(bub,"netsh wlan set hostednetwork key=%s",ssid);
			system(bub);
			system("netsh wlan refresh hostednetwork key");
		}
		else if(f==9)
			break;
		else
		{
			printf("��J���~\n\n");
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
