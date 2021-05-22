import java.util.*;

public class doomsday_two {
      
      public static void main(String args[]){
            Scanner sc = new Scanner(System.in);

            int size = sc.nextInt();

            int[][] arr = new int[size][];

            for(int i=0;i<size;i++){
                  arr[i] = new int[size];
            }

            for(int i=0;i<size;i++){
                  for(int j=0;j<size;j++){
                        arr[i][j] = sc.nextInt();
                  }
            }
            


            int [] answer = Solution.solut(arr);
            for(int i:answer){
                  System.out.printf("%d\t",i);
            }


            sc.close();
      }
}
class Solution{


      public static int[] solut(int[][] arr){

            if(arr.length ==1){
                  return new int[]{1,1};
            }
            double[] sorted_arr = SortStatesF(arr);
            int[][] ans_frac  = new int[sorted_arr.length][2];
            for(int i=0;i<sorted_arr.length;i++){
                  ans_frac[i]=getFrac(sorted_arr[i]);
            }
 
            int[] temp = new int[ans_frac.length+1];
            for(int i=0;i<ans_frac.length;i++){
                        temp[i]  = ans_frac[i][1];
            }
            
            int denominator = findlcm(temp,temp.length-1);
            for(int i=0;i<ans_frac.length;i++){
                  temp[i] = (denominator / ans_frac[i][1])*ans_frac[i][0];
            }
            temp[temp.length-1] = denominator;
            return temp; 
      }

      public static int gcd(int a, int b) 
      { 
            if (b == 0) 
            return a; 
            return gcd(b, a % b); 
      } 
      public static int findlcm(int arr[],int n) 
      { 
            int ans = arr[0]; 
  
            for (int i = 1; i < n; i++) 
            ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
            return ans; 
} 
      public static int lcm(int[] temp){
            int lcm_all = 1;
            int divisor = 2;
            boolean remainder = true;          
            while(true){
                  int counter=0;
                  for(int i=0;i<temp.length;i++){
                        if(temp[i]==0)
                              return 0;
                        else if(temp[i] <0)
                              temp[i]=  temp[i]*-1;

                        if(temp[i]==1)
                              counter++;

                        if(temp[i]% divisor == 0){
                                    remainder=false;
                                    temp[i] = temp[i]/divisor;
                        }
                  }
                  if(remainder == false){
                        lcm_all *=divisor;
                  }
                  else{
                        divisor++;
                  }
                  if(counter == temp.length){
                        return lcm_all;
                  }
            }
      }
      public static double[] SortStatesF(int[][] arr){
            double[][] sorted_arr = new double[arr.length][];
            for(int i=0;i<arr.length;i++){
                  sorted_arr[i] = new double[arr[i].length];
            }
            int sorted_i=0,zero_indices_count=0;
            int[] changed_indices = new int[arr.length];
            int index_for_changed=0;
            for(int i=0;i<arr.length;i++){
                  int j=0;
                  for(j=0;j<arr[i].length;j++){
                        if(arr[i][j] !=0){
                              break;
                        }
                  }
                  if(j==arr[i].length){
                        zero_indices_count++;
                        for(j=0;j<arr[i].length;j++){
                              sorted_arr[sorted_i][j]=arr[i][j];
                        }     
                        changed_indices[index_for_changed++]=i;
                        sorted_i++;
                  }
            }
            for(int i=0;i<arr.length;i++){
                  int j=0;
                  for(j=0;j<arr[i].length;j++){
                        if(arr[i][j] !=0){
                              break;
                        }
                  }
                  if(j!=arr[i].length){
                        for(j=0;j<arr[i].length;j++){
                              sorted_arr[sorted_i][j]=arr[i][j];
                        }     
                        changed_indices[index_for_changed++]=i;
                        sorted_i++;
                  }
            }
            for(int i=0;i<zero_indices_count;i++){
                  sorted_arr[i][i] = 1;
            }
            int sum=0;
            for(int i=zero_indices_count;i<sorted_arr.length;i++){
                  double[] temp = new double[sorted_arr[i].length];
                  for(int j=0;j<sorted_arr[i].length;j++){
                        temp[j]=sorted_arr[i][j];
                        sum+=sorted_arr[i][j];
                  }
                  for(int j=0;j<sorted_arr[i].length;j++){
                        sorted_arr[i][j]=temp[changed_indices[j]]/sum;
                  }
                  sum=0;
            }
            double[][] F = new double[sorted_arr.length-zero_indices_count][sorted_arr.length-zero_indices_count];
            for(int i=0;i<F.length;i++){
                  for(int j=0;j<F.length;j++){
                        if(i==j){
                              F[i][j]= 1- sorted_arr[zero_indices_count+i][zero_indices_count+i];
                        }
                        else{
                              F[i][j]= 0-sorted_arr[zero_indices_count+i][zero_indices_count+j];
                        }   
                  }
            }

            F = invert(F);
            double[][] R = new double[sorted_arr.length-zero_indices_count][zero_indices_count];
            for(int i=zero_indices_count,k=0;i<sorted_arr.length;i++){
                  for(int j=0;j<zero_indices_count;j++){
                        R[k][j] = sorted_arr[i][j];
                  }
                  k++;
            }
            return (mult(F,R));
      }

