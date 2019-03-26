#include<stdio.h>
#include<stdlib.h>

typedef struct node{  
                     int data;
                     int num;
                     struct node*next;
                  }linklist;
                  
linklist* createlist(int n)
{
	linklist*p,*q,*head;
	int i,a[n+1];
	q=head=p=(linklist*)malloc(sizeof(linklist));
	p->data=0;
	printf("请输入第1个人的密码");
	scanf("%d",&head->data);
	p->num=1;
	for(i=2;i<=n;i++)
	{
		p=(linklist*)malloc(sizeof(linklist));
		printf("请输入第%d个人的密码",i);
		scanf("%d",&a[i]);
		p->num=i;
		p->data=a[i];	
		q->next=p;
		q=p;	
	}
	p->next=head;
	return head;
}


int main()
{
	int n,m,i,j,k,a[1000];
	printf("请依次输入人数和初始密码");
	scanf("%d %d",&n,&m);
	linklist*s,*p,*head,*q;
	head=createlist(n);
	p=head;
	for(i=0;i<n;i++)
	{
			k=n-i;
			m=m%k;
			if(m==0)	m=k;
			if(m==1)
			{
				q=p->next;
				while(q->next!=p)q=q->next;
				a[i]=p->num;
				m=p->data;
				q->next=q->next->next;
				p=q->next;
			}
			else
			{
				for(j=0;j<m-1;j++)
				{
					q=p->next;
				    while(q->next!=p)q=q->next;
				    a[i]=p->num;
				    m=p->data;
				    q->next=q->next->next;
				    p=q->next;
				}
			}
			printf("%5d",a[i]);
	}
}

                  

