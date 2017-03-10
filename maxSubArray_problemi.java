package javaapplication1;

/**
 *
 * @author BM
 */
public class JavaApplication1 {

    public static int maxSubArray(int[] A) {
       int newsum=A[0];
       int max=A[0];
       for(int i=1;i<A.length;i++){
           newsum=Math.max(newsum+A[i],A[i]);
           max= Math.max(max, newsum);
       }
       return max;
    }
    
    public static void main(String[] args) {
        
        int L[]={4,-3,2, 1 ,6,-1,-2,4};
        
        
        int sinir=(L.length)/2;
        
        int L1[]=new int[sinir];
        int L2[]=new int[sinir];
        
        for(int i=0;i<sinir;i++){
            L1[i]=L[sinir-i-1];
            
        }
        
        for(int i=0;i<sinir;i++){
            L2[i]=L[sinir+i];
            
        }
        
        for(int i=0;i<L1.length;i++){
            System.out.println("L1 dizisi= "+L1[i]);
            
        }
        
        for(int i=0;i<L2.length;i++){
            System.out.println("L2 dizisi= "+L2[i]);
            
        }
         
        
        System.out.println("L1 toplam= "+maxSubArray(L1));
        System.out.println("L2 toplam= "+maxSubArray(L2));
        
        int toplam=maxSubArray(L1)+maxSubArray(L2);
        System.out.println("Toplam= " + toplam );
        
    }
    
    
}






run:
L1 dizisi= 1
L1 dizisi= 2
L1 dizisi= -3
L1 dizisi= 4
L2 dizisi= 6
L2 dizisi= -1
L2 dizisi= -2
L2 dizisi= 4
L1 toplam= 4
L2 toplam= 7
Toplam= 11
BUILD SUCCESSFUL (total time: 0 seconds)
