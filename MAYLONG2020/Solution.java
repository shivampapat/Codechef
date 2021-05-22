import java.util.*;

public class Solution{
      public static void main(String args[]){
            Scanner sc = new Scanner(System.in);

            int n = sc.nextInt();
            System.out.println(Solut.solution(n));
            sc.close();
      }
}

class Solut{
    public static String solution(int n) {
        StringBuilder s = new StringBuilder();
        
        boolean []numbers = new boolean[1000001];
        for(int i=0;i<=1000000;i++)
            numbers[i]=true;
        
        for(int i=2;(i*i)<=1000000;i++){
            if(numbers[i]==true){
                for(int j=i*2;j<=1000000;j+=i)
                    numbers[j]=false;
            }
        }
        
        for(int i=2;s.length() <=(n+5);i++)
        {
            if(numbers[i]==true){
                  s.append(Integer.toString(i));
            }
            
        }
      
        String str = s.substring(n,n+5);
        return str;
    } 
   
}