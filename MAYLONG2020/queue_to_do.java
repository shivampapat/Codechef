import java.util.*;

public class queue_to_do{

      public static void main(String[] args){

            Scanner sc = new Scanner(System.in);
            int starter = sc.nextInt();
            int steps = sc.nextInt();

            System.out.println(Solution.solute(starter,steps));

            sc.close();
      }
}

class Solution{

      public static int solute(int starter, int steps){

            int ans=0;
            int counter=starter;
            int skips=0;
            for(int i=0;i<steps;i++){
                  for(int j=0;j<(steps-skips);j++){
                        ans = ans^counter;
                        counter++;
                  }
                  counter = counter + skips;
                  skips++; 
            }

            return ans;
      }
}