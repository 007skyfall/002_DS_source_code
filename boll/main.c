#include "seqstack.h"
#include "linkqueue.h"

void allout(Seqstack_t s, Linkque_t q){
	while(is_empty_seqstack(s) != 1){
		in_linkque(q, pop_seqstack(s));
	}
}
int check_queue(Linkque_t Q){
	Quenode_t p = Q->front;
	while(p->next != NULL){
		if(p->data > p->next->data){
			return 0;
		}
		p = p->next;
	}
	return 1;
}
int main(int argc, const char *argv[])
{
	int sum = 0, out = 0;
	Seqstack_t s1, s5, s60;
	s1 = create_seqstack(4);
	s5 = create_seqstack(11);
	s60 = create_seqstack(11);

	Linkque_t Q;
	create_linkque(&Q);

	//小球初始化入队
	int i;
	for(i = 1; i <= 27; i++){
		in_linkque(Q, i);
	}


	while(1){
		sum++;
		out = out_linkque(Q);
		if(is_full_seqstack(s1) != 1){
			push_seqstack(s1, out);
			continue;
		}

		allout(s1, Q);
		if(is_full_seqstack(s5) != 1){
			push_seqstack(s5, out);
			continue;
		}

		allout(s5, Q);
		if(is_full_seqstack(s60) != 1){
			push_seqstack(s60, out);
			continue;
		}

		allout(s60, Q);
		in_linkque(Q, out);

		if(check_queue(Q) == 1){
			break;
		}	
	}
	printf("sum = %d\n", sum);
	
	return 0;
}
