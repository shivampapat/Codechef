import java.lang.*;
import java.util.*;

public class EscapePods{
      public static void main(String[] args){

            Scanner sc = new Scanner(System.in);

            int[][] arr = {{0,0,4,6,0,0,},{0,0,5,2,0,0,},{0,0,0,0,4,4,},{0,0,0,0,6,6},{0,0,0,0,0,0,},{0,0,0,0,0,0,}};
            
            int[] entrance = {0,1};  
            int[] exit = {4,5};


      System.out.println(Solution.solution(entrance,exit,arr));

            sc.close();
      }
}

 class Solution {

      public static int solution(int[] entrances, int[] exits, int[][] path) {

        int max_free_bunnies=0;
        int[][] residual_path = new int[path.length][path.length];
  
        ArrayList<Integer> exit = new ArrayList<Integer>(exits.length);
  
        for(int i: exits){
              exit.add(i);
        }

        //Copied original path as given
        for(int i = 0; i < path.length; i++){
              for(int j = 0; j < path[i].length; j++){
                    residual_path[i][j] = path[i][j];
              }
        }
  
      int prev_free_bunnies= Integer.MIN_VALUE;
  
        while(prev_free_bunnies != max_free_bunnies){
  
              prev_free_bunnies = max_free_bunnies;
  
              for(int i=0;i<entrances.length;i++){

                    ArrayList<Integer> visited_vertices = new ArrayList<Integer>();
                    ArrayList<Integer> path_vertices = new ArrayList<Integer>();
  
                    int current_row =entrances[i];
                 
                    while(true){
  
                          visited_vertices.add(current_row);
                          //Greedy approach here
                          int max =0;
                          int max_index = 0;
                          boolean unvisited = false;

                          for(int j=0;j<residual_path[current_row].length;j++){
  
                                if(residual_path[current_row][j] > max && (visited_vertices.contains(j) == false)){
                                      max =residual_path[current_row][j];
                                      max_index = j;
                                      unvisited = true;
                                }
                          }
  
                          if(unvisited == true){
                                path_vertices.add(current_row);
                                current_row = max_index;
                          }
                          else if(path_vertices.isEmpty())
                                    break;
                           else{        
                              current_row = path_vertices.get(path_vertices.size() - 1);
                              path_vertices.remove(path_vertices.size()-1);
                          }

                          System.out.println("current_rowbfore = " + current_row);

                        System.out.println("ResidualPath before entering exit");
                          for(int k=0;k<residual_path.length;k++){
                              for(int l=0;l<residual_path[k].length;l++){
                                    System.out.printf("%d\t",residual_path[k][l]);
                              }
                              System.out.println();
                        }
         
                          //if the current_row is one of exit bars
                          if(exit.contains(current_row)){
                                int min = 2000000; // max value given in questn
                                path_vertices.add(current_row);
  
                                for(int j=0;j<path_vertices.size()-1;j++){
                                      if(residual_path[path_vertices.get(j)][path_vertices.get(j+1)] < min){
                                            min = residual_path[path_vertices.get(j)][path_vertices.get(j+1)];
                                      }
                                }
          
                                max_free_bunnies+=min;
                              
                                System.out.println("Path vertices");
                        for(int k=0;k<path_vertices.size();k++){
                                  System.out.printf("%d\t",path_vertices.get(k));
                            }
                            System.out.println();
                                

                                for(int j=0;j<path_vertices.size()-2;j++){
                                      residual_path[path_vertices.get(j)][path_vertices.get(j+1)] -= min;
                                      residual_path[path_vertices.get(j+1)][path_vertices.get(j)] += min;
                                }

                                
                        System.out.println("ResidualPath after entering exit");
                        for(int k=0;k<residual_path.length;k++){
                            for(int l=0;l<residual_path[k].length;l++){
                                  System.out.printf("%d\t",residual_path[k][l]);
                            }
                            System.out.println();
                      }
       
                                                                                                                                                  
                                residual_path[path_vertices.get(path_vertices.size()-2)][path_vertices.get(path_vertices.size()-1)] -= min;
                                break;
                          }


  
                    }//while1
  
              }//for
  
      
        }//while
  
        return max_free_bunnies;
  
    }//solution
  }
 