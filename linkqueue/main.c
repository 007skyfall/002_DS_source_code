#include "linkqueue.h"
/*输入数值入队，　输入非数值出队，　－１结束*/
int main(int argc, const char *argv[])
{
	Linkque_t Q = NULL;
	create_linkque(&Q);
	if( NULL == Q ){
		printf("create error!\n");
		return -1;
	}
	show_linkque(Q);
	
	int ret=0, del=0, value = 0;
	while(1){
		ret = scanf("%d", &value);
		if( value == -1 ){	
			break;
		}else if(ret == 1){
			if(in_linkque(Q, value)==0){
				show_linkque(Q);
			}else{
				continue;
			}
		}else{
			if((del = out_linkque(Q)) != -1){
				printf("%d\n", del);	
				show_linkque(Q);
			}
		}
		while(getchar()!='\n');
	}

	return 0;
}
