import java.util.*;

public class LevelTwo{
      public static void main(String args[]){
            Scanner sc = new Scanner(System.in);

            int n = sc.nextInt();
            int[] arr  =new int[n];

            for(int i = 0; i < n; i++){
                  arr[i]=sc.nextInt();
            }
            System.out.println(Solut.solution(arr));
            sc.close();
      }
}

class Solut{
    public static int solution(int[] arr) {
        
            int sum=0,no=0;
            for(int i=0;i<arr.length;i++){
                  sum+=arr[i];
            }

            if(arr.length==1){
                  if(arr[0]%3==0){
                        return arr[0];
                  }
                  return 0;
            }
            

            Arrays.sort(arr);
            if(sum%3==0){
                  for(int i=0,j=1;i<arr.length;i++,j*=10){
                        no+=(arr[i]*j);
                  }
                  return no;
            }

            int index_found_1=-1;
            for(int i=0;i<arr.length;i++){
                  if(sum %3 == arr[i]%3){
                        index_found_1=i;
                        break;
                  }
            }
            no=0;
            if(index_found_1 != -1){
                  for(int i=0,j=1;i<arr.length;i++){
                        if(index_found_1 == i)
                              continue;
                        no+=(arr[i]*j);
                        j*=10;
                  }

                  return no;
            }

            if(arr.length == 2)
            {
                  return 0;
            }

            no=0;
            index_found_1= -1;
            int index_found_2= -1;           

            for(int i=0;i<arr.length;i++){
                  if((arr[i]==1 || arr[i]==4) || arr[i]==7){
                        for(int j=0;j<arr.length;j++){
                              if((arr[j]==1 || arr[j]==4) || arr[j]==7)
                              {
                                    index_found_1=i;
                                    index_found_2=j;
                                    break;
                              }
                        }
                        if(index_found_1 != -1 && index_found_2 != -1)
                              break;
                  }
                  else if((arr[i]==2 || arr[i]==5) || arr[i]==8){
                        for(int j=0;j<arr.length;j++){
                              if((arr[j]==2 || arr[j]==5) || arr[j]==8)
                              {
                                    index_found_1=i;
                                    index_found_2=j;
                                    break;
                              }
                        }
                        if(index_found_1 != -1 && index_found_2 != -1){
                              break;
                        }
                  }
            }

            
            if(index_found_1 != -1 && index_found_2 != -1){
                  for(int i=0,j=1;i<arr.length;i++){
                        if(i == index_found_1 || i==index_found_2)
                              continue;
                        no+=(arr[i]*j);
                        j*=10;
                  }
                  return no;
            }
            

            return 0;
    } 
   
}



/*

from itertools import combinations
 
def answer(l):
	Arrays.sort(arr);
	for i in reversed(range(1, len(l) + 1)):
		for tup in combinations(l, i):
			if sum(tup) % 3 == 0: return int(''.join(map(str, tup)))
	return 0


*/