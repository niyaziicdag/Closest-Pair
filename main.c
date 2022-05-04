#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct koord{//X ve Y koordinatlarý dinamik veri yapýsýnda tutulmuþtur.
		int x,y;
		
    	struct koord* next; 
}koord;
koord *head=NULL,*tmp=NULL,*node;

//1- Dosyadan x-y koordinatlarýnýn okunmasý
int addKoord(){
	int x,y,n=0;
	FILE *fp;
	
  	fp=fopen("sample.txt","r"); 
  	while (!feof(fp)) { 
  		fscanf(fp, "%d %d", &x,&y); 
		node= (koord*) malloc(sizeof (koord));
		node->x=x;
		node->y=y;
		node->next=NULL;
		n++;
		if (head == NULL)
    	{
    	    head = node;
    	    tmp=head;
    	    
    	}else{
    	tmp->next = node;
    	tmp = tmp->next;
    	}
    }
    return n;
}
void listele(int n){
	int i;
	tmp=head;
	 for(i=0;i<n;i++){
         printf("\n%d: %d-%d",i+1,tmp->x, tmp->y);
         tmp=tmp->next;      
       }
}
//2-Sýralama
void degistir(koord *a, koord *b) 
{ 
    int tempX = a->x; 
    a->x = b->x; 
    b->x = tempX; 
    int tempY = a->y; 
    a->y = b->y; 
    b->y = tempY;
}
void koordSirala(){

    int kontrol, i; 
    koord *ptr1; 
    koord *lptr = NULL; 
  
    if (head == NULL) 
        return; 
  
    do
    {
        kontrol = 0; 
        ptr1 = head; 

        while (ptr1->next != lptr) 
        {
            if (ptr1->x > ptr1->next->x) 
            {  
                degistir(ptr1, ptr1->next); 
                kontrol = 1; 
            } 
            ptr1 = ptr1->next; 
        }
        lptr = ptr1; 
    } 
    while (kontrol);
}
//3- Medyan Alma
float medyan(int n){
 int k=n/2;
 float toplam;
 	int i;
	tmp=head;
	if(n%2 ==0){
	 tmp=head;
	 toplam=0;
	 for(i=0;i<n;i++){
	 	if(i==k){
	 		toplam +=tmp->x;
		 }
		 else if(i==k-1){
		 	toplam +=tmp->x;
		 }
         tmp=tmp->next;      
       }
    }
	else {
		toplam=0;
		tmp=head;
		for(i=0;i<n;i++){
			if(i==k){
			toplam =tmp->x;	
			}
			tmp=tmp->next;
		}
		return toplam;
	}
 float med=toplam/2;
 return med;
}
///////////////////////////////////////////////
float mesafeHesapla(koord *a, koord *b){
	float mesafe=0;
	mesafe=sqrt( pow((a->x - b->x),2) + pow((a->y - b->y),2) );
	return mesafe;
}
float closestPair(koord *n1,int n,int med){
	int i,j;
	float mesafe=0;
	float min=9999;
	koord *n2;
	n2=head;
	if(n<=3){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				mesafe=mesafeHesapla(n1,n2);	
				if(mesafe<=min && mesafe!=0){min=mesafe;}
				n2=n2->next;	
			}
			n1=n1->next;
		}
	}
	return min;
}
int main(){
	int n;
	n=addKoord();
	printf("Koordinatlar ve n:%d \n",n);
    listele(n);
    printf("\n Sirali Koordinatlar \n");
	koordSirala();
	listele(n);
	float med=medyan(n);
	printf("\n Medyan: %f \n",med);
	koord *node=head;
	float min=closestPair(node,n,med);
	printf("Minimum:%f\n",min);
	return 0;
}
