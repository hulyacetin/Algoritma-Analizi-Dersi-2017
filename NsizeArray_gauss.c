
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int i,j,k,b;
float dizi[50][50],c,x[10],toplam=0.0;


float gaussEliminasyon(int n){
 
      printf("Simdi tum matrisin satir ve sutun elemanlarini tek tek girin\n\a");
      printf("Sonuclar matrisi de bu asamada sizden istenecektir.\n");
      for(i=1; i<=n; i++)
      {
           for(j=1; j<=(n+1);j++)
               {
                    printf("dizi[%d][%d]: ", i , j);
                        scanf("%f", &dizi[i][j]);   
                     }
            }
for(j=1; j<=n; j++) /*üçgen matris oluşturmak için döngü*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=dizi[i][j]/dizi[j][j];
                for(k=1; k<=n+1; k++)
                {
                    dizi[i][k]=dizi[i][k]-c*dizi[j][k];
                }
            }
        }
    }
x[n]=dizi[n][n+1]/dizi[n][n];
    /* geri yerine ekleme*/
    for(i=n-1; i>=1; i--)
    {
        toplam=0;
        for(j=i+1; j<=n; j++)
        {
            toplam=toplam+dizi[i][j]*x[j];
        }
        x[i]=(dizi[i][n+1]-toplam)/dizi[i][i];
    }
    printf("\nCOZUM : \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); /* x,y ve z değerleri*/
    }          
      
}

int main() {
      printf("Kaclik matris olsun? : ");
      scanf("%d",&b);
      gaussEliminasyon(b);
    
    
    system("PAUSE");
    return 0;
}   
