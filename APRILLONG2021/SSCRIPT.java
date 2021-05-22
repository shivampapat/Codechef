/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes her
		Scanner sc = new Scanner(System.in);
			
			int test = sc.nextInt();
			
			while(test-- > 0) {
				int n = sc.nextInt();
				int k = sc.nextInt();
				int count=0;
				String s = sc.next();
				boolean flag = false;
				for(int i=0;i<n;i++) {
					if(s.charAt(i) == '*') {
						while(i<n && s.charAt(i) == '*') {
				//			System.out.println(s.charAt(i));
							count++;
							i++;
						}
						if(count >=k) {
							System.out.println("YES");
							flag=true;
							break;
						}
						count = 0;
					}
				}
			//	System.out.println("i " + (i));
				if(!flag) {
					System.out.println("NO");
				}
			}
			
			sc.close();
	}
}
