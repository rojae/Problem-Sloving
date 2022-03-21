import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
* @fileName: MockTest.java
* @author: rojae 
* @date: 2022.03.22
* @description: https://programmers.co.kr/learn/courses/30/lessons/42840
*/
public class MockTest {
    public static void main(String args[]){
        Solution sol = new Solution();
        int ans[] = sol.solution(new int[] {1,3,2,4,2});
        
        for(int i : ans)
            System.out.print(i+ " ");
    }

    static class Solution {
        private final static int[] stud1 = new int[] {1, 2, 3, 4, 5};
        private final static int[] stud2 = new int[] {2, 1, 2, 3, 2, 4, 2, 5};
        private final static int[] stud3 = new int[] {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

        public int[] solution(int[] answers) {
            List<Integer> res = Arrays.asList(0, 0, 0);
            List<Integer> rtn = new ArrayList<Integer>();
            
            int max = 0;

            for(int i=0; i<answers.length; i++){
                if(answers[i] == stud1[i % 5])
                    res.set(0, res.get(0)+1);
                if(answers[i] == stud2[i % 8])
                    res.set(1, res.get(1)+1);
                if(answers[i] == stud3[i % 10])
                    res.set(2, res.get(2)+1);
                
                max = Math.max(res.get(0), Math.max(res.get(1), res.get(2)));
            }
            
            for(int i=0; i<3; i++){
                if(max == res.get(i))
                    rtn.add(i+1);
            }

            return rtn.stream().mapToInt(i->i).toArray();
        }
    }
}