      public static int[] getFrac(double x){
            double tolerance = 1.0E-10;
            double h1=1; double h2=0;
            double k1=0; double k2=1;
            double b = x;
            do {
                  double a = Math.floor(b);
                  double aux = h1; 
                  h1 = a*h1+h2; 
                  h2 = aux;
                  aux = k1; 
                  k1 = a*k1+k2; 
                  k2 = aux;
                  b = 1/(b-a);
            } while (Math.abs(x-h1/k1) > x*tolerance);
            return new int[]{(int)h1, (int)k1};
      }
      
      public static double[] mult(double[][] arr,double[][] brr){
            double[] FintoR = new double[brr[0].length];
                  for(int j=0;j<brr[0].length;j++){
                        for(int k=0;k<brr.length;k++){
                              FintoR[j]+=(arr[0][k]) * (brr[k][j]);
                        }       
            }
            return FintoR;
      }

      public static double[][] invert(double a[][]) 
    {
        int n = a.length;
        double x[][] = new double[n][n];
        double b[][] = new double[n][n];
        int index[] = new int[n];
        for (int i=0; i<n; ++i) 
            b[i][i] = 1;
 
        gaussian(a, index);
        for (int i=0; i<n-1; ++i)
            for (int j=i+1; j<n; ++j)
                for (int k=0; k<n; ++k)
                    b[index[j]][k]-= a[index[j]][i]*b[index[i]][k];
 
        for (int i=0; i<n; ++i) 
        {
            x[n-1][i] = b[index[n-1]][i]/a[index[n-1]][n-1];
            for (int j=n-2; j>=0; --j) 
            {
                x[j][i] = b[index[j]][i];
                for (int k=j+1; k<n; ++k) 
                {
                    x[j][i] -= a[index[j]][k]*x[k][i];
                }
                x[j][i] /= a[index[j]][j];
            }
        }
        return x;
    }
    public static void gaussian(double a[][], int index[]) 
    {
        int n = index.length;
        double c[] = new double[n];
 
        for (int i=0; i<n; ++i) 
            index[i] = i;
        for (int i=0; i<n; ++i) 
        {
            double c1 = 0;
            for (int j=0; j<n; ++j) 
            {
                double c0 = Math.abs(a[i][j]);
                if (c0 > c1) c1 = c0;
            }
            c[i] = c1;
        }
        int k = 0;
        for (int j=0; j<n-1; ++j) 
        {
            double pi1 = 0;
            for (int i=j; i<n; ++i) 
            {
                double pi0 = Math.abs(a[index[i]][j]);
                pi0 /= c[index[i]];
                if (pi0 > pi1) 
                {
                    pi1 = pi0;
                    k = i;
                }
            }
            int itmp = index[j];
            index[j] = index[k];
            index[k] = itmp;
            for (int i=j+1; i<n; ++i) 	
            {
                double pj = a[index[i]][j]/a[index[j]][j];
                a[index[i]][j] = pj;
                for (int l=j+1; l<n; ++l)
                    a[index[i]][l] -= pj*a[index[j]][l];
            }
        }
    }
}



