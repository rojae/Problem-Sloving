/** ==================================================
* @fileName: nNumberConvect.java
* @author: rojae 
* @date: 2022.04.03
* @description: https://programmers.co.kr/learn/courses/30/lessons/92335
==================================================**/

import java.util.Arrays;
import java.util.Scanner;

public class nNumberConvert {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println(solution(437674, 3));
		sc.close();
		return;
	}
	
	// n : number
	// k : 진법
    public static int solution(int n, int k) {
    	int ans = 0;
    	String chagneNumber;
    	
    	// step 1 - 진법변환 
    	StringBuilder sb = new StringBuilder();
	    int now = n;
	    
        while(now > 0){
            if(now % k < 10)
                sb.append(now % k);
            else
                sb.append((char)(now % k - 10 + 'A'));
            now /= k;
        }
        
        chagneNumber = sb.reverse().toString();
        
        String arr[] = chagneNumber.split("0");
        Arrays.sort(arr);
        
        for(int i = 0; i < arr.length; i++) {
        	// Exception catch
        	if( arr[i] != null && !arr[i].equals("")  && cal(Long.valueOf(arr[i])) )
        		ans++;
        }
        
        return ans;
    }
    
    public static boolean cal(long n){
        if(n == 0) 
        	return false;
        if(n == 1) 
        	return false;
        
        for(int i=2;i<=Math.sqrt(n);i++){
            if(n % i == 0) 
            	return false;
        }
        
        return true;
    }
	

}