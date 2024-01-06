import java.util.*;

class Solution {
    private Set<String> resultSet = new HashSet<>();
    
    public int solution(String[] user_id, String[] banned_id) {
        boolean[] visited = new boolean[user_id.length];
        dfs(user_id, banned_id, visited, 0);
        return resultSet.size();
    }
    
    private void dfs(String[] user_id, String[] banned_id, boolean[] visited, int depth) {
        if (depth == banned_id.length) {
            StringBuilder combination = new StringBuilder();
            for (int i = 0; i < user_id.length; i++) {
                if (visited[i]) {
                    combination.append(i);
                }
            }
            resultSet.add(combination.toString());
            return;
        }

        for (int i = 0; i < user_id.length; i++) {
            if (!visited[i] && isMatch(user_id[i], banned_id[depth])) {
                visited[i] = true;
                dfs(user_id, banned_id, visited, depth + 1);
                visited[i] = false;
            }
        }
    }
    
    private boolean isMatch(String userId, String bannedId) {
        if (userId.length() != bannedId.length()) {
            return false;
        }
        for (int i = 0; i < userId.length(); i++) {
            if (bannedId.charAt(i) != '*' && bannedId.charAt(i) != userId.charAt(i)) {
                return false;
            }
        }
        
        return true;
    }

}