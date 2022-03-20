/**
* @fileName:baseStation_install.java
* @author: rojae 
* @date: 2022.03.22 10:29:30
* @description: 프로그래머스 문제 풀이
* 
* https://programmers.co.kr/learn/courses/30/lessons/12979
* Object Type이 아닌
* Primitive type으로 바꿔야 효율성 테스트 통과
*/

import java.util.LinkedList;
import java.util.Queue;

public class baseStation_install {
	//	N	stations	W	answer
	//	11	[4, 11]		1	3
	//	16	[9]			2	3
	public static void main(String args[]) {
		Solution sol = new Solution();
		int[] arr = {4, 11};
		System.out.printf("%d", sol.solution(11, arr, 1));
	}
}

class Solution {
    public int solution(int n, int[] stations, int w) {
    	int answer = 0;
    	int position = 1;
		int idx = 0;

    	while(position <= n) {
    		// 범위 안에 존재하는 경우
    		if(idx < stations.length && stations[idx] - w <= position) {
				position = stations[idx] + w + 1;
				idx += 1;
    		}
    		// 범위 밖에 존재하는 경우
    		else {
	    		answer += 1;
	    		position += w * 2 + 1;
    		}
    	}
        return answer;
    }
}