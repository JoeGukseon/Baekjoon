class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;

        for (String skillTree : skill_trees) {
            boolean isOk = true;
            int curIdx = 0;
            for (char sk : skillTree.toCharArray()) {
                if (sk == skill.charAt(curIdx)) {
                    if (curIdx < skill.length()-1) {
                        curIdx++;
                    }
                } else if (!skill.contains(Character.toString(sk))) {
                    
                } else {
                    isOk = false;
                    break;
                }
            }
            if (isOk) {
                answer++;
            }
        }
        return answer;
    }
}