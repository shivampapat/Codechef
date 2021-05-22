import java.util.*;
import java.math.BigInteger;

public class bombbaby{

      public static void main(String[] args){

            Scanner sc = new Scanner(System.in);
            String M = sc.next();
            String F = sc.next();
            System.out.println(Solution.solute(M,F));
            sc.close();
      }
}

class Solution{

      public static String solute(String M,String F){

            BigInteger step_ans= new BigInteger("0");
            BigInteger val= new BigInteger("100");
            BigInteger machB   = new BigInteger(M);
            BigInteger faculaB = new BigInteger(F);
            if(machB.mod(new BigInteger("2"))== BigInteger.ZERO && faculaB.mod(new BigInteger("2"))== BigInteger.ZERO){
                  return("impossible");
            }
            if(machB == BigInteger.ONE && faculaB == BigInteger.ONE){
                  return "0";
            }
           
            while(machB.compareTo(faculaB) != 0){
                  if(machB.compareTo(faculaB) == 1){
                        
                        if(machB.divide(faculaB).compareTo(val) == 1){
                              machB = machB.mod(faculaB);
                              step_ans = step_ans.add(machB.divide(faculaB));
                        }
                        else{
                              machB = machB.subtract(faculaB);
                              step_ans = step_ans.add(BigInteger.ONE);
                        }
                        
                  }
                  else if(machB.compareTo(faculaB) == -1){

                        if(faculaB.divide(machB).compareTo(val) == 1){
                              faculaB = faculaB.mod(machB);
                              step_ans = step_ans.add(faculaB.divide(machB));      
                        }
                        else{
                              faculaB = faculaB.subtract(machB);
                              step_ans = step_ans.add(BigInteger.ONE);
                        }
                  }
                  
                  if(machB.compareTo(BigInteger.ONE) == 0 && faculaB.compareTo(BigInteger.ONE) ==0){
                        break;
                  }
            }

            if(machB.compareTo(BigInteger.ONE) == 0 && faculaB.compareTo(BigInteger.ONE) ==0){
                  return step_ans.toString();
            }

            if(machB.compareTo(faculaB) == 0 && faculaB.compareTo(BigInteger.ONE) !=0){
                  return "impossible";
            }
            if(machB.compareTo(BigInteger.ONE) == 0 || faculaB.compareTo(BigInteger.ONE) == 0){
                  step_ans = step_ans.add(machB.max(faculaB).subtract(BigInteger.ONE));
                  return step_ans.toString();
            }

            

            return "0";
      }
}