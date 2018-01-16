/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
    public int lcsDynamic(char str1[],char str2[]){
        //System.out.print(str1);
        //System.out.print(str2);
        int temp[][] = new int[str1.length + 1][str2.length + 1];
        int max = 0;
        for(int i=1; i < temp.length; i++){
            for(int j=1; j < temp[i].length; j++){
                if(str1[i-1] == str2[j-1]) {
                    temp[i][j] = temp[i - 1][j - 1] + 1;
                }
                else
                {
                    temp[i][j] = Math.max(temp[i][j-1],temp[i-1][j]);
                }
                if(temp[i][j] > max){
                    max = temp[i][j];
                }
            }
        }
        return max;

    }


	 public static void main(String args[]){
        Ideone lcs = new Ideone();
        Scanner sc = new Scanner(System.in);
        int k1=sc.nextInt();int k2=sc.nextInt();
        String s1 = sc.next();
        String s2 = sc.next();
        char str1[]=s1.toCharArray();
        char str2[]=s2.toCharArray();
        int z = k1+k2;
        int i=0,j=0;
        int ls1=str1.length;
        int ls2=str2.length;

        while(z!=0){
          if(j==ls1 || i==ls2)
          break;
          if(str1[i]!=str2[j]){
            str2[j]=str1[i];
            --z;
          }
          ++i;
          ++j;
        }

        int result = lcs.lcsDynamic(str1, str2);
        System.out.print(result);
    }


}
