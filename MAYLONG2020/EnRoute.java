import java.util.*;

public class EnRoute {
      public static void main(String[] args){

            Scanner sc = new Scanner(System.in);
            String s = new String();
            s = sc.next();

            System.out.println(Solut.solution(s));
            sc.close();
      
      }
}

class Solut{

      public static int solution(String str){
            int counter=0;
            int prev=0,temp=0;
            for(int i=0;i<str.length();i++){
                  if(str.charAt(i) == '>'){
                         temp++;
                  }
                  if(str.charAt(i) == '<'){
                        counter+=temp;
                  }
            }

            return counter*2;
      }
}