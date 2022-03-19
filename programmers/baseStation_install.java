// https://programmers.co.kr/learn/courses/30/lessons/12979

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
    	
    	Queue<Integer> q = new LinkedList<Integer>();
    	for(int s : stations)	q.offer(s);
    	
    	while(position <= n) {
    		// 범위 안에 존재하는 경우
    		if(!q.isEmpty() && q.peek() - w <= position) {
    			position = q.poll() + w + 1;
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