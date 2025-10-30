class Solution {
    public int[] twoSum(int[] arr, int target) {
        Map <Integer,Integer> map = new HashMap<>();
        for(int i =0;i<arr.length;i++) {
            int more = target - arr[i];

            if(map.containsKey(more)) {
                return new int[] {map.get(more),i};
            }
            map.put(arr[i],i);
        }
        return new int[] {};
    }
}