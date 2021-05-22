import java.util.*;

public class Partitions{

      public static List<List<List<Integer>>> BothPartition;
      public static List<List<Integer>> widthPartition;
      public static List<List<Integer>> heightPartition;
      public static int[] dp;
      public static int width;
      public static int height;

      public static void main(String[] args){
            Scanner s = new Scanner(System.in);
            int w=  s.nextInt();
            int h= s.nextInt();
            Partitions.width  = w;
            Partitions.height = h;
            dp = new int[Math.max(w,h)];

            BothPartition = new ArrayList<>(2);
            widthPartition= new ArrayList<>();
            heightPartition = new ArrayList<>();            

            findPartition(width,width,0,true);

            Arrays.fill(dp,0);
            findPartition(height,height,0,false);

            BothPartition.add(widthPartition);
            BothPartition.add(heightPartition);
            System.out.println(BothPartition);
      }

      public static  void findPartition(int max_val_partition, int rem_val_partition, int curr_index, boolean flagW){

            //Partition formed
            if(rem_val_partition ==0){
                  
                  int[] freq = new int[Math.max(Partitions.width, Partitions.height) + 1];

                  //Fill with 0 initial frequency
                  Arrays.fill(freq,0);

                  //FInd freq of each element
                  for(int i=0;i<curr_index;i++){
                        freq[dp[i]]+=1;
                  }
                 
                  //Find first non zero from back to front
                  int i=Math.max(Partitions.width, Partitions.height);
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
      }

}