import java.util.*;
import java.lang.*;
import java.math.BigInteger;


public class Shivam_DisorderlyEscape{

      public static List<List<Integer>> widthPartition;
      public static List<List<Integer>> heightPartition;
      public static int[] dp;
      public static int width;
      public static int height;

      public static void main(String args[]){

            Scanner sc = new Scanner(System.in);
            int width,height,s_colours;
            //Input colums, rows and no of colours to be used for colouring.
            width = sc.nextInt();
            height = sc.nextInt();
            s_colours = sc.nextInt();

            //Main function
            String answer = Shivam_DisorderlyEscape.solute(width,height,s_colours);
            System.out.println(answer);
      }

      public static String solute(int w, int h, int s) {
          
              List<List<List<Integer>>> partitions = new ArrayList<List<List<Integer>>>();
              partitions = NumberPartitions(w,h);
  
              List<List<Integer>> width_partition = partitions.get(0);
              List<List<Integer>> height_partition = partitions.get(1);
  
              //IMplementing formula now
  
              //w! X h! 
              BigInteger answer = BigInteger.ZERO;
              BigInteger numerator = factorial(w);
              numerator = numerator.multiply(factorial(h));
  
             
              for(List<Integer> each_width: width_partition){
  
                    for(List<Integer> each_height :height_partition){
  
                          BigInteger denominator = BigInteger.ONE;
                          denominator = denominator.multiply(permutation_of_partition(each_width));
                          denominator = denominator.multiply(permutation_of_partition(each_height));
  
                          BigInteger multiplier = BigInteger.ONE;
  
                          for(int i=0; i<each_width.size(); ++i){
  
                                int mul1 = each_width.get(i);
  
                                      for(int j=0; j<each_height.size(); ++j){
  
                                            int mul2 = each_height.get(j);
  
                                            if(mul2 !=0 && mul1 != 0){
                                             
                                                  int gcd_val = gcd(i+1,j+1);
                                                  int mul = mul1*mul2;
                                                  multiplier = multiplier.multiply(BigInteger.valueOf(s).pow(gcd_val).pow(mul));
                                            }
                                            if(mul1 == 0)
                                                  break;
                                      }
                          }     
                   
                          multiplier = multiplier.multiply(numerator.divide(denominator));
                          answer = answer.add(multiplier);
                    }
              }
              answer = answer.divide(numerator);
  
              return answer.toString();
        }//soln function ends
  
        //Generating partitions
        public static List<List<List<Integer>>> NumberPartitions(int w, int h){
                    List<List<List<Integer>>> partitions = new ArrayList<>();

                    Shivam_DisorderlyEscape.width  = w;
                    Shivam_DisorderlyEscape.height = h;
                    dp = new int[Math.max(w,h)];
        
                    widthPartition= new ArrayList<>();
                    findPartition(width,width,0,true);

                        if(w==h){
                              heightPartition = new ArrayList<>(widthPartition);

                        }
                        else{
                              heightPartition= new ArrayList<>();
                              Arrays.fill(dp,0);
                              findPartition(height,height,0,false);
                        }
                    

                    partitions.add(widthPartition);
                    partitions.add(heightPartition);
                    return partitions;
        }
  
        public static BigInteger permutation_of_partition(List<Integer> partition_of_a_number){
  
              BigInteger sum = BigInteger.ONE;
  
              for(int i = 0; i < partition_of_a_number.size();i++){
                    sum = sum.multiply(BigInteger.valueOf(i+1).pow(partition_of_a_number.get(i)));
                    sum = sum.multiply(factorial(partition_of_a_number.get(i)));
              }
              return sum;
        }
  
        //GCD of 2 nos
        public static int gcd(int a,int b){
              
              if(a==b){
                    return a;
              }
              else if(a==0 || b==0){
                    return (a>b) ? a:b;
              }
  
              if(a>b)
                   return gcd(a-b,b);
              return gcd(a,b-a);
        }
  
        //Factorial of a number used BigInteger here
        public static BigInteger factorial(int n){
              BigInteger answer;
              answer = BigInteger.ONE;
  
              while(n>1){
                    answer = answer.multiply(BigInteger.valueOf(n));
                    n--;
              }
  
              return answer;
        }
  
  
      
      //Partition function
        public static  void findPartition(int max_val_partition, int rem_val_partition, int curr_index, boolean flagW){
  
              //Partition formed
              if(rem_val_partition ==0){
                  
                  int[] freq = new int[Math.max(Shivam_DisorderlyEscape.width, Shivam_DisorderlyEscape.height) + 1];

                  //Fill with 0 initial frequency
                  Arrays.fill(freq,0);

                  //FInd freq of each element
                  for(int i=0;i<curr_index;i++){
                        freq[dp[i]]+=1;
                  }
                 
                  //Find first non zero from back to front
                  int i=Math.max(Shivam_DisorderlyEscape.width, Shivam_DisorderlyEscape.height);
                  while(freq[i]==0 && i>0){
                        i--;
                  }
                  
                  List<Integer> part=new ArrayList<Integer>();
                  

                  while(i>0){
                        part.add(0,freq[i]);
                        i--;
                  }
                  
                  
                  if (part.size() >0) 
                        if(flagW == true) 
                              widthPartition.add(part);     
                        else
                              heightPartition.add(part);
                  return;
            } 
            else{

                  for(int i=max_val_partition; i>=1; --i){
                        
                        //if i has value greater than remaining partition value then continue
                        if(i > rem_val_partition){
                              continue;
                        }
                        else{
                              dp[curr_index] = i;
                              findPartition(i, rem_val_partition - i, curr_index+1,flagW);
                        }
                  }
                  
            }
        }//function ends
  
      }//partition class ends
   