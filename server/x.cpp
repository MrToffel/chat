#pragma comment(lib,"ws2_32.lib")
#include<windows.h>
#include<string>
#include<iostream>
SOCKET s;


int main(){
WSADATA w;
WSAStartup(MAKEWORD(1,1),&w);
s=socket(AF_INET,SOCK_STREAM,0);
sockaddr_in info;
int len=sizeof(info);
info.sin_addr.s_addr=INADDR_ANY;
info.sin_port=htons(1);
info.sin_family=AF_INET;
bind(s,(struct sockaddr*)&info,len);
listen(s,SOMAXCONN);
std::string chat;
while(1){
	sockaddr_in cinfo;
	SOCKET c=accept(s,(struct sockaddr*)&cinfo,&len);
	char b[1]={0};
	recv(c,b,1,0);
	if(b[0]=='g'){
		send(c,chat.c_str(),chat.size(),0);
	}if(b[0]=='s'){
		std::cout << inet_ntoa(cinfo.sin_addr);
		std::cout<<"  sendet:";
		char v[500]={0};
		send(c,"ok",2,0);
		int r=recv(c,v,500,0);
		chat.append(inet_ntoa(cinfo.sin_addr));
		chat.append(" - ");
		chat.append(v,r);
		chat+="\r\n";
		std::cout<<" "<<v<<std::endl;
		int c = 0;
		for (int i = chat.size() - 1; i > 0; i--) {
			if (chat[i] == '\n')c++;
			if (c == 35) {
				chat.replace(0, i+1, "");
				break;
			}
		}
	}
	closesocket(c);
}
}