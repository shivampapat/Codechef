import java.lang.*;
import java.util.*;

public class freethebunny{
      public static void main(String args[]){

            Scanner sc = new Scanner(System.in);

            int bunnies=  sc.nextInt();
            int bunnies_needed = sc.nextInt();

            int [][] arr = Solution.solute(bunnies, bunnies_needed);

            sc.close();

      }
}


class Solution{

      public static int[][] solute(int bunnies, int bunnies_needed){

            int distinct_keys = combos(bunnies,bunnies_needed-1);
            int copies_per_keys = bunnies - bunnies_needed +1;
            int combo_length = (distinct_keys*copies_per_keys)/bunnies;
            int[] choose = new int[combo_length]; 

            int[][] arr = new int[bunnies][];

            for(int i=0;i<arr.length;i++){
                  arr[i] = new int[combo_length];
            }

            ArrayList<int[]> diff_combos = new ArrayList<int[]>();

            Combination(diff_combos,choose, 0,distinct_keys-1, 0,combo_length); 

            for (int i = 0; i < diff_combos.size();i++) 
	      { 		      
                        System.out.println(diff_combos.get(i)); 		
	      }   
            return arr;
      }

      public static int combos(int n, int m){

            int sum = 0;
            sum+= fact(n);
            sum/=fact(m);
            sum/=fact(n-m);
            return sum;
      }

      public static int fact(int n){
            
            int fact=1;
            for(int i=n;i>1;i--){
                  fact*=i;
            }

            return fact;
      }

 
public static void  Combination(ArrayList<int[]> arr, int choose[], int start, int end,int index, int combo_length)  
{  
    if (index == combo_length)  
    {  
            arr.add(choose);    
        return;  
    }  
  
    for (int i = start; i <= end &&  end - i + 1 >= combo_length-index; i++)  
    {  
        choose[index] = i;  
        Combination(arr, choose, i+1,end, index+1, combo_length);  
    }  
} 
} 