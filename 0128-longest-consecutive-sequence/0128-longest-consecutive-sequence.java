class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0) return 0;
        HashSet<Integer> hs = new HashSet<>();
        for(int num: nums){
            hs.add(num);
        }
        int lStreak = 0;
        for(int num: hs){
            if(!hs.contains(num-1)){
                int numm = num;
                int cstreak = 1;
                while (hs.contains(numm + 1)) {
                    numm++;
                    cstreak++;
                }
                lStreak = Math.max(lStreak, cstreak);
            }
        }
        return lStreak;
    }
}