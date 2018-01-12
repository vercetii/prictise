
#include<arpa/inet.h>
int inet_aton(const char *cp,struct in_addr inp); //若成功则唯一，若出错则为零
char *inet_ntoa( struct in_addr in);//返回只想点分十进制串的指针 
//因特网 应用程序通过调用一下函数从DNS数据库中检索任意主机条目
#include <netdb.h>
struct hostent *gethostbyname(const char *name);//返回和域名name相关的主机条目。 
struct hostent *gethostbyaddr(const char *addr,int len,0)//返回和IP地址addr相关的主机条目。第二个参数给出IP地址的字节长度，对于目前来说4个字节常见，要求来说总为零 
//若成功返回非NULL 出错返回NULL 
/*struct hosttent
{
char *h_name;//主机域名 
char **h_aliases;//null terminated arry of domain name？？？ 
int h_addrtype;//主机地址 
int h_length;//地址的字长 
char **h_addr_list;ull terminated arry of in_addr struct？？？ 
};
*/
#include "csapp.h"
int main(int argc,char **argv)
{
	char **pp;
	struct in_addr addr;
	struct hostent *hostp;
 } 
 if(argc != 2)
 {
 	fprintf(stderr,"%s",argv[0]);
 	exit(0);
 }
 if(inet_aton(argv[1],&addr)!=0)
 
 	hostp=gethostbyaddr((const char *)&addr,sizeof(addr),AF_INET);
	 /* 在写网络程序的时候，建立TCP socket：
   sock = socket(PF_INET, SOCK_STREAM, 0);
然后在绑定本地地址或连接远程地址时需要初始化sockaddr_in结构，其中指定address family时一般设置为AF_INET，即使用IP。

相关头文件中的定义：AF = Address Family
                    PF = Protocol Family
                    AF_INET = PF_INET
在windows中的Winsock2.h中，
                    #define AF_INET 0
                    #define PF_INET AF_INET
所以在windows中AF_INET与PF_INET完全一样
而在Unix/Linux系统中，在不同的版本中这两者有微小差别.对于BSD,是AF,对于POSIX是PF.
    理论上建立socket时是指定协议，
	应该用PF_xxxx，设置地址时应该用AF_xxxx。
	当然AF_INET和PF_INET的值是相同的，混用也 不会有太大的问题。也就是说你socket时候用PF_xxxx，
	设置的时候用AF_xxxx也是没关系的，这点随便找个TCPIP例子就可以验证出来 了。如下，
	不论是AF_INET还是PF_INET都是可行的，只不过这样子的话，有点不符合规范。*/

else 
 	hostp=gethostbyname(argv[1]);
 	printf("主机域名%s",host->h_name);
 	
 	for(pp=host->h_aliases;*pp!=NULL;pp++)
 	printf("主机biao%s",*pp);
 	for(pp=host->h_addr_list;*pp!=NULL;pp++)
 	{
 		addr.saddr=*((unsigned int*)*pp);
 		printf("地址%s",inet_ntoa(addr));
 		
	 }
	 exit(0);
}
