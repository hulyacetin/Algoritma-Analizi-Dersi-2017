
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int N;

   printf("Dizinin kac elemanli oldugunu belirtiniz:\n");
   scanf("%d",&N);
    
   int   i;
   float x[N], toplam = 0.0, ort, std_sap = 0.0;

   /* ortalama hesabı */
   for(i=0; i<N; i++)
   {
      printf("%d. sayi : ",i+1); 
      scanf("%f",&x[i]);

      toplam += x[i];
   }

   ort = toplam/N;

   /* standart sapma hesabı */
   for(toplam = 0.0, i=0; i<N; i++)
       toplam += pow(x[i]-ort, 2.0);

   std_sap = sqrt( toplam/(N-1) );

   printf("Ortalama       = %f\n",ort);
   printf("Standart sapma = %f\n",std_sap);
   printf("Varyans= %f\n", std_sap * std_sap);


   int   b, eb, ek, k;

   eb = x[0]; 

   for(b=1; b<N; b++)
      if( x[b]>eb ) eb = x[b];

   printf("En buyuk eleman = %d\n",eb);
   
   ek = x[0];
   
   for(k=1; k<N; k++)
            if ( x[k]<ek ) ek = x[k];
            
   printf("En kucuk eleman = %d\n",ek);
   
  system("PAUSE");	
  return 0;
}
