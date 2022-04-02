/** ==================================================
* @fileName: reportResult.java
* @author: rojae 
* @date: 2022.04.03
* @description: https://programmers.co.kr/learn/courses/30/lessons/92334
==================================================**/

import java.util.Scanner;

public class reportResult {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		String[] id_list = {"muzi", "frodo", "apeach", "neo"};
		String[] report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
		int k = 2;
		
		
		int[] ans = solution(id_list, report, k);
		for(int i =0; i < ans.length; i++)
			System.out.print(ans[i]+ " ");
		sc.close();
		return;
	}
    
	/*
	 * 	["muzi", "frodo", "apeach", "neo"],
	 *  ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"],
	 *   2
	 */
	public static int[] solution(String[] id_list, String[] report, int k) {
		int s = id_list.length;
        int[] answer = new int[s];
        int arr[][] = new int[s][s];
        boolean target[] = new boolean[s];
        
        
        // make arr[k][k]
        for(String i : report) {
        	String str[] = i.split(" ");
        	String reporter = str[0];
        	String reportee = str[1];
        	
        	int reporter_idx = 0;
    		int reportee_idx = 0;
    		
        	for(int j = 0; j < id_list.length; j++) {
        		if(reporter.equals(id_list[j]))
        			reporter_idx = j;
        		if(reportee.equals(id_list[j]))
        			reportee_idx = j;
        	}
        	
        	arr[reporter_idx][reportee_idx] = 1;
        }
        
        // i = reportee
        for(int i = 0; i < s; i++) {
        	
        	int sum = 0;
        	
        	// j = reporter
        	for(int j = 0; j < s; j++) {
        		if(arr[j][i] == 1) {
        			sum++;
        			if(sum == k) {
        				target[i] = true;
        				break;
        			}
        		}
        	}
        	
        }
        
        for(int i =0; i<s; i++) {
        	for(int j =0; j<s; j++) {
        		if( arr[i][j] == 1 && target[j])
        			answer[i]++;
        	}
        }
        
        return answer;
    }
    
}


